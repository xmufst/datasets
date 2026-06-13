/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "ThermostatWaterTank_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

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
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void ThermostatWaterTank_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 15
type: SIMPLE_ASSIGN
T_set_const.k = T_set
*/
OMC_DISABLE_OPT
static void ThermostatWaterTank_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  (data->simulationInfo->realParameter[4] /* T_set_const.k PARAM */) = (data->simulationInfo->realParameter[3] /* T_set PARAM */);
  TRACE_POP
}

/*
equation index: 16
type: SIMPLE_ASSIGN
feedback.u1 = T_set_const.k
*/
OMC_DISABLE_OPT
static void ThermostatWaterTank_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->simulationInfo->realParameter[10] /* feedback.u1 PARAM */) = (data->simulationInfo->realParameter[4] /* T_set_const.k PARAM */);
  TRACE_POP
}

/*
equation index: 17
type: SIMPLE_ASSIGN
T_set_const.y = T_set_const.k
*/
OMC_DISABLE_OPT
static void ThermostatWaterTank_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->simulationInfo->realParameter[5] /* T_set_const.y PARAM */) = (data->simulationInfo->realParameter[4] /* T_set_const.k PARAM */);
  TRACE_POP
}

/*
equation index: 18
type: SIMPLE_ASSIGN
booleanToReal.realTrue = Q_heater
*/
OMC_DISABLE_OPT
static void ThermostatWaterTank_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->simulationInfo->realParameter[8] /* booleanToReal.realTrue PARAM */) = (data->simulationInfo->realParameter[1] /* Q_heater PARAM */);
  TRACE_POP
}

/*
equation index: 19
type: SIMPLE_ASSIGN
hysteresis.uHigh = 0.5 * deadband
*/
OMC_DISABLE_OPT
static void ThermostatWaterTank_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->simulationInfo->realParameter[11] /* hysteresis.uHigh PARAM */) = (0.5) * ((data->simulationInfo->realParameter[9] /* deadband PARAM */));
  TRACE_POP
}

/*
equation index: 20
type: SIMPLE_ASSIGN
hysteresis.uLow = (-0.5) * deadband
*/
OMC_DISABLE_OPT
static void ThermostatWaterTank_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->simulationInfo->realParameter[12] /* hysteresis.uLow PARAM */) = (-0.5) * ((data->simulationInfo->realParameter[9] /* deadband PARAM */));
  TRACE_POP
}
OMC_DISABLE_OPT
void ThermostatWaterTank_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  ThermostatWaterTank_eqFunction_15(data, threadData);
  ThermostatWaterTank_eqFunction_16(data, threadData);
  ThermostatWaterTank_eqFunction_17(data, threadData);
  ThermostatWaterTank_eqFunction_18(data, threadData);
  ThermostatWaterTank_eqFunction_19(data, threadData);
  ThermostatWaterTank_eqFunction_20(data, threadData);
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

