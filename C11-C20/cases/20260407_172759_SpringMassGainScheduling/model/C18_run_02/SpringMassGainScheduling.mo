model SpringMassGainScheduling
  // Parameters with description and unit annotations
  parameter Real m = 1.0 "Mass (kg)";
  parameter Real k_base = 10.0 "Base spring stiffness (N/m)";
  parameter Real k_nl = 5.0 "Nonlinear spring coefficient (cubic term) (N/m^3)";
  parameter Real c = 2.0 "Damping coefficient (N·s/m)";
  parameter Real x_ref =  0.5 "Reference position step amplitude (m)";
  parameter Real Kp_low = 30.0 "Low zone proportional gain (|x| < 0.5 m) (N/m)";
  parameter Real Kp_mid = 50.0 "Mid zone proportional gain (0.5 ≤ |x| < 1.5 m) (N/m)";
  parameter Real Kp_high = 80.0 "High zone proportional gain (|x| ≥ 1.5 m) (N/m)";
  parameter Real Kd = 5.0 "Derivative gain (unified) (N·s/m)";
  parameter Real zone1 = 0.5 "Low/mid zone boundary (m)";
  parameter Real zone2 = 1.5 "Mid/high zone boundary (m)";
  
  // Variables with start values and units
  Real x(start = 0.0, unit = "m") "Mass position";
  Real v(start = 0.0, unit = "m/s") "Mass velocity";
  Real a(unit = "m/s^2") "Acceleration";
  Real x_error(unit = "m") "Position tracking error";
  Real F_control(unit = "N") "Control force";
  Real F_spring(unit = "N") "Nonlinear spring force";
  Real Kp_current(unit = "N/m") "Current proportional gain";
  Real E_kinetic(unit = "J") "Kinetic energy";
  
  // Reference signal source (Step input)
  Modelica.Blocks.Sources.Step step_ref(
    height = x_ref,
    offset = 0,
    startTime = 0)
    annotation(Placement(transformation(extent={{-80,20},{-60,40}})));
  
  Real x_ref_signal "Reference position signal from Step block";
  
equation
  // Get reference signal from Step block
  x_ref_signal = step_ref.y;
  
  // Calculate tracking error
  x_error = x_ref_signal - x;
  
  // Gain scheduling based on absolute position
  if abs(x) < zone1 then
    Kp_current = Kp_low;
  elseif abs(x) >= zone1 and abs(x) < zone2 then
    Kp_current = Kp_mid;
  else
    Kp_current = Kp_high;
  end if;
  
  // PD control law
  F_control = Kp_current * x_error - Kd * v;
  
  // Nonlinear spring force
  F_spring = k_base * x + k_nl * x^3;
  
  // Newton's second law: m*a = F_control - F_spring - c*v
  m * a = F_control - F_spring - c * v;
  
  // Kinematic relationships
  der(x) = v;
  der(v) = a;
  
  // Kinetic energy
  E_kinetic = 0.5 * m * v^2;
  
  annotation(experiment(StopTime=20, Interval=0.01));
end SpringMassGainScheduling;
