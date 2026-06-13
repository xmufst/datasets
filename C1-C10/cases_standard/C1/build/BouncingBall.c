/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "BouncingBall_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation BouncingBall_performSimulation
#define prefixedName_updateContinuousSystem BouncingBall_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation BouncingBall_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int BouncingBall_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BouncingBall_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BouncingBall_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BouncingBall_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BouncingBall_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int BouncingBall_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BouncingBall_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BouncingBall_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BouncingBall_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BouncingBall_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 7
type: SIMPLE_ASSIGN
$whenCondition1 = h <= 0.0
*/
void BouncingBall_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp1 = 1.0;
  tmp2 = 0.0;
  relationhysteresis(data, &tmp0, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1,v) */), 0.0, tmp1, tmp2, 2, LessEq, LessEqZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = tmp0;
  TRACE_POP
}
/*
equation index: 8
type: SIMPLE_ASSIGN
$DER.v = if h > 0.0 or v > 0.0 then -g else 0.0
*/
void BouncingBall_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  tmp4 = 1.0;
  tmp5 = 0.0;
  relationhysteresis(data, &tmp3, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1,v) */), 0.0, tmp4, tmp5, 0, Greater, GreaterZC);
  tmp7 = 1.0;
  tmp8 = 0.0;
  relationhysteresis(data, &tmp6, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1) */), 0.0, tmp7, tmp8, 1, Greater, GreaterZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(v) STATE_DER */) = ((tmp3 || tmp6)?(-(data->simulationInfo->realParameter[1] /* g PARAM */)):0.0);
  TRACE_POP
}
/*
equation index: 9
type: SIMPLE_ASSIGN
$DER.h = v
*/
void BouncingBall_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(h) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1) */);
  TRACE_POP
}
/*
equation index: 11
type: WHEN

when {$whenCondition1} then
  reinit(h,  0.0);
end when;
*/
void BouncingBall_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1,v) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit h = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1,v) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 10
type: WHEN

when {$whenCondition1} then
  reinit(v,  if pre(v) < (-v_threshold) then (-e) * pre(v) else 0.0);
end when;
*/
void BouncingBall_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  modelica_boolean tmp9;
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    tmp9 = Less((data->simulationInfo->realVarsPre[1] /* v STATE(1) */),(-(data->simulationInfo->realParameter[4] /* v_threshold PARAM */)));
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1) */) = (tmp9?((-(data->simulationInfo->realParameter[0] /* e PARAM */))) * ((data->simulationInfo->realVarsPre[1] /* v STATE(1) */)):0.0);
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit v = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int BouncingBall_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  BouncingBall_functionLocalKnownVars(data, threadData);
  BouncingBall_eqFunction_7(data, threadData);

  BouncingBall_eqFunction_8(data, threadData);

  BouncingBall_eqFunction_9(data, threadData);

  BouncingBall_eqFunction_11(data, threadData);

  BouncingBall_eqFunction_10(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int BouncingBall_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void BouncingBall_eqFunction_8(DATA* data, threadData_t *threadData);
extern void BouncingBall_eqFunction_9(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[2])(DATA*, threadData_t*) = {
    BouncingBall_eqFunction_8,
    BouncingBall_eqFunction_9
  };
  
  static const int eqIndices[2] = {
    8,
    9
  };
  
  for (id = 0; id < 2; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int BouncingBall_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  BouncingBall_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void BouncingBall_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* h STATE(1,v) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* v STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(h) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(v) STATE_DER */
  
  /* algVars */
  
  /* discreteAlgVars */
  
  /* realOptimizeConstraintsVars */
  
  /* realOptimizeFinalConstraintsVars */
  
  
  /* intAlgVars */
  
  /* boolAlgVars */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition1 DISCRETE */
  
  /* stringAlgVars */
  
  TRACE_POP
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "BouncingBall_12jac.h"
#include "BouncingBall_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks BouncingBall_callback = {
   (int (*)(DATA *, threadData_t *, void *)) BouncingBall_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) BouncingBall_performQSSSimulation,    /* performQSSSimulation */
   BouncingBall_updateContinuousSystem,    /* updateContinuousSystem */
   BouncingBall_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   BouncingBall_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   BouncingBall_initializeDAEmodeData,
   BouncingBall_computeVarIndices,
   BouncingBall_functionODE,
   BouncingBall_functionAlgebraics,
   BouncingBall_functionDAE,
   BouncingBall_functionLocalKnownVars,
   BouncingBall_input_function,
   BouncingBall_input_function_init,
   BouncingBall_input_function_updateStartValues,
   BouncingBall_data_function,
   BouncingBall_output_function,
   BouncingBall_setc_function,
   BouncingBall_setb_function,
   BouncingBall_function_storeDelayed,
   BouncingBall_function_storeSpatialDistribution,
   BouncingBall_function_initSpatialDistribution,
   BouncingBall_updateBoundVariableAttributes,
   BouncingBall_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   BouncingBall_functionRemovedInitialEquations,
   BouncingBall_updateBoundParameters,
   BouncingBall_checkForAsserts,
   BouncingBall_function_ZeroCrossingsEquations,
   BouncingBall_function_ZeroCrossings,
   BouncingBall_function_updateRelations,
   BouncingBall_zeroCrossingDescription,
   BouncingBall_relationDescription,
   BouncingBall_function_initSample,
   BouncingBall_INDEX_JAC_A,
   BouncingBall_INDEX_JAC_B,
   BouncingBall_INDEX_JAC_C,
   BouncingBall_INDEX_JAC_D,
   BouncingBall_INDEX_JAC_F,
   BouncingBall_INDEX_JAC_H,
   BouncingBall_initialAnalyticJacobianA,
   BouncingBall_initialAnalyticJacobianB,
   BouncingBall_initialAnalyticJacobianC,
   BouncingBall_initialAnalyticJacobianD,
   BouncingBall_initialAnalyticJacobianF,
   BouncingBall_initialAnalyticJacobianH,
   BouncingBall_functionJacA_column,
   BouncingBall_functionJacB_column,
   BouncingBall_functionJacC_column,
   BouncingBall_functionJacD_column,
   BouncingBall_functionJacF_column,
   BouncingBall_functionJacH_column,
   BouncingBall_linear_model_frame,
   BouncingBall_linear_model_datarecovery_frame,
   BouncingBall_mayer,
   BouncingBall_lagrange,
   BouncingBall_pickUpBoundsForInputsInOptimization,
   BouncingBall_setInputData,
   BouncingBall_getTimeGrid,
   BouncingBall_symbolicInlineSystem,
   BouncingBall_function_initSynchronous,
   BouncingBall_function_updateSynchronous,
   BouncingBall_function_equationsSynchronous,
   BouncingBall_inputNames,
   BouncingBall_dataReconciliationInputNames,
   BouncingBall_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "BouncingBall"
#define _OMC_LIT_RESOURCE_0_dir_data "G:/数据/第一类/C1"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,12,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,22,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void BouncingBall_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &BouncingBall_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "BouncingBall";
  data->modelData->modelFilePrefix = "BouncingBall";
  data->modelData->modelFileName = "BouncingBall.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "G:/数据/第一类/C1";
  data->modelData->modelGUID = "{cafdad42-e556-4e12-9d28-332a4c688a68}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "BouncingBall_init.c"
    ;
  static const char contents_info[] =
    #include "BouncingBall_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "BouncingBall_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "BouncingBall_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "BouncingBall_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 4;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 1;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 5;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 2;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 3;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 14;
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
  
    BouncingBall_setupDataStruc(&data, threadData);
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


