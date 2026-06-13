/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "NewtonCooling_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation NewtonCooling_performSimulation
#define prefixedName_updateContinuousSystem NewtonCooling_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation NewtonCooling_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int NewtonCooling_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NewtonCooling_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NewtonCooling_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NewtonCooling_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NewtonCooling_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int NewtonCooling_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NewtonCooling_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NewtonCooling_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NewtonCooling_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NewtonCooling_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 9
type: SIMPLE_ASSIGN
dT = T - T_env
*/
void NewtonCooling_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* dT variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* T STATE(1) */) - (data->simulationInfo->realParameter[1] /* T_env PARAM */);
  TRACE_POP
}
/*
equation index: 10
type: SIMPLE_ASSIGN
E_thermal = m * cp * dT
*/
void NewtonCooling_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* E_thermal variable */) = ((data->simulationInfo->realParameter[4] /* m PARAM */)) * (((data->simulationInfo->realParameter[2] /* cp PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* dT variable */)));
  TRACE_POP
}
/*
equation index: 11
type: SIMPLE_ASSIGN
Q_dot = hA * dT
*/
void NewtonCooling_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* Q_dot variable */) = ((data->simulationInfo->realParameter[3] /* hA PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* dT variable */));
  TRACE_POP
}
/*
equation index: 12
type: SIMPLE_ASSIGN
$DER.T = (-Q_dot) / (cp * m)
*/
void NewtonCooling_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(T) STATE_DER */) = DIVISION_SIM((-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* Q_dot variable */)),((data->simulationInfo->realParameter[2] /* cp PARAM */)) * ((data->simulationInfo->realParameter[4] /* m PARAM */)),"cp * m",equationIndexes);
  TRACE_POP
}
/*
equation index: 13
type: SIMPLE_ASSIGN
$DER.E_dissipated = Q_dot
*/
void NewtonCooling_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(E_dissipated) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* Q_dot variable */);
  TRACE_POP
}
/*
equation index: 14
type: ALGORITHM

  assert(E_thermal >= -1e-6, "E_thermal should be non-negative: E_thermal = " + String(E_thermal, 6, 0, true));
*/
void NewtonCooling_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,46,"E_thermal should be non-negative: E_thermal = ");
  modelica_string tmp2;
  modelica_metatype tmpMeta3;
  static int tmp4 = 0;
  {
    tmp0 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* E_thermal variable */),-1e-6);
    if(!tmp0)
    {
      tmp2 = modelica_real_to_modelica_string((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* E_thermal variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta3 = stringAppend(MMC_REFSTRINGLIT(tmp1),tmp2);
      {
        const char* assert_cond = "(E_thermal >= -1e-6)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/Desktop/第一类数据/cases/20260330_191135_NewtonCooling/model/NewtonCooling.mo",37,3,37,99,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta3));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/FST/Desktop/第一类数据/cases/20260330_191135_NewtonCooling/model/NewtonCooling.mo",37,3,37,99,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta3));
        }
      }
    }
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int NewtonCooling_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  NewtonCooling_functionLocalKnownVars(data, threadData);
  NewtonCooling_eqFunction_9(data, threadData);

  NewtonCooling_eqFunction_10(data, threadData);

  NewtonCooling_eqFunction_11(data, threadData);

  NewtonCooling_eqFunction_12(data, threadData);

  NewtonCooling_eqFunction_13(data, threadData);

  NewtonCooling_eqFunction_14(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int NewtonCooling_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void NewtonCooling_eqFunction_9(DATA* data, threadData_t *threadData);
extern void NewtonCooling_eqFunction_11(DATA* data, threadData_t *threadData);
extern void NewtonCooling_eqFunction_12(DATA* data, threadData_t *threadData);
extern void NewtonCooling_eqFunction_13(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[4])(DATA*, threadData_t*) = {
    NewtonCooling_eqFunction_9,
    NewtonCooling_eqFunction_11,
    NewtonCooling_eqFunction_12,
    NewtonCooling_eqFunction_13
  };
  
  static const int eqIndices[4] = {
    9,
    11,
    12,
    13
  };
  
  for (id = 0; id < 4; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int NewtonCooling_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  NewtonCooling_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void NewtonCooling_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_dissipated STATE(1,Q_dot) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(E_dissipated) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(T) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_thermal variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_dot variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* dT variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* tau variable */
  
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

#include "NewtonCooling_12jac.h"
#include "NewtonCooling_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks NewtonCooling_callback = {
   (int (*)(DATA *, threadData_t *, void *)) NewtonCooling_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) NewtonCooling_performQSSSimulation,    /* performQSSSimulation */
   NewtonCooling_updateContinuousSystem,    /* updateContinuousSystem */
   NewtonCooling_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   NewtonCooling_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   NewtonCooling_initializeDAEmodeData,
   NewtonCooling_computeVarIndices,
   NewtonCooling_functionODE,
   NewtonCooling_functionAlgebraics,
   NewtonCooling_functionDAE,
   NewtonCooling_functionLocalKnownVars,
   NewtonCooling_input_function,
   NewtonCooling_input_function_init,
   NewtonCooling_input_function_updateStartValues,
   NewtonCooling_data_function,
   NewtonCooling_output_function,
   NewtonCooling_setc_function,
   NewtonCooling_setb_function,
   NewtonCooling_function_storeDelayed,
   NewtonCooling_function_storeSpatialDistribution,
   NewtonCooling_function_initSpatialDistribution,
   NewtonCooling_updateBoundVariableAttributes,
   NewtonCooling_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   NewtonCooling_functionRemovedInitialEquations,
   NewtonCooling_updateBoundParameters,
   NewtonCooling_checkForAsserts,
   NewtonCooling_function_ZeroCrossingsEquations,
   NewtonCooling_function_ZeroCrossings,
   NewtonCooling_function_updateRelations,
   NewtonCooling_zeroCrossingDescription,
   NewtonCooling_relationDescription,
   NewtonCooling_function_initSample,
   NewtonCooling_INDEX_JAC_A,
   NewtonCooling_INDEX_JAC_B,
   NewtonCooling_INDEX_JAC_C,
   NewtonCooling_INDEX_JAC_D,
   NewtonCooling_INDEX_JAC_F,
   NewtonCooling_INDEX_JAC_H,
   NewtonCooling_initialAnalyticJacobianA,
   NewtonCooling_initialAnalyticJacobianB,
   NewtonCooling_initialAnalyticJacobianC,
   NewtonCooling_initialAnalyticJacobianD,
   NewtonCooling_initialAnalyticJacobianF,
   NewtonCooling_initialAnalyticJacobianH,
   NewtonCooling_functionJacA_column,
   NewtonCooling_functionJacB_column,
   NewtonCooling_functionJacC_column,
   NewtonCooling_functionJacD_column,
   NewtonCooling_functionJacF_column,
   NewtonCooling_functionJacH_column,
   NewtonCooling_linear_model_frame,
   NewtonCooling_linear_model_datarecovery_frame,
   NewtonCooling_mayer,
   NewtonCooling_lagrange,
   NewtonCooling_pickUpBoundsForInputsInOptimization,
   NewtonCooling_setInputData,
   NewtonCooling_getTimeGrid,
   NewtonCooling_symbolicInlineSystem,
   NewtonCooling_function_initSynchronous,
   NewtonCooling_function_updateSynchronous,
   NewtonCooling_function_equationsSynchronous,
   NewtonCooling_inputNames,
   NewtonCooling_dataReconciliationInputNames,
   NewtonCooling_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "NewtonCooling"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/Desktop/第一类数据/cases/20260330_191135_NewtonCooling/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,13,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,78,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void NewtonCooling_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &NewtonCooling_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "NewtonCooling";
  data->modelData->modelFilePrefix = "NewtonCooling";
  data->modelData->modelFileName = "NewtonCooling.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/第一类数据/cases/20260330_191135_NewtonCooling/model";
  data->modelData->modelGUID = "{8cdd1e55-1785-4a97-96ef-4d70af810bd3}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "NewtonCooling_init.c"
    ;
  static const char contents_info[] =
    #include "NewtonCooling_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "NewtonCooling_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "NewtonCooling_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "NewtonCooling_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 8;
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
  
    NewtonCooling_setupDataStruc(&data, threadData);
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


