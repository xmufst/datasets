/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "FurnaceFeedforward_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation FurnaceFeedforward_performSimulation
#define prefixedName_updateContinuousSystem FurnaceFeedforward_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation FurnaceFeedforward_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int FurnaceFeedforward_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FurnaceFeedforward_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FurnaceFeedforward_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FurnaceFeedforward_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FurnaceFeedforward_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int FurnaceFeedforward_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FurnaceFeedforward_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FurnaceFeedforward_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FurnaceFeedforward_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FurnaceFeedforward_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 7
type: SIMPLE_ASSIGN
Q_disturbance = disturbance.offset + (if time < disturbance.startTime then 0.0 else disturbance.height)
*/
void FurnaceFeedforward_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[15] /* disturbance.startTime PARAM */));
  relationhysteresis(data, &tmp0, data->localData[0]->timeValue, (data->simulationInfo->realParameter[15] /* disturbance.startTime PARAM */), tmp1, tmp2, 0, Less, LessZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* Q_disturbance variable */) = (data->simulationInfo->realParameter[14] /* disturbance.offset PARAM */) + (tmp0?0.0:(data->simulationInfo->realParameter[13] /* disturbance.height PARAM */));
  TRACE_POP
}
/*
equation index: 8
type: SIMPLE_ASSIGN
u_ff = feedforward_gain.k * Q_disturbance
*/
void FurnaceFeedforward_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* u_ff variable */) = ((data->simulationInfo->realParameter[16] /* feedforward_gain.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* Q_disturbance variable */));
  TRACE_POP
}
/*
equation index: 9
type: SIMPLE_ASSIGN
Q_heater = add_signals.k1 * Q_steady.k + add_signals.k2 * u_ff
*/
void FurnaceFeedforward_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* Q_heater variable */) = ((data->simulationInfo->realParameter[10] /* add_signals.k1 PARAM */)) * ((data->simulationInfo->realParameter[5] /* Q_steady.k PARAM */)) + ((data->simulationInfo->realParameter[11] /* add_signals.k2 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* u_ff variable */));
  TRACE_POP
}
/*
equation index: 10
type: SIMPLE_ASSIGN
Q_loss = UA * (T - T_amb)
*/
void FurnaceFeedforward_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* Q_loss variable */) = ((data->simulationInfo->realParameter[9] /* UA PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */) - (data->simulationInfo->realParameter[8] /* T_amb PARAM */));
  TRACE_POP
}
/*
equation index: 11
type: SIMPLE_ASSIGN
$DER.T = (Q_heater + (-Q_loss) - Q_disturbance) / C_furnace
*/
void FurnaceFeedforward_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* der(T) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* Q_heater variable */) + (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* Q_loss variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* Q_disturbance variable */),(data->simulationInfo->realParameter[0] /* C_furnace PARAM */),"C_furnace",equationIndexes);
  TRACE_POP
}

