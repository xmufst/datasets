model ThermostatWaterTank
  // Parameters with description and unit
  parameter Real C = 1000.0 "Heat capacity of water tank (J/K)";
  parameter Real Q_heater =  300.0 "Rated heating power (W)";
  parameter Real UA = 5.0 "Heat loss coefficient (W/K)";
  parameter Real T_amb = 20.0 "Ambient temperature (degC)";
  parameter Real T_set = 60.0 "Temperature setpoint (degC)";
  parameter Real deadband = 2.0 "Hysteresis bandwidth (K)";
  
  // Variables with start and unit attributes
  Real T(start=25.0, unit="degC") "Water tank temperature";
  Real Q_in(unit="W") "Heating power input";
  Real Q_loss(unit="W") "Heat loss to ambient";
  Real T_error(unit="degC") "Temperature error (setpoint - actual)";
  Boolean heater_on "Heater on/off state";
  
  // Standard library components
  Modelica.Blocks.Sources.Constant T_set_const(k=T_set) "Temperature setpoint source";
  Modelica.Blocks.Math.Feedback feedback "Error calculation block";
  Modelica.Blocks.Logical.Hysteresis hysteresis(
    uHigh=deadband/2,
    uLow=-deadband/2,
    pre_y_start=false) "Hysteresis relay controller";
  Modelica.Blocks.Math.BooleanToReal booleanToReal(
    realTrue=Q_heater,
    realFalse=0) "Convert boolean to heating power";
  
equation
  // Physical model of water tank
  der(T) = (Q_in - Q_loss) / C;
  Q_loss = UA * (T - T_amb);
  
  // Control signal connections
  connect(T_set_const.y, feedback.u1);
  feedback.u2 = T;  // Connect measured temperature to feedback
  connect(feedback.y, hysteresis.u);
  connect(hysteresis.y, booleanToReal.u);
  Q_in = booleanToReal.y;
  
  // Additional output variables
  heater_on = hysteresis.y;
  T_error = feedback.y;
  
  annotation(experiment(StartTime=0, StopTime=500, Tolerance=1e-6, Interval=0.01));
end ThermostatWaterTank;
