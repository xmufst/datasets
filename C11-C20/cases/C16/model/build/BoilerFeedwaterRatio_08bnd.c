/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "BoilerFeedwaterRatio_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 46
type: SIMPLE_ASSIGN
$START.piController.x = piController.x_start
*/
static void BoilerFeedwaterRatio_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
  (data->modelData->realVarsData[1] /* piController.x STATE(1) */).attribute .start = (data->simulationInfo->realParameter[12] /* piController.x_start PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piController.x STATE(1) */) = (data->modelData->realVarsData[1] /* piController.x STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* piController.x */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piController.x STATE(1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int BoilerFeedwaterRatio_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  BoilerFeedwaterRatio_eqFunction_46(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void BoilerFeedwaterRatio_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 47
type: SIMPLE_ASSIGN
ratioSetpoint.k = R_set
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
  (data->simulationInfo->realParameter[15] /* ratioSetpoint.k PARAM */) = (data->simulationInfo->realParameter[3] /* R_set PARAM */);
  TRACE_POP
}

/*
equation index: 48
type: SIMPLE_ASSIGN
ratioFeedback.u1 = ratioSetpoint.k
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
  (data->simulationInfo->realParameter[14] /* ratioFeedback.u1 PARAM */) = (data->simulationInfo->realParameter[15] /* ratioSetpoint.k PARAM */);
  TRACE_POP
}

/*
equation index: 49
type: SIMPLE_ASSIGN
ratioSetpoint.y = ratioSetpoint.k
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
  (data->simulationInfo->realParameter[16] /* ratioSetpoint.y PARAM */) = (data->simulationInfo->realParameter[15] /* ratioSetpoint.k PARAM */);
  TRACE_POP
}

/*
equation index: 50
type: SIMPLE_ASSIGN
maxFlowConstant.k = K_fw
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
  (data->simulationInfo->realParameter[8] /* maxFlowConstant.k PARAM */) = (data->simulationInfo->realParameter[1] /* K_fw PARAM */);
  TRACE_POP
}

/*
equation index: 51
type: SIMPLE_ASSIGN
flowMultiplier.u2 = maxFlowConstant.k
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  (data->simulationInfo->realParameter[7] /* flowMultiplier.u2 PARAM */) = (data->simulationInfo->realParameter[8] /* maxFlowConstant.k PARAM */);
  TRACE_POP
}

/*
equation index: 52
type: SIMPLE_ASSIGN
maxFlowConstant.y = maxFlowConstant.k
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
  (data->simulationInfo->realParameter[9] /* maxFlowConstant.y PARAM */) = (data->simulationInfo->realParameter[8] /* maxFlowConstant.k PARAM */);
  TRACE_POP
}

/*
equation index: 56
type: SIMPLE_ASSIGN
piController.T = Ti
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_56(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,56};
  (data->simulationInfo->realParameter[10] /* piController.T PARAM */) = (data->simulationInfo->realParameter[4] /* Ti PARAM */);
  TRACE_POP
}

/*
equation index: 57
type: SIMPLE_ASSIGN
piController.k = Kp
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
  (data->simulationInfo->realParameter[11] /* piController.k PARAM */) = (data->simulationInfo->realParameter[2] /* Kp PARAM */);
  TRACE_POP
}

/*
equation index: 58
type: SIMPLE_ASSIGN
steamFlowStep.startTime = t_dist
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
  (data->simulationInfo->realParameter[19] /* steamFlowStep.startTime PARAM */) = (data->simulationInfo->realParameter[20] /* t_dist PARAM */);
  TRACE_POP
}

/*
equation index: 59
type: SIMPLE_ASSIGN
steamFlowStep.offset = W_steam_base
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
  (data->simulationInfo->realParameter[18] /* steamFlowStep.offset PARAM */) = (data->simulationInfo->realParameter[5] /* W_steam_base PARAM */);
  TRACE_POP
}

/*
equation index: 60
type: SIMPLE_ASSIGN
steamFlowStep.height = dW_steam
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_60(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,60};
  (data->simulationInfo->realParameter[17] /* steamFlowStep.height PARAM */) = (data->simulationInfo->realParameter[6] /* dW_steam PARAM */);
  TRACE_POP
}

