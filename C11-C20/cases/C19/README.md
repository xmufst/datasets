# 加热炉温度前馈-反馈复合控制系统仿真

## 1) 模型目的与范围
本模型旨在仿真加热炉温度前馈加PI反馈复合控制系统。通过建立集总热容模型，基于能量守恒原理，模拟加热炉在环境散热、非负加热功率约束及外部热扰动下的温度动态响应，并验证前馈-反馈复合控制策略对参考温度的跟踪与抗扰性能。

## 2) 组件清单
本模型使用了以下 Modelica 标准库 (MSL) 组件：
- `Modelica.Blocks.Sources.Constant`：常数信号源（用于参考温度和基准功率）
- `Modelica.Blocks.Math.Feedback`：反馈计算模块（用于计算温度误差）
- `Modelica.Blocks.Continuous.PI`：PI 控制器模块
- `Modelica.Blocks.Sources.Step`：阶跃信号源（用于模拟扰动功率）
- `Modelica.Blocks.Math.Gain`：增益模块（用于前馈增益）
- `Modelica.Blocks.Math.Add3`：三通道加法器（用于合成控制信号）
- `Modelica.Blocks.Sources.RealExpression`：实数表达式信号源（用于提取炉温变量）

## 3) 参数表
| Name | Value | Unit | Description |
| :--- | :--- | :--- | :--- |
| `C_furnace` | 5000.0 | J/K | 加热炉热容 |
| `UA` | 5.0 | W/K | 散热系数 |
| `T_amb` | 20.0 | °C | 环境温度 |
| `T_ref` | 80.0 | °C | 参考温度 |
| `Q_ss` | 300.0 | W | 稳态基准加热功率 |
| `Q_dist` | 200.0 | W | 扰动功率阶跃幅值 |
| `t_dist` | 100.0 | s | 扰动施加时刻 |
| `K_ff` | 1.0 | 1 | 前馈增益 |
| `Kp` | 0.5 | W/°C | PI比例增益 |
| `Ti` | 50.0 | s | PI积分时间 |

## 4) 初始条件
| Variable | Value | Description |
| :--- | :--- | :--- |
| `T` | 80.0 | 初始炉温 (°C) |
| `PI_integrator_state` | 0.0 | PI控制器内部积分状态初始值 |

## 5) 控制逻辑说明
控制系统采用**前馈+PI反馈复合控制**策略，分为三个控制通道：
1. **基准通道**：通过 `Constant` 模块提供稳态基准加热功率 `Q_ss`，用于维持初始无扰动状态下的热量平衡。
2. **PI反馈通道**：参考温度 `T_ref` 与实际炉温 `T` 通过 `Feedback` 模块计算得到温度误差 `T_error`，误差信号输入 `PI` 控制器产生反馈校正功率 `u_pi`，用于消除残余误差。
3. **前馈通道**：扰动阶跃信号 `Q_disturbance` 经 `Gain` 模块乘以前馈增益 `K_ff` 后产生前馈补偿功率 `u_ff`，在扰动发生时提前动作，快速抵消扰动影响。

三通道信号通过 `Add3` 合成总输出信号 `u_total`。实际加热功率 `Q_heater` 受非负约束（`max(0, u_total)`），防止出现负加热物理异常。

## 6) 仿真设置
- **停止时间 (Stop Time)**: 500 s
- **步长 (Step Size)**: 0.01 s
- **求解器 (Solver)**: dassl
- **容差 (Tolerance)**: 1e-06

## 7) 结果概览
目标变量在仿真过程中的统计摘要如下：

| Variable | Start | Final | Min | Max | Unit |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `T` | 80.0 | 80.0 | 80.0 | 80.0 | degC |
| `T_error` | 0.0 | 0.0 | 0.0 | 0.0 | degC |
| `u_pi` | 0.0 | 0.0 | 0.0 | 0.0 | W |
| `u_ff` | 0.0 | 200.0 | 0.0 | 200.0 | W |
| `u_total` | 300.0 | 500.0 | 300.0 | 500.0 | W |
| `Q_heater` | 300.0 | 500.0 | 300.0 | 500.0 | W |
| `Q_loss` | 300.0 | 300.0 | 300.0 | 300.0 | W |
| `Q_disturbance` | 0.0 | 200.0 | 0.0 | 200.0 | W |

**结果分析**：由于前馈增益 `K_ff` 设置为1，实现了对扰动 `Q_disturbance` 的完全补偿。在 100s 施加 200W 扰动时，前馈通道 `u_ff` 立即提供 200W 补偿，使得炉温 `T` 始终保持在 80.0°C，温度误差 `T_error` 和 PI 校正量 `u_pi` 全程保持为 0，体现了前馈控制对可测量扰动的高效抑制能力。

## 8) 运行与复现方法
1. 确保已安装支持 Modelica 标准库的开源或商业仿真环境（如 OpenModelica, Dymola 等）。
2. 将模型文件放置于相对路径 `./model/FeedforwardFeedbackTemp.mo`。
3. 在仿真环境中加载该模型文件。
4. 配置仿真参数：设置仿真时长为 500s，求解器选择 dassl，容差设为 1e-06。
5. 运行仿真并绘制 `T`, `T_error`, `u_ff`, `Q_heater` 等目标变量曲线以复现结果。