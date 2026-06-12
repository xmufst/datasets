/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "TankTempPIControl_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation TankTempPIControl_performSimulation
#define prefixedName_updateContinuousSystem TankTempPIControl_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation TankTempPIControl_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int TankTempPIControl_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankTempPIControl_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankTempPIControl_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankTempPIControl_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankTempPIControl_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int TankTempPIControl_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankTempPIControl_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankTempPIControl_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankTempPIControl_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankTempPIControl_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 42
type: SIMPLE_ASSIGN
T_ambient = ambTemp.offset + (if time < ambTemp.startTime then 0.0 else ambTemp.height)
*/
void TankTempPIControl_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[9] /* ambTemp.startTime PARAM */));
  relationhysteresis(data, &tmp0, data->localData[0]->timeValue, (data->simulationInfo->realParameter[9] /* ambTemp.startTime PARAM */), tmp1, tmp2, 0, Less, LessZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* T_ambient variable */) = (data->simulationInfo->realParameter[8] /* ambTemp.offset PARAM */) + (tmp0?0.0:(data->simulationInfo->realParameter[7] /* ambTemp.height PARAM */));
  TRACE_POP
}
/*
equation index: 43
type: SIMPLE_ASSIGN
piController.addP.y = piController.addP.k1 * refTemp.k + piController.addP.k2 * T_water
*/
void TankTempPIControl_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* piController.addP.y variable */) = ((data->simulationInfo->realParameter[32] /* piController.addP.k1 PARAM */)) * ((data->simulationInfo->realParameter[57] /* refTemp.k PARAM */)) + ((data->simulationInfo->realParameter[33] /* piController.addP.k2 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_water STATE(1) */));
  TRACE_POP
}
/*
equation index: 44
type: SIMPLE_ASSIGN
piController.P.y = piController.P.k * piController.addP.y
*/
void TankTempPIControl_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* piController.P.y variable */) = ((data->simulationInfo->realParameter[22] /* piController.P.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* piController.addP.y variable */));
  TRACE_POP
}
/*
equation index: 45
type: SIMPLE_ASSIGN
piController.addPID.y = piController.addPID.k1 * piController.P.y + piController.addPID.k2 * piController.Dzero.k + piController.addPID.k3 * piController.I.y
*/
void TankTempPIControl_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* piController.addPID.y variable */) = ((data->simulationInfo->realParameter[35] /* piController.addPID.k1 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* piController.P.y variable */)) + ((data->simulationInfo->realParameter[36] /* piController.addPID.k2 PARAM */)) * ((data->simulationInfo->realParameter[14] /* piController.Dzero.k PARAM */)) + ((data->simulationInfo->realParameter[37] /* piController.addPID.k3 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piController.I.y STATE(1) */));
  TRACE_POP
}
/*
equation index: 46
type: SIMPLE_ASSIGN
piController.gainPID.y = piController.gainPID.k * piController.addPID.y
*/
void TankTempPIControl_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* piController.gainPID.y variable */) = ((data->simulationInfo->realParameter[41] /* piController.gainPID.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* piController.addPID.y variable */));
  TRACE_POP
}
/*
equation index: 47
type: SIMPLE_ASSIGN
piController.limiter.u = piController.addFF.k1 * piController.gainPID.y + piController.addFF.k2 * piController.FFzero.k
*/
void TankTempPIControl_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* piController.limiter.u variable */) = ((data->simulationInfo->realParameter[25] /* piController.addFF.k1 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* piController.gainPID.y variable */)) + ((data->simulationInfo->realParameter[26] /* piController.addFF.k2 PARAM */)) * ((data->simulationInfo->realParameter[16] /* piController.FFzero.k PARAM */));
  TRACE_POP
}
/*
equation index: 48
type: SIMPLE_ASSIGN
u_pi = smooth(0, if piController.limiter.u > piController.limiter.uMax then piController.limiter.uMax else if piController.limiter.u < piController.limiter.uMin then piController.limiter.uMin else piController.limiter.u)
*/
void TankTempPIControl_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
  modelica_boolean tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_real tmp6;
  tmp3 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* piController.limiter.u variable */),(data->simulationInfo->realParameter[45] /* piController.limiter.uMax PARAM */));
  tmp5 = (modelica_boolean)tmp3;
  if(tmp5)
  {
    tmp6 = (data->simulationInfo->realParameter[45] /* piController.limiter.uMax PARAM */);
  }
  else
  {
    tmp4 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* piController.limiter.u variable */),(data->simulationInfo->realParameter[46] /* piController.limiter.uMin PARAM */));
    tmp6 = (tmp4?(data->simulationInfo->realParameter[46] /* piController.limiter.uMin PARAM */):(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* piController.limiter.u variable */));
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* u_pi variable */) = tmp6;
  TRACE_POP
}
/*
equation index: 49
type: SIMPLE_ASSIGN
piController.addSat.y = piController.addSat.k1 * u_pi + piController.addSat.k2 * piController.limiter.u
*/
void TankTempPIControl_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* piController.addSat.y variable */) = ((data->simulationInfo->realParameter[39] /* piController.addSat.k1 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* u_pi variable */)) + ((data->simulationInfo->realParameter[40] /* piController.addSat.k2 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* piController.limiter.u variable */));
  TRACE_POP
}
/*
equation index: 50
type: SIMPLE_ASSIGN
piController.gainTrack.y = piController.gainTrack.k * piController.addSat.y
*/
void TankTempPIControl_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* piController.gainTrack.y variable */) = ((data->simulationInfo->realParameter[42] /* piController.gainTrack.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* piController.addSat.y variable */));
  TRACE_POP
}
/*
equation index: 51
type: SIMPLE_ASSIGN
piController.addI.y = piController.addI.k1 * refTemp.k + piController.addI.k2 * T_water + piController.addI.k3 * piController.gainTrack.y
*/
void TankTempPIControl_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* piController.addI.y variable */) = ((data->simulationInfo->realParameter[28] /* piController.addI.k1 PARAM */)) * ((data->simulationInfo->realParameter[57] /* refTemp.k PARAM */)) + ((data->simulationInfo->realParameter[29] /* piController.addI.k2 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_water STATE(1) */)) + ((data->simulationInfo->realParameter[30] /* piController.addI.k3 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* piController.gainTrack.y variable */));
  TRACE_POP
}
/*
equation index: 52
type: SIMPLE_ASSIGN
$DER.piController.I.y = piController.I.k * piController.addI.y
*/
void TankTempPIControl_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(piController.I.y) STATE_DER */) = ((data->simulationInfo->realParameter[18] /* piController.I.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* piController.addI.y variable */));
  TRACE_POP
}
/*
equation index: 53
type: SIMPLE_ASSIGN
P_heat = heaterGain.k * u_pi
*/
void TankTempPIControl_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* P_heat variable */) = ((data->simulationInfo->realParameter[12] /* heaterGain.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* u_pi variable */));
  TRACE_POP
}
/*
equation index: 54
type: SIMPLE_ASSIGN
T_error = refTemp.k - T_water
*/
void TankTempPIControl_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,54};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* T_error variable */) = (data->simulationInfo->realParameter[57] /* refTemp.k PARAM */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_water STATE(1) */);
  TRACE_POP
}
/*
equation index: 55
type: SIMPLE_ASSIGN
P_loss = h_env * (T_water - T_ambient)
*/
void TankTempPIControl_eqFunction_55(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,55};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* P_loss variable */) = ((data->simulationInfo->realParameter[11] /* h_env PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_water STATE(1) */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* T_ambient variable */));
  TRACE_POP
}
/*
equation index: 56
type: SIMPLE_ASSIGN
$DER.T_water = (P_heat - P_loss) / (cp_water * water_mass)
*/
void TankTempPIControl_eqFunction_56(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,56};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(T_water) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* P_heat variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* P_loss variable */),((data->simulationInfo->realParameter[10] /* cp_water PARAM */)) * ((data->simulationInfo->realParameter[61] /* water_mass PARAM */)),"cp_water * water_mass",equationIndexes);
  TRACE_POP
}
/*
equation index: 57
type: SIMPLE_ASSIGN
T_water_C = -273.15 + T_water
*/
void TankTempPIControl_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* T_water_C variable */) = -273.15 + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_water STATE(1) */);
  TRACE_POP
}
/*
equation index: 58
type: ALGORITHM

  assert(piController.limiter.uMax >= piController.limiter.uMin, "Limiter: Limits must be consistent. However, uMax (=" + String(piController.limiter.uMax, 6, 0, true) + ") < uMin (=" + String(piController.limiter.uMin, 6, 0, true) + ")");
*/
void TankTempPIControl_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
  modelica_boolean tmp7;
  static const MMC_DEFSTRINGLIT(tmp8,52,"Limiter: Limits must be consistent. However, uMax (=");
  modelica_string tmp9;
  modelica_metatype tmpMeta10;
  static const MMC_DEFSTRINGLIT(tmp11,11,") < uMin (=");
  modelica_metatype tmpMeta12;
  modelica_string tmp13;
  modelica_metatype tmpMeta14;
  modelica_metatype tmpMeta15;
  static int tmp16 = 0;
  {
    tmp7 = GreaterEq((data->simulationInfo->realParameter[45] /* piController.limiter.uMax PARAM */),(data->simulationInfo->realParameter[46] /* piController.limiter.uMin PARAM */));
    if(!tmp7)
    {
      tmp9 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[45] /* piController.limiter.uMax PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta10 = stringAppend(MMC_REFSTRINGLIT(tmp8),tmp9);
      tmpMeta12 = stringAppend(tmpMeta10,MMC_REFSTRINGLIT(tmp11));
      tmp13 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[46] /* piController.limiter.uMin PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta14 = stringAppend(tmpMeta12,tmp13);
      tmpMeta15 = stringAppend(tmpMeta14,(modelica_string) mmc_strings_len1[41]);
      {
        const char* assert_cond = "(piController.limiter.uMax >= piController.limiter.uMin)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta15));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta15));
        }
      }
    }
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int TankTempPIControl_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  TankTempPIControl_functionLocalKnownVars(data, threadData);
  TankTempPIControl_eqFunction_42(data, threadData);

  TankTempPIControl_eqFunction_43(data, threadData);

  TankTempPIControl_eqFunction_44(data, threadData);

  TankTempPIControl_eqFunction_45(data, threadData);

  TankTempPIControl_eqFunction_46(data, threadData);

  TankTempPIControl_eqFunction_47(data, threadData);

  TankTempPIControl_eqFunction_48(data, threadData);

  TankTempPIControl_eqFunction_49(data, threadData);

  TankTempPIControl_eqFunction_50(data, threadData);

  TankTempPIControl_eqFunction_51(data, threadData);

  TankTempPIControl_eqFunction_52(data, threadData);

  TankTempPIControl_eqFunction_53(data, threadData);

  TankTempPIControl_eqFunction_54(data, threadData);

  TankTempPIControl_eqFunction_55(data, threadData);

  TankTempPIControl_eqFunction_56(data, threadData);

  TankTempPIControl_eqFunction_57(data, threadData);

  TankTempPIControl_eqFunction_58(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int TankTempPIControl_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void TankTempPIControl_eqFunction_42(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_43(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_44(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_45(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_46(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_47(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_48(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_49(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_50(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_51(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_52(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_53(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_55(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_56(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[14])(DATA*, threadData_t*) = {
    TankTempPIControl_eqFunction_42,
    TankTempPIControl_eqFunction_43,
    TankTempPIControl_eqFunction_44,
    TankTempPIControl_eqFunction_45,
    TankTempPIControl_eqFunction_46,
    TankTempPIControl_eqFunction_47,
    TankTempPIControl_eqFunction_48,
    TankTempPIControl_eqFunction_49,
    TankTempPIControl_eqFunction_50,
    TankTempPIControl_eqFunction_51,
    TankTempPIControl_eqFunction_52,
    TankTempPIControl_eqFunction_53,
    TankTempPIControl_eqFunction_55,
    TankTempPIControl_eqFunction_56
  };
  
  static const int eqIndices[14] = {
    42,
    43,
    44,
    45,
    46,
    47,
    48,
    49,
    50,
    51,
    52,
    53,
    55,
    56
  };
  
  for (id = 0; id < 14; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int TankTempPIControl_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  TankTempPIControl_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void TankTempPIControl_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
{
  TRACE_PUSH

  size_t i_real = 0;
  size_t i_integer = 0;
  size_t i_boolean = 0;
  size_t i_string = 0;

  realIndex[0] = 0;
  integerIndex[0] = 0;
  booleanIndex[0] = 0;
  stringIndex[0] = 0;

  /* stateVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_water STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* piController.I.y STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(T_water) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(piController.I.y) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* P_heat variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* P_loss variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_ambient variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_error variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_water_C variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* piController.I.local_set variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* piController.P.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* piController.addI.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* piController.addP.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* piController.addPID.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* piController.addSat.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* piController.gainPID.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* piController.gainTrack.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* piController.limiter.u variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* u_pi variable */
  
  /* discreteAlgVars */
  
  /* realOptimizeConstraintsVars */
  
  /* realOptimizeFinalConstraintsVars */
  
  
  /* intAlgVars */
  
  /* boolAlgVars */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* piController.I.local_reset DISCRETE */
  
  /* stringAlgVars */
  
  TRACE_POP
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "TankTempPIControl_12jac.h"
#include "TankTempPIControl_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks TankTempPIControl_callback = {
   (int (*)(DATA *, threadData_t *, void *)) TankTempPIControl_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) TankTempPIControl_performQSSSimulation,    /* performQSSSimulation */
   TankTempPIControl_updateContinuousSystem,    /* updateContinuousSystem */
   TankTempPIControl_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   TankTempPIControl_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   TankTempPIControl_initializeDAEmodeData,
   TankTempPIControl_computeVarIndices,
   TankTempPIControl_functionODE,
   TankTempPIControl_functionAlgebraics,
   TankTempPIControl_functionDAE,
   TankTempPIControl_functionLocalKnownVars,
   TankTempPIControl_input_function,
   TankTempPIControl_input_function_init,
   TankTempPIControl_input_function_updateStartValues,
   TankTempPIControl_data_function,
   TankTempPIControl_output_function,
   TankTempPIControl_setc_function,
   TankTempPIControl_setb_function,
   TankTempPIControl_function_storeDelayed,
   TankTempPIControl_function_storeSpatialDistribution,
   TankTempPIControl_function_initSpatialDistribution,
   TankTempPIControl_updateBoundVariableAttributes,
   TankTempPIControl_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   TankTempPIControl_functionInitialEquations_lambda0,
   TankTempPIControl_functionRemovedInitialEquations,
   TankTempPIControl_updateBoundParameters,
   TankTempPIControl_checkForAsserts,
   TankTempPIControl_function_ZeroCrossingsEquations,
   TankTempPIControl_function_ZeroCrossings,
   TankTempPIControl_function_updateRelations,
   TankTempPIControl_zeroCrossingDescription,
   TankTempPIControl_relationDescription,
   TankTempPIControl_function_initSample,
   TankTempPIControl_INDEX_JAC_A,
   TankTempPIControl_INDEX_JAC_B,
   TankTempPIControl_INDEX_JAC_C,
   TankTempPIControl_INDEX_JAC_D,
   TankTempPIControl_INDEX_JAC_F,
   TankTempPIControl_INDEX_JAC_H,
   TankTempPIControl_initialAnalyticJacobianA,
   TankTempPIControl_initialAnalyticJacobianB,
   TankTempPIControl_initialAnalyticJacobianC,
   TankTempPIControl_initialAnalyticJacobianD,
   TankTempPIControl_initialAnalyticJacobianF,
   TankTempPIControl_initialAnalyticJacobianH,
   TankTempPIControl_functionJacA_column,
   TankTempPIControl_functionJacB_column,
   TankTempPIControl_functionJacC_column,
   TankTempPIControl_functionJacD_column,
   TankTempPIControl_functionJacF_column,
   TankTempPIControl_functionJacH_column,
   TankTempPIControl_linear_model_frame,
   TankTempPIControl_linear_model_datarecovery_frame,
   TankTempPIControl_mayer,
   TankTempPIControl_lagrange,
   TankTempPIControl_pickUpBoundsForInputsInOptimization,
   TankTempPIControl_setInputData,
   TankTempPIControl_getTimeGrid,
   TankTempPIControl_symbolicInlineSystem,
   TankTempPIControl_function_initSynchronous,
   TankTempPIControl_function_updateSynchronous,
   TankTempPIControl_function_equationsSynchronous,
   TankTempPIControl_inputNames,
   TankTempPIControl_dataReconciliationInputNames,
   TankTempPIControl_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Complex"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Complex 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,7,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,75,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "Modelica"
#define _OMC_LIT_RESOURCE_1_dir_data "C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,8,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,76,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_2_dir_data "C:/Users/FST/AppData/Roaming/.openmodelica/libraries/ModelicaServices 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,16,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,84,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "TankTempPIControl"
#define _OMC_LIT_RESOURCE_3_dir_data "C:/Users/FST/Desktop/实验组3/cases/20260427_170310_TankTempPIControl/build/src"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,17,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,81,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void TankTempPIControl_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &TankTempPIControl_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "TankTempPIControl";
  data->modelData->modelFilePrefix = "TankTempPIControl";
  data->modelData->modelFileName = "TankTempPIControl.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/实验组3/cases/20260427_170310_TankTempPIControl/build/src";
  data->modelData->modelGUID = "{7f0f4894-d919-4e6d-8f5f-76c1fce6a920}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "TankTempPIControl_init.c"
    ;
  static const char contents_info[] =
    #include "TankTempPIControl_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "TankTempPIControl_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "TankTempPIControl_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "TankTempPIControl_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 19;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 1;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 62;
  data->modelData->nParametersInteger = 5;
  data->modelData->nParametersBoolean = 7;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 22;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 1;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 1;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 117;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 6;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  data->modelData->nDelayExpressions = 0;
  data->modelData->nBaseClocks = 0;
  data->modelData->nSpatialDistributions = 0;
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
  data->modelData->nSetcVars = 0;
  data->modelData->ndataReconVars = 0;
  data->modelData->nSetbVars = 0;
  data->modelData->nRelatedBoundaryConditions = 0;
  data->modelData->linearizationDumpLanguage = OMC_LINEARIZE_DUMP_LANGUAGE_MODELICA;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}


