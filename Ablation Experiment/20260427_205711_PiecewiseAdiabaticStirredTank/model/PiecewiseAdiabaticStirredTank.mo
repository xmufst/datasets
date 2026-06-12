model PiecewiseAdiabaticStirredTank
  "Adiabatic stirred tank model, describing the effect of piecewise stirring power input on liquid temperature"

  parameter Real m_liquid = 10 "liquid mass (kg)" annotation(Dialog(group="Parameters"));
  parameter Real cp_liquid = 4184 "liquid specific heat capacity (J/(kg.K))" annotation(Dialog(group="Parameters"));
  parameter Real P_stir_phase1 = 500 "phase 1 stirring power (W)" annotation(Dialog(group="Parameters"));
  parameter Real P_stir_phase2 = 1000 "phase 2 stirring power (W)" annotation(Dialog(group="Parameters"));
  parameter Real P_stir_phase3 = 0 "phase 3 stirring power (W)" annotation(Dialog(group="Parameters"));
  parameter Real t_end_phase1 = 300 "phase 1 end time (s)" annotation(Dialog(group="Parameters"));
  parameter Real t_end_phase2 = 600 "phase 2 end time (s)" annotation(Dialog(group="Parameters"));

  Real T_liquid(start = 293.15, fixed = true, unit = "K");
  Real energy_added(start = 0, fixed = true, unit = "J");
  Real energy_residual(start = 0, unit = "J");
  Real T_liquid_C(unit = "degC");
  Real P_stir(unit = "W");
  Real dTdt_theoretical(unit = "K/s");
  Real energy_stored(unit = "J");

equation
  P_stir = if noEvent(time < t_end_phase1) then P_stir_phase1
           else if noEvent(time < t_end_phase2) then P_stir_phase2
           else P_stir_phase3;

  dTdt_theoretical = P_stir / (m_liquid * cp_liquid);

  der(T_liquid) = dTdt_theoretical;

  T_liquid_C = T_liquid - 273.15;

  der(energy_added) = P_stir;

  energy_stored = m_liquid * cp_liquid * (T_liquid - 293.15);

  energy_residual = energy_added - energy_stored;

end PiecewiseAdiabaticStirredTank;
