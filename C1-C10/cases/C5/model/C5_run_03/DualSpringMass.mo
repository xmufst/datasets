model DualSpringMass
  parameter Real m1=1.0 "Mass of block 1 (kg)";
  parameter Real m2=1.0 "Mass of block 2 (kg)";
  parameter Real k1=100.0 "Spring 1 stiffness, wall to m1 (N/m)";
  parameter Real k2=50.0 "Spring 2 stiffness, m1 to m2 (N/m)";
  parameter Real x1_0= 0.3 "Initial displacement of block 1 (m)";
  parameter Real x2_0= 0.3 "Initial displacement of block 2 (m)";
  parameter Real v1_0=0.0 "Initial velocity of block 1 (m/s)";
  parameter Real v2_0=0.0 "Initial velocity of block 2 (m/s)";

  Real x1(start=x1_0, unit="m") "Displacement of block 1 (m)";
  Real v1(start=v1_0, unit="m/s") "Velocity of block 1 (m/s)";
  Real x2(start=x2_0, unit="m") "Displacement of block 2 (m)";
  Real v2(start=v2_0, unit="m/s") "Velocity of block 2 (m/s)";
  Real F_spring1(unit="N") "Force from spring 1 (N)";
  Real F_spring2(unit="N") "Coupling force from spring 2 (N)";
  Real delta_x(unit="m") "Relative displacement (m)";
  Real E_kinetic(unit="J") "Total kinetic energy (J)";
  Real E_potential(unit="J") "Total potential energy (J)";
  Real E_total(unit="J") "Total mechanical energy (J)";

equation
  // Kinematics
  der(x1) = v1;
  der(x2) = v2;

  // Dynamics (Newton's second law)
  m1 * der(v1) = -k1 * x1 + k2 * (x2 - x1);
  m2 * der(v2) = -k2 * (x2 - x1);

  // Auxiliary variables
  F_spring1 = k1 * x1;
  F_spring2 = k2 * (x2 - x1);
  delta_x = x2 - x1;
  E_kinetic = 0.5 * m1 * v1^2 + 0.5 * m2 * v2^2;
  E_potential = 0.5 * k1 * x1^2 + 0.5 * k2 * (x2 - x1)^2;
  E_total = E_kinetic + E_potential;
end DualSpringMass;
