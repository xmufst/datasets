/* Delay */
#include "SmithPredictorTemp_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

int SmithPredictorTemp_function_storeDelayed(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  int equationIndexes[2] = {1,-1};
  equationIndexes[1] = 0;
  storeDelayedExpression(data, threadData, 0, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* T_process STATE(1) */), (data->simulationInfo->realParameter[2] /* L PARAM */), (data->simulationInfo->realParameter[2] /* L PARAM */));
  equationIndexes[1] = 1;
  storeDelayedExpression(data, threadData, 1, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_model STATE(1) */), (data->simulationInfo->realParameter[2] /* L PARAM */), (data->simulationInfo->realParameter[2] /* L PARAM */));
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

