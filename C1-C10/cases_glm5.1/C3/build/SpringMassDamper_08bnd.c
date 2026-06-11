/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "SpringMassDamper_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 21
type: SIMPLE_ASSIGN
$START.v = v0
*/
static void SpringMassDamper_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->modelData->realVarsData[0] /* v STATE(1,a) */).attribute .start = (data->simulationInfo->realParameter[3] /* v0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */) = (data->modelData->realVarsData[0] /* v STATE(1,a) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* v */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */));
  TRACE_POP
}

/*
equation index: 22
type: SIMPLE_ASSIGN
$START.x = x0
*/
static void SpringMassDamper_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->modelData->realVarsData[1] /* x STATE(1,v) */).attribute .start = (data->simulationInfo->realParameter[4] /* x0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */) = (data->modelData->realVarsData[1] /* x STATE(1,v) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* x */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int SpringMassDamper_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  SpringMassDamper_eqFunction_21(data, threadData);

  SpringMassDamper_eqFunction_22(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void SpringMassDamper_updateBoundParameters_0(DATA *data, threadData_t *threadData);
extern void SpringMassDamper_eqFunction_2(DATA *data, threadData_t *threadData);

extern void SpringMassDamper_eqFunction_1(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void SpringMassDamper_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SpringMassDamper_eqFunction_2(data, threadData);
  SpringMassDamper_eqFunction_1(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int SpringMassDamper_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SpringMassDamper_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

