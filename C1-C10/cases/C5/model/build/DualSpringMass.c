/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "DualSpringMass_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation DualSpringMass_performSimulation
#define prefixedName_updateContinuousSystem DualSpringMass_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation DualSpringMass_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int DualSpringMass_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DualSpringMass_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DualSpringMass_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DualSpringMass_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DualSpringMass_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int DualSpringMass_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DualSpringMass_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DualSpringMass_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DualSpringMass_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int DualSpringMass_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 15
type: SIMPLE_ASSIGN
E_kinetic = 0.5 * (m1 * v1 ^ 2.0 + m2 * v2 ^ 2.0)
*/
void DualSpringMass_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v1 STATE(1) */);
  tmp1 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v2 STATE(1) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* E_kinetic variable */) = (0.5) * (((data->simulationInfo->realParameter[2] /* m1 PARAM */)) * ((tmp0 * tmp0)) + ((data->simulationInfo->realParameter[3] /* m2 PARAM */)) * ((tmp1 * tmp1)));
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
delta_x = x2 - x1
*/
void DualSpringMass_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* delta_x variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* x2 STATE(1,v2) */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* x1 STATE(1,v1) */);
  TRACE_POP
}
/*
equation index: 17
type: SIMPLE_ASSIGN
E_potential = 0.5 * (k1 * x1 ^ 2.0 + k2 * delta_x ^ 2.0)
*/
void DualSpringMass_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  modelica_real tmp2;
  modelica_real tmp3;
  tmp2 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* x1 STATE(1,v1) */);
  tmp3 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* delta_x variable */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* E_potential variable */) = (0.5) * (((data->simulationInfo->realParameter[0] /* k1 PARAM */)) * ((tmp2 * tmp2)) + ((data->simulationInfo->realParameter[1] /* k2 PARAM */)) * ((tmp3 * tmp3)));
  TRACE_POP
}
/*
equation index: 18
type: SIMPLE_ASSIGN
E_total = E_kinetic + E_potential
*/
void DualSpringMass_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* E_total variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* E_kinetic variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* E_potential variable */);
  TRACE_POP
}
/*
equation index: 19
type: SIMPLE_ASSIGN
F_spring2 = k2 * delta_x
*/
void DualSpringMass_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* F_spring2 variable */) = ((data->simulationInfo->realParameter[1] /* k2 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* delta_x variable */));
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
F_spring1 = k1 * x1
*/
void DualSpringMass_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* F_spring1 variable */) = ((data->simulationInfo->realParameter[0] /* k1 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* x1 STATE(1,v1) */));
  TRACE_POP
}
/*
equation index: 21
type: SIMPLE_ASSIGN
$DER.v2 = k2 * (x1 - x2) / m2
*/
void DualSpringMass_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* der(v2) STATE_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[1] /* k2 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* x1 STATE(1,v1) */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* x2 STATE(1,v2) */)),(data->simulationInfo->realParameter[3] /* m2 PARAM */),"m2",equationIndexes);
  TRACE_POP
}
/*
equation index: 22
type: SIMPLE_ASSIGN
$DER.v1 = (F_spring2 - F_spring1) / m1
*/
void DualSpringMass_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* der(v1) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* F_spring2 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* F_spring1 variable */),(data->simulationInfo->realParameter[2] /* m1 PARAM */),"m1",equationIndexes);
  TRACE_POP
}
/*
equation index: 23
type: SIMPLE_ASSIGN
$DER.x2 = v2
*/
void DualSpringMass_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* der(x2) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v2 STATE(1) */);
  TRACE_POP
}
/*
equation index: 24
type: SIMPLE_ASSIGN
$DER.x1 = v1
*/
void DualSpringMass_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* der(x1) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v1 STATE(1) */);
  TRACE_POP
}

