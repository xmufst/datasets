model SmithPredictorTemp
  // Parameters
  parameter Real K_plant = 1.0 "Plant static gain (degC/unit)";
  parameter Real T_plant = 20.0 "Plant time constant (s)";
  parameter Real L =  2.0 "Pure transport delay (s)";
  parameter Real T_ref = 80.0 "Reference temperature (degC)";
  parameter Real T0 = 20.0 "Ambient/initial temperature (degC)";
  parameter Real Kp = 2.0 "PI proportional gain (1)";
  parameter Real Ti = 15.0 "PI integral time (s)";

  // Variables
  Real T_process(start = 20.0, fixed = true, unit = "degC") "Process temperature at heating point";
  Real T_model(start = 20.0, fixed = true, unit = "degC") "Internal model temperature";
  Real T_measured(unit = "degC") "Sensor measured temperature";
  Real T_predicted(unit = "degC") "Smith predictor compensated predicted temperature";
  Real T_error(unit = "degC") "Temperature tracking error";
  Real u_pi(unit = "unit") "PI controller output signal";
  Real T_ref_signal(unit = "degC") "Reference temperature signal";
  Real T_plant_output(unit = "degC") "True plant temperature at heating point";
  Real T_model_delayed(unit = "degC") "Internal model delayed temperature output";

  // MSL Components
  Modelica.Blocks.Sources.Step step_ref(
    height = T_ref - T0,
    offset = T0,
    startTime = 0
  ) "Reference temperature step source";

  Modelica.Blocks.Math.Feedback feedback "Error calculator: T_ref - T_predicted";

  Modelica.Blocks.Continuous.PI pi_ctrl(
    k = Kp,
    T = Ti,
    initType = Modelica.Blocks.Types.Init.InitialState,
    x_start = 0
  ) "PI controller";

  Modelica.Blocks.Math.Add3 add3_smith(
    k1 = +1,
    k2 = +1,
    k3 = -1
  ) "Smith predictor compensation: T_measured + T_model - T_model_delayed";

equation
  // Plant dynamics: first-order heating with T0 bias
  T_plant * der(T_process) + (T_process - T0) = K_plant * u_pi;
  T_plant_output = T_process;

  // Internal model dynamics: same as plant
  T_plant * der(T_model) + (T_model - T0) = K_plant * u_pi;

  // Reference signal from step source
  T_ref_signal = step_ref.y;

  // Plant delay with soft-start: output T0 before delay window
  T_measured = if noEvent(time > L) then delay(T_process, L) else T0;

  // Model delay with soft-start: output T0 before delay window
  T_model_delayed = if noEvent(time > L) then delay(T_model, L) else T0;

  // Control loop connections using connect()
  connect(step_ref.y, feedback.u1);
  connect(add3_smith.y, feedback.u2);
  connect(feedback.y, pi_ctrl.u);

  // PI controller output
  u_pi = pi_ctrl.y;

  // Temperature tracking error
  T_error = feedback.y;

  // Smith predictor compensation
  add3_smith.u1 = T_measured;
  add3_smith.u2 = T_model;
  add3_smith.u3 = T_model_delayed;
  T_predicted = add3_smith.y;

end SmithPredictorTemp;
