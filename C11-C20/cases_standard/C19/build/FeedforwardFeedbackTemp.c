/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "FeedforwardFeedbackTemp_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation FeedforwardFeedbackTemp_performSimulation
#define prefixedName_updateContinuousSystem FeedforwardFeedbackTemp_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation FeedforwardFeedbackTemp_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int FeedforwardFeedbackTemp_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FeedforwardFeedbackTemp_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FeedforwardFeedbackTemp_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FeedforwardFeedbackTemp_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FeedforwardFeedbackTemp_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int FeedforwardFeedbackTemp_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FeedforwardFeedbackTemp_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FeedforwardFeedbackTemp_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FeedforwardFeedbackTemp_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FeedforwardFeedbackTemp_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 12
type: SIMPLE_ASSIGN
T_error = refSignal.k - T
*/
void FeedforwardFeedbackTemp_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* T_error variable */) = (data->simulationInfo->realParameter[25] /* refSignal.k PARAM */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */);
  TRACE_POP
}
/*
equation index: 13
type: SIMPLE_ASSIGN
$DER.piCorrection.x = T_error / piCorrection.T
*/
void FeedforwardFeedbackTemp_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(piCorrection.x) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* T_error variable */),(data->simulationInfo->realParameter[21] /* piCorrection.T PARAM */),"piCorrection.T",equationIndexes);
  TRACE_POP
}
/*
equation index: 14
type: SIMPLE_ASSIGN
u_pi = piCorrection.k * (piCorrection.x + T_error)
*/
void FeedforwardFeedbackTemp_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* u_pi variable */) = ((data->simulationInfo->realParameter[22] /* piCorrection.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piCorrection.x STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* T_error variable */));
  TRACE_POP
}
/*
equation index: 15
type: SIMPLE_ASSIGN
Q_disturbance = disturbanceSignal.offset + (if time < disturbanceSignal.startTime then 0.0 else disturbanceSignal.height)
*/
void FeedforwardFeedbackTemp_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[14] /* disturbanceSignal.startTime PARAM */));
  relationhysteresis(data, &tmp0, data->localData[0]->timeValue, (data->simulationInfo->realParameter[14] /* disturbanceSignal.startTime PARAM */), tmp1, tmp2, 0, Less, LessZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* Q_disturbance variable */) = (data->simulationInfo->realParameter[13] /* disturbanceSignal.offset PARAM */) + (tmp0?0.0:(data->simulationInfo->realParameter[12] /* disturbanceSignal.height PARAM */));
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
u_ff = feedforwardGain.k * Q_disturbance
*/
void FeedforwardFeedbackTemp_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_ff variable */) = ((data->simulationInfo->realParameter[16] /* feedforwardGain.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* Q_disturbance variable */));
  TRACE_POP
}
/*
equation index: 17
type: SIMPLE_ASSIGN
u_total = heaterSum.k1 * baselineHeat.k + heaterSum.k2 * u_pi + heaterSum.k3 * u_ff
*/
void FeedforwardFeedbackTemp_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* u_total variable */) = ((data->simulationInfo->realParameter[17] /* heaterSum.k1 PARAM */)) * ((data->simulationInfo->realParameter[10] /* baselineHeat.k PARAM */)) + ((data->simulationInfo->realParameter[18] /* heaterSum.k2 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* u_pi variable */)) + ((data->simulationInfo->realParameter[19] /* heaterSum.k3 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_ff variable */));
  TRACE_POP
}
/*
equation index: 18
type: SIMPLE_ASSIGN
Q_heater = max(0.0, u_total)
*/
void FeedforwardFeedbackTemp_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* Q_heater variable */) = fmax(0.0,(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* u_total variable */));
  TRACE_POP
}
/*
equation index: 19
type: SIMPLE_ASSIGN
Q_loss = UA * (T - T_amb)
*/
void FeedforwardFeedbackTemp_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* Q_loss variable */) = ((data->simulationInfo->realParameter[9] /* UA PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */) - (data->simulationInfo->realParameter[6] /* T_amb PARAM */));
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
$DER.T = (Q_heater + (-Q_loss) - Q_disturbance) / C_furnace
*/
void FeedforwardFeedbackTemp_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(T) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* Q_heater variable */) + (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* Q_loss variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* Q_disturbance variable */),(data->simulationInfo->realParameter[0] /* C_furnace PARAM */),"C_furnace",equationIndexes);
  TRACE_POP
}

