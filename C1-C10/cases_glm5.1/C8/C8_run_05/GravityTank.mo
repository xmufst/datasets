model GravityTank
  // Parameters with unit attributes
  parameter Modelica.Units.SI.Area A_tank = 0.1 "Cross-sectional area of tank (m^2)";
  parameter Modelica.Units.SI.Area A_orifice =  0.005 "Area of orifice (m^2)";
  parameter Real Cd = 0.61 "Discharge coefficient (dimensionless)";
  parameter Modelica.Units.SI.Acceleration g = 9.81 "Gravitational acceleration (m/s^2)";
  parameter Modelica.Units.SI.Length h0 = 2.0 "Initial liquid level (m)";
  parameter Modelica.Units.SI.VolumeFlowRate Q_in = 0.0 "Constant inflow rate (m^3/s)";
  
  // Variables
  Modelica.Units.SI.Length h(start = h0) "Liquid level height";
  Modelica.Units.SI.VolumeFlowRate Q_out "Outflow rate through orifice";
  Modelica.Units.SI.Velocity v_out "Velocity at orifice";
  Modelica.Units.SI.Volume V_liquid "Liquid volume in tank";
  Modelica.Units.SI.VolumeFlowRate Q_net "Net inflow rate";
  
equation 
  // Derivative equation for liquid level
  der(h) = Q_net / A_tank;
  
  // Orifice outflow (Torricelli's law)
  Q_out = Cd * A_orifice * sqrt(2 * g * max(h, 0));
  
  // Orifice velocity
  v_out = sqrt(2 * g * max(h, 0));
  
  // Liquid volume
  V_liquid = A_tank * h;
  
  // Net flow rate
  Q_net = Q_in - Q_out;
  
  // Discrete event for boundary protection
  when h <= 0 then
    reinit(h, 0);
  end when;
  
initial equation 
  // Initial condition for liquid level
  h = h0;
  
  // Assertion for non-negative initial level
  assert(h0 >= 0, "Initial liquid level must be non-negative");
end GravityTank;
