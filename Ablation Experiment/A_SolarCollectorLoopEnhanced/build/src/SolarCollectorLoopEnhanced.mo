model SolarCollectorLoopEnhanced
  "Solar collector loop: water temperature under constant solar irradiation"

  // Parameters
  parameter Real p_system(unit = "Pa") = 101325 "System operating pressure (Pa)";
  parameter Real G_solar(unit = "W/m2") = 500 "Solar irradiance heat flux density (W/m2)";
  parameter Real A_collector(unit = "m2") = 2.0 "Collector area (m2)";
  parameter Real eta_collector(unit = "1") = 0.7 "Collector efficiency (1)";
  parameter Real m_water(unit = "kg") = 5.0 "Water mass (kg)";
  parameter Real cp_water(unit = "J/(kg.K)") = 4184 "Water specific heat capacity (J/(kg.K))";
  parameter Real T_ambient(unit = "degC") = 20.0 "Ambient temperature (degC)";
  parameter Real h_loss(unit = "W/K") = 5.0 "Heat loss coefficient to environment (W/K)";

  // State and target variables
  Real T_water(start = 293.15, unit = "K") "Water temperature (K)";
  Real T_water_C(unit = "degC") "Water temperature in Celsius (degC)";
  Real Q_solar(unit = "W") "Effective solar collector power (W)";
  Real Q_loss(unit = "W") "Heat loss power to environment (W)";
  Real p_system_bar(unit = "bar") "System pressure in bar (bar)";
  Real collector_power_density(unit = "W/m2") "Collector power density (W/m2)";

equation
  // Solar irradiance heating
  Q_solar = G_solar * A_collector * eta_collector;

  // Lumped parameter thermal capacitance
  m_water * cp_water * der(T_water) = Q_solar - Q_loss;

  // First-order linear heat loss to environment
  // T_ambient is in degC; temperature difference in K equals difference in degC numerically
  Q_loss = h_loss * (T_water - (T_ambient + 273.15));

  // Celsius-Kelvin conversion
  T_water_C = T_water - 273.15;

  // Pressure unit conversion
  p_system_bar = p_system / 100000;

  // Collector power density
  collector_power_density = Q_solar / A_collector;

end SolarCollectorLoopEnhanced;
