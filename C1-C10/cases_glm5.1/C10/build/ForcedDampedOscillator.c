/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "ForcedDampedOscillator_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation ForcedDampedOscillator_performSimulation
#define prefixedName_updateContinuousSystem ForcedDampedOscillator_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation ForcedDampedOscillator_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int ForcedDampedOscillator_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ForcedDampedOscillator_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ForcedDampedOscillator_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ForcedDampedOscillator_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ForcedDampedOscillator_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int ForcedDampedOscillator_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ForcedDampedOscillator_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ForcedDampedOscillator_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ForcedDampedOscillator_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ForcedDampedOscillator_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 14
type: SIMPLE_ASSIGN
$cse1 = sin(omega * time)
*/
void ForcedDampedOscillator_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* $cse1 variable */) = sin(((data->simulationInfo->realParameter[5] /* omega PARAM */)) * (data->localData[0]->timeValue));
  TRACE_POP
}
/*
equation index: 15
type: SIMPLE_ASSIGN
P_dissipated = c * v ^ 2.0
*/
void ForcedDampedOscillator_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* P_dissipated variable */) = ((data->simulationInfo->realParameter[2] /* c PARAM */)) * ((tmp0 * tmp0));
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
E_potential = 0.5 * k * x ^ 2.0
*/
void ForcedDampedOscillator_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  modelica_real tmp1;
  tmp1 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* E_potential variable */) = (0.5) * (((data->simulationInfo->realParameter[3] /* k PARAM */)) * ((tmp1 * tmp1)));
  TRACE_POP
}
/*
equation index: 17
type: SIMPLE_ASSIGN
E_kinetic = 0.5 * m * v ^ 2.0
*/
void ForcedDampedOscillator_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  modelica_real tmp2;
  tmp2 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* E_kinetic variable */) = (0.5) * (((data->simulationInfo->realParameter[4] /* m PARAM */)) * ((tmp2 * tmp2)));
  TRACE_POP
}
/*
equation index: 18
type: SIMPLE_ASSIGN
E_total = E_kinetic + E_potential
*/
void ForcedDampedOscillator_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* E_total variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* E_kinetic variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* E_potential variable */);
  TRACE_POP
}
/*
equation index: 19
type: SIMPLE_ASSIGN
$DER.x = v
*/
void ForcedDampedOscillator_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(x) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */);
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
F_damper = c * v
*/
void ForcedDampedOscillator_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* F_damper variable */) = ((data->simulationInfo->realParameter[2] /* c PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */));
  TRACE_POP
}
/*
equation index: 21
type: SIMPLE_ASSIGN
F_spring = k * x
*/
void ForcedDampedOscillator_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* F_spring variable */) = ((data->simulationInfo->realParameter[3] /* k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */));
  TRACE_POP
}
/*
equation index: 22
type: SIMPLE_ASSIGN
F_ext = F0 * $cse1
*/
void ForcedDampedOscillator_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* F_ext variable */) = ((data->simulationInfo->realParameter[0] /* F0 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* $cse1 variable */));
  TRACE_POP
}
/*
equation index: 23
type: SIMPLE_ASSIGN
a = (F_ext + (-F_spring) - F_damper) / m
*/
void ForcedDampedOscillator_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* a variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* F_ext variable */) + (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* F_spring variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* F_damper variable */),(data->simulationInfo->realParameter[4] /* m PARAM */),"m",equationIndexes);
  TRACE_POP
}
/*
equation index: 24
type: SIMPLE_ASSIGN
$DER.v = a
*/
void ForcedDampedOscillator_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(v) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* a variable */);
  TRACE_POP
}
/*
equation index: 25
type: SIMPLE_ASSIGN
P_input = F_ext * v
*/
void ForcedDampedOscillator_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* P_input variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* F_ext variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */));
  TRACE_POP
}

