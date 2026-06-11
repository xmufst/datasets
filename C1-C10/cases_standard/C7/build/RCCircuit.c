/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "RCCircuit_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation RCCircuit_performSimulation
#define prefixedName_updateContinuousSystem RCCircuit_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation RCCircuit_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int RCCircuit_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCCircuit_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCCircuit_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCCircuit_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCCircuit_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int RCCircuit_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCCircuit_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCCircuit_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCCircuit_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCCircuit_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 9
type: SIMPLE_ASSIGN
E_capacitor = 0.5 * C * Vc ^ 2.0
*/
void RCCircuit_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* Vc STATE(1) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* E_capacitor variable */) = (0.5) * (((data->simulationInfo->realParameter[0] /* C PARAM */)) * ((tmp0 * tmp0)));
  TRACE_POP
}
/*
equation index: 10
type: SIMPLE_ASSIGN
V_in = if time < t_switch then V_source else 0.0
*/
void RCCircuit_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  modelica_boolean tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  tmp2 = 1.0;
  tmp3 = fabs((data->simulationInfo->realParameter[4] /* t_switch PARAM */));
  relationhysteresis(data, &tmp1, data->localData[0]->timeValue, (data->simulationInfo->realParameter[4] /* t_switch PARAM */), tmp2, tmp3, 0, Less, LessZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* V_in variable */) = (tmp1?(data->simulationInfo->realParameter[2] /* V_source PARAM */):0.0);
  TRACE_POP
}
/*
equation index: 11
type: SIMPLE_ASSIGN
i = (V_in - Vc) / R
*/
void RCCircuit_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* i variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* V_in variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* Vc STATE(1) */),(data->simulationInfo->realParameter[1] /* R PARAM */),"R",equationIndexes);
  TRACE_POP
}
/*
equation index: 12
type: SIMPLE_ASSIGN
$DER.Vc = i / C
*/
void RCCircuit_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(Vc) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* i variable */),(data->simulationInfo->realParameter[0] /* C PARAM */),"C",equationIndexes);
  TRACE_POP
}
/*
equation index: 13
type: SIMPLE_ASSIGN
P_resistor = i ^ 2.0 * R
*/
void RCCircuit_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  modelica_real tmp4;
  tmp4 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* i variable */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* P_resistor variable */) = ((tmp4 * tmp4)) * ((data->simulationInfo->realParameter[1] /* R PARAM */));
  TRACE_POP
}
/*
equation index: 14
type: SIMPLE_ASSIGN
$DER.E_dissipated = P_resistor
*/
void RCCircuit_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(E_dissipated) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* P_resistor variable */);
  TRACE_POP
}

