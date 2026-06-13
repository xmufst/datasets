/* Algebraic */
#include "ForcedDampedOscillator_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forwarded equations */
extern void ForcedDampedOscillator_eqFunction_15(DATA* data, threadData_t *threadData);
extern void ForcedDampedOscillator_eqFunction_16(DATA* data, threadData_t *threadData);
extern void ForcedDampedOscillator_eqFunction_17(DATA* data, threadData_t *threadData);
extern void ForcedDampedOscillator_eqFunction_18(DATA* data, threadData_t *threadData);
extern void ForcedDampedOscillator_eqFunction_19(DATA* data, threadData_t *threadData);
extern void ForcedDampedOscillator_eqFunction_21(DATA* data, threadData_t *threadData);
extern void ForcedDampedOscillator_eqFunction_22(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[7])(DATA*, threadData_t*) = {
    ForcedDampedOscillator_eqFunction_15,
    ForcedDampedOscillator_eqFunction_16,
    ForcedDampedOscillator_eqFunction_17,
    ForcedDampedOscillator_eqFunction_18,
    ForcedDampedOscillator_eqFunction_19,
    ForcedDampedOscillator_eqFunction_21,
    ForcedDampedOscillator_eqFunction_22
  };
  
  static const int eqIndices[7] = {
    15,
    16,
    17,
    18,
    19,
    21,
    22
  };
  
  for (id = 0; id < 7; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}
/* for continuous time variables */
int ForcedDampedOscillator_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  ForcedDampedOscillator_function_savePreSynchronous(data, threadData);
  
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