OMC_DISABLE_OPT
int FurnaceFeedforward_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  FurnaceFeedforward_functionLocalKnownVars(data, threadData);
  FurnaceFeedforward_eqFunction_7(data, threadData);

  FurnaceFeedforward_eqFunction_8(data, threadData);

  FurnaceFeedforward_eqFunction_9(data, threadData);

  FurnaceFeedforward_eqFunction_10(data, threadData);

  FurnaceFeedforward_eqFunction_11(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int FurnaceFeedforward_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void FurnaceFeedforward_eqFunction_7(DATA* data, threadData_t *threadData);
extern void FurnaceFeedforward_eqFunction_8(DATA* data, threadData_t *threadData);
extern void FurnaceFeedforward_eqFunction_9(DATA* data, threadData_t *threadData);
extern void FurnaceFeedforward_eqFunction_10(DATA* data, threadData_t *threadData);
extern void FurnaceFeedforward_eqFunction_11(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[5])(DATA*, threadData_t*) = {
    FurnaceFeedforward_eqFunction_7,
    FurnaceFeedforward_eqFunction_8,
    FurnaceFeedforward_eqFunction_9,
    FurnaceFeedforward_eqFunction_10,
    FurnaceFeedforward_eqFunction_11
  };
  
  static const int eqIndices[5] = {
    7,
    8,
    9,
    10,
    11
  };
  
  for (id = 0; id < 5; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int FurnaceFeedforward_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  FurnaceFeedforward_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void FurnaceFeedforward_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(T) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_disturbance variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_heater variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_loss variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* u_ff variable */
  
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

#include "FurnaceFeedforward_12jac.h"
#include "FurnaceFeedforward_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks FurnaceFeedforward_callback = {
   (int (*)(DATA *, threadData_t *, void *)) FurnaceFeedforward_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) FurnaceFeedforward_performQSSSimulation,    /* performQSSSimulation */
   FurnaceFeedforward_updateContinuousSystem,    /* updateContinuousSystem */
   FurnaceFeedforward_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   FurnaceFeedforward_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   FurnaceFeedforward_initializeDAEmodeData,
   FurnaceFeedforward_computeVarIndices,
   FurnaceFeedforward_functionODE,
   FurnaceFeedforward_functionAlgebraics,
   FurnaceFeedforward_functionDAE,
   FurnaceFeedforward_functionLocalKnownVars,
   FurnaceFeedforward_input_function,
   FurnaceFeedforward_input_function_init,
   FurnaceFeedforward_input_function_updateStartValues,
   FurnaceFeedforward_data_function,
   FurnaceFeedforward_output_function,
   FurnaceFeedforward_setc_function,
   FurnaceFeedforward_setb_function,
   FurnaceFeedforward_function_storeDelayed,
   FurnaceFeedforward_function_storeSpatialDistribution,
   FurnaceFeedforward_function_initSpatialDistribution,
   FurnaceFeedforward_updateBoundVariableAttributes,
   FurnaceFeedforward_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   FurnaceFeedforward_functionRemovedInitialEquations,
   FurnaceFeedforward_updateBoundParameters,
   FurnaceFeedforward_checkForAsserts,
   FurnaceFeedforward_function_ZeroCrossingsEquations,
   FurnaceFeedforward_function_ZeroCrossings,
   FurnaceFeedforward_function_updateRelations,
   FurnaceFeedforward_zeroCrossingDescription,
   FurnaceFeedforward_relationDescription,
   FurnaceFeedforward_function_initSample,
   FurnaceFeedforward_INDEX_JAC_A,
   FurnaceFeedforward_INDEX_JAC_B,
   FurnaceFeedforward_INDEX_JAC_C,
   FurnaceFeedforward_INDEX_JAC_D,
   FurnaceFeedforward_INDEX_JAC_F,
   FurnaceFeedforward_INDEX_JAC_H,
   FurnaceFeedforward_initialAnalyticJacobianA,
   FurnaceFeedforward_initialAnalyticJacobianB,
   FurnaceFeedforward_initialAnalyticJacobianC,
   FurnaceFeedforward_initialAnalyticJacobianD,
   FurnaceFeedforward_initialAnalyticJacobianF,
   FurnaceFeedforward_initialAnalyticJacobianH,
   FurnaceFeedforward_functionJacA_column,
   FurnaceFeedforward_functionJacB_column,
   FurnaceFeedforward_functionJacC_column,
   FurnaceFeedforward_functionJacD_column,
   FurnaceFeedforward_functionJacF_column,
   FurnaceFeedforward_functionJacH_column,
   FurnaceFeedforward_linear_model_frame,
   FurnaceFeedforward_linear_model_datarecovery_frame,
   FurnaceFeedforward_mayer,
   FurnaceFeedforward_lagrange,
   FurnaceFeedforward_pickUpBoundsForInputsInOptimization,
   FurnaceFeedforward_setInputData,
   FurnaceFeedforward_getTimeGrid,
   FurnaceFeedforward_symbolicInlineSystem,
   FurnaceFeedforward_function_initSynchronous,
   FurnaceFeedforward_function_updateSynchronous,
   FurnaceFeedforward_function_equationsSynchronous,
   FurnaceFeedforward_inputNames,
   FurnaceFeedforward_dataReconciliationInputNames,
   FurnaceFeedforward_dataReconciliationUnmeasuredVariables,
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

#define _OMC_LIT_RESOURCE_1_name_data "FurnaceFeedforward"
#define _OMC_LIT_RESOURCE_1_dir_data "C:/Users/FST/Desktop/AFM/cases/20260407_160309_FurnaceFeedforward/build/src"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,18,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,75,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "Modelica"
#define _OMC_LIT_RESOURCE_2_dir_data "C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,8,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,76,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_3_dir_data "C:/Users/FST/AppData/Roaming/.openmodelica/libraries/ModelicaServices 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,16,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,84,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void FurnaceFeedforward_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &FurnaceFeedforward_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "FurnaceFeedforward";
  data->modelData->modelFilePrefix = "FurnaceFeedforward";
  data->modelData->modelFileName = "FurnaceFeedforward.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/cases/20260407_160309_FurnaceFeedforward/build/src";
  data->modelData->modelGUID = "{70f7759a-c344-4f97-85f1-78b5e0222409}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "FurnaceFeedforward_init.c"
    ;
  static const char contents_info[] =
    #include "FurnaceFeedforward_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "FurnaceFeedforward_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "FurnaceFeedforward_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "FurnaceFeedforward_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 1;
  data->modelData->nVariablesRealArray = 6;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 18;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 5;
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
  data->modelData->modelDataXml.nEquations = 19;
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
  
    FurnaceFeedforward_setupDataStruc(&data, threadData);
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


