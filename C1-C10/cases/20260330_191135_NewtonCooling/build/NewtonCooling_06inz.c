/* Initialization */
#include "NewtonCooling_model.h"
#include "NewtonCooling_11mix.h"
#include "NewtonCooling_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void NewtonCooling_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
E_dissipated = $START.E_dissipated
*/
void NewtonCooling_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* E_dissipated STATE(1,Q_dot) */) = (data->modelData->realVarsData[0] /* E_dissipated STATE(1,Q_dot) */).attribute .start;
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
tau = m * cp / hA
*/
void NewtonCooling_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* tau variable */) = ((data->simulationInfo->realParameter[4] /* m PARAM */)) * (DIVISION_SIM((data->simulationInfo->realParameter[2] /* cp PARAM */),(data->simulationInfo->realParameter[3] /* hA PARAM */),"hA",equationIndexes));
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
T = $START.T
*/
void NewtonCooling_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* T STATE(1) */) = (data->modelData->realVarsData[1] /* T STATE(1) */).attribute .start;
  TRACE_POP
}
extern void NewtonCooling_eqFunction_9(DATA *data, threadData_t *threadData);

extern void NewtonCooling_eqFunction_10(DATA *data, threadData_t *threadData);

extern void NewtonCooling_eqFunction_11(DATA *data, threadData_t *threadData);

extern void NewtonCooling_eqFunction_13(DATA *data, threadData_t *threadData);

extern void NewtonCooling_eqFunction_12(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void NewtonCooling_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  NewtonCooling_eqFunction_1(data, threadData);
  NewtonCooling_eqFunction_2(data, threadData);
  NewtonCooling_eqFunction_3(data, threadData);
  NewtonCooling_eqFunction_9(data, threadData);
  NewtonCooling_eqFunction_10(data, threadData);
  NewtonCooling_eqFunction_11(data, threadData);
  NewtonCooling_eqFunction_13(data, threadData);
  NewtonCooling_eqFunction_12(data, threadData);
  TRACE_POP
}

int NewtonCooling_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  NewtonCooling_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No NewtonCooling_functionInitialEquations_lambda0 function */

int NewtonCooling_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

