/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "ThermostatWaterTank_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void ThermostatWaterTank_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *ThermostatWaterTank_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"not pre(hysteresis.y) and T_error > hysteresis.uHigh or pre(hysteresis.y) and T_error >= hysteresis.uLow"};
  static const int occurEqs0[] = {1,10};
  static const int *occurEqs[] = {occurEqs0};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void ThermostatWaterTank_eqFunction_9(DATA* data, threadData_t *threadData);
extern void ThermostatWaterTank_eqFunction_10(DATA* data, threadData_t *threadData);
extern void ThermostatWaterTank_eqFunction_11(DATA* data, threadData_t *threadData);
extern void ThermostatWaterTank_eqFunction_12(DATA* data, threadData_t *threadData);
extern void ThermostatWaterTank_eqFunction_13(DATA* data, threadData_t *threadData);

int ThermostatWaterTank_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  ThermostatWaterTank_eqFunction_9(data, threadData);

  ThermostatWaterTank_eqFunction_10(data, threadData);

  ThermostatWaterTank_eqFunction_11(data, threadData);

  ThermostatWaterTank_eqFunction_12(data, threadData);

  ThermostatWaterTank_eqFunction_13(data, threadData);
  
  TRACE_POP
  return 0;
}

int ThermostatWaterTank_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  start_index = current_index;
  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[11] /* hysteresis.uHigh PARAM */));
  tmp0 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_error variable */), (data->simulationInfo->realParameter[11] /* hysteresis.uHigh PARAM */), tmp1, tmp2, data->simulationInfo->storedRelations[0]);
  tmp4 = 1.0;
  tmp5 = fabs((data->simulationInfo->realParameter[12] /* hysteresis.uLow PARAM */));
  tmp3 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_error variable */), (data->simulationInfo->realParameter[12] /* hysteresis.uLow PARAM */), tmp4, tmp5, data->simulationInfo->storedRelations[1]);
  gout[start_index] = ((((!(data->simulationInfo->booleanVarsPre[0] /* hysteresis.y DISCRETE */)) && tmp0) || ((data->simulationInfo->booleanVarsPre[0] /* hysteresis.y DISCRETE */) && tmp3))) ? 1 : -1;
  current_index++;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *ThermostatWaterTank_relationDescription(int i)
{
  const char *res[] = {"T_error > hysteresis.uHigh",
  "T_error >= hysteresis.uLow"};
  return res[i];
}

int ThermostatWaterTank_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
  if(evalforZeroCross) {
    start_index = current_index;
    tmp7 = 1.0;
    tmp8 = fabs((data->simulationInfo->realParameter[11] /* hysteresis.uHigh PARAM */));
    tmp6 = GreaterZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_error variable */), (data->simulationInfo->realParameter[11] /* hysteresis.uHigh PARAM */), tmp7, tmp8, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[start_index] = tmp6;
    current_index++;

    start_index = current_index;
    tmp10 = 1.0;
    tmp11 = fabs((data->simulationInfo->realParameter[12] /* hysteresis.uLow PARAM */));
    tmp9 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_error variable */), (data->simulationInfo->realParameter[12] /* hysteresis.uLow PARAM */), tmp10, tmp11, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[start_index] = tmp9;
    current_index++;
  } else {
    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_error variable */) > (data->simulationInfo->realParameter[11] /* hysteresis.uHigh PARAM */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_error variable */) >= (data->simulationInfo->realParameter[12] /* hysteresis.uLow PARAM */));
    current_index++;
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

