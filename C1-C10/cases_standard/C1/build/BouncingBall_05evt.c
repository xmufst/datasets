/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "BouncingBall_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void BouncingBall_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *BouncingBall_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"h > 0.0 or v > 0.0",
  "h <= 0.0"};
  static const int occurEqs0[] = {1,8};
  static const int occurEqs1[] = {1,7};
  static const int *occurEqs[] = {occurEqs0,occurEqs1};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void BouncingBall_eqFunction_8(DATA* data, threadData_t *threadData);
extern void BouncingBall_eqFunction_9(DATA* data, threadData_t *threadData);

int BouncingBall_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  BouncingBall_eqFunction_8(data, threadData);

  BouncingBall_eqFunction_9(data, threadData);
  
  TRACE_POP
  return 0;
}

int BouncingBall_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  start_index = current_index;
  tmp1 = 1.0;
  tmp2 = 0.0;
  tmp0 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1,v) */), 0.0, tmp1, tmp2, data->simulationInfo->storedRelations[0]);
  tmp4 = 1.0;
  tmp5 = 0.0;
  tmp3 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1) */), 0.0, tmp4, tmp5, data->simulationInfo->storedRelations[1]);
  gout[start_index] = ((tmp0 || tmp3)) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp7 = 1.0;
  tmp8 = 0.0;
  tmp6 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1,v) */), 0.0, tmp7, tmp8, data->simulationInfo->storedRelations[2]);
  gout[start_index] = (tmp6) ? 1 : -1;
  current_index++;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *BouncingBall_relationDescription(int i)
{
  const char *res[] = {"h > 0.0",
  "v > 0.0",
  "h <= 0.0"};
  return res[i];
}

int BouncingBall_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_boolean tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_boolean tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
  if(evalforZeroCross) {
    start_index = current_index;
    tmp10 = 1.0;
    tmp11 = 0.0;
    tmp9 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1,v) */), 0.0, tmp10, tmp11, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[start_index] = tmp9;
    current_index++;

    start_index = current_index;
    tmp13 = 1.0;
    tmp14 = 0.0;
    tmp12 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1) */), 0.0, tmp13, tmp14, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[start_index] = tmp12;
    current_index++;

    start_index = current_index;
    tmp16 = 1.0;
    tmp17 = 0.0;
    tmp15 = LessEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1,v) */), 0.0, tmp16, tmp17, data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[start_index] = tmp15;
    current_index++;
  } else {
    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1,v) */) > 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1) */) > 0.0);
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1,v) */) <= 0.0);
    current_index++;
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

