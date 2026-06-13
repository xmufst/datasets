model SimplePendulum "Simple pendulum with nonlinear dynamics"
  // Parameters
  parameter Real g =  5.0 "Gravitational acceleration (m/s2)";
  parameter Real L = 1.0 "Pendulum length (m)";
  parameter Real theta0 = 0.5 "Initial angular displacement (rad)";
  parameter Real omega0 = 0.0 "Initial angular velocity (rad/s)";

  // State variables
  Real theta(start = theta0, fixed = true) "Angular displacement from vertical (rad)";
  Real omega(start = omega0, fixed = true) "Angular velocity (rad/s)";

  // Derived outputs
  Real x "Horizontal position of bob (m)";
  Real y "Vertical position of bob, measured downward from pivot (m)";
  Real E_kinetic "Kinetic energy (J), assuming unit mass";
  Real E_potential "Potential energy (J), assuming unit mass";
  Real E_total "Total mechanical energy (J), should be conserved";

equation
  der(theta) = omega;
  der(omega) = -(g / L) * sin(theta);

  x = L * sin(theta);
  y = -L * cos(theta);
  E_kinetic = 0.5 * (L * omega) ^ 2;
  E_potential = g * (L - L * cos(theta));
  E_total = E_kinetic + E_potential;

end SimplePendulum;
