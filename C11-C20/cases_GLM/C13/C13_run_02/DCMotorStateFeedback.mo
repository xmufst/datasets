model DCMotorStateFeedback
  "A DC motor full state feedback speed tracking control system with motor physics and feedback control loop using standard components."
  
  // Parameters with description and unit annotations
  parameter Real Ra = 1.0 "Armature resistance (Ω)";
  parameter Modelica.Units.SI.Inductance La = 0.01 "Armature inductance (H)";
  parameter Real Ke(unit="V.s/rad") = 0.1 "Back EMF constant (V·s/rad)";
  parameter Real Kt(unit="N.m/A") = 0.1 "Torque constant (N·m/A)";
  parameter Modelica.Units.SI.Inertia J = 0.01 "Rotor moment of inertia (kg·m²)";
  parameter Modelica.Units.SI.RotationalDampingConstant B_fric = 0.001 "Viscous friction coefficient (N·m·s/rad)";
  parameter Modelica.Units.SI.AngularVelocity omega_ref =  75.0 "Reference speed (rad/s)";
  parameter Real K1 = 0.5 "Current feedback gain";
  parameter Real K2 = 0.5 "Speed feedback gain";
  parameter Real Kr = 0.62 "Reference feedforward gain";
  parameter Modelica.Units.SI.Torque T_load_step = 0.05 "Load torque step magnitude (N·m)";
  parameter Modelica.Units.SI.Time t_load = 5.0 "Load application time (s)";
  
  // Variables with start values (remove unit specification for SI types)
  Modelica.Units.SI.Current ia(start=0) "Armature current";
  Modelica.Units.SI.AngularVelocity omega(start=0) "Rotor speed";
  Modelica.Units.SI.Voltage Va "Applied armature voltage";
  Modelica.Units.SI.Voltage Vemf "Back EMF";
  Modelica.Units.SI.Torque T_motor "Motor electromagnetic torque";
  Modelica.Units.SI.Torque T_load "External load torque";
  Modelica.Units.SI.AngularVelocity omega_error "Speed tracking error (omega_ref - omega)";
  Modelica.Units.SI.Voltage u_control "Control signal (alias for Va)";
  
  // Standard library components
  Modelica.Blocks.Sources.Step referenceStep(
    height=omega_ref,
    offset=0,
    startTime=0) "Reference speed step input";
  
  Modelica.Blocks.Sources.Step loadTorqueStep(
    height=T_load_step,
    offset=0,
    startTime=t_load) "Load torque disturbance step";
  
  Modelica.Blocks.Math.Gain feedforwardGain(
    k=Kr) "Reference feedforward gain Kr";
  
  Modelica.Blocks.Math.Gain currentFeedbackGain(
    k=K1) "Current feedback gain K1";
  
  Modelica.Blocks.Math.Gain speedFeedbackGain(
    k=K2) "Speed feedback gain K2";
  
  Modelica.Blocks.Math.Add3 controlVoltageAdd(
    k1=+1,
    k2=-1,
    k3=-1) "Control voltage synthesis: Kr*omega_ref - K1*ia - K2*omega";
  
  // Feedback signals for control synthesis
  Modelica.Blocks.Sources.RealExpression currentSignal(y=ia) "Current measurement";
  Modelica.Blocks.Sources.RealExpression speedSignal(y=omega) "Speed measurement";
  
equation
  // Connect control blocks
  connect(referenceStep.y, feedforwardGain.u);
  connect(feedforwardGain.y, controlVoltageAdd.u1);
  connect(currentSignal.y, currentFeedbackGain.u);
  connect(currentFeedbackGain.y, controlVoltageAdd.u2);
  connect(speedSignal.y, speedFeedbackGain.u);
  connect(speedFeedbackGain.y, controlVoltageAdd.u3);
  
  // Control voltage assignment
  Va = controlVoltageAdd.y;
  u_control = Va;  // Alias as required
  
  // Load torque assignment
  T_load = loadTorqueStep.y;
  
  // DC motor physical equations
  // Electrical dynamics: La * der(ia) = Va - Ra * ia - Ke * omega
  La * der(ia) = Va - Ra * ia - Ke * omega;
  
  // Mechanical dynamics: J * der(omega) = Kt * ia - B_fric * omega - T_load
  J * der(omega) = Kt * ia - B_fric * omega - T_load;
  
  // Auxiliary variables
  Vemf = Ke * omega;
  T_motor = Kt * ia;
  
  // Speed tracking error
  omega_error = omega_ref - omega;
  
  // Initial conditions (already defined in variable declarations)
  
end DCMotorStateFeedback;
