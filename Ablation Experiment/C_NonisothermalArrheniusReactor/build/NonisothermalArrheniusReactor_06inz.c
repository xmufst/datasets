/* Initialization */
#include "NonisothermalArrheniusReactor_model.h"
#include "NonisothermalArrheniusReactor_11mix.h"
#include "NonisothermalArrheniusReactor_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void NonisothermalArrheniusReactor_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
C_A = $START.C_A
*/
void NonisothermalArrheniusReactor_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* C_A STATE(1) */) = (data->modelData->realVarsData[0] /* C_A STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
C_B = $START.C_B
*/
void NonisothermalArrheniusReactor_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* C_B STATE(1,r) */) = (data->modelData->realVarsData[1] /* C_B STATE(1,r) */).attribute .start;
  TRACE_POP
}
extern void NonisothermalArrheniusReactor_eqFunction_24(DATA *data, threadData_t *threadData);

extern void NonisothermalArrheniusReactor_eqFunction_25(DATA *data, threadData_t *threadData);


/*
equation index: 5
type: SIMPLE_ASSIGN
T = $START.T
*/
void NonisothermalArrheniusReactor_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T STATE(1) */) = (data->modelData->realVarsData[4] /* T STATE(1) */).attribute .start;
  TRACE_POP
}
extern void NonisothermalArrheniusReactor_eqFunction_20(DATA *data, threadData_t *threadData);

extern void NonisothermalArrheniusReactor_eqFunction_22(DATA *data, threadData_t *threadData);

extern void NonisothermalArrheniusReactor_eqFunction_23(DATA *data, threadData_t *threadData);


/*
equation index: 9
type: SIMPLE_ASSIGN
k = k0 * exp((-Ea) / (R * T))
*/
void NonisothermalArrheniusReactor_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* k variable */) = ((data->simulationInfo->realParameter[7] /* k0 PARAM */)) * (exp(DIVISION_SIM((-(data->simulationInfo->realParameter[0] /* Ea PARAM */)),((data->simulationInfo->realParameter[1] /* R PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T STATE(1) */)),"R * T",equationIndexes)));
  TRACE_POP
}
extern void NonisothermalArrheniusReactor_eqFunction_27(DATA *data, threadData_t *threadData);

extern void NonisothermalArrheniusReactor_eqFunction_30(DATA *data, threadData_t *threadData);

extern void NonisothermalArrheniusReactor_eqFunction_32(DATA *data, threadData_t *threadData);

extern void NonisothermalArrheniusReactor_eqFunction_31(DATA *data, threadData_t *threadData);

extern void NonisothermalArrheniusReactor_eqFunction_29(DATA *data, threadData_t *threadData);

extern void NonisothermalArrheniusReactor_eqFunction_28(DATA *data, threadData_t *threadData);


/*
equation index: 16
type: SIMPLE_ASSIGN
E_reaction_input = $START.E_reaction_input
*/
void NonisothermalArrheniusReactor_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* E_reaction_input STATE(1,Q_reaction) */) = (data->modelData->realVarsData[3] /* E_reaction_input STATE(1,Q_reaction) */).attribute .start;
  TRACE_POP
}

/*
equation index: 17
type: SIMPLE_ASSIGN
E_cooling_output = $START.E_cooling_output
*/
void NonisothermalArrheniusReactor_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* E_cooling_output STATE(1,Q_cooling) */) = (data->modelData->realVarsData[2] /* E_cooling_output STATE(1,Q_cooling) */).attribute .start;
  TRACE_POP
}
extern void NonisothermalArrheniusReactor_eqFunction_21(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void NonisothermalArrheniusReactor_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  NonisothermalArrheniusReactor_eqFunction_1(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_2(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_24(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_25(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_5(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_20(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_22(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_23(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_9(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_27(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_30(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_32(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_31(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_29(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_28(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_16(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_17(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_21(data, threadData);
  TRACE_POP
}

int NonisothermalArrheniusReactor_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  NonisothermalArrheniusReactor_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No NonisothermalArrheniusReactor_functionInitialEquations_lambda0 function */

int NonisothermalArrheniusReactor_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

