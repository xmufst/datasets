model NewtonCooling "Lumped thermal mass cooling by Newton's law"
  // Parameters
  parameter Real m = 1.0 "Mass of the object (kg)";
  parameter Real cp = 500.0 "Specific heat capacity (J/(kg.K))";
  parameter Real hA = 100.0 "Heat transfer coefficient times surface area (W/K)";
  parameter Real T0 =  200.0 "Initial object temperature (degC)";
  parameter Real T_env = 20.0 "Environment temperature (degC)";

  // Derived constant
  parameter Real tau = m * cp / hA "Thermal time constant (s)";

  // State variable
  Real T(start = T0, fixed = true) "Object temperature (degC)";

  // Derived outputs
  Real dT "Temperature difference T - T_env (degC)";
  Real Q_dot "Heat flow rate from object to environment (W)";
  Real E_thermal "Thermal energy above environment, m*cp*(T-T_env) (J)";
  Real E_dissipated(start = 0, fixed = true) "Cumulative heat dissipated to environment (J)";

equation
  m * cp * der(T) = -hA * (T - T_env);

  dT = T - T_env;
  Q_dot = hA * (T - T_env);
  E_thermal = m * cp * (T - T_env);
  der(E_dissipated) = Q_dot;

end NewtonCooling;
