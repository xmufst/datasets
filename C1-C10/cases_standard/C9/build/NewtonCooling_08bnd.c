/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "NewtonCooling_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 13
type: SIMPLE_ASSIGN
$START.T = T0
*/
static void NewtonCooling_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->modelData->realVarsData[1] /* T STATE(1) */).attribute .start = (data->simulationInfo->realParameter[0] /* T0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* T STATE(1) */) = (data->modelData->realVarsData[1] /* T STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* T */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* T STATE(1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int NewtonCooling_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  NewtonCooling_eqFunction_13(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void NewtonCooling_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 14
type: SIMPLE_ASSIGN
tau = m * cp / hA
*/
OMC_DISABLE_OPT
static void NewtonCooling_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  (data->simulationInfo->realParameter[5] /* tau PARAM */) = ((data->simulationInfo->realParameter[4] /* m PARAM */)) * (DIVISION_SIM((data->simulationInfo->realParameter[2] /* cp PARAM */),(data->simulationInfo->realParameter[3] /* hA PARAM */),"hA",equationIndexes));
  TRACE_POP
}
OMC_DISABLE_OPT
void NewtonCooling_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  NewtonCooling_eqFunction_14(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int NewtonCooling_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  NewtonCooling_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

