model ForcedDampedOscillator "Mass-spring-damper with sinusoidal external forcing"
  // Parameters
  parameter Real m = 1.0 "Mass (kg)";
  parameter Real k = 100.0 "Spring stiffness (N/m)";
  parameter Real c = 2.0 "Damping coefficient (N.s/m)";
  parameter Real F0 = 10.0 "Forcing amplitude (N)";
  parameter Real omega = 5.0 "Forcing angular frequency (rad/s)";
  parameter Real x0 = 0.0 "Initial displacement (m)";
  parameter Real v0 = 0.0 "Initial velocity (m/s)";

  // Derived constants
  parameter Real omega_n = sqrt(k / m) "Natural frequency (rad/s)";
  parameter Real zeta = c / (2 * sqrt(k * m)) "Damping ratio (1)";
  parameter Real X_static = F0 / k "Static deflection under F0 (m)";

  // State variables
  Real x(start = x0, fixed = true) "Displacement from equilibrium (m)";
  Real v(start = v0, fixed = true) "Velocity (m/s)";

  // Derived outputs
  Real a "Acceleration (m/s2)";
  Real F_ext "External forcing (N)";
  Real F_spring "Spring force (N)";
  Real F_damper "Damper force (N)";
  Real E_kinetic "Kinetic energy (J)";
  Real E_potential "Spring potential energy (J)";
  Real E_total "Kinetic + potential energy (J)";
  Real P_input "Instantaneous power input from external force (W)";
  Real P_dissipated "Instantaneous power dissipated by damper (W)";

equation
  der(x) = v;
  m * der(v) = -k * x - c * v + F0 * sin(omega * time);

  a = der(v);
  F_ext = F0 * sin(omega * time);
  F_spring = -k * x;
  F_damper = -c * v;
  E_kinetic = 0.5 * m * v ^ 2;
  E_potential = 0.5 * k * x ^ 2;
  E_total = E_kinetic + E_potential;
  P_input = F_ext * v;
  P_dissipated = c * v ^ 2;

end ForcedDampedOscillator;
