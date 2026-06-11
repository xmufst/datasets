model FurnaceFeedforward
  "Using Modelica Standard Library components to implement a pure feedforward disturbance compensation control system for a furnace."
  
  // Parameters with units
  parameter Real C_furnace(unit="J/K") = 5000.0 "Furnace heat capacity";
  parameter Real K_heater(unit="W/unit") = 100.0 "Heater power gain (W/unit as per requirement)";
  parameter Real UA(unit="W/K") = 5.0 "Heat transfer coefficient";
  parameter Real T_amb(unit="degC") = 20.0 "Ambient temperature";
  parameter Real Q_ss(unit="W") = 300.0 "Steady-state base heating power";
  parameter Real T0(unit="degC") = 80.0 "Initial temperature parameter";
  parameter Real Q_dist(unit="W") = 200.0 "Disturbance power step amplitude";
  parameter Real t_dist(unit="s") = 100.0 "Disturbance application time";
  parameter Real K_ff(unit="1") = 1.0 "Feedforward gain";
  
  // Variables with start attributes and units
  Real T(start=T0, unit="degC") "Furnace real-time temperature";
  Real Q_heater(unit="W") "Total heating power";
  Real Q_loss(unit="W") "Heat loss power";
  Real Q_disturbance(unit="W") "Disturbance heat load";
  Real u_ff(unit="W") "Feedforward compensation signal";
  
  // Control loop components from Modelica Standard Library
  Modelica.Blocks.Sources.Constant Q_steady(k=Q_ss) 
    annotation (Placement(transformation(extent={{-80,40},{-60,60}})));
  Modelica.Blocks.Sources.Step disturbance(
    height=Q_dist,
    startTime=t_dist,
    offset=0)
    annotation (Placement(transformation(extent={{-80,-20},{-60,0}})));
  Modelica.Blocks.Math.Gain feedforward_gain(k=K_ff)
    annotation (Placement(transformation(extent={{-40,-20},{-20,0}})));
  Modelica.Blocks.Math.Add add_signals(k1=+1, k2=+1)
    annotation (Placement(transformation(extent={{0,20},{20,40}})));
  
equation
  // Connect control loop components
  connect(Q_steady.y, add_signals.u1);
  connect(disturbance.y, feedforward_gain.u);
  connect(feedforward_gain.y, add_signals.u2);
  
  // Assign signals to output variables
  Q_heater = add_signals.y;  // Remove heater_gain, direct assignment
  Q_disturbance = disturbance.y;
  u_ff = feedforward_gain.y;
  
  // Physical model of furnace
  // Heat loss by Newton's law of cooling
  Q_loss = UA * (T - T_amb);
  
  // Energy balance: C_furnace * dT/dt = Q_heater - Q_loss - Q_disturbance
  C_furnace * der(T) = Q_heater - Q_loss - Q_disturbance;
  
  // Initial condition
  initial equation
    T = T0;
  
  annotation (
    uses(Modelica(version="4.0.0")),
    experiment(
      StopTime=300,
      Interval=0.01,
      Tolerance=1e-6,
      __Dymola_Algorithm="dassl"));
end FurnaceFeedforward;
