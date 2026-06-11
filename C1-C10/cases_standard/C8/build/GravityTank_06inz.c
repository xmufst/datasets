/* Initialization */
#include "GravityTank_model.h"
#include "GravityTank_11mix.h"
#include "GravityTank_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void GravityTank_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
h = h0
*/
void GravityTank_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1) */) = (data->simulationInfo->realParameter[5] /* h0 PARAM */);
  TRACE_POP
}
extern void GravityTank_eqFunction_7(DATA *data, threadData_t *threadData);

extern void GravityTank_eqFunction_8(DATA *data, threadData_t *threadData);

extern void GravityTank_eqFunction_9(DATA *data, threadData_t *threadData);

extern void GravityTank_eqFunction_10(DATA *data, threadData_t *threadData);

extern void GravityTank_eqFunction_11(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void GravityTank_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  GravityTank_eqFunction_1(data, threadData);
  GravityTank_eqFunction_7(data, threadData);
  GravityTank_eqFunction_8(data, threadData);
  GravityTank_eqFunction_9(data, threadData);
  GravityTank_eqFunction_10(data, threadData);
  GravityTank_eqFunction_11(data, threadData);
  TRACE_POP
}

int GravityTank_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  GravityTank_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No GravityTank_functionInitialEquations_lambda0 function */

int GravityTank_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

