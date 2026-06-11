model SmithPredictorTemp
  "Temperature control with Smith predictor for pure transport delay compensation"

  import Modelica.Blocks.Sources;
  import Modelica.Blocks.Math;
  import Modelica.Blocks.Continuous;

  // Plant parameters
  parameter Real K_plant = 1.0 "Plant static gain (degC/unit)";
  parameter Real T_plant = 20.0 "Plant time constant (s)";
  parameter Real L =  2.0 "Pure transport delay (s)";
  parameter Real T_ref = 80.0 "Reference temperature (degC)";
  parameter Real T0 = 20.0 "Ambient / initial temperature (degC)";

  // PI controller parameters
  parameter Real Kp = 2.0 "PI proportional gain";
  parameter Real Ti = 15.0 "PI integral time (s)";

  // ---- MSL control components ----
  Sources.Step reference(height = T_ref - T0, offset = T0, startTime = 0)
    "Reference temperature step signal";
  Math.Feedback errorCalc
    "Error = T_ref - T_compensated";
  Continuous.PI piController(
    k = Kp, T = Ti,
    initType = Modelica.Blocks.Types.Init.InitialState,
    x_start = 0)
    "PI controller (operates on delay-free compensated signal)";
  Math.Add3 compensator(k1 = +1, k2 = +1, k3 = -1)
    "Smith compensator: T_measured + T_model - T_model_delayed";

  // ---- Plant states ----
  Real T_process(start = T0, fixed = true, unit = "degC")
    "Temperature at heating point (true plant state)";

  // ---- Internal model state ----
  Real T_model(start = T0, fixed = true, unit = "degC")
    "Internal model temperature (mirrors plant, no delay)";

  // ---- Target output variables ----
  Real T_measured(unit = "degC") "Sensor measurement (delayed)";
  Real T_predicted(unit = "degC") "Smith predictor compensated signal";
  Real T_error(unit = "degC") "Tracking error";
  Real u_pi "PI controller output";
  Real T_ref_signal(unit = "degC") "Reference signal";
  Real T_plant_output(unit = "degC") "Plant output at heating point";
  Real T_model_delayed(unit = "degC") "Internal model delayed output";

equation
  // ===== Control chain =====
  // Reference signal
  T_ref_signal = reference.y;

  // Error computation: e = T_ref - T_compensated
  connect(reference.y, errorCalc.u1);
  connect(errorCalc.y, piController.u);

  // ===== Real plant (first-order + pure delay) =====
  T_plant * der(T_process) = -(T_process - T0) + K_plant * piController.y;
  T_plant_output = T_process;
  T_measured = delay(T_process, L);

  // ===== Internal model (same first-order, no delay in ODE) =====
  T_plant * der(T_model) = -(T_model - T0) + K_plant * piController.y;
  T_model_delayed = delay(T_model, L);

  // ===== Smith predictor compensation =====
  // T_compensated = T_measured + T_model - T_model_delayed
  compensator.u1 = T_measured;
  compensator.u2 = T_model;
  compensator.u3 = T_model_delayed;   // k3 = -1
  T_predicted = compensator.y;

  // Feed compensated signal back to error computation
  errorCalc.u2 = T_predicted;

  // Target aliases
  T_error = errorCalc.y;
  u_pi = piController.y;

end SmithPredictorTemp;
