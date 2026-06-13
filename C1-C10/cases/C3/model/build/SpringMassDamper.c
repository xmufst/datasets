/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "SpringMassDamper_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation SpringMassDamper_performSimulation
#define prefixedName_updateContinuousSystem SpringMassDamper_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation SpringMassDamper_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int SpringMassDamper_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassDamper_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassDamper_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassDamper_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassDamper_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int SpringMassDamper_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassDamper_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassDamper_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassDamper_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringMassDamper_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 13
type: SIMPLE_ASSIGN
E_potential = 0.5 * k * x ^ 2.0
*/
void SpringMassDamper_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* E_potential variable */) = (0.5) * (((data->simulationInfo->realParameter[1] /* k PARAM */)) * ((tmp0 * tmp0)));
  TRACE_POP
}
/*
equation index: 14
type: SIMPLE_ASSIGN
E_kinetic = 0.5 * m * v ^ 2.0
*/
void SpringMassDamper_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  modelica_real tmp1;
  tmp1 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* E_kinetic variable */) = (0.5) * (((data->simulationInfo->realParameter[2] /* m PARAM */)) * ((tmp1 * tmp1)));
  TRACE_POP
}
/*
equation index: 15
type: SIMPLE_ASSIGN
E_total = E_kinetic + E_potential
*/
void SpringMassDamper_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* E_total variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* E_kinetic variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* E_potential variable */);
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
$DER.x = v
*/
void SpringMassDamper_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(x) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */);
  TRACE_POP
}
/*
equation index: 17
type: SIMPLE_ASSIGN
F_damper = c * v
*/
void SpringMassDamper_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* F_damper variable */) = ((data->simulationInfo->realParameter[0] /* c PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */));
  TRACE_POP
}
/*
equation index: 18
type: SIMPLE_ASSIGN
F_spring = k * x
*/
void SpringMassDamper_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* F_spring variable */) = ((data->simulationInfo->realParameter[1] /* k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */));
  TRACE_POP
}
/*
equation index: 19
type: SIMPLE_ASSIGN
a = ((-F_spring) - F_damper) / m
*/
void SpringMassDamper_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* a variable */) = DIVISION_SIM((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* F_spring variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* F_damper variable */),(data->simulationInfo->realParameter[2] /* m PARAM */),"m",equationIndexes);
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
$DER.v = a
*/
void SpringMassDamper_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(v) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* a variable */);
  TRACE_POP
}

