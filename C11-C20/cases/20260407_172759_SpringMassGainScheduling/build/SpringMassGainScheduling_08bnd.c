/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "SpringMassGainScheduling_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int SpringMassGainScheduling_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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

void SpringMassGainScheduling_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 21
type: SIMPLE_ASSIGN
step_ref.height = x_ref
*/
OMC_DISABLE_OPT
static void SpringMassGainScheduling_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->simulationInfo->realParameter[8] /* step_ref.height PARAM */) = (data->simulationInfo->realParameter[11] /* x_ref PARAM */);
  TRACE_POP
}
OMC_DISABLE_OPT
void SpringMassGainScheduling_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SpringMassGainScheduling_eqFunction_21(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int SpringMassGainScheduling_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SpringMassGainScheduling_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

