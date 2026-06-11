model FeedforwardFeedbackTemp
  "Heating furnace temperature feedforward plus PI feedback composite control system simulation"

  // Parameters
  parameter Real C_furnace = 5000.0 "Heating furnace heat capacity (J/K)";
  parameter Real UA = 5.0 "Heat dissipation coefficient (W/K)";
  parameter Real T_amb = 20.0 "Ambient temperature (degC)";
  parameter Real T_ref = 80.0 "Reference temperature (degC)";
  parameter Real Q_ss = 300.0 "Steady-state base heating power (W)";
  parameter Real Q_dist =  250.0 "Disturbance power step amplitude (W)";
  parameter Real t_dist = 100.0 "Disturbance application time (s)";
  parameter Real K_ff = 1.0 "Feedforward gain (1)";
  parameter Real Kp = 0.5 "PI proportional gain (W/degC)";
  parameter Real Ti = 50.0 "PI integral time (s)";

  // Target variables
  Real T(start = 80.0, unit = "degC") "Furnace real-time temperature";
  Real T_error(unit = "degC") "Temperature tracking error";
  Real u_pi(unit = "W") "PI correction channel output power";
  Real u_ff(unit = "W") "Feedforward channel output power";
  Real u_total(unit = "W") "Three-channel synthesis module total output signal";
  Real Q_heater(unit = "W") "Actual total heating power";
  Real Q_loss(unit = "W") "Heat dissipation to environment power";
  Real Q_disturbance(unit = "W") "Disturbance heat load";

  // MSL Components
  Modelica.Blocks.Sources.Constant refTemp(k = T_ref) "Reference temperature module";
  Modelica.Blocks.Math.Feedback feedback "Error calculator";
  Modelica.Blocks.Continuous.PI piController(
    k = Kp,
    T = Ti,
    initType = Modelica.Blocks.Types.Init.InitialState,
    x_start = 0
  ) "PI controller";
  Modelica.Blocks.Sources.Step disturbanceStep(
    height = Q_dist,
    startTime = t_dist
  ) "Disturbance step signal module";
  Modelica.Blocks.Math.Gain ffGain(k = K_ff) "Feedforward gain module";
  Modelica.Blocks.Sources.Constant basePower(k = Q_ss) "Base heating power module";
  Modelica.Blocks.Math.Add3 sum3(k1 = 1, k2 = 1, k3 = 1) "Three-channel summer module";
  Modelica.Blocks.Sources.RealExpression furnaceTemp(y = T) "Furnace temperature signal";

equation
  // PI feedback channel connections
  connect(refTemp.y, feedback.u1);
  connect(furnaceTemp.y, feedback.u2);
  connect(feedback.y, piController.u);

  // Feedforward channel connections
  connect(disturbanceStep.y, ffGain.u);

  // Three-channel synthesis connections
  connect(basePower.y, sum3.u1);
  connect(piController.y, sum3.u2);
  connect(ffGain.y, sum3.u3);

  // Signal assignments for target variables
  T_error = feedback.y;
  u_pi = piController.y;
  u_ff = ffGain.y;
  u_total = sum3.y;
  Q_disturbance = disturbanceStep.y;

  // Physical equations for furnace
  Q_loss = UA * (T - T_amb);
  Q_heater = noEvent(max(0, u_total));
  C_furnace * der(T) = Q_heater - Q_loss - Q_disturbance;

end FeedforwardFeedbackTemp;
