/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "DCMotorStateFeedback_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation DCMotorStateFeedback_performSimulation
#define prefixedName_updateContinuousSystem DCMotorStateFeedback_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation DCMotorStateFeedback_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int DCMotorStateFeedback_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DCMotorStateFeedback_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DCMotorStateFeedback_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DCMotorStateFeedback_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DCMotorStateFeedback_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int DCMotorStateFeedback_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DCMotorStateFeedback_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DCMotorStateFeedback_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DCMotorStateFeedback_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DCMotorStateFeedback_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 14
type: SIMPLE_ASSIGN
refSignal.y = refSignal.offset + (if time < refSignal.startTime then 0.0 else refSignal.height)
*/
void DCMotorStateFeedback_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[19] /* refSignal.startTime PARAM */));
  relationhysteresis(data, &tmp0, data->localData[0]->timeValue, (data->simulationInfo->realParameter[19] /* refSignal.startTime PARAM */), tmp1, tmp2, 1, Less, LessZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* refSignal.y variable */) = (data->simulationInfo->realParameter[18] /* refSignal.offset PARAM */) + (tmp0?0.0:(data->simulationInfo->realParameter[17] /* refSignal.height PARAM */));
  TRACE_POP
}
/*
equation index: 15
type: SIMPLE_ASSIGN
T_load = loadDisturbance.offset + (if time < loadDisturbance.startTime then 0.0 else loadDisturbance.height)
*/
void DCMotorStateFeedback_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  tmp4 = 1.0;
  tmp5 = fabs((data->simulationInfo->realParameter[15] /* loadDisturbance.startTime PARAM */));
  relationhysteresis(data, &tmp3, data->localData[0]->timeValue, (data->simulationInfo->realParameter[15] /* loadDisturbance.startTime PARAM */), tmp4, tmp5, 0, Less, LessZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_load variable */) = (data->simulationInfo->realParameter[14] /* loadDisturbance.offset PARAM */) + (tmp3?0.0:(data->simulationInfo->realParameter[13] /* loadDisturbance.height PARAM */));
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
gainKr.y = gainKr.k * refSignal.y
*/
void DCMotorStateFeedback_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* gainKr.y variable */) = ((data->simulationInfo->realParameter[12] /* gainKr.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* refSignal.y variable */));
  TRACE_POP
}
/*
equation index: 17
type: SIMPLE_ASSIGN
gainK1.y = gainK1.k * ia
*/
void DCMotorStateFeedback_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* gainK1.y variable */) = ((data->simulationInfo->realParameter[10] /* gainK1.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* ia STATE(1) */));
  TRACE_POP
}
/*
equation index: 18
type: SIMPLE_ASSIGN
gainK2.y = gainK2.k * omega
*/
void DCMotorStateFeedback_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* gainK2.y variable */) = ((data->simulationInfo->realParameter[11] /* gainK2.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* omega STATE(1) */));
  TRACE_POP
}
/*
equation index: 19
type: SIMPLE_ASSIGN
u_control = sumControl.k1 * gainKr.y + sumControl.k2 * gainK1.y + sumControl.k3 * gainK2.y
*/
void DCMotorStateFeedback_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* u_control variable */) = ((data->simulationInfo->realParameter[20] /* sumControl.k1 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* gainKr.y variable */)) + ((data->simulationInfo->realParameter[21] /* sumControl.k2 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* gainK1.y variable */)) + ((data->simulationInfo->realParameter[22] /* sumControl.k3 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* gainK2.y variable */));
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
Vemf = Ke * omega
*/
void DCMotorStateFeedback_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* Vemf variable */) = ((data->simulationInfo->realParameter[4] /* Ke PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* omega STATE(1) */));
  TRACE_POP
}
/*
equation index: 21
type: SIMPLE_ASSIGN
$DER.ia = (u_control + (-Ra) * ia - Vemf) / La
*/
void DCMotorStateFeedback_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(ia) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* u_control variable */) + ((-(data->simulationInfo->realParameter[8] /* Ra PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* ia STATE(1) */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* Vemf variable */),(data->simulationInfo->realParameter[7] /* La PARAM */),"La",equationIndexes);
  TRACE_POP
}
/*
equation index: 22
type: SIMPLE_ASSIGN
T_motor = Kt * ia
*/
void DCMotorStateFeedback_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* T_motor variable */) = ((data->simulationInfo->realParameter[6] /* Kt PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* ia STATE(1) */));
  TRACE_POP
}
/*
equation index: 23
type: SIMPLE_ASSIGN
$DER.omega = (T_motor + (-B_fric) * omega - T_load) / J
*/
void DCMotorStateFeedback_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(omega) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* T_motor variable */) + ((-(data->simulationInfo->realParameter[0] /* B_fric PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* omega STATE(1) */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_load variable */),(data->simulationInfo->realParameter[1] /* J PARAM */),"J",equationIndexes);
  TRACE_POP
}
/*
equation index: 24
type: SIMPLE_ASSIGN
omega_error = omega_ref - omega
*/
void DCMotorStateFeedback_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* omega_error variable */) = (data->simulationInfo->realParameter[16] /* omega_ref PARAM */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* omega STATE(1) */);
  TRACE_POP
}