OMC_DISABLE_OPT
int ForcedDampedOscillator_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  ForcedDampedOscillator_functionLocalKnownVars(data, threadData);
  ForcedDampedOscillator_eqFunction_14(data, threadData);

  ForcedDampedOscillator_eqFunction_15(data, threadData);

  ForcedDampedOscillator_eqFunction_16(data, threadData);

  ForcedDampedOscillator_eqFunction_17(data, threadData);

  ForcedDampedOscillator_eqFunction_18(data, threadData);

  ForcedDampedOscillator_eqFunction_19(data, threadData);

  ForcedDampedOscillator_eqFunction_20(data, threadData);

  ForcedDampedOscillator_eqFunction_21(data, threadData);

  ForcedDampedOscillator_eqFunction_22(data, threadData);

  ForcedDampedOscillator_eqFunction_23(data, threadData);

  ForcedDampedOscillator_eqFunction_24(data, threadData);

  ForcedDampedOscillator_eqFunction_25(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int ForcedDampedOscillator_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void ForcedDampedOscillator_eqFunction_14(DATA* data, threadData_t *threadData);
extern void ForcedDampedOscillator_eqFunction_19(DATA* data, threadData_t *threadData);
extern void ForcedDampedOscillator_eqFunction_20(DATA* data, threadData_t *threadData);
extern void ForcedDampedOscillator_eqFunction_21(DATA* data, threadData_t *threadData);
extern void ForcedDampedOscillator_eqFunction_22(DATA* data, threadData_t *threadData);
extern void ForcedDampedOscillator_eqFunction_23(DATA* data, threadData_t *threadData);
extern void ForcedDampedOscillator_eqFunction_24(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[7])(DATA*, threadData_t*) = {
    ForcedDampedOscillator_eqFunction_14,
    ForcedDampedOscillator_eqFunction_19,
    ForcedDampedOscillator_eqFunction_20,
    ForcedDampedOscillator_eqFunction_21,
    ForcedDampedOscillator_eqFunction_22,
    ForcedDampedOscillator_eqFunction_23,
    ForcedDampedOscillator_eqFunction_24
  };
  
  static const int eqIndices[7] = {
    14,
    19,
    20,
    21,
    22,
    23,
    24
  };
  
  for (id = 0; id < 7; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int ForcedDampedOscillator_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  ForcedDampedOscillator_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void ForcedDampedOscillator_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_kinetic variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_potential variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_total variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_damper variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_ext variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_spring variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* P_dissipated variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* P_input variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* a variable */
  
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

#include "ForcedDampedOscillator_12jac.h"
#include "ForcedDampedOscillator_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks ForcedDampedOscillator_callback = {
   (int (*)(DATA *, threadData_t *, void *)) ForcedDampedOscillator_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) ForcedDampedOscillator_performQSSSimulation,    /* performQSSSimulation */
   ForcedDampedOscillator_updateContinuousSystem,    /* updateContinuousSystem */
   ForcedDampedOscillator_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   ForcedDampedOscillator_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   ForcedDampedOscillator_initializeDAEmodeData,
   ForcedDampedOscillator_computeVarIndices,
   ForcedDampedOscillator_functionODE,
   ForcedDampedOscillator_functionAlgebraics,
   ForcedDampedOscillator_functionDAE,
   ForcedDampedOscillator_functionLocalKnownVars,
   ForcedDampedOscillator_input_function,
   ForcedDampedOscillator_input_function_init,
   ForcedDampedOscillator_input_function_updateStartValues,
   ForcedDampedOscillator_data_function,
   ForcedDampedOscillator_output_function,
   ForcedDampedOscillator_setc_function,
   ForcedDampedOscillator_setb_function,
   ForcedDampedOscillator_function_storeDelayed,
   ForcedDampedOscillator_function_storeSpatialDistribution,
   ForcedDampedOscillator_function_initSpatialDistribution,
   ForcedDampedOscillator_updateBoundVariableAttributes,
   ForcedDampedOscillator_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   ForcedDampedOscillator_functionRemovedInitialEquations,
   ForcedDampedOscillator_updateBoundParameters,
   ForcedDampedOscillator_checkForAsserts,
   ForcedDampedOscillator_function_ZeroCrossingsEquations,
   ForcedDampedOscillator_function_ZeroCrossings,
   ForcedDampedOscillator_function_updateRelations,
   ForcedDampedOscillator_zeroCrossingDescription,
   ForcedDampedOscillator_relationDescription,
   ForcedDampedOscillator_function_initSample,
   ForcedDampedOscillator_INDEX_JAC_A,
   ForcedDampedOscillator_INDEX_JAC_B,
   ForcedDampedOscillator_INDEX_JAC_C,
   ForcedDampedOscillator_INDEX_JAC_D,
   ForcedDampedOscillator_INDEX_JAC_F,
   ForcedDampedOscillator_INDEX_JAC_H,
   ForcedDampedOscillator_initialAnalyticJacobianA,
   ForcedDampedOscillator_initialAnalyticJacobianB,
   ForcedDampedOscillator_initialAnalyticJacobianC,
   ForcedDampedOscillator_initialAnalyticJacobianD,
   ForcedDampedOscillator_initialAnalyticJacobianF,
   ForcedDampedOscillator_initialAnalyticJacobianH,
   ForcedDampedOscillator_functionJacA_column,
   ForcedDampedOscillator_functionJacB_column,
   ForcedDampedOscillator_functionJacC_column,
   ForcedDampedOscillator_functionJacD_column,
   ForcedDampedOscillator_functionJacF_column,
   ForcedDampedOscillator_functionJacH_column,
   ForcedDampedOscillator_linear_model_frame,
   ForcedDampedOscillator_linear_model_datarecovery_frame,
   ForcedDampedOscillator_mayer,
   ForcedDampedOscillator_lagrange,
   ForcedDampedOscillator_pickUpBoundsForInputsInOptimization,
   ForcedDampedOscillator_setInputData,
   ForcedDampedOscillator_getTimeGrid,
   ForcedDampedOscillator_symbolicInlineSystem,
   ForcedDampedOscillator_function_initSynchronous,
   ForcedDampedOscillator_function_updateSynchronous,
   ForcedDampedOscillator_function_equationsSynchronous,
   ForcedDampedOscillator_inputNames,
   ForcedDampedOscillator_dataReconciliationInputNames,
   ForcedDampedOscillator_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "ForcedDampedOscillator"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/Desktop/AFM/cases/20260410_132426_ForcedDampedOscillator/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,22,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,75,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void ForcedDampedOscillator_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &ForcedDampedOscillator_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "ForcedDampedOscillator";
  data->modelData->modelFilePrefix = "ForcedDampedOscillator";
  data->modelData->modelFileName = "ForcedDampedOscillator.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/cases/20260410_132426_ForcedDampedOscillator/model";
  data->modelData->modelGUID = "{7a3fa27d-9974-4f74-81c8-b6704b65bbe5}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "ForcedDampedOscillator_init.c"
    ;
  static const char contents_info[] =
    #include "ForcedDampedOscillator_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "ForcedDampedOscillator_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "ForcedDampedOscillator_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "ForcedDampedOscillator_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 14;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 10;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 0;
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
  
    ForcedDampedOscillator_setupDataStruc(&data, threadData);
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


