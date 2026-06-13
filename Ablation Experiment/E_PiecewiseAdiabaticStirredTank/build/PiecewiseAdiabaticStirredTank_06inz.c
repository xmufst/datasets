/* Initialization */
#include "PiecewiseAdiabaticStirredTank_model.h"
#include "PiecewiseAdiabaticStirredTank_11mix.h"
#include "PiecewiseAdiabaticStirredTank_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void PiecewiseAdiabaticStirredTank_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void PiecewiseAdiabaticStirredTank_eqFunction_13(DATA *data, threadData_t *threadData);

extern void PiecewiseAdiabaticStirredTank_eqFunction_14(DATA *data, threadData_t *threadData);

extern void PiecewiseAdiabaticStirredTank_eqFunction_15(DATA *data, threadData_t *threadData);

extern void PiecewiseAdiabaticStirredTank_eqFunction_16(DATA *data, threadData_t *threadData);


/*
equation index: 5
type: SIMPLE_ASSIGN
T_liquid = $START.T_liquid
*/
void PiecewiseAdiabaticStirredTank_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_liquid STATE(1,dTdt_theoretical) */) = (data->modelData->realVarsData[0] /* T_liquid STATE(1,dTdt_theoretical) */).attribute .start;
  TRACE_POP
}
extern void PiecewiseAdiabaticStirredTank_eqFunction_10(DATA *data, threadData_t *threadData);

extern void PiecewiseAdiabaticStirredTank_eqFunction_12(DATA *data, threadData_t *threadData);


/*
equation index: 8
type: SIMPLE_ASSIGN
energy_added = $START.energy_added
*/
void PiecewiseAdiabaticStirredTank_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* energy_added STATE(1,P_stir) */) = (data->modelData->realVarsData[1] /* energy_added STATE(1,P_stir) */).attribute .start;
  TRACE_POP
}
extern void PiecewiseAdiabaticStirredTank_eqFunction_11(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void PiecewiseAdiabaticStirredTank_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  PiecewiseAdiabaticStirredTank_eqFunction_13(data, threadData);
  PiecewiseAdiabaticStirredTank_eqFunction_14(data, threadData);
  PiecewiseAdiabaticStirredTank_eqFunction_15(data, threadData);
  PiecewiseAdiabaticStirredTank_eqFunction_16(data, threadData);
  PiecewiseAdiabaticStirredTank_eqFunction_5(data, threadData);
  PiecewiseAdiabaticStirredTank_eqFunction_10(data, threadData);
  PiecewiseAdiabaticStirredTank_eqFunction_12(data, threadData);
  PiecewiseAdiabaticStirredTank_eqFunction_8(data, threadData);
  PiecewiseAdiabaticStirredTank_eqFunction_11(data, threadData);
  TRACE_POP
}

int PiecewiseAdiabaticStirredTank_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  PiecewiseAdiabaticStirredTank_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No PiecewiseAdiabaticStirredTank_functionInitialEquations_lambda0 function */

int PiecewiseAdiabaticStirredTank_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

