# RCCircuit 一阶RC电路充放电模型

## 1. 模型目的与范围
本模型旨在模拟由电阻和电容串联组成的一阶RC电路的充电和放电过程。通过阶跃电压源激励，模型展示了RC电路的瞬态响应特性，涵盖的物理机制包括：
- RC充放电过程
- 阶跃电压响应
- 能量耗散与储能机制

## 2. 组件清单
本模型使用了以下 Modelica 标准库 (MSL) 组件：
- `Modelica.Electrical.Analog.Basic.Resistor`：电阻元件
- `Modelica.Electrical.Analog.Basic.Capacitor`：电容元件
- `Modelica.Electrical.Analog.Basic.Ground`：接地元件
- `Modelica.Electrical.Analog.Sources.SignalVoltage`：信号电压源
- `Modelica.Blocks.Sources.Step`：阶跃信号源

## 3. 参数表
| Name | Value | Unit | Description |
|---|---|---|---|
| R | 1000.0 | Ω | 电阻 |
| C | 0.001 | F | 电容 |
| V_source | 10.0 | V | 电压源幅值 |
| t_switch | 5.0 | s | 电源断开时刻 |

## 4. 初始条件
| Variable | Value | Description |
|---|---|---|
| Vc | 0.0 | 电容初始电压 |
| E_dissipated | 0.0 | 初始累积耗散能量 |

## 5. 控制逻辑说明
本模型**不包含**显式的闭环控制逻辑。电路的充放电切换通过开环信号驱动实现：
- 使用 `Modelica.Blocks.Sources.Step` 产生阶跃信号，初始幅值为 `V_source`，在 `t_switch` 时刻幅值下降 `V_source`（即输出降为0V）。
- 该阶跃信号输入至 `SignalVoltage`，控制电路输入电压 `V_in` 在 0~5s 保持 10V，在 5~10s 变为 0V，从而自然触发电容的充电（0~5s）和放电（5~10s）过程。

## 6. 仿真设置
| Setting | Value |
|---|---|
| Stop Time | 10 s |
| Step Size | 0.01 s |
| Solver Method | dassl |
| Tolerance | 1e-06 |

## 7. 结果概览
仿真运行后，目标变量的统计摘要如下：

| Variable | Start | Final | Min | Max | Unit |
|---|---|---|---|---|---|
| Vc | 0.0 | 0.0669 | 0.0 | 9.9326 | V |
| V_in | 10.0 | 0.0 | 0.0 | 10.0 | V |
| i | 0.01 | -6.69e-05 | -0.00993 | 0.01 | A |
| P_resistor | 0.1 | 4.48e-06 | 4.48e-06 | 0.1 | W |
| E_capacitor | 0.0 | 2.24e-06 | 0.0 | 0.0493 | J |
| E_dissipated | 0.0 | 0.0993 | 0.0 | 0.0993 | J |
| tau | 1.0 | 1.0 | 1.0 | 1.0 | s |

*注：时间常数 `tau` 为 R 与 C 的乘积，恒为 1.0s；电容最终电压趋近于0，耗散能量最终约为0.0993J，符合理论预期。*

## 8. 运行与复现方法
1. **环境准备**：确保已安装支持 Modelica 的仿真环境（如 Dymola、OpenModelica 或 OMEdit）。
2. **获取模型文件**：模型文件位于 `./model/RCCircuit.mo`。
3. **加载模型**：在仿真环境中打开或导入上述 `.mo` 文件。
4. **仿真设置**：配置仿真参数（Stop Time=10, Solver=dassl, Tolerance=1e-06）。
5. **执行仿真**：运行 `RCCircuit` 模型。
6. **结果查看**：仿真结束后，绘制 `Vc`、`i`、`E_dissipated` 等目标变量即可复现结果概览中的数据。