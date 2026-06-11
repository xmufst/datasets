/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "FeedforwardFeedbackTemp_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 21
type: SIMPLE_ASSIGN
$START.T = T0
*/
static void FeedforwardFeedbackTemp_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->modelData->realVarsData[0] /* T STATE(1) */).attribute .start = (data->simulationInfo->realParameter[5] /* T0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */) = (data->modelData->realVarsData[0] /* T STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* T */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */));
  TRACE_POP
}

/*
equation index: 22
type: SIMPLE_ASSIGN
$START.piCorrection.x = piCorrection.x_start
*/
static void FeedforwardFeedbackTemp_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->modelData->realVarsData[1] /* piCorrection.x STATE(1) */).attribute .start = (data->simulationInfo->realParameter[23] /* piCorrection.x_start PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piCorrection.x STATE(1) */) = (data->modelData->realVarsData[1] /* piCorrection.x STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* piCorrection.x */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piCorrection.x STATE(1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int FeedforwardFeedbackTemp_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  FeedforwardFeedbackTemp_eqFunction_21(data, threadData);

  FeedforwardFeedbackTemp_eqFunction_22(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void FeedforwardFeedbackTemp_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 23
type: SIMPLE_ASSIGN
baselineHeat.k = Q_ss
*/
OMC_DISABLE_OPT
static void FeedforwardFeedbackTemp_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->simulationInfo->realParameter[10] /* baselineHeat.k PARAM */) = (data->simulationInfo->realParameter[4] /* Q_ss PARAM */);
  TRACE_POP
}

/*
equation index: 24
type: SIMPLE_ASSIGN
heaterSum.u1 = baselineHeat.k
*/
OMC_DISABLE_OPT
static void FeedforwardFeedbackTemp_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->simulationInfo->realParameter[20] /* heaterSum.u1 PARAM */) = (data->simulationInfo->realParameter[10] /* baselineHeat.k PARAM */);
  TRACE_POP
}

/*
equation index: 25
type: SIMPLE_ASSIGN
baselineHeat.y = baselineHeat.k
*/
OMC_DISABLE_OPT
static void FeedforwardFeedbackTemp_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->simulationInfo->realParameter[11] /* baselineHeat.y PARAM */) = (data->simulationInfo->realParameter[10] /* baselineHeat.k PARAM */);
  TRACE_POP
}

/*
equation index: 26
type: SIMPLE_ASSIGN
refSignal.k = T_ref
*/
OMC_DISABLE_OPT
static void FeedforwardFeedbackTemp_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->simulationInfo->realParameter[25] /* refSignal.k PARAM */) = (data->simulationInfo->realParameter[7] /* T_ref PARAM */);
  TRACE_POP
}

/*
equation index: 27
type: SIMPLE_ASSIGN
errorCalc.u1 = refSignal.k
*/
OMC_DISABLE_OPT
static void FeedforwardFeedbackTemp_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  (data->simulationInfo->realParameter[15] /* errorCalc.u1 PARAM */) = (data->simulationInfo->realParameter[25] /* refSignal.k PARAM */);
  TRACE_POP
}

/*
equation index: 28
type: SIMPLE_ASSIGN
refSignal.y = refSignal.k
*/
OMC_DISABLE_OPT
static void FeedforwardFeedbackTemp_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  (data->simulationInfo->realParameter[26] /* refSignal.y PARAM */) = (data->simulationInfo->realParameter[25] /* refSignal.k PARAM */);
  TRACE_POP
}

/*
equation index: 29
type: SIMPLE_ASSIGN
feedforwardGain.k = K_ff
*/
OMC_DISABLE_OPT
static void FeedforwardFeedbackTemp_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  (data->simulationInfo->realParameter[16] /* feedforwardGain.k PARAM */) = (data->simulationInfo->realParameter[1] /* K_ff PARAM */);
  TRACE_POP
}

/*
equation index: 30
type: SIMPLE_ASSIGN
disturbanceSignal.startTime = t_dist
*/
OMC_DISABLE_OPT
static void FeedforwardFeedbackTemp_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  (data->simulationInfo->realParameter[14] /* disturbanceSignal.startTime PARAM */) = (data->simulationInfo->realParameter[27] /* t_dist PARAM */);
  TRACE_POP
}

