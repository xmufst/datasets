model NonisothermalArrheniusReactor
  // Parameters
  parameter Real k0 = 1.0 "Pre-exponential factor (1/s)";
  parameter Real Ea = 5000 "Activation energy (J/mol)";
  parameter Real R = 8.314 "Gas constant (J/(mol.K))";
  parameter Real V = 1.0 "Reactor volume (m3)";
  parameter Real rho = 1000 "Liquid density (kg/m3)";
  parameter Real cp = 4184 "Liquid specific heat capacity (J/(kg.K))";
  parameter Real dH = -50000 "Reaction enthalpy (J/mol)";
  parameter Real UA = 200 "Cooling coefficient (W/K)";
  parameter Real T_cool = 300 "Coolant temperature (K)";

  // State variables
  Real C_A(start = 1000, fixed = true, unit = "mol/m3") "Concentration of reactant A";
  Real C_B(start = 0.0, fixed = true, unit = "mol/m3") "Concentration of product B";
  Real T(start = 330, fixed = true, unit = "K") "Reactor temperature";

  // Cumulative energy variables
  Real E_reaction_input(start = 0, fixed = true, unit = "J") "Cumulative reaction heat input";
  Real E_cooling_output(start = 0, fixed = true, unit = "J") "Cumulative cooling heat output";

  // Algebraic variables
  Real k(unit = "1/s") "Rate constant";
  Real r(unit = "mol/(m3.s)") "Reaction rate";
  Real Q_reaction(unit = "W") "Reaction heat generation rate";
  Real Q_cooling(unit = "W") "Cooling heat removal rate";
  Real mass_total(unit = "mol/m3") "Total concentration (A+B)";
  Real mass_balance_residual(unit = "mol/m3") "Mass balance residual";
  Real E_thermal_observed(unit = "J") "Thermal energy change from temperature";
  Real energy_balance_residual(unit = "J") "Energy balance residual";

equation
  // Arrhenius kinetics
  k = k0 * exp(-Ea / (R * T));
  r = k * C_A;

  // Species mass balances
  der(C_A) = -r;
  der(C_B) = r;

  // Mass conservation monitoring
  mass_total = C_A + C_B;
  mass_balance_residual = mass_total - 1000.0;

  // Heat effects
  Q_reaction = -dH * r * V;
  Q_cooling = UA * (T - T_cool);

  // Energy balance: temperature dynamics
  rho * V * cp * der(T) = Q_reaction - Q_cooling;

  // Cumulative energy integrals
  der(E_reaction_input) = Q_reaction;
  der(E_cooling_output) = Q_cooling;

  // Thermal energy observed from temperature change
  E_thermal_observed = rho * V * cp * (T - 330);

  // Energy balance residual
  energy_balance_residual = E_reaction_input - E_cooling_output - E_thermal_observed;
end NonisothermalArrheniusReactor;
