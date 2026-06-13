/* Initialization */
#include "DCMotorStateFeedback_model.h"
#include "DCMotorStateFeedback_11mix.h"
#include "DCMotorStateFeedback_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void DCMotorStateFeedback_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void DCMotorStateFeedback_eqFunction_15(DATA *data, threadData_t *threadData);

extern void DCMotorStateFeedback_eqFunction_14(DATA *data, threadData_t *threadData);

extern void DCMotorStateFeedback_eqFunction_16(DATA *data, threadData_t *threadData);


/*
equation index: 4
type: SIMPLE_ASSIGN
ia = $START.ia
*/
void DCMotorStateFeedback_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* ia STATE(1) */) = (data->modelData->realVarsData[0] /* ia STATE(1) */).attribute .start;
  TRACE_POP
}
extern void DCMotorStateFeedback_eqFunction_17(DATA *data, threadData_t *threadData);

extern void DCMotorStateFeedback_eqFunction_22(DATA *data, threadData_t *threadData);


/*
equation index: 7
type: SIMPLE_ASSIGN
omega = $START.omega
*/
void DCMotorStateFeedback_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* omega STATE(1) */) = (data->modelData->realVarsData[1] /* omega STATE(1) */).attribute .start;
  TRACE_POP
}
extern void DCMotorStateFeedback_eqFunction_18(DATA *data, threadData_t *threadData);

extern void DCMotorStateFeedback_eqFunction_19(DATA *data, threadData_t *threadData);

extern void DCMotorStateFeedback_eqFunction_20(DATA *data, threadData_t *threadData);

extern void DCMotorStateFeedback_eqFunction_21(DATA *data, threadData_t *threadData);

extern void DCMotorStateFeedback_eqFunction_23(DATA *data, threadData_t *threadData);

extern void DCMotorStateFeedback_eqFunction_24(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void DCMotorStateFeedback_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  DCMotorStateFeedback_eqFunction_15(data, threadData);
  DCMotorStateFeedback_eqFunction_14(data, threadData);
  DCMotorStateFeedback_eqFunction_16(data, threadData);
  DCMotorStateFeedback_eqFunction_4(data, threadData);
  DCMotorStateFeedback_eqFunction_17(data, threadData);
  DCMotorStateFeedback_eqFunction_22(data, threadData);
  DCMotorStateFeedback_eqFunction_7(data, threadData);
  DCMotorStateFeedback_eqFunction_18(data, threadData);
  DCMotorStateFeedback_eqFunction_19(data, threadData);
  DCMotorStateFeedback_eqFunction_20(data, threadData);
  DCMotorStateFeedback_eqFunction_21(data, threadData);
  DCMotorStateFeedback_eqFunction_23(data, threadData);
  DCMotorStateFeedback_eqFunction_24(data, threadData);
  TRACE_POP
}

int DCMotorStateFeedback_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  DCMotorStateFeedback_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No DCMotorStateFeedback_functionInitialEquations_lambda0 function */

int DCMotorStateFeedback_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

