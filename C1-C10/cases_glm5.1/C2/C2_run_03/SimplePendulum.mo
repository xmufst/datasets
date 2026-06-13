model SimplePendulum
  parameter Real m = 1.0 "Pendulum mass (kg)";
  parameter Real g = 9.81 "Gravitational acceleration (m/s2)";
  parameter Real L = 1.0 "Pendulum length (m)";
  parameter Real theta0 =  1.0 "Initial angle (rad)";
  parameter Real omega0 = 0.0 "Initial angular velocity (rad/s)";

  Real theta(start = theta0, unit = "rad") "Angular displacement";
  Real omega(start = omega0, unit = "rad/s") "Angular velocity";
  Real x(unit = "m") "Horizontal position of pendulum bob";
  Real y(unit = "m") "Vertical position of pendulum bob";
  Real E_kinetic(unit = "J") "Kinetic energy";
  Real E_potential(unit = "J") "Potential energy";
  Real E_total(unit = "J") "Total mechanical energy";

equation
  der(theta) = omega;
  der(omega) = -(g / L) * sin(theta);
  x = L * sin(theta);
  y = -L * cos(theta);
  E_kinetic = 0.5 * m * (L * omega) ^ 2;
  E_potential = m * g * (L + y);
  E_total = E_kinetic + E_potential;
end SimplePendulum;
