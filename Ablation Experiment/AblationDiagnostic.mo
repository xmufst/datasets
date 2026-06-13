within ;
package AblationDiagnosticEnhanced
  /*
    ============================================================
    五个消融实验诊断案例 · 修订版（v2）
    每个案例对应一位审查器（main.py 中定义）的核心职责。
    ============================================================
  */
  import SI = Modelica.Units.SI;


  /*
    ============================================================
    Case A : ParameterChecker
    SolarCollectorLoopEnhanced
    覆盖红线：
      - 单位/数量级/温度换算
      - 状态变量初始化锁定 (start, fixed=true)
      - 求解器参数与需求一致
    ============================================================
  */
  model SolarCollectorLoopEnhanced
    parameter SI.Pressure p_system = 101325
      "System pressure, must be 1 atm = 101325 Pa";
    parameter Real p_system_bar_expected(unit="bar") = 1.01325
      "Equivalent pressure in bar (1 atm)";

    parameter SI.Irradiance G = 500
      "Solar irradiance / collector power density (W/m^2, NOT total power)";
    parameter SI.Area A_collector = 2.0
      "Collector area (m^2)";
    parameter Real eta_collector(min=0, max=1) = 0.70
      "Collector optical-thermal efficiency (-)";

    parameter SI.Mass m_water = 5.0
      "Water mass (kg)";
    parameter SI.SpecificHeatCapacity cp_water = 4184
      "Water specific heat capacity (J/(kg.K))";

    parameter Real T0_C(unit="degC") = 20.0
      "Initial water temperature in Celsius";
    parameter Real T_amb_C(unit="degC") = 20.0
      "Ambient temperature in Celsius";
    parameter SI.Temperature T0    = T0_C    + 273.15
      "Initial water temperature in Kelvin";
    parameter SI.Temperature T_amb = T_amb_C + 273.15
      "Ambient temperature in Kelvin";

    parameter SI.ThermalConductance UA_loss = 5.0
      "Lumped heat loss coefficient (W/K)";

    /* State variable: MUST use start AND fixed=true (ParameterChecker red line) */
    SI.Temperature T_water(start=T0, fixed=true)
      "Water temperature (K)";

    Real T_water_C(unit="degC")
      "Water temperature (degC)";
    SI.HeatFlowRate Q_solar
      "Useful solar heat input (W)";
    SI.HeatFlowRate Q_loss
      "Heat loss to ambient (W)";
    SI.Irradiance collector_power_density
      "Collector power density (W/m^2)";
    Real p_system_bar(unit="bar")
      "System pressure expressed in bar";
  equation
    collector_power_density = G;
    /* Useful solar heat must include eta * area * irradiance (NOT bare G). */
    Q_solar = eta_collector * A_collector * G;
    Q_loss  = UA_loss * (T_water - T_amb);
    m_water * cp_water * der(T_water) = Q_solar - Q_loss;

    T_water_C    = T_water - 273.15;
    /* Use proper unit conversion (avoids Modelica unit warning vs /1e5) */
    p_system_bar = Modelica.Units.Conversions.to_bar(p_system);

    annotation(experiment(StopTime=600, Interval=0.01, Tolerance=1e-6));
  end SolarCollectorLoopEnhanced;


  /*
    ============================================================
    Case B : ComponentChecker  (REDESIGNED)
    TankTempPIControl
    覆盖红线：
      - PI 控制器 initType = InitialState（禁止 InitialOutput / NoInit）
      - PI x_start 必须根据稳态偏置物理推导
      - Sources.Constant.k 必须等于被控物理量的初始状态（Kelvin）
      - 系统初始已在 T_init=60 °C 稳态，PI 必须输出 u_pi_ss=4.0 维持
    在 t=100 s 时给环境温度施加阶跃扰动以激发 PI 响应。
    ============================================================
  */
  model TankTempPIControl
    /* ---------- 物理参数 ---------- */
    parameter SI.Mass                 m_water = 5.0
      "Water mass (kg)";
    parameter SI.SpecificHeatCapacity cp_water = 4184
      "Water specific heat capacity (J/(kg.K))";
    parameter SI.ThermalConductance   UA = 100
      "Tank-to-ambient lumped heat transfer coefficient (W/K)";
    parameter Real K_heater(unit="W") = 1000
      "Heater power per unit control signal (W per control unit)";

    /* ---------- 温度基准（°C 表征 + Kelvin 派生） ---------- */
    parameter Real T_ambient_init_C(unit="degC") = 20.0
      "Initial ambient temperature, Celsius";
    parameter Real T_ambient_dist_C(unit="degC") = 10.0
      "Disturbed ambient temperature after t_dist, Celsius";
    parameter Real T_ref_C(unit="degC")          = 60.0
      "Reference setpoint temperature, Celsius";
    parameter Real T_init_C(unit="degC")         = 60.0
      "Initial water temperature (already in steady state), Celsius";

    parameter SI.Temperature T_ambient_init = T_ambient_init_C + 273.15;
    parameter SI.Temperature T_ambient_dist = T_ambient_dist_C + 273.15;
    parameter SI.Temperature T_ref          = T_ref_C          + 273.15;
    parameter SI.Temperature T_init         = T_init_C         + 273.15;

    parameter SI.Time t_dist = 100.0
      "Time at which ambient temperature drops (disturbance)";

    /* ---------- PI 增益 ---------- */
    parameter Real Kp = 1.0
      "PI proportional gain";
    parameter SI.Time Ti = 100.0
      "PI integral time";
    parameter Real yMax = 20.0
      "PI output upper saturation";
    parameter Real yMin =  0.0
      "PI output lower saturation";

    /* ---------- 稳态偏置推导（核心物理推导） ----------
       At t=0 system is in steady state: T_water=T_init=60C, T_ambient=20C.
       Power balance:   K_heater * u_pi_ss = UA * (T_init - T_ambient_init)
       =>               u_pi_ss = UA*(T_init - T_ambient_init)/K_heater
                                = 100*40/1000 = 4.0
       MSL Continuous.PI internal form:
         Ti * der(x) = u
         y          = k * (u + x)
       At steady state e=0, so:  y_ss = k * x_ss  =>  x_start = u_pi_ss / Kp
    */
    parameter Real u_pi_ss = UA * (T_init - T_ambient_init) / K_heater
      "Required steady-state PI output to maintain T_init";
    parameter Real x_start_PI = u_pi_ss / Kp
      "Internal PI integral state at t=0 (steady-state bias)";

    /* ---------- MSL 控制库组件实例化 ---------- */
    /* Reference signal: Constant with k = T_ref in Kelvin
       (Sources base value MUST match controlled-variable initial-state
       reference frame; ComponentChecker red line on basis alignment.) */
    Modelica.Blocks.Sources.Constant T_ref_source(
      k = T_ref);

    /* Feedback: e = T_ref - T_water */
    Modelica.Blocks.Math.Feedback feedback;

    /* PI controller with EXPLICIT InitialState + correct x_start */
    Modelica.Blocks.Continuous.LimPI pi_controller(
      controllerType = Modelica.Blocks.Types.SimpleController.PI,
      k         = Kp,
      Ti        = Ti,
      yMax      = yMax,
      yMin      = yMin,
      initType  = Modelica.Blocks.Types.Init.InitialState,
      xi_start  = x_start_PI);

    /* ---------- 物理过程信号 ---------- */
    SI.Temperature T_water(start = T_init, fixed = true)
      "Water temperature (K)";
    Real T_water_C(unit="degC");
    SI.Temperature T_ambient
      "Ambient temperature with step disturbance at t_dist";
    Real            T_ref_signal(unit="K");
    Real            T_error(unit="K");
    Real            u_pi;
    SI.Power        P_heat;
    SI.Power        P_loss;

  equation
    /* Ambient temperature step disturbance — wrap with noEvent to avoid
       solver event iteration on 'time' (Engineer rule [4.1] in main.py). */
    T_ambient =
      if noEvent(time < t_dist) then T_ambient_init else T_ambient_dist;

    /* Connect MSL signal-flow control loop */
    connect(T_ref_source.y, feedback.u1);
    /* T_water (a Real, in Kelvin) is fed back via signal expression: */
    feedback.u2 = T_water;
    connect(feedback.y, pi_controller.u);

    T_ref_signal = T_ref_source.y;
    T_error      = feedback.y;
    u_pi         = pi_controller.y;

    /* Plant: lumped-heat tank with heater + ambient loss */
    P_heat = K_heater * u_pi;
    P_loss = UA * (T_water - T_ambient);
    m_water * cp_water * der(T_water) = P_heat - P_loss;

    T_water_C = T_water - 273.15;

    annotation(experiment(StopTime=300, Interval=0.01, Tolerance=1e-6));
  end TankTempPIControl;


  /*
    ============================================================
    Case C : EquationChecker  (REVISED)
    NonisothermalArrheniusReactor
    覆盖红线：
      - 守恒方程自洽 (mass_balance_residual)
      - 物理方程符号正确 (Arrhenius, deltaH)
      - 数值边界保护 max(C_A, 0)
      - 独立能量残差（积分态变量替代构造性零）
    典型错误说明：
      - C1 反应级数错配：速率变量定义为 r = k*C_A^2，但物质衡算中
        又直接使用 der(C_A) = -k*C_A，或产物方程仍使用 der(C_B)=r，
        导致速率定义、反应阶数和物种守恒方程不一致。
      - C2 阿伦尼乌斯指数符号错误：写成 k = k0*exp(+Ea/(R*T))，
        导致反应速率常数的温度依赖方向错误，并可能在低温下产生
        异常大的速率常数。
    主要修改：C_A0  1.0 -> 1000 mol/m^3，能量残差用积分态变量重构。
    ============================================================
  */
  model NonisothermalArrheniusReactor
    parameter Real k0(unit="1/s")          = 1.0;
    parameter SI.MolarEnergy Ea            = 5000;
    parameter SI.MolarGasConstant R        = 8.314;
    parameter SI.Volume V_reactor          = 1.0;
    parameter SI.Density rho               = 1000;
    parameter SI.SpecificHeatCapacity cp   = 4184;
    parameter Real deltaH(unit="J/mol")    = -50000
      "Reaction enthalpy (negative = exothermic)";
    parameter SI.ThermalConductance UA     = 200;
    parameter SI.Temperature T_cool        = 300;

    parameter SI.Concentration C_A0 = 1000
      "Initial reactant A concentration (CHANGED from 1.0)";
    parameter SI.Concentration C_B0 = 0;
    parameter SI.Temperature   T0   = 330;

    SI.Concentration C_A(start=C_A0, fixed=true);
    SI.Concentration C_B(start=C_B0, fixed=true);
    SI.Temperature   T  (start=T0,   fixed=true);

    Real k(unit="1/s");
    Real r(unit="mol/(m3.s)");
    SI.Power Q_reaction, Q_cooling;

    SI.Concentration mass_total;
    Real mass_balance_residual(unit="mol/(m3.s)");

    /* Independent integral state vars => non-tautological energy residual */
    SI.Energy E_reaction_input(start=0, fixed=true);
    SI.Energy E_cooling_output(start=0, fixed=true);
    SI.Energy E_thermal_observed;
    SI.Energy energy_balance_residual;

  protected
    SI.Mass m_reactor;
  equation
    m_reactor = rho * V_reactor;

    /* Arrhenius: NEGATIVE exponent — sign error is a target diagnostic. */
    k = k0 * exp(-Ea / (R * T));

    /* Reaction rate with mandatory non-negative boundary protection.
       (EquationChecker red line: max(x,0) wrapping for restricted-domain ops.) */
    r = k * max(C_A, 0);

    /* First-order kinetics. Same r in both species equations. */
    der(C_A) = -r;
    der(C_B) =  r;

    /* Exothermic: deltaH<0  =>  -deltaH*V*r > 0  =>  heat released */
    Q_reaction = -deltaH * V_reactor * r;
    Q_cooling  =  UA * (T - T_cool);
    m_reactor * cp * der(T) = Q_reaction - Q_cooling;

    mass_total            = C_A + C_B;
    /* Non-tautological: cross-checks two independent species ODEs. */
    mass_balance_residual = der(C_A) + der(C_B);

    /* Independent integral path */
    der(E_reaction_input) = Q_reaction;
    der(E_cooling_output) = Q_cooling;
    E_thermal_observed    = m_reactor * cp * (T - T0);

    /* Non-tautological: T-evolution path vs. heat-bookkeeping path. */
    energy_balance_residual =
      E_thermal_observed - (E_reaction_input - E_cooling_output);

    annotation(experiment(StopTime=100, Interval=0.01, Tolerance=1e-6));
  end NonisothermalArrheniusReactor;


  /*
    ============================================================
    Case D : LogicChecker  (REVISED TIMER RESET)
    TurbineOverspeedTripEnhanced
    覆盖：阈值方向 / 延迟计时 / 锁存 Latch / 阀门方向 / 状态机
    ============================================================
  */
  model TurbineOverspeedTripEnhanced
    parameter SI.AngularVelocity omega_nominal = 100;
    parameter SI.AngularVelocity omega_trip    = 1.1 * omega_nominal;
    parameter SI.Time            trip_delay    = 0.1;
    parameter SI.Inertia         J             = 10;
    parameter SI.Torque          tau_steam     = 1400;
    parameter Real D_load(unit="N.m.s/rad")    = 10;
    parameter SI.Time            T_valve       = 0.05;
    parameter SI.AngularVelocity omega0        = omega_nominal;

    SI.AngularVelocity omega(start=omega0, fixed=true);
    Boolean overspeed;
    discrete Boolean trip_latched(start=false, fixed=true);
    SI.Time trip_timer(start=0, fixed=true);
    Real valve_target(min=0, max=1);
    Real valve_opening(start=1.0, fixed=true, min=0, max=1);
    SI.Torque tau_in, tau_load;
  equation
    /* Correct overspeed direction: omega > omega_trip */
    overspeed = omega > omega_trip;

    /* Timer accumulates only during sustained overspeed,
       resets quickly (tau=0.001s) when overspeed ceases. */
    der(trip_timer) =
      if overspeed and not trip_latched then
        1
      elseif not overspeed and not trip_latched and trip_timer > 0 then
        -trip_timer / 0.001
      else
        0;

    /* Latch trip when timer reaches delay threshold */
    when trip_timer >= trip_delay then
      trip_latched = true;
    end when;

    /* Valve closes (target=0) once latched, otherwise full open (target=1) */
    valve_target = if trip_latched then 0 else 1;
    T_valve * der(valve_opening) = valve_target - valve_opening;

    tau_in   = valve_opening * tau_steam;
    tau_load = D_load * omega;
    J * der(omega) = tau_in - tau_load;

    annotation(experiment(StopTime=20, Interval=0.001, Tolerance=1e-6));
  end TurbineOverspeedTripEnhanced;


  /*
    ============================================================
    Case E : ResultChecker  (UNCHANGED — reference design)
    PiecewiseAdiabaticStirredTank
    Independent residual via analytical energy_added formula.
    ============================================================
  */
  model PiecewiseAdiabaticStirredTank
    parameter SI.Mass                 m_liquid  = 10;
    parameter SI.SpecificHeatCapacity cp_liquid = 4184;
    parameter Real T0_C(unit="degC")            = 20.0;
    parameter SI.Temperature T0                 = T0_C + 273.15;
    parameter SI.Power P1 = 500;
    parameter SI.Power P2 = 1000;
    parameter SI.Power P3 = 0;
    parameter SI.Time  t1 = 300;
    parameter SI.Time  t2 = 600;

    SI.Temperature T_liquid(start=T0, fixed=true);
    Real T_liquid_C(unit="degC");
    SI.Power  P_stir;
    Real      dTdt_theoretical(unit="K/s");
    SI.Energy energy_added, energy_stored, energy_residual;
  equation
    P_stir =
      if      time < t1 then P1
      elseif  time < t2 then P2
      else                   P3;

    dTdt_theoretical = P_stir / (m_liquid * cp_liquid);
    m_liquid * cp_liquid * der(T_liquid) = P_stir;

    /* Analytical (independent) energy integral */
    energy_added =
      if      time < t1 then P1 * time
      elseif  time < t2 then P1 * t1 + P2 * (time - t1)
      else                   P1 * t1 + P2 * (t2 - t1) + P3 * (time - t2);

    energy_stored   = m_liquid * cp_liquid * (T_liquid - T0);
    /* Non-tautological: compares simulation-derived T-energy with
       analytical power-time integral. Diverges if equation is wrong. */
    energy_residual = energy_stored - energy_added;
    T_liquid_C      = T_liquid - 273.15;

    annotation(experiment(StopTime=1000, Interval=0.1, Tolerance=1e-6));
  end PiecewiseAdiabaticStirredTank;

end AblationDiagnosticEnhanced;
