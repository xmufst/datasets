model SpringEndStop
  "Spring-mass-damper system with end stop using penalty method for contact simulation"
  
  // Parameters with description and unit
  parameter Real m(unit="kg") = 1.0 "Mass of the block";
  parameter Real k(unit="N/m") = 50.0 "Stiffness of main spring";
  parameter Real c(unit="N·s/m") = 0.5 "Damping coefficient of main damper";
  parameter Real x0(unit="m") = 0.8 "Initial displacement parameter";
  parameter Real v0(unit="m/s") = 0.0 "Initial velocity parameter";
  parameter Real gap(unit="m") = 0.5 "Gap distance to end stop";
  parameter Real k_contact(unit="N/m") = 1000.0 "Contact spring stiffness";
  parameter Real c_contact(unit="N·s/m") = 5.0 "Contact damper coefficient";
  
  // Variables with start values and units
  Real x(start=x0, unit="m") "Displacement of mass";
  Real v(start=v0, unit="m/s") "Velocity of mass";
  Real F_spring(unit="N") "Main spring force";
  Real F_damper(unit="N") "Main damper force";
  Real F_contact(unit="N") "Contact force";
  Real F_net(unit="N") "Net force on mass";
  Real penetration(unit="m") "Penetration into end stop (positive when x > gap)";
  Boolean in_contact "Contact state (true when in contact)";
  Real E_kinetic(unit="J") "Kinetic energy";
  Real E_spring(unit="J") "Spring potential energy";
  Real E_total(unit="J") "Total mechanical energy";
  
  // Discrete contact state for event handling
  discrete Boolean contact(start=x0 > gap) "Discrete contact state";
  
  // Small tolerance for event handling
  parameter Real eps(unit="m") = 1e-6 "Small tolerance for contact threshold";
  
initial equation
  // Initial conditions already set via start attributes
  
equation
  // Kinematic relationships
  der(x) = v;
  
  // Penetration calculation: positive when x > gap (mass contacts end stop)
  penetration = x - gap;
  
  // Contact state (continuous for force calculation)
  in_contact = penetration > 0;
  
  // Update discrete contact state (triggers events at contact boundary)
  contact = penetration > 0;
  
  // Main spring force (spring origin at x=0)
  F_spring = -k * x;
  
  // Main damper force
  F_damper = -c * v;
  
  // Contact force using penalty method (only when in contact)
  // Correct damping force: -c_contact * v (always dissipative, power = -c_contact * v^2 <= 0)
  F_contact = if in_contact then (-k_contact * penetration - c_contact * v) else 0;
  
  // Net force
  F_net = F_spring + F_damper + F_contact;
  
  // Dynamics: Newton's second law
  m * der(v) = F_net;
  
  // Energy calculations
  E_kinetic = 0.5 * m * v^2;
  E_spring = 0.5 * k * x^2;
  E_total = E_kinetic + E_spring;
  
  // Simplified event handling: no reinitialization of physical states
  // Keep discrete state for event detection only
  // No when clauses to avoid non-physical interventions
  
  annotation(
    experiment(
      StartTime=0,
      StopTime=10,
      Tolerance=1e-6
    )
  );
end SpringEndStop;
