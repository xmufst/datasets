/* Initialization */
#include "TurbineOverspeedTripEnhanced_model.h"
#include "TurbineOverspeedTripEnhanced_11mix.h"
#include "TurbineOverspeedTripEnhanced_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void TurbineOverspeedTripEnhanced_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_25(DATA *data, threadData_t *threadData);


/*
equation index: 2
type: SIMPLE_ASSIGN
$PRE.trip_latched = false
*/
void TurbineOverspeedTripEnhanced_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->simulationInfo->booleanVarsPre[3] /* trip_latched DISCRETE */) = 0 /* false */;
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
trip_latched = $PRE.trip_latched
*/
void TurbineOverspeedTripEnhanced_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[3]] /* trip_latched DISCRETE */) = (data->simulationInfo->booleanVarsPre[3] /* trip_latched DISCRETE */);
  TRACE_POP
}
extern void TurbineOverspeedTripEnhanced_eqFunction_21(DATA *data, threadData_t *threadData);


/*
equation index: 5
type: SIMPLE_ASSIGN
trip_timer = $START.trip_timer
*/
void TurbineOverspeedTripEnhanced_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* trip_timer STATE(1) */) = (data->modelData->realVarsData[1] /* trip_timer STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
$whenCondition1 = trip_timer >= trip_delay and not $PRE.trip_latched
*/
void TurbineOverspeedTripEnhanced_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  modelica_boolean tmp0;
  tmp0 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* trip_timer STATE(1) */),(data->simulationInfo->realParameter[10] /* trip_delay PARAM */));
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = (tmp0 && (!(data->simulationInfo->booleanVarsPre[3] /* trip_latched DISCRETE */)));
  TRACE_POP
}

/*
equation index: 7
type: SIMPLE_ASSIGN
valve_opening = $START.valve_opening
*/
void TurbineOverspeedTripEnhanced_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* valve_opening STATE(1) */) = (data->modelData->realVarsData[2] /* valve_opening STATE(1) */).attribute .start;
  TRACE_POP
}
extern void TurbineOverspeedTripEnhanced_eqFunction_22(DATA *data, threadData_t *threadData);

extern void TurbineOverspeedTripEnhanced_eqFunction_24(DATA *data, threadData_t *threadData);


/*
equation index: 10
type: SIMPLE_ASSIGN
omega = $START.omega
*/
void TurbineOverspeedTripEnhanced_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* omega STATE(1) */) = (data->modelData->realVarsData[0] /* omega STATE(1) */).attribute .start;
  TRACE_POP
}
extern void TurbineOverspeedTripEnhanced_eqFunction_18(DATA *data, threadData_t *threadData);


/*
equation index: 12
type: SIMPLE_ASSIGN
$whenCondition2 = not overspeed and not $PRE.trip_latched
*/
void TurbineOverspeedTripEnhanced_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) = ((!(data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[2]] /* overspeed DISCRETE */)) && (!(data->simulationInfo->booleanVarsPre[3] /* trip_latched DISCRETE */)));
  TRACE_POP
}
extern void TurbineOverspeedTripEnhanced_eqFunction_19(DATA *data, threadData_t *threadData);

extern void TurbineOverspeedTripEnhanced_eqFunction_23(DATA *data, threadData_t *threadData);

extern void TurbineOverspeedTripEnhanced_eqFunction_26(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void TurbineOverspeedTripEnhanced_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  TurbineOverspeedTripEnhanced_eqFunction_25(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_2(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_3(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_21(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_5(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_6(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_7(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_22(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_24(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_10(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_18(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_12(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_19(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_23(data, threadData);
  TurbineOverspeedTripEnhanced_eqFunction_26(data, threadData);
  TRACE_POP
}

int TurbineOverspeedTripEnhanced_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  TurbineOverspeedTripEnhanced_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No TurbineOverspeedTripEnhanced_functionInitialEquations_lambda0 function */

int TurbineOverspeedTripEnhanced_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

