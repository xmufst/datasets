/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "CascadeTankPI_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 50
type: SIMPLE_ASSIGN
$START.inner_PI.x = inner_PI.x_start
*/
static void CascadeTankPI_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
  (data->modelData->realVarsData[2] /* inner_PI.x STATE(1) */).attribute .start = (data->simulationInfo->realParameter[12] /* inner_PI.x_start PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* inner_PI.x STATE(1) */) = (data->modelData->realVarsData[2] /* inner_PI.x STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[2].info /* inner_PI.x */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* inner_PI.x STATE(1) */));
  TRACE_POP
}

/*
equation index: 51
type: SIMPLE_ASSIGN
$START.outer_PI.x = outer_PI.x_start
*/
static void CascadeTankPI_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  (data->modelData->realVarsData[3] /* outer_PI.x STATE(1) */).attribute .start = (data->simulationInfo->realParameter[18] /* outer_PI.x_start PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* outer_PI.x STATE(1) */) = (data->modelData->realVarsData[3] /* outer_PI.x STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[3].info /* outer_PI.x */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* outer_PI.x STATE(1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int CascadeTankPI_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  CascadeTankPI_eqFunction_50(data, threadData);

  CascadeTankPI_eqFunction_51(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void CascadeTankPI_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 52
type: SIMPLE_ASSIGN
h2_ref_source.k = h2_ref
*/
OMC_DISABLE_OPT
static void CascadeTankPI_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
  (data->simulationInfo->realParameter[8] /* h2_ref_source.k PARAM */) = (data->simulationInfo->realParameter[7] /* h2_ref PARAM */);
  TRACE_POP
}

/*
equation index: 53
type: SIMPLE_ASSIGN
outer_feedback.u1 = h2_ref_source.k
*/
OMC_DISABLE_OPT
static void CascadeTankPI_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
  (data->simulationInfo->realParameter[20] /* outer_feedback.u1 PARAM */) = (data->simulationInfo->realParameter[8] /* h2_ref_source.k PARAM */);
  TRACE_POP
}

/*
equation index: 54
type: SIMPLE_ASSIGN
h2_ref_source.y = h2_ref_source.k
*/
OMC_DISABLE_OPT
static void CascadeTankPI_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,54};
  (data->simulationInfo->realParameter[9] /* h2_ref_source.y PARAM */) = (data->simulationInfo->realParameter[8] /* h2_ref_source.k PARAM */);
  TRACE_POP
}

/*
equation index: 58
type: SIMPLE_ASSIGN
inner_PI.T = Ti_inner
*/
OMC_DISABLE_OPT
static void CascadeTankPI_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
  (data->simulationInfo->realParameter[10] /* inner_PI.T PARAM */) = (data->simulationInfo->realParameter[5] /* Ti_inner PARAM */);
  TRACE_POP
}

/*
equation index: 59
type: SIMPLE_ASSIGN
inner_PI.k = Kp_inner
*/
OMC_DISABLE_OPT
static void CascadeTankPI_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
  (data->simulationInfo->realParameter[11] /* inner_PI.k PARAM */) = (data->simulationInfo->realParameter[2] /* Kp_inner PARAM */);
  TRACE_POP
}

/*
equation index: 61
type: SIMPLE_ASSIGN
outer_PI.T = Ti_outer
*/
OMC_DISABLE_OPT
static void CascadeTankPI_eqFunction_61(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
  (data->simulationInfo->realParameter[16] /* outer_PI.T PARAM */) = (data->simulationInfo->realParameter[6] /* Ti_outer PARAM */);
  TRACE_POP
}

/*
equation index: 62
type: SIMPLE_ASSIGN
outer_PI.k = Kp_outer
*/
OMC_DISABLE_OPT
static void CascadeTankPI_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
  (data->simulationInfo->realParameter[17] /* outer_PI.k PARAM */) = (data->simulationInfo->realParameter[3] /* Kp_outer PARAM */);
  TRACE_POP
}

