model SpringMassGainScheduling
  "Nonlinear spring-mass system with position-based gain scheduling"

  import Modelica.Blocks.Sources;

  // Plant parameters
  parameter Real m = 1.0 "Mass (kg)";
  parameter Real k_base = 10.0 "Base spring stiffness (N/m)";
  parameter Real k_nl = 5.0 "Nonlinear (cubic) spring coefficient (N/m3)";
  parameter Real c = 2.0 "Damping coefficient (N.s/m)";

  // Reference and initial conditions
  parameter Real x_ref =  1.8 "Reference position step (m)";
  parameter Real x0 = 0.0 "Initial position (m)";
  parameter Real v0 = 0.0 "Initial velocity (m/s)";

  // Gain scheduling parameters
  parameter Real Kp_low = 30.0 "Proportional gain for |x| < 0.5 m (N/m)";
  parameter Real Kp_mid = 50.0 "Proportional gain for 0.5 <= |x| < 1.5 m (N/m)";
  parameter Real Kp_high = 80.0 "Proportional gain for |x| >= 1.5 m (N/m)";
  parameter Real Kd = 5.0 "Derivative gain, uniform (N.s/m)";

  // Gain zone boundaries
  parameter Real zone1 = 0.5 "Low/mid zone boundary (m)";
  parameter Real zone2 = 1.5 "Mid/high zone boundary (m)";

  // ---- MSL component ----
  Sources.Step refSignal(height = x_ref, startTime = 0)
    "Reference position step input";

  // ---- State variables ----
  Real x(start = x0, fixed = true, unit = "m") "Position";
  Real v(start = v0, fixed = true, unit = "m/s") "Velocity";

  // ---- Target output variables ----
  Real a(unit = "m/s2") "Acceleration";
  Real x_error(unit = "m") "Position tracking error";
  Real F_control(unit = "N") "Control force";
  Real F_spring(unit = "N") "Spring force (nonlinear)";
  Real Kp_current(unit = "N/m") "Currently active proportional gain";
  Real E_kinetic(unit = "J") "Kinetic energy";

equation
  // Position error
  x_error = refSignal.y - x;

  // Gain scheduling: select Kp based on current position
  Kp_current = if abs(x) < zone1 then Kp_low
               elseif abs(x) < zone2 then Kp_mid
               else Kp_high;

  // Control force: PD with scheduled Kp
  F_control = Kp_current * x_error - Kd * v;

  // Nonlinear spring force (hardening spring)
  F_spring = k_base * x + k_nl * x ^ 3;

  // Equations of motion
  der(x) = v;
  m * a = F_control - F_spring - c * v;
  der(v) = a;

  // Kinetic energy
  E_kinetic = 0.5 * m * v ^ 2;

end SpringMassGainScheduling;
