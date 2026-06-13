model CascadeTankPI
  "Cascade PI control of two series-connected water tanks"

  import Modelica.Blocks.Sources;
  import Modelica.Blocks.Math;
  import Modelica.Blocks.Continuous;
  import Modelica.Blocks.Nonlinear;

  // Tank parameters
  parameter Real A1 = 1.0 "Upper tank cross-section area (m2)";
  parameter Real A2 = 1.0 "Lower tank cross-section area (m2)";
  parameter Real k1 = 0.015 "Upper tank outlet flow coefficient (m2.5/s)";
  parameter Real k2 = 0.01 "Lower tank outlet flow coefficient (m2.5/s)";
  parameter Real Q_in_max = 0.05 "Maximum inflow rate (m3/s)";

  // Reference and initial conditions
  parameter Real h2_ref =  1.5 "Lower tank level setpoint (m)";
  parameter Real h1_0 = 0.5 "Upper tank initial level (m)";
  parameter Real h2_0 = 0.3 "Lower tank initial level (m)";

  // Outer loop PI parameters (controls h2, SLOW)
  parameter Real Kp_outer = 1.0 "Outer PI proportional gain";
  parameter Real Ti_outer = 40.0 "Outer PI integral time (s)";

  // Inner loop PI parameters (controls h1, FAST)
  parameter Real Kp_inner = 3.0 "Inner PI proportional gain";
  parameter Real Ti_inner = 8.0 "Inner PI integral time (s)";

  // ---- MSL control components ----
  // Outer loop: controls h2 -> outputs h1 setpoint
  Sources.Constant h2Setpoint(k = h2_ref)
    "Lower tank level setpoint";
  Math.Feedback outerError
    "Outer error = h2_ref - h2";
  Continuous.PI outerPI(
    k = Kp_outer, T = Ti_outer,
    initType = Modelica.Blocks.Types.Init.InitialState,
    x_start = 0)
    "Outer loop PI controller";

  // Inner loop: controls h1 -> outputs valve command
  Math.Feedback innerError
    "Inner error = h1_setpoint - h1";
  Continuous.PI innerPI(
    k = Kp_inner, T = Ti_inner,
    initType = Modelica.Blocks.Types.Init.InitialState,
    x_start = 0)
    "Inner loop PI controller";
  Nonlinear.Limiter valveLimiter(uMax = 1, uMin = 0)
    "Valve position saturation [0, 1]";

  // ---- Plant states ----
  Real h1(start = h1_0, fixed = true, unit = "m") "Upper tank level";
  Real h2(start = h2_0, fixed = true, unit = "m") "Lower tank level";

  // ---- Target output variables ----
  Real h2_error(unit = "m") "Lower tank level tracking error";
  Real Q_in(unit = "m3/s") "Inflow to upper tank";
  Real Q_12(unit = "m3/s") "Flow from upper to lower tank";
  Real Q_out(unit = "m3/s") "Outflow from lower tank";
  Real u_outer "Outer PI output (h1 setpoint)";
  Real u_inner "Inner PI output (valve command)";

equation
  // ===== Outer loop: h2 control =====
  connect(h2Setpoint.y, outerError.u1);
  outerError.u2 = h2;
  connect(outerError.y, outerPI.u);
  u_outer = outerPI.y;

  // ===== Inner loop: h1 control =====
  // Outer PI output serves as h1 setpoint
  innerError.u1 = outerPI.y;
  innerError.u2 = h1;
  connect(innerError.y, innerPI.u);
  connect(innerPI.y, valveLimiter.u);
  u_inner = innerPI.y;

  // ===== Valve and inflow =====
  Q_in = Q_in_max * valveLimiter.y;

  // ===== Plant dynamics =====
  // Upper tank: gravity-driven outflow to lower tank
  Q_12 = k1 * sqrt(max(h1, 0));
  A1 * der(h1) = Q_in - Q_12;

  // Lower tank: receives from upper, drains at bottom
  Q_out = k2 * sqrt(max(h2, 0));
  A2 * der(h2) = Q_12 - Q_out;

  // Target alias
  h2_error = outerError.y;

end CascadeTankPI;
