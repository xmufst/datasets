/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "RCLeadCompensator_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 31
type: SIMPLE_ASSIGN
$START.compensator.x[1] = compensator.x_start[1]
*/
static void RCLeadCompensator_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  (data->modelData->realVarsData[6] /* compensator.x[1] variable */).attribute .start = (data->simulationInfo->realParameter[13] /* compensator.x_start[1] PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* compensator.x[1] variable */) = (data->modelData->realVarsData[6] /* compensator.x[1] variable */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[6].info /* compensator.x[1] */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* compensator.x[1] variable */));
  TRACE_POP
}
OMC_DISABLE_OPT
int RCLeadCompensator_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  RCLeadCompensator_eqFunction_31(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void RCLeadCompensator_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 34
type: SIMPLE_ASSIGN
limiter.uMin = -V_max
*/
OMC_DISABLE_OPT
static void RCLeadCompensator_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  (data->simulationInfo->realParameter[16] /* limiter.uMin PARAM */) = (-(data->simulationInfo->realParameter[3] /* V_max PARAM */));
  TRACE_POP
}

/*
equation index: 35
type: SIMPLE_ASSIGN
limiter.uMax = V_max
*/
OMC_DISABLE_OPT
static void RCLeadCompensator_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  (data->simulationInfo->realParameter[15] /* limiter.uMax PARAM */) = (data->simulationInfo->realParameter[3] /* V_max PARAM */);
  TRACE_POP
}

/*
equation index: 36
type: SIMPLE_ASSIGN
compensator.a[1] = tau_lag
*/
OMC_DISABLE_OPT
static void RCLeadCompensator_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  (data->simulationInfo->realParameter[5] /* compensator.a[1] PARAM */) = (data->simulationInfo->realParameter[20] /* tau_lag PARAM */);
  TRACE_POP
}

/*
equation index: 37
type: SIMPLE_ASSIGN
compensator.a_end = if compensator.a[2] > 1e-13 * sqrt(compensator.a[1] ^ 2.0 + compensator.a[2] ^ 2.0) then compensator.a[2] else 1.0
*/
OMC_DISABLE_OPT
static void RCLeadCompensator_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  tmp0 = (data->simulationInfo->realParameter[5] /* compensator.a[1] PARAM */);
  tmp1 = (data->simulationInfo->realParameter[6] /* compensator.a[2] PARAM */);
  tmp2 = (tmp0 * tmp0) + (tmp1 * tmp1);
  if(!(tmp2 >= 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(compensator.a[1] ^ 2.0 + compensator.a[2] ^ 2.0) was %g should be >= 0", tmp2);
    }
  }tmp3 = Greater((data->simulationInfo->realParameter[6] /* compensator.a[2] PARAM */),(1e-13) * (sqrt(tmp2)));
  (data->simulationInfo->realParameter[7] /* compensator.a_end PARAM */) = (tmp3?(data->simulationInfo->realParameter[6] /* compensator.a[2] PARAM */):1.0);
  TRACE_POP
}

/*
equation index: 38
type: SIMPLE_ASSIGN
compensator.b[1] = Kc * tau_lead
*/
OMC_DISABLE_OPT
static void RCLeadCompensator_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  (data->simulationInfo->realParameter[8] /* compensator.b[1] PARAM */) = ((data->simulationInfo->realParameter[1] /* Kc PARAM */)) * ((data->simulationInfo->realParameter[21] /* tau_lead PARAM */));
  TRACE_POP
}

/*
equation index: 39
type: SIMPLE_ASSIGN
compensator.bb[1] = compensator.b[1]
*/
OMC_DISABLE_OPT
static void RCLeadCompensator_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  (data->simulationInfo->realParameter[10] /* compensator.bb[1] PARAM */) = (data->simulationInfo->realParameter[8] /* compensator.b[1] PARAM */);
  TRACE_POP
}

/*
equation index: 40
type: SIMPLE_ASSIGN
compensator.d = compensator.bb[1] / compensator.a[1]
*/
OMC_DISABLE_OPT
static void RCLeadCompensator_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  (data->simulationInfo->realParameter[12] /* compensator.d PARAM */) = DIVISION_SIM((data->simulationInfo->realParameter[10] /* compensator.bb[1] PARAM */),(data->simulationInfo->realParameter[5] /* compensator.a[1] PARAM */),"compensator.a[1]",equationIndexes);
  TRACE_POP
}

/*
equation index: 41
type: SIMPLE_ASSIGN
compensator.b[2] = Kc
*/
OMC_DISABLE_OPT
static void RCLeadCompensator_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
  (data->simulationInfo->realParameter[9] /* compensator.b[2] PARAM */) = (data->simulationInfo->realParameter[1] /* Kc PARAM */);
  TRACE_POP
}

/*
equation index: 42
type: SIMPLE_ASSIGN
compensator.bb[2] = compensator.b[2]
*/
OMC_DISABLE_OPT
static void RCLeadCompensator_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  (data->simulationInfo->realParameter[11] /* compensator.bb[2] PARAM */) = (data->simulationInfo->realParameter[9] /* compensator.b[2] PARAM */);
  TRACE_POP
}

