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
T = T0
*/
void NewtonCooling_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* T STATE(1) */) = (data->simulationInfo->realParameter[0] /* T0 PARAM */);
  TRACE_POP
}
extern void NewtonCooling_eqFunction_8(DATA *data, threadData_t *threadData);

extern void NewtonCooling_eqFunction_11(DATA *data, threadData_t *threadData);

extern void NewtonCooling_eqFunction_9(DATA *data, threadData_t *threadData);

extern void NewtonCooling_eqFunction_10(DATA *data, threadData_t *threadData);

extern void NewtonCooling_eqFunction_12(DATA *data, threadData_t *threadData);


/*
equation index: 7
type: SIMPLE_ASSIGN
E_dissipated = $START.E_dissipated
*/
void NewtonCooling_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* E_dissipated STATE(1,Q_dot) */) = (data->modelData->realVarsData[0] /* E_dissipated STATE(1,Q_dot) */).attribute .start;
  TRACE_POP
}
OMC_DISABLE_OPT
void NewtonCooling_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  NewtonCooling_eqFunction_1(data, threadData);
  NewtonCooling_eqFunction_8(data, threadData);
  NewtonCooling_eqFunction_11(data, threadData);
  NewtonCooling_eqFunction_9(data, threadData);
  NewtonCooling_eqFunction_10(data, threadData);
  NewtonCooling_eqFunction_12(data, threadData);
  NewtonCooling_eqFunction_7(data, threadData);
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

