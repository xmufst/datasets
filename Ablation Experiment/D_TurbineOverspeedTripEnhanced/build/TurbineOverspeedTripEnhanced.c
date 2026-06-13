/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "TurbineOverspeedTripEnhanced_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation TurbineOverspeedTripEnhanced_performSimulation
#define prefixedName_updateContinuousSystem TurbineOverspeedTripEnhanced_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation TurbineOverspeedTripEnhanced_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int TurbineOverspeedTripEnhanced_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TurbineOverspeedTripEnhanced_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TurbineOverspeedTripEnhanced_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TurbineOverspeedTripEnhanced_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TurbineOverspeedTripEnhanced_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int TurbineOverspeedTripEnhanced_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TurbineOverspeedTripEnhanced_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TurbineOverspeedTripEnhanced_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TurbineOverspeedTripEnhanced_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TurbineOverspeedTripEnhanced_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 16
type: SIMPLE_ASSIGN
$whenCondition1 = trip_timer >= trip_delay and not pre(trip_latched)
*/
void TurbineOverspeedTripEnhanced_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[10] /* trip_delay PARAM */));
  relationhysteresis(data, &tmp0, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* trip_timer STATE(1) */), (data->simulationInfo->realParameter[10] /* trip_delay PARAM */), tmp1, tmp2, 5, GreaterEq, GreaterEqZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (tmp0 && (!(data->simulationInfo->booleanVarsPre[3] /* trip_latched DISCRETE */)));
  TRACE_POP
}
/*
equation index: 17
type: WHEN

when {$whenCondition1} then
  trip_latched = true;
end when;
*/
void TurbineOverspeedTripEnhanced_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[3]] /* trip_latched DISCRETE */) = 1 /* true */;
  }
  TRACE_POP
}
/*
equation index: 18
type: SIMPLE_ASSIGN
overspeed = omega >= omega_trip
*/
void TurbineOverspeedTripEnhanced_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  tmp4 = 1.0;
  tmp5 = fabs((data->simulationInfo->realParameter[4] /* omega_trip PARAM */));
  relationhysteresis(data, &tmp3, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* omega STATE(1) */), (data->simulationInfo->realParameter[4] /* omega_trip PARAM */), tmp4, tmp5, 4, GreaterEq, GreaterEqZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* overspeed DISCRETE */) = tmp3;
  TRACE_POP
}
/*
equation index: 19
type: SIMPLE_ASSIGN
$DER.trip_timer = if overspeed and not trip_latched then 1.0 else 0.0
*/
void TurbineOverspeedTripEnhanced_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* der(trip_timer) STATE_DER */) = (((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* overspeed DISCRETE */) && (!(data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[3]] /* trip_latched DISCRETE */)))?1.0:0.0);
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
$whenCondition2 = not overspeed and not pre(trip_latched)
*/
void TurbineOverspeedTripEnhanced_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) = ((!(data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* overspeed DISCRETE */)) && (!(data->simulationInfo->booleanVarsPre[3] /* trip_latched DISCRETE */)));
  TRACE_POP
}
/*
equation index: 21
type: SIMPLE_ASSIGN
valve_target = if trip_latched then 0.0 else 1.0
*/
void TurbineOverspeedTripEnhanced_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* valve_target variable */) = ((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[3]] /* trip_latched DISCRETE */)?0.0:1.0);
  TRACE_POP
}
/*
equation index: 22
type: SIMPLE_ASSIGN
$DER.valve_opening = (valve_target - valve_opening) / T_valve
*/
void TurbineOverspeedTripEnhanced_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* der(valve_opening) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* valve_target variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* valve_opening STATE(1) */),(data->simulationInfo->realParameter[1] /* T_valve PARAM */),"T_valve",equationIndexes);
  TRACE_POP
}
/*
equation index: 23
type: SIMPLE_ASSIGN
tau_load = d_load * omega
*/
void TurbineOverspeedTripEnhanced_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* tau_load variable */) = ((data->simulationInfo->realParameter[2] /* d_load PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* omega STATE(1) */));
  TRACE_POP
}
/*
equation index: 24
type: SIMPLE_ASSIGN
tau_in = tau_steam_rated * valve_opening
*/
void TurbineOverspeedTripEnhanced_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* tau_in variable */) = ((data->simulationInfo->realParameter[9] /* tau_steam_rated PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* valve_opening STATE(1) */));
  TRACE_POP
}
/*
equation index: 25
type: SIMPLE_ASSIGN
tau_disturb = if time >= t_short_start and time < t_short_start + t_short_dur or time >= t_long_start and time < t_long_start + t_long_dur then 2000.0 else 0.0
*/
void TurbineOverspeedTripEnhanced_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_boolean tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_boolean tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  tmp7 = 1.0;
  tmp8 = fabs((data->simulationInfo->realParameter[8] /* t_short_start PARAM */));
  relationhysteresis(data, &tmp6, data->localData[0]->timeValue, (data->simulationInfo->realParameter[8] /* t_short_start PARAM */), tmp7, tmp8, 0, GreaterEq, GreaterEqZC);
  tmp10 = 1.0;
  tmp11 = fabs((data->simulationInfo->realParameter[8] /* t_short_start PARAM */)) + fabs((data->simulationInfo->realParameter[7] /* t_short_dur PARAM */));
  relationhysteresis(data, &tmp9, data->localData[0]->timeValue, (data->simulationInfo->realParameter[8] /* t_short_start PARAM */) + (data->simulationInfo->realParameter[7] /* t_short_dur PARAM */), tmp10, tmp11, 1, Less, LessZC);
  tmp13 = 1.0;
  tmp14 = fabs((data->simulationInfo->realParameter[6] /* t_long_start PARAM */));
  relationhysteresis(data, &tmp12, data->localData[0]->timeValue, (data->simulationInfo->realParameter[6] /* t_long_start PARAM */), tmp13, tmp14, 2, GreaterEq, GreaterEqZC);
  tmp16 = 1.0;
  tmp17 = fabs((data->simulationInfo->realParameter[6] /* t_long_start PARAM */)) + fabs((data->simulationInfo->realParameter[5] /* t_long_dur PARAM */));
  relationhysteresis(data, &tmp15, data->localData[0]->timeValue, (data->simulationInfo->realParameter[6] /* t_long_start PARAM */) + (data->simulationInfo->realParameter[5] /* t_long_dur PARAM */), tmp16, tmp17, 3, Less, LessZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* tau_disturb variable */) = (((tmp6 && tmp9) || (tmp12 && tmp15))?2000.0:0.0);
  TRACE_POP
}
/*
equation index: 26
type: SIMPLE_ASSIGN
$DER.omega = (tau_in + tau_disturb - tau_load) / J
*/
void TurbineOverspeedTripEnhanced_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(omega) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* tau_in variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* tau_disturb variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* tau_load variable */),(data->simulationInfo->realParameter[0] /* J PARAM */),"J",equationIndexes);
  TRACE_POP
}
/*
equation index: 27
type: WHEN

when {$whenCondition2} then
  reinit(trip_timer,  0.0);
end when;
*/
void TurbineOverspeedTripEnhanced_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* trip_timer STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit trip_timer = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* trip_timer STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int TurbineOverspeedTripEnhanced_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  TurbineOverspeedTripEnhanced_functionLocalKnownVars(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_16(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_17(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_18(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_19(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_20(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_21(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_22(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_23(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_24(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_25(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_26(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_27(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int TurbineOverspeedTripEnhanced_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void TurbineOverspeedTripEnhanced_eqFunction_16(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_18(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_19(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_21(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_22(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_23(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_24(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_25(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_26(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[9])(DATA*, threadData_t*) = {
    TurbineOverspeedTripEnhanced_eqFunction_16,
    TurbineOverspeedTripEnhanced_eqFunction_18,
    TurbineOverspeedTripEnhanced_eqFunction_19,
    TurbineOverspeedTripEnhanced_eqFunction_21,
    TurbineOverspeedTripEnhanced_eqFunction_22,
    TurbineOverspeedTripEnhanced_eqFunction_23,
    TurbineOverspeedTripEnhanced_eqFunction_24,
    TurbineOverspeedTripEnhanced_eqFunction_25,
    TurbineOverspeedTripEnhanced_eqFunction_26
  };
  
  static const int eqIndices[9] = {
    16,
    18,
    19,
    21,
    22,
    23,
    24,
    25,
    26
  };
  
  for (id = 0; id < 9; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int TurbineOverspeedTripEnhanced_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  TurbineOverspeedTripEnhanced_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void TurbineOverspeedTripEnhanced_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* omega STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* trip_timer STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* valve_opening STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(omega) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(trip_timer) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(valve_opening) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* tau_disturb variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* tau_in variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* tau_load variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* valve_target variable */
  
  /* discreteAlgVars */
  
  /* realOptimizeConstraintsVars */
  
  /* realOptimizeFinalConstraintsVars */
  
  
  /* intAlgVars */
  
  /* boolAlgVars */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition1 DISCRETE */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition2 DISCRETE */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* overspeed DISCRETE */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* trip_latched DISCRETE */
  
  /* stringAlgVars */
  
  TRACE_POP
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "TurbineOverspeedTripEnhanced_12jac.h"
#include "TurbineOverspeedTripEnhanced_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks TurbineOverspeedTripEnhanced_callback = {
   (int (*)(DATA *, threadData_t *, void *)) TurbineOverspeedTripEnhanced_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) TurbineOverspeedTripEnhanced_performQSSSimulation,    /* performQSSSimulation */
   TurbineOverspeedTripEnhanced_updateContinuousSystem,    /* updateContinuousSystem */
   TurbineOverspeedTripEnhanced_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   TurbineOverspeedTripEnhanced_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   TurbineOverspeedTripEnhanced_initializeDAEmodeData,
   TurbineOverspeedTripEnhanced_computeVarIndices,
   TurbineOverspeedTripEnhanced_functionODE,
   TurbineOverspeedTripEnhanced_functionAlgebraics,
   TurbineOverspeedTripEnhanced_functionDAE,
   TurbineOverspeedTripEnhanced_functionLocalKnownVars,
   TurbineOverspeedTripEnhanced_input_function,
   TurbineOverspeedTripEnhanced_input_function_init,
   TurbineOverspeedTripEnhanced_input_function_updateStartValues,
   TurbineOverspeedTripEnhanced_data_function,
   TurbineOverspeedTripEnhanced_output_function,
   TurbineOverspeedTripEnhanced_setc_function,
   TurbineOverspeedTripEnhanced_setb_function,
   TurbineOverspeedTripEnhanced_function_storeDelayed,
   TurbineOverspeedTripEnhanced_function_storeSpatialDistribution,
   TurbineOverspeedTripEnhanced_function_initSpatialDistribution,
   TurbineOverspeedTripEnhanced_updateBoundVariableAttributes,
   TurbineOverspeedTripEnhanced_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   TurbineOverspeedTripEnhanced_functionRemovedInitialEquations,
   TurbineOverspeedTripEnhanced_updateBoundParameters,
   TurbineOverspeedTripEnhanced_checkForAsserts,
   TurbineOverspeedTripEnhanced_function_ZeroCrossingsEquations,
   TurbineOverspeedTripEnhanced_function_ZeroCrossings,
   TurbineOverspeedTripEnhanced_function_updateRelations,
   TurbineOverspeedTripEnhanced_zeroCrossingDescription,
   TurbineOverspeedTripEnhanced_relationDescription,
   TurbineOverspeedTripEnhanced_function_initSample,
   TurbineOverspeedTripEnhanced_INDEX_JAC_A,
   TurbineOverspeedTripEnhanced_INDEX_JAC_B,
   TurbineOverspeedTripEnhanced_INDEX_JAC_C,
   TurbineOverspeedTripEnhanced_INDEX_JAC_D,
   TurbineOverspeedTripEnhanced_INDEX_JAC_F,
   TurbineOverspeedTripEnhanced_INDEX_JAC_H,
   TurbineOverspeedTripEnhanced_initialAnalyticJacobianA,
   TurbineOverspeedTripEnhanced_initialAnalyticJacobianB,
   TurbineOverspeedTripEnhanced_initialAnalyticJacobianC,
   TurbineOverspeedTripEnhanced_initialAnalyticJacobianD,
   TurbineOverspeedTripEnhanced_initialAnalyticJacobianF,
   TurbineOverspeedTripEnhanced_initialAnalyticJacobianH,
   TurbineOverspeedTripEnhanced_functionJacA_column,
   TurbineOverspeedTripEnhanced_functionJacB_column,
   TurbineOverspeedTripEnhanced_functionJacC_column,
   TurbineOverspeedTripEnhanced_functionJacD_column,
   TurbineOverspeedTripEnhanced_functionJacF_column,
   TurbineOverspeedTripEnhanced_functionJacH_column,
   TurbineOverspeedTripEnhanced_linear_model_frame,
   TurbineOverspeedTripEnhanced_linear_model_datarecovery_frame,
   TurbineOverspeedTripEnhanced_mayer,
   TurbineOverspeedTripEnhanced_lagrange,
   TurbineOverspeedTripEnhanced_pickUpBoundsForInputsInOptimization,
   TurbineOverspeedTripEnhanced_setInputData,
   TurbineOverspeedTripEnhanced_getTimeGrid,
   TurbineOverspeedTripEnhanced_symbolicInlineSystem,
   TurbineOverspeedTripEnhanced_function_initSynchronous,
   TurbineOverspeedTripEnhanced_function_updateSynchronous,
   TurbineOverspeedTripEnhanced_function_equationsSynchronous,
   TurbineOverspeedTripEnhanced_inputNames,
   TurbineOverspeedTripEnhanced_dataReconciliationInputNames,
   TurbineOverspeedTripEnhanced_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "TurbineOverspeedTripEnhanced"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/Desktop/实验组6/cases/20260427_203118_TurbineOverspeedTripEnhanced/build/src"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,28,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,92,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void TurbineOverspeedTripEnhanced_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &TurbineOverspeedTripEnhanced_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "TurbineOverspeedTripEnhanced";
  data->modelData->modelFilePrefix = "TurbineOverspeedTripEnhanced";
  data->modelData->modelFileName = "TurbineOverspeedTripEnhanced.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/实验组6/cases/20260427_203118_TurbineOverspeedTripEnhanced/build/src";
  data->modelData->modelGUID = "{bea7262c-49dc-492f-b434-dc02de642726}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "TurbineOverspeedTripEnhanced_init.c"
    ;
  static const char contents_info[] =
    #include "TurbineOverspeedTripEnhanced_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "TurbineOverspeedTripEnhanced_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "TurbineOverspeedTripEnhanced_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "TurbineOverspeedTripEnhanced_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 3;
  data->modelData->nVariablesRealArray = 10;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 4;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 11;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 3;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 6;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 28;
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
  
    TurbineOverspeedTripEnhanced_setupDataStruc(&data, threadData);
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


