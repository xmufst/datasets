/* Initialization */
#include "SpringMassDamper_model.h"
#include "SpringMassDamper_11mix.h"
#include "SpringMassDamper_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void SpringMassDamper_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
omega_n = sqrt(k / m)
*/
void SpringMassDamper_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  modelica_real tmp0;
  tmp0 = DIVISION_SIM((data->simulationInfo->realParameter[1] /* k PARAM */),(data->simulationInfo->realParameter[2] /* m PARAM */),"m",equationIndexes);
  if(!(tmp0 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(k / m) was %g should be >= 0", tmp0);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* omega_n variable */) = sqrt(tmp0);
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
zeta = 0.5 * c / sqrt(k * m)
*/
void SpringMassDamper_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  modelica_real tmp1;
  tmp1 = ((data->simulationInfo->realParameter[1] /* k PARAM */)) * ((data->simulationInfo->realParameter[2] /* m PARAM */));
  if(!(tmp1 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(k * m) was %g should be >= 0", tmp1);
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* zeta variable */) = (0.5) * (DIVISION_SIM((data->simulationInfo->realParameter[0] /* c PARAM */),sqrt(tmp1),"sqrt(k * m)",equationIndexes));
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
x = $START.x
*/
void SpringMassDamper_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */) = (data->modelData->realVarsData[1] /* x STATE(1,v) */).attribute .start;
  TRACE_POP
}
extern void SpringMassDamper_eqFunction_13(DATA *data, threadData_t *threadData);

extern void SpringMassDamper_eqFunction_18(DATA *data, threadData_t *threadData);


/*
equation index: 6
type: SIMPLE_ASSIGN
v = $START.v
*/
void SpringMassDamper_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */) = (data->modelData->realVarsData[0] /* v STATE(1,a) */).attribute .start;
  TRACE_POP
}
extern void SpringMassDamper_eqFunction_14(DATA *data, threadData_t *threadData);

extern void SpringMassDamper_eqFunction_15(DATA *data, threadData_t *threadData);

extern void SpringMassDamper_eqFunction_16(DATA *data, threadData_t *threadData);

extern void SpringMassDamper_eqFunction_17(DATA *data, threadData_t *threadData);

extern void SpringMassDamper_eqFunction_19(DATA *data, threadData_t *threadData);

extern void SpringMassDamper_eqFunction_20(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void SpringMassDamper_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SpringMassDamper_eqFunction_1(data, threadData);
  SpringMassDamper_eqFunction_2(data, threadData);
  SpringMassDamper_eqFunction_3(data, threadData);
  SpringMassDamper_eqFunction_13(data, threadData);
  SpringMassDamper_eqFunction_18(data, threadData);
  SpringMassDamper_eqFunction_6(data, threadData);
  SpringMassDamper_eqFunction_14(data, threadData);
  SpringMassDamper_eqFunction_15(data, threadData);
  SpringMassDamper_eqFunction_16(data, threadData);
  SpringMassDamper_eqFunction_17(data, threadData);
  SpringMassDamper_eqFunction_19(data, threadData);
  SpringMassDamper_eqFunction_20(data, threadData);
  TRACE_POP
}

int SpringMassDamper_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  SpringMassDamper_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No SpringMassDamper_functionInitialEquations_lambda0 function */

int SpringMassDamper_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

