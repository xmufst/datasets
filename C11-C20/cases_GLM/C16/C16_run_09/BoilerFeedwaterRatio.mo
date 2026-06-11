model BoilerFeedwaterRatio
  "Boiler feedwater ratio control system with drum level dynamics and PI controller."
  
  // Parameters with description and unit
  parameter Real A_eff(unit = "kg/m") = 500.0 "Equivalent drum area (kg/m)";
  parameter Real K_fw(unit = "kg/s") = 3.0 "Maximum feedwater flow rate (kg/s)";
  parameter Real W_steam_base(unit = "kg/s") = 1.0 "Base steam mass flow rate (kg/s)";
  parameter Real dW_steam(unit = "kg/s") = 0.5 "Step increment in steam flow disturbance (kg/s)";
  parameter Real t_dist(unit = "s") = 200.0 "Time when steam flow disturbance is applied (s)";
  parameter Real R_set(unit = "1") = 1.0 "Setpoint for feedwater to steam ratio (1)";
  parameter Real Kp(unit = "1") = 3.0 "Proportional gain of PI controller (1)";
  parameter Real Ti(unit = "s") = 10.0 "Integral time of PI controller (s)";
  
  // Variables with start values and units
  Real h_drum(unit = "m", start = 1.0) "Drum level (m)";
  Real W_feedwater(unit = "kg/s") "Feedwater mass flow rate (kg/s)";
  Real W_steam(unit = "kg/s") "Steam mass flow rate (kg/s)";
  Real ratio_actual(unit = "1") "Actual feedwater to steam ratio (1)";
  Real ratio_error(unit = "1") "Ratio error (1)";
  Real u_pi(unit = "1") "PI controller output (1)";
  Real valve_opening(unit = "1") "Valve opening (0-1)";
  
  // Standard library components
  Modelica.Blocks.Sources.Step steamFlowStep(
    height = dW_steam,
    offset = W_steam_base,
    startTime = t_dist
  ) "Steam mass flow rate step disturbance";
  
  Modelica.Blocks.Sources.Constant ratioSetpoint(
    k = R_set
  ) "Setpoint for feedwater to steam ratio";
  
  Modelica.Blocks.Math.Division ratioDivider
    "Divide feedwater by steam flow to get actual ratio";
  
  Modelica.Blocks.Math.Feedback ratioFeedback
    "Calculate error between setpoint and actual ratio";
  
  Modelica.Blocks.Continuous.PI piController(
    k = Kp,
    T = Ti,
    initType = Modelica.Blocks.Types.Init.InitialState
  ) "PI controller for ratio regulation";
  
  Modelica.Blocks.Nonlinear.Limiter valveLimiter(
    uMax = 1,
    uMin = 0
  ) "Limit valve opening to [0, 1]";
  
  Modelica.Blocks.Math.Product flowMultiplier
    "Multiply valve opening by max feedwater flow";
  
  Modelica.Blocks.Sources.Constant maxFlowConstant(
    k = K_fw
  ) "Maximum feedwater flow rate constant";
  
equation
  // Connect standard library components
  connect(steamFlowStep.y, ratioDivider.u2);  // Steam flow as divisor
  
  connect(ratioSetpoint.y, ratioFeedback.u1);  // Setpoint
  
  connect(ratioDivider.y, ratioFeedback.u2);  // Actual ratio feedback
  
  connect(ratioFeedback.y, piController.u);  // Error to PI controller
  
  connect(piController.y, valveLimiter.u);  // PI output to limiter
  
  connect(valveLimiter.y, flowMultiplier.u1);  // Valve opening to multiplier
  
  connect(maxFlowConstant.y, flowMultiplier.u2);  // Max flow constant to multiplier
  connect(flowMultiplier.y, ratioDivider.u1);  // Feedwater flow as dividend
  
  // Assign signals to variables
  ratio_actual = ratioDivider.y;
  ratio_error = ratioFeedback.y;
  u_pi = piController.y;
  valve_opening = valveLimiter.y;
  W_feedwater = flowMultiplier.y;
  W_steam = steamFlowStep.y;
  
  // Drum level dynamics
  der(h_drum) = (W_feedwater - W_steam) / A_eff;
  
end BoilerFeedwaterRatio;
