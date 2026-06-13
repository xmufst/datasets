/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "SimplePendulum_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation SimplePendulum_performSimulation
#define prefixedName_updateContinuousSystem SimplePendulum_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation SimplePendulum_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int SimplePendulum_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SimplePendulum_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SimplePendulum_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SimplePendulum_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SimplePendulum_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int SimplePendulum_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SimplePendulum_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SimplePendulum_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SimplePendulum_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SimplePendulum_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 10
type: SIMPLE_ASSIGN
$cse1 = sin(theta)
*/
void SimplePendulum_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* $cse1 variable */) = sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* theta STATE(1,omega) */));
  TRACE_POP
}
/*
equation index: 11
type: SIMPLE_ASSIGN
$cse2 = cos(theta)
*/
void SimplePendulum_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* $cse2 variable */) = cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* theta STATE(1,omega) */));
  TRACE_POP
}
/*
equation index: 12
type: SIMPLE_ASSIGN
E_kinetic = 0.5 * m * (L * omega) ^ 2.0
*/
void SimplePendulum_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  modelica_real tmp0;
  tmp0 = ((data->simulationInfo->realParameter[0] /* L PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* omega STATE(1) */));
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* E_kinetic variable */) = (0.5) * (((data->simulationInfo->realParameter[2] /* m PARAM */)) * ((tmp0 * tmp0)));
  TRACE_POP
}
/*
equation index: 13
type: SIMPLE_ASSIGN
y = (-L) * $cse2
*/
void SimplePendulum_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* y variable */) = ((-(data->simulationInfo->realParameter[0] /* L PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* $cse2 variable */));
  TRACE_POP
}
/*
equation index: 14
type: SIMPLE_ASSIGN
E_potential = m * g * (L + y)
*/
void SimplePendulum_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* E_potential variable */) = ((data->simulationInfo->realParameter[2] /* m PARAM */)) * (((data->simulationInfo->realParameter[1] /* g PARAM */)) * ((data->simulationInfo->realParameter[0] /* L PARAM */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* y variable */)));
  TRACE_POP
}
/*
equation index: 15
type: SIMPLE_ASSIGN
E_total = E_kinetic + E_potential
*/
void SimplePendulum_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* E_total variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* E_kinetic variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* E_potential variable */);
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
x = L * $cse1
*/
void SimplePendulum_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* x variable */) = ((data->simulationInfo->realParameter[0] /* L PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* $cse1 variable */));
  TRACE_POP
}
/*
equation index: 17
type: SIMPLE_ASSIGN
$DER.omega = (-$cse1) * g / L
*/
void SimplePendulum_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(omega) STATE_DER */) = ((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* $cse1 variable */))) * (DIVISION_SIM((data->simulationInfo->realParameter[1] /* g PARAM */),(data->simulationInfo->realParameter[0] /* L PARAM */),"L",equationIndexes));
  TRACE_POP
}
/*
equation index: 18
type: SIMPLE_ASSIGN
$DER.theta = omega
*/
void SimplePendulum_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(theta) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* omega STATE(1) */);
  TRACE_POP
}

