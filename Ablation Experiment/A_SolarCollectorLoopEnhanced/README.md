# SolarCollectorLoopEnhanced 模型文档

## 1) 模型目的与范围

本模型（`SolarCollectorLoopEnhanced`）旨在描述水工质在太阳辐照作用下的温度变化过程，模拟一个简化的太阳能集热器循环系统。模型的物理机制涵盖了以下方面：
- **太阳辐照加热**：通过太阳辐照度、集热器面积和效率计算有效吸热量。
- **集中参数热容**：将水工质视为集中参数的热容系统，计算温度随时间的动态响应。
- **一阶线性环境散热**：考虑系统与外界环境之间的一阶线性热损失。
- **摄氏度与开尔文温度转换**：方便工程查看，同时输出开尔文与摄氏度温度及压力的不同单位。

## 2) 组件清单

本模型采用纯数学方程构建，**未使用** Modelica 标准库（MSL）中的组件。

## 3) 参数表

| Name | Value | Unit | Description |
| :--- | :--- | :--- | :--- |
| `p_system` | 101325 | Pa | 系统运行压力 |
| `G_solar` | 500 | W/m2 | 太阳辐照热流密度 |
| `A_collector` | 2.0 | m2 | 集热器面积 |
| `eta_collector` | 0.7 | 1 | 集热效率 |
| `m_water` | 5.0 | kg | 水质量 |
| `cp_water` | 4184 | J/(kg.K) | 水比热容 |
| `T_ambient` | 20.0 | degC | 环境温度 |
| `h_loss` | 5.0 | W/K | 环境散热系数 |

## 4) 初始条件

| Variable | Value | Description |
| :--- | :--- | :--- |
| `T_water` | 293.15 K (20.0 °C) | 水工质初始温度 |
| `p_system` | 101325 Pa | 系统初始压力 |

## 5) 控制逻辑说明

本模型**不包含**控制逻辑。系统在恒定的太阳辐照和恒定的环境条件下进行开环动态响应仿真。

## 6) 仿真设置

| Setting | Value |
| :--- | :--- |
| 停止时间 (Stop Time) | 600 s |
| 步长 (Step Size) | 0.01 s |
| 求解器 (Solver) | dassl |
| 容差 (Tolerance) | 1e-06 |

## 7) 结果概览

在 600 秒的仿真时间内，系统在恒定太阳辐照下吸热，水温逐渐上升，同时散热损失随温差增大而增加。目标变量的统计摘要如下：

| Variable | Start | Final | Min | Max | Unit |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `T_water` | 293.15 | 311.85 | 293.15 | 311.85 | K |
| `T_water_C` | 20.00 | 38.70 | 20.00 | 38.70 | degC |
| `Q_solar` | 700.00 | 700.00 | 700.00 | 700.00 | W |
| `Q_loss` | 0.00 | 93.52 | 0.00 | 93.52 | W |
| `p_system` | 101325.00 | 101325.00 | 101325.00 | 101325.00 | Pa |
| `p_system_bar` | 1.01 | 1.01 | 1.01 | 1.01 | bar |
| `collector_power_density`| 350.00 | 350.00 | 350.00 | 350.00 | W/m2 |

**结果分析**：水工质温度从 20°C 上升至约 38.7°C；集热器吸收的恒定太阳功率为 700 W，随着水温升高，散热损失从 0 W 增加至约 93.5 W，系统逐渐趋于热平衡。

## 8) 运行与复现方法

### 依赖环境
- Modelica 编译环境（如 Dymola 或 OpenModelica）

### 文件结构
- 模型文件：`./SolarCollectorLoopEnhanced.mo`

### 复现步骤
1. 将 `./SolarCollectorLoopEnhanced.mo` 加载至 Modelica 开发环境中。
2. 在仿真设置中，配置求解器为 `dassl`，停止时间为 `600`，容差为 `1e-06`。
3. 运行仿真。
4. 绘制目标变量（`T_water_C`, `Q_solar`, `Q_loss` 等）以复现结果。

*(如使用 OpenModelica 命令行，可执行：)*
```modelica
loadFile("./SolarCollectorLoopEnhanced.mo");
simulate(SolarCollectorLoopEnhanced, startTime=0, stopTime=600, numberOfIntervals=60000, method="dassl", tolerance=1e-6);