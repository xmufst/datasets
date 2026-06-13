model RCCircuit
  "Simulate charging and discharging of a first-order RC circuit with resistor and capacitor in series"

  // Parameters
  parameter Real R =  2000.0 "Resistance (Ohm)" annotation(unit = "Ohm");
  parameter Real C = 0.001 "Capacitance (F)" annotation(unit = "F");
  parameter Real V_source = 10.0 "Source voltage amplitude (V)" annotation(unit = "V");
  parameter Real t_switch = 5.0 "Source disconnect time (s)" annotation(unit = "s");
  parameter Real Vc0 = 0.0 "Initial capacitor voltage (V)" annotation(unit = "V");

  // Variables
  Real Vc(start=Vc0, unit="V") "Capacitor voltage";
  Real E_dissipated(start=0.0, fixed=true, unit="J") "Accumulated dissipated energy";
  Real V_in(unit="V") "Input voltage";
  Real i(unit="A") "Circuit current";
  Real P_resistor(unit="W") "Resistor power dissipation";
  Real E_capacitor(unit="J") "Capacitor stored energy";
  Real tau(unit="s") "Time constant";

  // MSL Components
  Modelica.Electrical.Analog.Basic.Resistor resistor(R=R)
    annotation(Placement(transformation(extent={{-20,20},{0,40}})));
  Modelica.Electrical.Analog.Basic.Capacitor capacitor(C=C, v(start=Vc0, fixed=true))
    annotation(Placement(transformation(extent={{20,20},{40,40}})));
  Modelica.Electrical.Analog.Basic.Ground ground
    annotation(Placement(transformation(extent={{-10,-40},{10,-20}})));
  Modelica.Electrical.Analog.Sources.SignalVoltage signalVoltage
    annotation(Placement(transformation(extent={{-50,20},{-30,40}})));
  Modelica.Blocks.Sources.Step stepSignal(height=-V_source, offset=V_source, startTime=t_switch)
    annotation(Placement(transformation(extent={{-80,50},{-60,70}})));

equation
  // Derived quantities from circuit components
  Vc = capacitor.v;
  V_in = signalVoltage.v;
  i = resistor.i;
  P_resistor = R * i * i;
  E_capacitor =  2000.0 * C * Vc * Vc;
  tau = R * C;
  der(E_dissipated) = P_resistor;

  // Circuit topology connections
  connect(stepSignal.y, signalVoltage.v);
  connect(signalVoltage.p, resistor.p);
  connect(resistor.n, capacitor.p);
  connect(capacitor.n, signalVoltage.n);
  connect(ground.p, signalVoltage.n);

end RCCircuit;
