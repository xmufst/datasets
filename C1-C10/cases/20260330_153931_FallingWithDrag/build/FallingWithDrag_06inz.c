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
E_dissipated = $START.E_dissipated
*/
void FallingWithDrag_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* E_dissipated STATE(1) */) = (data->modelData->realVarsData[0] /* E_dissipated STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
F_gravity = m * g
*/
void FallingWithDrag_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* F_gravity variable */) = ((data->simulationInfo->realParameter[2] /* m PARAM */)) * ((data->simulationInfo->realParameter[1] /* g PARAM */));
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
v_terminal = sqrt(m * g / b)
*/
void FallingWithDrag_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  modelica_real tmp0;
  tmp0 = DIVISION_SIM(((data->simulationInfo->realParameter[2] /* m PARAM */)) * ((data->simulationInfo->realParameter[1] /* g PARAM */)),(data->simulationInfo->realParameter[0] /* b PARAM */),"b",equationIndexes);
  if(!(tmp0 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(m * g / b) was %g should be >= 0", tmp0);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* v_terminal variable */) = sqrt(tmp0);
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
v = v0
*/
void FallingWithDrag_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1,a) */) = (data->simulationInfo->realParameter[3] /* v0 PARAM */);
  TRACE_POP
}
extern void FallingWithDrag_eqFunction_16(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_17(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_18(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_22(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_19(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_20(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_21(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_23(DATA *data, threadData_t *threadData);


/*
equation index: 13
type: SIMPLE_ASSIGN
y = 0.0
*/
void FallingWithDrag_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* y STATE(1,v) */) = 0.0;
  TRACE_POP
}
extern void FallingWithDrag_eqFunction_15(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void FallingWithDrag_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  FallingWithDrag_eqFunction_1(data, threadData);
  FallingWithDrag_eqFunction_2(data, threadData);
  FallingWithDrag_eqFunction_3(data, threadData);
  FallingWithDrag_eqFunction_4(data, threadData);
  FallingWithDrag_eqFunction_16(data, threadData);
  FallingWithDrag_eqFunction_17(data, threadData);
  FallingWithDrag_eqFunction_18(data, threadData);
  FallingWithDrag_eqFunction_22(data, threadData);
  FallingWithDrag_eqFunction_19(data, threadData);
  FallingWithDrag_eqFunction_20(data, threadData);
  FallingWithDrag_eqFunction_21(data, threadData);
  FallingWithDrag_eqFunction_23(data, threadData);
  FallingWithDrag_eqFunction_13(data, threadData);
  FallingWithDrag_eqFunction_15(data, threadData);
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

