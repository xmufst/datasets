/* Initialization */
#include "SpringMassDamper_model.h"
#include "SpringMassDamper_11mix.h"
#include "SpringMassDamper_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void SpringMassDamper_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
x = x0
*/
void SpringMassDamper_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */) = (data->simulationInfo->realParameter[5] /* x0 PARAM */);
  TRACE_POP
}
extern void SpringMassDamper_eqFunction_11(DATA *data, threadData_t *threadData);

extern void SpringMassDamper_eqFunction_15(DATA *data, threadData_t *threadData);


/*
equation index: 4
type: SIMPLE_ASSIGN
v = v0
*/
void SpringMassDamper_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */) = (data->simulationInfo->realParameter[4] /* v0 PARAM */);
  TRACE_POP
}
extern void SpringMassDamper_eqFunction_12(DATA *data, threadData_t *threadData);

extern void SpringMassDamper_eqFunction_13(DATA *data, threadData_t *threadData);

extern void SpringMassDamper_eqFunction_14(DATA *data, threadData_t *threadData);

extern void SpringMassDamper_eqFunction_16(DATA *data, threadData_t *threadData);

extern void SpringMassDamper_eqFunction_17(DATA *data, threadData_t *threadData);

extern void SpringMassDamper_eqFunction_18(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void SpringMassDamper_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SpringMassDamper_eqFunction_1(data, threadData);
  SpringMassDamper_eqFunction_11(data, threadData);
  SpringMassDamper_eqFunction_15(data, threadData);
  SpringMassDamper_eqFunction_4(data, threadData);
  SpringMassDamper_eqFunction_12(data, threadData);
  SpringMassDamper_eqFunction_13(data, threadData);
  SpringMassDamper_eqFunction_14(data, threadData);
  SpringMassDamper_eqFunction_16(data, threadData);
  SpringMassDamper_eqFunction_17(data, threadData);
  SpringMassDamper_eqFunction_18(data, threadData);
  TRACE_POP
}

int SpringMassDamper_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  SpringMassDamper_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No SpringMassDamper_functionInitialEquations_lambda0 function */

int SpringMassDamper_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

