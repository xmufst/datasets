# SmithPredictorTemp 模型文档

## 1) 模型目的与范围

本模型（`SmithPredictorTemp`）旨在构建一个基于 **Smith预估器** 补偿纯滞后的温度跟踪闭环控制系统。在涉及大纯延迟的加热或化工过程中，常规PID控制往往导致系统超调增大或失稳，Smith预估器通过引入内部模型将纯延迟移出闭环特征方程，从而显著改善系统的动态响应与稳定性。

**物理机制与范围：**
- 一阶惯性加热过程
- 纯传输延迟
- 热力学平衡与散热特性
- Smith预估补偿机制
- PI闭环控制逻辑

## 2) 组件清单

本模型使用了以下 Modelica 标准库 (MSL) 组件：

| 组件路径 | 功能说明 |
| :--- | :--- |
| `Modelica.Blocks.Sources.Step` | 产生参考温度阶跃信号 |
| `Modelica.Blocks.Math.Feedback` | 计算参考温度与预估温度的跟踪误差 |
| `Modelica.Blocks.Continuous.PI` | 比例-积分(PI)控制器 |
| `Modelica.Blocks.Math.Add3` | 三输入加法器，用于实现 Smith 预估补偿逻辑 |

## 3) 参数表

| Name | Value | Unit | Description |
| :--- | :--- | :--- | :--- |
| `K_plant` | 1.0 | °C/unit | 对象静态增益 |
| `T_plant` | 20.0 | s | 对象时间常数 |
| `L` | 10.0 | s | 纯传输延迟时间 |
| `T_ref` | 80.0 | °C | 参考目标温度 |
| `T0` | 20.0 | °C | 环境/初始偏置温度 |
| `Kp` | 2.0 | - | PI 控制器比例增益 |
| `Ti` | 15.0 | s | PI 控制器积分时间常数 |

## 4) 初始条件

| Variable | Value | Description |
| :--- | :--- | :--- |
| `T_process` | 20.0 | 初始加热点温度 (等于环境温度 T0) |
| `T_model` | 20.0 | 初始内部模型温度 (等于环境温度 T0) |

## 5) 控制逻辑说明

本模型采用 Smith 预估器结合 PI 控制器来克服纯滞后对控制品质的不利影响，核心逻辑如下：

1. **参考信号生成**：`Step` 模块在 0 时刻产生幅值为 60°C（`T_ref - T0`）、偏置为 20°C 的阶跃信号，作为目标温度 `T_ref_signal`。
2. **误差计算**：`Feedback` 模块计算跟踪误差 `T_error = T_ref_signal - T_predicted`。
3. **PI 控制**：`PI` 控制器根据误差 `T_error` 计算控制量 `u_pi`，驱动被控对象和内部模型。
4. **对象与模型动态**：被控对象与内部模型均遵循一阶惯性加纯延迟特性。其中无延迟部分由微分方程 `T_plant * der(T) + (T - T0) = K_plant * u_pi` 描述。
5. **纯滞后处理**：被控对象输出 `T_process` 经延迟 `L` 秒后得到实测温度 `T_measured`；内部模型输出 `T_model` 经延迟 `L` 秒后得到 `T_model_delayed`。为避免仿真初始阶段的不连续，延迟模块在 `time <= L` 时输出初始温度 `T0`。
6. **Smith 预估补偿**：通过 `Add3` 模块实现预估温度计算 `T_predicted = T_measured + T_model - T_model_delayed`。该逻辑将无延迟的模型输出引入反馈回路，等效地消除了闭环特征方程中的延迟项，使 PI 控制器能够基于“无延迟”的预测状态进行快速调节。

## 6) 仿真设置

| 设置项 | 值 |
| :--- | :--- |
| 停止时间 (Stop Time) | 300 s |
| 步长 (Step Size) | 0.01 s |
| 求解器 (Solver) | dassl |
| 容差 (Tolerance) | 1e-06 |

## 7) 结果概览

针对目标变量的仿真统计摘要如下：

| Variable | Start | Final | Min | Max | Unit |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `T_measured` | 20.0 | 80.0 | 20.0 | 81.4 | °C |
| `T_predicted` | 20.0 | 80.0 | 20.0 | 81.4 | °C |
| `T_error` | 60.0 | -2.48e-07 | -1.4 | 60.0 | °C |
| `u_pi` | 120.0 | 60.0 | 59.86 | 120.0 | - |
| `T_ref_signal` | 80.0 | 80.0 | 80.0 | 80.0 | °C |
| `T_plant_output` | 20.0 | 80.0 | 20.0 | 81.4 | °C |
| `T_model_delayed` | 20.0 | 80.0 | 20.0 | 81.4 | °C |

*注：系统在 Smith 预估器的作用下，最大超调量约为 1.4°C，最终稳态误差趋近于 0，控制量 `u_pi` 最终稳定在 60.0 以维持热平衡。*

## 8) 运行与复现方法

1. **模型文件**：请确保模型文件位于相对路径 `./model/SmithPredictorTemp.mo`。
2. **导入环境**：使用支持 Modelica 的仿真环境（如 Dymola, OpenModelica, OMSimulator 等）加载该文件。
3. **仿真配置**：在仿真设置界面中，将停止时间设为 `300`，求解器选择 `dassl`，容差设为 `1e-06`，积分步长可设为 `0.01` 或由求解器自适应。
4. **执行仿真**：运行模型并绘制 `T_measured`、`T_predicted`、`T_error` 及 `u_pi` 等目标变量以复现控制效果。
5. **用例标识**：本次运行对应的 Case ID 为 `20260413_203655_SmithPredictorTemp`。