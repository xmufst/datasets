/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "SmithPredictorTemp_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 22
type: SIMPLE_ASSIGN
$START.pi_ctrl.x = pi_ctrl.x_start
*/
static void SmithPredictorTemp_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->modelData->realVarsData[2] /* pi_ctrl.x STATE(1) */).attribute .start = (data->simulationInfo->realParameter[12] /* pi_ctrl.x_start PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* pi_ctrl.x STATE(1) */) = (data->modelData->realVarsData[2] /* pi_ctrl.x STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[2].info /* pi_ctrl.x */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* pi_ctrl.x STATE(1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int SmithPredictorTemp_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  SmithPredictorTemp_eqFunction_22(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void SmithPredictorTemp_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 24
type: SIMPLE_ASSIGN
pi_ctrl.T = Ti
*/
OMC_DISABLE_OPT
static void SmithPredictorTemp_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->simulationInfo->realParameter[10] /* pi_ctrl.T PARAM */) = (data->simulationInfo->realParameter[6] /* Ti PARAM */);
  TRACE_POP
}

/*
equation index: 25
type: SIMPLE_ASSIGN
pi_ctrl.k = Kp
*/
OMC_DISABLE_OPT
static void SmithPredictorTemp_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->simulationInfo->realParameter[11] /* pi_ctrl.k PARAM */) = (data->simulationInfo->realParameter[1] /* Kp PARAM */);
  TRACE_POP
}

/*
equation index: 26
type: SIMPLE_ASSIGN
step_ref.offset = T0
*/
OMC_DISABLE_OPT
static void SmithPredictorTemp_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->simulationInfo->realParameter[15] /* step_ref.offset PARAM */) = (data->simulationInfo->realParameter[3] /* T0 PARAM */);
  TRACE_POP
}

/*
equation index: 27
type: SIMPLE_ASSIGN
step_ref.height = T_ref - T0
*/
OMC_DISABLE_OPT
static void SmithPredictorTemp_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  (data->simulationInfo->realParameter[14] /* step_ref.height PARAM */) = (data->simulationInfo->realParameter[5] /* T_ref PARAM */) - (data->simulationInfo->realParameter[3] /* T0 PARAM */);
  TRACE_POP
}

/*
equation index: 28
type: ALGORITHM

  assert(pi_ctrl.initType >= Modelica.Blocks.Types.Init.NoInit and pi_ctrl.initType <= Modelica.Blocks.Types.Init.InitialOutput, "Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= pi_ctrl.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: " + String(pi_ctrl.initType, "d"));
*/
OMC_DISABLE_OPT
static void SmithPredictorTemp_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,149,"Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= pi_ctrl.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: ");
  modelica_string tmp3;
  modelica_metatype tmpMeta4;
  static int tmp5 = 0;
  if(!tmp5)
  {
    tmp0 = GreaterEq((data->simulationInfo->integerParameter[0] /* pi_ctrl.initType PARAM */),1);
    tmp1 = LessEq((data->simulationInfo->integerParameter[0] /* pi_ctrl.initType PARAM */),4);
    if(!(tmp0 && tmp1))
    {
      tmp3 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[0] /* pi_ctrl.initType PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta4 = stringAppend(MMC_REFSTRINGLIT(tmp2),tmp3);
      {
        const char* assert_cond = "(pi_ctrl.initType >= Modelica.Blocks.Types.Init.NoInit and pi_ctrl.initType <= Modelica.Blocks.Types.Init.InitialOutput)";
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
equation index: 29
type: ALGORITHM

  assert(pi_ctrl.T >= 1e-60, "Variable violating min constraint: 1e-60 <= pi_ctrl.T, has value: " + String(pi_ctrl.T, "g"));
*/
OMC_DISABLE_OPT
static void SmithPredictorTemp_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  modelica_boolean tmp6;
  static const MMC_DEFSTRINGLIT(tmp7,66,"Variable violating min constraint: 1e-60 <= pi_ctrl.T, has value: ");
  modelica_string tmp8;
  modelica_metatype tmpMeta9;
  static int tmp10 = 0;
  if(!tmp10)
  {
    tmp6 = GreaterEq((data->simulationInfo->realParameter[10] /* pi_ctrl.T PARAM */),1e-60);
    if(!tmp6)
    {
      tmp8 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[10] /* pi_ctrl.T PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta9 = stringAppend(MMC_REFSTRINGLIT(tmp7),tmp8);
      {
        const char* assert_cond = "(pi_ctrl.T >= 1e-60)";
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
void SmithPredictorTemp_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  SmithPredictorTemp_eqFunction_24(data, threadData);
  SmithPredictorTemp_eqFunction_25(data, threadData);
  SmithPredictorTemp_eqFunction_26(data, threadData);
  SmithPredictorTemp_eqFunction_27(data, threadData);
  SmithPredictorTemp_eqFunction_28(data, threadData);
  SmithPredictorTemp_eqFunction_29(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int SmithPredictorTemp_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->integerParameter[0]/* pi_ctrl.initType PARAM */) = 3;
  data->modelData->integerParameterData[0].time_unvarying = 1;
  SmithPredictorTemp_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

