/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "SpringMassDamper_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 19
type: SIMPLE_ASSIGN
$START.v = v0
*/
static void SpringMassDamper_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->modelData->realVarsData[0] /* v STATE(1,a) */).attribute .start = (data->simulationInfo->realParameter[4] /* v0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */) = (data->modelData->realVarsData[0] /* v STATE(1,a) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* v */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */));
  TRACE_POP
}

/*
equation index: 20
type: SIMPLE_ASSIGN
$START.x = x0
*/
static void SpringMassDamper_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->modelData->realVarsData[1] /* x STATE(1,v) */).attribute .start = (data->simulationInfo->realParameter[5] /* x0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */) = (data->modelData->realVarsData[1] /* x STATE(1,v) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* x */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int SpringMassDamper_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating min-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* max ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating max-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* nominal **************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating nominal-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating primary start-values");
  SpringMassDamper_eqFunction_19(data, threadData);

  SpringMassDamper_eqFunction_20(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void SpringMassDamper_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 21
type: SIMPLE_ASSIGN
zeta = 0.5 * c / sqrt(k * m)
*/
OMC_DISABLE_OPT
static void SpringMassDamper_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  modelica_real tmp0;
  tmp0 = ((data->simulationInfo->realParameter[1] /* k PARAM */)) * ((data->simulationInfo->realParameter[2] /* m PARAM */));
  if(!(tmp0 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(k * m) was %g should be >= 0", tmp0);
    }
  }
  (data->simulationInfo->realParameter[6] /* zeta PARAM */) = (0.5) * (DIVISION_SIM((data->simulationInfo->realParameter[0] /* c PARAM */),sqrt(tmp0),"sqrt(k * m)",equationIndexes));
  TRACE_POP
}

/*
equation index: 22
type: SIMPLE_ASSIGN
omega_n = sqrt(k / m)
*/
OMC_DISABLE_OPT
static void SpringMassDamper_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  modelica_real tmp1;
  tmp1 = DIVISION_SIM((data->simulationInfo->realParameter[1] /* k PARAM */),(data->simulationInfo->realParameter[2] /* m PARAM */),"m",equationIndexes);
  if(!(tmp1 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(k / m) was %g should be >= 0", tmp1);
    }
  }
  (data->simulationInfo->realParameter[3] /* omega_n PARAM */) = sqrt(tmp1);
  TRACE_POP
}
OMC_DISABLE_OPT
void SpringMassDamper_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SpringMassDamper_eqFunction_21(data, threadData);
  SpringMassDamper_eqFunction_22(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int SpringMassDamper_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SpringMassDamper_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

