/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "SolarCollectorLoopEnhanced_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation SolarCollectorLoopEnhanced_performSimulation
#define prefixedName_updateContinuousSystem SolarCollectorLoopEnhanced_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation SolarCollectorLoopEnhanced_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int SolarCollectorLoopEnhanced_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SolarCollectorLoopEnhanced_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SolarCollectorLoopEnhanced_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SolarCollectorLoopEnhanced_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SolarCollectorLoopEnhanced_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int SolarCollectorLoopEnhanced_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SolarCollectorLoopEnhanced_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SolarCollectorLoopEnhanced_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SolarCollectorLoopEnhanced_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SolarCollectorLoopEnhanced_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 8
type: SIMPLE_ASSIGN
collector_power_density = Q_solar / A_collector
*/
void SolarCollectorLoopEnhanced_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* collector_power_density variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* Q_solar variable */),(data->simulationInfo->realParameter[0] /* A_collector PARAM */),"A_collector",equationIndexes);
  TRACE_POP
}
/*
equation index: 9
type: SIMPLE_ASSIGN
Q_loss = h_loss * (-273.15 + T_water - T_ambient)
*/
void SolarCollectorLoopEnhanced_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* Q_loss variable */) = ((data->simulationInfo->realParameter[5] /* h_loss PARAM */)) * (-273.15 + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_water STATE(1) */) - (data->simulationInfo->realParameter[2] /* T_ambient PARAM */));
  TRACE_POP
}
/*
equation index: 10
type: SIMPLE_ASSIGN
$DER.T_water = (Q_solar - Q_loss) / (m_water * cp_water)
*/
void SolarCollectorLoopEnhanced_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* der(T_water) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* Q_solar variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* Q_loss variable */),((data->simulationInfo->realParameter[6] /* m_water PARAM */)) * ((data->simulationInfo->realParameter[3] /* cp_water PARAM */)),"m_water * cp_water",equationIndexes);
  TRACE_POP
}
/*
equation index: 11
type: SIMPLE_ASSIGN
T_water_C = -273.15 + T_water
*/
void SolarCollectorLoopEnhanced_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_water_C variable */) = -273.15 + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_water STATE(1) */);
  TRACE_POP
}

