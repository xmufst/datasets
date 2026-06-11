/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "GravityTank_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation GravityTank_performSimulation
#define prefixedName_updateContinuousSystem GravityTank_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation GravityTank_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int GravityTank_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int GravityTank_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int GravityTank_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int GravityTank_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int GravityTank_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int GravityTank_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int GravityTank_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int GravityTank_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int GravityTank_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int GravityTank_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 7
type: SIMPLE_ASSIGN
V_liquid = A_tank * h
*/
void GravityTank_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* V_liquid variable */) = ((data->simulationInfo->realParameter[1] /* A_tank PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1) */));
  TRACE_POP
}
/*
equation index: 8
type: SIMPLE_ASSIGN
v_out = sqrt(2.0 * g * max(h, 0.0))
*/
void GravityTank_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  modelica_real tmp0;
  tmp0 = ((2.0) * ((data->simulationInfo->realParameter[4] /* g PARAM */))) * (fmax((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1) */),0.0));
  if(!(tmp0 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(2.0 * g * max(h, 0.0)) was %g should be >= 0", tmp0);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* v_out variable */) = sqrt(tmp0);
  TRACE_POP
}
/*
equation index: 9
type: SIMPLE_ASSIGN
Q_out = Cd * A_orifice * v_out
*/
void GravityTank_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* Q_out variable */) = ((data->simulationInfo->realParameter[2] /* Cd PARAM */)) * (((data->simulationInfo->realParameter[0] /* A_orifice PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* v_out variable */)));
  TRACE_POP
}
/*
equation index: 10
type: SIMPLE_ASSIGN
Q_net = Q_in - Q_out
*/
void GravityTank_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* Q_net variable */) = (data->simulationInfo->realParameter[3] /* Q_in PARAM */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* Q_out variable */);
  TRACE_POP
}
/*
equation index: 11
type: SIMPLE_ASSIGN
$DER.h = Q_net / A_tank
*/
void GravityTank_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* der(h) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* Q_net variable */),(data->simulationInfo->realParameter[1] /* A_tank PARAM */),"A_tank",equationIndexes);
  TRACE_POP
}

OMC_DISABLE_OPT
int GravityTank_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  GravityTank_functionLocalKnownVars(data, threadData);
  GravityTank_eqFunction_7(data, threadData);

  GravityTank_eqFunction_8(data, threadData);

  GravityTank_eqFunction_9(data, threadData);

  GravityTank_eqFunction_10(data, threadData);

  GravityTank_eqFunction_11(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int GravityTank_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void GravityTank_eqFunction_8(DATA* data, threadData_t *threadData);
extern void GravityTank_eqFunction_9(DATA* data, threadData_t *threadData);
extern void GravityTank_eqFunction_10(DATA* data, threadData_t *threadData);
extern void GravityTank_eqFunction_11(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[4])(DATA*, threadData_t*) = {
    GravityTank_eqFunction_8,
    GravityTank_eqFunction_9,
    GravityTank_eqFunction_10,
    GravityTank_eqFunction_11
  };
  
  static const int eqIndices[4] = {
    8,
    9,
    10,
    11
  };
  
  for (id = 0; id < 4; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int GravityTank_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  GravityTank_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void GravityTank_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* h STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(h) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_net variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_out variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* V_liquid variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* v_out variable */
  
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

#include "GravityTank_12jac.h"
#include "GravityTank_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks GravityTank_callback = {
   (int (*)(DATA *, threadData_t *, void *)) GravityTank_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) GravityTank_performQSSSimulation,    /* performQSSSimulation */
   GravityTank_updateContinuousSystem,    /* updateContinuousSystem */
   GravityTank_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   GravityTank_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   GravityTank_initializeDAEmodeData,
   GravityTank_computeVarIndices,
   GravityTank_functionODE,
   GravityTank_functionAlgebraics,
   GravityTank_functionDAE,
   GravityTank_functionLocalKnownVars,
   GravityTank_input_function,
   GravityTank_input_function_init,
   GravityTank_input_function_updateStartValues,
   GravityTank_data_function,
   GravityTank_output_function,
   GravityTank_setc_function,
   GravityTank_setb_function,
   GravityTank_function_storeDelayed,
   GravityTank_function_storeSpatialDistribution,
   GravityTank_function_initSpatialDistribution,
   GravityTank_updateBoundVariableAttributes,
   GravityTank_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   GravityTank_functionRemovedInitialEquations,
   GravityTank_updateBoundParameters,
   GravityTank_checkForAsserts,
   GravityTank_function_ZeroCrossingsEquations,
   GravityTank_function_ZeroCrossings,
   GravityTank_function_updateRelations,
   GravityTank_zeroCrossingDescription,
   GravityTank_relationDescription,
   GravityTank_function_initSample,
   GravityTank_INDEX_JAC_A,
   GravityTank_INDEX_JAC_B,
   GravityTank_INDEX_JAC_C,
   GravityTank_INDEX_JAC_D,
   GravityTank_INDEX_JAC_F,
   GravityTank_INDEX_JAC_H,
   GravityTank_initialAnalyticJacobianA,
   GravityTank_initialAnalyticJacobianB,
   GravityTank_initialAnalyticJacobianC,
   GravityTank_initialAnalyticJacobianD,
   GravityTank_initialAnalyticJacobianF,
   GravityTank_initialAnalyticJacobianH,
   GravityTank_functionJacA_column,
   GravityTank_functionJacB_column,
   GravityTank_functionJacC_column,
   GravityTank_functionJacD_column,
   GravityTank_functionJacF_column,
   GravityTank_functionJacH_column,
   GravityTank_linear_model_frame,
   GravityTank_linear_model_datarecovery_frame,
   GravityTank_mayer,
   GravityTank_lagrange,
   GravityTank_pickUpBoundsForInputsInOptimization,
   GravityTank_setInputData,
   GravityTank_getTimeGrid,
   GravityTank_symbolicInlineSystem,
   GravityTank_function_initSynchronous,
   GravityTank_function_updateSynchronous,
   GravityTank_function_equationsSynchronous,
   GravityTank_inputNames,
   GravityTank_dataReconciliationInputNames,
   GravityTank_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "GravityTank"
#define _OMC_LIT_RESOURCE_0_dir_data "G:/数据/第一类/C8"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,11,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,22,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void GravityTank_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &GravityTank_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "GravityTank";
  data->modelData->modelFilePrefix = "GravityTank";
  data->modelData->modelFileName = "GravityTank.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "G:/数据/第一类/C8";
  data->modelData->modelGUID = "{cd5c7de2-7671-440b-90f3-047afcd5e31b}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "GravityTank_init.c"
    ;
  static const char contents_info[] =
    #include "GravityTank_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "GravityTank_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "GravityTank_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "GravityTank_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 1;
  data->modelData->nVariablesRealArray = 6;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 6;
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
  data->modelData->modelDataXml.nEquations = 13;
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
  
    GravityTank_setupDataStruc(&data, threadData);
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


