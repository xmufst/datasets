/* Initialization */
#include "SimplePendulum_model.h"
#include "SimplePendulum_11mix.h"
#include "SimplePendulum_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void SimplePendulum_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
theta = theta0
*/
void SimplePendulum_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* theta STATE(1,omega) */) = (data->simulationInfo->realParameter[3] /* theta0 PARAM */);
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
E_potential = g * (L - L * cos(theta))
*/
void SimplePendulum_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* E_potential variable */) = ((data->simulationInfo->realParameter[1] /* g PARAM */)) * ((data->simulationInfo->realParameter[0] /* L PARAM */) - (((data->simulationInfo->realParameter[0] /* L PARAM */)) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* theta STATE(1,omega) */)))));
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
y = (-L) * cos(theta)
*/
void SimplePendulum_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* y variable */) = ((-(data->simulationInfo->realParameter[0] /* L PARAM */))) * (cos((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* theta STATE(1,omega) */)));
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
x = L * sin(theta)
*/
void SimplePendulum_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* x variable */) = ((data->simulationInfo->realParameter[0] /* L PARAM */)) * (sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* theta STATE(1,omega) */)));
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
$DER.omega = (-sin(theta)) * g / L
*/
void SimplePendulum_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(omega) STATE_DER */) = ((-sin((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* theta STATE(1,omega) */)))) * (DIVISION_SIM((data->simulationInfo->realParameter[1] /* g PARAM */),(data->simulationInfo->realParameter[0] /* L PARAM */),"L",equationIndexes));
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
omega = omega0
*/
void SimplePendulum_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* omega STATE(1) */) = (data->simulationInfo->realParameter[2] /* omega0 PARAM */);
  TRACE_POP
}
extern void SimplePendulum_eqFunction_13(DATA *data, threadData_t *threadData);

extern void SimplePendulum_eqFunction_14(DATA *data, threadData_t *threadData);

extern void SimplePendulum_eqFunction_18(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void SimplePendulum_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SimplePendulum_eqFunction_1(data, threadData);
  SimplePendulum_eqFunction_2(data, threadData);
  SimplePendulum_eqFunction_3(data, threadData);
  SimplePendulum_eqFunction_4(data, threadData);
  SimplePendulum_eqFunction_5(data, threadData);
  SimplePendulum_eqFunction_6(data, threadData);
  SimplePendulum_eqFunction_13(data, threadData);
  SimplePendulum_eqFunction_14(data, threadData);
  SimplePendulum_eqFunction_18(data, threadData);
  TRACE_POP
}

int SimplePendulum_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  SimplePendulum_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No SimplePendulum_functionInitialEquations_lambda0 function */

int SimplePendulum_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

