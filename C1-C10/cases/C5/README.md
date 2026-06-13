# DualSpringMass 模型文档

## 1) 模型目的与范围
**模型名称**：DualSpringMass  
**模型描述**：模拟由两个质量块和两根线性弹簧组成的二自由度耦合振动系统的自由振动过程，展示模态耦合与拍频效应。  
**物理机制**：涵盖自由振动、模态耦合、拍频效应以及能量守恒定律。

## 2) 组件清单
本模型采用基于方程的数学建模方式，未直接实例化 MSL (Modelica Standard Library) 组件。其物理结构等效于以下 MSL 组件组合：
- `Modelica.Mechanics.Translational.Components.Mass`（质量块 m1, m2）
- `Modelica.Mechanics.Translational.Components.Spring`（弹簧 k1, k2）
- `Modelica.Mechanics.Translational.Components.Fixed`（固定墙端点）

## 3) 参数表
| Name | Value | Unit | Description |
| :--- | :--- | :--- | :--- |
| m1 | 1.0 | kg | 质量块1质量 |
| m2 | 1.0 | kg | 质量块2质量 |
| k1 | 100.0 | N/m | 弹簧1刚度（墙到m1） |
| k2 | 50.0 | N/m | 弹簧2刚度（m1到m2） |
| x1_0 | 0.5 | m | 质量块1初始位移 |
| x2_0 | 0.0 | m | 质量块2初始位移 |
| v1_0 | 0.0 | m/s | 质量块1初始速度 |
| v2_0 | 0.0 | m/s | 质量块2初始速度 |

## 4) 初始条件
| Variable | Value | Description |
| :--- | :--- | :--- |
| x1 | x1_0 (0.5) | 质量块1初始位移 |
| v1 | v1_0 (0.0) | 质量块1初始速度 |
| x2 | x2_0 (0.0) | 质量块2初始位移 |
| v2 | v2_0 (0.0) | 质量块2初始速度 |

## 5) 控制逻辑说明
本模型无控制逻辑，为纯物理自由振动系统。系统动力学完全由牛顿第二定律及弹簧胡克定律决定：
- 质量块1受力方程：`m1 * der(v1) = -k1 * x1 + k2 * (x2 - x1)`
- 质量块2受力方程：`m2 * der(v2) = -k2 * (x2 - x1)`

## 6) 仿真设置
| Setting | Value |
| :--- | :--- |
| Stop Time | 10 s |
| Step Size | 0.01 s |
| Solver Method | dassl |
| Tolerance | 1e-06 |

## 7) 结果概览
目标变量在仿真时间内的统计摘要如下：

| Variable | Start | Final | Min | Max | Unit |
| :--- | :--- | :--- | :--- | :--- | :--- |
| x1 | 0.5 | 0.0626 | -0.4998 | 0.5 | m |
| v1 | 0.0 | 5.6177 | -5.9313 | 5.9658 | m/s |
| x2 | 0.0 | -0.1827 | -0.3518 | 0.3523 | m |
| v2 | 0.0 | -1.5942 | -3.2322 | 3.2626 | m/s |
| F_spring1 | 50.0 | 6.2616 | -49.9822 | 50.0 | N |
| F_spring2 | -25.0 | -12.2636 | -35.2430 | 35.2274 | N |
| delta_x | -0.5 | -0.2453 | -0.7049 | 0.7045 | m |
| E_kinetic | 0.0 | 17.0499 | 0.0 | 18.7277 | J |
| E_potential | 18.75 | 1.7000 | 0.0223 | 18.75 | J |
| E_total | 18.75 | 18.7499 | 18.7499 | 18.75 | J |

**结果分析**：系统的总机械能（`E_total`）在仿真过程中最大值为 18.75 J，最小值为 18.7499 J，基本保持恒定，验证了无阻尼系统的能量守恒特性。质量块1和质量块2的位移与速度呈现出明显的拍频效应与模态耦合特征。

## 8) 运行与复现方法
1. 确保已安装 OpenModelica 或其他兼容的 Modelica 仿真环境。
2. 将模型文件放置于相对路径 `./model/DualSpringMass.mo`。
3. 运行以下脚本以加载模型、配置参数并执行仿真：

```modelica
loadFile("./model/DualSpringMass.mo");
simulate(DualSpringMass, stopTime=10, stepSize=0.01, method="dassl", tolerance=1e-06);
```

4. 仿真结束后，可使用绘图工具查看目标变量（如 `x1`, `x2`, `E_total`）的时域响应曲线。