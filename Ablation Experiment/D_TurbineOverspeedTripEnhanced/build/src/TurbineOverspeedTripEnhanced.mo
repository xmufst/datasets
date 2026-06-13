model TurbineOverspeedTripEnhanced
  parameter Real omega_rated = 100 "Rated speed (rad/s)";
  parameter Real omega_trip = 110 "Overspeed trip threshold (rad/s)";
  parameter Real trip_delay = 0.1 "Trip delay time (s)";
  parameter Real J = 10 "Rotor inertia (kg.m2)";
  parameter Real tau_steam_rated = 1400 "Rated steam torque (N.m)";
  parameter Real d_load = 10 "Load damping coefficient (N.m.s/rad)";
  parameter Real T_valve = 0.05 "Valve time constant (s)";
  parameter Real t_short_start = 1.0 "Short overspeed test start time (s)";
  parameter Real t_short_dur = 0.05 "Short overspeed test duration (s)";
  parameter Real t_long_start = 3.0 "Long overspeed test start time (s)";
  parameter Real t_long_dur = 0.3 "Long overspeed test duration (s)";

  Real omega(start = 100, fixed = true, unit = "rad/s") "Turbine speed";
  Real valve_opening(start = 1.0, fixed = true, unit = "1") "Main steam valve actual opening";
  Real trip_timer(start = 0, fixed = true, unit = "s") "Overspeed duration timer";
  Boolean trip_latched(start = false, fixed = true) "Trip latch signal";
  Boolean overspeed "Overspeed detection signal";
  Real valve_target(unit = "1") "Valve target opening";
  Real tau_in(unit = "N.m") "Steam input torque";
  Real tau_load(unit = "N.m") "Load torque";
  Real tau_disturb(unit = "N.m") "Equivalent disturbance torque";

equation
  // Disturbance torque generation: two-phase overspeed test
  tau_disturb = if (time >= t_short_start and time < t_short_start + t_short_dur) or
                   (time >= t_long_start and time < t_long_start + t_long_dur) then 2000 else 0;

  // Rotor dynamics
  J * der(omega) = tau_in + tau_disturb - tau_load;

  // Torque calculations
  tau_in = tau_steam_rated * valve_opening;
  tau_load = d_load * omega;

  // First-order valve dynamics
  T_valve * der(valve_opening) = valve_target - valve_opening;

  // Valve target logic
  valve_target = if trip_latched then 0 else 1;

  // Overspeed detection
  overspeed = omega >= omega_trip;

  // Trip timer: increment when overspeed and not latched
  der(trip_timer) = if overspeed and not trip_latched then 1 else 0;

  // Reset timer when not overspeed and not latched
  when not overspeed and not pre(trip_latched) then
    reinit(trip_timer, 0);
  end when;

  // Trip latch: lock when timer exceeds delay
  when trip_timer >= trip_delay and not pre(trip_latched) then
    trip_latched = true;
  end when;

  annotation(
    experiment(StopTime = 20, Interval = 0.001, Tolerance = 1e-6),
    Documentation(info = "<html>Turbine overspeed trip protection with delayed trip and latch mechanism.</html>")
  );
end TurbineOverspeedTripEnhanced;
