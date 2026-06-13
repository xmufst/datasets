/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "DualSpringMass_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 25
type: SIMPLE_ASSIGN
$START.v2 = v2_0
*/
static void DualSpringMass_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->modelData->realVarsData[1] /* v2 STATE(1) */).attribute .start = (data->simulationInfo->realParameter[5] /* v2_0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v2 STATE(1) */) = (data->modelData->realVarsData[1] /* v2 STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* v2 */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* v2 STATE(1) */));
  TRACE_POP
}

/*
equation index: 26
type: SIMPLE_ASSIGN
$START.x2 = x2_0
*/
static void DualSpringMass_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->modelData->realVarsData[3] /* x2 STATE(1,v2) */).attribute .start = (data->simulationInfo->realParameter[7] /* x2_0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* x2 STATE(1,v2) */) = (data->modelData->realVarsData[3] /* x2 STATE(1,v2) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[3].info /* x2 */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* x2 STATE(1,v2) */));
  TRACE_POP
}

/*
equation index: 27
type: SIMPLE_ASSIGN
$START.v1 = v1_0
*/
static void DualSpringMass_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  (data->modelData->realVarsData[0] /* v1 STATE(1) */).attribute .start = (data->simulationInfo->realParameter[4] /* v1_0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v1 STATE(1) */) = (data->modelData->realVarsData[0] /* v1 STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* v1 */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* v1 STATE(1) */));
  TRACE_POP
}

/*
equation index: 28
type: SIMPLE_ASSIGN
$START.x1 = x1_0
*/
static void DualSpringMass_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  (data->modelData->realVarsData[2] /* x1 STATE(1,v1) */).attribute .start = (data->simulationInfo->realParameter[6] /* x1_0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* x1 STATE(1,v1) */) = (data->modelData->realVarsData[2] /* x1 STATE(1,v1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[2].info /* x1 */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* x1 STATE(1,v1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int DualSpringMass_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  DualSpringMass_eqFunction_25(data, threadData);

  DualSpringMass_eqFunction_26(data, threadData);

  DualSpringMass_eqFunction_27(data, threadData);

  DualSpringMass_eqFunction_28(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int DualSpringMass_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

