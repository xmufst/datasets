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
equation index: 15
type: SIMPLE_ASSIGN
E_capacitor = 0.5 * C * capacitor.v ^ 2.0
*/
void RCCircuit_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* capacitor.v STATE(1) */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* E_capacitor variable */) = (0.5) * (((data->simulationInfo->realParameter[0] /* C PARAM */)) * ((tmp0 * tmp0)));
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
V_in = stepSignal.offset + (if time < stepSignal.startTime then 0.0 else stepSignal.height)
*/
void RCCircuit_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  modelica_boolean tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  tmp2 = 1.0;
  tmp3 = fabs((data->simulationInfo->realParameter[12] /* stepSignal.startTime PARAM */));
  relationhysteresis(data, &tmp1, data->localData[0]->timeValue, (data->simulationInfo->realParameter[12] /* stepSignal.startTime PARAM */), tmp2, tmp3, 0, Less, LessZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* V_in variable */) = (data->simulationInfo->realParameter[11] /* stepSignal.offset PARAM */) + (tmp1?0.0:(data->simulationInfo->realParameter[10] /* stepSignal.height PARAM */));
  TRACE_POP
}
/*
equation index: 17
type: SIMPLE_ASSIGN
resistor.v = V_in - capacitor.v
*/
void RCCircuit_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* resistor.v variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* V_in variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* capacitor.v STATE(1) */);
  TRACE_POP
}
/*
equation index: 18
type: SIMPLE_ASSIGN
i = resistor.v / resistor.R_actual
*/
void RCCircuit_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* i variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* resistor.v variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* resistor.R_actual variable */),"resistor.R_actual",equationIndexes);
  TRACE_POP
}
/*
equation index: 19
type: SIMPLE_ASSIGN
resistor.LossPower = resistor.v * i
*/
void RCCircuit_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* resistor.LossPower variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* resistor.v variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* i variable */));
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
$DER.capacitor.v = i / capacitor.C
*/
void RCCircuit_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(capacitor.v) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* i variable */),(data->simulationInfo->realParameter[4] /* capacitor.C PARAM */),"capacitor.C",equationIndexes);
  TRACE_POP
}
/*
equation index: 21
type: SIMPLE_ASSIGN
P_resistor = R * i ^ 2.0
*/
void RCCircuit_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  modelica_real tmp4;
  tmp4 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* i variable */);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* P_resistor variable */) = ((data->simulationInfo->realParameter[1] /* R PARAM */)) * ((tmp4 * tmp4));
  TRACE_POP
}
/*
equation index: 22
type: SIMPLE_ASSIGN
$DER.E_dissipated = P_resistor
*/
void RCCircuit_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(E_dissipated) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* P_resistor variable */);
  TRACE_POP
}
/*
equation index: 23
type: ALGORITHM

  assert(1.0 + resistor.alpha * (resistor.T - resistor.T_ref) >= 1e-15, "Temperature outside scope of model!");
*/
void RCCircuit_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  modelica_boolean tmp5;
  static const MMC_DEFSTRINGLIT(tmp6,35,"Temperature outside scope of model!");
  static int tmp7 = 0;
  {
    tmp5 = GreaterEq(1.0 + ((data->simulationInfo->realParameter[9] /* resistor.alpha PARAM */)) * ((data->simulationInfo->realParameter[6] /* resistor.T PARAM */) - (data->simulationInfo->realParameter[8] /* resistor.T_ref PARAM */)),1e-15);
    if(!tmp5)
    {
      {
        const char* assert_cond = "(1.0 + resistor.alpha * (resistor.T - resistor.T_ref) >= 1e-15)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Electrical/Analog/Basic/Resistor.mo",15,3,16,43,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp6)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Electrical/Analog/Basic/Resistor.mo",15,3,16,43,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp6)));
        }
      }
    }
  }
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
  RCCircuit_eqFunction_15(data, threadData);

  RCCircuit_eqFunction_16(data, threadData);

  RCCircuit_eqFunction_17(data, threadData);

  RCCircuit_eqFunction_18(data, threadData);

  RCCircuit_eqFunction_19(data, threadData);

  RCCircuit_eqFunction_20(data, threadData);

  RCCircuit_eqFunction_21(data, threadData);

  RCCircuit_eqFunction_22(data, threadData);

  RCCircuit_eqFunction_23(data, threadData);
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
extern void RCCircuit_eqFunction_16(DATA* data, threadData_t *threadData);
extern void RCCircuit_eqFunction_17(DATA* data, threadData_t *threadData);
extern void RCCircuit_eqFunction_18(DATA* data, threadData_t *threadData);
extern void RCCircuit_eqFunction_20(DATA* data, threadData_t *threadData);
extern void RCCircuit_eqFunction_21(DATA* data, threadData_t *threadData);
extern void RCCircuit_eqFunction_22(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[6])(DATA*, threadData_t*) = {
    RCCircuit_eqFunction_16,
    RCCircuit_eqFunction_17,
    RCCircuit_eqFunction_18,
    RCCircuit_eqFunction_20,
    RCCircuit_eqFunction_21,
    RCCircuit_eqFunction_22
  };
  
  static const int eqIndices[6] = {
    16,
    17,
    18,
    20,
    21,
    22
  };
  
  for (id = 0; id < 6; id++) {
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* capacitor.v STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(E_dissipated) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(capacitor.v) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_capacitor variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* P_resistor variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* V_in variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* ground.p.i variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* ground.p.v variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* i variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* resistor.LossPower variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* resistor.R_actual variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* resistor.v variable */
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

#define _OMC_LIT_RESOURCE_3_name_data "RCCircuit"
#define _OMC_LIT_RESOURCE_3_dir_data "C:/Users/FST/Desktop/AFM/cases/20260410_131527_RCCircuit/build/src"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,9,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,66,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
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
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/cases/20260410_131527_RCCircuit/build/src";
  data->modelData->modelGUID = "{09df1360-8050-41e1-9b1b-624776480e81}";
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
  data->modelData->nVariablesRealArray = 14;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 14;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 1;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 18;
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
  data->modelData->modelDataXml.nEquations = 41;
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


