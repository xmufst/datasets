/* Algebraic */
#include "SpringEndStop_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forwarded equations */
extern void SpringEndStop_eqFunction_14(DATA* data, threadData_t *threadData);
extern void SpringEndStop_eqFunction_15(DATA* data, threadData_t *threadData);
extern void SpringEndStop_eqFunction_16(DATA* data, threadData_t *threadData);
extern void SpringEndStop_eqFunction_19(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[4])(DATA*, threadData_t*) = {
    SpringEndStop_eqFunction_14,
    SpringEndStop_eqFunction_15,
    SpringEndStop_eqFunction_16,
    SpringEndStop_eqFunction_19
  };
  
  static const int eqIndices[4] = {
    14,
    15,
    16,
    19
  };
  
  for (id = 0; id < 4; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}
/* for continuous time variables */
int SpringEndStop_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  SpringEndStop_function_savePreSynchronous(data, threadData);
  
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
