/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "TankTempPIControl_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 59
type: SIMPLE_ASSIGN
$START.P_loss = P_loss_ss
*/
static void TankTempPIControl_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
  (data->modelData->realVarsData[5] /* P_loss variable */).attribute .start = (data->simulationInfo->realParameter[1] /* P_loss_ss PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* P_loss variable */) = (data->modelData->realVarsData[5] /* P_loss variable */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[5].info /* P_loss */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* P_loss variable */));
  TRACE_POP
}

/*
equation index: 60
type: SIMPLE_ASSIGN
$START.P_heat = P_loss_ss
*/
static void TankTempPIControl_eqFunction_60(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,60};
  (data->modelData->realVarsData[4] /* P_heat variable */).attribute .start = (data->simulationInfo->realParameter[1] /* P_loss_ss PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* P_heat variable */) = (data->modelData->realVarsData[4] /* P_heat variable */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[4].info /* P_heat */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* P_heat variable */));
  TRACE_POP
}

/*
equation index: 61
type: SIMPLE_ASSIGN
$START.u_pi = u_pi_ss
*/
static void TankTempPIControl_eqFunction_61(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
  (data->modelData->realVarsData[18] /* u_pi variable */).attribute .start = (data->simulationInfo->realParameter[60] /* u_pi_ss PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* u_pi variable */) = (data->modelData->realVarsData[18] /* u_pi variable */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[18].info /* u_pi */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* u_pi variable */));
  TRACE_POP
}

/*
equation index: 62
type: SIMPLE_ASSIGN
$START.piController.I.y = piController.I.y_start
*/
static void TankTempPIControl_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
  (data->modelData->realVarsData[1] /* piController.I.y STATE(1) */).attribute .start = (data->simulationInfo->realParameter[19] /* piController.I.y_start PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piController.I.y STATE(1) */) = (data->modelData->realVarsData[1] /* piController.I.y STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* piController.I.y */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piController.I.y STATE(1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int TankTempPIControl_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating min-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* max ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating max-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* nominal **************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating nominal-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating primary start-values");
  TankTempPIControl_eqFunction_59(data, threadData);

  TankTempPIControl_eqFunction_60(data, threadData);

  TankTempPIControl_eqFunction_61(data, threadData);

  TankTempPIControl_eqFunction_62(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void TankTempPIControl_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 63
type: SIMPLE_ASSIGN
piController.addPID.u2 = piController.Dzero.k
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_63(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,63};
  (data->simulationInfo->realParameter[38] /* piController.addPID.u2 PARAM */) = (data->simulationInfo->realParameter[14] /* piController.Dzero.k PARAM */);
  TRACE_POP
}

/*
equation index: 64
type: SIMPLE_ASSIGN
piController.Dzero.y = piController.Dzero.k
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_64(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,64};
  (data->simulationInfo->realParameter[15] /* piController.Dzero.y PARAM */) = (data->simulationInfo->realParameter[14] /* piController.Dzero.k PARAM */);
  TRACE_POP
}

/*
equation index: 65
type: SIMPLE_ASSIGN
piController.addFF.u2 = piController.FFzero.k
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  (data->simulationInfo->realParameter[27] /* piController.addFF.u2 PARAM */) = (data->simulationInfo->realParameter[16] /* piController.FFzero.k PARAM */);
  TRACE_POP
}

/*
equation index: 66
type: SIMPLE_ASSIGN
piController.FFzero.y = piController.FFzero.k
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_66(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,66};
  (data->simulationInfo->realParameter[17] /* piController.FFzero.y PARAM */) = (data->simulationInfo->realParameter[16] /* piController.FFzero.k PARAM */);
  TRACE_POP
}

/*
equation index: 67
type: SIMPLE_ASSIGN
refTemp.k = 273.15 + T_ref
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_67(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,67};
  (data->simulationInfo->realParameter[57] /* refTemp.k PARAM */) = 273.15 + (data->simulationInfo->realParameter[4] /* T_ref PARAM */);
  TRACE_POP
}