OMC_DISABLE_OPT
int DCMotorStateFeedback_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  DCMotorStateFeedback_functionLocalKnownVars(data, threadData);
  DCMotorStateFeedback_eqFunction_14(data, threadData);

  DCMotorStateFeedback_eqFunction_15(data, threadData);

  DCMotorStateFeedback_eqFunction_16(data, threadData);

  DCMotorStateFeedback_eqFunction_17(data, threadData);

  DCMotorStateFeedback_eqFunction_18(data, threadData);

  DCMotorStateFeedback_eqFunction_19(data, threadData);

  DCMotorStateFeedback_eqFunction_20(data, threadData);

  DCMotorStateFeedback_eqFunction_21(data, threadData);

  DCMotorStateFeedback_eqFunction_22(data, threadData);

  DCMotorStateFeedback_eqFunction_23(data, threadData);

  DCMotorStateFeedback_eqFunction_24(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int DCMotorStateFeedback_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void DCMotorStateFeedback_eqFunction_14(DATA* data, threadData_t *threadData);
extern void DCMotorStateFeedback_eqFunction_15(DATA* data, threadData_t *threadData);
extern void DCMotorStateFeedback_eqFunction_16(DATA* data, threadData_t *threadData);
extern void DCMotorStateFeedback_eqFunction_17(DATA* data, threadData_t *threadData);
extern void DCMotorStateFeedback_eqFunction_18(DATA* data, threadData_t *threadData);
extern void DCMotorStateFeedback_eqFunction_19(DATA* data, threadData_t *threadData);
extern void DCMotorStateFeedback_eqFunction_20(DATA* data, threadData_t *threadData);
extern void DCMotorStateFeedback_eqFunction_21(DATA* data, threadData_t *threadData);
extern void DCMotorStateFeedback_eqFunction_22(DATA* data, threadData_t *threadData);
extern void DCMotorStateFeedback_eqFunction_23(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[10])(DATA*, threadData_t*) = {
    DCMotorStateFeedback_eqFunction_14,
    DCMotorStateFeedback_eqFunction_15,
    DCMotorStateFeedback_eqFunction_16,
    DCMotorStateFeedback_eqFunction_17,
    DCMotorStateFeedback_eqFunction_18,
    DCMotorStateFeedback_eqFunction_19,
    DCMotorStateFeedback_eqFunction_20,
    DCMotorStateFeedback_eqFunction_21,
    DCMotorStateFeedback_eqFunction_22,
    DCMotorStateFeedback_eqFunction_23
  };
  
  static const int eqIndices[10] = {
    14,
    15,
    16,
    17,
    18,
    19,
    20,
    21,
    22,
    23
  };
  
  for (id = 0; id < 10; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int DCMotorStateFeedback_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  DCMotorStateFeedback_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void DCMotorStateFeedback_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* ia STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* omega STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(ia) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(omega) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_load variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_motor variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Vemf variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* gainK1.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* gainK2.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* gainKr.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* omega_error variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* refSignal.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* u_control variable */
  
  /* discreteAlgVars */
  
  /* realOptimizeConstraintsVars */
  
  /* realOptimizeFinalConstraintsVars */
  
  
  /* intAlgVars */
  
  /* boolAlgVars */
  
  /* stringAlgVars */
  
  TRACE_POP
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "DCMotorStateFeedback_12jac.h"
#include "DCMotorStateFeedback_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks DCMotorStateFeedback_callback = {
   (int (*)(DATA *, threadData_t *, void *)) DCMotorStateFeedback_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) DCMotorStateFeedback_performQSSSimulation,    /* performQSSSimulation */
   DCMotorStateFeedback_updateContinuousSystem,    /* updateContinuousSystem */
   DCMotorStateFeedback_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   DCMotorStateFeedback_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   DCMotorStateFeedback_initializeDAEmodeData,
   DCMotorStateFeedback_computeVarIndices,
   DCMotorStateFeedback_functionODE,
   DCMotorStateFeedback_functionAlgebraics,
   DCMotorStateFeedback_functionDAE,
   DCMotorStateFeedback_functionLocalKnownVars,
   DCMotorStateFeedback_input_function,
   DCMotorStateFeedback_input_function_init,
   DCMotorStateFeedback_input_function_updateStartValues,
   DCMotorStateFeedback_data_function,
   DCMotorStateFeedback_output_function,
   DCMotorStateFeedback_setc_function,
   DCMotorStateFeedback_setb_function,
   DCMotorStateFeedback_function_storeDelayed,
   DCMotorStateFeedback_function_storeSpatialDistribution,
   DCMotorStateFeedback_function_initSpatialDistribution,
   DCMotorStateFeedback_updateBoundVariableAttributes,
   DCMotorStateFeedback_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   DCMotorStateFeedback_functionRemovedInitialEquations,
   DCMotorStateFeedback_updateBoundParameters,
   DCMotorStateFeedback_checkForAsserts,
   DCMotorStateFeedback_function_ZeroCrossingsEquations,
   DCMotorStateFeedback_function_ZeroCrossings,
   DCMotorStateFeedback_function_updateRelations,
   DCMotorStateFeedback_zeroCrossingDescription,
   DCMotorStateFeedback_relationDescription,
   DCMotorStateFeedback_function_initSample,
   DCMotorStateFeedback_INDEX_JAC_A,
   DCMotorStateFeedback_INDEX_JAC_B,
   DCMotorStateFeedback_INDEX_JAC_C,
   DCMotorStateFeedback_INDEX_JAC_D,
   DCMotorStateFeedback_INDEX_JAC_F,
   DCMotorStateFeedback_INDEX_JAC_H,
   DCMotorStateFeedback_initialAnalyticJacobianA,
   DCMotorStateFeedback_initialAnalyticJacobianB,
   DCMotorStateFeedback_initialAnalyticJacobianC,
   DCMotorStateFeedback_initialAnalyticJacobianD,
   DCMotorStateFeedback_initialAnalyticJacobianF,
   DCMotorStateFeedback_initialAnalyticJacobianH,
   DCMotorStateFeedback_functionJacA_column,
   DCMotorStateFeedback_functionJacB_column,
   DCMotorStateFeedback_functionJacC_column,
   DCMotorStateFeedback_functionJacD_column,
   DCMotorStateFeedback_functionJacF_column,
   DCMotorStateFeedback_functionJacH_column,
   DCMotorStateFeedback_linear_model_frame,
   DCMotorStateFeedback_linear_model_datarecovery_frame,
   DCMotorStateFeedback_mayer,
   DCMotorStateFeedback_lagrange,
   DCMotorStateFeedback_pickUpBoundsForInputsInOptimization,
   DCMotorStateFeedback_setInputData,
   DCMotorStateFeedback_getTimeGrid,
   DCMotorStateFeedback_symbolicInlineSystem,
   DCMotorStateFeedback_function_initSynchronous,
   DCMotorStateFeedback_function_updateSynchronous,
   DCMotorStateFeedback_function_equationsSynchronous,
   DCMotorStateFeedback_inputNames,
   DCMotorStateFeedback_dataReconciliationInputNames,
   DCMotorStateFeedback_dataReconciliationUnmeasuredVariables,
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

#define _OMC_LIT_RESOURCE_1_name_data "DCMotorStateFeedback"
#define _OMC_LIT_RESOURCE_1_dir_data "C:/Users/FST/Desktop/AFM/C13"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,20,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,28,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "Modelica"
#define _OMC_LIT_RESOURCE_2_dir_data "C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,8,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,76,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_3_dir_data "C:/Users/FST/AppData/Roaming/.openmodelica/libraries/ModelicaServices 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,16,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,84,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void DCMotorStateFeedback_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &DCMotorStateFeedback_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "DCMotorStateFeedback";
  data->modelData->modelFilePrefix = "DCMotorStateFeedback";
  data->modelData->modelFileName = "DCMotorStateFeedback.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/C13";
  data->modelData->modelGUID = "{f43beabd-bb7d-4fa1-86b7-80dbad83e493}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "DCMotorStateFeedback_init.c"
    ;
  static const char contents_info[] =
    #include "DCMotorStateFeedback_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "DCMotorStateFeedback_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "DCMotorStateFeedback_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "DCMotorStateFeedback_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 13;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 24;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 9;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 2;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 2;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 31;
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
  
    DCMotorStateFeedback_setupDataStruc(&data, threadData);
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


