/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "SpringEndStop_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation SpringEndStop_performSimulation
#define prefixedName_updateContinuousSystem SpringEndStop_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation SpringEndStop_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int SpringEndStop_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringEndStop_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringEndStop_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringEndStop_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringEndStop_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int SpringEndStop_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringEndStop_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringEndStop_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringEndStop_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int SpringEndStop_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 14
type: SIMPLE_ASSIGN
$DER.x = v
*/
void SpringEndStop_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(x) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1) */);
  TRACE_POP
}
/*
equation index: 15
type: SIMPLE_ASSIGN
penetration = x - gap
*/
void SpringEndStop_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* penetration variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */) - (data->simulationInfo->realParameter[3] /* gap PARAM */);
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
contact = penetration > 0.0
*/
void SpringEndStop_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp1 = 1.0;
  tmp2 = 0.0;
  relationhysteresis(data, &tmp0, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* penetration variable */), 0.0, tmp1, tmp2, 0, Greater, GreaterZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* contact DISCRETE */) = tmp0;
  TRACE_POP
}
/*
equation index: 17
type: SIMPLE_ASSIGN
F_spring = (-k) * x
*/
void SpringEndStop_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* F_spring variable */) = ((-(data->simulationInfo->realParameter[4] /* k PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */));
  TRACE_POP
}
/*
equation index: 18
type: SIMPLE_ASSIGN
F_damper = (-c) * v
*/
void SpringEndStop_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* F_damper variable */) = ((-(data->simulationInfo->realParameter[0] /* c PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1) */));
  TRACE_POP
}
/*
equation index: 19
type: SIMPLE_ASSIGN
F_contact = if contact then (-k_contact) * penetration - c_contact * v else 0.0
*/
void SpringEndStop_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* F_contact variable */) = ((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* contact DISCRETE */)?((-(data->simulationInfo->realParameter[5] /* k_contact PARAM */))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* penetration variable */)) - (((data->simulationInfo->realParameter[1] /* c_contact PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1) */))):0.0);
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
F_net = F_spring + F_damper + F_contact
*/
void SpringEndStop_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* F_net variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* F_spring variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* F_damper variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* F_contact variable */);
  TRACE_POP
}
/*
equation index: 21
type: SIMPLE_ASSIGN
$DER.v = F_net / m
*/
void SpringEndStop_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(v) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* F_net variable */),(data->simulationInfo->realParameter[6] /* m PARAM */),"m",equationIndexes);
  TRACE_POP
}
/*
equation index: 22
type: SIMPLE_ASSIGN
E_kinetic = 0.5 * m * v ^ 2.0
*/
void SpringEndStop_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  modelica_real tmp3;
  tmp3 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* E_kinetic variable */) = (0.5) * (((data->simulationInfo->realParameter[6] /* m PARAM */)) * ((tmp3 * tmp3)));
  TRACE_POP
}
/*
equation index: 23
type: SIMPLE_ASSIGN
E_spring = 0.5 * k * x ^ 2.0
*/
void SpringEndStop_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  modelica_real tmp4;
  tmp4 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* E_spring variable */) = (0.5) * (((data->simulationInfo->realParameter[4] /* k PARAM */)) * ((tmp4 * tmp4)));
  TRACE_POP
}
/*
equation index: 24
type: SIMPLE_ASSIGN
E_total = E_kinetic + E_spring
*/
void SpringEndStop_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* E_total variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* E_kinetic variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* E_spring variable */);
  TRACE_POP
}

