/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "FurnaceFeedforward_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 12
type: SIMPLE_ASSIGN
$START.T = T0
*/
static void FurnaceFeedforward_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  (data->modelData->realVarsData[0] /* T STATE(1) */).attribute .start = (data->simulationInfo->realParameter[5] /* T0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */) = (data->modelData->realVarsData[0] /* T STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* T */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int FurnaceFeedforward_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  FurnaceFeedforward_eqFunction_12(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void FurnaceFeedforward_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 13
type: SIMPLE_ASSIGN
steadyStateHeat.k = Q_ss
*/
OMC_DISABLE_OPT
static void FurnaceFeedforward_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->simulationInfo->realParameter[15] /* steadyStateHeat.k PARAM */) = (data->simulationInfo->realParameter[4] /* Q_ss PARAM */);
  TRACE_POP
}

/*
equation index: 14
type: SIMPLE_ASSIGN
heaterSum.u1 = steadyStateHeat.k
*/
OMC_DISABLE_OPT
static void FurnaceFeedforward_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  (data->simulationInfo->realParameter[14] /* heaterSum.u1 PARAM */) = (data->simulationInfo->realParameter[15] /* steadyStateHeat.k PARAM */);
  TRACE_POP
}

/*
equation index: 15
type: SIMPLE_ASSIGN
steadyStateHeat.y = steadyStateHeat.k
*/
OMC_DISABLE_OPT
static void FurnaceFeedforward_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  (data->simulationInfo->realParameter[16] /* steadyStateHeat.y PARAM */) = (data->simulationInfo->realParameter[15] /* steadyStateHeat.k PARAM */);
  TRACE_POP
}

/*
equation index: 16
type: SIMPLE_ASSIGN
feedforwardGain.k = K_ff
*/
OMC_DISABLE_OPT
static void FurnaceFeedforward_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->simulationInfo->realParameter[11] /* feedforwardGain.k PARAM */) = (data->simulationInfo->realParameter[1] /* K_ff PARAM */);
  TRACE_POP
}

/*
equation index: 17
type: SIMPLE_ASSIGN
disturbanceSignal.startTime = t_dist
*/
OMC_DISABLE_OPT
static void FurnaceFeedforward_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->simulationInfo->realParameter[10] /* disturbanceSignal.startTime PARAM */) = (data->simulationInfo->realParameter[17] /* t_dist PARAM */);
  TRACE_POP
}

/*
equation index: 18
type: SIMPLE_ASSIGN
disturbanceSignal.height = Q_dist
*/
OMC_DISABLE_OPT
static void FurnaceFeedforward_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->simulationInfo->realParameter[8] /* disturbanceSignal.height PARAM */) = (data->simulationInfo->realParameter[3] /* Q_dist PARAM */);
  TRACE_POP
}
OMC_DISABLE_OPT
void FurnaceFeedforward_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  FurnaceFeedforward_eqFunction_13(data, threadData);
  FurnaceFeedforward_eqFunction_14(data, threadData);
  FurnaceFeedforward_eqFunction_15(data, threadData);
  FurnaceFeedforward_eqFunction_16(data, threadData);
  FurnaceFeedforward_eqFunction_17(data, threadData);
  FurnaceFeedforward_eqFunction_18(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int FurnaceFeedforward_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  FurnaceFeedforward_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

