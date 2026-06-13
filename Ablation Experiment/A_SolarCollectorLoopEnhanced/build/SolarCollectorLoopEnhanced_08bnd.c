/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "SolarCollectorLoopEnhanced_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int SolarCollectorLoopEnhanced_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating min-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* max ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating max-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* nominal **************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating nominal-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating primary start-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void SolarCollectorLoopEnhanced_updateBoundParameters_0(DATA *data, threadData_t *threadData);
extern void SolarCollectorLoopEnhanced_eqFunction_5(DATA *data, threadData_t *threadData);

extern void SolarCollectorLoopEnhanced_eqFunction_1(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void SolarCollectorLoopEnhanced_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SolarCollectorLoopEnhanced_eqFunction_5(data, threadData);
  SolarCollectorLoopEnhanced_eqFunction_1(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int SolarCollectorLoopEnhanced_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SolarCollectorLoopEnhanced_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

