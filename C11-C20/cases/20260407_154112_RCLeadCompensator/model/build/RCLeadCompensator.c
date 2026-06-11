/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "RCLeadCompensator_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation RCLeadCompensator_performSimulation
#define prefixedName_updateContinuousSystem RCLeadCompensator_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation RCLeadCompensator_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int RCLeadCompensator_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCLeadCompensator_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCLeadCompensator_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCLeadCompensator_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCLeadCompensator_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int RCLeadCompensator_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCLeadCompensator_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCLeadCompensator_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCLeadCompensator_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int RCLeadCompensator_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 22
type: SIMPLE_ASSIGN
step.y = step.offset + (if time < step.startTime then 0.0 else step.height)
*/
void RCLeadCompensator_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[19] /* step.startTime PARAM */));
  relationhysteresis(data, &tmp0, data->localData[0]->timeValue, (data->simulationInfo->realParameter[19] /* step.startTime PARAM */), tmp1, tmp2, 0, Less, LessZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* step.y variable */) = (data->simulationInfo->realParameter[18] /* step.offset PARAM */) + (tmp0?0.0:(data->simulationInfo->realParameter[17] /* step.height PARAM */));
  TRACE_POP
}
/*
equation index: 23
type: SIMPLE_ASSIGN
Vc_error = step.y - Vc
*/
void RCLeadCompensator_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* Vc_error variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* step.y variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Vc STATE(1) */);
  TRACE_POP
}
/*
equation index: 24
type: SIMPLE_ASSIGN
$DER.compensator.x_scaled[1] = (compensator.a_end * Vc_error - compensator.a[2] * compensator.x_scaled[1]) / compensator.a[1]
*/
void RCLeadCompensator_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(compensator.x_scaled[1]) STATE_DER */) = DIVISION_SIM(((data->simulationInfo->realParameter[7] /* compensator.a_end PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* Vc_error variable */)) - (((data->simulationInfo->realParameter[6] /* compensator.a[2] PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* compensator.x_scaled[1] STATE(1) */))),(data->simulationInfo->realParameter[5] /* compensator.a[1] PARAM */),"compensator.a[1]",equationIndexes);
  TRACE_POP
}
/*
equation index: 25
type: SIMPLE_ASSIGN
compensator.x[1] = compensator.x_scaled[1] / compensator.a_end
*/
void RCLeadCompensator_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* compensator.x[1] variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* compensator.x_scaled[1] STATE(1) */),(data->simulationInfo->realParameter[7] /* compensator.a_end PARAM */),"compensator.a_end",equationIndexes);
  TRACE_POP
}
/*
equation index: 26
type: SIMPLE_ASSIGN
u_compensator = (compensator.bb[2] - compensator.d * compensator.a[2]) * compensator.x[1] + compensator.d * Vc_error
*/
void RCLeadCompensator_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* u_compensator variable */) = ((data->simulationInfo->realParameter[11] /* compensator.bb[2] PARAM */) - (((data->simulationInfo->realParameter[12] /* compensator.d PARAM */)) * ((data->simulationInfo->realParameter[6] /* compensator.a[2] PARAM */)))) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* compensator.x[1] variable */)) + ((data->simulationInfo->realParameter[12] /* compensator.d PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* Vc_error variable */));
  TRACE_POP
}
/*
equation index: 27
type: SIMPLE_ASSIGN
V_in = smooth(0, if u_compensator > limiter.uMax then limiter.uMax else if u_compensator < limiter.uMin then limiter.uMin else u_compensator)
*/
void RCLeadCompensator_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  modelica_boolean tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_real tmp6;
  tmp3 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* u_compensator variable */),(data->simulationInfo->realParameter[15] /* limiter.uMax PARAM */));
  tmp5 = (modelica_boolean)tmp3;
  if(tmp5)
  {
    tmp6 = (data->simulationInfo->realParameter[15] /* limiter.uMax PARAM */);
  }
  else
  {
    tmp4 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* u_compensator variable */),(data->simulationInfo->realParameter[16] /* limiter.uMin PARAM */));
    tmp6 = (tmp4?(data->simulationInfo->realParameter[16] /* limiter.uMin PARAM */):(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* u_compensator variable */));
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* V_in variable */) = tmp6;
  TRACE_POP
}
/*
equation index: 28
type: SIMPLE_ASSIGN
i_R = (V_in - Vc) / R
*/
void RCLeadCompensator_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* i_R variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* V_in variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Vc STATE(1) */),(data->simulationInfo->realParameter[2] /* R PARAM */),"R",equationIndexes);
  TRACE_POP
}
/*
equation index: 29
type: SIMPLE_ASSIGN
$DER.Vc = i_R / C_val
*/
void RCLeadCompensator_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(Vc) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* i_R variable */),(data->simulationInfo->realParameter[0] /* C_val PARAM */),"C_val",equationIndexes);
  TRACE_POP
}
/*
equation index: 30
type: ALGORITHM

  assert(limiter.uMax >= limiter.uMin, "Limiter: Limits must be consistent. However, uMax (=" + String(limiter.uMax, 6, 0, true) + ") < uMin (=" + String(limiter.uMin, 6, 0, true) + ")");
*/
void RCLeadCompensator_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  modelica_boolean tmp7;
  static const MMC_DEFSTRINGLIT(tmp8,52,"Limiter: Limits must be consistent. However, uMax (=");
  modelica_string tmp9;
  modelica_metatype tmpMeta10;
  static const MMC_DEFSTRINGLIT(tmp11,11,") < uMin (=");
  modelica_metatype tmpMeta12;
  modelica_string tmp13;
  modelica_metatype tmpMeta14;
  modelica_metatype tmpMeta15;
  static int tmp16 = 0;
  {
    tmp7 = GreaterEq((data->simulationInfo->realParameter[15] /* limiter.uMax PARAM */),(data->simulationInfo->realParameter[16] /* limiter.uMin PARAM */));
    if(!tmp7)
    {
      tmp9 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[15] /* limiter.uMax PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta10 = stringAppend(MMC_REFSTRINGLIT(tmp8),tmp9);
      tmpMeta12 = stringAppend(tmpMeta10,MMC_REFSTRINGLIT(tmp11));
      tmp13 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[16] /* limiter.uMin PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta14 = stringAppend(tmpMeta12,tmp13);
      tmpMeta15 = stringAppend(tmpMeta14,(modelica_string) mmc_strings_len1[41]);
      {
        const char* assert_cond = "(limiter.uMax >= limiter.uMin)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta15));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta15));
        }
      }
    }
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int RCLeadCompensator_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  RCLeadCompensator_functionLocalKnownVars(data, threadData);
  RCLeadCompensator_eqFunction_22(data, threadData);

  RCLeadCompensator_eqFunction_23(data, threadData);

  RCLeadCompensator_eqFunction_24(data, threadData);

  RCLeadCompensator_eqFunction_25(data, threadData);

  RCLeadCompensator_eqFunction_26(data, threadData);

  RCLeadCompensator_eqFunction_27(data, threadData);

  RCLeadCompensator_eqFunction_28(data, threadData);

  RCLeadCompensator_eqFunction_29(data, threadData);

  RCLeadCompensator_eqFunction_30(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int RCLeadCompensator_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void RCLeadCompensator_eqFunction_22(DATA* data, threadData_t *threadData);
extern void RCLeadCompensator_eqFunction_23(DATA* data, threadData_t *threadData);
extern void RCLeadCompensator_eqFunction_24(DATA* data, threadData_t *threadData);
extern void RCLeadCompensator_eqFunction_25(DATA* data, threadData_t *threadData);
extern void RCLeadCompensator_eqFunction_26(DATA* data, threadData_t *threadData);
extern void RCLeadCompensator_eqFunction_27(DATA* data, threadData_t *threadData);
extern void RCLeadCompensator_eqFunction_28(DATA* data, threadData_t *threadData);
extern void RCLeadCompensator_eqFunction_29(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[8])(DATA*, threadData_t*) = {
    RCLeadCompensator_eqFunction_22,
    RCLeadCompensator_eqFunction_23,
    RCLeadCompensator_eqFunction_24,
    RCLeadCompensator_eqFunction_25,
    RCLeadCompensator_eqFunction_26,
    RCLeadCompensator_eqFunction_27,
    RCLeadCompensator_eqFunction_28,
    RCLeadCompensator_eqFunction_29
  };
  
  static const int eqIndices[8] = {
    22,
    23,
    24,
    25,
    26,
    27,
    28,
    29
  };
  
  for (id = 0; id < 8; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int RCLeadCompensator_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  RCLeadCompensator_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void RCLeadCompensator_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Vc STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* compensator.x_scaled[1] STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(Vc) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(compensator.x_scaled[1]) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* V_in variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Vc_error variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* compensator.x[1] variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* i_R variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* step.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* u_compensator variable */
  
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

#include "RCLeadCompensator_12jac.h"
#include "RCLeadCompensator_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks RCLeadCompensator_callback = {
   (int (*)(DATA *, threadData_t *, void *)) RCLeadCompensator_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) RCLeadCompensator_performQSSSimulation,    /* performQSSSimulation */
   RCLeadCompensator_updateContinuousSystem,    /* updateContinuousSystem */
   RCLeadCompensator_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   RCLeadCompensator_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   RCLeadCompensator_initializeDAEmodeData,
   RCLeadCompensator_computeVarIndices,
   RCLeadCompensator_functionODE,
   RCLeadCompensator_functionAlgebraics,
   RCLeadCompensator_functionDAE,
   RCLeadCompensator_functionLocalKnownVars,
   RCLeadCompensator_input_function,
   RCLeadCompensator_input_function_init,
   RCLeadCompensator_input_function_updateStartValues,
   RCLeadCompensator_data_function,
   RCLeadCompensator_output_function,
   RCLeadCompensator_setc_function,
   RCLeadCompensator_setb_function,
   RCLeadCompensator_function_storeDelayed,
   RCLeadCompensator_function_storeSpatialDistribution,
   RCLeadCompensator_function_initSpatialDistribution,
   RCLeadCompensator_updateBoundVariableAttributes,
   RCLeadCompensator_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   RCLeadCompensator_functionInitialEquations_lambda0,
   RCLeadCompensator_functionRemovedInitialEquations,
   RCLeadCompensator_updateBoundParameters,
   RCLeadCompensator_checkForAsserts,
   RCLeadCompensator_function_ZeroCrossingsEquations,
   RCLeadCompensator_function_ZeroCrossings,
   RCLeadCompensator_function_updateRelations,
   RCLeadCompensator_zeroCrossingDescription,
   RCLeadCompensator_relationDescription,
   RCLeadCompensator_function_initSample,
   RCLeadCompensator_INDEX_JAC_A,
   RCLeadCompensator_INDEX_JAC_B,
   RCLeadCompensator_INDEX_JAC_C,
   RCLeadCompensator_INDEX_JAC_D,
   RCLeadCompensator_INDEX_JAC_F,
   RCLeadCompensator_INDEX_JAC_H,
   RCLeadCompensator_initialAnalyticJacobianA,
   RCLeadCompensator_initialAnalyticJacobianB,
   RCLeadCompensator_initialAnalyticJacobianC,
   RCLeadCompensator_initialAnalyticJacobianD,
   RCLeadCompensator_initialAnalyticJacobianF,
   RCLeadCompensator_initialAnalyticJacobianH,
   RCLeadCompensator_functionJacA_column,
   RCLeadCompensator_functionJacB_column,
   RCLeadCompensator_functionJacC_column,
   RCLeadCompensator_functionJacD_column,
   RCLeadCompensator_functionJacF_column,
   RCLeadCompensator_functionJacH_column,
   RCLeadCompensator_linear_model_frame,
   RCLeadCompensator_linear_model_datarecovery_frame,
   RCLeadCompensator_mayer,
   RCLeadCompensator_lagrange,
   RCLeadCompensator_pickUpBoundsForInputsInOptimization,
   RCLeadCompensator_setInputData,
   RCLeadCompensator_getTimeGrid,
   RCLeadCompensator_symbolicInlineSystem,
   RCLeadCompensator_function_initSynchronous,
   RCLeadCompensator_function_updateSynchronous,
   RCLeadCompensator_function_equationsSynchronous,
   RCLeadCompensator_inputNames,
   RCLeadCompensator_dataReconciliationInputNames,
   RCLeadCompensator_dataReconciliationUnmeasuredVariables,
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

#define _OMC_LIT_RESOURCE_3_name_data "RCLeadCompensator"
#define _OMC_LIT_RESOURCE_3_dir_data "C:/Users/FST/Desktop/AFM/cases/20260407_154112_RCLeadCompensator/model"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,17,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,70,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void RCLeadCompensator_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &RCLeadCompensator_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "RCLeadCompensator";
  data->modelData->modelFilePrefix = "RCLeadCompensator";
  data->modelData->modelFileName = "RCLeadCompensator.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/cases/20260407_154112_RCLeadCompensator/model";
  data->modelData->modelGUID = "{8d971353-9e5c-4a83-a260-75520701be75}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "RCLeadCompensator_init.c"
    ;
  static const char contents_info[] =
    #include "RCLeadCompensator_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "RCLeadCompensator_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "RCLeadCompensator_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "RCLeadCompensator_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 10;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 22;
  data->modelData->nParametersInteger = 5;
  data->modelData->nParametersBoolean = 1;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 9;
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
  data->modelData->modelDataXml.nEquations = 51;
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
  
    RCLeadCompensator_setupDataStruc(&data, threadData);
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


