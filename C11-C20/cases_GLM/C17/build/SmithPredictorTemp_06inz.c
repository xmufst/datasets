/* Initialization */
#include "SmithPredictorTemp_model.h"
#include "SmithPredictorTemp_11mix.h"
#include "SmithPredictorTemp_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void SmithPredictorTemp_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void SmithPredictorTemp_eqFunction_13(DATA *data, threadData_t *threadData);


/*
equation index: 2
type: SIMPLE_ASSIGN
T_process = $START.T_process
*/
void SmithPredictorTemp_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* T_process STATE(1) */) = (data->modelData->realVarsData[1] /* T_process STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
T_measured = if noEvent(time > L) then T_process else T0
*/
void SmithPredictorTemp_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  modelica_boolean tmp0;
  tmp0 = Greater(data->localData[0]->timeValue,(data->simulationInfo->realParameter[2] /* L PARAM */));
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* T_measured variable */) = (tmp0?(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* T_process STATE(1) */):(data->simulationInfo->realParameter[3] /* T0 PARAM */));
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
T_model = $START.T_model
*/
void SmithPredictorTemp_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_model STATE(1) */) = (data->modelData->realVarsData[0] /* T_model STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
T_model_delayed = if noEvent(time > L) then T_model else T0
*/
void SmithPredictorTemp_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  modelica_boolean tmp1;
  tmp1 = Greater(data->localData[0]->timeValue,(data->simulationInfo->realParameter[2] /* L PARAM */));
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* T_model_delayed variable */) = (tmp1?(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_model STATE(1) */):(data->simulationInfo->realParameter[3] /* T0 PARAM */));
  TRACE_POP
}
extern void SmithPredictorTemp_eqFunction_16(DATA *data, threadData_t *threadData);

extern void SmithPredictorTemp_eqFunction_17(DATA *data, threadData_t *threadData);

extern void SmithPredictorTemp_eqFunction_21(DATA *data, threadData_t *threadData);


/*
equation index: 9
type: SIMPLE_ASSIGN
pi_ctrl.x = pi_ctrl.x_start
*/
void SmithPredictorTemp_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* pi_ctrl.x STATE(1) */) = (data->simulationInfo->realParameter[12] /* pi_ctrl.x_start PARAM */);
  TRACE_POP
}
extern void SmithPredictorTemp_eqFunction_18(DATA *data, threadData_t *threadData);

extern void SmithPredictorTemp_eqFunction_20(DATA *data, threadData_t *threadData);

extern void SmithPredictorTemp_eqFunction_19(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void SmithPredictorTemp_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SmithPredictorTemp_eqFunction_13(data, threadData);
  SmithPredictorTemp_eqFunction_2(data, threadData);
  SmithPredictorTemp_eqFunction_3(data, threadData);
  SmithPredictorTemp_eqFunction_4(data, threadData);
  SmithPredictorTemp_eqFunction_5(data, threadData);
  SmithPredictorTemp_eqFunction_16(data, threadData);
  SmithPredictorTemp_eqFunction_17(data, threadData);
  SmithPredictorTemp_eqFunction_21(data, threadData);
  SmithPredictorTemp_eqFunction_9(data, threadData);
  SmithPredictorTemp_eqFunction_18(data, threadData);
  SmithPredictorTemp_eqFunction_20(data, threadData);
  SmithPredictorTemp_eqFunction_19(data, threadData);
  TRACE_POP
}

int SmithPredictorTemp_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  SmithPredictorTemp_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No SmithPredictorTemp_functionInitialEquations_lambda0 function */

int SmithPredictorTemp_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

