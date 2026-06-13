model FallingWithDrag
  // Parameters
  parameter Real m = 1.0 "Object mass (kg)";
  parameter Real g =  5.0 "Gravity acceleration (m/s2)";
  parameter Real b = 0.04 "Comprehensive drag coefficient (kg/m)";
  parameter Real v0 = 0.0 "Initial falling velocity (m/s)";
  
  // Variables with start values and units
  Real y(start = 0, unit = "m") "Falling distance";
  Real v(start = v0, unit = "m/s") "Velocity";
  
  // Intermediate and output variables
  Real v_ratio "Velocity ratio v/v_terminal";
  Real F_gravity(unit = "N") "Gravity force";
  Real F_drag(unit = "N") "Drag force";
  Real F_net(unit = "N") "Net force";
  Real a(unit = "m/s2") "Acceleration";
  Real E_kinetic(unit = "J") "Kinetic energy";
  Real E_potential_lost(unit = "J") "Lost potential energy";
  Real E_dissipated(start = 0, unit = "J") "Dissipated energy";
  Real v_terminal_out(unit = "m/s") "Terminal velocity output";

protected
  Real v_terminal(unit = "m/s") "Terminal velocity";
  
initial equation
  // Explicit initial conditions as required
  y = 0;
  v = v0;
  
equation
  // Core kinematics
  der(y) = v;
  
  // Force calculations
  F_gravity = m * g;
  F_drag = b * v * abs(v);  // Drag magnitude, always non-negative
  
  // Net force considering direction (drag opposes motion)
  F_net = F_gravity - sign(v) * F_drag;
  
  // Acceleration from Newton's second law
  a = F_net / m;
  der(v) = a;
  
  // Terminal velocity (steady-state when F_net = 0)
  v_terminal = sqrt(m * g / b);
  v_terminal_out = v_terminal;
  
  // Velocity ratio
  v_ratio = v / v_terminal;
  
  // Energy calculations
  E_kinetic = 0.5 * m * v * v;
  E_potential_lost = m * g * y;  // Assuming zero initial height
  der(E_dissipated) = F_drag * abs(v);  // Power dissipated by drag
  
  // Assertion for physical consistency
  assert(v >= -1e-3, "Velocity should not become significantly negative in free fall");
end FallingWithDrag;
