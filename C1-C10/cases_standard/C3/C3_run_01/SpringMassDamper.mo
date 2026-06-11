model SpringMassDamper "Spring-mass-damper system with linear vibration and decay"
  // Parameters
  parameter Real m = 1.0 "Mass (kg)";
  parameter Real k = 100.0 "Spring stiffness (N/m)";
  parameter Real c = 2.0 "Damping coefficient (N.s/m)";
  parameter Real x0 = 0.5 "Initial displacement from equilibrium (m)";
  parameter Real v0 = 0.0 "Initial velocity (m/s)";

  // Derived constants (for documentation, not used in equations)
  parameter Real omega_n = sqrt(k / m) "Natural frequency (rad/s)";
  parameter Real zeta = c / (2 * sqrt(k * m)) "Damping ratio (1)";

  // State variables
  Real x(start = x0, fixed = true) "Displacement from equilibrium (m)";
  Real v(start = v0, fixed = true) "Velocity (m/s)";

  // Derived outputs
  Real a "Acceleration (m/s2)";
  Real F_spring "Spring force (N)";
  Real F_damper "Damper force (N)";
  Real E_kinetic "Kinetic energy (J)";
  Real E_potential "Potential energy (J)";
  Real E_total "Total mechanical energy (J), should decay due to damping";

equation
  der(x) = v;
  m * der(v) = -k * x - c * v;

  a = der(v);
  F_spring = -k * x;
  F_damper = -c * v;
  E_kinetic = 0.5 * m * v ^ 2;
  E_potential = 0.5 * k * x ^ 2;
  E_total = E_kinetic + E_potential;

end SpringMassDamper;