OMC_DISABLE_OPT
int SimplePendulum_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  SimplePendulum_functionLocalKnownVars(data, threadData);
  SimplePendulum_eqFunction_10(data, threadData);

  SimplePendulum_eqFunction_11(data, threadData);

  SimplePendulum_eqFunction_12(data, threadData);

  SimplePendulum_eqFunction_13(data, threadData);

  SimplePendulum_eqFunction_14(data, threadData);

  SimplePendulum_eqFunction_15(data, threadData);

  SimplePendulum_eqFunction_16(data, threadData);

  SimplePendulum_eqFunction_17(data, threadData);

  SimplePendulum_eqFunction_18(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int SimplePendulum_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void SimplePendulum_eqFunction_10(DATA* data, threadData_t *threadData);
extern void SimplePendulum_eqFunction_17(DATA* data, threadData_t *threadData);
extern void SimplePendulum_eqFunction_18(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[3])(DATA*, threadData_t*) = {
    SimplePendulum_eqFunction_10,
    SimplePendulum_eqFunction_17,
    SimplePendulum_eqFunction_18
  };
  
  static const int eqIndices[3] = {
    10,
    17,
    18
  };
  
  for (id = 0; id < 3; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int SimplePendulum_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  SimplePendulum_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void SimplePendulum_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* theta STATE(1,omega) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(omega) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(theta) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_kinetic variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_potential variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_total variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* x variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* y variable */
  
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

#include "SimplePendulum_12jac.h"
#include "SimplePendulum_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks SimplePendulum_callback = {
   (int (*)(DATA *, threadData_t *, void *)) SimplePendulum_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) SimplePendulum_performQSSSimulation,    /* performQSSSimulation */
   SimplePendulum_updateContinuousSystem,    /* updateContinuousSystem */
   SimplePendulum_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   SimplePendulum_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   SimplePendulum_initializeDAEmodeData,
   SimplePendulum_computeVarIndices,
   SimplePendulum_functionODE,
   SimplePendulum_functionAlgebraics,
   SimplePendulum_functionDAE,
   SimplePendulum_functionLocalKnownVars,
   SimplePendulum_input_function,
   SimplePendulum_input_function_init,
   SimplePendulum_input_function_updateStartValues,
   SimplePendulum_data_function,
   SimplePendulum_output_function,
   SimplePendulum_setc_function,
   SimplePendulum_setb_function,
   SimplePendulum_function_storeDelayed,
   SimplePendulum_function_storeSpatialDistribution,
   SimplePendulum_function_initSpatialDistribution,
   SimplePendulum_updateBoundVariableAttributes,
   SimplePendulum_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   SimplePendulum_functionRemovedInitialEquations,
   SimplePendulum_updateBoundParameters,
   SimplePendulum_checkForAsserts,
   SimplePendulum_function_ZeroCrossingsEquations,
   SimplePendulum_function_ZeroCrossings,
   SimplePendulum_function_updateRelations,
   SimplePendulum_zeroCrossingDescription,
   SimplePendulum_relationDescription,
   SimplePendulum_function_initSample,
   SimplePendulum_INDEX_JAC_A,
   SimplePendulum_INDEX_JAC_B,
   SimplePendulum_INDEX_JAC_C,
   SimplePendulum_INDEX_JAC_D,
   SimplePendulum_INDEX_JAC_F,
   SimplePendulum_INDEX_JAC_H,
   SimplePendulum_initialAnalyticJacobianA,
   SimplePendulum_initialAnalyticJacobianB,
   SimplePendulum_initialAnalyticJacobianC,
   SimplePendulum_initialAnalyticJacobianD,
   SimplePendulum_initialAnalyticJacobianF,
   SimplePendulum_initialAnalyticJacobianH,
   SimplePendulum_functionJacA_column,
   SimplePendulum_functionJacB_column,
   SimplePendulum_functionJacC_column,
   SimplePendulum_functionJacD_column,
   SimplePendulum_functionJacF_column,
   SimplePendulum_functionJacH_column,
   SimplePendulum_linear_model_frame,
   SimplePendulum_linear_model_datarecovery_frame,
   SimplePendulum_mayer,
   SimplePendulum_lagrange,
   SimplePendulum_pickUpBoundsForInputsInOptimization,
   SimplePendulum_setInputData,
   SimplePendulum_getTimeGrid,
   SimplePendulum_symbolicInlineSystem,
   SimplePendulum_function_initSynchronous,
   SimplePendulum_function_updateSynchronous,
   SimplePendulum_function_equationsSynchronous,
   SimplePendulum_inputNames,
   SimplePendulum_dataReconciliationInputNames,
   SimplePendulum_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "SimplePendulum"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/Desktop/AFM/cases/20260410_123710_SimplePendulum/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,14,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,67,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void SimplePendulum_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &SimplePendulum_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "SimplePendulum";
  data->modelData->modelFilePrefix = "SimplePendulum";
  data->modelData->modelFileName = "SimplePendulum.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/cases/20260410_123710_SimplePendulum/model";
  data->modelData->modelGUID = "{e50b9e9c-44e0-4a94-82a2-7037eec50134}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "SimplePendulum_init.c"
    ;
  static const char contents_info[] =
    #include "SimplePendulum_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "SimplePendulum_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "SimplePendulum_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "SimplePendulum_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 11;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
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
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 21;
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
  
    SimplePendulum_setupDataStruc(&data, threadData);
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


