/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "FallingWithDrag_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation FallingWithDrag_performSimulation
#define prefixedName_updateContinuousSystem FallingWithDrag_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation FallingWithDrag_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int FallingWithDrag_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FallingWithDrag_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FallingWithDrag_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FallingWithDrag_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FallingWithDrag_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int FallingWithDrag_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FallingWithDrag_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FallingWithDrag_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FallingWithDrag_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int FallingWithDrag_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 15
type: SIMPLE_ASSIGN
E_potential_lost = m * g * y
*/
void FallingWithDrag_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* E_potential_lost variable */) = ((data->simulationInfo->realParameter[2] /* m PARAM */)) * (((data->simulationInfo->realParameter[1] /* g PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* y STATE(1,v) */)));
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
E_kinetic = 0.5 * m * v ^ 2.0
*/
void FallingWithDrag_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1,a) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* E_kinetic variable */) = (0.5) * (((data->simulationInfo->realParameter[2] /* m PARAM */)) * ((tmp0 * tmp0)));
  TRACE_POP
}
/*
equation index: 17
type: SIMPLE_ASSIGN
v_ratio = v / v_terminal
*/
void FallingWithDrag_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* v_ratio variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1,a) */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* v_terminal variable */),"v_terminal",equationIndexes);
  TRACE_POP
}
/*
equation index: 18
type: SIMPLE_ASSIGN
F_drag = b * v * abs(v)
*/
void FallingWithDrag_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* F_drag variable */) = ((data->simulationInfo->realParameter[0] /* b PARAM */)) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1,a) */)) * (fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1,a) */))));
  TRACE_POP
}
/*
equation index: 19
type: SIMPLE_ASSIGN
F_net = F_gravity - (*Real*)(sign(v)) * F_drag
*/
void FallingWithDrag_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* F_net variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* F_gravity variable */) - ((((modelica_real)sign((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1,a) */)))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* F_drag variable */)));
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
a = F_net / m
*/
void FallingWithDrag_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* a variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* F_net variable */),(data->simulationInfo->realParameter[2] /* m PARAM */),"m",equationIndexes);
  TRACE_POP
}
/*
equation index: 21
type: SIMPLE_ASSIGN
$DER.v = a
*/
void FallingWithDrag_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* der(v) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* a variable */);
  TRACE_POP
}
/*
equation index: 22
type: SIMPLE_ASSIGN
$DER.E_dissipated = F_drag * abs(v)
*/
void FallingWithDrag_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(E_dissipated) STATE_DER */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* F_drag variable */)) * (fabs((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1,a) */)));
  TRACE_POP
}
/*
equation index: 23
type: SIMPLE_ASSIGN
$DER.y = v
*/
void FallingWithDrag_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* der(y) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1,a) */);
  TRACE_POP
}
/*
equation index: 24
type: ALGORITHM

  assert(v >= -0.001, "Velocity should not become significantly negative in free fall");
*/
void FallingWithDrag_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,62,"Velocity should not become significantly negative in free fall");
  static int tmp3 = 0;
  {
    tmp1 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1,a) */),-0.001);
    if(!tmp1)
    {
      {
        const char* assert_cond = "(v >= -0.001)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/Desktop/第一类数据/cases/20260330_153931_FallingWithDrag/model/FallingWithDrag.mo",59,3,59,87,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp2)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/FST/Desktop/第一类数据/cases/20260330_153931_FallingWithDrag/model/FallingWithDrag.mo",59,3,59,87,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp2)));
        }
      }
    }
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int FallingWithDrag_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  FallingWithDrag_functionLocalKnownVars(data, threadData);
  FallingWithDrag_eqFunction_15(data, threadData);

  FallingWithDrag_eqFunction_16(data, threadData);

  FallingWithDrag_eqFunction_17(data, threadData);

  FallingWithDrag_eqFunction_18(data, threadData);

  FallingWithDrag_eqFunction_19(data, threadData);

  FallingWithDrag_eqFunction_20(data, threadData);

  FallingWithDrag_eqFunction_21(data, threadData);

  FallingWithDrag_eqFunction_22(data, threadData);

  FallingWithDrag_eqFunction_23(data, threadData);

  FallingWithDrag_eqFunction_24(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int FallingWithDrag_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void FallingWithDrag_eqFunction_18(DATA* data, threadData_t *threadData);
extern void FallingWithDrag_eqFunction_19(DATA* data, threadData_t *threadData);
extern void FallingWithDrag_eqFunction_20(DATA* data, threadData_t *threadData);
extern void FallingWithDrag_eqFunction_21(DATA* data, threadData_t *threadData);
extern void FallingWithDrag_eqFunction_22(DATA* data, threadData_t *threadData);
extern void FallingWithDrag_eqFunction_23(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[6])(DATA*, threadData_t*) = {
    FallingWithDrag_eqFunction_18,
    FallingWithDrag_eqFunction_19,
    FallingWithDrag_eqFunction_20,
    FallingWithDrag_eqFunction_21,
    FallingWithDrag_eqFunction_22,
    FallingWithDrag_eqFunction_23
  };
  
  static const int eqIndices[6] = {
    18,
    19,
    20,
    21,
    22,
    23
  };
  
  for (id = 0; id < 6; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int FallingWithDrag_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  FallingWithDrag_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void FallingWithDrag_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_dissipated STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* v STATE(1,a) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* y STATE(1,v) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(E_dissipated) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(v) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(y) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_kinetic variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_potential_lost variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_drag variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_gravity variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* F_net variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* a variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* v_ratio variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* v_terminal variable */
  
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

#include "FallingWithDrag_12jac.h"
#include "FallingWithDrag_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks FallingWithDrag_callback = {
   (int (*)(DATA *, threadData_t *, void *)) FallingWithDrag_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) FallingWithDrag_performQSSSimulation,    /* performQSSSimulation */
   FallingWithDrag_updateContinuousSystem,    /* updateContinuousSystem */
   FallingWithDrag_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   FallingWithDrag_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   FallingWithDrag_initializeDAEmodeData,
   FallingWithDrag_computeVarIndices,
   FallingWithDrag_functionODE,
   FallingWithDrag_functionAlgebraics,
   FallingWithDrag_functionDAE,
   FallingWithDrag_functionLocalKnownVars,
   FallingWithDrag_input_function,
   FallingWithDrag_input_function_init,
   FallingWithDrag_input_function_updateStartValues,
   FallingWithDrag_data_function,
   FallingWithDrag_output_function,
   FallingWithDrag_setc_function,
   FallingWithDrag_setb_function,
   FallingWithDrag_function_storeDelayed,
   FallingWithDrag_function_storeSpatialDistribution,
   FallingWithDrag_function_initSpatialDistribution,
   FallingWithDrag_updateBoundVariableAttributes,
   FallingWithDrag_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   FallingWithDrag_functionRemovedInitialEquations,
   FallingWithDrag_updateBoundParameters,
   FallingWithDrag_checkForAsserts,
   FallingWithDrag_function_ZeroCrossingsEquations,
   FallingWithDrag_function_ZeroCrossings,
   FallingWithDrag_function_updateRelations,
   FallingWithDrag_zeroCrossingDescription,
   FallingWithDrag_relationDescription,
   FallingWithDrag_function_initSample,
   FallingWithDrag_INDEX_JAC_A,
   FallingWithDrag_INDEX_JAC_B,
   FallingWithDrag_INDEX_JAC_C,
   FallingWithDrag_INDEX_JAC_D,
   FallingWithDrag_INDEX_JAC_F,
   FallingWithDrag_INDEX_JAC_H,
   FallingWithDrag_initialAnalyticJacobianA,
   FallingWithDrag_initialAnalyticJacobianB,
   FallingWithDrag_initialAnalyticJacobianC,
   FallingWithDrag_initialAnalyticJacobianD,
   FallingWithDrag_initialAnalyticJacobianF,
   FallingWithDrag_initialAnalyticJacobianH,
   FallingWithDrag_functionJacA_column,
   FallingWithDrag_functionJacB_column,
   FallingWithDrag_functionJacC_column,
   FallingWithDrag_functionJacD_column,
   FallingWithDrag_functionJacF_column,
   FallingWithDrag_functionJacH_column,
   FallingWithDrag_linear_model_frame,
   FallingWithDrag_linear_model_datarecovery_frame,
   FallingWithDrag_mayer,
   FallingWithDrag_lagrange,
   FallingWithDrag_pickUpBoundsForInputsInOptimization,
   FallingWithDrag_setInputData,
   FallingWithDrag_getTimeGrid,
   FallingWithDrag_symbolicInlineSystem,
   FallingWithDrag_function_initSynchronous,
   FallingWithDrag_function_updateSynchronous,
   FallingWithDrag_function_equationsSynchronous,
   FallingWithDrag_inputNames,
   FallingWithDrag_dataReconciliationInputNames,
   FallingWithDrag_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "FallingWithDrag"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/Desktop/第一类数据/cases/20260330_153931_FallingWithDrag/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,15,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,80,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void FallingWithDrag_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &FallingWithDrag_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "FallingWithDrag";
  data->modelData->modelFilePrefix = "FallingWithDrag";
  data->modelData->modelFileName = "FallingWithDrag.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/第一类数据/cases/20260330_153931_FallingWithDrag/model";
  data->modelData->modelGUID = "{db7d4764-2dc9-480e-8c79-efef52d22fc8}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "FallingWithDrag_init.c"
    ;
  static const char contents_info[] =
    #include "FallingWithDrag_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "FallingWithDrag_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "FallingWithDrag_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "FallingWithDrag_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 3;
  data->modelData->nVariablesRealArray = 14;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 4;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 1;
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
  
    FallingWithDrag_setupDataStruc(&data, threadData);
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


