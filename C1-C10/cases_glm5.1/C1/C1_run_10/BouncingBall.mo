model BouncingBall
  // A bouncing ball with gravity, elastic collision, and energy loss,
  // using speed truncation threshold to prevent Zeno phenomenon.
  // Simulation settings per original_user_task:
  //   step_size =  0.85 s
  //   solver_method = dassl
  //   tolerance =  0.85e-6

  // Parameters with description and unit
  parameter Real g = 9.81 annotation(Documentation(info="Gravity acceleration", unit="m/s^2"));
  parameter Real e =  0.85 annotation(Documentation(info="Restitution coefficient", unit="1"));
  parameter Real h0 =  15.0 annotation(Documentation(info="Initial release height", unit="m"));
  parameter Real v0 = 0.0 annotation(Documentation(info="Initial velocity", unit="m/s"));
  parameter Real v_threshold = 0.01 annotation(Documentation(info="Zeno truncation speed threshold", unit="m/s"));

  // Variables with start and unit attributes
  Real h(start=h0, unit="m") "Height of ball";
  Real v(start=v0, unit="m/s") "Velocity of ball";

equation
  // Kinematic relationships
  der(h) = v;
  der(v) = if (h <= 0 and v < 0) then 0 else -g;  // Support force when on ground and trying to go down

  // Discrete collision event with Zeno prevention
  when h <= 0 then
    reinit(v, if pre(v) < -v_threshold then -e * pre(v) else 0);
    reinit(h, 0);  // Reset height to ground level
  end when;

end BouncingBall;
