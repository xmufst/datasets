model SpringMassDamper
  "Simulate free vibration decay of a single-DOF spring-mass-damper system"

  parameter Real m = 1.0 "Mass of the block (kg)";
  parameter Real k = 100.0 "Spring stiffness (N/m)";
  parameter Real c =  20.0 "Damping coefficient (N.s/m)";
  parameter Real x0 = 0.5 "Initial displacement (m)";
  parameter Real v0 = 0.0 "Initial velocity (m/s)";

  Real x(start = x0, unit = "m") "Mass displacement";
  Real v(start = v0, unit = "m/s") "Mass velocity";
  Real a(unit = "m/s2") "Mass acceleration";
  Real F_spring(unit = "N") "Spring force";
  Real F_damper(unit = "N") "Damper force";
  Real E_kinetic(unit = "J") "Kinetic energy";
  Real E_potential(unit = "J") "Potential energy";
  Real E_total(unit = "J") "Total mechanical energy";
  Real omega_n(unit = "rad/s") "Natural frequency";
  Real zeta "Damping ratio (dimensionless)";

equation
  omega_n = sqrt(k / m);
  zeta = c / (2 * sqrt(k * m));

  F_spring = k * x;
  F_damper = c * v;

  m * a = -F_spring - F_damper;

  der(x) = v;
  der(v) = a;

  E_kinetic =  20.0 * m * v ^ 2;
  E_potential = 0.5 * k * x ^ 2;
  E_total = E_kinetic + E_potential;

end SpringMassDamper;
