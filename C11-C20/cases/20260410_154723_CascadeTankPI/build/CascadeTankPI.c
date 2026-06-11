/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "CascadeTankPI_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation CascadeTankPI_performSimulation
#define prefixedName_updateContinuousSystem CascadeTankPI_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation CascadeTankPI_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int CascadeTankPI_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int CascadeTankPI_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int CascadeTankPI_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int CascadeTankPI_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int CascadeTankPI_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int CascadeTankPI_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int CascadeTankPI_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int CascadeTankPI_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int CascadeTankPI_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int CascadeTankPI_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 36
type: SIMPLE_ASSIGN
outer_feedback.y = h2_ref_source.k - h2
*/
void CascadeTankPI_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* outer_feedback.y variable */) = (data->simulationInfo->realParameter[8] /* h2_ref_source.k PARAM */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* h2 STATE(1) */);
  TRACE_POP
}
/*
equation index: 37
type: SIMPLE_ASSIGN
$DER.outer_PI.x = outer_feedback.y / outer_PI.T
*/
void CascadeTankPI_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* der(outer_PI.x) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* outer_feedback.y variable */),(data->simulationInfo->realParameter[16] /* outer_PI.T PARAM */),"outer_PI.T",equationIndexes);
  TRACE_POP
}
/*
equation index: 38
type: SIMPLE_ASSIGN
u_outer = outer_PI.k * (outer_PI.x + outer_feedback.y)
*/
void CascadeTankPI_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* u_outer variable */) = ((data->simulationInfo->realParameter[17] /* outer_PI.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* outer_PI.x STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* outer_feedback.y variable */));
  TRACE_POP
}
/*
equation index: 39
type: SIMPLE_ASSIGN
inner_feedback.y = u_outer - h1
*/
void CascadeTankPI_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* inner_feedback.y variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* u_outer variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h1 STATE(1) */);
  TRACE_POP
}
/*
equation index: 40
type: SIMPLE_ASSIGN
$DER.inner_PI.x = inner_feedback.y / inner_PI.T
*/
void CascadeTankPI_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* der(inner_PI.x) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* inner_feedback.y variable */),(data->simulationInfo->realParameter[10] /* inner_PI.T PARAM */),"inner_PI.T",equationIndexes);
  TRACE_POP
}
/*
equation index: 41
type: SIMPLE_ASSIGN
u_inner = inner_PI.k * (inner_PI.x + inner_feedback.y)
*/
void CascadeTankPI_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* u_inner variable */) = ((data->simulationInfo->realParameter[11] /* inner_PI.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* inner_PI.x STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* inner_feedback.y variable */));
  TRACE_POP
}
/*
equation index: 42
type: SIMPLE_ASSIGN
valve_limiter.y = smooth(0, if u_inner > valve_limiter.uMax then valve_limiter.uMax else if u_inner < valve_limiter.uMin then valve_limiter.uMin else u_inner)
*/
void CascadeTankPI_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* u_inner variable */),(data->simulationInfo->realParameter[21] /* valve_limiter.uMax PARAM */));
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = (data->simulationInfo->realParameter[21] /* valve_limiter.uMax PARAM */);
  }
  else
  {
    tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* u_inner variable */),(data->simulationInfo->realParameter[22] /* valve_limiter.uMin PARAM */));
    tmp3 = (tmp1?(data->simulationInfo->realParameter[22] /* valve_limiter.uMin PARAM */):(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* u_inner variable */));
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* valve_limiter.y variable */) = tmp3;
  TRACE_POP
}
/*
equation index: 43
type: SIMPLE_ASSIGN
Q_12 = k1 * sqrt(max(h1, 0.0))
*/
void CascadeTankPI_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
  modelica_real tmp4;
  tmp4 = fmax((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h1 STATE(1) */),0.0);
  if(!(tmp4 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(max(h1, 0.0)) was %g should be >= 0", tmp4);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* Q_12 variable */) = ((data->simulationInfo->realParameter[14] /* k1 PARAM */)) * (sqrt(tmp4));
  TRACE_POP
}
/*
equation index: 44
type: SIMPLE_ASSIGN
Q_out = k2 * sqrt(max(h2, 0.0))
*/
void CascadeTankPI_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
  modelica_real tmp5;
  tmp5 = fmax((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* h2 STATE(1) */),0.0);
  if(!(tmp5 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(max(h2, 0.0)) was %g should be >= 0", tmp5);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* Q_out variable */) = ((data->simulationInfo->realParameter[15] /* k2 PARAM */)) * (sqrt(tmp5));
  TRACE_POP
}
/*
equation index: 45
type: SIMPLE_ASSIGN
$DER.h2 = (Q_12 - Q_out) / A2
*/
void CascadeTankPI_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* der(h2) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* Q_12 variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* Q_out variable */),(data->simulationInfo->realParameter[1] /* A2 PARAM */),"A2",equationIndexes);
  TRACE_POP
}
/*
equation index: 46
type: SIMPLE_ASSIGN
h2_error = h2_ref - h2
*/
void CascadeTankPI_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* h2_error variable */) = (data->simulationInfo->realParameter[7] /* h2_ref PARAM */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* h2 STATE(1) */);
  TRACE_POP
}
/*
equation index: 47
type: SIMPLE_ASSIGN
Q_in = valve_limiter.y * Q_in_max
*/
void CascadeTankPI_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* Q_in variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* valve_limiter.y variable */)) * ((data->simulationInfo->realParameter[4] /* Q_in_max PARAM */));
  TRACE_POP
}
/*
equation index: 48
type: SIMPLE_ASSIGN
$DER.h1 = (Q_in - Q_12) / A1
*/
void CascadeTankPI_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* der(h1) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* Q_in variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* Q_12 variable */),(data->simulationInfo->realParameter[0] /* A1 PARAM */),"A1",equationIndexes);
  TRACE_POP
}
/*
equation index: 49
type: ALGORITHM

  assert(valve_limiter.uMax >= valve_limiter.uMin, "Limiter: Limits must be consistent. However, uMax (=" + String(valve_limiter.uMax, 6, 0, true) + ") < uMin (=" + String(valve_limiter.uMin, 6, 0, true) + ")");
*/
void CascadeTankPI_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
  modelica_boolean tmp6;
  static const MMC_DEFSTRINGLIT(tmp7,52,"Limiter: Limits must be consistent. However, uMax (=");
  modelica_string tmp8;
  modelica_metatype tmpMeta9;
  static const MMC_DEFSTRINGLIT(tmp10,11,") < uMin (=");
  modelica_metatype tmpMeta11;
  modelica_string tmp12;
  modelica_metatype tmpMeta13;
  modelica_metatype tmpMeta14;
  static int tmp15 = 0;
  {
    tmp6 = GreaterEq((data->simulationInfo->realParameter[21] /* valve_limiter.uMax PARAM */),(data->simulationInfo->realParameter[22] /* valve_limiter.uMin PARAM */));
    if(!tmp6)
    {
      tmp8 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[21] /* valve_limiter.uMax PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta9 = stringAppend(MMC_REFSTRINGLIT(tmp7),tmp8);
      tmpMeta11 = stringAppend(tmpMeta9,MMC_REFSTRINGLIT(tmp10));
      tmp12 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[22] /* valve_limiter.uMin PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta13 = stringAppend(tmpMeta11,tmp12);
      tmpMeta14 = stringAppend(tmpMeta13,(modelica_string) mmc_strings_len1[41]);
      {
        const char* assert_cond = "(valve_limiter.uMax >= valve_limiter.uMin)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
        }
      }
    }
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int CascadeTankPI_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  CascadeTankPI_functionLocalKnownVars(data, threadData);
  CascadeTankPI_eqFunction_36(data, threadData);

  CascadeTankPI_eqFunction_37(data, threadData);

  CascadeTankPI_eqFunction_38(data, threadData);

  CascadeTankPI_eqFunction_39(data, threadData);

  CascadeTankPI_eqFunction_40(data, threadData);

  CascadeTankPI_eqFunction_41(data, threadData);

  CascadeTankPI_eqFunction_42(data, threadData);

  CascadeTankPI_eqFunction_43(data, threadData);

  CascadeTankPI_eqFunction_44(data, threadData);

  CascadeTankPI_eqFunction_45(data, threadData);

  CascadeTankPI_eqFunction_46(data, threadData);

  CascadeTankPI_eqFunction_47(data, threadData);

  CascadeTankPI_eqFunction_48(data, threadData);

  CascadeTankPI_eqFunction_49(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int CascadeTankPI_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void CascadeTankPI_eqFunction_36(DATA* data, threadData_t *threadData);
extern void CascadeTankPI_eqFunction_37(DATA* data, threadData_t *threadData);
extern void CascadeTankPI_eqFunction_38(DATA* data, threadData_t *threadData);
extern void CascadeTankPI_eqFunction_39(DATA* data, threadData_t *threadData);
extern void CascadeTankPI_eqFunction_40(DATA* data, threadData_t *threadData);
extern void CascadeTankPI_eqFunction_41(DATA* data, threadData_t *threadData);
extern void CascadeTankPI_eqFunction_42(DATA* data, threadData_t *threadData);
extern void CascadeTankPI_eqFunction_43(DATA* data, threadData_t *threadData);
extern void CascadeTankPI_eqFunction_44(DATA* data, threadData_t *threadData);
extern void CascadeTankPI_eqFunction_45(DATA* data, threadData_t *threadData);
extern void CascadeTankPI_eqFunction_47(DATA* data, threadData_t *threadData);
extern void CascadeTankPI_eqFunction_48(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[12])(DATA*, threadData_t*) = {
    CascadeTankPI_eqFunction_36,
    CascadeTankPI_eqFunction_37,
    CascadeTankPI_eqFunction_38,
    CascadeTankPI_eqFunction_39,
    CascadeTankPI_eqFunction_40,
    CascadeTankPI_eqFunction_41,
    CascadeTankPI_eqFunction_42,
    CascadeTankPI_eqFunction_43,
    CascadeTankPI_eqFunction_44,
    CascadeTankPI_eqFunction_45,
    CascadeTankPI_eqFunction_47,
    CascadeTankPI_eqFunction_48
  };
  
  static const int eqIndices[12] = {
    36,
    37,
    38,
    39,
    40,
    41,
    42,
    43,
    44,
    45,
    47,
    48
  };
  
  for (id = 0; id < 12; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int CascadeTankPI_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  CascadeTankPI_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void CascadeTankPI_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* h1 STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* h2 STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* inner_PI.x STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* outer_PI.x STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(h1) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(h2) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(inner_PI.x) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(outer_PI.x) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_12 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_in variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_out variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* h2_error variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* inner_feedback.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* outer_feedback.y variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* u_inner variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* u_outer variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* valve_limiter.y variable */
  
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

#include "CascadeTankPI_12jac.h"
#include "CascadeTankPI_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks CascadeTankPI_callback = {
   (int (*)(DATA *, threadData_t *, void *)) CascadeTankPI_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) CascadeTankPI_performQSSSimulation,    /* performQSSSimulation */
   CascadeTankPI_updateContinuousSystem,    /* updateContinuousSystem */
   CascadeTankPI_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   CascadeTankPI_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   CascadeTankPI_initializeDAEmodeData,
   CascadeTankPI_computeVarIndices,
   CascadeTankPI_functionODE,
   CascadeTankPI_functionAlgebraics,
   CascadeTankPI_functionDAE,
   CascadeTankPI_functionLocalKnownVars,
   CascadeTankPI_input_function,
   CascadeTankPI_input_function_init,
   CascadeTankPI_input_function_updateStartValues,
   CascadeTankPI_data_function,
   CascadeTankPI_output_function,
   CascadeTankPI_setc_function,
   CascadeTankPI_setb_function,
   CascadeTankPI_function_storeDelayed,
   CascadeTankPI_function_storeSpatialDistribution,
   CascadeTankPI_function_initSpatialDistribution,
   CascadeTankPI_updateBoundVariableAttributes,
   CascadeTankPI_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   CascadeTankPI_functionInitialEquations_lambda0,
   CascadeTankPI_functionRemovedInitialEquations,
   CascadeTankPI_updateBoundParameters,
   CascadeTankPI_checkForAsserts,
   CascadeTankPI_function_ZeroCrossingsEquations,
   CascadeTankPI_function_ZeroCrossings,
   CascadeTankPI_function_updateRelations,
   CascadeTankPI_zeroCrossingDescription,
   CascadeTankPI_relationDescription,
   CascadeTankPI_function_initSample,
   CascadeTankPI_INDEX_JAC_A,
   CascadeTankPI_INDEX_JAC_B,
   CascadeTankPI_INDEX_JAC_C,
   CascadeTankPI_INDEX_JAC_D,
   CascadeTankPI_INDEX_JAC_F,
   CascadeTankPI_INDEX_JAC_H,
   CascadeTankPI_initialAnalyticJacobianA,
   CascadeTankPI_initialAnalyticJacobianB,
   CascadeTankPI_initialAnalyticJacobianC,
   CascadeTankPI_initialAnalyticJacobianD,
   CascadeTankPI_initialAnalyticJacobianF,
   CascadeTankPI_initialAnalyticJacobianH,
   CascadeTankPI_functionJacA_column,
   CascadeTankPI_functionJacB_column,
   CascadeTankPI_functionJacC_column,
   CascadeTankPI_functionJacD_column,
   CascadeTankPI_functionJacF_column,
   CascadeTankPI_functionJacH_column,
   CascadeTankPI_linear_model_frame,
   CascadeTankPI_linear_model_datarecovery_frame,
   CascadeTankPI_mayer,
   CascadeTankPI_lagrange,
   CascadeTankPI_pickUpBoundsForInputsInOptimization,
   CascadeTankPI_setInputData,
   CascadeTankPI_getTimeGrid,
   CascadeTankPI_symbolicInlineSystem,
   CascadeTankPI_function_initSynchronous,
   CascadeTankPI_function_updateSynchronous,
   CascadeTankPI_function_equationsSynchronous,
   CascadeTankPI_inputNames,
   CascadeTankPI_dataReconciliationInputNames,
   CascadeTankPI_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "CascadeTankPI"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/Desktop/AFM/cases/20260410_154723_CascadeTankPI/build/src"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,13,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,70,_OMC_LIT_RESOURCE_0_dir_data);

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
void CascadeTankPI_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &CascadeTankPI_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "CascadeTankPI";
  data->modelData->modelFilePrefix = "CascadeTankPI";
  data->modelData->modelFileName = "CascadeTankPI.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/AFM/cases/20260410_154723_CascadeTankPI/build/src";
  data->modelData->modelGUID = "{5df322d0-96d2-470e-918c-4e9d36c30ab1}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "CascadeTankPI_init.c"
    ;
  static const char contents_info[] =
    #include "CascadeTankPI_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "CascadeTankPI_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "CascadeTankPI_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "CascadeTankPI_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 4;
  data->modelData->nVariablesRealArray = 17;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 23;
  data->modelData->nParametersInteger = 3;
  data->modelData->nParametersBoolean = 1;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 11;
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
  data->modelData->modelDataXml.nEquations = 68;
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
  
    CascadeTankPI_setupDataStruc(&data, threadData);
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