/*
equation index: 31
type: SIMPLE_ASSIGN
disturbanceSignal.height = Q_dist
*/
OMC_DISABLE_OPT
static void FeedforwardFeedbackTemp_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  (data->simulationInfo->realParameter[12] /* disturbanceSignal.height PARAM */) = (data->simulationInfo->realParameter[3] /* Q_dist PARAM */);
  TRACE_POP
}

/*
equation index: 33
type: SIMPLE_ASSIGN
piCorrection.T = Ti
*/
OMC_DISABLE_OPT
static void FeedforwardFeedbackTemp_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  (data->simulationInfo->realParameter[21] /* piCorrection.T PARAM */) = (data->simulationInfo->realParameter[8] /* Ti PARAM */);
  TRACE_POP
}

/*
equation index: 34
type: SIMPLE_ASSIGN
piCorrection.k = Kp
*/
OMC_DISABLE_OPT
static void FeedforwardFeedbackTemp_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  (data->simulationInfo->realParameter[22] /* piCorrection.k PARAM */) = (data->simulationInfo->realParameter[2] /* Kp PARAM */);
  TRACE_POP
}

/*
equation index: 35
type: ALGORITHM

  assert(piCorrection.initType >= Modelica.Blocks.Types.Init.NoInit and piCorrection.initType <= Modelica.Blocks.Types.Init.InitialOutput, "Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= piCorrection.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: " + String(piCorrection.initType, "d"));
*/
OMC_DISABLE_OPT
static void FeedforwardFeedbackTemp_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,154,"Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= piCorrection.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: ");
  modelica_string tmp3;
  modelica_metatype tmpMeta4;
  static int tmp5 = 0;
  if(!tmp5)
  {
    tmp0 = GreaterEq((data->simulationInfo->integerParameter[0] /* piCorrection.initType PARAM */),1);
    tmp1 = LessEq((data->simulationInfo->integerParameter[0] /* piCorrection.initType PARAM */),4);
    if(!(tmp0 && tmp1))
    {
      tmp3 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[0] /* piCorrection.initType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta4 = stringAppend(MMC_REFSTRINGLIT(tmp2),tmp3);
      {
        const char* assert_cond = "(piCorrection.initType >= Modelica.Blocks.Types.Init.NoInit and piCorrection.initType <= Modelica.Blocks.Types.Init.InitialOutput)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",513,5,516,40,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",513,5,516,40,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
        }
      }
      tmp5 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 36
type: ALGORITHM

  assert(piCorrection.T >= 1e-60, "Variable violating min constraint: 1e-60 <= piCorrection.T, has value: " + String(piCorrection.T, "g"));
*/
OMC_DISABLE_OPT
static void FeedforwardFeedbackTemp_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  modelica_boolean tmp6;
  static const MMC_DEFSTRINGLIT(tmp7,71,"Variable violating min constraint: 1e-60 <= piCorrection.T, has value: ");
  modelica_string tmp8;
  modelica_metatype tmpMeta9;
  static int tmp10 = 0;
  if(!tmp10)
  {
    tmp6 = GreaterEq((data->simulationInfo->realParameter[21] /* piCorrection.T PARAM */),1e-60);
    if(!tmp6)
    {
      tmp8 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[21] /* piCorrection.T PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta9 = stringAppend(MMC_REFSTRINGLIT(tmp7),tmp8);
      {
        const char* assert_cond = "(piCorrection.T >= 1e-60)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",511,5,512,37,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta9));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",511,5,512,37,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta9));
        }
      }
      tmp10 = 1;
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void FeedforwardFeedbackTemp_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  FeedforwardFeedbackTemp_eqFunction_23(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_24(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_25(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_26(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_27(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_28(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_29(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_30(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_31(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_33(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_34(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_35(data, threadData);
  FeedforwardFeedbackTemp_eqFunction_36(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int FeedforwardFeedbackTemp_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->integerParameter[0]/* piCorrection.initType PARAM */) = 3;
  data->modelData->integerParameterData[0].time_unvarying = 1;
  FeedforwardFeedbackTemp_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

