/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "DCMotorStateFeedback_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int DCMotorStateFeedback_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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

void DCMotorStateFeedback_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 25
type: SIMPLE_ASSIGN
speedFeedbackGain.k = K2
*/
OMC_DISABLE_OPT
static void DCMotorStateFeedback_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->simulationInfo->realParameter[22] /* speedFeedbackGain.k PARAM */) = (data->simulationInfo->realParameter[3] /* K2 PARAM */);
  TRACE_POP
}

/*
equation index: 26
type: SIMPLE_ASSIGN
currentFeedbackGain.k = K1
*/
OMC_DISABLE_OPT
static void DCMotorStateFeedback_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->simulationInfo->realParameter[13] /* currentFeedbackGain.k PARAM */) = (data->simulationInfo->realParameter[2] /* K1 PARAM */);
  TRACE_POP
}

/*
equation index: 27
type: SIMPLE_ASSIGN
feedforwardGain.k = Kr
*/
OMC_DISABLE_OPT
static void DCMotorStateFeedback_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  (data->simulationInfo->realParameter[14] /* feedforwardGain.k PARAM */) = (data->simulationInfo->realParameter[5] /* Kr PARAM */);
  TRACE_POP
}

/*
equation index: 28
type: SIMPLE_ASSIGN
loadTorqueStep.startTime = t_load
*/
OMC_DISABLE_OPT
static void DCMotorStateFeedback_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  (data->simulationInfo->realParameter[17] /* loadTorqueStep.startTime PARAM */) = (data->simulationInfo->realParameter[23] /* t_load PARAM */);
  TRACE_POP
}

/*
equation index: 29
type: SIMPLE_ASSIGN
loadTorqueStep.height = T_load_step
*/
OMC_DISABLE_OPT
static void DCMotorStateFeedback_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  (data->simulationInfo->realParameter[15] /* loadTorqueStep.height PARAM */) = (data->simulationInfo->realParameter[9] /* T_load_step PARAM */);
  TRACE_POP
}

/*
equation index: 30
type: SIMPLE_ASSIGN
referenceStep.height = omega_ref
*/
OMC_DISABLE_OPT
static void DCMotorStateFeedback_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  (data->simulationInfo->realParameter[19] /* referenceStep.height PARAM */) = (data->simulationInfo->realParameter[18] /* omega_ref PARAM */);
  TRACE_POP
}
OMC_DISABLE_OPT
void DCMotorStateFeedback_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  DCMotorStateFeedback_eqFunction_25(data, threadData);
  DCMotorStateFeedback_eqFunction_26(data, threadData);
  DCMotorStateFeedback_eqFunction_27(data, threadData);
  DCMotorStateFeedback_eqFunction_28(data, threadData);
  DCMotorStateFeedback_eqFunction_29(data, threadData);
  DCMotorStateFeedback_eqFunction_30(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int DCMotorStateFeedback_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  DCMotorStateFeedback_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

