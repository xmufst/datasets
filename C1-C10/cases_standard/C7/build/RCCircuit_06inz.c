/* Initialization */
#include "RCCircuit_model.h"
#include "RCCircuit_11mix.h"
#include "RCCircuit_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void RCCircuit_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void RCCircuit_eqFunction_10(DATA *data, threadData_t *threadData);


/*
equation index: 2
type: SIMPLE_ASSIGN
Vc = Vc0
*/
void RCCircuit_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* Vc STATE(1) */) = (data->simulationInfo->realParameter[3] /* Vc0 PARAM */);
  TRACE_POP
}
extern void RCCircuit_eqFunction_9(DATA *data, threadData_t *threadData);

extern void RCCircuit_eqFunction_11(DATA *data, threadData_t *threadData);

extern void RCCircuit_eqFunction_13(DATA *data, threadData_t *threadData);

extern void RCCircuit_eqFunction_14(DATA *data, threadData_t *threadData);

extern void RCCircuit_eqFunction_12(DATA *data, threadData_t *threadData);


/*
equation index: 8
type: SIMPLE_ASSIGN
E_dissipated = $START.E_dissipated
*/
void RCCircuit_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* E_dissipated STATE(1,P_resistor) */) = (data->modelData->realVarsData[0] /* E_dissipated STATE(1,P_resistor) */).attribute .start;
  TRACE_POP
}
OMC_DISABLE_OPT
void RCCircuit_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  RCCircuit_eqFunction_10(data, threadData);
  RCCircuit_eqFunction_2(data, threadData);
  RCCircuit_eqFunction_9(data, threadData);
  RCCircuit_eqFunction_11(data, threadData);
  RCCircuit_eqFunction_13(data, threadData);
  RCCircuit_eqFunction_14(data, threadData);
  RCCircuit_eqFunction_12(data, threadData);
  RCCircuit_eqFunction_8(data, threadData);
  TRACE_POP
}

int RCCircuit_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  RCCircuit_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No RCCircuit_functionInitialEquations_lambda0 function */

int RCCircuit_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

