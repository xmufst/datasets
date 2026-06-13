/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "SmithPredictorTemp_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation SmithPredictorTemp_performSimulation
#define prefixedName_updateContinuousSystem SmithPredictorTemp_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation SmithPredictorTemp_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int SmithPredictorTemp_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SmithPredictorTemp_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SmithPredictorTemp_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SmithPredictorTemp_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SmithPredictorTemp_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int SmithPredictorTemp_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SmithPredictorTemp_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SmithPredictorTemp_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SmithPredictorTemp_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SmithPredictorTemp_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 13
type: SIMPLE_ASSIGN
T_ref_signal = reference.offset + (if time < reference.startTime then 0.0 else reference.height)
*/
void SmithPredictorTemp_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[16] /* reference.startTime PARAM */));
  relationhysteresis(data, &tmp0, data->localData[0]->timeValue, (data->simulationInfo->realParameter[16] /* reference.startTime PARAM */), tmp1, tmp2, 2, Less, LessZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* T_ref_signal variable */) = (data->simulationInfo->realParameter[15] /* reference.offset PARAM */) + (tmp0?0.0:(data->simulationInfo->realParameter[14] /* reference.height PARAM */));
  TRACE_POP
}
/*
equation index: 14
type: SIMPLE_ASSIGN
T_measured = delay(0, T_process, L, L)
*/
void SmithPredictorTemp_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  modelica_real tmp3;
  tmp3 = delayImpl(data, threadData, 0, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* T_process STATE(1) */), (data->simulationInfo->realParameter[2] /* L PARAM */), (data->simulationInfo->realParameter[2] /* L PARAM */));
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* T_measured variable */) = tmp3;
  TRACE_POP
}
/*
equation index: 15
type: SIMPLE_ASSIGN
T_model_delayed = delay(1, T_model, L, L)
*/
void SmithPredictorTemp_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  modelica_real tmp4;
  tmp4 = delayImpl(data, threadData, 1, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_model STATE(1) */), (data->simulationInfo->realParameter[2] /* L PARAM */), (data->simulationInfo->realParameter[2] /* L PARAM */));
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* T_model_delayed variable */) = tmp4;
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
T_predicted = compensator.k1 * T_measured + compensator.k2 * T_model + compensator.k3 * T_model_delayed
*/
void SmithPredictorTemp_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* T_predicted variable */) = ((data->simulationInfo->realParameter[7] /* compensator.k1 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* T_measured variable */)) + ((data->simulationInfo->realParameter[8] /* compensator.k2 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_model STATE(1) */)) + ((data->simulationInfo->realParameter[9] /* compensator.k3 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* T_model_delayed variable */));
  TRACE_POP
}
/*
equation index: 17
type: SIMPLE_ASSIGN
T_error = T_ref_signal - T_predicted
*/
void SmithPredictorTemp_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* T_error variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* T_ref_signal variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* T_predicted variable */);
  TRACE_POP
}
/*
equation index: 18
type: SIMPLE_ASSIGN
u_pi = piController.k * (piController.x + T_error)
*/
void SmithPredictorTemp_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* u_pi variable */) = ((data->simulationInfo->realParameter[11] /* piController.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* piController.x STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* T_error variable */));
  TRACE_POP
}
/*
equation index: 19
type: SIMPLE_ASSIGN
$DER.T_model = (K_plant * u_pi + T0 - T_model) / T_plant
*/
void SmithPredictorTemp_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(T_model) STATE_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[0] /* K_plant PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* u_pi variable */)) + (data->simulationInfo->realParameter[3] /* T0 PARAM */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_model STATE(1) */),(data->simulationInfo->realParameter[4] /* T_plant PARAM */),"T_plant",equationIndexes);
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
$DER.T_process = (K_plant * u_pi + T0 - T_process) / T_plant
*/
void SmithPredictorTemp_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* der(T_process) STATE_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[0] /* K_plant PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* u_pi variable */)) + (data->simulationInfo->realParameter[3] /* T0 PARAM */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* T_process STATE(1) */),(data->simulationInfo->realParameter[4] /* T_plant PARAM */),"T_plant",equationIndexes);
  TRACE_POP
}
/*
equation index: 21
type: SIMPLE_ASSIGN
$DER.piController.x = T_error / piController.T
*/
void SmithPredictorTemp_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* der(piController.x) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* T_error variable */),(data->simulationInfo->realParameter[10] /* piController.T PARAM */),"piController.T",equationIndexes);
  TRACE_POP
}