/*
equation index: 68
type: SIMPLE_ASSIGN
piController.addI.u1 = refTemp.k
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_68(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,68};
  (data->simulationInfo->realParameter[31] /* piController.addI.u1 PARAM */) = (data->simulationInfo->realParameter[57] /* refTemp.k PARAM */);
  TRACE_POP
}

/*
equation index: 69
type: SIMPLE_ASSIGN
piController.addP.u1 = refTemp.k
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_69(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,69};
  (data->simulationInfo->realParameter[34] /* piController.addP.u1 PARAM */) = (data->simulationInfo->realParameter[57] /* refTemp.k PARAM */);
  TRACE_POP
}

/*
equation index: 70
type: SIMPLE_ASSIGN
piController.u_s = refTemp.k
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_70(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,70};
  (data->simulationInfo->realParameter[47] /* piController.u_s PARAM */) = (data->simulationInfo->realParameter[57] /* refTemp.k PARAM */);
  TRACE_POP
}

/*
equation index: 71
type: SIMPLE_ASSIGN
T_ref_signal = refTemp.k
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_71(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,71};
  (data->simulationInfo->realParameter[5] /* T_ref_signal PARAM */) = (data->simulationInfo->realParameter[57] /* refTemp.k PARAM */);
  TRACE_POP
}

/*
equation index: 72
type: SIMPLE_ASSIGN
refTemp.y = refTemp.k
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_72(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,72};
  (data->simulationInfo->realParameter[58] /* refTemp.y PARAM */) = (data->simulationInfo->realParameter[57] /* refTemp.k PARAM */);
  TRACE_POP
}

/*
equation index: 73
type: SIMPLE_ASSIGN
heaterGain.k = k_heater
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_73(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,73};
  (data->simulationInfo->realParameter[12] /* heaterGain.k PARAM */) = (data->simulationInfo->realParameter[13] /* k_heater PARAM */);
  TRACE_POP
}

/*
equation index: 74
type: SIMPLE_ASSIGN
piController.addFF.k2 = piController.kFF
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_74(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,74};
  (data->simulationInfo->realParameter[26] /* piController.addFF.k2 PARAM */) = (data->simulationInfo->realParameter[44] /* piController.kFF PARAM */);
  TRACE_POP
}

/*
equation index: 79
type: SIMPLE_ASSIGN
piController.k = Kp
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_79(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,79};
  (data->simulationInfo->realParameter[43] /* piController.k PARAM */) = (data->simulationInfo->realParameter[0] /* Kp PARAM */);
  TRACE_POP
}

/*
equation index: 80
type: SIMPLE_ASSIGN
piController.gainTrack.k = 1.0 / (piController.Ni * piController.k)
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_80(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,80};
  (data->simulationInfo->realParameter[42] /* piController.gainTrack.k PARAM */) = DIVISION_SIM(1.0,((data->simulationInfo->realParameter[21] /* piController.Ni PARAM */)) * ((data->simulationInfo->realParameter[43] /* piController.k PARAM */)),"piController.Ni * piController.k",equationIndexes);
  TRACE_POP
}

/*
equation index: 81
type: SIMPLE_ASSIGN
piController.gainPID.k = piController.k
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_81(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,81};
  (data->simulationInfo->realParameter[41] /* piController.gainPID.k PARAM */) = (data->simulationInfo->realParameter[43] /* piController.k PARAM */);
  TRACE_POP
}

/*
equation index: 82
type: SIMPLE_ASSIGN
P_loss_ss = h_env * (T_ref - T_ambient_init)
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_82(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,82};
  (data->simulationInfo->realParameter[1] /* P_loss_ss PARAM */) = ((data->simulationInfo->realParameter[11] /* h_env PARAM */)) * ((data->simulationInfo->realParameter[4] /* T_ref PARAM */) - (data->simulationInfo->realParameter[3] /* T_ambient_init PARAM */));
  TRACE_POP
}

/*
equation index: 83
type: SIMPLE_ASSIGN
u_pi_ss = P_loss_ss / k_heater
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_83(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,83};
  (data->simulationInfo->realParameter[60] /* u_pi_ss PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[1] /* P_loss_ss PARAM */),(data->simulationInfo->realParameter[13] /* k_heater PARAM */),"k_heater",equationIndexes);
  TRACE_POP
}