OMC_DISABLE_OPT
int SolarCollectorLoopEnhanced_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  SolarCollectorLoopEnhanced_functionLocalKnownVars(data, threadData);
  SolarCollectorLoopEnhanced_eqFunction_8(data, threadData);

  SolarCollectorLoopEnhanced_eqFunction_9(data, threadData);

  SolarCollectorLoopEnhanced_eqFunction_10(data, threadData);

  SolarCollectorLoopEnhanced_eqFunction_11(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int SolarCollectorLoopEnhanced_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void SolarCollectorLoopEnhanced_eqFunction_9(DATA* data, threadData_t *threadData);
extern void SolarCollectorLoopEnhanced_eqFunction_10(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[2])(DATA*, threadData_t*) = {
    SolarCollectorLoopEnhanced_eqFunction_9,
    SolarCollectorLoopEnhanced_eqFunction_10
  };
  
  static const int eqIndices[2] = {
    9,
    10
  };
  
  for (id = 0; id < 2; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int SolarCollectorLoopEnhanced_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  SolarCollectorLoopEnhanced_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void SolarCollectorLoopEnhanced_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(T_water) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_loss variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_solar variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_water_C variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* collector_power_density variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* p_system_bar variable */
  
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

#include "SolarCollectorLoopEnhanced_12jac.h"
#include "SolarCollectorLoopEnhanced_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks SolarCollectorLoopEnhanced_callback = {
   (int (*)(DATA *, threadData_t *, void *)) SolarCollectorLoopEnhanced_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) SolarCollectorLoopEnhanced_performQSSSimulation,    /* performQSSSimulation */
   SolarCollectorLoopEnhanced_updateContinuousSystem,    /* updateContinuousSystem */
   SolarCollectorLoopEnhanced_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   SolarCollectorLoopEnhanced_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   SolarCollectorLoopEnhanced_initializeDAEmodeData,
   SolarCollectorLoopEnhanced_computeVarIndices,
   SolarCollectorLoopEnhanced_functionODE,
   SolarCollectorLoopEnhanced_functionAlgebraics,
   SolarCollectorLoopEnhanced_functionDAE,
   SolarCollectorLoopEnhanced_functionLocalKnownVars,
   SolarCollectorLoopEnhanced_input_function,
   SolarCollectorLoopEnhanced_input_function_init,
   SolarCollectorLoopEnhanced_input_function_updateStartValues,
   SolarCollectorLoopEnhanced_data_function,
   SolarCollectorLoopEnhanced_output_function,
   SolarCollectorLoopEnhanced_setc_function,
   SolarCollectorLoopEnhanced_setb_function,
   SolarCollectorLoopEnhanced_function_storeDelayed,
   SolarCollectorLoopEnhanced_function_storeSpatialDistribution,
   SolarCollectorLoopEnhanced_function_initSpatialDistribution,
   SolarCollectorLoopEnhanced_updateBoundVariableAttributes,
   SolarCollectorLoopEnhanced_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   SolarCollectorLoopEnhanced_functionRemovedInitialEquations,
   SolarCollectorLoopEnhanced_updateBoundParameters,
   SolarCollectorLoopEnhanced_checkForAsserts,
   SolarCollectorLoopEnhanced_function_ZeroCrossingsEquations,
   SolarCollectorLoopEnhanced_function_ZeroCrossings,
   SolarCollectorLoopEnhanced_function_updateRelations,
   SolarCollectorLoopEnhanced_zeroCrossingDescription,
   SolarCollectorLoopEnhanced_relationDescription,
   SolarCollectorLoopEnhanced_function_initSample,
   SolarCollectorLoopEnhanced_INDEX_JAC_A,
   SolarCollectorLoopEnhanced_INDEX_JAC_B,
   SolarCollectorLoopEnhanced_INDEX_JAC_C,
   SolarCollectorLoopEnhanced_INDEX_JAC_D,
   SolarCollectorLoopEnhanced_INDEX_JAC_F,
   SolarCollectorLoopEnhanced_INDEX_JAC_H,
   SolarCollectorLoopEnhanced_initialAnalyticJacobianA,
   SolarCollectorLoopEnhanced_initialAnalyticJacobianB,
   SolarCollectorLoopEnhanced_initialAnalyticJacobianC,
   SolarCollectorLoopEnhanced_initialAnalyticJacobianD,
   SolarCollectorLoopEnhanced_initialAnalyticJacobianF,
   SolarCollectorLoopEnhanced_initialAnalyticJacobianH,
   SolarCollectorLoopEnhanced_functionJacA_column,
   SolarCollectorLoopEnhanced_functionJacB_column,
   SolarCollectorLoopEnhanced_functionJacC_column,
   SolarCollectorLoopEnhanced_functionJacD_column,
   SolarCollectorLoopEnhanced_functionJacF_column,
   SolarCollectorLoopEnhanced_functionJacH_column,
   SolarCollectorLoopEnhanced_linear_model_frame,
   SolarCollectorLoopEnhanced_linear_model_datarecovery_frame,
   SolarCollectorLoopEnhanced_mayer,
   SolarCollectorLoopEnhanced_lagrange,
   SolarCollectorLoopEnhanced_pickUpBoundsForInputsInOptimization,
   SolarCollectorLoopEnhanced_setInputData,
   SolarCollectorLoopEnhanced_getTimeGrid,
   SolarCollectorLoopEnhanced_symbolicInlineSystem,
   SolarCollectorLoopEnhanced_function_initSynchronous,
   SolarCollectorLoopEnhanced_function_updateSynchronous,
   SolarCollectorLoopEnhanced_function_equationsSynchronous,
   SolarCollectorLoopEnhanced_inputNames,
   SolarCollectorLoopEnhanced_dataReconciliationInputNames,
   SolarCollectorLoopEnhanced_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "SolarCollectorLoopEnhanced"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/Desktop/实验组5/cases/20260427_161332_SolarCollectorLoopEnhanced/build/src"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,26,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,90,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void SolarCollectorLoopEnhanced_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &SolarCollectorLoopEnhanced_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "SolarCollectorLoopEnhanced";
  data->modelData->modelFilePrefix = "SolarCollectorLoopEnhanced";
  data->modelData->modelFileName = "SolarCollectorLoopEnhanced.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/实验组5/cases/20260427_161332_SolarCollectorLoopEnhanced/build/src";
  data->modelData->modelGUID = "{670dd641-afb2-474e-b716-bad446265ff9}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "SolarCollectorLoopEnhanced_init.c"
    ;
  static const char contents_info[] =
    #include "SolarCollectorLoopEnhanced_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "SolarCollectorLoopEnhanced_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "SolarCollectorLoopEnhanced_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "SolarCollectorLoopEnhanced_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 1;
  data->modelData->nVariablesRealArray = 7;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 8;
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
  
    SolarCollectorLoopEnhanced_setupDataStruc(&data, threadData);
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


