/* Algebraic */
#include "DualSpringMass_model.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forwarded equations */
extern void DualSpringMass_eqFunction_15(DATA* data, threadData_t *threadData);
extern void DualSpringMass_eqFunction_17(DATA* data, threadData_t *threadData);
extern void DualSpringMass_eqFunction_18(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[3])(DATA*, threadData_t*) = {
    DualSpringMass_eqFunction_15,
    DualSpringMass_eqFunction_17,
    DualSpringMass_eqFunction_18
  };
  
  static const int eqIndices[3] = {
    15,
    17,
    18
  };
  
  for (id = 0; id < 3; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}
/* for continuous time variables */
int DualSpringMass_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  DualSpringMass_function_savePreSynchronous(data, threadData);
  
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
