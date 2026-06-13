model CascadeTankPI
  "Cascade PI control dual-tank level system simulation model"

  // ---------- Parameters ----------
  parameter Real A1 = 1.0 "Upper tank cross-sectional area (m2)";
  parameter Real A2 = 1.0 "Lower tank cross-sectional area (m2)";
  parameter Real k1 = 0.015 "Upper tank outlet flow coefficient (m^2.5/s)";
  parameter Real k2 = 0.01 "Lower tank outlet flow coefficient (m^2.5/s)";
  parameter Real Q_in_max = 0.05 "Maximum inlet flow rate (m3/s)";
  parameter Real h2_ref =  0.7 "Lower tank setpoint level (m)";
  parameter Real Kp_outer = 1.0 "Outer-loop PI proportional gain (1)";
  parameter Real Ti_outer = 40.0 "Outer-loop PI integral time (s)";
  parameter Real Kp_inner = 3.0 "Inner-loop PI proportional gain (1)";
  parameter Real Ti_inner = 8.0 "Inner-loop PI integral time (s)";

  // ---------- Physical state variables ----------
  Real h1(start = 0.5, fixed = true, unit = "m") "Upper tank real-time level";
  Real h2(start = 0.3, fixed = true, unit = "m") "Lower tank real-time level";

  // ---------- Target variables ----------
  Real h2_error(unit = "m") "Lower tank level tracking error";
  Real Q_in(unit = "m3/s") "Upper tank actual inlet flow rate";
  Real Q_12(unit = "m3/s") "Flow from upper tank to lower tank";
  Real Q_out(unit = "m3/s") "Lower tank outlet flow rate";
  Real u_outer(unit = "m") "Outer-loop PI output (upper tank level setpoint)";
  Real u_inner(unit = "1") "Inner-loop PI raw output signal";

  // ---------- MSL Control Components ----------

  // Outer loop
  Modelica.Blocks.Sources.Constant h2_ref_source(k = h2_ref)
    "Lower tank level setpoint constant";
  Modelica.Blocks.Math.Feedback outer_feedback
    "Outer loop feedback: h2_ref - h2";
  Modelica.Blocks.Continuous.PI outer_PI(
    k = Kp_outer,
    T = Ti_outer,
    initType = Modelica.Blocks.Types.Init.InitialState,
    x_start = 0)
    "Outer loop PI controller";

  // Inner loop
  Modelica.Blocks.Math.Feedback inner_feedback
    "Inner loop feedback: u_outer - h1";
  Modelica.Blocks.Continuous.PI inner_PI(
    k = Kp_inner,
    T = Ti_inner,
    initType = Modelica.Blocks.Types.Init.InitialState,
    x_start = 0)
    "Inner loop PI controller";
  Modelica.Blocks.Nonlinear.Limiter valve_limiter(uMax = 1.0, uMin = 0.0)
    "Valve opening limiter [0, 1]";

  // Signal from physical variables to control blocks
  Modelica.Blocks.Sources.RealExpression h2_signal(y = h2)
    "Lower tank level as RealExpression signal";
  Modelica.Blocks.Sources.RealExpression h1_signal(y = h1)
    "Upper tank level as RealExpression signal";

equation
  // ---------- Physical equations (mass balance + gravity-driven outflow) ----------
  Q_12 = k1 * sqrt(max(h1, 0));
  Q_out = k2 * sqrt(max(h2, 0));
  A1 * der(h1) = Q_in - Q_12;
  A2 * der(h2) = Q_12 - Q_out;

  // ---------- Target variable equations ----------
  h2_error = h2_ref - h2;
  u_outer = outer_PI.y;
  u_inner = inner_PI.y;

  // ---------- Execution logic: valve opening -> actual flow ----------
  Q_in = valve_limiter.y * Q_in_max;

  // ---------- Control loop connections ----------
  // Outer loop
  connect(h2_ref_source.y, outer_feedback.u1);
  connect(h2_signal.y, outer_feedback.u2);
  connect(outer_feedback.y, outer_PI.u);

  // Inner loop
  connect(outer_PI.y, inner_feedback.u1);
  connect(h1_signal.y, inner_feedback.u2);
  connect(inner_feedback.y, inner_PI.u);
  connect(inner_PI.y, valve_limiter.u);

end CascadeTankPI;
