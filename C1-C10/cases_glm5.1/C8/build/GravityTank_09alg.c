/* Algebraic */
#include "GravityTank_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forwarded equations */
extern void GravityTank_eqFunction_9(DATA* data, threadData_t *threadData);
extern void GravityTank_eqFunction_10(DATA* data, threadData_t *threadData);
extern void GravityTank_eqFunction_15(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[3])(DATA*, threadData_t*) = {
    GravityTank_eqFunction_9,
    GravityTank_eqFunction_10,
    GravityTank_eqFunction_15
  };
  
  static const int eqIndices[3] = {
    9,
    10,
    15
  };
  
  for (id = 0; id < 3; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}
/* for continuous time variables */
int GravityTank_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  GravityTank_function_savePreSynchronous(data, threadData);
  
  functionAlg_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ALGEBRAICS);
#endif

  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif
