model NewtonCooling
  // Parameters
  parameter Real m(unit="kg") = 1.0 "Mass of the object";
  parameter Real cp(unit="J/(kg.K)") = 500.0 "Specific heat capacity";
  parameter Real hA(unit="W/K") = 100.0 "Overall heat transfer coefficient";
  parameter Real T0(unit="degC") = 100.0 "Initial object temperature";
  parameter Real T_env(unit="degC") = 20.0 "Environment temperature";
  
  // Variables
  Real T(start=T0, unit="degC") "Object temperature";
  Real E_dissipated(start=0, unit="J") "Cumulative dissipated heat";
  Real dT(unit="K") "Temperature difference (object minus environment)";
  Real Q_dot(unit="W") "Heat flow rate from object to environment (positive when object cools)";
  Real E_thermal(unit="J") "Thermal energy of object relative to environment";
  Real tau(unit="s") "Thermal time constant";
  
equation
  // Heat flow rate from object to environment (Newton's law of cooling)
  Q_dot = hA * (T - T_env);
  
  // Temperature dynamics (energy balance): cooling reduces temperature
  der(T) = -Q_dot / (m * cp);
  
  // Temperature difference (target variable)
  dT = T - T_env;
  
  // Thermal time constant (constant)
  tau = m * cp / hA;
  
  // Thermal energy relative to environment
  E_thermal = m * cp * (T - T_env);
  
  // Cumulative dissipated heat (integral of heat flow from object)
  der(E_dissipated) = Q_dot;
  
  // Assertion for physical consistency
  assert(E_thermal >= -1e-6, "E_thermal should be non-negative: E_thermal = " + String(E_thermal));
  
end NewtonCooling;
