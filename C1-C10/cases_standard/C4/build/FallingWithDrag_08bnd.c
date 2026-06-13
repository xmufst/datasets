/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "FallingWithDrag_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 22
type: SIMPLE_ASSIGN
$START.v = v0
*/
static void FallingWithDrag_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->modelData->realVarsData[0] /* v STATE(1,a) */).attribute .start = (data->simulationInfo->realParameter[3] /* v0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */) = (data->modelData->realVarsData[0] /* v STATE(1,a) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* v */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v STATE(1,a) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int FallingWithDrag_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  FallingWithDrag_eqFunction_22(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void FallingWithDrag_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 23
type: SIMPLE_ASSIGN
v_terminal = sqrt(m * g / b)
*/
OMC_DISABLE_OPT
static void FallingWithDrag_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
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
  (data->simulationInfo->realParameter[4] /* v_terminal PARAM */) = sqrt(tmp0);
  TRACE_POP
}
extern void FallingWithDrag_eqFunction_1(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void FallingWithDrag_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  FallingWithDrag_eqFunction_23(data, threadData);
  FallingWithDrag_eqFunction_1(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int FallingWithDrag_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  FallingWithDrag_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

