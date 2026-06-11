model FurnaceFeedforward
  "Furnace temperature control with pure feedforward compensation"

  import Modelica.Blocks.Sources;
  import Modelica.Blocks.Math;

  // Plant parameters
  parameter Real C_furnace = 5000.0 "Furnace thermal capacity (J/K)";
  parameter Real K_heater = 100.0 "Heater power gain (W/unit)";
  parameter Real UA = 5.0 "Heat loss coefficient to ambient (W/K)";
  parameter Real T_amb = 20.0 "Ambient temperature (degC)";
  parameter Real Q_ss = 300.0 "Steady-state heating power without disturbance (W)";
  parameter Real T0 = 80.0 "Initial furnace temperature (degC)";

  // Disturbance parameters
  parameter Real Q_dist = 200.0 "Disturbance power step magnitude (W)";
  parameter Real t_dist = 100.0 "Disturbance step time (s)";

  // Feedforward parameter
  parameter Real K_ff =  1.2 "Feedforward gain (1.0 = ideal compensation)";

  // ---- MSL components ----
  Sources.Constant steadyStateHeat(k = Q_ss)
    "Baseline heating power (constant)";
  Sources.Step disturbanceSignal(height = Q_dist, startTime = t_dist)
    "Measurable disturbance step signal";
  Math.Gain feedforwardGain(k = K_ff)
    "Feedforward compensation gain";
  Math.Add heaterSum(k1 = +1, k2 = +1)
    "Total heater power = Q_ss + K_ff * Q_dist";

  // ---- Plant state ----
  Real T(start = T0, fixed = true, unit = "degC") "Furnace temperature";

  // ---- Target output variables ----
  Real Q_heater(unit = "W") "Total heating power";
  Real Q_loss(unit = "W") "Heat loss to ambient";
  Real Q_disturbance(unit = "W") "Disturbance heat load";
  Real u_ff "Feedforward compensation signal";

equation
  // Feedforward control chain:
  // disturbance measurement -> feedforward gain -> add to baseline
  connect(disturbanceSignal.y, feedforwardGain.u);
  connect(steadyStateHeat.y, heaterSum.u1);
  connect(feedforwardGain.y, heaterSum.u2);

  // Total heater power
  Q_heater = heaterSum.y;

  // Feedforward compensation signal
  u_ff = feedforwardGain.y;

  // Disturbance power
  Q_disturbance = disturbanceSignal.y;

  // Heat loss to ambient
  Q_loss = UA * (T - T_amb);

  // Energy balance: furnace dynamics
  C_furnace * der(T) = Q_heater - Q_loss - Q_disturbance;

end FurnaceFeedforward;
