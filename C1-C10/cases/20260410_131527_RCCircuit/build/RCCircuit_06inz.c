/* Initialization */
#include "RCCircuit_model.h"
#include "RCCircuit_11mix.h"
#include "RCCircuit_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void RCCircuit_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
tau = R * C
*/
void RCCircuit_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* tau variable */) = ((data->simulationInfo->realParameter[1] /* R PARAM */)) * ((data->simulationInfo->realParameter[0] /* C PARAM */));
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
resistor.R_actual = resistor.R * (1.0 + resistor.alpha * (resistor.T - resistor.T_ref))
*/
void RCCircuit_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* resistor.R_actual variable */) = ((data->simulationInfo->realParameter[5] /* resistor.R PARAM */)) * (1.0 + ((data->simulationInfo->realParameter[9] /* resistor.alpha PARAM */)) * ((data->simulationInfo->realParameter[6] /* resistor.T PARAM */) - (data->simulationInfo->realParameter[8] /* resistor.T_ref PARAM */)));
  TRACE_POP
}
extern void RCCircuit_eqFunction_16(DATA *data, threadData_t *threadData);


/*
equation index: 4
type: SIMPLE_ASSIGN
capacitor.v = Vc0
*/
void RCCircuit_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* capacitor.v STATE(1) */) = (data->simulationInfo->realParameter[3] /* Vc0 PARAM */);
  TRACE_POP
}
extern void RCCircuit_eqFunction_15(DATA *data, threadData_t *threadData);

extern void RCCircuit_eqFunction_17(DATA *data, threadData_t *threadData);

extern void RCCircuit_eqFunction_18(DATA *data, threadData_t *threadData);

extern void RCCircuit_eqFunction_21(DATA *data, threadData_t *threadData);

extern void RCCircuit_eqFunction_22(DATA *data, threadData_t *threadData);

extern void RCCircuit_eqFunction_20(DATA *data, threadData_t *threadData);

extern void RCCircuit_eqFunction_19(DATA *data, threadData_t *threadData);


/*
equation index: 12
type: SIMPLE_ASSIGN
ground.p.i = 0.0
*/
void RCCircuit_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* ground.p.i variable */) = 0.0;
  TRACE_POP
}

/*
equation index: 13
type: SIMPLE_ASSIGN
ground.p.v = 0.0
*/
void RCCircuit_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* ground.p.v variable */) = 0.0;
  TRACE_POP
}

/*
equation index: 14
type: SIMPLE_ASSIGN
E_dissipated = $START.E_dissipated
*/
void RCCircuit_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* E_dissipated STATE(1,P_resistor) */) = (data->modelData->realVarsData[0] /* E_dissipated STATE(1,P_resistor) */).attribute .start;
  TRACE_POP
}
OMC_DISABLE_OPT
void RCCircuit_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  RCCircuit_eqFunction_1(data, threadData);
  RCCircuit_eqFunction_2(data, threadData);
  RCCircuit_eqFunction_16(data, threadData);
  RCCircuit_eqFunction_4(data, threadData);
  RCCircuit_eqFunction_15(data, threadData);
  RCCircuit_eqFunction_17(data, threadData);
  RCCircuit_eqFunction_18(data, threadData);
  RCCircuit_eqFunction_21(data, threadData);
  RCCircuit_eqFunction_22(data, threadData);
  RCCircuit_eqFunction_20(data, threadData);
  RCCircuit_eqFunction_19(data, threadData);
  RCCircuit_eqFunction_12(data, threadData);
  RCCircuit_eqFunction_13(data, threadData);
  RCCircuit_eqFunction_14(data, threadData);
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

