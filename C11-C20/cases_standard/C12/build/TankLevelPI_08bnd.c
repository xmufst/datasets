/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "TankLevelPI_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 28
type: SIMPLE_ASSIGN
$START.h = h0
*/
static void TankLevelPI_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  (data->modelData->realVarsData[0] /* h STATE(1) */).attribute .start = (data->simulationInfo->realParameter[5] /* h0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1) */) = (data->modelData->realVarsData[0] /* h STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* h */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1) */));
  TRACE_POP
}

/*
equation index: 29
type: SIMPLE_ASSIGN
$START.piController.x = piController.x_start
*/
static void TankLevelPI_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  (data->modelData->realVarsData[1] /* piController.x STATE(1) */).attribute .start = (data->simulationInfo->realParameter[12] /* piController.x_start PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piController.x STATE(1) */) = (data->modelData->realVarsData[1] /* piController.x STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* piController.x */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piController.x STATE(1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int TankLevelPI_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  TankLevelPI_eqFunction_28(data, threadData);

  TankLevelPI_eqFunction_29(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void TankLevelPI_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 30
type: SIMPLE_ASSIGN
setpoint.k = h_ref
*/
OMC_DISABLE_OPT
static void TankLevelPI_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  (data->simulationInfo->realParameter[14] /* setpoint.k PARAM */) = (data->simulationInfo->realParameter[6] /* h_ref PARAM */);
  TRACE_POP
}

/*
equation index: 31
type: SIMPLE_ASSIGN
feedback.u1 = setpoint.k
*/
OMC_DISABLE_OPT
static void TankLevelPI_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  (data->simulationInfo->realParameter[4] /* feedback.u1 PARAM */) = (data->simulationInfo->realParameter[14] /* setpoint.k PARAM */);
  TRACE_POP
}

/*
equation index: 32
type: SIMPLE_ASSIGN
setpoint.y = setpoint.k
*/
OMC_DISABLE_OPT
static void TankLevelPI_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  (data->simulationInfo->realParameter[15] /* setpoint.y PARAM */) = (data->simulationInfo->realParameter[14] /* setpoint.k PARAM */);
  TRACE_POP
}

/*
equation index: 36
type: SIMPLE_ASSIGN
piController.T = Ti
*/
OMC_DISABLE_OPT
static void TankLevelPI_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  (data->simulationInfo->realParameter[10] /* piController.T PARAM */) = (data->simulationInfo->realParameter[3] /* Ti PARAM */);
  TRACE_POP
}

/*
equation index: 37
type: SIMPLE_ASSIGN
piController.k = Kp
*/
OMC_DISABLE_OPT
static void TankLevelPI_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  (data->simulationInfo->realParameter[11] /* piController.k PARAM */) = (data->simulationInfo->realParameter[1] /* Kp PARAM */);
  TRACE_POP
}

/*
equation index: 38
type: ALGORITHM

  assert(limiter.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, "Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: " + String(limiter.homotopyType, "d"));
*/
OMC_DISABLE_OPT
static void TankLevelPI_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,176,"Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: ");
  modelica_string tmp3;
  modelica_metatype tmpMeta4;
  static int tmp5 = 0;
  if(!tmp5)
  {
    tmp0 = GreaterEq((data->simulationInfo->integerParameter[0] /* limiter.homotopyType PARAM */),1);
    tmp1 = LessEq((data->simulationInfo->integerParameter[0] /* limiter.homotopyType PARAM */),4);
    if(!(tmp0 && tmp1))
    {
      tmp3 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[0] /* limiter.homotopyType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta4 = stringAppend(MMC_REFSTRINGLIT(tmp2),tmp3);
      {
        const char* assert_cond = "(limiter.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit)";
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
equation index: 39
type: ALGORITHM

  assert(piController.initType >= Modelica.Blocks.Types.Init.NoInit and piController.initType <= Modelica.Blocks.Types.Init.InitialOutput, "Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= piController.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: " + String(piController.initType, "d"));
*/
OMC_DISABLE_OPT
static void TankLevelPI_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  static const MMC_DEFSTRINGLIT(tmp8,154,"Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= piController.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: ");
  modelica_string tmp9;
  modelica_metatype tmpMeta10;
  static int tmp11 = 0;
  if(!tmp11)
  {
    tmp6 = GreaterEq((data->simulationInfo->integerParameter[1] /* piController.initType PARAM */),1);
    tmp7 = LessEq((data->simulationInfo->integerParameter[1] /* piController.initType PARAM */),4);
    if(!(tmp6 && tmp7))
    {
      tmp9 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[1] /* piController.initType PARAM */), (modelica_string) mmc_strings_len1[100]);
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
equation index: 40
type: ALGORITHM

  assert(piController.T >= 1e-60, "Variable violating min constraint: 1e-60 <= piController.T, has value: " + String(piController.T, "g"));
*/
OMC_DISABLE_OPT
static void TankLevelPI_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
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
void TankLevelPI_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  TankLevelPI_eqFunction_30(data, threadData);
  TankLevelPI_eqFunction_31(data, threadData);
  TankLevelPI_eqFunction_32(data, threadData);
  TankLevelPI_eqFunction_36(data, threadData);
  TankLevelPI_eqFunction_37(data, threadData);
  TankLevelPI_eqFunction_38(data, threadData);
  TankLevelPI_eqFunction_39(data, threadData);
  TankLevelPI_eqFunction_40(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int TankLevelPI_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->booleanParameter[0]/* limiter.strict PARAM */) = 0 /* false */;
  data->modelData->booleanParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[0]/* limiter.homotopyType PARAM */) = 2;
  data->modelData->integerParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[1]/* piController.initType PARAM */) = 3;
  data->modelData->integerParameterData[1].time_unvarying = 1;
  TankLevelPI_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

