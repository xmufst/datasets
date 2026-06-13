model DCMotorStateFeedback
  "DC motor speed control via full state feedback (pole placement)"

  import Modelica.Blocks.Sources;
  import Modelica.Blocks.Math;

  // Motor parameters
  parameter Real Ra = 1.0 "Armature resistance (Ohm)";
  parameter Real La = 0.01 "Armature inductance (H)";
  parameter Real Ke = 0.1 "Back-EMF constant (V.s/rad)";
  parameter Real Kt = 0.1 "Torque constant (N.m/A)";
  parameter Real J = 0.01 "Rotor inertia (kg.m2)";
  parameter Real B_fric = 0.001 "Viscous friction coefficient (N.m.s/rad)";

  // Control parameters
  parameter Real omega_ref =  175.0 "Reference speed (rad/s)";
  parameter Real K1 = 0.5 "State feedback gain for armature current";
  parameter Real K2 = 0.5 "State feedback gain for rotor speed";
  parameter Real Kr = 0.62 "Reference feedforward gain";

  // Load disturbance parameters
  parameter Real T_load_step = 0.05 "Load torque step magnitude (N.m)";
  parameter Real t_load = 5.0 "Load torque step time (s)";

  // ---- MSL components ----
  Sources.Step refSignal(height = omega_ref, startTime = 0)
    "Reference speed step input";
  Sources.Step loadDisturbance(height = T_load_step, startTime = t_load)
    "Load torque step disturbance";
  Math.Gain gainKr(k = Kr) "Reference feedforward gain";
  Math.Gain gainK1(k = K1) "Current feedback gain";
  Math.Gain gainK2(k = K2) "Speed feedback gain";
  Math.Add3 sumControl(k1 = +1, k2 = -1, k3 = -1)
    "Control summing junction: Kr*ref - K1*ia - K2*omega";

  // ---- State variables ----
  Real ia(start = 0, fixed = true, unit = "A") "Armature current";
  Real omega(start = 0, fixed = true, unit = "rad/s") "Rotor speed";

  // ---- Target output variables ----
  Real Va(unit = "V") "Armature voltage (control input)";
  Real Vemf(unit = "V") "Back-EMF voltage";
  Real T_motor(unit = "N.m") "Electromagnetic torque";
  Real T_load(unit = "N.m") "External load torque";
  Real omega_error(unit = "rad/s") "Speed tracking error";
  Real u_control(unit = "V") "Control signal (= Va)";

equation
  // Control signal chain using MSL blocks
  connect(refSignal.y, gainKr.u);
  gainK1.u = ia;
  gainK2.u = omega;
  connect(gainKr.y, sumControl.u1);
  connect(gainK1.y, sumControl.u2);
  connect(gainK2.y, sumControl.u3);

  // Control output
  Va = sumControl.y;
  u_control = Va;

  // Load torque from step source
  T_load = loadDisturbance.y;

  // Motor electrical dynamics
  Vemf = Ke * omega;
  La * der(ia) = Va - Ra * ia - Vemf;

  // Motor mechanical dynamics
  T_motor = Kt * ia;
  J * der(omega) = T_motor - B_fric * omega - T_load;

  // Tracking error
  omega_error = omega_ref - omega;

end DCMotorStateFeedback;
