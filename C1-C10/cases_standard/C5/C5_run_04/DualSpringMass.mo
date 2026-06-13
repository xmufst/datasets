model DualSpringMass "Two-mass two-spring coupled vibration system"
  // Parameters
  parameter Real m1 = 1.0 "Mass of first body (kg)";
  parameter Real m2 = 1.0 "Mass of second body (kg)";
  parameter Real k1 = 100.0 "Stiffness of spring 1, wall to m1 (N/m)";
  parameter Real k2 = 50.0 "Stiffness of spring 2, m1 to m2 (N/m)";
  parameter Real x1_0 =  0.3 "Initial displacement of m1 (m)";
  parameter Real x2_0 =  -0.3 "Initial displacement of m2 (m)";
  parameter Real v1_0 = 0.0 "Initial velocity of m1 (m/s)";
  parameter Real v2_0 = 0.0 "Initial velocity of m2 (m/s)";

  // State variables
  Real x1(start = x1_0, fixed = true) "Displacement of m1 from equilibrium (m)";
  Real v1(start = v1_0, fixed = true) "Velocity of m1 (m/s)";
  Real x2(start = x2_0, fixed = true) "Displacement of m2 from equilibrium (m)";
  Real v2(start = v2_0, fixed = true) "Velocity of m2 (m/s)";

  // Derived outputs
  Real F_spring1 "Force of spring 1 on m1 (N)";
  Real F_spring2 "Force of spring 2, coupling force (N)";
  Real E_kinetic "Total kinetic energy (J)";
  Real E_potential "Total potential energy (J)";
  Real E_total "Total mechanical energy (J), should be conserved";
  Real delta_x "Relative displacement x2 - x1 (m)";

equation
  // Equations of motion
  der(x1) = v1;
  m1 * der(v1) = -k1 * x1 + k2 * (x2 - x1);

  der(x2) = v2;
  m2 * der(v2) = -k2 * (x2 - x1);

  // Spring forces
  F_spring1 = -k1 * x1;
  F_spring2 = k2 * (x2 - x1);

  // Energy
  E_kinetic = 0.5 * m1 * v1 ^ 2 + 0.5 * m2 * v2 ^ 2;
  E_potential = 0.5 * k1 * x1 ^ 2 + 0.5 * k2 * (x2 - x1) ^ 2;
  E_total = E_kinetic + E_potential;

  // Relative displacement
  delta_x = x2 - x1;

end DualSpringMass;