/*
equation index: 61
type: ALGORITHM

  assert(valveLimiter.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and valveLimiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, "Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= valveLimiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: " + String(valveLimiter.homotopyType, "d"));
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_61(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,181,"Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= valveLimiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: ");
  modelica_string tmp3;
  modelica_metatype tmpMeta4;
  static int tmp5 = 0;
  if(!tmp5)
  {
    tmp0 = GreaterEq((data->simulationInfo->integerParameter[1] /* valveLimiter.homotopyType PARAM */),1);
    tmp1 = LessEq((data->simulationInfo->integerParameter[1] /* valveLimiter.homotopyType PARAM */),4);
    if(!(tmp0 && tmp1))
    {
      tmp3 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[1] /* valveLimiter.homotopyType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta4 = stringAppend(MMC_REFSTRINGLIT(tmp2),tmp3);
      {
        const char* assert_cond = "(valveLimiter.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and valveLimiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",12,9,13,69,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",12,9,13,69,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
        }
      }
      tmp5 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 62
type: ALGORITHM

  assert(piController.initType >= Modelica.Blocks.Types.Init.NoInit and piController.initType <= Modelica.Blocks.Types.Init.InitialOutput, "Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= piController.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: " + String(piController.initType, "d"));
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  static const MMC_DEFSTRINGLIT(tmp8,154,"Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= piController.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: ");
  modelica_string tmp9;
  modelica_metatype tmpMeta10;
  static int tmp11 = 0;
  if(!tmp11)
  {
    tmp6 = GreaterEq((data->simulationInfo->integerParameter[0] /* piController.initType PARAM */),1);
    tmp7 = LessEq((data->simulationInfo->integerParameter[0] /* piController.initType PARAM */),4);
    if(!(tmp6 && tmp7))
    {
      tmp9 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[0] /* piController.initType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta10 = stringAppend(MMC_REFSTRINGLIT(tmp8),tmp9);
      {
        const char* assert_cond = "(piController.initType >= Modelica.Blocks.Types.Init.NoInit and piController.initType <= Modelica.Blocks.Types.Init.InitialOutput)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",513,5,516,40,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta10));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",513,5,516,40,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta10));
        }
      }
      tmp11 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 63
type: ALGORITHM

  assert(piController.T >= 1e-60, "Variable violating min constraint: 1e-60 <= piController.T, has value: " + String(piController.T, "g"));
*/
OMC_DISABLE_OPT
static void BoilerFeedwaterRatio_eqFunction_63(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,63};
  modelica_boolean tmp12;
  static const MMC_DEFSTRINGLIT(tmp13,71,"Variable violating min constraint: 1e-60 <= piController.T, has value: ");
  modelica_string tmp14;
  modelica_metatype tmpMeta15;
  static int tmp16 = 0;
  if(!tmp16)
  {
    tmp12 = GreaterEq((data->simulationInfo->realParameter[10] /* piController.T PARAM */),1e-60);
    if(!tmp12)
    {
      tmp14 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[10] /* piController.T PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta15 = stringAppend(MMC_REFSTRINGLIT(tmp13),tmp14);
      {
        const char* assert_cond = "(piController.T >= 1e-60)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",511,5,512,37,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta15));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",511,5,512,37,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta15));
        }
      }
      tmp16 = 1;
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void BoilerFeedwaterRatio_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  BoilerFeedwaterRatio_eqFunction_47(data, threadData);
  BoilerFeedwaterRatio_eqFunction_48(data, threadData);
  BoilerFeedwaterRatio_eqFunction_49(data, threadData);
  BoilerFeedwaterRatio_eqFunction_50(data, threadData);
  BoilerFeedwaterRatio_eqFunction_51(data, threadData);
  BoilerFeedwaterRatio_eqFunction_52(data, threadData);
  BoilerFeedwaterRatio_eqFunction_56(data, threadData);
  BoilerFeedwaterRatio_eqFunction_57(data, threadData);
  BoilerFeedwaterRatio_eqFunction_58(data, threadData);
  BoilerFeedwaterRatio_eqFunction_59(data, threadData);
  BoilerFeedwaterRatio_eqFunction_60(data, threadData);
  BoilerFeedwaterRatio_eqFunction_61(data, threadData);
  BoilerFeedwaterRatio_eqFunction_62(data, threadData);
  BoilerFeedwaterRatio_eqFunction_63(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int BoilerFeedwaterRatio_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->booleanParameter[0]/* valveLimiter.strict PARAM */) = 0 /* false */;
  data->modelData->booleanParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[0]/* piController.initType PARAM */) = 3;
  data->modelData->integerParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[1]/* valveLimiter.homotopyType PARAM */) = 2;
  data->modelData->integerParameterData[1].time_unvarying = 1;
  BoilerFeedwaterRatio_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