/*
equation index: 84
type: SIMPLE_ASSIGN
piController.xi_start = u_pi_ss
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_84(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,84};
  (data->simulationInfo->realParameter[51] /* piController.xi_start PARAM */) = (data->simulationInfo->realParameter[60] /* u_pi_ss PARAM */);
  TRACE_POP
}

/*
equation index: 85
type: SIMPLE_ASSIGN
piController.I.y_start = piController.xi_start
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_85(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,85};
  (data->simulationInfo->realParameter[19] /* piController.I.y_start PARAM */) = (data->simulationInfo->realParameter[51] /* piController.xi_start PARAM */);
  TRACE_POP
}

/*
equation index: 89
type: SIMPLE_ASSIGN
piController.Ti = Ti
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_89(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,89};
  (data->simulationInfo->realParameter[24] /* piController.Ti PARAM */) = (data->simulationInfo->realParameter[6] /* Ti PARAM */);
  TRACE_POP
}

/*
equation index: 90
type: SIMPLE_ASSIGN
piController.I.k = 1.0 / piController.Ti
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_90(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
  (data->simulationInfo->realParameter[18] /* piController.I.k PARAM */) = DIVISION_SIM(1.0,(data->simulationInfo->realParameter[24] /* piController.Ti PARAM */),"piController.Ti",equationIndexes);
  TRACE_POP
}

/*
equation index: 91
type: SIMPLE_ASSIGN
piController.addP.k1 = piController.wp
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_91(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,91};
  (data->simulationInfo->realParameter[32] /* piController.addP.k1 PARAM */) = (data->simulationInfo->realParameter[49] /* piController.wp PARAM */);
  TRACE_POP
}

/*
equation index: 100
type: SIMPLE_ASSIGN
ambTemp.startTime = t_disturb
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_100(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,100};
  (data->simulationInfo->realParameter[9] /* ambTemp.startTime PARAM */) = (data->simulationInfo->realParameter[59] /* t_disturb PARAM */);
  TRACE_POP
}

/*
equation index: 101
type: SIMPLE_ASSIGN
ambTemp.offset = 273.15 + T_ambient_init
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,101};
  (data->simulationInfo->realParameter[8] /* ambTemp.offset PARAM */) = 273.15 + (data->simulationInfo->realParameter[3] /* T_ambient_init PARAM */);
  TRACE_POP
}

