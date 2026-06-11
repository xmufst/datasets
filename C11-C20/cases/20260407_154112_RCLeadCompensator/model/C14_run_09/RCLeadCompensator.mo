model RCLeadCompensator
  "A RC circuit voltage tracking closed-loop control system with lead compensator based on standard control components."
  
  // Parameters with MSL SI types
  parameter Modelica.Units.SI.Resistance R = 10.0 "Resistance (Ω)";
  parameter Modelica.Units.SI.Capacitance C_val = 0.1 "Capacitance (F)";
  parameter Modelica.Units.SI.Voltage V_ref =  9.0 "Reference voltage (V)";
  parameter Real Kc = 5.0 "Compensator gain (dimensionless)";
  parameter Modelica.Units.SI.Time tau_lead = 0.5 "Lead time constant (s)";
  parameter Modelica.Units.SI.Time tau_lag = 0.05 "Lag time constant (s)";
  parameter Modelica.Units.SI.Voltage V_max = 15.0 "Maximum input voltage limit (V)";
  
  // Variables
  Modelica.Units.SI.Voltage Vc(start = 0.0) "Capacitor voltage";
  Modelica.Units.SI.Current i_R "Resistor current";
  Modelica.Units.SI.Voltage Vc_error "Voltage tracking error";
  Real u_compensator "Compensator raw output (before limiter)";
  Modelica.Units.SI.Voltage V_in "Actual input voltage to RC circuit (after limiter)";
  
  // Standard library components
  Modelica.Blocks.Sources.Step step(
    height = V_ref,
    offset = 0.0,
    startTime = 0.0) "Reference voltage step signal";
  
  Modelica.Blocks.Math.Feedback feedback "Feedback block for error calculation";
  
  Modelica.Blocks.Continuous.TransferFunction compensator(
    b = {Kc * tau_lead, Kc},
    a = {tau_lag, 1},
    initType = Modelica.Blocks.Types.Init.InitialState) 
    "Lead compensator transfer function";
  
  Modelica.Blocks.Nonlinear.Limiter limiter(
    uMax = V_max,
    uMin = -V_max) 
    "Limiter to constrain input voltage";
  
  Modelica.Blocks.Sources.RealExpression Vc_signal(y = Vc) 
    "Convert capacitor voltage to signal for feedback";
  
equation
  // RC circuit dynamics
  C_val * der(Vc) = (V_in - Vc) / R;
  
  // Resistor current
  i_R = (V_in - Vc) / R;
  
  // Connect control loop components - pure signal flow with connect statements
  connect(step.y, feedback.u1);
  connect(Vc_signal.y, feedback.u2);
  Vc_error = feedback.y;
  
  connect(feedback.y, compensator.u);
  u_compensator = compensator.y;
  
  connect(compensator.y, limiter.u);
  V_in = limiter.y;
  
end RCLeadCompensator;
