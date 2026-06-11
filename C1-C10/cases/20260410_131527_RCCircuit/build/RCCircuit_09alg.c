/* Algebraic */
#include "RCCircuit_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forwarded equations */
extern void RCCircuit_eqFunction_15(DATA* data, threadData_t *threadData);
extern void RCCircuit_eqFunction_19(DATA* data, threadData_t *threadData);
extern void RCCircuit_eqFunction_23(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[3])(DATA*, threadData_t*) = {
    RCCircuit_eqFunction_15,
    RCCircuit_eqFunction_19,
    RCCircuit_eqFunction_23
  };
  
  static const int eqIndices[3] = {
    15,
    19,
    23
  };
  
  for (id = 0; id < 3; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}
/* for continuous time variables */
int RCCircuit_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  RCCircuit_function_savePreSynchronous(data, threadData);
  
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
