/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "TurbineOverspeedTripEnhanced_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void TurbineOverspeedTripEnhanced_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *TurbineOverspeedTripEnhanced_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"time >= t_short_start and time < t_short_start + t_short_dur or time >= t_long_start and time < t_long_start + t_long_dur",
  "omega >= omega_trip",
  "trip_timer >= trip_delay and not pre(trip_latched)"};
  static const int occurEqs0[] = {1,25};
  static const int occurEqs1[] = {1,18};
  static const int occurEqs2[] = {1,16};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void TurbineOverspeedTripEnhanced_eqFunction_16(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_18(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_19(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_21(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_22(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_23(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_24(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_25(DATA* data, threadData_t *threadData);
extern void TurbineOverspeedTripEnhanced_eqFunction_26(DATA* data, threadData_t *threadData);

int TurbineOverspeedTripEnhanced_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  TurbineOverspeedTripEnhanced_eqFunction_16(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_18(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_19(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_21(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_22(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_23(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_24(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_25(data, threadData);

  TurbineOverspeedTripEnhanced_eqFunction_26(data, threadData);
  
  TRACE_POP
  return 0;
}

int TurbineOverspeedTripEnhanced_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_boolean tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_boolean tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  start_index = current_index;
  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[8] /* t_short_start PARAM */));
  tmp0 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[8] /* t_short_start PARAM */), tmp1, tmp2, data->simulationInfo->storedRelations[0]);
  tmp4 = 1.0;
  tmp5 = fabs((data->simulationInfo->realParameter[8] /* t_short_start PARAM */)) + fabs((data->simulationInfo->realParameter[7] /* t_short_dur PARAM */));
  tmp3 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[8] /* t_short_start PARAM */) + (data->simulationInfo->realParameter[7] /* t_short_dur PARAM */), tmp4, tmp5, data->simulationInfo->storedRelations[1]);
  tmp7 = 1.0;
  tmp8 = fabs((data->simulationInfo->realParameter[6] /* t_long_start PARAM */));
  tmp6 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[6] /* t_long_start PARAM */), tmp7, tmp8, data->simulationInfo->storedRelations[2]);
  tmp10 = 1.0;
  tmp11 = fabs((data->simulationInfo->realParameter[6] /* t_long_start PARAM */)) + fabs((data->simulationInfo->realParameter[5] /* t_long_dur PARAM */));
  tmp9 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[6] /* t_long_start PARAM */) + (data->simulationInfo->realParameter[5] /* t_long_dur PARAM */), tmp10, tmp11, data->simulationInfo->storedRelations[3]);
  gout[start_index] = (((tmp0 && tmp3) || (tmp6 && tmp9))) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp13 = 1.0;
  tmp14 = fabs((data->simulationInfo->realParameter[4] /* omega_trip PARAM */));
  tmp12 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* omega STATE(1) */), (data->simulationInfo->realParameter[4] /* omega_trip PARAM */), tmp13, tmp14, data->simulationInfo->storedRelations[4]);
  gout[start_index] = (tmp12) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp16 = 1.0;
  tmp17 = fabs((data->simulationInfo->realParameter[10] /* trip_delay PARAM */));
  tmp15 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* trip_timer STATE(1) */), (data->simulationInfo->realParameter[10] /* trip_delay PARAM */), tmp16, tmp17, data->simulationInfo->storedRelations[5]);
  gout[start_index] = ((tmp15 && (!(data->simulationInfo->booleanVarsPre[3] /* trip_latched DISCRETE */)))) ? 1 : -1;
  current_index++;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *TurbineOverspeedTripEnhanced_relationDescription(int i)
{
  const char *res[] = {"time >= t_short_start",
  "time < t_short_start + t_short_dur",
  "time >= t_long_start",
  "time < t_long_start + t_long_dur",
  "omega >= omega_trip",
  "trip_timer >= trip_delay"};
  return res[i];
}

int TurbineOverspeedTripEnhanced_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_boolean tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  modelica_boolean tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_boolean tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  modelica_boolean tmp33;
  modelica_real tmp34;
  modelica_real tmp35;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
  if(evalforZeroCross) {
    start_index = current_index;
    tmp19 = 1.0;
    tmp20 = fabs((data->simulationInfo->realParameter[8] /* t_short_start PARAM */));
    tmp18 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[8] /* t_short_start PARAM */), tmp19, tmp20, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[start_index] = tmp18;
    current_index++;

    start_index = current_index;
    tmp22 = 1.0;
    tmp23 = fabs((data->simulationInfo->realParameter[8] /* t_short_start PARAM */)) + fabs((data->simulationInfo->realParameter[7] /* t_short_dur PARAM */));
    tmp21 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[8] /* t_short_start PARAM */) + (data->simulationInfo->realParameter[7] /* t_short_dur PARAM */), tmp22, tmp23, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[start_index] = tmp21;
    current_index++;

    start_index = current_index;
    tmp25 = 1.0;
    tmp26 = fabs((data->simulationInfo->realParameter[6] /* t_long_start PARAM */));
    tmp24 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[6] /* t_long_start PARAM */), tmp25, tmp26, data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[start_index] = tmp24;
    current_index++;

    start_index = current_index;
    tmp28 = 1.0;
    tmp29 = fabs((data->simulationInfo->realParameter[6] /* t_long_start PARAM */)) + fabs((data->simulationInfo->realParameter[5] /* t_long_dur PARAM */));
    tmp27 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[6] /* t_long_start PARAM */) + (data->simulationInfo->realParameter[5] /* t_long_dur PARAM */), tmp28, tmp29, data->simulationInfo->storedRelations[3]);
    data->simulationInfo->relations[start_index] = tmp27;
    current_index++;

    start_index = current_index;
    tmp31 = 1.0;
    tmp32 = fabs((data->simulationInfo->realParameter[4] /* omega_trip PARAM */));
    tmp30 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* omega STATE(1) */), (data->simulationInfo->realParameter[4] /* omega_trip PARAM */), tmp31, tmp32, data->simulationInfo->storedRelations[4]);
    data->simulationInfo->relations[start_index] = tmp30;
    current_index++;

    start_index = current_index;
    tmp34 = 1.0;
    tmp35 = fabs((data->simulationInfo->realParameter[10] /* trip_delay PARAM */));
    tmp33 = GreaterEqZC((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* trip_timer STATE(1) */), (data->simulationInfo->realParameter[10] /* trip_delay PARAM */), tmp34, tmp35, data->simulationInfo->storedRelations[5]);
    data->simulationInfo->relations[start_index] = tmp33;
    current_index++;
  } else {
    start_index = current_index;
    data->simulationInfo->relations[start_index] = (data->localData[0]->timeValue >= (data->simulationInfo->realParameter[8] /* t_short_start PARAM */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = (data->localData[0]->timeValue < (data->simulationInfo->realParameter[8] /* t_short_start PARAM */) + (data->simulationInfo->realParameter[7] /* t_short_dur PARAM */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = (data->localData[0]->timeValue >= (data->simulationInfo->realParameter[6] /* t_long_start PARAM */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = (data->localData[0]->timeValue < (data->simulationInfo->realParameter[6] /* t_long_start PARAM */) + (data->simulationInfo->realParameter[5] /* t_long_dur PARAM */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* omega STATE(1) */) >= (data->simulationInfo->realParameter[4] /* omega_trip PARAM */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* trip_timer STATE(1) */) >= (data->simulationInfo->realParameter[10] /* trip_delay PARAM */));
    current_index++;
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

