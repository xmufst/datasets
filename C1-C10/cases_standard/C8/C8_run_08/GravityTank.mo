model GravityTank "Open tank with constant inflow and Torricelli gravity outflow"
  // Parameters
  parameter Real A_tank = 0.1 "Cross-sectional area of tank (m2)";
  parameter Real A_orifice = 0.01 "Orifice area at tank bottom (m2)";
  parameter Real Cd = 0.61 "Discharge coefficient (1)";
  parameter Real g = 9.81 "Gravitational acceleration (m/s2)";
  parameter Real h0 =  0.2 "Initial liquid level (m)";
  parameter Real Q_in =  0.02 "Constant volumetric inflow rate (m3/s)";

  // State variable
  Real h(start = h0, fixed = true) "Liquid level in tank (m)";

  // Derived outputs
  Real Q_out "Volumetric outflow rate (m3/s)";
  Real v_out "Outflow velocity at orifice (m/s)";
  Real V_liquid "Liquid volume in tank (m3)";
  Real Q_net "Net flow rate, positive = filling (m3/s)";

equation
  // Torricelli outflow with protection against negative h
  v_out = sqrt(2 * g * max(h, 0));
  Q_out = Cd * A_orifice * v_out;

  // Mass balance
  A_tank * der(h) = Q_in - Q_out;

  // Derived quantities
  V_liquid = A_tank * h;
  Q_net = Q_in - Q_out;

end GravityTank;