/*
equation index: 47
type: SIMPLE_ASSIGN
step.height = V_ref
*/
OMC_DISABLE_OPT
static void RCLeadCompensator_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
  (data->simulationInfo->realParameter[17] /* step.height PARAM */) = (data->simulationInfo->realParameter[4] /* V_ref PARAM */);
  TRACE_POP
}

/*
equation index: 48
type: ALGORITHM

  assert(limiter.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, "Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: " + String(limiter.homotopyType, "d"));
*/
OMC_DISABLE_OPT
static void RCLeadCompensator_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  static const MMC_DEFSTRINGLIT(tmp6,176,"Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: ");
  modelica_string tmp7;
  modelica_metatype tmpMeta8;
  static int tmp9 = 0;
  if(!tmp9)
  {
    tmp4 = GreaterEq((data->simulationInfo->integerParameter[4] /* limiter.homotopyType PARAM */),1);
    tmp5 = LessEq((data->simulationInfo->integerParameter[4] /* limiter.homotopyType PARAM */),4);
    if(!(tmp4 && tmp5))
    {
      tmp7 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[4] /* limiter.homotopyType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta8 = stringAppend(MMC_REFSTRINGLIT(tmp6),tmp7);
      {
        const char* assert_cond = "(limiter.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",12,9,13,69,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",12,9,13,69,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
        }
      }
      tmp9 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 49
type: ALGORITHM

  assert(compensator.initType >= Modelica.Blocks.Types.Init.NoInit and compensator.initType <= Modelica.Blocks.Types.Init.InitialOutput, "Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= compensator.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: " + String(compensator.initType, "d"));
*/
OMC_DISABLE_OPT
static void RCLeadCompensator_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  static const MMC_DEFSTRINGLIT(tmp12,153,"Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= compensator.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: ");
  modelica_string tmp13;
  modelica_metatype tmpMeta14;
  static int tmp15 = 0;
  if(!tmp15)
  {
    tmp10 = GreaterEq((data->simulationInfo->integerParameter[0] /* compensator.initType PARAM */),1);
    tmp11 = LessEq((data->simulationInfo->integerParameter[0] /* compensator.initType PARAM */),4);
    if(!(tmp10 && tmp11))
    {
      tmp13 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[0] /* compensator.initType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta14 = stringAppend(MMC_REFSTRINGLIT(tmp12),tmp13);
      {
        const char* assert_cond = "(compensator.initType >= Modelica.Blocks.Types.Init.NoInit and compensator.initType <= Modelica.Blocks.Types.Init.InitialOutput)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",1127,5,1130,31,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",1127,5,1130,31,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
        }
      }
      tmp15 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 50
type: ALGORITHM

  assert(C_val >= 0.0, "Variable violating min constraint: 0.0 <= C_val, has value: " + String(C_val, "g"));
*/
OMC_DISABLE_OPT
static void RCLeadCompensator_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
  modelica_boolean tmp16;
  static const MMC_DEFSTRINGLIT(tmp17,60,"Variable violating min constraint: 0.0 <= C_val, has value: ");
  modelica_string tmp18;
  modelica_metatype tmpMeta19;
  static int tmp20 = 0;
  if(!tmp20)
  {
    tmp16 = GreaterEq((data->simulationInfo->realParameter[0] /* C_val PARAM */),0.0);
    if(!tmp16)
    {
      tmp18 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[0] /* C_val PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta19 = stringAppend(MMC_REFSTRINGLIT(tmp17),tmp18);
      {
        const char* assert_cond = "(C_val >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/Desktop/AFM/cases/20260407_154112_RCLeadCompensator/build/src/RCLeadCompensator.mo",6,3,6,72,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta19));
        } else {
          FILE_INFO info = {"C:/Users/FST/Desktop/AFM/cases/20260407_154112_RCLeadCompensator/build/src/RCLeadCompensator.mo",6,3,6,72,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta19));
        }
      }
      tmp20 = 1;
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void RCLeadCompensator_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  RCLeadCompensator_eqFunction_34(data, threadData);
  RCLeadCompensator_eqFunction_35(data, threadData);
  RCLeadCompensator_eqFunction_36(data, threadData);
  RCLeadCompensator_eqFunction_37(data, threadData);
  RCLeadCompensator_eqFunction_38(data, threadData);
  RCLeadCompensator_eqFunction_39(data, threadData);
  RCLeadCompensator_eqFunction_40(data, threadData);
  RCLeadCompensator_eqFunction_41(data, threadData);
  RCLeadCompensator_eqFunction_42(data, threadData);
  RCLeadCompensator_eqFunction_47(data, threadData);
  RCLeadCompensator_eqFunction_48(data, threadData);
  RCLeadCompensator_eqFunction_49(data, threadData);
  RCLeadCompensator_eqFunction_50(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int RCLeadCompensator_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->integerParameter[1]/* compensator.na PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[1].time_unvarying = 1;
  (data->simulationInfo->integerParameter[2]/* compensator.nb PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[2].time_unvarying = 1;
  (data->simulationInfo->integerParameter[3]/* compensator.nx PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[3].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[0]/* limiter.strict PARAM */) = 0 /* false */;
  data->modelData->booleanParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[0]/* compensator.initType PARAM */) = 3;
  data->modelData->integerParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[4]/* limiter.homotopyType PARAM */) = 2;
  data->modelData->integerParameterData[4].time_unvarying = 1;
  RCLeadCompensator_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

