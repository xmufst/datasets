/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "BouncingBall_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 12
type: SIMPLE_ASSIGN
$START.v = v0
*/
static void BouncingBall_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  (data->modelData->realVarsData[1] /* v STATE(1) */).attribute .start = (data->simulationInfo->realParameter[3] /* v0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1) */) = (data->modelData->realVarsData[1] /* v STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* v */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1) */));
  TRACE_POP
}

/*
equation index: 13
type: SIMPLE_ASSIGN
$START.h = h0
*/
static void BouncingBall_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->modelData->realVarsData[0] /* h STATE(1,v) */).attribute .start = (data->simulationInfo->realParameter[2] /* h0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1,v) */) = (data->modelData->realVarsData[0] /* h STATE(1,v) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* h */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1,v) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int BouncingBall_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  BouncingBall_eqFunction_12(data, threadData);

  BouncingBall_eqFunction_13(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int BouncingBall_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

