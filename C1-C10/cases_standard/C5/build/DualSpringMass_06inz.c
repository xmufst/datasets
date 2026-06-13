/* Initialization */
#include "DualSpringMass_model.h"
#include "DualSpringMass_11mix.h"
#include "DualSpringMass_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void DualSpringMass_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
x1 = x1_0
*/
void DualSpringMass_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* x1 STATE(1,v1) */) = (data->simulationInfo->realParameter[6] /* x1_0 PARAM */);
  TRACE_POP
}
extern void DualSpringMass_eqFunction_20(DATA *data, threadData_t *threadData);


/*
equation index: 3
type: SIMPLE_ASSIGN
v1 = v1_0
*/
void DualSpringMass_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v1 STATE(1) */) = (data->simulationInfo->realParameter[4] /* v1_0 PARAM */);
  TRACE_POP
}
extern void DualSpringMass_eqFunction_24(DATA *data, threadData_t *threadData);


/*
equation index: 5
type: SIMPLE_ASSIGN
x2 = x2_0
*/
void DualSpringMass_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* x2 STATE(1,v2) */) = (data->simulationInfo->realParameter[7] /* x2_0 PARAM */);
  TRACE_POP
}
extern void DualSpringMass_eqFunction_15(DATA *data, threadData_t *threadData);

extern void DualSpringMass_eqFunction_16(DATA *data, threadData_t *threadData);

extern void DualSpringMass_eqFunction_19(DATA *data, threadData_t *threadData);

extern void DualSpringMass_eqFunction_23(DATA *data, threadData_t *threadData);

extern void DualSpringMass_eqFunction_21(DATA *data, threadData_t *threadData);


/*
equation index: 11
type: SIMPLE_ASSIGN
v2 = v2_0
*/
void DualSpringMass_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v2 STATE(1) */) = (data->simulationInfo->realParameter[5] /* v2_0 PARAM */);
  TRACE_POP
}
extern void DualSpringMass_eqFunction_17(DATA *data, threadData_t *threadData);

extern void DualSpringMass_eqFunction_18(DATA *data, threadData_t *threadData);

extern void DualSpringMass_eqFunction_22(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void DualSpringMass_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  DualSpringMass_eqFunction_1(data, threadData);
  DualSpringMass_eqFunction_20(data, threadData);
  DualSpringMass_eqFunction_3(data, threadData);
  DualSpringMass_eqFunction_24(data, threadData);
  DualSpringMass_eqFunction_5(data, threadData);
  DualSpringMass_eqFunction_15(data, threadData);
  DualSpringMass_eqFunction_16(data, threadData);
  DualSpringMass_eqFunction_19(data, threadData);
  DualSpringMass_eqFunction_23(data, threadData);
  DualSpringMass_eqFunction_21(data, threadData);
  DualSpringMass_eqFunction_11(data, threadData);
  DualSpringMass_eqFunction_17(data, threadData);
  DualSpringMass_eqFunction_18(data, threadData);
  DualSpringMass_eqFunction_22(data, threadData);
  TRACE_POP
}

int DualSpringMass_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  DualSpringMass_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No DualSpringMass_functionInitialEquations_lambda0 function */

int DualSpringMass_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

