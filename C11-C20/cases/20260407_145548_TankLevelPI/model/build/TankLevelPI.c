/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "TankLevelPI_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation TankLevelPI_performSimulation
#define prefixedName_updateContinuousSystem TankLevelPI_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation TankLevelPI_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int TankLevelPI_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankLevelPI_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankLevelPI_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankLevelPI_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankLevelPI_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int TankLevelPI_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankLevelPI_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankLevelPI_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankLevelPI_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int TankLevelPI_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 20
type: SIMPLE_ASSIGN
h_error = h_ref_signal.k - h
*/
void TankLevelPI_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* h_error variable */) = (data->simulationInfo->realParameter[12] /* h_ref_signal.k PARAM */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* h STATE(1) */);
  TRACE_POP
}
/*
equation index: 21
type: SIMPLE_ASSIGN
$DER.PI_controller.x = h_error / PI_controller.T
*/
void TankLevelPI_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(PI_controller.x) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* h_error variable */),(data->simulationInfo->realParameter[2] /* PI_controller.T PARAM */),"PI_controller.T",equationIndexes);
  TRACE_POP
}
/*
equation index: 22
type: SIMPLE_ASSIGN
u_pi = PI_controller.k * (PI_controller.x + h_error)
*/
void TankLevelPI_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */) = ((data->simulationInfo->realParameter[3] /* PI_controller.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* PI_controller.x STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* h_error variable */));
  TRACE_POP
}
/*
equation index: 23
type: SIMPLE_ASSIGN
limiter.y = smooth(0, if u_pi > limiter.uMax then limiter.uMax else if u_pi < limiter.uMin then limiter.uMin else u_pi)
*/
void TankLevelPI_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */),(data->simulationInfo->realParameter[15] /* limiter.uMax PARAM */));
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = (data->simulationInfo->realParameter[15] /* limiter.uMax PARAM */);
  }
  else
  {
    tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */),(data->simulationInfo->realParameter[16] /* limiter.uMin PARAM */));
    tmp3 = (tmp1?(data->simulationInfo->realParameter[16] /* limiter.uMin PARAM */):(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */));
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* limiter.y variable */) = tmp3;
  TRACE_POP
}
/*
equation index: 24
type: SIMPLE_ASSIGN
Q_in = limiter.y * Qmax_constant.k
*/
void TankLevelPI_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* Q_in variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* limiter.y variable */)) * ((data->simulationInfo->realParameter[7] /* Qmax_constant.k PARAM */));
  TRACE_POP
}
/*
equation index: 25
type: SIMPLE_ASSIGN
Q_out = k_out * sqrt(max(h, 0.0))
*/
void TankLevelPI_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  modelica_real tmp4;
  tmp4 = fmax((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* h STATE(1) */),0.0);
  if(!(tmp4 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(max(h, 0.0)) was %g should be >= 0", tmp4);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* Q_out variable */) = ((data->simulationInfo->realParameter[14] /* k_out PARAM */)) * (sqrt(tmp4));
  TRACE_POP
}
/*
equation index: 26
type: SIMPLE_ASSIGN
$DER.h = (Q_in - Q_out) / A_tank
*/
void TankLevelPI_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(h) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* Q_in variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* Q_out variable */),(data->simulationInfo->realParameter[0] /* A_tank PARAM */),"A_tank",equationIndexes);
  TRACE_POP
}
/*
equation index: 27
type: ALGORITHM

  assert(limiter.uMax >= limiter.uMin, "Limiter: Limits must be consistent. However, uMax (=" + String(limiter.uMax, 6, 0, true) + ") < uMin (=" + String(limiter.uMin, 6, 0, true) + ")");
*/
void TankLevelPI_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  modelica_boolean tmp5;
  static const MMC_DEFSTRINGLIT(tmp6,52,"Limiter: Limits must be consistent. However, uMax (=");
  modelica_string tmp7;
  modelica_metatype tmpMeta8;
  static const MMC_DEFSTRINGLIT(tmp9,11,") < uMin (=");
  modelica_metatype tmpMeta10;
  modelica_string tmp11;
  modelica_metatype tmpMeta12;
  modelica_metatype tmpMeta13;
  static int tmp14 = 0;
  {
    tmp5 = GreaterEq((data->simulationInfo->realParameter[15] /* limiter.uMax PARAM */),(data->simulationInfo->realParameter[16] /* limiter.uMin PARAM */));
    if(!tmp5)
    {
      tmp7 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[15] /* limiter.uMax PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta8 = stringAppend(MMC_REFSTRINGLIT(tmp6),tmp7);
      tmpMeta10 = stringAppend(tmpMeta8,MMC_REFSTRINGLIT(tmp9));
      tmp11 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[16] /* limiter.uMin PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta12 = stringAppend(tmpMeta10,tmp11);
      tmpMeta13 = stringAppend(tmpMeta12,(modelica_string) mmc_strings_len1[41]);
      {
        const char* assert_cond = "(limiter.uMax >= limiter.uMin)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta13));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta13));
        }
      }
    }
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int TankLevelPI_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  TankLevelPI_functionLocalKnownVars(data, threadData);
  TankLevelPI_eqFunction_20(data, threadData);

  TankLevelPI_eqFunction_21(data, threadData);

  TankLevelPI_eqFunction_22(data, threadData);

  TankLevelPI_eqFunction_23(data, threadData);

  TankLevelPI_eqFunction_24(data, threadData);

  TankLevelPI_eqFunction_25(data, threadData);

  TankLevelPI_eqFunction_26(data, threadData);

  TankLevelPI_eqFunction_27(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int TankLevelPI_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void TankLevelPI_eqFunction_20(DATA* data, threadData_t *threadData);
extern void TankLevelPI_eqFunction_21(DATA* data, threadData_t *threadData);
extern void TankLevelPI_eqFunction_22(DATA* data, threadData_t *threadData);
extern void TankLevelPI_eqFunction_23(DATA* data, threadData_t *threadData);
extern void TankLevelPI_eqFunction_24(DATA* data, threadData_t *threadData);
extern void TankLevelPI_eqFunction_25(DATA* data, threadData_t *threadData);
extern void TankLevelPI_eqFunction_26(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[7])(DATA*, threadData_t*) = {
    TankLevelPI_eqFunction_20,
    TankLevelPI_eqFunction_21,
    TankLevelPI_eqFunction_22,
    TankLevelPI_eqFunction_23,
    TankLevelPI_eqFunction_24,
    TankLevelPI_eqFunction_25,
    TankLevelPI_eqFunction_26
  };
  
  static const int eqIndices[7] = {
    20,
    21,
    22,
    23,
    24,
    25,
    26
  };
  
  for (id = 0; id < 7; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int TankLevelPI_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  TankLevelPI_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void TankLevelPI_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* PI_controller.x STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* h STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(PI_controller.x) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(h) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_in variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_out variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* h_error variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* limiter.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* u_pi variable */
  
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

#include "TankLevelPI_12jac.h"
#include "TankLevelPI_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks TankLevelPI_callback = {
   (int (*)(DATA *, threadData_t *, void *)) TankLevelPI_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) TankLevelPI_performQSSSimulation,    /* performQSSSimulation */
   TankLevelPI_updateContinuousSystem,    /* updateContinuousSystem */
   TankLevelPI_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   TankLevelPI_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   TankLevelPI_initializeDAEmodeData,
   TankLevelPI_computeVarIndices,
   TankLevelPI_functionODE,
   TankLevelPI_functionAlgebraics,
   TankLevelPI_functionDAE,
   TankLevelPI_functionLocalKnownVars,
   TankLevelPI_input_function,
   TankLevelPI_input_function_init,
   TankLevelPI_input_function_updateStartValues,
   TankLevelPI_data_function,
   TankLevelPI_output_function,
   TankLevelPI_setc_function,
   TankLevelPI_setb_function,
   TankLevelPI_function_storeDelayed,
   TankLevelPI_function_storeSpatialDistribution,
   TankLevelPI_function_initSpatialDistribution,
   TankLevelPI_updateBoundVariableAttributes,
   TankLevelPI_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   TankLevelPI_functionInitialEquations_lambda0,
   TankLevelPI_functionRemovedInitialEquations,
   TankLevelPI_updateBoundParameters,
   TankLevelPI_checkForAsserts,
   TankLevelPI_function_ZeroCrossingsEquations,
   TankLevelPI_function_ZeroCrossings,
   TankLevelPI_function_updateRelations,
   TankLevelPI_zeroCrossingDescription,
   TankLevelPI_relationDescription,
   TankLevelPI_function_initSample,
   TankLevelPI_INDEX_JAC_A,
   TankLevelPI_INDEX_JAC_B,
   TankLevelPI_INDEX_JAC_C,
   TankLevelPI_INDEX_JAC_D,
   TankLevelPI_INDEX_JAC_F,
   TankLevelPI_INDEX_JAC_H,
   TankLevelPI_initialAnalyticJacobianA,
   TankLevelPI_initialAnalyticJacobianB,
   TankLevelPI_initialAnalyticJacobianC,
   TankLevelPI_initialAnalyticJacobianD,
   TankLevelPI_initialAnalyticJacobianF,
   TankLevelPI_initialAnalyticJacobianH,
   TankLevelPI_functionJacA_column,
   TankLevelPI_functionJacB_column,
   TankLevelPI_functionJacC_column,
   TankLevelPI_functionJacD_column,
   TankLevelPI_functionJacF_column,
   TankLevelPI_functionJacH_column,
   TankLevelPI_linear_model_frame,
   TankLevelPI_linear_model_datarecovery_frame,
   TankLevelPI_mayer,
   TankLevelPI_lagrange,
   TankLevelPI_pickUpBoundsForInputsInOptimization,
   TankLevelPI_setInputData,
   TankLevelPI_getTimeGrid,
   TankLevelPI_symbolicInlineSystem,
   TankLevelPI_function_initSynchronous,
   TankLevelPI_function_updateSynchronous,
   TankLevelPI_function_equationsSynchronous,
   TankLevelPI_inputNames,
   TankLevelPI_dataReconciliationInputNames,
   TankLevelPI_dataReconciliationUnmeasuredVariables,
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

#define _OMC_LIT_RESOURCE_3_name_data "TankLevelPI"
#define _OMC_LIT_RESOURCE_3_dir_data "C:/Users/FST/Desktop/AFM/cases/20260407_145548_TankLevelPI/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,11,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,64,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void TankLevelPI_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &TankLevelPI_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "TankLevelPI";
  data->modelData->modelFilePrefix = "TankLevelPI";
  data->modelData->modelFileName = "TankLevelPI.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/cases/20260407_145548_TankLevelPI/model";
  data->modelData->modelGUID = "{4a3ee335-9fe0-48f8-9131-2f1ffb97ca8a}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "TankLevelPI_init.c"
    ;
  static const char contents_info[] =
    #include "TankLevelPI_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "TankLevelPI_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "TankLevelPI_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "TankLevelPI_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 9;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 18;
  data->modelData->nParametersInteger = 2;
  data->modelData->nParametersBoolean = 1;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 9;
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
  data->modelData->modelDataXml.nEquations = 43;
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
  
    TankLevelPI_setupDataStruc(&data, threadData);
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


