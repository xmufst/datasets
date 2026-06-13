/* Initialization */
#include "ForcedDampedOscillator_model.h"
#include "ForcedDampedOscillator_11mix.h"
#include "ForcedDampedOscillator_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void ForcedDampedOscillator_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
F_ext = F0 * sin(omega * time)
*/
void ForcedDampedOscillator_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* F_ext variable */) = ((data->simulationInfo->realParameter[0] /* F0 PARAM */)) * (sin(((data->simulationInfo->realParameter[5] /* omega PARAM */)) * (data->localData[0]->timeValue)));
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
x = $START.x
*/
void ForcedDampedOscillator_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */) = (data->modelData->realVarsData[1] /* x STATE(1,v) */).attribute .start;
  TRACE_POP
}
extern void ForcedDampedOscillator_eqFunction_16(DATA *data, threadData_t *threadData);

extern void ForcedDampedOscillator_eqFunction_21(DATA *data, threadData_t *threadData);


/*
equation index: 5
type: SIMPLE_ASSIGN
v = $START.v
*/
void ForcedDampedOscillator_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */) = (data->modelData->realVarsData[0] /* v STATE(1,a) */).attribute .start;
  TRACE_POP
}
extern void ForcedDampedOscillator_eqFunction_15(DATA *data, threadData_t *threadData);

extern void ForcedDampedOscillator_eqFunction_25(DATA *data, threadData_t *threadData);

extern void ForcedDampedOscillator_eqFunction_17(DATA *data, threadData_t *threadData);

extern void ForcedDampedOscillator_eqFunction_18(DATA *data, threadData_t *threadData);

extern void ForcedDampedOscillator_eqFunction_19(DATA *data, threadData_t *threadData);

extern void ForcedDampedOscillator_eqFunction_20(DATA *data, threadData_t *threadData);

extern void ForcedDampedOscillator_eqFunction_23(DATA *data, threadData_t *threadData);

extern void ForcedDampedOscillator_eqFunction_24(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void ForcedDampedOscillator_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  ForcedDampedOscillator_eqFunction_1(data, threadData);
  ForcedDampedOscillator_eqFunction_2(data, threadData);
  ForcedDampedOscillator_eqFunction_16(data, threadData);
  ForcedDampedOscillator_eqFunction_21(data, threadData);
  ForcedDampedOscillator_eqFunction_5(data, threadData);
  ForcedDampedOscillator_eqFunction_15(data, threadData);
  ForcedDampedOscillator_eqFunction_25(data, threadData);
  ForcedDampedOscillator_eqFunction_17(data, threadData);
  ForcedDampedOscillator_eqFunction_18(data, threadData);
  ForcedDampedOscillator_eqFunction_19(data, threadData);
  ForcedDampedOscillator_eqFunction_20(data, threadData);
  ForcedDampedOscillator_eqFunction_23(data, threadData);
  ForcedDampedOscillator_eqFunction_24(data, threadData);
  TRACE_POP
}

int ForcedDampedOscillator_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  ForcedDampedOscillator_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No ForcedDampedOscillator_functionInitialEquations_lambda0 function */

int ForcedDampedOscillator_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