/*
equation index: 63
type: ALGORITHM

  assert(valve_limiter.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and valve_limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, "Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= valve_limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: " + String(valve_limiter.homotopyType, "d"));
*/
OMC_DISABLE_OPT
static void CascadeTankPI_eqFunction_63(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,63};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,182,"Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= valve_limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: ");
  modelica_string tmp3;
  modelica_metatype tmpMeta4;
  static int tmp5 = 0;
  if(!tmp5)
  {
    tmp0 = GreaterEq((data->simulationInfo->integerParameter[2] /* valve_limiter.homotopyType PARAM */),1);
    tmp1 = LessEq((data->simulationInfo->integerParameter[2] /* valve_limiter.homotopyType PARAM */),4);
    if(!(tmp0 && tmp1))
    {
      tmp3 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[2] /* valve_limiter.homotopyType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta4 = stringAppend(MMC_REFSTRINGLIT(tmp2),tmp3);
      {
        const char* assert_cond = "(valve_limiter.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and valve_limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit)";
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
equation index: 64
type: ALGORITHM

  assert(inner_PI.initType >= Modelica.Blocks.Types.Init.NoInit and inner_PI.initType <= Modelica.Blocks.Types.Init.InitialOutput, "Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= inner_PI.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: " + String(inner_PI.initType, "d"));
*/
OMC_DISABLE_OPT
static void CascadeTankPI_eqFunction_64(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,64};
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  static const MMC_DEFSTRINGLIT(tmp8,150,"Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= inner_PI.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: ");
  modelica_string tmp9;
  modelica_metatype tmpMeta10;
  static int tmp11 = 0;
  if(!tmp11)
  {
    tmp6 = GreaterEq((data->simulationInfo->integerParameter[0] /* inner_PI.initType PARAM */),1);
    tmp7 = LessEq((data->simulationInfo->integerParameter[0] /* inner_PI.initType PARAM */),4);
    if(!(tmp6 && tmp7))
    {
      tmp9 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[0] /* inner_PI.initType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta10 = stringAppend(MMC_REFSTRINGLIT(tmp8),tmp9);
      {
        const char* assert_cond = "(inner_PI.initType >= Modelica.Blocks.Types.Init.NoInit and inner_PI.initType <= Modelica.Blocks.Types.Init.InitialOutput)";
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
equation index: 65
type: ALGORITHM

  assert(inner_PI.T >= 1e-60, "Variable violating min constraint: 1e-60 <= inner_PI.T, has value: " + String(inner_PI.T, "g"));
*/
OMC_DISABLE_OPT
static void CascadeTankPI_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  modelica_boolean tmp12;
  static const MMC_DEFSTRINGLIT(tmp13,67,"Variable violating min constraint: 1e-60 <= inner_PI.T, has value: ");
  modelica_string tmp14;
  modelica_metatype tmpMeta15;
  static int tmp16 = 0;
  if(!tmp16)
  {
    tmp12 = GreaterEq((data->simulationInfo->realParameter[10] /* inner_PI.T PARAM */),1e-60);
    if(!tmp12)
    {
      tmp14 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[10] /* inner_PI.T PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta15 = stringAppend(MMC_REFSTRINGLIT(tmp13),tmp14);
      {
        const char* assert_cond = "(inner_PI.T >= 1e-60)";
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

/*
equation index: 66
type: ALGORITHM

  assert(outer_PI.initType >= Modelica.Blocks.Types.Init.NoInit and outer_PI.initType <= Modelica.Blocks.Types.Init.InitialOutput, "Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= outer_PI.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: " + String(outer_PI.initType, "d"));
*/
OMC_DISABLE_OPT
static void CascadeTankPI_eqFunction_66(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,66};
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  static const MMC_DEFSTRINGLIT(tmp19,150,"Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= outer_PI.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: ");
  modelica_string tmp20;
  modelica_metatype tmpMeta21;
  static int tmp22 = 0;
  if(!tmp22)
  {
    tmp17 = GreaterEq((data->simulationInfo->integerParameter[1] /* outer_PI.initType PARAM */),1);
    tmp18 = LessEq((data->simulationInfo->integerParameter[1] /* outer_PI.initType PARAM */),4);
    if(!(tmp17 && tmp18))
    {
      tmp20 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[1] /* outer_PI.initType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta21 = stringAppend(MMC_REFSTRINGLIT(tmp19),tmp20);
      {
        const char* assert_cond = "(outer_PI.initType >= Modelica.Blocks.Types.Init.NoInit and outer_PI.initType <= Modelica.Blocks.Types.Init.InitialOutput)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",513,5,516,40,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta21));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",513,5,516,40,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta21));
        }
      }
      tmp22 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 67
type: ALGORITHM

  assert(outer_PI.T >= 1e-60, "Variable violating min constraint: 1e-60 <= outer_PI.T, has value: " + String(outer_PI.T, "g"));
*/
OMC_DISABLE_OPT
static void CascadeTankPI_eqFunction_67(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,67};
  modelica_boolean tmp23;
  static const MMC_DEFSTRINGLIT(tmp24,67,"Variable violating min constraint: 1e-60 <= outer_PI.T, has value: ");
  modelica_string tmp25;
  modelica_metatype tmpMeta26;
  static int tmp27 = 0;
  if(!tmp27)
  {
    tmp23 = GreaterEq((data->simulationInfo->realParameter[16] /* outer_PI.T PARAM */),1e-60);
    if(!tmp23)
    {
      tmp25 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[16] /* outer_PI.T PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta26 = stringAppend(MMC_REFSTRINGLIT(tmp24),tmp25);
      {
        const char* assert_cond = "(outer_PI.T >= 1e-60)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",511,5,512,37,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta26));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Continuous.mo",511,5,512,37,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta26));
        }
      }
      tmp27 = 1;
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void CascadeTankPI_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  CascadeTankPI_eqFunction_52(data, threadData);
  CascadeTankPI_eqFunction_53(data, threadData);
  CascadeTankPI_eqFunction_54(data, threadData);
  CascadeTankPI_eqFunction_58(data, threadData);
  CascadeTankPI_eqFunction_59(data, threadData);
  CascadeTankPI_eqFunction_61(data, threadData);
  CascadeTankPI_eqFunction_62(data, threadData);
  CascadeTankPI_eqFunction_63(data, threadData);
  CascadeTankPI_eqFunction_64(data, threadData);
  CascadeTankPI_eqFunction_65(data, threadData);
  CascadeTankPI_eqFunction_66(data, threadData);
  CascadeTankPI_eqFunction_67(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int CascadeTankPI_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->booleanParameter[0]/* valve_limiter.strict PARAM */) = 0 /* false */;
  data->modelData->booleanParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[0]/* inner_PI.initType PARAM */) = 3;
  data->modelData->integerParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[1]/* outer_PI.initType PARAM */) = 3;
  data->modelData->integerParameterData[1].time_unvarying = 1;
  (data->simulationInfo->integerParameter[2]/* valve_limiter.homotopyType PARAM */) = 2;
  data->modelData->integerParameterData[2].time_unvarying = 1;
  CascadeTankPI_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

