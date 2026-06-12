/* Algebraic */
#include "TankTempPIControl_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forwarded equations */
extern void TankTempPIControl_eqFunction_54(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_57(DATA* data, threadData_t *threadData);
extern void TankTempPIControl_eqFunction_58(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[3])(DATA*, threadData_t*) = {
    TankTempPIControl_eqFunction_54,
    TankTempPIControl_eqFunction_57,
    TankTempPIControl_eqFunction_58
  };
  
  static const int eqIndices[3] = {
    54,
    57,
    58
  };
  
  for (id = 0; id < 3; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}
/* for continuous time variables */
int TankTempPIControl_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  TankTempPIControl_function_savePreSynchronous(data, threadData);
  
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
