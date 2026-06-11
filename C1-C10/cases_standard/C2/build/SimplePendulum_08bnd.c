/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "SimplePendulum_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 19
type: SIMPLE_ASSIGN
$START.omega = omega0
*/
static void SimplePendulum_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->modelData->realVarsData[0] /* omega STATE(1) */).attribute .start = (data->simulationInfo->realParameter[2] /* omega0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* omega STATE(1) */) = (data->modelData->realVarsData[0] /* omega STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* omega */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* omega STATE(1) */));
  TRACE_POP
}

/*
equation index: 20
type: SIMPLE_ASSIGN
$START.theta = theta0
*/
static void SimplePendulum_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->modelData->realVarsData[1] /* theta STATE(1,omega) */).attribute .start = (data->simulationInfo->realParameter[3] /* theta0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* theta STATE(1,omega) */) = (data->modelData->realVarsData[1] /* theta STATE(1,omega) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* theta */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* theta STATE(1,omega) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int SimplePendulum_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  SimplePendulum_eqFunction_19(data, threadData);

  SimplePendulum_eqFunction_20(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int SimplePendulum_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

