/* Algebraic */
#include "TurbineOverspeedTripEnhanced_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forwarded equations */
extern void TurbineOverspeedTripEnhanced_eqFunction_20(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_27(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[2])(DATA*, threadData_t*) = {
    TurbineOverspeedTripEnhanced_eqFunction_20,
    TurbineOverspeedTripEnhanced_eqFunction_27
  };
  
  static const int eqIndices[2] = {
    20,
    27
  };
  
  for (id = 0; id < 2; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}
/* for continuous time variables */
int TurbineOverspeedTripEnhanced_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  TurbineOverspeedTripEnhanced_function_savePreSynchronous(data, threadData);
  
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
