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
  (data->modelData->realVarsData[0] /* T STATE(1) */).attribute .start = (data->simulationInfo->realParameter[7] /* T0 PARAM */);
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
Q_steady.k = Q_ss
*/
OMC_DISABLE_OPT
static void FurnaceFeedforward_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->simulationInfo->realParameter[5] /* Q_steady.k PARAM */) = (data->simulationInfo->realParameter[4] /* Q_ss PARAM */);
  TRACE_POP
}

/*
equation index: 14
type: SIMPLE_ASSIGN
add_signals.u1 = Q_steady.k
*/
OMC_DISABLE_OPT
static void FurnaceFeedforward_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  (data->simulationInfo->realParameter[12] /* add_signals.u1 PARAM */) = (data->simulationInfo->realParameter[5] /* Q_steady.k PARAM */);
  TRACE_POP
}

/*
equation index: 15
type: SIMPLE_ASSIGN
Q_steady.y = Q_steady.k
*/
OMC_DISABLE_OPT
static void FurnaceFeedforward_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  (data->simulationInfo->realParameter[6] /* Q_steady.y PARAM */) = (data->simulationInfo->realParameter[5] /* Q_steady.k PARAM */);
  TRACE_POP
}

/*
equation index: 16
type: SIMPLE_ASSIGN
feedforward_gain.k = K_ff
*/
OMC_DISABLE_OPT
static void FurnaceFeedforward_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->simulationInfo->realParameter[16] /* feedforward_gain.k PARAM */) = (data->simulationInfo->realParameter[1] /* K_ff PARAM */);
  TRACE_POP
}

/*
equation index: 17
type: SIMPLE_ASSIGN
disturbance.startTime = t_dist
*/
OMC_DISABLE_OPT
static void FurnaceFeedforward_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->simulationInfo->realParameter[15] /* disturbance.startTime PARAM */) = (data->simulationInfo->realParameter[17] /* t_dist PARAM */);
  TRACE_POP
}

/*
equation index: 18
type: SIMPLE_ASSIGN
disturbance.height = Q_dist
*/
OMC_DISABLE_OPT
static void FurnaceFeedforward_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->simulationInfo->realParameter[13] /* disturbance.height PARAM */) = (data->simulationInfo->realParameter[3] /* Q_dist PARAM */);
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

