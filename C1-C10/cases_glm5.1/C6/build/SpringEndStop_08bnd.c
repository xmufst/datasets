/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "SpringEndStop_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 25
type: SIMPLE_ASSIGN
$START.contact = x0 > gap
*/
static void SpringEndStop_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->modelData->booleanVarsData[0] /* contact DISCRETE */).attribute .start = ((data->simulationInfo->realParameter[8] /* x0 PARAM */) > (data->simulationInfo->realParameter[3] /* gap PARAM */));
    (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* contact DISCRETE */) = (data->modelData->booleanVarsData[0] /* contact DISCRETE */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%d)", data->modelData->booleanVarsData[0].info /* contact */.name, (modelica_boolean) (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* contact DISCRETE */));
  TRACE_POP
}

/*
equation index: 26
type: SIMPLE_ASSIGN
$START.v = v0
*/
static void SpringEndStop_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->modelData->realVarsData[0] /* v STATE(1) */).attribute .start = (data->simulationInfo->realParameter[7] /* v0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1) */) = (data->modelData->realVarsData[0] /* v STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* v */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1) */));
  TRACE_POP
}

/*
equation index: 27
type: SIMPLE_ASSIGN
$START.x = x0
*/
static void SpringEndStop_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  (data->modelData->realVarsData[1] /* x STATE(1,v) */).attribute .start = (data->simulationInfo->realParameter[8] /* x0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */) = (data->modelData->realVarsData[1] /* x STATE(1,v) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* x */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int SpringEndStop_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  SpringEndStop_eqFunction_25(data, threadData);

  SpringEndStop_eqFunction_26(data, threadData);

  SpringEndStop_eqFunction_27(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int SpringEndStop_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

