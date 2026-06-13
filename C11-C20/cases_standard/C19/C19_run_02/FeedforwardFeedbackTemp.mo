model FeedforwardFeedbackTemp
  "Furnace temperature control with feedforward + PI feedback composite"

  import Modelica.Blocks.Sources;
  import Modelica.Blocks.Math;
  import Modelica.Blocks.Continuous;

  // Plant parameters
  parameter Real C_furnace = 5000.0 "Furnace thermal capacity (J/K)";
  parameter Real UA = 5.0 "Heat loss coefficient to ambient (W/K)";
  parameter Real T_amb = 20.0 "Ambient temperature (degC)";
  parameter Real T_ref = 80.0 "Reference temperature (degC)";
  parameter Real T0 = 80.0 "Initial temperature (degC) — starts at steady state";

  // Steady-state baseline heating
  parameter Real Q_ss = 300.0 "Steady-state heating power = UA*(T_ref-T_amb) (W)";

  // Disturbance parameters
  parameter Real Q_dist =  100.0 "Disturbance power step magnitude (W)";
  parameter Real t_dist = 100.0 "Disturbance step time (s)";

  // Feedforward parameter
  parameter Real K_ff = 1.0 "Feedforward gain (1.0 = ideal compensation)";

  // PI correction parameters
  parameter Real Kp = 0.5 "PI proportional gain (W/degC)";
  parameter Real Ti = 50.0 "PI integral time (s)";

  // ---- MSL control components ----
  // Baseline heating (constant)
  Sources.Constant baselineHeat(k = Q_ss)
    "Steady-state baseline heating power";

  // PI feedback correction channel
  Sources.Constant refSignal(k = T_ref)
    "Temperature reference";
  Math.Feedback errorCalc
    "Error = T_ref - T";
  Continuous.PI piCorrection(
    k = Kp, T = Ti,
    initType = Modelica.Blocks.Types.Init.InitialState,
    x_start = 0)
    "PI correction controller (outputs delta power in Watts)";

  // Feedforward channel
  Sources.Step disturbanceSignal(height = Q_dist, startTime = t_dist)
    "Measurable disturbance step signal";
  Math.Gain feedforwardGain(k = K_ff)
    "Feedforward compensation gain";

  // Three-channel summation: Q_heater = Q_ss + u_pi + u_ff
  Math.Add3 heaterSum(k1 = +1, k2 = +1, k3 = +1)
    "Total heater power = baseline + PI correction + feedforward";

  // ---- Plant state ----
  Real T(start = T0, fixed = true, unit = "degC") "Furnace temperature";

  // ---- Target output variables ----
  Real T_error(unit = "degC") "Temperature tracking error";
  Real u_pi(unit = "W") "PI correction channel output";
  Real u_ff(unit = "W") "Feedforward channel output";
  Real u_total(unit = "W") "Total control signal";
  Real Q_heater(unit = "W") "Total heating power";
  Real Q_loss(unit = "W") "Heat loss to ambient";
  Real Q_disturbance(unit = "W") "Disturbance heat load";

equation
  // ===== PI feedback correction channel =====
  connect(refSignal.y, errorCalc.u1);
  errorCalc.u2 = T;
  connect(errorCalc.y, piCorrection.u);

  // ===== Feedforward channel =====
  connect(disturbanceSignal.y, feedforwardGain.u);

  // ===== Three-channel summation =====
  connect(baselineHeat.y, heaterSum.u1);
  connect(piCorrection.y, heaterSum.u2);
  connect(feedforwardGain.y, heaterSum.u3);

  // ===== Heater power (non-negative) =====
  Q_heater = max(0, heaterSum.y);

  // ===== Disturbance =====
  Q_disturbance = disturbanceSignal.y;

  // ===== Heat loss =====
  Q_loss = UA * (T - T_amb);

  // ===== Plant dynamics =====
  C_furnace * der(T) = Q_heater - Q_loss - Q_disturbance;

  // ===== Target variable aliases =====
  T_error = errorCalc.y;
  u_pi = piCorrection.y;
  u_ff = feedforwardGain.y;
  u_total = heaterSum.y;

end FeedforwardFeedbackTemp;
