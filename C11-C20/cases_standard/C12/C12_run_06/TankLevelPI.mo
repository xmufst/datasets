model TankLevelPI
  "Water tank level control using MSL PI controller, Limiter, and Feedback blocks"

  import Modelica.Blocks.Continuous;
  import Modelica.Blocks.Nonlinear;
  import Modelica.Blocks.Sources;
  import Modelica.Blocks.Math;

  // Parameters
  parameter Real A_tank = 1.0 "Tank cross-section area (m2)";
  parameter Real k_out = 0.01 "Outlet flow coefficient (m2.5/s)";
  parameter Real Q_in_max = 0.05 "Maximum inflow rate (m3/s)";
  parameter Real h_ref =  1.2 "Level setpoint (m)";
  parameter Real h0 = 0.5 "Initial water level (m)";
  parameter Real Kp = 2.0 "PI proportional gain";
  parameter Real Ti = 4.0 "PI integral time (s)";

  // ---- MSL control components ----
  Sources.Constant setpoint(k = h_ref)
    "Level setpoint source";
  Math.Feedback feedback
    "Computes error = setpoint - measured level";
  Continuous.PI piController(
    k = Kp, T = Ti,
    initType = Modelica.Blocks.Types.Init.InitialState,
    x_start = 0)
    "PI controller";
  Nonlinear.Limiter limiter(uMax = 1, uMin = 0)
    "Valve position saturation [0, 1]";

  // ---- Plant state ----
  Real h(start = h0, fixed = true, unit = "m") "Water level";

  // ---- Target output variables ----
  Real h_error(unit = "m") "Level tracking error";
  Real Q_in(unit = "m3/s") "Inflow rate";
  Real Q_out(unit = "m3/s") "Outflow rate";
  Real u_pi "PI controller raw output";

equation
  // Control signal chain: setpoint -> feedback -> PI -> limiter
  connect(setpoint.y, feedback.u1);
  connect(feedback.y, piController.u);
  connect(piController.y, limiter.u);

  // Measured level fed back to error computation
  feedback.u2 = h;

  // Valve output to physical inflow
  Q_in = Q_in_max * limiter.y;

  // Gravity-driven outflow (proportional to sqrt of level)
  Q_out = k_out * sqrt(max(h, 0));

  // Plant dynamics: mass balance
  A_tank * der(h) = Q_in - Q_out;

  // Alias target variables for output
  h_error = feedback.y;
  u_pi = piController.y;

end TankLevelPI;