OMC_DISABLE_OPT
int SmithPredictorTemp_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  SmithPredictorTemp_functionLocalKnownVars(data, threadData);
  SmithPredictorTemp_eqFunction_13(data, threadData);

  SmithPredictorTemp_eqFunction_14(data, threadData);

  SmithPredictorTemp_eqFunction_15(data, threadData);

  SmithPredictorTemp_eqFunction_16(data, threadData);

  SmithPredictorTemp_eqFunction_17(data, threadData);

  SmithPredictorTemp_eqFunction_18(data, threadData);

  SmithPredictorTemp_eqFunction_19(data, threadData);

  SmithPredictorTemp_eqFunction_20(data, threadData);

  SmithPredictorTemp_eqFunction_21(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int SmithPredictorTemp_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void SmithPredictorTemp_eqFunction_13(DATA* data, threadData_t *threadData);
extern void SmithPredictorTemp_eqFunction_14(DATA* data, threadData_t *threadData);
extern void SmithPredictorTemp_eqFunction_15(DATA* data, threadData_t *threadData);
extern void SmithPredictorTemp_eqFunction_16(DATA* data, threadData_t *threadData);
extern void SmithPredictorTemp_eqFunction_17(DATA* data, threadData_t *threadData);
extern void SmithPredictorTemp_eqFunction_18(DATA* data, threadData_t *threadData);
extern void SmithPredictorTemp_eqFunction_19(DATA* data, threadData_t *threadData);
extern void SmithPredictorTemp_eqFunction_20(DATA* data, threadData_t *threadData);
extern void SmithPredictorTemp_eqFunction_21(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[9])(DATA*, threadData_t*) = {
    SmithPredictorTemp_eqFunction_13,
    SmithPredictorTemp_eqFunction_14,
    SmithPredictorTemp_eqFunction_15,
    SmithPredictorTemp_eqFunction_16,
    SmithPredictorTemp_eqFunction_17,
    SmithPredictorTemp_eqFunction_18,
    SmithPredictorTemp_eqFunction_19,
    SmithPredictorTemp_eqFunction_20,
    SmithPredictorTemp_eqFunction_21
  };
  
  static const int eqIndices[9] = {
    13,
    14,
    15,
    16,
    17,
    18,
    19,
    20,
    21
  };
  
  for (id = 0; id < 9; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int SmithPredictorTemp_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  SmithPredictorTemp_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void SmithPredictorTemp_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_model STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_process STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* piController.x STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(T_model) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(T_process) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(piController.x) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_error variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_measured variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_model_delayed variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_predicted variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_ref_signal variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* u_pi variable */
  
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

#include "SmithPredictorTemp_12jac.h"
#include "SmithPredictorTemp_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks SmithPredictorTemp_callback = {
   (int (*)(DATA *, threadData_t *, void *)) SmithPredictorTemp_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) SmithPredictorTemp_performQSSSimulation,    /* performQSSSimulation */
   SmithPredictorTemp_updateContinuousSystem,    /* updateContinuousSystem */
   SmithPredictorTemp_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   SmithPredictorTemp_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   SmithPredictorTemp_initializeDAEmodeData,
   SmithPredictorTemp_computeVarIndices,
   SmithPredictorTemp_functionODE,
   SmithPredictorTemp_functionAlgebraics,
   SmithPredictorTemp_functionDAE,
   SmithPredictorTemp_functionLocalKnownVars,
   SmithPredictorTemp_input_function,
   SmithPredictorTemp_input_function_init,
   SmithPredictorTemp_input_function_updateStartValues,
   SmithPredictorTemp_data_function,
   SmithPredictorTemp_output_function,
   SmithPredictorTemp_setc_function,
   SmithPredictorTemp_setb_function,
   SmithPredictorTemp_function_storeDelayed,
   SmithPredictorTemp_function_storeSpatialDistribution,
   SmithPredictorTemp_function_initSpatialDistribution,
   SmithPredictorTemp_updateBoundVariableAttributes,
   SmithPredictorTemp_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   SmithPredictorTemp_functionRemovedInitialEquations,
   SmithPredictorTemp_updateBoundParameters,
   SmithPredictorTemp_checkForAsserts,
   SmithPredictorTemp_function_ZeroCrossingsEquations,
   SmithPredictorTemp_function_ZeroCrossings,
   SmithPredictorTemp_function_updateRelations,
   SmithPredictorTemp_zeroCrossingDescription,
   SmithPredictorTemp_relationDescription,
   SmithPredictorTemp_function_initSample,
   SmithPredictorTemp_INDEX_JAC_A,
   SmithPredictorTemp_INDEX_JAC_B,
   SmithPredictorTemp_INDEX_JAC_C,
   SmithPredictorTemp_INDEX_JAC_D,
   SmithPredictorTemp_INDEX_JAC_F,
   SmithPredictorTemp_INDEX_JAC_H,
   SmithPredictorTemp_initialAnalyticJacobianA,
   SmithPredictorTemp_initialAnalyticJacobianB,
   SmithPredictorTemp_initialAnalyticJacobianC,
   SmithPredictorTemp_initialAnalyticJacobianD,
   SmithPredictorTemp_initialAnalyticJacobianF,
   SmithPredictorTemp_initialAnalyticJacobianH,
   SmithPredictorTemp_functionJacA_column,
   SmithPredictorTemp_functionJacB_column,
   SmithPredictorTemp_functionJacC_column,
   SmithPredictorTemp_functionJacD_column,
   SmithPredictorTemp_functionJacF_column,
   SmithPredictorTemp_functionJacH_column,
   SmithPredictorTemp_linear_model_frame,
   SmithPredictorTemp_linear_model_datarecovery_frame,
   SmithPredictorTemp_mayer,
   SmithPredictorTemp_lagrange,
   SmithPredictorTemp_pickUpBoundsForInputsInOptimization,
   SmithPredictorTemp_setInputData,
   SmithPredictorTemp_getTimeGrid,
   SmithPredictorTemp_symbolicInlineSystem,
   SmithPredictorTemp_function_initSynchronous,
   SmithPredictorTemp_function_updateSynchronous,
   SmithPredictorTemp_function_equationsSynchronous,
   SmithPredictorTemp_inputNames,
   SmithPredictorTemp_dataReconciliationInputNames,
   SmithPredictorTemp_dataReconciliationUnmeasuredVariables,
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

#define _OMC_LIT_RESOURCE_3_name_data "SmithPredictorTemp"
#define _OMC_LIT_RESOURCE_3_dir_data "C:/Users/FST/Desktop/第二类数据/cases_standard/C17"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,18,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,55,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void SmithPredictorTemp_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &SmithPredictorTemp_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "SmithPredictorTemp";
  data->modelData->modelFilePrefix = "SmithPredictorTemp";
  data->modelData->modelFileName = "SmithPredictorTemp.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/第二类数据/cases_standard/C17";
  data->modelData->modelGUID = "{0564bfcc-a75c-4f32-aba6-945b8bbeff06}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "SmithPredictorTemp_init.c"
    ;
  static const char contents_info[] =
    #include "SmithPredictorTemp_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "SmithPredictorTemp_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "SmithPredictorTemp_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "SmithPredictorTemp_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 3;
  data->modelData->nVariablesRealArray = 12;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 17;
  data->modelData->nParametersInteger = 1;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 11;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 3;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 3;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 32;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 6;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  data->modelData->nDelayExpressions = 2;
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
  
    SmithPredictorTemp_setupDataStruc(&data, threadData);
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


