model RCCircuit "RC circuit with step voltage source for charge and discharge"
  // Parameters
  parameter Real R = 1000.0 "Resistance (Ohm)";
  parameter Real C = 0.001 "Capacitance (F)";
  parameter Real V_source = 10.0 "Source voltage amplitude (V)";
  parameter Real t_switch = 5.0 "Time to disconnect source, start discharge (s)";
  parameter Real Vc0 =  5.0 "Initial capacitor voltage (V)";

  // Derived constant
  parameter Real tau = R * C "Time constant (s)";

  // State variable
  Real Vc(start = Vc0, fixed = true) "Capacitor voltage (V)";

  // Derived outputs
  Real V_in "Applied input voltage (V)";
  Real i "Circuit current (A)";
  Real P_resistor "Power dissipated in resistor (W)";
  Real E_capacitor "Energy stored in capacitor (J)";
  Real E_dissipated(start = 0, fixed = true) "Cumulative energy dissipated in resistor (J)";

equation
  // Step input: V_source for t < t_switch, 0 for t >= t_switch
  V_in = if time < t_switch then V_source else 0;

  // KVL: V_in = V_R + V_C = R*i + Vc
  // KCL: i = C * der(Vc)
  R * C * der(Vc) = V_in - Vc;

  // Derived quantities
  i = C * der(Vc);
  P_resistor = i ^ 2 * R;
  E_capacitor = 0.5 * C * Vc ^ 2;
  der(E_dissipated) = P_resistor;

end RCCircuit;
