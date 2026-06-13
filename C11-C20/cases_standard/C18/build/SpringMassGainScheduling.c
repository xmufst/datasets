/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "SpringMassGainScheduling_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation SpringMassGainScheduling_performSimulation
#define prefixedName_updateContinuousSystem SpringMassGainScheduling_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation SpringMassGainScheduling_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int SpringMassGainScheduling_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassGainScheduling_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassGainScheduling_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassGainScheduling_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassGainScheduling_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int SpringMassGainScheduling_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassGainScheduling_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassGainScheduling_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassGainScheduling_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassGainScheduling_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 12
type: SIMPLE_ASSIGN
E_kinetic = 0.5 * m * v ^ 2.0
*/
void SpringMassGainScheduling_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* E_kinetic variable */) = (0.5) * (((data->simulationInfo->realParameter[7] /* m PARAM */)) * ((tmp0 * tmp0)));
  TRACE_POP
}
/*
equation index: 13
type: SIMPLE_ASSIGN
$DER.x = v
*/
void SpringMassGainScheduling_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(x) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */);
  TRACE_POP
}
/*
equation index: 14
type: SIMPLE_ASSIGN
F_spring = k_base * x + k_nl * x ^ 3.0
*/
void SpringMassGainScheduling_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  modelica_real tmp1;
  tmp1 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* F_spring variable */) = ((data->simulationInfo->realParameter[5] /* k_base PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */)) + ((data->simulationInfo->realParameter[6] /* k_nl PARAM */)) * ((tmp1 * tmp1 * tmp1));
  TRACE_POP
}
/*
equation index: 15
type: SIMPLE_ASSIGN
Kp_current = if abs(x) < zone1 then Kp_low else if abs(x) < zone2 then Kp_mid else Kp_high
*/
void SpringMassGainScheduling_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  modelica_boolean tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_boolean tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_real tmp9;
  tmp3 = 1.0;
  tmp4 = fabs((data->simulationInfo->realParameter[14] /* zone1 PARAM */));
  relationhysteresis(data, &tmp2, fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */)), (data->simulationInfo->realParameter[14] /* zone1 PARAM */), tmp3, tmp4, 1, Less, LessZC);
  tmp8 = (modelica_boolean)tmp2;
  if(tmp8)
  {
    tmp9 = (data->simulationInfo->realParameter[2] /* Kp_low PARAM */);
  }
  else
  {
    tmp6 = 1.0;
    tmp7 = fabs((data->simulationInfo->realParameter[15] /* zone2 PARAM */));
    relationhysteresis(data, &tmp5, fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */)), (data->simulationInfo->realParameter[15] /* zone2 PARAM */), tmp6, tmp7, 2, Less, LessZC);
    tmp9 = (tmp5?(data->simulationInfo->realParameter[3] /* Kp_mid PARAM */):(data->simulationInfo->realParameter[1] /* Kp_high PARAM */));
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* Kp_current variable */) = tmp9;
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
refSignal.y = refSignal.offset + (if time < refSignal.startTime then 0.0 else refSignal.height)
*/
void SpringMassGainScheduling_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  modelica_boolean tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  tmp11 = 1.0;
  tmp12 = fabs((data->simulationInfo->realParameter[10] /* refSignal.startTime PARAM */));
  relationhysteresis(data, &tmp10, data->localData[0]->timeValue, (data->simulationInfo->realParameter[10] /* refSignal.startTime PARAM */), tmp11, tmp12, 0, Less, LessZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* refSignal.y variable */) = (data->simulationInfo->realParameter[9] /* refSignal.offset PARAM */) + (tmp10?0.0:(data->simulationInfo->realParameter[8] /* refSignal.height PARAM */));
  TRACE_POP
}
/*
equation index: 17
type: SIMPLE_ASSIGN
x_error = refSignal.y - x
*/
void SpringMassGainScheduling_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* x_error variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* refSignal.y variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */);
  TRACE_POP
}
/*
equation index: 18
type: SIMPLE_ASSIGN
F_control = Kp_current * x_error - Kd * v
*/
void SpringMassGainScheduling_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* F_control variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* Kp_current variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* x_error variable */)) - (((data->simulationInfo->realParameter[0] /* Kd PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */)));
  TRACE_POP
}
/*
equation index: 19
type: SIMPLE_ASSIGN
a = (F_control + (-F_spring) - c * v) / m
*/
void SpringMassGainScheduling_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* a variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* F_control variable */) + (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* F_spring variable */)) - (((data->simulationInfo->realParameter[4] /* c PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */))),(data->simulationInfo->realParameter[7] /* m PARAM */),"m",equationIndexes);
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
$DER.v = a
*/
void SpringMassGainScheduling_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(v) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* a variable */);
  TRACE_POP
}