OMC_DISABLE_OPT
int DualSpringMass_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  DualSpringMass_functionLocalKnownVars(data, threadData);
  DualSpringMass_eqFunction_15(data, threadData);

  DualSpringMass_eqFunction_16(data, threadData);

  DualSpringMass_eqFunction_17(data, threadData);

  DualSpringMass_eqFunction_18(data, threadData);

  DualSpringMass_eqFunction_19(data, threadData);

  DualSpringMass_eqFunction_20(data, threadData);

  DualSpringMass_eqFunction_21(data, threadData);

  DualSpringMass_eqFunction_22(data, threadData);

  DualSpringMass_eqFunction_23(data, threadData);

  DualSpringMass_eqFunction_24(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int DualSpringMass_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void DualSpringMass_eqFunction_16(DATA* data, threadData_t *threadData);
extern void DualSpringMass_eqFunction_19(DATA* data, threadData_t *threadData);
extern void DualSpringMass_eqFunction_20(DATA* data, threadData_t *threadData);
extern void DualSpringMass_eqFunction_21(DATA* data, threadData_t *threadData);
extern void DualSpringMass_eqFunction_22(DATA* data, threadData_t *threadData);
extern void DualSpringMass_eqFunction_23(DATA* data, threadData_t *threadData);
extern void DualSpringMass_eqFunction_24(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[7])(DATA*, threadData_t*) = {
    DualSpringMass_eqFunction_16,
    DualSpringMass_eqFunction_19,
    DualSpringMass_eqFunction_20,
    DualSpringMass_eqFunction_21,
    DualSpringMass_eqFunction_22,
    DualSpringMass_eqFunction_23,
    DualSpringMass_eqFunction_24
  };
  
  static const int eqIndices[7] = {
    16,
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

int DualSpringMass_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  DualSpringMass_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void DualSpringMass_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* v1 STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* v2 STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* x1 STATE(1,v1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* x2 STATE(1,v2) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(v1) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(v2) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(x1) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(x2) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_kinetic variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_potential variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_total variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_spring1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_spring2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* delta_x variable */
  
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

#include "DualSpringMass_12jac.h"
#include "DualSpringMass_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks DualSpringMass_callback = {
   (int (*)(DATA *, threadData_t *, void *)) DualSpringMass_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) DualSpringMass_performQSSSimulation,    /* performQSSSimulation */
   DualSpringMass_updateContinuousSystem,    /* updateContinuousSystem */
   DualSpringMass_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   DualSpringMass_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   DualSpringMass_initializeDAEmodeData,
   DualSpringMass_computeVarIndices,
   DualSpringMass_functionODE,
   DualSpringMass_functionAlgebraics,
   DualSpringMass_functionDAE,
   DualSpringMass_functionLocalKnownVars,
   DualSpringMass_input_function,
   DualSpringMass_input_function_init,
   DualSpringMass_input_function_updateStartValues,
   DualSpringMass_data_function,
   DualSpringMass_output_function,
   DualSpringMass_setc_function,
   DualSpringMass_setb_function,
   DualSpringMass_function_storeDelayed,
   DualSpringMass_function_storeSpatialDistribution,
   DualSpringMass_function_initSpatialDistribution,
   DualSpringMass_updateBoundVariableAttributes,
   DualSpringMass_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   DualSpringMass_functionRemovedInitialEquations,
   DualSpringMass_updateBoundParameters,
   DualSpringMass_checkForAsserts,
   DualSpringMass_function_ZeroCrossingsEquations,
   DualSpringMass_function_ZeroCrossings,
   DualSpringMass_function_updateRelations,
   DualSpringMass_zeroCrossingDescription,
   DualSpringMass_relationDescription,
   DualSpringMass_function_initSample,
   DualSpringMass_INDEX_JAC_A,
   DualSpringMass_INDEX_JAC_B,
   DualSpringMass_INDEX_JAC_C,
   DualSpringMass_INDEX_JAC_D,
   DualSpringMass_INDEX_JAC_F,
   DualSpringMass_INDEX_JAC_H,
   DualSpringMass_initialAnalyticJacobianA,
   DualSpringMass_initialAnalyticJacobianB,
   DualSpringMass_initialAnalyticJacobianC,
   DualSpringMass_initialAnalyticJacobianD,
   DualSpringMass_initialAnalyticJacobianF,
   DualSpringMass_initialAnalyticJacobianH,
   DualSpringMass_functionJacA_column,
   DualSpringMass_functionJacB_column,
   DualSpringMass_functionJacC_column,
   DualSpringMass_functionJacD_column,
   DualSpringMass_functionJacF_column,
   DualSpringMass_functionJacH_column,
   DualSpringMass_linear_model_frame,
   DualSpringMass_linear_model_datarecovery_frame,
   DualSpringMass_mayer,
   DualSpringMass_lagrange,
   DualSpringMass_pickUpBoundsForInputsInOptimization,
   DualSpringMass_setInputData,
   DualSpringMass_getTimeGrid,
   DualSpringMass_symbolicInlineSystem,
   DualSpringMass_function_initSynchronous,
   DualSpringMass_function_updateSynchronous,
   DualSpringMass_function_equationsSynchronous,
   DualSpringMass_inputNames,
   DualSpringMass_dataReconciliationInputNames,
   DualSpringMass_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "DualSpringMass"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/Desktop/AFM/cases/20260410_130109_DualSpringMass/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,14,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,67,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void DualSpringMass_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &DualSpringMass_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "DualSpringMass";
  data->modelData->modelFilePrefix = "DualSpringMass";
  data->modelData->modelFileName = "DualSpringMass.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/cases/20260410_130109_DualSpringMass/model";
  data->modelData->modelGUID = "{4083eb23-01ae-44f8-8668-5e2963c068e9}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "DualSpringMass_init.c"
    ;
  static const char contents_info[] =
    #include "DualSpringMass_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "DualSpringMass_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "DualSpringMass_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "DualSpringMass_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 4;
  data->modelData->nVariablesRealArray = 14;
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
  data->modelData->modelDataXml.nEquations = 29;
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
  
    DualSpringMass_setupDataStruc(&data, threadData);
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


