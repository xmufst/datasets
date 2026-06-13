model TankLevelPI
  // ===========================================================================
  // Liquid Level Control System with PI Controller
  // ===========================================================================
  // This model simulates a water tank level control system.
  // Physical system: Tank with outflow proportional to sqrt(h), inflow controlled by PI controller.
  // Control objective: Maintain liquid level h at reference height h_ref.
  // Control structure: Standard PI controller with output limiting to [0, 1] and scaling to Q_in_max.
  // ===========================================================================
  
  // Physical tank parameters
  parameter Real A_tank(unit="m^2") = 1.0 "Cross-sectional area of tank (m^2)";
  parameter Real k_out(unit="m^(5/2)/s") = 0.01 "Outlet flow coefficient (m^(5/2)/s)";
  parameter Real Q_in_max(unit="m^3/s") = 0.05 "Maximum inflow rate (m^3/s)";
  
  // Control parameters
  parameter Real h_ref(unit="m") = 1.0 "Reference liquid level setpoint (m)";
  parameter Real Kp = 2.0 "PI controller proportional gain";
  parameter Real Ti(unit="s") = 4.0 "PI controller integral time (s)";
  
  // System variables
  Real h(unit="m", start=0.5) "Actual liquid level (m)";
  Real h_error(unit="m") "Level tracking error: h_ref - h (m)";
  Real Q_in(unit="m^3/s") "Actual inflow rate (m^3/s)";
  Real Q_out(unit="m^3/s") "Actual outflow rate (m^3/s)";
  Real u_pi "PI controller raw output signal (0-1)";
  
  // ===========================================================================
  // Standard Modelica Library Components
  // ===========================================================================
  
  // Setpoint signal
  Modelica.Blocks.Sources.Constant h_ref_signal(k=h_ref) "Reference level setpoint";
  
  // Feedback error calculation
  Modelica.Blocks.Math.Feedback feedback "Error calculation: h_ref - h";
  
  // PI controller (standard MSL component)
  Modelica.Blocks.Continuous.PI PI_controller(
    k=Kp,
    T=Ti,
    y_start=0,
    initType=Modelica.Blocks.Types.Init.InitialState) "Standard PI controller";
  
  // Output limiting (0 to 1 for scaling factor)
  Modelica.Blocks.Nonlinear.Limiter limiter(
    uMin=0,
    uMax=1) "Limiter for control output scaling factor";
  
  // Scaling to actual flow rate
  Modelica.Blocks.Math.Product product "Multiplication: scaling factor * Q_in_max";
  Modelica.Blocks.Sources.Constant Qmax_constant(k=Q_in_max) "Maximum flow rate constant";
  
  // Level measurement feedback
  Modelica.Blocks.Sources.RealExpression level_signal(y=h) "Tank level measurement";
  
initial equation
  // Integral state initialization handled by PI_controller.y_start=0
  
equation
  // ===========================================================================
  // Control System Connections
  // ===========================================================================
  
  // Error calculation: h_ref - h
  connect(h_ref_signal.y, feedback.u1);
  connect(level_signal.y, feedback.u2);
  
  // PI controller processes the error
  connect(feedback.y, PI_controller.u);
  
  // Limit PI output to [0, 1] range
  connect(PI_controller.y, limiter.u);
  
  // Scale limited output to actual flow rate: Q_in = u_limited * Q_in_max
  connect(limiter.y, product.u1);
  connect(Qmax_constant.y, product.u2);
  
  // ===========================================================================
  // Assign monitoring variables
  // ===========================================================================
  h_error = feedback.y;               // Tracking error
  u_pi = PI_controller.y;             // PI controller raw output
  Q_in = product.y;                   // Actual inflow rate
  
  // ===========================================================================
  // Physical Tank Model
  // ===========================================================================
  
  // Mass balance: A_tank * dh/dt = Q_in - Q_out
  A_tank * der(h) = Q_in - Q_out;
  
  // Outflow model: Q_out = k_out * sqrt(h) (with protection for negative h)
  Q_out = k_out * sqrt(max(h, 0));
  
end TankLevelPI;