#if defined(__MINGW32__) || defined(_MSC_VER)

#if !defined(_UNICODE)
#define _UNICODE
#endif
#if !defined(UNICODE)
#define UNICODE
#endif

#include <windows.h>
char** omc_fixWindowsArgv(int argc, wchar_t **wargv)
{
  char** newargv;
  /* Support for non-ASCII characters
  * Read the unicode command line arguments and translate it to char*
  */
  newargv = (char**)malloc(argc*sizeof(char*));
  for (int i = 0; i < argc; i++) {
    newargv[i] = omc_wchar_to_multibyte_str(wargv[i]);
  }
  return newargv;
}

#define OMC_MAIN wmain
#define OMC_CHAR wchar_t
#define OMC_EXPORT __declspec(dllexport) extern

#else
#define omc_fixWindowsArgv(N, A) (A)
#define OMC_MAIN main
#define OMC_CHAR char
#define OMC_EXPORT extern
#endif

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
#if defined(OMC_DLL_MAIN_DEFINE)
OMC_EXPORT int omcDllMain(int argc, OMC_CHAR **argv)
#else
int OMC_MAIN(int argc, OMC_CHAR** argv)
#endif
{
  char** newargv = omc_fixWindowsArgv(argc, argv);
  /*
    Set the error functions to be used for simulation.
    The default value for them is 'functions' version. Change it here to 'simulation' versions
  */
  omc_assert = omc_assert_simulation;
  omc_assert_withEquationIndexes = omc_assert_simulation_withEquationIndexes;

  omc_assert_warning_withEquationIndexes = omc_assert_warning_simulation_withEquationIndexes;
  omc_assert_warning = omc_assert_warning_simulation;
  omc_terminate = omc_terminate_simulation;
  omc_throw = omc_throw_simulation;

  int res;
  DATA data;
  MODEL_DATA modelData;
  SIMULATION_INFO simInfo;
  data.modelData = &modelData;
  data.simulationInfo = &simInfo;
  measure_time_flag = 0;
  compiledInDAEMode = 0;
  compiledWithSymSolver = 0;
  MMC_INIT(0);
  omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    TankTempPIControl_setupDataStruc(&data, threadData);
    res = _main_initRuntimeAndSimulation(argc, newargv, &data, threadData);
    if(res == 0) {
      res = _main_SimulationRuntime(argc, newargv, &data, threadData);
    }
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
  return res;
}

#ifdef __cplusplus
}
#endif


