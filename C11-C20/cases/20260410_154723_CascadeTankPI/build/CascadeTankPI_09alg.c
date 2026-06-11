/* Algebraic */
#include "CascadeTankPI_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forwarded equations */
extern void CascadeTankPI_eqFunction_46(DATA* data, threadData_t *threadData);
extern void CascadeTankPI_eqFunction_49(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[2])(DATA*, threadData_t*) = {
    CascadeTankPI_eqFunction_46,
    CascadeTankPI_eqFunction_49
  };
  
  static const int eqIndices[2] = {
    46,
    49
  };
  
  for (id = 0; id < 2; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}
/* for continuous time variables */
int CascadeTankPI_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  CascadeTankPI_function_savePreSynchronous(data, threadData);
  
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
