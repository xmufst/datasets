# PiecewiseAdiabaticStirredTank 模型文档

## 1) 模型目的与范围
**目的**：本模型用于模拟绝热搅拌槽，分析分段搅拌功率输入对槽内液体温度变化的影响。
**范围**：模型基于集中参数热容和绝热系统假设，不涉及与外界的热交换，仅考虑搅拌功转化为热能导致的液体温升，并严格遵循能量守恒定律。

## 2) 组件清单
本模型为纯方程式模型，未使用 Modelica 标准库 (MSL) 的物理组件，所有逻辑均通过数学方程直接实现。

## 3) 参数表
| Name | Value | Unit | Description |
| :--- | :--- | :--- | :--- |
| `m_liquid` | 10 | kg | 液体质量 |
| `cp_liquid` | 4184 | J/(kg·K) | 液体比热容 |
| `P_stir_phase1` | 500 | W | 第一阶段搅拌功率 |
| `P_stir_phase2` | 1000 | W | 第二阶段搅拌功率 |
| `P_stir_phase3` | 0 | W | 第三阶段搅拌功率 |
| `t_end_phase1` | 300 | s | 第一阶段结束时刻 |
| `t_end_phase2` | 600 | s | 第二阶段结束时刻 |

## 4) 初始条件
| Variable | Value | Description |
| :--- | :--- | :--- |
| `T_liquid` | 293.15 K (20.0 °C) | 初始液体温度 |
| `energy_added` | 0 J | 累计输入搅拌能量初始值 |
| `energy_residual` | 0 J | 能量残差初始值 |

## 5) 控制逻辑说明
模型通过时间条件判断实现分段搅拌功率输入，采用 `noEvent` 操作符避免不必要的状态事件触发，逻辑如下：
- 当 `time < t_end_phase1` (0-300s) 时，`P_stir = P_stir_phase1` (500 W)；
- 当 `t_end_phase1 <= time < t_end_phase2` (300-600s) 时，`P_stir = P_stir_phase2` (1000 W)；
- 当 `time >= t_end_phase2` (600s及以后) 时，`P_stir = P_stir_phase3` (0 W)。

理论温升速率由 `dTdt_theoretical = P_stir / (m_liquid * cp_liquid)` 计算，并直接作为液体温度的导数 `der(T_liquid)`。

## 6) 仿真设置
| Setting | Value |
| :--- | :--- |
| 停止时间 (Stop Time) | 1000 s |
| 步长 (Step Size) | 0.1 s |
| 求解器 (Solver) | dassl |
| 容差 (Tolerance) | 1e-06 |

## 7) 结果概览
目标变量在仿真过程中的统计摘要如下：

| Variable | Start | Final | Min | Max | Unit |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `T_liquid` | 293.15 | 303.905 | 293.15 | 303.905 | K |
| `T_liquid_C` | 20.0 | 30.755 | 20.0 | 30.755 | degC |
| `P_stir` | 500.0 | 0.0 | 0.0 | 1000.0 | W |
| `dTdt_theoretical` | 0.01195 | 0.0 | 0.0 | 0.0239 | K/s |
| `energy_added` | 0.0 | 449998.058 | 0.0 | 449998.058 | J |
| `energy_stored` | 0.0 | 449998.058 | 0.0 | 449998.058 | J |
| `energy_residual` | 0.0 | ~1.51e-09 | -1.72e-09 | 4.16e-09 | J |

**分析**：液体温度最终上升约 10.755 K。`energy_residual`（输入能量与存储能量之差）在仿真结束时接近于 0（数量级为 1e-09），验证了绝热系统下的能量守恒及仿真计算的高精度。

## 8) 运行与复现方法
1. 确保已安装支持 Modelica 的仿真环境（如 Dymola, OpenModelica 等）。
2. 将模型文件放置于相对路径 `./model/PiecewiseAdiabaticStirredTank.mo` 下。
3. 在仿真环境中加载该模型文件。
4. 配置仿真参数：设置 Stop Time 为 `1000`，Solver 为 `dassl`，Tolerance 为 `1e-06`。
5. 运行仿真并绘制 `T_liquid_C`、`P_stir` 及 `energy_residual` 等目标变量以复现结果。