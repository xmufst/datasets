model SpringEndStop "Mass-spring system with elastic end stop contact"
  // Parameters
  parameter Real m =  2.0 "Mass (kg)";
  parameter Real k = 50.0 "Main spring stiffness (N/m)";
  parameter Real c = 0.5 "Main spring damping coefficient (N.s/m)";
  parameter Real x0 =  0.0 "Initial displacement from equilibrium (m)";
  parameter Real v0 =  6.0 "Initial velocity (m/s)";
  parameter Real gap =  0.6 "Distance from equilibrium to end stop (m)";
  parameter Real k_contact =  800.0 "End stop contact stiffness (N/m)";
  parameter Real c_contact =  4.0 "End stop contact damping (N.s/m)";

  // State variables
  Real x(start = x0, fixed = true) "Displacement from equilibrium (m)";
  Real v(start = v0, fixed = true) "Velocity (m/s)";

  // Derived outputs
  Real F_spring "Main spring force (N)";
  Real F_damper "Main damper force (N)";
  Real F_contact "End stop contact force (N), zero when not in contact";
  Real F_net "Net force on mass (N)";
  Real penetration "Penetration depth into end stop (m), zero when not in contact";
  Boolean in_contact "True when mass is in contact with end stop";
  Real E_kinetic "Kinetic energy (J)";
  Real E_spring "Main spring potential energy (J)";
  Real E_total "Kinetic + main spring potential energy (J)";

equation
  der(x) = v;

  // Forces
  F_spring = -k * x;
  F_damper = -c * v;
  penetration = if x > gap then x - gap else 0;
  in_contact = x > gap;
  F_contact = if x > gap then -k_contact * (x - gap) - c_contact * v else 0;

  // Net force and Newton's second law
  F_net = F_spring + F_damper + F_contact;
  m * der(v) = F_net;

  // Energy (main spring system only, contact dissipates energy)
  E_kinetic = 0.5 * m * v ^ 2;
  E_spring = 0.5 * k * x ^ 2;
  E_total = E_kinetic + E_spring;

end SpringEndStop;
