/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "ThermostatWaterTank_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 17
type: SIMPLE_ASSIGN
$START.T = T0
*/
static void ThermostatWaterTank_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->modelData->realVarsData[0] /* T STATE(1) */).attribute .start = (data->simulationInfo->realParameter[2] /* T0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */) = (data->modelData->realVarsData[0] /* T STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* T */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int ThermostatWaterTank_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  ThermostatWaterTank_eqFunction_17(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void ThermostatWaterTank_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 18
type: SIMPLE_ASSIGN
setpoint.k = T_set
*/
OMC_DISABLE_OPT
static void ThermostatWaterTank_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->simulationInfo->realParameter[10] /* setpoint.k PARAM */) = (data->simulationInfo->realParameter[4] /* T_set PARAM */);
  TRACE_POP
}

/*
equation index: 19
type: SIMPLE_ASSIGN
feedback.u1 = setpoint.k
*/
OMC_DISABLE_OPT
static void ThermostatWaterTank_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->simulationInfo->realParameter[9] /* feedback.u1 PARAM */) = (data->simulationInfo->realParameter[10] /* setpoint.k PARAM */);
  TRACE_POP
}

/*
equation index: 20
type: SIMPLE_ASSIGN
setpoint.y = setpoint.k
*/
OMC_DISABLE_OPT
static void ThermostatWaterTank_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->simulationInfo->realParameter[11] /* setpoint.y PARAM */) = (data->simulationInfo->realParameter[10] /* setpoint.k PARAM */);
  TRACE_POP
}

/*
equation index: 21
type: SIMPLE_ASSIGN
controller.uHigh = 0.5 * deadband
*/
OMC_DISABLE_OPT
static void ThermostatWaterTank_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->simulationInfo->realParameter[6] /* controller.uHigh PARAM */) = (0.5) * ((data->simulationInfo->realParameter[8] /* deadband PARAM */));
  TRACE_POP
}

/*
equation index: 22
type: SIMPLE_ASSIGN
controller.uLow = (-0.5) * deadband
*/
OMC_DISABLE_OPT
static void ThermostatWaterTank_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->simulationInfo->realParameter[7] /* controller.uLow PARAM */) = (-0.5) * ((data->simulationInfo->realParameter[8] /* deadband PARAM */));
  TRACE_POP
}
OMC_DISABLE_OPT
void ThermostatWaterTank_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  ThermostatWaterTank_eqFunction_18(data, threadData);
  ThermostatWaterTank_eqFunction_19(data, threadData);
  ThermostatWaterTank_eqFunction_20(data, threadData);
  ThermostatWaterTank_eqFunction_21(data, threadData);
  ThermostatWaterTank_eqFunction_22(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int ThermostatWaterTank_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  ThermostatWaterTank_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

