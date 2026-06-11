model RCLeadCompensator
  "RC circuit voltage control with lead compensator using MSL TransferFunction"

  import Modelica.Blocks.Continuous;
  import Modelica.Blocks.Nonlinear;
  import Modelica.Blocks.Sources;
  import Modelica.Blocks.Math;

  // Circuit parameters
  parameter Real R = 10.0 "Resistance (Ohm)";
  parameter Real C_val = 0.1 "Capacitance (F)";
  parameter Real V_ref =  7.0 "Reference voltage (V)";
  parameter Real Vc0 = 0.0 "Initial capacitor voltage (V)";

  // Compensator parameters
  parameter Real Kc = 5.0 "Compensator DC gain";
  parameter Real tau_lead = 0.5 "Lead time constant — zero at s=-1/tau_lead (s)";
  parameter Real tau_lag = 0.05 "Lag time constant — pole at s=-1/tau_lag (s)";
  parameter Real V_max = 15.0 "Input voltage saturation limit (V)";

  // ---- MSL control components ----
  Sources.Step reference(height = V_ref, startTime = 0)
    "Reference voltage step";
  Math.Feedback feedback
    "Error = V_ref - Vc";
  Continuous.TransferFunction leadComp(
    b = {Kc * tau_lead, Kc},
    a = {tau_lag, 1},
    initType = Modelica.Blocks.Types.Init.InitialState)
    "Lead compensator: Kc*(tau_lead*s+1)/(tau_lag*s+1)";
  Nonlinear.Limiter limiter(uMax = V_max, uMin = -V_max)
    "Voltage saturation";

  // ---- Plant state ----
  Real Vc(start = Vc0, fixed = true, unit = "V") "Capacitor voltage";

  // ---- Target output variables ----
  Real Vc_error(unit = "V") "Voltage tracking error";
  Real V_in(unit = "V") "Applied input voltage (after saturation)";
  Real i_R(unit = "A") "Current through resistor";
  Real u_compensator "Compensator raw output (before saturation)";

equation
  // Control signal chain: reference -> feedback -> lead compensator -> limiter
  connect(reference.y, feedback.u1);
  connect(feedback.y, leadComp.u);
  connect(leadComp.y, limiter.u);

  // Measured voltage feedback
  feedback.u2 = Vc;

  // Saturated input voltage
  V_in = limiter.y;

  // RC circuit plant dynamics
  C_val * der(Vc) = (V_in - Vc) / R;

  // Resistor current
  i_R = (V_in - Vc) / R;

  // Target variable aliases
  Vc_error = feedback.y;
  u_compensator = leadComp.y;

end RCLeadCompensator;
