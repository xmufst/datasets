/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "SpringMassGainScheduling_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 21
type: SIMPLE_ASSIGN
$START.v = v0
*/
static void SpringMassGainScheduling_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->modelData->realVarsData[0] /* v STATE(1,a) */).attribute .start = (data->simulationInfo->realParameter[11] /* v0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */) = (data->modelData->realVarsData[0] /* v STATE(1,a) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* v */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */));
  TRACE_POP
}

/*
equation index: 22
type: SIMPLE_ASSIGN
$START.x = x0
*/
static void SpringMassGainScheduling_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->modelData->realVarsData[1] /* x STATE(1,v) */).attribute .start = (data->simulationInfo->realParameter[12] /* x0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */) = (data->modelData->realVarsData[1] /* x STATE(1,v) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* x */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */));
  TRACE_POP
}
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
  SpringMassGainScheduling_eqFunction_21(data, threadData);

  SpringMassGainScheduling_eqFunction_22(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void SpringMassGainScheduling_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 23
type: SIMPLE_ASSIGN
refSignal.height = x_ref
*/
OMC_DISABLE_OPT
static void SpringMassGainScheduling_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->simulationInfo->realParameter[8] /* refSignal.height PARAM */) = (data->simulationInfo->realParameter[13] /* x_ref PARAM */);
  TRACE_POP
}
OMC_DISABLE_OPT
void SpringMassGainScheduling_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SpringMassGainScheduling_eqFunction_23(data, threadData);
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