/*
equation index: 102
type: SIMPLE_ASSIGN
ambTemp.height = T_ambient_disturb - T_ambient_init
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,102};
  (data->simulationInfo->realParameter[7] /* ambTemp.height PARAM */) = (data->simulationInfo->realParameter[2] /* T_ambient_disturb PARAM */) - (data->simulationInfo->realParameter[3] /* T_ambient_init PARAM */);
  TRACE_POP
}
extern void TankTempPIControl_eqFunction_2(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_1(DATA *data, threadData_t *threadData);


/*
equation index: 105
type: ALGORITHM

  assert(piController.limiter.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and piController.limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, "Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= piController.limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: " + String(piController.limiter.homotopyType, "d"));
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,105};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,189,"Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= piController.limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: ");
  modelica_string tmp3;
  modelica_metatype tmpMeta4;
  static int tmp5 = 0;
  if(!tmp5)
  {
    tmp0 = GreaterEq((data->simulationInfo->integerParameter[4] /* piController.limiter.homotopyType PARAM */),1);
    tmp1 = LessEq((data->simulationInfo->integerParameter[4] /* piController.limiter.homotopyType PARAM */),4);
    if(!(tmp0 && tmp1))
    {
      tmp3 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[4] /* piController.limiter.homotopyType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta4 = stringAppend(MMC_REFSTRINGLIT(tmp2),tmp3);
      {
        const char* assert_cond = "(piController.limiter.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and piController.limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",12,9,13,69,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",12,9,13,69,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
        }
      }
      tmp5 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 106
type: ALGORITHM

  assert(piController.k >= 0.0, "Variable violating min constraint: 0.0 <= piController.k, has value: " + String(piController.k, "g"));
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,106};
  modelica_boolean tmp6;
  static const MMC_DEFSTRINGLIT(tmp7,69,"Variable violating min constraint: 0.0 <= piController.k, has value: ");
  modelica_string tmp8;
  modelica_metatype tmpMeta9;
  static int tmp10 = 0;
  if(!tmp10)
  {
    tmp6 = GreaterEq((data->simulationInfo->realParameter[43] /* piController.k PARAM */),0.0);
    if(!tmp6)
    {
      tmp8 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[43] /* piController.k PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta9 = stringAppend(MMC_REFSTRINGLIT(tmp7),tmp8);
      {
        const char* assert_cond = "(piController.k >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",768,5,768,63,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta9));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",768,5,768,63,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta9));
        }
      }
      tmp10 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 107
type: ALGORITHM

  assert(piController.Ni >= 1e-13, "Variable violating min constraint: 1e-13 <= piController.Ni, has value: " + String(piController.Ni, "g"));
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,107};
  modelica_boolean tmp11;
  static const MMC_DEFSTRINGLIT(tmp12,72,"Variable violating min constraint: 1e-13 <= piController.Ni, has value: ");
  modelica_string tmp13;
  modelica_metatype tmpMeta14;
  static int tmp15 = 0;
  if(!tmp15)
  {
    tmp11 = GreaterEq((data->simulationInfo->realParameter[21] /* piController.Ni PARAM */),1e-13);
    if(!tmp11)
    {
      tmp13 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[21] /* piController.Ni PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta14 = stringAppend(MMC_REFSTRINGLIT(tmp12),tmp13);
      {
        const char* assert_cond = "(piController.Ni >= 1e-13)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",784,5,787,94,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",784,5,787,94,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
        }
      }
      tmp15 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 108
type: ALGORITHM

  assert(piController.I.initType >= Modelica.Blocks.Types.Init.NoInit and piController.I.initType <= Modelica.Blocks.Types.Init.InitialOutput, "Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= piController.I.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: " + String(piController.I.initType, "d"));
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,108};
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  static const MMC_DEFSTRINGLIT(tmp18,156,"Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= piController.I.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: ");
  modelica_string tmp19;
  modelica_metatype tmpMeta20;
  static int tmp21 = 0;
  if(!tmp21)
  {
    tmp16 = GreaterEq((data->simulationInfo->integerParameter[0] /* piController.I.initType PARAM */),1);
    tmp17 = LessEq((data->simulationInfo->integerParameter[0] /* piController.I.initType PARAM */),4);
    if(!(tmp16 && tmp17))
    {
      tmp19 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[0] /* piController.I.initType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta20 = stringAppend(MMC_REFSTRINGLIT(tmp18),tmp19);
      {
        const char* assert_cond = "(piController.I.initType >= Modelica.Blocks.Types.Init.NoInit and piController.I.initType <= Modelica.Blocks.Types.Init.InitialOutput)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",19,5,21,40,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta20));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",19,5,21,40,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta20));
        }
      }
      tmp21 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 109
type: ALGORITHM

  assert(piController.Ti >= 1e-60, "Variable violating min constraint: 1e-60 <= piController.Ti, has value: " + String(piController.Ti, "g"));
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,109};
  modelica_boolean tmp22;
  static const MMC_DEFSTRINGLIT(tmp23,72,"Variable violating min constraint: 1e-60 <= piController.Ti, has value: ");
  modelica_string tmp24;
  modelica_metatype tmpMeta25;
  static int tmp26 = 0;
  if(!tmp26)
  {
    tmp22 = GreaterEq((data->simulationInfo->realParameter[24] /* piController.Ti PARAM */),1e-60);
    if(!tmp22)
    {
      tmp24 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[24] /* piController.Ti PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta25 = stringAppend(MMC_REFSTRINGLIT(tmp23),tmp24);
      {
        const char* assert_cond = "(piController.Ti >= 1e-60)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",769,5,772,76,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta25));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",769,5,772,76,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta25));
        }
      }
      tmp26 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 110
type: ALGORITHM

  assert(piController.wp >= 0.0, "Variable violating min constraint: 0.0 <= piController.wp, has value: " + String(piController.wp, "g"));
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_110(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,110};
  modelica_boolean tmp27;
  static const MMC_DEFSTRINGLIT(tmp28,70,"Variable violating min constraint: 0.0 <= piController.wp, has value: ");
  modelica_string tmp29;
  modelica_metatype tmpMeta30;
  static int tmp31 = 0;
  if(!tmp31)
  {
    tmp27 = GreaterEq((data->simulationInfo->realParameter[49] /* piController.wp PARAM */),0.0);
    if(!tmp27)
    {
      tmp29 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[49] /* piController.wp PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta30 = stringAppend(MMC_REFSTRINGLIT(tmp28),tmp29);
      {
        const char* assert_cond = "(piController.wp >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",779,5,780,55,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta30));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",779,5,780,55,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta30));
        }
      }
      tmp31 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 111
type: ALGORITHM

  assert(piController.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and piController.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, "Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= piController.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: " + String(piController.homotopyType, "d"));
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,111};
  modelica_boolean tmp32;
  modelica_boolean tmp33;
  static const MMC_DEFSTRINGLIT(tmp34,181,"Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= piController.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: ");
  modelica_string tmp35;
  modelica_metatype tmpMeta36;
  static int tmp37 = 0;
  if(!tmp37)
  {
    tmp32 = GreaterEq((data->simulationInfo->integerParameter[2] /* piController.homotopyType PARAM */),1);
    tmp33 = LessEq((data->simulationInfo->integerParameter[2] /* piController.homotopyType PARAM */),4);
    if(!(tmp32 && tmp33))
    {
      tmp35 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[2] /* piController.homotopyType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta36 = stringAppend(MMC_REFSTRINGLIT(tmp34),tmp35);
      {
        const char* assert_cond = "(piController.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and piController.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",812,5,814,65,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta36));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",812,5,814,65,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta36));
        }
      }
      tmp37 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 112
type: ALGORITHM

  assert(piController.initType >= Modelica.Blocks.Types.Init.NoInit and piController.initType <= Modelica.Blocks.Types.Init.InitialOutput, "Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= piController.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: " + String(piController.initType, "d"));
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_112(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,112};
  modelica_boolean tmp38;
  modelica_boolean tmp39;
  static const MMC_DEFSTRINGLIT(tmp40,154,"Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= piController.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: ");
  modelica_string tmp41;
  modelica_metatype tmpMeta42;
  static int tmp43 = 0;
  if(!tmp43)
  {
    tmp38 = GreaterEq((data->simulationInfo->integerParameter[3] /* piController.initType PARAM */),1);
    tmp39 = LessEq((data->simulationInfo->integerParameter[3] /* piController.initType PARAM */),4);
    if(!(tmp38 && tmp39))
    {
      tmp41 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[3] /* piController.initType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta42 = stringAppend(MMC_REFSTRINGLIT(tmp40),tmp41);
      {
        const char* assert_cond = "(piController.initType >= Modelica.Blocks.Types.Init.NoInit and piController.initType <= Modelica.Blocks.Types.Init.InitialOutput)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",796,5,798,64,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta42));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",796,5,798,64,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta42));
        }
      }
      tmp43 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 113
type: ALGORITHM

  assert(piController.Nd >= 1e-13, "Variable violating min constraint: 1e-13 <= piController.Nd, has value: " + String(piController.Nd, "g"));
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,113};
  modelica_boolean tmp44;
  static const MMC_DEFSTRINGLIT(tmp45,72,"Variable violating min constraint: 1e-13 <= piController.Nd, has value: ");
  modelica_string tmp46;
  modelica_metatype tmpMeta47;
  static int tmp48 = 0;
  if(!tmp48)
  {
    tmp44 = GreaterEq((data->simulationInfo->realParameter[20] /* piController.Nd PARAM */),1e-13);
    if(!tmp44)
    {
      tmp46 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[20] /* piController.Nd PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta47 = stringAppend(MMC_REFSTRINGLIT(tmp45),tmp46);
      {
        const char* assert_cond = "(piController.Nd >= 1e-13)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",788,5,791,96,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta47));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",788,5,791,96,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta47));
        }
      }
      tmp48 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 114
type: ALGORITHM

  assert(piController.wd >= 0.0, "Variable violating min constraint: 0.0 <= piController.wd, has value: " + String(piController.wd, "g"));
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,114};
  modelica_boolean tmp49;
  static const MMC_DEFSTRINGLIT(tmp50,70,"Variable violating min constraint: 0.0 <= piController.wd, has value: ");
  modelica_string tmp51;
  modelica_metatype tmpMeta52;
  static int tmp53 = 0;
  if(!tmp53)
  {
    tmp49 = GreaterEq((data->simulationInfo->realParameter[48] /* piController.wd PARAM */),0.0);
    if(!tmp49)
    {
      tmp51 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[48] /* piController.wd PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta52 = stringAppend(MMC_REFSTRINGLIT(tmp50),tmp51);
      {
        const char* assert_cond = "(piController.wd >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",781,5,783,96,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta52));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",781,5,783,96,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta52));
        }
      }
      tmp53 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 115
type: ALGORITHM

  assert(piController.Td >= 0.0, "Variable violating min constraint: 0.0 <= piController.Td, has value: " + String(piController.Td, "g"));
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
  modelica_boolean tmp54;
  static const MMC_DEFSTRINGLIT(tmp55,70,"Variable violating min constraint: 0.0 <= piController.Td, has value: ");
  modelica_string tmp56;
  modelica_metatype tmpMeta57;
  static int tmp58 = 0;
  if(!tmp58)
  {
    tmp54 = GreaterEq((data->simulationInfo->realParameter[23] /* piController.Td PARAM */),0.0);
    if(!tmp54)
    {
      tmp56 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[23] /* piController.Td PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta57 = stringAppend(MMC_REFSTRINGLIT(tmp55),tmp56);
      {
        const char* assert_cond = "(piController.Td >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",773,5,776,76,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta57));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",773,5,776,76,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta57));
        }
      }
      tmp58 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 116
type: ALGORITHM

  assert(piController.controllerType >= Modelica.Blocks.Types.SimpleController.P and piController.controllerType <= Modelica.Blocks.Types.SimpleController.PID, "Variable violating min/max constraint: Modelica.Blocks.Types.SimpleController.P <= piController.controllerType <= Modelica.Blocks.Types.SimpleController.PID, has value: " + String(piController.controllerType, "d"));
*/
OMC_DISABLE_OPT
static void TankTempPIControl_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,116};
  modelica_boolean tmp59;
  modelica_boolean tmp60;
  static const MMC_DEFSTRINGLIT(tmp61,169,"Variable violating min/max constraint: Modelica.Blocks.Types.SimpleController.P <= piController.controllerType <= Modelica.Blocks.Types.SimpleController.PID, has value: ");
  modelica_string tmp62;
  modelica_metatype tmpMeta63;
  static int tmp64 = 0;
  if(!tmp64)
  {
    tmp59 = GreaterEq((data->simulationInfo->integerParameter[1] /* piController.controllerType PARAM */),1);
    tmp60 = LessEq((data->simulationInfo->integerParameter[1] /* piController.controllerType PARAM */),4);
    if(!(tmp59 && tmp60))
    {
      tmp62 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[1] /* piController.controllerType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta63 = stringAppend(MMC_REFSTRINGLIT(tmp61),tmp62);
      {
        const char* assert_cond = "(piController.controllerType >= Modelica.Blocks.Types.SimpleController.P and piController.controllerType <= Modelica.Blocks.Types.SimpleController.PID)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",766,5,767,76,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta63));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",766,5,767,76,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta63));
        }
      }
      tmp64 = 1;
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void TankTempPIControl_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  TankTempPIControl_eqFunction_63(data, threadData);
  TankTempPIControl_eqFunction_64(data, threadData);
  TankTempPIControl_eqFunction_65(data, threadData);
  TankTempPIControl_eqFunction_66(data, threadData);
  TankTempPIControl_eqFunction_67(data, threadData);
  TankTempPIControl_eqFunction_68(data, threadData);
  TankTempPIControl_eqFunction_69(data, threadData);
  TankTempPIControl_eqFunction_70(data, threadData);
  TankTempPIControl_eqFunction_71(data, threadData);
  TankTempPIControl_eqFunction_72(data, threadData);
  TankTempPIControl_eqFunction_73(data, threadData);
  TankTempPIControl_eqFunction_74(data, threadData);
  TankTempPIControl_eqFunction_79(data, threadData);
  TankTempPIControl_eqFunction_80(data, threadData);
  TankTempPIControl_eqFunction_81(data, threadData);
  TankTempPIControl_eqFunction_82(data, threadData);
  TankTempPIControl_eqFunction_83(data, threadData);
  TankTempPIControl_eqFunction_84(data, threadData);
  TankTempPIControl_eqFunction_85(data, threadData);
  TankTempPIControl_eqFunction_89(data, threadData);
  TankTempPIControl_eqFunction_90(data, threadData);
  TankTempPIControl_eqFunction_91(data, threadData);
  TankTempPIControl_eqFunction_100(data, threadData);
  TankTempPIControl_eqFunction_101(data, threadData);
  TankTempPIControl_eqFunction_102(data, threadData);
  TankTempPIControl_eqFunction_2(data, threadData);
  TankTempPIControl_eqFunction_1(data, threadData);
  TankTempPIControl_eqFunction_105(data, threadData);
  TankTempPIControl_eqFunction_106(data, threadData);
  TankTempPIControl_eqFunction_107(data, threadData);
  TankTempPIControl_eqFunction_108(data, threadData);
  TankTempPIControl_eqFunction_109(data, threadData);
  TankTempPIControl_eqFunction_110(data, threadData);
  TankTempPIControl_eqFunction_111(data, threadData);
  TankTempPIControl_eqFunction_112(data, threadData);
  TankTempPIControl_eqFunction_113(data, threadData);
  TankTempPIControl_eqFunction_114(data, threadData);
  TankTempPIControl_eqFunction_115(data, threadData);
  TankTempPIControl_eqFunction_116(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int TankTempPIControl_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->realParameter[52]/* piController.yMax PARAM */) = 20.0;
  data->modelData->realParameterData[52].time_unvarying = 1;
  (data->simulationInfo->realParameter[53]/* piController.yMin PARAM */) = 0.0;
  data->modelData->realParameterData[53].time_unvarying = 1;
  (data->simulationInfo->realParameter[54]/* piController.y_start PARAM */) = 4.0;
  data->modelData->realParameterData[54].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[0]/* piController.I.use_reset PARAM */) = 0 /* false */;
  data->modelData->booleanParameterData[0].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[1]/* piController.I.use_set PARAM */) = 0 /* false */;
  data->modelData->booleanParameterData[1].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[2]/* piController.limiter.strict PARAM */) = 0 /* false */;
  data->modelData->booleanParameterData[2].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[3]/* piController.strict PARAM */) = 0 /* false */;
  data->modelData->booleanParameterData[3].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[4]/* piController.withFeedForward PARAM */) = 0 /* false */;
  data->modelData->booleanParameterData[4].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[5]/* piController.with_D PARAM */) = 0 /* false */;
  data->modelData->booleanParameterData[5].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[6]/* piController.with_I PARAM */) = 1 /* true */;
  data->modelData->booleanParameterData[6].time_unvarying = 1;
  (data->simulationInfo->integerParameter[0]/* piController.I.initType PARAM */) = 3;
  data->modelData->integerParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[1]/* piController.controllerType PARAM */) = 2;
  data->modelData->integerParameterData[1].time_unvarying = 1;
  (data->simulationInfo->integerParameter[2]/* piController.homotopyType PARAM */) = 2;
  data->modelData->integerParameterData[2].time_unvarying = 1;
  (data->simulationInfo->integerParameter[3]/* piController.initType PARAM */) = 3;
  data->modelData->integerParameterData[3].time_unvarying = 1;
  (data->simulationInfo->integerParameter[4]/* piController.limiter.homotopyType PARAM */) = 2;
  data->modelData->integerParameterData[4].time_unvarying = 1;
  TankTempPIControl_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

