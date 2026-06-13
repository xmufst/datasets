/* Initialization */
#include "FallingWithDrag_model.h"
#include "FallingWithDrag_11mix.h"
#include "FallingWithDrag_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void FallingWithDrag_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
F_gravity = m * g
*/
void FallingWithDrag_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* F_gravity variable */) = ((data->simulationInfo->realParameter[2] /* m PARAM */)) * ((data->simulationInfo->realParameter[1] /* g PARAM */));
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
y = $START.y
*/
void FallingWithDrag_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* y STATE(1,v) */) = (data->modelData->realVarsData[1] /* y STATE(1,v) */).attribute .start;
  TRACE_POP
}
extern void FallingWithDrag_eqFunction_13(DATA *data, threadData_t *threadData);


/*
equation index: 4
type: SIMPLE_ASSIGN
v = v0
*/
void FallingWithDrag_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */) = (data->simulationInfo->realParameter[3] /* v0 PARAM */);
  TRACE_POP
}
extern void FallingWithDrag_eqFunction_14(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_15(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_16(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_17(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_19(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_20(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_18(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_21(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void FallingWithDrag_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  FallingWithDrag_eqFunction_1(data, threadData);
  FallingWithDrag_eqFunction_2(data, threadData);
  FallingWithDrag_eqFunction_13(data, threadData);
  FallingWithDrag_eqFunction_4(data, threadData);
  FallingWithDrag_eqFunction_14(data, threadData);
  FallingWithDrag_eqFunction_15(data, threadData);
  FallingWithDrag_eqFunction_16(data, threadData);
  FallingWithDrag_eqFunction_17(data, threadData);
  FallingWithDrag_eqFunction_19(data, threadData);
  FallingWithDrag_eqFunction_20(data, threadData);
  FallingWithDrag_eqFunction_18(data, threadData);
  FallingWithDrag_eqFunction_21(data, threadData);
  TRACE_POP
}

int FallingWithDrag_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  FallingWithDrag_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No FallingWithDrag_functionInitialEquations_lambda0 function */

int FallingWithDrag_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

