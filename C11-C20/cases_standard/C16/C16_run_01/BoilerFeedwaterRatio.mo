model BoilerFeedwaterRatio
  "Boiler feedwater ratio control using MSL Division and PI blocks"

  import Modelica.Blocks.Sources;
  import Modelica.Blocks.Math;
  import Modelica.Blocks.Continuous;
  import Modelica.Blocks.Nonlinear;

  // Drum parameters
  parameter Real A_eff = 500.0 "Effective drum area parameter (kg/m)";
  parameter Real K_fw = 3.0 "Maximum feedwater flow at full valve (kg/s)";
  parameter Real h0 = 1.0 "Initial drum water level (m)";

  // Steam parameters
  parameter Real W_steam_base = 1.0 "Base steam mass flow (kg/s)";
  parameter Real dW_steam = 0.5 "Steam flow step increase (kg/s)";
  parameter Real t_dist = 200.0 "Steam disturbance step time (s)";

  // Ratio control parameters
  parameter Real R_set =  0.80 "Feedwater/steam ratio setpoint";
  parameter Real Kp = 3.0 "PI proportional gain";
  parameter Real Ti = 10.0 "PI integral time (s)";

  // ---- MSL control components ----
  Sources.Step steamSource(
    offset = W_steam_base, height = dW_steam, startTime = t_dist)
    "Steam mass flow (uncontrolled wild variable)";
  Sources.Constant ratioSetpoint(k = R_set)
    "Ratio setpoint signal";
  Math.Division ratioCalc
    "Computes actual ratio = W_feedwater / W_steam";
  Math.Feedback ratioFeedback
    "Ratio error = R_set - ratio_actual";
  Continuous.PI piController(
    k = Kp, T = Ti,
    initType = Modelica.Blocks.Types.Init.InitialState,
    x_start = 0)
    "PI ratio controller";
  Nonlinear.Limiter valveLimiter(uMax = 1, uMin = 0)
    "Valve position limit [0, 1]";

  // ---- Plant state ----
  Real h_drum(start = h0, fixed = true, unit = "m") "Drum water level";

  // ---- Target output variables ----
  Real W_feedwater(unit = "kg/s") "Feedwater mass flow";
  Real W_steam(unit = "kg/s") "Steam mass flow";
  Real ratio_actual "Actual feedwater/steam ratio";
  Real ratio_error "Ratio tracking error";
  Real u_pi "PI controller output";
  Real valve_opening "Valve position (0-1)";

equation
  // Steam flow (wild variable, uncontrolled)
  W_steam = steamSource.y;

  // Ratio computation: Division.y = u1 / u2
  ratioCalc.u1 = W_feedwater;
  ratioCalc.u2 = W_steam;
  ratio_actual = ratioCalc.y;

  // Ratio control loop: setpoint -> error -> PI -> limiter
  connect(ratioSetpoint.y, ratioFeedback.u1);
  ratioFeedback.u2 = ratio_actual;
  connect(ratioFeedback.y, piController.u);
  connect(piController.y, valveLimiter.u);

  // Valve and feedwater flow
  valve_opening = valveLimiter.y;
  W_feedwater = K_fw * valve_opening;

  // Ratio error alias
  ratio_error = ratioFeedback.y;
  u_pi = piController.y;

  // Drum level dynamics (mass balance)
  A_eff * der(h_drum) = W_feedwater - W_steam;

end BoilerFeedwaterRatio;
