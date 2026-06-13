model ForcedDampedOscillator
  "Dynamic response and energy/power analysis of a spring-mass-damper system under external sinusoidal excitation"

  // Parameters
  parameter Real m = 1.0 "Mass of the block (kg)" annotation(Dialog(group="Physical parameters"));
  parameter Real k = 100.0 "Spring stiffness (N/m)" annotation(Dialog(group="Physical parameters"));
  parameter Real c = 2.0 "Damping coefficient (N.s/m)" annotation(Dialog(group="Physical parameters"));
  parameter Real F0 = 10.0 "Excitation force amplitude (N)" annotation(Dialog(group="Excitation parameters"));
  parameter Real omega =  3.0 "Excitation angular frequency (rad/s)" annotation(Dialog(group="Excitation parameters"));
  parameter Real x0 = 0.0 "Initial displacement parameter (m)" annotation(Dialog(group="Initial conditions"));
  parameter Real v0 = 0.0 "Initial velocity parameter (m/s)" annotation(Dialog(group="Initial conditions"));

  // Derived parameters
  final parameter Real omega_n = sqrt(k / m) "Natural frequency (rad/s)";
  final parameter Real zeta = c / (2 * sqrt(k * m)) "Damping ratio (1)";
  final parameter Real X_static = F0 / k "Static deformation (m)";

  // State variables
  Real x(start = x0, unit = "m") "Displacement of the mass block";
  Real v(start = v0, unit = "m/s") "Velocity of the mass block";

  // Target variables
  Real a(unit = "m/s2") "Acceleration of the mass block";
  Real F_ext(unit = "N") "External excitation force";
  Real F_spring(unit = "N") "Spring force";
  Real F_damper(unit = "N") "Damper force";
  Real E_kinetic(unit = "J") "Kinetic energy";
  Real E_potential(unit = "J") "Spring potential energy";
  Real E_total(unit = "J") "Total mechanical energy";
  Real P_input(unit = "W") "Instantaneous input power from external force";
  Real P_dissipated(unit = "W") "Instantaneous dissipated power by damper";

equation
  // External excitation force
  F_ext = F0 * sin(omega * time);

  // Spring and damper forces
  F_spring = k * x;
  F_damper = c * v;

  // Equation of motion: m * a = F_ext - F_spring - F_damper
  a = (F_ext - F_spring - F_damper) / m;

  // Kinematic relations
  der(x) = v;
  der(v) = a;

  // Energy calculations
  E_kinetic = 0.5 * m * v ^ 2;
  E_potential = 0.5 * k * x ^ 2;
  E_total = E_kinetic + E_potential;

  // Power calculations
  P_input = F_ext * v;
  P_dissipated = c * v ^ 2;

end ForcedDampedOscillator;
