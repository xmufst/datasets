/* Initialization */
#include "FurnaceFeedforward_model.h"
#include "FurnaceFeedforward_11mix.h"
#include "FurnaceFeedforward_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void FurnaceFeedforward_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void FurnaceFeedforward_eqFunction_7(DATA *data, threadData_t *threadData);

extern void FurnaceFeedforward_eqFunction_8(DATA *data, threadData_t *threadData);

extern void FurnaceFeedforward_eqFunction_9(DATA *data, threadData_t *threadData);


/*
equation index: 4
type: SIMPLE_ASSIGN
T = T0
*/
void FurnaceFeedforward_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */) = (data->simulationInfo->realParameter[5] /* T0 PARAM */);
  TRACE_POP
}
extern void FurnaceFeedforward_eqFunction_10(DATA *data, threadData_t *threadData);

extern void FurnaceFeedforward_eqFunction_11(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void FurnaceFeedforward_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  FurnaceFeedforward_eqFunction_7(data, threadData);
  FurnaceFeedforward_eqFunction_8(data, threadData);
  FurnaceFeedforward_eqFunction_9(data, threadData);
  FurnaceFeedforward_eqFunction_4(data, threadData);
  FurnaceFeedforward_eqFunction_10(data, threadData);
  FurnaceFeedforward_eqFunction_11(data, threadData);
  TRACE_POP
}

int FurnaceFeedforward_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  FurnaceFeedforward_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No FurnaceFeedforward_functionInitialEquations_lambda0 function */

int FurnaceFeedforward_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