OMC_DISABLE_OPT
int RCCircuit_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  RCCircuit_functionLocalKnownVars(data, threadData);
  RCCircuit_eqFunction_9(data, threadData);

  RCCircuit_eqFunction_10(data, threadData);

  RCCircuit_eqFunction_11(data, threadData);

  RCCircuit_eqFunction_12(data, threadData);

  RCCircuit_eqFunction_13(data, threadData);

  RCCircuit_eqFunction_14(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int RCCircuit_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void RCCircuit_eqFunction_10(DATA* data, threadData_t *threadData);
extern void RCCircuit_eqFunction_11(DATA* data, threadData_t *threadData);
extern void RCCircuit_eqFunction_12(DATA* data, threadData_t *threadData);
extern void RCCircuit_eqFunction_13(DATA* data, threadData_t *threadData);
extern void RCCircuit_eqFunction_14(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[5])(DATA*, threadData_t*) = {
    RCCircuit_eqFunction_10,
    RCCircuit_eqFunction_11,
    RCCircuit_eqFunction_12,
    RCCircuit_eqFunction_13,
    RCCircuit_eqFunction_14
  };
  
  static const int eqIndices[5] = {
    10,
    11,
    12,
    13,
    14
  };
  
  for (id = 0; id < 5; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int RCCircuit_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  RCCircuit_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void RCCircuit_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_dissipated STATE(1,P_resistor) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Vc STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(E_dissipated) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(Vc) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_capacitor variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* P_resistor variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* V_in variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* i variable */
  
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

#include "RCCircuit_12jac.h"
#include "RCCircuit_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks RCCircuit_callback = {
   (int (*)(DATA *, threadData_t *, void *)) RCCircuit_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) RCCircuit_performQSSSimulation,    /* performQSSSimulation */
   RCCircuit_updateContinuousSystem,    /* updateContinuousSystem */
   RCCircuit_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   RCCircuit_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   RCCircuit_initializeDAEmodeData,
   RCCircuit_computeVarIndices,
   RCCircuit_functionODE,
   RCCircuit_functionAlgebraics,
   RCCircuit_functionDAE,
   RCCircuit_functionLocalKnownVars,
   RCCircuit_input_function,
   RCCircuit_input_function_init,
   RCCircuit_input_function_updateStartValues,
   RCCircuit_data_function,
   RCCircuit_output_function,
   RCCircuit_setc_function,
   RCCircuit_setb_function,
   RCCircuit_function_storeDelayed,
   RCCircuit_function_storeSpatialDistribution,
   RCCircuit_function_initSpatialDistribution,
   RCCircuit_updateBoundVariableAttributes,
   RCCircuit_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   RCCircuit_functionRemovedInitialEquations,
   RCCircuit_updateBoundParameters,
   RCCircuit_checkForAsserts,
   RCCircuit_function_ZeroCrossingsEquations,
   RCCircuit_function_ZeroCrossings,
   RCCircuit_function_updateRelations,
   RCCircuit_zeroCrossingDescription,
   RCCircuit_relationDescription,
   RCCircuit_function_initSample,
   RCCircuit_INDEX_JAC_A,
   RCCircuit_INDEX_JAC_B,
   RCCircuit_INDEX_JAC_C,
   RCCircuit_INDEX_JAC_D,
   RCCircuit_INDEX_JAC_F,
   RCCircuit_INDEX_JAC_H,
   RCCircuit_initialAnalyticJacobianA,
   RCCircuit_initialAnalyticJacobianB,
   RCCircuit_initialAnalyticJacobianC,
   RCCircuit_initialAnalyticJacobianD,
   RCCircuit_initialAnalyticJacobianF,
   RCCircuit_initialAnalyticJacobianH,
   RCCircuit_functionJacA_column,
   RCCircuit_functionJacB_column,
   RCCircuit_functionJacC_column,
   RCCircuit_functionJacD_column,
   RCCircuit_functionJacF_column,
   RCCircuit_functionJacH_column,
   RCCircuit_linear_model_frame,
   RCCircuit_linear_model_datarecovery_frame,
   RCCircuit_mayer,
   RCCircuit_lagrange,
   RCCircuit_pickUpBoundsForInputsInOptimization,
   RCCircuit_setInputData,
   RCCircuit_getTimeGrid,
   RCCircuit_symbolicInlineSystem,
   RCCircuit_function_initSynchronous,
   RCCircuit_function_updateSynchronous,
   RCCircuit_function_equationsSynchronous,
   RCCircuit_inputNames,
   RCCircuit_dataReconciliationInputNames,
   RCCircuit_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "RCCircuit"
#define _OMC_LIT_RESOURCE_0_dir_data "G:/数据/第一类/C7"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,9,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,22,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void RCCircuit_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &RCCircuit_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "RCCircuit";
  data->modelData->modelFilePrefix = "RCCircuit";
  data->modelData->modelFileName = "RCCircuit.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "G:/数据/第一类/C7";
  data->modelData->modelGUID = "{c90d8ac6-15e3-4625-8ae2-a581eec54054}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "RCCircuit_init.c"
    ;
  static const char contents_info[] =
    #include "RCCircuit_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "RCCircuit_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "RCCircuit_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "RCCircuit_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 8;
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
  data->modelData->nZeroCrossings = 1;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 1;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 17;
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
  
    RCCircuit_setupDataStruc(&data, threadData);
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


