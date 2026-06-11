model FallingWithDrag "Free fall with quadratic air drag"
  // Parameters
  parameter Real m = 1.0 "Mass of the object (kg)";
  parameter Real g =  5.0 "Gravitational acceleration (m/s2)";
  parameter Real b = 0.04 "Quadratic drag coefficient, equals 0.5*Cd*A*rho (kg/m)";
  parameter Real v0 = 0.0 "Initial falling speed (m/s)";

  // State variables
  // Convention: y = distance fallen (positive downward), v = falling speed (positive downward)
  Real y(start = 0, fixed = true) "Distance fallen from release point (m)";
  Real v(start = v0, fixed = true) "Falling speed, positive downward (m/s)";

  // Derived outputs
  Real v_ratio "Ratio v / v_terminal (1), approaches 1.0 at terminal velocity";
  Real F_gravity "Gravity force (N)";
  Real F_drag "Aerodynamic drag force (N)";
  Real F_net "Net downward force (N)";
  Real a "Acceleration (m/s2)";
  Real E_kinetic "Kinetic energy (J)";
  Real E_potential_lost "Gravitational potential energy lost (J)";
  Real E_dissipated "Energy dissipated by drag (J), equals E_potential_lost - E_kinetic";

protected
  parameter Real v_terminal = sqrt(m * g / b) "Terminal velocity (m/s)";

equation
  der(y) = v;
  m * der(v) = m * g - b * v ^ 2;

  v_ratio = v / v_terminal;
  F_gravity = m * g;
  F_drag = b * v ^ 2;
  F_net = F_gravity - F_drag;
  a = der(v);
  E_kinetic = 0.5 * m * v ^ 2;
  E_potential_lost = m * g * y;
  E_dissipated = E_potential_lost - E_kinetic;

end FallingWithDrag;
