/* Initialization */
#include "FeedforwardFeedbackTemp_model.h"
#include "FeedforwardFeedbackTemp_11mix.h"
#include "FeedforwardFeedbackTemp_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void FeedforwardFeedbackTemp_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void FeedforwardFeedbackTemp_eqFunction_15(DATA *data, threadData_t *threadData);

extern void FeedforwardFeedbackTemp_eqFunction_16(DATA *data, threadData_t *threadData);


/*
equation index: 3
type: SIMPLE_ASSIGN
T = $START.T
*/
void FeedforwardFeedbackTemp_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */) = (data->modelData->realVarsData[0] /* T STATE(1) */).attribute .start;
  TRACE_POP
}
extern void FeedforwardFeedbackTemp_eqFunction_12(DATA *data, threadData_t *threadData);

extern void FeedforwardFeedbackTemp_eqFunction_13(DATA *data, threadData_t *threadData);

extern void FeedforwardFeedbackTemp_eqFunction_19(DATA *data, threadData_t *threadData);


/*
equation index: 7
type: SIMPLE_ASSIGN
piController.x = piController.x_start
*/
void FeedforwardFeedbackTemp_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piController.x STATE(1) */) = (data->simulationInfo->realParameter[18] /* piController.x_start PARAM */);
  TRACE_POP
}
extern void FeedforwardFeedbackTemp_eqFunction_14(DATA *data, threadData_t *threadData);

extern void FeedforwardFeedbackTemp_eqFunction_17(DATA *data, threadData_t *threadData);

extern void FeedforwardFeedbackTemp_eqFunction_18(DATA *data, threadData_t *threadData);

extern void FeedforwardFeedbackTemp_eqFunction_20(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void FeedforwardFeedbackTemp_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  FeedforwardFeedbackTemp_eqFunction_15(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_16(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_3(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_12(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_13(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_19(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_7(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_14(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_17(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_18(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_20(data, threadData);
  TRACE_POP
}

int FeedforwardFeedbackTemp_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  FeedforwardFeedbackTemp_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No FeedforwardFeedbackTemp_functionInitialEquations_lambda0 function */

int FeedforwardFeedbackTemp_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

