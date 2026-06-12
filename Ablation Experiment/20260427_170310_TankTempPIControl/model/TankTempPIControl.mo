model TankTempPIControl
  "Closed-loop temperature control of insulated water tank using MSL control components"

  // Physical parameters
  parameter Real water_mass(unit="kg") = 5.0 "Water mass (kg)";
  parameter Real cp_water(unit="J/(kg.K)") = 4184 "Water specific heat capacity (J/(kg.K))";
  parameter Real h_env(unit="W/K") = 100 "Heat transfer coefficient tank-to-ambient (W/K)";
  parameter Real k_heater(unit="W") = 1000 "Heater power coefficient (W)";

  // Controller parameters
  parameter Real Kp(unit="1") = 1.0 "PI proportional gain (1)";
  parameter Real Ti(unit="s") = 100 "PI integral time (s)";
  parameter Real pi_lim_max(unit="1") = 20 "PI output upper limit (1)";
  parameter Real pi_lim_min(unit="1") = 0 "PI output lower limit (1)";

  // Environment parameters
  parameter Real T_ambient_init(unit="degC") = 20.0 "Initial ambient temperature (degC)";
  parameter Real T_ambient_disturb(unit="degC") = 10.0 "Ambient temperature after disturbance (degC)";
  parameter Real t_disturb(unit="s") = 100 "Disturbance onset time (s)";

  // Reference parameter
  parameter Real T_ref(unit="degC") = 60.0 "Reference target temperature (degC)";

  // Steady-state initial values
  final parameter Real P_loss_ss = h_env * ((T_ref + 273.15) - (T_ambient_init + 273.15))
    "Initial steady-state heat loss (W)";
  final parameter Real u_pi_ss = P_loss_ss / k_heater
    "Initial steady-state PI output (1)";

  // ---- MSL Components ----

  // Reference temperature source (constant, in Kelvin)
  Modelica.Blocks.Sources.Constant refTemp(k=T_ref + 273.15)
    "Reference temperature signal in Kelvin";

  // Ambient temperature source (step disturbance, in Kelvin)
  Modelica.Blocks.Sources.Step ambTemp(
    offset=T_ambient_init + 273.15,
    height=(T_ambient_disturb - T_ambient_init),
    startTime=t_disturb)
    "Ambient temperature with step disturbance in Kelvin";

  // PI controller with output limits - initialized at steady state
  Modelica.Blocks.Continuous.LimPID piController(
    controllerType=Modelica.Blocks.Types.SimpleController.PI,
    k=Kp,
    Ti=Ti,
    Td=Modelica.Constants.inf,
    yMax=pi_lim_max,
    yMin=pi_lim_min,
    initType=Modelica.Blocks.Types.Init.InitialState,
    xi_start=u_pi_ss,
    xd_start=0,
    y_start=u_pi_ss)
    "PI controller with anti-windup and output limits, initialized at steady state";

  // Gain: convert PI output (0..20) to heating power (0..20000 W)
  Modelica.Blocks.Math.Gain heaterGain(k=k_heater)
    "Heater power gain";

  // RealExpression to feed T_water into the block diagram
  Modelica.Blocks.Sources.RealExpression waterTempExpr(y=T_water)
    "Water temperature as block signal";

  // ---- Target variables ----
  Real T_water(start=333.15, fixed=true, unit="K") "Tank water temperature";
  Real T_water_C(start=60.0, unit="degC") "Tank water temperature in Celsius";
  Real T_ref_signal(start=333.15, unit="K") "Reference temperature signal";
  Real T_error(start=0, unit="K") "Temperature tracking error";
  Real u_pi(start=u_pi_ss, unit="1") "PI controller output signal";
  Real P_heat(start=P_loss_ss, unit="W") "Heating power";
  Real T_ambient(start=293.15, unit="K") "Current ambient temperature";
  Real P_loss(start=P_loss_ss, unit="W") "Heat loss to environment";

equation
  // ---- Signal connections ----
  connect(refTemp.y, piController.u_s);
  connect(waterTempExpr.y, piController.u_m);
  connect(piController.y, heaterGain.u);

  // ---- Assign target variables from component outputs ----
  T_ref_signal = refTemp.y;
  T_error = piController.u_s - piController.u_m;
  u_pi = piController.y;
  P_heat = heaterGain.y;
  T_ambient = ambTemp.y;

  // ---- Physical equations (non-standard: tank thermal dynamics) ----
  P_loss = h_env * (T_water - T_ambient);
  der(T_water) = (P_heat - P_loss) / (water_mass * cp_water);
  T_water_C = T_water - 273.15;

end TankTempPIControl;
