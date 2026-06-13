/* Initialization */
#include "SpringMassGainScheduling_model.h"
#include "SpringMassGainScheduling_11mix.h"
#include "SpringMassGainScheduling_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void SpringMassGainScheduling_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void SpringMassGainScheduling_eqFunction_12(DATA *data, threadData_t *threadData);


/*
equation index: 2
type: SIMPLE_ASSIGN
x = $START.x
*/
void SpringMassGainScheduling_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */) = (data->modelData->realVarsData[1] /* x STATE(1,v) */).attribute .start;
  TRACE_POP
}
extern void SpringMassGainScheduling_eqFunction_13(DATA *data, threadData_t *threadData);

extern void SpringMassGainScheduling_eqFunction_14(DATA *data, threadData_t *threadData);

extern void SpringMassGainScheduling_eqFunction_16(DATA *data, threadData_t *threadData);


/*
equation index: 6
type: SIMPLE_ASSIGN
v = $START.v
*/
void SpringMassGainScheduling_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */) = (data->modelData->realVarsData[0] /* v STATE(1,a) */).attribute .start;
  TRACE_POP
}
extern void SpringMassGainScheduling_eqFunction_15(DATA *data, threadData_t *threadData);

extern void SpringMassGainScheduling_eqFunction_17(DATA *data, threadData_t *threadData);

extern void SpringMassGainScheduling_eqFunction_19(DATA *data, threadData_t *threadData);

extern void SpringMassGainScheduling_eqFunction_18(DATA *data, threadData_t *threadData);

extern void SpringMassGainScheduling_eqFunction_20(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void SpringMassGainScheduling_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SpringMassGainScheduling_eqFunction_12(data, threadData);
  SpringMassGainScheduling_eqFunction_2(data, threadData);
  SpringMassGainScheduling_eqFunction_13(data, threadData);
  SpringMassGainScheduling_eqFunction_14(data, threadData);
  SpringMassGainScheduling_eqFunction_16(data, threadData);
  SpringMassGainScheduling_eqFunction_6(data, threadData);
  SpringMassGainScheduling_eqFunction_15(data, threadData);
  SpringMassGainScheduling_eqFunction_17(data, threadData);
  SpringMassGainScheduling_eqFunction_19(data, threadData);
  SpringMassGainScheduling_eqFunction_18(data, threadData);
  SpringMassGainScheduling_eqFunction_20(data, threadData);
  TRACE_POP
}

int SpringMassGainScheduling_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  SpringMassGainScheduling_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No SpringMassGainScheduling_functionInitialEquations_lambda0 function */

int SpringMassGainScheduling_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

