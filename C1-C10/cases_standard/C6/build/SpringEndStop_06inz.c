/* Initialization */
#include "SpringEndStop_model.h"
#include "SpringEndStop_11mix.h"
#include "SpringEndStop_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void SpringEndStop_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
x = x0
*/
void SpringEndStop_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */) = (data->simulationInfo->realParameter[7] /* x0 PARAM */);
  TRACE_POP
}
extern void SpringEndStop_eqFunction_14(DATA *data, threadData_t *threadData);

extern void SpringEndStop_eqFunction_17(DATA *data, threadData_t *threadData);

extern void SpringEndStop_eqFunction_19(DATA *data, threadData_t *threadData);

extern void SpringEndStop_eqFunction_21(DATA *data, threadData_t *threadData);


/*
equation index: 6
type: SIMPLE_ASSIGN
v = v0
*/
void SpringEndStop_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1) */) = (data->simulationInfo->realParameter[6] /* v0 PARAM */);
  TRACE_POP
}
extern void SpringEndStop_eqFunction_15(DATA *data, threadData_t *threadData);

extern void SpringEndStop_eqFunction_16(DATA *data, threadData_t *threadData);

extern void SpringEndStop_eqFunction_18(DATA *data, threadData_t *threadData);

extern void SpringEndStop_eqFunction_20(DATA *data, threadData_t *threadData);

extern void SpringEndStop_eqFunction_22(DATA *data, threadData_t *threadData);

extern void SpringEndStop_eqFunction_23(DATA *data, threadData_t *threadData);

extern void SpringEndStop_eqFunction_24(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void SpringEndStop_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SpringEndStop_eqFunction_1(data, threadData);
  SpringEndStop_eqFunction_14(data, threadData);
  SpringEndStop_eqFunction_17(data, threadData);
  SpringEndStop_eqFunction_19(data, threadData);
  SpringEndStop_eqFunction_21(data, threadData);
  SpringEndStop_eqFunction_6(data, threadData);
  SpringEndStop_eqFunction_15(data, threadData);
  SpringEndStop_eqFunction_16(data, threadData);
  SpringEndStop_eqFunction_18(data, threadData);
  SpringEndStop_eqFunction_20(data, threadData);
  SpringEndStop_eqFunction_22(data, threadData);
  SpringEndStop_eqFunction_23(data, threadData);
  SpringEndStop_eqFunction_24(data, threadData);
  TRACE_POP
}

int SpringEndStop_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  SpringEndStop_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No SpringEndStop_functionInitialEquations_lambda0 function */

int SpringEndStop_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

