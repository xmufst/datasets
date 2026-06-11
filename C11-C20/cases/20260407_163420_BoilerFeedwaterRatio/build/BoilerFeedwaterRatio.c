/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "BoilerFeedwaterRatio_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation BoilerFeedwaterRatio_performSimulation
#define prefixedName_updateContinuousSystem BoilerFeedwaterRatio_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation BoilerFeedwaterRatio_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int BoilerFeedwaterRatio_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BoilerFeedwaterRatio_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BoilerFeedwaterRatio_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BoilerFeedwaterRatio_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BoilerFeedwaterRatio_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int BoilerFeedwaterRatio_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BoilerFeedwaterRatio_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BoilerFeedwaterRatio_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BoilerFeedwaterRatio_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int BoilerFeedwaterRatio_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 32
type: SIMPLE_ASSIGN
W_steam = steamFlowStep.offset + (if time < steamFlowStep.startTime then 0.0 else steamFlowStep.height)
*/
void BoilerFeedwaterRatio_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[19] /* steamFlowStep.startTime PARAM */));
  relationhysteresis(data, &tmp0, data->localData[0]->timeValue, (data->simulationInfo->realParameter[19] /* steamFlowStep.startTime PARAM */), tmp1, tmp2, 0, Less, LessZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* W_steam variable */) = (data->simulationInfo->realParameter[18] /* steamFlowStep.offset PARAM */) + (tmp0?0.0:(data->simulationInfo->realParameter[17] /* steamFlowStep.height PARAM */));
  TRACE_POP
}
void BoilerFeedwaterRatio_eqFunction_33(DATA*, threadData_t*);
void BoilerFeedwaterRatio_eqFunction_34(DATA*, threadData_t*);
void BoilerFeedwaterRatio_eqFunction_35(DATA*, threadData_t*);
void BoilerFeedwaterRatio_eqFunction_36(DATA*, threadData_t*);
void BoilerFeedwaterRatio_eqFunction_37(DATA*, threadData_t*);
/*
equation index: 42
indexNonlinear: 1
type: NONLINEAR

vars: {u_pi}
eqns: {33, 34, 35, 36, 37}
*/
void BoilerFeedwaterRatio_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  int retValue;
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving nonlinear system 42 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */);
  retValue = solve_nonlinear_system(data, threadData, 1);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,42};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 42 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */) = data->simulationInfo->nonlinearSystemData[1].nlsx[0];
  TRACE_POP
}
/*
equation index: 43
type: SIMPLE_ASSIGN
$DER.piController.x = ratio_error / piController.T
*/
void BoilerFeedwaterRatio_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(piController.x) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* ratio_error variable */),(data->simulationInfo->realParameter[10] /* piController.T PARAM */),"piController.T",equationIndexes);
  TRACE_POP
}
/*
equation index: 44
type: SIMPLE_ASSIGN
$DER.h_drum = (W_feedwater - W_steam) / A_eff
*/
void BoilerFeedwaterRatio_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(h_drum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* W_feedwater variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* W_steam variable */),(data->simulationInfo->realParameter[0] /* A_eff PARAM */),"A_eff",equationIndexes);
  TRACE_POP
}
/*
equation index: 45
type: ALGORITHM

  assert(valveLimiter.uMax >= valveLimiter.uMin, "Limiter: Limits must be consistent. However, uMax (=" + String(valveLimiter.uMax, 6, 0, true) + ") < uMin (=" + String(valveLimiter.uMin, 6, 0, true) + ")");
*/
void BoilerFeedwaterRatio_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,52,"Limiter: Limits must be consistent. However, uMax (=");
  modelica_string tmp2;
  modelica_metatype tmpMeta3;
  static const MMC_DEFSTRINGLIT(tmp4,11,") < uMin (=");
  modelica_metatype tmpMeta5;
  modelica_string tmp6;
  modelica_metatype tmpMeta7;
  modelica_metatype tmpMeta8;
  static int tmp9 = 0;
  {
    tmp0 = GreaterEq((data->simulationInfo->realParameter[21] /* valveLimiter.uMax PARAM */),(data->simulationInfo->realParameter[22] /* valveLimiter.uMin PARAM */));
    if(!tmp0)
    {
      tmp2 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[21] /* valveLimiter.uMax PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta3 = stringAppend(MMC_REFSTRINGLIT(tmp1),tmp2);
      tmpMeta5 = stringAppend(tmpMeta3,MMC_REFSTRINGLIT(tmp4));
      tmp6 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[22] /* valveLimiter.uMin PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta7 = stringAppend(tmpMeta5,tmp6);
      tmpMeta8 = stringAppend(tmpMeta7,(modelica_string) mmc_strings_len1[41]);
      {
        const char* assert_cond = "(valveLimiter.uMax >= valveLimiter.uMin)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
        }
      }
    }
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int BoilerFeedwaterRatio_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  BoilerFeedwaterRatio_functionLocalKnownVars(data, threadData);
  BoilerFeedwaterRatio_eqFunction_32(data, threadData);

  BoilerFeedwaterRatio_eqFunction_42(data, threadData);

  BoilerFeedwaterRatio_eqFunction_43(data, threadData);

  BoilerFeedwaterRatio_eqFunction_44(data, threadData);

  BoilerFeedwaterRatio_eqFunction_45(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int BoilerFeedwaterRatio_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void BoilerFeedwaterRatio_eqFunction_32(DATA* data, threadData_t *threadData);
extern void BoilerFeedwaterRatio_eqFunction_42(DATA* data, threadData_t *threadData);
extern void BoilerFeedwaterRatio_eqFunction_43(DATA* data, threadData_t *threadData);
extern void BoilerFeedwaterRatio_eqFunction_44(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[4])(DATA*, threadData_t*) = {
    BoilerFeedwaterRatio_eqFunction_32,
    BoilerFeedwaterRatio_eqFunction_42,
    BoilerFeedwaterRatio_eqFunction_43,
    BoilerFeedwaterRatio_eqFunction_44
  };
  
  static const int eqIndices[4] = {
    32,
    42,
    43,
    44
  };
  
  for (id = 0; id < 4; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int BoilerFeedwaterRatio_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  BoilerFeedwaterRatio_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void BoilerFeedwaterRatio_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* h_drum STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* piController.x STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(h_drum) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(piController.x) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* W_feedwater variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* W_steam variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* ratio_actual variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* ratio_error variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* u_pi variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* valve_opening variable */
  
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

#include "BoilerFeedwaterRatio_12jac.h"
#include "BoilerFeedwaterRatio_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks BoilerFeedwaterRatio_callback = {
   (int (*)(DATA *, threadData_t *, void *)) BoilerFeedwaterRatio_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) BoilerFeedwaterRatio_performQSSSimulation,    /* performQSSSimulation */
   BoilerFeedwaterRatio_updateContinuousSystem,    /* updateContinuousSystem */
   BoilerFeedwaterRatio_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   BoilerFeedwaterRatio_initialNonLinearSystem,    /* initialNonLinearSystem */
   BoilerFeedwaterRatio_initialLinearSystem,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   BoilerFeedwaterRatio_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   BoilerFeedwaterRatio_initializeDAEmodeData,
   BoilerFeedwaterRatio_computeVarIndices,
   BoilerFeedwaterRatio_functionODE,
   BoilerFeedwaterRatio_functionAlgebraics,
   BoilerFeedwaterRatio_functionDAE,
   BoilerFeedwaterRatio_functionLocalKnownVars,
   BoilerFeedwaterRatio_input_function,
   BoilerFeedwaterRatio_input_function_init,
   BoilerFeedwaterRatio_input_function_updateStartValues,
   BoilerFeedwaterRatio_data_function,
   BoilerFeedwaterRatio_output_function,
   BoilerFeedwaterRatio_setc_function,
   BoilerFeedwaterRatio_setb_function,
   BoilerFeedwaterRatio_function_storeDelayed,
   BoilerFeedwaterRatio_function_storeSpatialDistribution,
   BoilerFeedwaterRatio_function_initSpatialDistribution,
   BoilerFeedwaterRatio_updateBoundVariableAttributes,
   BoilerFeedwaterRatio_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   BoilerFeedwaterRatio_functionInitialEquations_lambda0,
   BoilerFeedwaterRatio_functionRemovedInitialEquations,
   BoilerFeedwaterRatio_updateBoundParameters,
   BoilerFeedwaterRatio_checkForAsserts,
   BoilerFeedwaterRatio_function_ZeroCrossingsEquations,
   BoilerFeedwaterRatio_function_ZeroCrossings,
   BoilerFeedwaterRatio_function_updateRelations,
   BoilerFeedwaterRatio_zeroCrossingDescription,
   BoilerFeedwaterRatio_relationDescription,
   BoilerFeedwaterRatio_function_initSample,
   BoilerFeedwaterRatio_INDEX_JAC_A,
   BoilerFeedwaterRatio_INDEX_JAC_B,
   BoilerFeedwaterRatio_INDEX_JAC_C,
   BoilerFeedwaterRatio_INDEX_JAC_D,
   BoilerFeedwaterRatio_INDEX_JAC_F,
   BoilerFeedwaterRatio_INDEX_JAC_H,
   BoilerFeedwaterRatio_initialAnalyticJacobianA,
   BoilerFeedwaterRatio_initialAnalyticJacobianB,
   BoilerFeedwaterRatio_initialAnalyticJacobianC,
   BoilerFeedwaterRatio_initialAnalyticJacobianD,
   BoilerFeedwaterRatio_initialAnalyticJacobianF,
   BoilerFeedwaterRatio_initialAnalyticJacobianH,
   BoilerFeedwaterRatio_functionJacA_column,
   BoilerFeedwaterRatio_functionJacB_column,
   BoilerFeedwaterRatio_functionJacC_column,
   BoilerFeedwaterRatio_functionJacD_column,
   BoilerFeedwaterRatio_functionJacF_column,
   BoilerFeedwaterRatio_functionJacH_column,
   BoilerFeedwaterRatio_linear_model_frame,
   BoilerFeedwaterRatio_linear_model_datarecovery_frame,
   BoilerFeedwaterRatio_mayer,
   BoilerFeedwaterRatio_lagrange,
   BoilerFeedwaterRatio_pickUpBoundsForInputsInOptimization,
   BoilerFeedwaterRatio_setInputData,
   BoilerFeedwaterRatio_getTimeGrid,
   BoilerFeedwaterRatio_symbolicInlineSystem,
   BoilerFeedwaterRatio_function_initSynchronous,
   BoilerFeedwaterRatio_function_updateSynchronous,
   BoilerFeedwaterRatio_function_equationsSynchronous,
   BoilerFeedwaterRatio_inputNames,
   BoilerFeedwaterRatio_dataReconciliationInputNames,
   BoilerFeedwaterRatio_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "BoilerFeedwaterRatio"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/Desktop/AFM/cases/20260407_163420_BoilerFeedwaterRatio/build/src"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,20,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,77,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "Complex"
#define _OMC_LIT_RESOURCE_1_dir_data "C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Complex 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,7,_OMC_LIT_RESOURCE_1_name_data);
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
void BoilerFeedwaterRatio_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &BoilerFeedwaterRatio_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "BoilerFeedwaterRatio";
  data->modelData->modelFilePrefix = "BoilerFeedwaterRatio";
  data->modelData->modelFileName = "BoilerFeedwaterRatio.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/cases/20260407_163420_BoilerFeedwaterRatio/build/src";
  data->modelData->modelGUID = "{37f51ef1-2d00-43e2-bff9-f0f7799e862d}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "BoilerFeedwaterRatio_init.c"
    ;
  static const char contents_info[] =
    #include "BoilerFeedwaterRatio_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "BoilerFeedwaterRatio_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "BoilerFeedwaterRatio_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "BoilerFeedwaterRatio_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 10;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 23;
  data->modelData->nParametersInteger = 2;
  data->modelData->nParametersBoolean = 1;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 13;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 3;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 3;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 64;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 1;
  data->modelData->nNonLinearSystems = 2;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 9;
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
  
    BoilerFeedwaterRatio_setupDataStruc(&data, threadData);
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


