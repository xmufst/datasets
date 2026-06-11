/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "FallingWithDrag_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 25
type: SIMPLE_ASSIGN
$START.v = v0
*/
static void FallingWithDrag_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->modelData->realVarsData[1] /* v STATE(1,a) */).attribute .start = (data->simulationInfo->realParameter[3] /* v0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1,a) */) = (data->modelData->realVarsData[1] /* v STATE(1,a) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* v */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v STATE(1,a) */));
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
  FallingWithDrag_eqFunction_25(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void FallingWithDrag_updateBoundParameters_0(DATA *data, threadData_t *threadData);
extern void FallingWithDrag_eqFunction_3(DATA *data, threadData_t *threadData);

extern void FallingWithDrag_eqFunction_2(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void FallingWithDrag_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  FallingWithDrag_eqFunction_3(data, threadData);
  FallingWithDrag_eqFunction_2(data, threadData);
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