OMC_DISABLE_OPT
int SpringMassGainScheduling_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  SpringMassGainScheduling_functionLocalKnownVars(data, threadData);
  SpringMassGainScheduling_eqFunction_12(data, threadData);

  SpringMassGainScheduling_eqFunction_13(data, threadData);

  SpringMassGainScheduling_eqFunction_14(data, threadData);

  SpringMassGainScheduling_eqFunction_15(data, threadData);

  SpringMassGainScheduling_eqFunction_16(data, threadData);

  SpringMassGainScheduling_eqFunction_17(data, threadData);

  SpringMassGainScheduling_eqFunction_18(data, threadData);

  SpringMassGainScheduling_eqFunction_19(data, threadData);

  SpringMassGainScheduling_eqFunction_20(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int SpringMassGainScheduling_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void SpringMassGainScheduling_eqFunction_13(DATA* data, threadData_t *threadData);
extern void SpringMassGainScheduling_eqFunction_14(DATA* data, threadData_t *threadData);
extern void SpringMassGainScheduling_eqFunction_15(DATA* data, threadData_t *threadData);
extern void SpringMassGainScheduling_eqFunction_16(DATA* data, threadData_t *threadData);
extern void SpringMassGainScheduling_eqFunction_17(DATA* data, threadData_t *threadData);
extern void SpringMassGainScheduling_eqFunction_18(DATA* data, threadData_t *threadData);
extern void SpringMassGainScheduling_eqFunction_19(DATA* data, threadData_t *threadData);
extern void SpringMassGainScheduling_eqFunction_20(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[8])(DATA*, threadData_t*) = {
    SpringMassGainScheduling_eqFunction_13,
    SpringMassGainScheduling_eqFunction_14,
    SpringMassGainScheduling_eqFunction_15,
    SpringMassGainScheduling_eqFunction_16,
    SpringMassGainScheduling_eqFunction_17,
    SpringMassGainScheduling_eqFunction_18,
    SpringMassGainScheduling_eqFunction_19,
    SpringMassGainScheduling_eqFunction_20
  };
  
  static const int eqIndices[8] = {
    13,
    14,
    15,
    16,
    17,
    18,
    19,
    20
  };
  
  for (id = 0; id < 8; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int SpringMassGainScheduling_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  SpringMassGainScheduling_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void SpringMassGainScheduling_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* v STATE(1,a) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* x STATE(1,v) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(v) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(x) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_kinetic variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_control variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_spring variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Kp_current variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* a variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* refSignal.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* x_error variable */
  
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

#include "SpringMassGainScheduling_12jac.h"
#include "SpringMassGainScheduling_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks SpringMassGainScheduling_callback = {
   (int (*)(DATA *, threadData_t *, void *)) SpringMassGainScheduling_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) SpringMassGainScheduling_performQSSSimulation,    /* performQSSSimulation */
   SpringMassGainScheduling_updateContinuousSystem,    /* updateContinuousSystem */
   SpringMassGainScheduling_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   SpringMassGainScheduling_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   SpringMassGainScheduling_initializeDAEmodeData,
   SpringMassGainScheduling_computeVarIndices,
   SpringMassGainScheduling_functionODE,
   SpringMassGainScheduling_functionAlgebraics,
   SpringMassGainScheduling_functionDAE,
   SpringMassGainScheduling_functionLocalKnownVars,
   SpringMassGainScheduling_input_function,
   SpringMassGainScheduling_input_function_init,
   SpringMassGainScheduling_input_function_updateStartValues,
   SpringMassGainScheduling_data_function,
   SpringMassGainScheduling_output_function,
   SpringMassGainScheduling_setc_function,
   SpringMassGainScheduling_setb_function,
   SpringMassGainScheduling_function_storeDelayed,
   SpringMassGainScheduling_function_storeSpatialDistribution,
   SpringMassGainScheduling_function_initSpatialDistribution,
   SpringMassGainScheduling_updateBoundVariableAttributes,
   SpringMassGainScheduling_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   SpringMassGainScheduling_functionRemovedInitialEquations,
   SpringMassGainScheduling_updateBoundParameters,
   SpringMassGainScheduling_checkForAsserts,
   SpringMassGainScheduling_function_ZeroCrossingsEquations,
   SpringMassGainScheduling_function_ZeroCrossings,
   SpringMassGainScheduling_function_updateRelations,
   SpringMassGainScheduling_zeroCrossingDescription,
   SpringMassGainScheduling_relationDescription,
   SpringMassGainScheduling_function_initSample,
   SpringMassGainScheduling_INDEX_JAC_A,
   SpringMassGainScheduling_INDEX_JAC_B,
   SpringMassGainScheduling_INDEX_JAC_C,
   SpringMassGainScheduling_INDEX_JAC_D,
   SpringMassGainScheduling_INDEX_JAC_F,
   SpringMassGainScheduling_INDEX_JAC_H,
   SpringMassGainScheduling_initialAnalyticJacobianA,
   SpringMassGainScheduling_initialAnalyticJacobianB,
   SpringMassGainScheduling_initialAnalyticJacobianC,
   SpringMassGainScheduling_initialAnalyticJacobianD,
   SpringMassGainScheduling_initialAnalyticJacobianF,
   SpringMassGainScheduling_initialAnalyticJacobianH,
   SpringMassGainScheduling_functionJacA_column,
   SpringMassGainScheduling_functionJacB_column,
   SpringMassGainScheduling_functionJacC_column,
   SpringMassGainScheduling_functionJacD_column,
   SpringMassGainScheduling_functionJacF_column,
   SpringMassGainScheduling_functionJacH_column,
   SpringMassGainScheduling_linear_model_frame,
   SpringMassGainScheduling_linear_model_datarecovery_frame,
   SpringMassGainScheduling_mayer,
   SpringMassGainScheduling_lagrange,
   SpringMassGainScheduling_pickUpBoundsForInputsInOptimization,
   SpringMassGainScheduling_setInputData,
   SpringMassGainScheduling_getTimeGrid,
   SpringMassGainScheduling_symbolicInlineSystem,
   SpringMassGainScheduling_function_initSynchronous,
   SpringMassGainScheduling_function_updateSynchronous,
   SpringMassGainScheduling_function_equationsSynchronous,
   SpringMassGainScheduling_inputNames,
   SpringMassGainScheduling_dataReconciliationInputNames,
   SpringMassGainScheduling_dataReconciliationUnmeasuredVariables,
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

#define _OMC_LIT_RESOURCE_3_name_data "SpringMassGainScheduling"
#define _OMC_LIT_RESOURCE_3_dir_data "C:/Users/FST/Desktop/AFM/C18"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,24,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,28,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void SpringMassGainScheduling_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &SpringMassGainScheduling_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "SpringMassGainScheduling";
  data->modelData->modelFilePrefix = "SpringMassGainScheduling";
  data->modelData->modelFileName = "SpringMassGainScheduling.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/C18";
  data->modelData->modelGUID = "{6a4b9d7e-9ddf-4335-a941-52aff843a129}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "SpringMassGainScheduling_init.c"
    ;
  static const char contents_info[] =
    #include "SpringMassGainScheduling_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "SpringMassGainScheduling_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "SpringMassGainScheduling_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "SpringMassGainScheduling_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 11;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 16;
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
  data->modelData->nRelations = 3;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 24;
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
  
    SpringMassGainScheduling_setupDataStruc(&data, threadData);
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


