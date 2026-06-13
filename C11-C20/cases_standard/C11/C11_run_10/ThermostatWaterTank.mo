model ThermostatWaterTank "使用MSL标准组件的恒温水箱控制模型"
  // 物理参数
  parameter Real C = 1000.0 "水箱热容 (J/K)";
  parameter Real Q_heater =  2000.0 "加热器额定功率 (W)";
  parameter Real UA = 5.0 "散热系数 (W/K)";
  parameter Real T_amb = 20.0 "环境温度 (degC)";
  parameter Real T_set = 60.0 "目标温度设定值 (degC)";
  parameter Real deadband = 2.0 "迟滞带宽 (K)";
  parameter Real T0 = 25.0 "初始水箱温度 (degC)";

  // 物理变量 (被控对象)
  Real T(start = T0, fixed = true, unit = "degC") "水箱实时温度";
  Real Q_in(unit = "W") "实际输入热功率";
  Real Q_loss(unit = "W") "散热功率";
  Real T_error(unit = "K") "温度误差";

  // 实例化 MSL 标准组件
  Modelica.Blocks.Sources.Constant setpoint(k = T_set) "设定值信号源";
  Modelica.Blocks.Math.Feedback feedback "反馈计算 (设定值 - 测量值)";
  Modelica.Blocks.Logical.Hysteresis controller(uLow = -deadband/2, uHigh = deadband/2) "迟滞继电器";

  // 定义控制器的布尔输出转 Real 的中间变量（用于 Q_in 计算）
  Boolean heater_on "加热器指令状态";

equation
  // 被控对象物理方程
  Q_loss = UA * (T - T_amb);
  C * der(T) = Q_in - Q_loss;
  T_error = T_set - T;

  // 组件连接 (信号流)
  connect(setpoint.y, feedback.u1);
  feedback.u2 = T; // 传感器测量值
  connect(feedback.y, controller.u);

  // 执行器逻辑
  heater_on = controller.y;
  Q_in = if heater_on then Q_heater else 0;

end ThermostatWaterTank;