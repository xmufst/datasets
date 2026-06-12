/* Initialization */
#include "SolarCollectorLoopEnhanced_model.h"
#include "SolarCollectorLoopEnhanced_11mix.h"
#include "SolarCollectorLoopEnhanced_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void SolarCollectorLoopEnhanced_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
p_system_bar = 1e-5 * p_system
*/
void SolarCollectorLoopEnhanced_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* p_system_bar variable */) = (1e-5) * ((data->simulationInfo->realParameter[7] /* p_system PARAM */));
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
T_water = $START.T_water
*/
void SolarCollectorLoopEnhanced_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_water STATE(1) */) = (data->modelData->realVarsData[0] /* T_water STATE(1) */).attribute .start;
  TRACE_POP
}
extern void SolarCollectorLoopEnhanced_eqFunction_11(DATA *data, threadData_t *threadData);

extern void SolarCollectorLoopEnhanced_eqFunction_9(DATA *data, threadData_t *threadData);


/*
equation index: 5
type: SIMPLE_ASSIGN
Q_solar = G_solar * A_collector * eta_collector
*/
void SolarCollectorLoopEnhanced_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* Q_solar variable */) = ((data->simulationInfo->realParameter[1] /* G_solar PARAM */)) * (((data->simulationInfo->realParameter[0] /* A_collector PARAM */)) * ((data->simulationInfo->realParameter[4] /* eta_collector PARAM */)));
  TRACE_POP
}
extern void SolarCollectorLoopEnhanced_eqFunction_8(DATA *data, threadData_t *threadData);

extern void SolarCollectorLoopEnhanced_eqFunction_10(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void SolarCollectorLoopEnhanced_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SolarCollectorLoopEnhanced_eqFunction_1(data, threadData);
  SolarCollectorLoopEnhanced_eqFunction_2(data, threadData);
  SolarCollectorLoopEnhanced_eqFunction_11(data, threadData);
  SolarCollectorLoopEnhanced_eqFunction_9(data, threadData);
  SolarCollectorLoopEnhanced_eqFunction_5(data, threadData);
  SolarCollectorLoopEnhanced_eqFunction_8(data, threadData);
  SolarCollectorLoopEnhanced_eqFunction_10(data, threadData);
  TRACE_POP
}

int SolarCollectorLoopEnhanced_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  SolarCollectorLoopEnhanced_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No SolarCollectorLoopEnhanced_functionInitialEquations_lambda0 function */

int SolarCollectorLoopEnhanced_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