OMC_DISABLE_OPT
int FeedforwardFeedbackTemp_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  FeedforwardFeedbackTemp_functionLocalKnownVars(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_12(data, threadData);

  FeedforwardFeedbackTemp_eqFunction_13(data, threadData);

  FeedforwardFeedbackTemp_eqFunction_14(data, threadData);

  FeedforwardFeedbackTemp_eqFunction_15(data, threadData);

  FeedforwardFeedbackTemp_eqFunction_16(data, threadData);

  FeedforwardFeedbackTemp_eqFunction_17(data, threadData);

  FeedforwardFeedbackTemp_eqFunction_18(data, threadData);

  FeedforwardFeedbackTemp_eqFunction_19(data, threadData);

  FeedforwardFeedbackTemp_eqFunction_20(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int FeedforwardFeedbackTemp_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void FeedforwardFeedbackTemp_eqFunction_12(DATA* data, threadData_t *threadData);
extern void FeedforwardFeedbackTemp_eqFunction_13(DATA* data, threadData_t *threadData);
extern void FeedforwardFeedbackTemp_eqFunction_14(DATA* data, threadData_t *threadData);
extern void FeedforwardFeedbackTemp_eqFunction_15(DATA* data, threadData_t *threadData);
extern void FeedforwardFeedbackTemp_eqFunction_16(DATA* data, threadData_t *threadData);
extern void FeedforwardFeedbackTemp_eqFunction_17(DATA* data, threadData_t *threadData);
extern void FeedforwardFeedbackTemp_eqFunction_18(DATA* data, threadData_t *threadData);
extern void FeedforwardFeedbackTemp_eqFunction_19(DATA* data, threadData_t *threadData);
extern void FeedforwardFeedbackTemp_eqFunction_20(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[9])(DATA*, threadData_t*) = {
    FeedforwardFeedbackTemp_eqFunction_12,
    FeedforwardFeedbackTemp_eqFunction_13,
    FeedforwardFeedbackTemp_eqFunction_14,
    FeedforwardFeedbackTemp_eqFunction_15,
    FeedforwardFeedbackTemp_eqFunction_16,
    FeedforwardFeedbackTemp_eqFunction_17,
    FeedforwardFeedbackTemp_eqFunction_18,
    FeedforwardFeedbackTemp_eqFunction_19,
    FeedforwardFeedbackTemp_eqFunction_20
  };
  
  static const int eqIndices[9] = {
    12,
    13,
    14,
    15,
    16,
    17,
    18,
    19,
    20
  };
  
  for (id = 0; id < 9; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int FeedforwardFeedbackTemp_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  FeedforwardFeedbackTemp_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void FeedforwardFeedbackTemp_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* piCorrection.x STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(T) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(piCorrection.x) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_disturbance variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_heater variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_loss variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_error variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* u_ff variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* u_pi variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* u_total variable */
  
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

#include "FeedforwardFeedbackTemp_12jac.h"
#include "FeedforwardFeedbackTemp_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks FeedforwardFeedbackTemp_callback = {
   (int (*)(DATA *, threadData_t *, void *)) FeedforwardFeedbackTemp_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) FeedforwardFeedbackTemp_performQSSSimulation,    /* performQSSSimulation */
   FeedforwardFeedbackTemp_updateContinuousSystem,    /* updateContinuousSystem */
   FeedforwardFeedbackTemp_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   FeedforwardFeedbackTemp_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   FeedforwardFeedbackTemp_initializeDAEmodeData,
   FeedforwardFeedbackTemp_computeVarIndices,
   FeedforwardFeedbackTemp_functionODE,
   FeedforwardFeedbackTemp_functionAlgebraics,
   FeedforwardFeedbackTemp_functionDAE,
   FeedforwardFeedbackTemp_functionLocalKnownVars,
   FeedforwardFeedbackTemp_input_function,
   FeedforwardFeedbackTemp_input_function_init,
   FeedforwardFeedbackTemp_input_function_updateStartValues,
   FeedforwardFeedbackTemp_data_function,
   FeedforwardFeedbackTemp_output_function,
   FeedforwardFeedbackTemp_setc_function,
   FeedforwardFeedbackTemp_setb_function,
   FeedforwardFeedbackTemp_function_storeDelayed,
   FeedforwardFeedbackTemp_function_storeSpatialDistribution,
   FeedforwardFeedbackTemp_function_initSpatialDistribution,
   FeedforwardFeedbackTemp_updateBoundVariableAttributes,
   FeedforwardFeedbackTemp_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   FeedforwardFeedbackTemp_functionRemovedInitialEquations,
   FeedforwardFeedbackTemp_updateBoundParameters,
   FeedforwardFeedbackTemp_checkForAsserts,
   FeedforwardFeedbackTemp_function_ZeroCrossingsEquations,
   FeedforwardFeedbackTemp_function_ZeroCrossings,
   FeedforwardFeedbackTemp_function_updateRelations,
   FeedforwardFeedbackTemp_zeroCrossingDescription,
   FeedforwardFeedbackTemp_relationDescription,
   FeedforwardFeedbackTemp_function_initSample,
   FeedforwardFeedbackTemp_INDEX_JAC_A,
   FeedforwardFeedbackTemp_INDEX_JAC_B,
   FeedforwardFeedbackTemp_INDEX_JAC_C,
   FeedforwardFeedbackTemp_INDEX_JAC_D,
   FeedforwardFeedbackTemp_INDEX_JAC_F,
   FeedforwardFeedbackTemp_INDEX_JAC_H,
   FeedforwardFeedbackTemp_initialAnalyticJacobianA,
   FeedforwardFeedbackTemp_initialAnalyticJacobianB,
   FeedforwardFeedbackTemp_initialAnalyticJacobianC,
   FeedforwardFeedbackTemp_initialAnalyticJacobianD,
   FeedforwardFeedbackTemp_initialAnalyticJacobianF,
   FeedforwardFeedbackTemp_initialAnalyticJacobianH,
   FeedforwardFeedbackTemp_functionJacA_column,
   FeedforwardFeedbackTemp_functionJacB_column,
   FeedforwardFeedbackTemp_functionJacC_column,
   FeedforwardFeedbackTemp_functionJacD_column,
   FeedforwardFeedbackTemp_functionJacF_column,
   FeedforwardFeedbackTemp_functionJacH_column,
   FeedforwardFeedbackTemp_linear_model_frame,
   FeedforwardFeedbackTemp_linear_model_datarecovery_frame,
   FeedforwardFeedbackTemp_mayer,
   FeedforwardFeedbackTemp_lagrange,
   FeedforwardFeedbackTemp_pickUpBoundsForInputsInOptimization,
   FeedforwardFeedbackTemp_setInputData,
   FeedforwardFeedbackTemp_getTimeGrid,
   FeedforwardFeedbackTemp_symbolicInlineSystem,
   FeedforwardFeedbackTemp_function_initSynchronous,
   FeedforwardFeedbackTemp_function_updateSynchronous,
   FeedforwardFeedbackTemp_function_equationsSynchronous,
   FeedforwardFeedbackTemp_inputNames,
   FeedforwardFeedbackTemp_dataReconciliationInputNames,
   FeedforwardFeedbackTemp_dataReconciliationUnmeasuredVariables,
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

#define _OMC_LIT_RESOURCE_1_name_data "FeedforwardFeedbackTemp"
#define _OMC_LIT_RESOURCE_1_dir_data "C:/Users/FST/Desktop/AFM/C19"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,23,_OMC_LIT_RESOURCE_1_name_data);
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
void FeedforwardFeedbackTemp_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &FeedforwardFeedbackTemp_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "FeedforwardFeedbackTemp";
  data->modelData->modelFilePrefix = "FeedforwardFeedbackTemp";
  data->modelData->modelFileName = "FeedforwardFeedbackTemp.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/C19";
  data->modelData->modelGUID = "{c2d9ad50-3735-4cfe-b9ba-2e28cf3e154b}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "FeedforwardFeedbackTemp_init.c"
    ;
  static const char contents_info[] =
    #include "FeedforwardFeedbackTemp_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "FeedforwardFeedbackTemp_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "FeedforwardFeedbackTemp_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "FeedforwardFeedbackTemp_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 11;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 28;
  data->modelData->nParametersInteger = 1;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 10;
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
  data->modelData->modelDataXml.nEquations = 37;
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
  
    FeedforwardFeedbackTemp_setupDataStruc(&data, threadData);
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