OMC_DISABLE_OPT
int SpringMassDamper_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  SpringMassDamper_functionLocalKnownVars(data, threadData);
  SpringMassDamper_eqFunction_13(data, threadData);

  SpringMassDamper_eqFunction_14(data, threadData);

  SpringMassDamper_eqFunction_15(data, threadData);

  SpringMassDamper_eqFunction_16(data, threadData);

  SpringMassDamper_eqFunction_17(data, threadData);

  SpringMassDamper_eqFunction_18(data, threadData);

  SpringMassDamper_eqFunction_19(data, threadData);

  SpringMassDamper_eqFunction_20(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int SpringMassDamper_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void SpringMassDamper_eqFunction_16(DATA* data, threadData_t *threadData);
extern void SpringMassDamper_eqFunction_17(DATA* data, threadData_t *threadData);
extern void SpringMassDamper_eqFunction_18(DATA* data, threadData_t *threadData);
extern void SpringMassDamper_eqFunction_19(DATA* data, threadData_t *threadData);
extern void SpringMassDamper_eqFunction_20(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[5])(DATA*, threadData_t*) = {
    SpringMassDamper_eqFunction_16,
    SpringMassDamper_eqFunction_17,
    SpringMassDamper_eqFunction_18,
    SpringMassDamper_eqFunction_19,
    SpringMassDamper_eqFunction_20
  };
  
  static const int eqIndices[5] = {
    16,
    17,
    18,
    19,
    20
  };
  
  for (id = 0; id < 5; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int SpringMassDamper_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  SpringMassDamper_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void SpringMassDamper_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_potential variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_total variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_damper variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_spring variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* a variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* omega_n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* zeta variable */
  
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

#include "SpringMassDamper_12jac.h"
#include "SpringMassDamper_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks SpringMassDamper_callback = {
   (int (*)(DATA *, threadData_t *, void *)) SpringMassDamper_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) SpringMassDamper_performQSSSimulation,    /* performQSSSimulation */
   SpringMassDamper_updateContinuousSystem,    /* updateContinuousSystem */
   SpringMassDamper_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   SpringMassDamper_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   SpringMassDamper_initializeDAEmodeData,
   SpringMassDamper_computeVarIndices,
   SpringMassDamper_functionODE,
   SpringMassDamper_functionAlgebraics,
   SpringMassDamper_functionDAE,
   SpringMassDamper_functionLocalKnownVars,
   SpringMassDamper_input_function,
   SpringMassDamper_input_function_init,
   SpringMassDamper_input_function_updateStartValues,
   SpringMassDamper_data_function,
   SpringMassDamper_output_function,
   SpringMassDamper_setc_function,
   SpringMassDamper_setb_function,
   SpringMassDamper_function_storeDelayed,
   SpringMassDamper_function_storeSpatialDistribution,
   SpringMassDamper_function_initSpatialDistribution,
   SpringMassDamper_updateBoundVariableAttributes,
   SpringMassDamper_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   SpringMassDamper_functionRemovedInitialEquations,
   SpringMassDamper_updateBoundParameters,
   SpringMassDamper_checkForAsserts,
   SpringMassDamper_function_ZeroCrossingsEquations,
   SpringMassDamper_function_ZeroCrossings,
   SpringMassDamper_function_updateRelations,
   SpringMassDamper_zeroCrossingDescription,
   SpringMassDamper_relationDescription,
   SpringMassDamper_function_initSample,
   SpringMassDamper_INDEX_JAC_A,
   SpringMassDamper_INDEX_JAC_B,
   SpringMassDamper_INDEX_JAC_C,
   SpringMassDamper_INDEX_JAC_D,
   SpringMassDamper_INDEX_JAC_F,
   SpringMassDamper_INDEX_JAC_H,
   SpringMassDamper_initialAnalyticJacobianA,
   SpringMassDamper_initialAnalyticJacobianB,
   SpringMassDamper_initialAnalyticJacobianC,
   SpringMassDamper_initialAnalyticJacobianD,
   SpringMassDamper_initialAnalyticJacobianF,
   SpringMassDamper_initialAnalyticJacobianH,
   SpringMassDamper_functionJacA_column,
   SpringMassDamper_functionJacB_column,
   SpringMassDamper_functionJacC_column,
   SpringMassDamper_functionJacD_column,
   SpringMassDamper_functionJacF_column,
   SpringMassDamper_functionJacH_column,
   SpringMassDamper_linear_model_frame,
   SpringMassDamper_linear_model_datarecovery_frame,
   SpringMassDamper_mayer,
   SpringMassDamper_lagrange,
   SpringMassDamper_pickUpBoundsForInputsInOptimization,
   SpringMassDamper_setInputData,
   SpringMassDamper_getTimeGrid,
   SpringMassDamper_symbolicInlineSystem,
   SpringMassDamper_function_initSynchronous,
   SpringMassDamper_function_updateSynchronous,
   SpringMassDamper_function_equationsSynchronous,
   SpringMassDamper_inputNames,
   SpringMassDamper_dataReconciliationInputNames,
   SpringMassDamper_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "SpringMassDamper"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/Desktop/AFM/cases/20260410_125015_SpringMassDamper/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,16,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,69,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void SpringMassDamper_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &SpringMassDamper_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "SpringMassDamper";
  data->modelData->modelFilePrefix = "SpringMassDamper";
  data->modelData->modelFileName = "SpringMassDamper.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/cases/20260410_125015_SpringMassDamper/model";
  data->modelData->modelGUID = "{64233705-e6f1-4b52-ba03-cbf3cbdf75a8}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "SpringMassDamper_init.c"
    ;
  static const char contents_info[] =
    #include "SpringMassDamper_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "SpringMassDamper_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "SpringMassDamper_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "SpringMassDamper_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 12;
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
  data->modelData->modelDataXml.nEquations = 25;
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
  
    SpringMassDamper_setupDataStruc(&data, threadData);
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


