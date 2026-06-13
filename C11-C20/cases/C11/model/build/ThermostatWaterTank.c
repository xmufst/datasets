/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "ThermostatWaterTank_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation ThermostatWaterTank_performSimulation
#define prefixedName_updateContinuousSystem ThermostatWaterTank_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation ThermostatWaterTank_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int ThermostatWaterTank_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ThermostatWaterTank_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ThermostatWaterTank_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ThermostatWaterTank_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ThermostatWaterTank_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int ThermostatWaterTank_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ThermostatWaterTank_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ThermostatWaterTank_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ThermostatWaterTank_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ThermostatWaterTank_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 9
type: SIMPLE_ASSIGN
T_error = T_set_const.k - T
*/
void ThermostatWaterTank_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_error variable */) = (data->simulationInfo->realParameter[4] /* T_set_const.k PARAM */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */);
  TRACE_POP
}
/*
equation index: 10
type: SIMPLE_ASSIGN
hysteresis.y = not pre(hysteresis.y) and T_error > hysteresis.uHigh or pre(hysteresis.y) and T_error >= hysteresis.uLow
*/
void ThermostatWaterTank_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[11] /* hysteresis.uHigh PARAM */));
  relationhysteresis(data, &tmp0, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_error variable */), (data->simulationInfo->realParameter[11] /* hysteresis.uHigh PARAM */), tmp1, tmp2, 0, Greater, GreaterZC);
  tmp4 = 1.0;
  tmp5 = fabs((data->simulationInfo->realParameter[12] /* hysteresis.uLow PARAM */));
  relationhysteresis(data, &tmp3, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_error variable */), (data->simulationInfo->realParameter[12] /* hysteresis.uLow PARAM */), tmp4, tmp5, 1, GreaterEq, GreaterEqZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* hysteresis.y DISCRETE */) = (((!(data->simulationInfo->booleanVarsPre[0] /* hysteresis.y DISCRETE */)) && tmp0) || ((data->simulationInfo->booleanVarsPre[0] /* hysteresis.y DISCRETE */) && tmp3));
  TRACE_POP
}
/*
equation index: 11
type: SIMPLE_ASSIGN
Q_in = if hysteresis.y then booleanToReal.realTrue else booleanToReal.realFalse
*/
void ThermostatWaterTank_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* Q_in variable */) = ((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* hysteresis.y DISCRETE */)?(data->simulationInfo->realParameter[8] /* booleanToReal.realTrue PARAM */):(data->simulationInfo->realParameter[7] /* booleanToReal.realFalse PARAM */));
  TRACE_POP
}
/*
equation index: 12
type: SIMPLE_ASSIGN
Q_loss = UA * (T - T_amb)
*/
void ThermostatWaterTank_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* Q_loss variable */) = ((data->simulationInfo->realParameter[6] /* UA PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */) - (data->simulationInfo->realParameter[2] /* T_amb PARAM */));
  TRACE_POP
}
/*
equation index: 13
type: SIMPLE_ASSIGN
$DER.T = (Q_in - Q_loss) / C
*/
void ThermostatWaterTank_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* der(T) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* Q_in variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* Q_loss variable */),(data->simulationInfo->realParameter[0] /* C PARAM */),"C",equationIndexes);
  TRACE_POP
}
/*
equation index: 14
type: ALGORITHM

  assert(hysteresis.uHigh > hysteresis.uLow, "Hysteresis limits wrong (uHigh <= uLow)");
*/
void ThermostatWaterTank_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  modelica_boolean tmp6;
  static const MMC_DEFSTRINGLIT(tmp7,39,"Hysteresis limits wrong (uHigh <= uLow)");
  static int tmp8 = 0;
  {
    tmp6 = Greater((data->simulationInfo->realParameter[11] /* hysteresis.uHigh PARAM */),(data->simulationInfo->realParameter[12] /* hysteresis.uLow PARAM */));
    if(!tmp6)
    {
      {
        const char* assert_cond = "(hysteresis.uHigh > hysteresis.uLow)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Logical.mo",523,5,523,67,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp7)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Logical.mo",523,5,523,67,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp7)));
        }
      }
    }
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int ThermostatWaterTank_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  ThermostatWaterTank_functionLocalKnownVars(data, threadData);
  ThermostatWaterTank_eqFunction_9(data, threadData);

  ThermostatWaterTank_eqFunction_10(data, threadData);

  ThermostatWaterTank_eqFunction_11(data, threadData);

  ThermostatWaterTank_eqFunction_12(data, threadData);

  ThermostatWaterTank_eqFunction_13(data, threadData);

  ThermostatWaterTank_eqFunction_14(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int ThermostatWaterTank_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void ThermostatWaterTank_eqFunction_9(DATA* data, threadData_t *threadData);
extern void ThermostatWaterTank_eqFunction_10(DATA* data, threadData_t *threadData);
extern void ThermostatWaterTank_eqFunction_11(DATA* data, threadData_t *threadData);
extern void ThermostatWaterTank_eqFunction_12(DATA* data, threadData_t *threadData);
extern void ThermostatWaterTank_eqFunction_13(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[5])(DATA*, threadData_t*) = {
    ThermostatWaterTank_eqFunction_9,
    ThermostatWaterTank_eqFunction_10,
    ThermostatWaterTank_eqFunction_11,
    ThermostatWaterTank_eqFunction_12,
    ThermostatWaterTank_eqFunction_13
  };
  
  static const int eqIndices[5] = {
    9,
    10,
    11,
    12,
    13
  };
  
  for (id = 0; id < 5; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int ThermostatWaterTank_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  ThermostatWaterTank_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void ThermostatWaterTank_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_in variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_loss variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_error variable */
  
  /* discreteAlgVars */
  
  /* realOptimizeConstraintsVars */
  
  /* realOptimizeFinalConstraintsVars */
  
  
  /* intAlgVars */
  
  /* boolAlgVars */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* hysteresis.y DISCRETE */
  
  /* stringAlgVars */
  
  TRACE_POP
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "ThermostatWaterTank_12jac.h"
#include "ThermostatWaterTank_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks ThermostatWaterTank_callback = {
   (int (*)(DATA *, threadData_t *, void *)) ThermostatWaterTank_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) ThermostatWaterTank_performQSSSimulation,    /* performQSSSimulation */
   ThermostatWaterTank_updateContinuousSystem,    /* updateContinuousSystem */
   ThermostatWaterTank_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   ThermostatWaterTank_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   ThermostatWaterTank_initializeDAEmodeData,
   ThermostatWaterTank_computeVarIndices,
   ThermostatWaterTank_functionODE,
   ThermostatWaterTank_functionAlgebraics,
   ThermostatWaterTank_functionDAE,
   ThermostatWaterTank_functionLocalKnownVars,
   ThermostatWaterTank_input_function,
   ThermostatWaterTank_input_function_init,
   ThermostatWaterTank_input_function_updateStartValues,
   ThermostatWaterTank_data_function,
   ThermostatWaterTank_output_function,
   ThermostatWaterTank_setc_function,
   ThermostatWaterTank_setb_function,
   ThermostatWaterTank_function_storeDelayed,
   ThermostatWaterTank_function_storeSpatialDistribution,
   ThermostatWaterTank_function_initSpatialDistribution,
   ThermostatWaterTank_updateBoundVariableAttributes,
   ThermostatWaterTank_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   ThermostatWaterTank_functionRemovedInitialEquations,
   ThermostatWaterTank_updateBoundParameters,
   ThermostatWaterTank_checkForAsserts,
   ThermostatWaterTank_function_ZeroCrossingsEquations,
   ThermostatWaterTank_function_ZeroCrossings,
   ThermostatWaterTank_function_updateRelations,
   ThermostatWaterTank_zeroCrossingDescription,
   ThermostatWaterTank_relationDescription,
   ThermostatWaterTank_function_initSample,
   ThermostatWaterTank_INDEX_JAC_A,
   ThermostatWaterTank_INDEX_JAC_B,
   ThermostatWaterTank_INDEX_JAC_C,
   ThermostatWaterTank_INDEX_JAC_D,
   ThermostatWaterTank_INDEX_JAC_F,
   ThermostatWaterTank_INDEX_JAC_H,
   ThermostatWaterTank_initialAnalyticJacobianA,
   ThermostatWaterTank_initialAnalyticJacobianB,
   ThermostatWaterTank_initialAnalyticJacobianC,
   ThermostatWaterTank_initialAnalyticJacobianD,
   ThermostatWaterTank_initialAnalyticJacobianF,
   ThermostatWaterTank_initialAnalyticJacobianH,
   ThermostatWaterTank_functionJacA_column,
   ThermostatWaterTank_functionJacB_column,
   ThermostatWaterTank_functionJacC_column,
   ThermostatWaterTank_functionJacD_column,
   ThermostatWaterTank_functionJacF_column,
   ThermostatWaterTank_functionJacH_column,
   ThermostatWaterTank_linear_model_frame,
   ThermostatWaterTank_linear_model_datarecovery_frame,
   ThermostatWaterTank_mayer,
   ThermostatWaterTank_lagrange,
   ThermostatWaterTank_pickUpBoundsForInputsInOptimization,
   ThermostatWaterTank_setInputData,
   ThermostatWaterTank_getTimeGrid,
   ThermostatWaterTank_symbolicInlineSystem,
   ThermostatWaterTank_function_initSynchronous,
   ThermostatWaterTank_function_updateSynchronous,
   ThermostatWaterTank_function_equationsSynchronous,
   ThermostatWaterTank_inputNames,
   ThermostatWaterTank_dataReconciliationInputNames,
   ThermostatWaterTank_dataReconciliationUnmeasuredVariables,
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

#define _OMC_LIT_RESOURCE_1_name_data "Modelica"
#define _OMC_LIT_RESOURCE_1_dir_data "C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,8,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,76,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_2_dir_data "C:/Users/FST/AppData/Roaming/.openmodelica/libraries/ModelicaServices 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,16,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,84,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "ThermostatWaterTank"
#define _OMC_LIT_RESOURCE_3_dir_data "C:/Users/FST/Desktop/AFM/cases/20260407_141845_ThermostatWaterTank/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,19,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,72,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void ThermostatWaterTank_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &ThermostatWaterTank_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "ThermostatWaterTank";
  data->modelData->modelFilePrefix = "ThermostatWaterTank";
  data->modelData->modelFileName = "ThermostatWaterTank.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/cases/20260407_141845_ThermostatWaterTank/model";
  data->modelData->modelGUID = "{966c22fd-663a-46bf-aac4-b2e99a7ffda8}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "ThermostatWaterTank_init.c"
    ;
  static const char contents_info[] =
    #include "ThermostatWaterTank_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "ThermostatWaterTank_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "ThermostatWaterTank_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "ThermostatWaterTank_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 1;
  data->modelData->nVariablesRealArray = 5;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 1;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 13;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 1;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 4;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 2;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 1;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 2;
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
  
    ThermostatWaterTank_setupDataStruc(&data, threadData);
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


