/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "ForcedDampedOscillator_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 26
type: SIMPLE_ASSIGN
$START.v = v0
*/
static void ForcedDampedOscillator_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->modelData->realVarsData[0] /* v STATE(1,a) */).attribute .start = (data->simulationInfo->realParameter[7] /* v0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */) = (data->modelData->realVarsData[0] /* v STATE(1,a) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* v */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */));
  TRACE_POP
}

/*
equation index: 27
type: SIMPLE_ASSIGN
$START.x = x0
*/
static void ForcedDampedOscillator_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  (data->modelData->realVarsData[1] /* x STATE(1,v) */).attribute .start = (data->simulationInfo->realParameter[8] /* x0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */) = (data->modelData->realVarsData[1] /* x STATE(1,v) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* x */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* x STATE(1,v) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int ForcedDampedOscillator_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  ForcedDampedOscillator_eqFunction_26(data, threadData);

  ForcedDampedOscillator_eqFunction_27(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void ForcedDampedOscillator_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 28
type: SIMPLE_ASSIGN
X_static = F0 / k
*/
OMC_DISABLE_OPT
static void ForcedDampedOscillator_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  (data->simulationInfo->realParameter[1] /* X_static PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[0] /* F0 PARAM */),(data->simulationInfo->realParameter[3] /* k PARAM */),"k",equationIndexes);
  TRACE_POP
}

/*
equation index: 29
type: SIMPLE_ASSIGN
zeta = 0.5 * c / sqrt(k * m)
*/
OMC_DISABLE_OPT
static void ForcedDampedOscillator_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  modelica_real tmp0;
  tmp0 = ((data->simulationInfo->realParameter[3] /* k PARAM */)) * ((data->simulationInfo->realParameter[4] /* m PARAM */));
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
  (data->simulationInfo->realParameter[9] /* zeta PARAM */) = (0.5) * (DIVISION_SIM((data->simulationInfo->realParameter[2] /* c PARAM */),sqrt(tmp0),"sqrt(k * m)",equationIndexes));
  TRACE_POP
}

/*
equation index: 30
type: SIMPLE_ASSIGN
omega_n = sqrt(k / m)
*/
OMC_DISABLE_OPT
static void ForcedDampedOscillator_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  modelica_real tmp1;
  tmp1 = DIVISION_SIM((data->simulationInfo->realParameter[3] /* k PARAM */),(data->simulationInfo->realParameter[4] /* m PARAM */),"m",equationIndexes);
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
  (data->simulationInfo->realParameter[6] /* omega_n PARAM */) = sqrt(tmp1);
  TRACE_POP
}
OMC_DISABLE_OPT
void ForcedDampedOscillator_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  ForcedDampedOscillator_eqFunction_28(data, threadData);
  ForcedDampedOscillator_eqFunction_29(data, threadData);
  ForcedDampedOscillator_eqFunction_30(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int ForcedDampedOscillator_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  ForcedDampedOscillator_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

