# TurbineOverspeedTripEnhanced 模型文档

## 1) 模型目的与范围

**目的**：本模型用于模拟带有超速保护、延迟停机和主蒸汽阀门动态的汽轮机调速系统。通过引入短时与持续两种超速扰动，验证保护逻辑的响应速度、延迟触发机制及停机保持（Latch）功能的有效性。

**范围**：涵盖以下物理机制与控制逻辑：
- 转子动力学（旋转惯量与阻尼）
- 一阶阀门动态（主蒸汽阀开度响应）
- 超速保护逻辑（阈值检测与计时）
- 停机保持机制（触发后自锁，防止重合闸）

## 2) 组件清单（列出 MSL 组件类型）

本模型为纯方程式模型，未实例化任何 Modelica 标准库（MSL）组件。所有动力学与逻辑均通过原生方程与 `when` 语句直接实现。

## 3) 参数表

| Name | Value | Unit | Description |
| :--- | :--- | :--- | :--- |
| `omega_rated` | 100 | rad/s | 额定转速 |
| `omega_trip` | 110 | rad/s | 超速阈值（额定转速的110%） |
| `trip_delay` | 0.1 | s | 停机延迟时间 |
| `J` | 10 | kg.m2 | 转子惯量 |
| `tau_steam_rated` | 1400 | N.m | 额定蒸汽力矩 |
| `d_load` | 10 | N.m.s/rad | 负载阻尼系数 |
| `T_valve` | 0.05 | s | 阀门时间常数 |
| `t_short_start` | 1.0 | s | 短暂超速测试开始时刻 |
| `t_short_dur` | 0.05 | s | 短暂超速测试持续时间 |
| `t_long_start` | 3.0 | s | 持续超速测试开始时刻 |
| `t_long_dur` | 0.3 | s | 持续超速测试持续时间 |

## 4) 初始条件

| Variable | Value | Description |
| :--- | :--- | :--- |
| `omega` | 100 | 初始转速 |
| `valve_opening` | 1.0 | 初始阀门开度 |
| `trip_timer` | 0 | 初始超速持续计时器 |
| `trip_latched` | false | 初始停机保持信号 |

## 5) 控制逻辑说明

1. **扰动生成**：在 `t_short_start` 时刻施加持续 `t_short_dur` 的 2000 N.m 扰动力矩；在 `t_long_start` 时刻施加持续 `t_long_dur` 的 2000 N.m 扰动力矩。
2. **超速检测**：当转子转速 `omega` 大于等于超速阈值 `omega_trip` 时，超速标志 `overspeed` 置为 `true`。
3. **延迟计时**：若处于超速状态且未触发停机保持（`overspeed and not trip_latched`），计时器 `trip_timer` 累加；若超速状态消失且未保持，计时器复位为 0。
4. **停机保持（Latch）**：当超速计时器达到停机延迟 `trip_delay` 时，停机保持信号 `trip_latched` 锁定为 `true`，此后不可逆。
5. **阀门目标逻辑**：正常情况下阀门目标开度 `valve_target` 为 1；一旦 `trip_latched` 为 `true`，目标开度立即降为 0。
6. **阀门动态**：主蒸汽阀实际开度 `valve_opening` 以一阶惯性环节（时间常数 `T_valve`）追踪目标开度 `valve_target`，进而切断蒸汽输入力矩 `tau_in`。

## 6) 仿真设置

| Setting | Value |
| :--- | :--- |
| 停止时间 (Stop Time) | 20 s |
| 步长 ( Interval) | 0.001 s |
| 求解器 (Solver) | dassl |
| 容差 (Tolerance) | 1e-06 |

## 7) 结果概览（target_variables 的统计摘要）

| Name | Start | Min | Max | Final | Unit |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `omega` | 100.0 | 3.47e-06 | 112.995 | 3.47e-06 | rad/s |
| `omega_trip` | 110.0 | 110.0 | 110.0 | 110.0 | - |
| `overspeed` | 0.0 | 0.0 | 1.0 | 0.0 | - |
| `trip_timer` | 0.0 | 0.0 | 0.100 | 0.100 | s |
| `trip_latched` | 0.0 | 0.0 | 1.0 | 1.0 | - |
| `valve_target` | 1.0 | 0.0 | 1.0 | 0.0 | 1 |
| `valve_opening` | 1.0 | -1.86e-10 | 1.0 | 2.34e-35 | 1 |
| `tau_in` | 1400.0 | -2.61e-07 | 1400.0 | 3.28e-32 | N.m |
| `tau_load` | 1000.0 | 3.47e-05 | 1129.950 | 3.47e-05 | N.m |

*注：结果显示在第二次持续扰动期间，转速最高飙升至 112.995 rad/s，超速计时器达到 0.1 s 阈值触发停机保持，阀门完全关闭，转速最终衰减至接近 0。*

## 8) 运行与复现方法

1. 确保已安装支持 Modelica 的仿真环境（如 Dymola 或 OpenModelica）。
2. 将模型文件放置于相对路径 `./model/TurbineOverspeedTripEnhanced.mo`。
3. 在仿真环境中加载该文件。
4. 配置仿真参数：停止时间为 20s，求解器为 dassl，容差为 1e-6。
5. 运行仿真并查看 `omega`、`trip_latched` 及 `valve_opening` 等目标变量曲线，以复现超速保护与停机保持过程。