OMC_DISABLE_OPT
int SpringEndStop_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  SpringEndStop_functionLocalKnownVars(data, threadData);
  SpringEndStop_eqFunction_14(data, threadData);

  SpringEndStop_eqFunction_15(data, threadData);

  SpringEndStop_eqFunction_16(data, threadData);

  SpringEndStop_eqFunction_17(data, threadData);

  SpringEndStop_eqFunction_18(data, threadData);

  SpringEndStop_eqFunction_19(data, threadData);

  SpringEndStop_eqFunction_20(data, threadData);

  SpringEndStop_eqFunction_21(data, threadData);

  SpringEndStop_eqFunction_22(data, threadData);

  SpringEndStop_eqFunction_23(data, threadData);

  SpringEndStop_eqFunction_24(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int SpringEndStop_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void SpringEndStop_eqFunction_14(DATA* data, threadData_t *threadData);
extern void SpringEndStop_eqFunction_15(DATA* data, threadData_t *threadData);
extern void SpringEndStop_eqFunction_16(DATA* data, threadData_t *threadData);
extern void SpringEndStop_eqFunction_17(DATA* data, threadData_t *threadData);
extern void SpringEndStop_eqFunction_18(DATA* data, threadData_t *threadData);
extern void SpringEndStop_eqFunction_19(DATA* data, threadData_t *threadData);
extern void SpringEndStop_eqFunction_20(DATA* data, threadData_t *threadData);
extern void SpringEndStop_eqFunction_21(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[8])(DATA*, threadData_t*) = {
    SpringEndStop_eqFunction_14,
    SpringEndStop_eqFunction_15,
    SpringEndStop_eqFunction_16,
    SpringEndStop_eqFunction_17,
    SpringEndStop_eqFunction_18,
    SpringEndStop_eqFunction_19,
    SpringEndStop_eqFunction_20,
    SpringEndStop_eqFunction_21
  };
  
  static const int eqIndices[8] = {
    14,
    15,
    16,
    17,
    18,
    19,
    20,
    21
  };
  
  for (id = 0; id < 8; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int SpringEndStop_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  SpringEndStop_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void SpringEndStop_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* v STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* x STATE(1,v) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(v) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(x) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_kinetic variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_spring variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_total variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_contact variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_damper variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_net variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_spring variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* penetration variable */
  
  /* discreteAlgVars */
  
  /* realOptimizeConstraintsVars */
  
  /* realOptimizeFinalConstraintsVars */
  
  
  /* intAlgVars */
  
  /* boolAlgVars */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* contact DISCRETE */
  
  /* stringAlgVars */
  
  TRACE_POP
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "SpringEndStop_12jac.h"
#include "SpringEndStop_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks SpringEndStop_callback = {
   (int (*)(DATA *, threadData_t *, void *)) SpringEndStop_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) SpringEndStop_performQSSSimulation,    /* performQSSSimulation */
   SpringEndStop_updateContinuousSystem,    /* updateContinuousSystem */
   SpringEndStop_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   SpringEndStop_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   SpringEndStop_initializeDAEmodeData,
   SpringEndStop_computeVarIndices,
   SpringEndStop_functionODE,
   SpringEndStop_functionAlgebraics,
   SpringEndStop_functionDAE,
   SpringEndStop_functionLocalKnownVars,
   SpringEndStop_input_function,
   SpringEndStop_input_function_init,
   SpringEndStop_input_function_updateStartValues,
   SpringEndStop_data_function,
   SpringEndStop_output_function,
   SpringEndStop_setc_function,
   SpringEndStop_setb_function,
   SpringEndStop_function_storeDelayed,
   SpringEndStop_function_storeSpatialDistribution,
   SpringEndStop_function_initSpatialDistribution,
   SpringEndStop_updateBoundVariableAttributes,
   SpringEndStop_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   SpringEndStop_functionRemovedInitialEquations,
   SpringEndStop_updateBoundParameters,
   SpringEndStop_checkForAsserts,
   SpringEndStop_function_ZeroCrossingsEquations,
   SpringEndStop_function_ZeroCrossings,
   SpringEndStop_function_updateRelations,
   SpringEndStop_zeroCrossingDescription,
   SpringEndStop_relationDescription,
   SpringEndStop_function_initSample,
   SpringEndStop_INDEX_JAC_A,
   SpringEndStop_INDEX_JAC_B,
   SpringEndStop_INDEX_JAC_C,
   SpringEndStop_INDEX_JAC_D,
   SpringEndStop_INDEX_JAC_F,
   SpringEndStop_INDEX_JAC_H,
   SpringEndStop_initialAnalyticJacobianA,
   SpringEndStop_initialAnalyticJacobianB,
   SpringEndStop_initialAnalyticJacobianC,
   SpringEndStop_initialAnalyticJacobianD,
   SpringEndStop_initialAnalyticJacobianF,
   SpringEndStop_initialAnalyticJacobianH,
   SpringEndStop_functionJacA_column,
   SpringEndStop_functionJacB_column,
   SpringEndStop_functionJacC_column,
   SpringEndStop_functionJacD_column,
   SpringEndStop_functionJacF_column,
   SpringEndStop_functionJacH_column,
   SpringEndStop_linear_model_frame,
   SpringEndStop_linear_model_datarecovery_frame,
   SpringEndStop_mayer,
   SpringEndStop_lagrange,
   SpringEndStop_pickUpBoundsForInputsInOptimization,
   SpringEndStop_setInputData,
   SpringEndStop_getTimeGrid,
   SpringEndStop_symbolicInlineSystem,
   SpringEndStop_function_initSynchronous,
   SpringEndStop_function_updateSynchronous,
   SpringEndStop_function_equationsSynchronous,
   SpringEndStop_inputNames,
   SpringEndStop_dataReconciliationInputNames,
   SpringEndStop_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "SpringEndStop"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/Desktop/第一类数据/cases/20260330_173903_SpringEndStop/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,13,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,78,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void SpringEndStop_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &SpringEndStop_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "SpringEndStop";
  data->modelData->modelFilePrefix = "SpringEndStop";
  data->modelData->modelFileName = "SpringEndStop.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/第一类数据/cases/20260330_173903_SpringEndStop/model";
  data->modelData->modelGUID = "{d03ac2e5-9424-4b6f-8bfb-d80839530a14}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "SpringEndStop_init.c"
    ;
  static const char contents_info[] =
    #include "SpringEndStop_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "SpringEndStop_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "SpringEndStop_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "SpringEndStop_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 12;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 1;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 9;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 1;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 1;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 1;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 28;
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
  
    SpringEndStop_setupDataStruc(&data, threadData);
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


