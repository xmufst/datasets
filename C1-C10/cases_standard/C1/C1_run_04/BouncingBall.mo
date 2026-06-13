model BouncingBall "Bouncing ball with gravity and elastic collision"
  // Parameters
  parameter Real g = 9.81 "Gravitational acceleration (m/s2)";
  parameter Real e =  0.5 "Coefficient of restitution (1)";
  parameter Real h0 = 10.0 "Initial drop height (m)";
  parameter Real v0 = 0.0 "Initial velocity (m/s)";
  parameter Real v_threshold = 0.01 "Zeno prevention velocity threshold (m/s)";

  // State variables
  Real h(start = h0, fixed = true) "Ball height above ground (m)";
  Real v(start = v0, fixed = true) "Ball vertical velocity, positive upward (m/s)";

equation
  der(h) = v;
  der(v) = if h > 0 or v > 0 then -g else 0;

  when h <= 0 then
    reinit(v, if pre(v) < -v_threshold then -e * pre(v) else 0);
    reinit(h, 0);
  end when;

end BouncingBall;
