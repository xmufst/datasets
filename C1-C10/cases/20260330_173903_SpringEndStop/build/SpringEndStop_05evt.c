/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "SpringEndStop_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void SpringEndStop_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *SpringEndStop_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"penetration > 0.0"};
  static const int occurEqs0[] = {1,16};
  static const int *occurEqs[] = {occurEqs0};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
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

int SpringEndStop_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  SpringEndStop_eqFunction_14(data, threadData);

  SpringEndStop_eqFunction_15(data, threadData);

  SpringEndStop_eqFunction_16(data, threadData);

  SpringEndStop_eqFunction_17(data, threadData);

  SpringEndStop_eqFunction_18(data, threadData);

  SpringEndStop_eqFunction_19(data, threadData);

  SpringEndStop_eqFunction_20(data, threadData);

  SpringEndStop_eqFunction_21(data, threadData);
  
  TRACE_POP
  return 0;
}

int SpringEndStop_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  start_index = current_index;
  tmp1 = 1.0;
  tmp2 = 0.0;
  tmp0 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* penetration variable */), 0.0, tmp1, tmp2, data->simulationInfo->storedRelations[0]);
  gout[start_index] = (tmp0) ? 1 : -1;
  current_index++;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *SpringEndStop_relationDescription(int i)
{
  const char *res[] = {"penetration > 0.0"};
  return res[i];
}

int SpringEndStop_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
  if(evalforZeroCross) {
    start_index = current_index;
    tmp4 = 1.0;
    tmp5 = 0.0;
    tmp3 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* penetration variable */), 0.0, tmp4, tmp5, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[start_index] = tmp3;
    current_index++;
  } else {
    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* penetration variable */) > 0.0);
    current_index++;
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

