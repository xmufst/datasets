/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "RCCircuit_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 24
type: SIMPLE_ASSIGN
$START.capacitor.v = Vc0
*/
static void RCCircuit_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->modelData->realVarsData[1] /* capacitor.v STATE(1) */).attribute .start = (data->simulationInfo->realParameter[3] /* Vc0 PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* capacitor.v STATE(1) */) = (data->modelData->realVarsData[1] /* capacitor.v STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* capacitor.v */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* capacitor.v STATE(1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int RCCircuit_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  RCCircuit_eqFunction_24(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void RCCircuit_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 25
type: SIMPLE_ASSIGN
resistor.T = resistor.T_ref
*/
OMC_DISABLE_OPT
static void RCCircuit_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->simulationInfo->realParameter[6] /* resistor.T PARAM */) = (data->simulationInfo->realParameter[8] /* resistor.T_ref PARAM */);
  TRACE_POP
}

/*
equation index: 26
type: SIMPLE_ASSIGN
resistor.T_heatPort = resistor.T
*/
OMC_DISABLE_OPT
static void RCCircuit_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->simulationInfo->realParameter[7] /* resistor.T_heatPort PARAM */) = (data->simulationInfo->realParameter[6] /* resistor.T PARAM */);
  TRACE_POP
}

/*
equation index: 27
type: SIMPLE_ASSIGN
stepSignal.startTime = t_switch
*/
OMC_DISABLE_OPT
static void RCCircuit_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  (data->simulationInfo->realParameter[12] /* stepSignal.startTime PARAM */) = (data->simulationInfo->realParameter[13] /* t_switch PARAM */);
  TRACE_POP
}

/*
equation index: 28
type: SIMPLE_ASSIGN
stepSignal.offset = V_source
*/
OMC_DISABLE_OPT
static void RCCircuit_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  (data->simulationInfo->realParameter[11] /* stepSignal.offset PARAM */) = (data->simulationInfo->realParameter[2] /* V_source PARAM */);
  TRACE_POP
}

/*
equation index: 29
type: SIMPLE_ASSIGN
stepSignal.height = -V_source
*/
OMC_DISABLE_OPT
static void RCCircuit_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  (data->simulationInfo->realParameter[10] /* stepSignal.height PARAM */) = (-(data->simulationInfo->realParameter[2] /* V_source PARAM */));
  TRACE_POP
}

/*
equation index: 30
type: SIMPLE_ASSIGN
capacitor.C = C
*/
OMC_DISABLE_OPT
static void RCCircuit_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  (data->simulationInfo->realParameter[4] /* capacitor.C PARAM */) = (data->simulationInfo->realParameter[0] /* C PARAM */);
  TRACE_POP
}

/*
equation index: 32
type: SIMPLE_ASSIGN
resistor.R = R
*/
OMC_DISABLE_OPT
static void RCCircuit_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  (data->simulationInfo->realParameter[5] /* resistor.R PARAM */) = (data->simulationInfo->realParameter[1] /* R PARAM */);
  TRACE_POP
}
extern void RCCircuit_eqFunction_13(DATA *data, threadData_t *threadData);

extern void RCCircuit_eqFunction_12(DATA *data, threadData_t *threadData);

extern void RCCircuit_eqFunction_2(DATA *data, threadData_t *threadData);

extern void RCCircuit_eqFunction_1(DATA *data, threadData_t *threadData);


/*
equation index: 37
type: ALGORITHM

  assert(resistor.T_ref >= 0.0, "Variable violating min constraint: 0.0 <= resistor.T_ref, has value: " + String(resistor.T_ref, "g"));
*/
OMC_DISABLE_OPT
static void RCCircuit_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,69,"Variable violating min constraint: 0.0 <= resistor.T_ref, has value: ");
  modelica_string tmp2;
  modelica_metatype tmpMeta3;
  static int tmp4 = 0;
  if(!tmp4)
  {
    tmp0 = GreaterEq((data->simulationInfo->realParameter[8] /* resistor.T_ref PARAM */),0.0);
    if(!tmp0)
    {
      tmp2 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[8] /* resistor.T_ref PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta3 = stringAppend(MMC_REFSTRINGLIT(tmp1),tmp2);
      {
        const char* assert_cond = "(resistor.T_ref >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Electrical/Analog/Basic/Resistor.mo",5,3,5,64,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta3));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Electrical/Analog/Basic/Resistor.mo",5,3,5,64,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta3));
        }
      }
      tmp4 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 38
type: ALGORITHM

  assert(resistor.T >= 0.0, "Variable violating min constraint: 0.0 <= resistor.T, has value: " + String(resistor.T, "g"));
*/
OMC_DISABLE_OPT
static void RCCircuit_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  modelica_boolean tmp5;
  static const MMC_DEFSTRINGLIT(tmp6,65,"Variable violating min constraint: 0.0 <= resistor.T, has value: ");
  modelica_string tmp7;
  modelica_metatype tmpMeta8;
  static int tmp9 = 0;
  if(!tmp9)
  {
    tmp5 = GreaterEq((data->simulationInfo->realParameter[6] /* resistor.T PARAM */),0.0);
    if(!tmp5)
    {
      tmp7 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[6] /* resistor.T PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta8 = stringAppend(MMC_REFSTRINGLIT(tmp6),tmp7);
      {
        const char* assert_cond = "(resistor.T >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Electrical/Analog/Interfaces/ConditionalHeatPort.mo",7,3,8,97,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Electrical/Analog/Interfaces/ConditionalHeatPort.mo",7,3,8,97,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
        }
      }
      tmp9 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 39
type: ALGORITHM

  assert(resistor.T_heatPort >= 0.0, "Variable violating min constraint: 0.0 <= resistor.T_heatPort, has value: " + String(resistor.T_heatPort, "g"));
*/
OMC_DISABLE_OPT
static void RCCircuit_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  modelica_boolean tmp10;
  static const MMC_DEFSTRINGLIT(tmp11,74,"Variable violating min constraint: 0.0 <= resistor.T_heatPort, has value: ");
  modelica_string tmp12;
  modelica_metatype tmpMeta13;
  static int tmp14 = 0;
  if(!tmp14)
  {
    tmp10 = GreaterEq((data->simulationInfo->realParameter[7] /* resistor.T_heatPort PARAM */),0.0);
    if(!tmp10)
    {
      tmp12 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[7] /* resistor.T_heatPort PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta13 = stringAppend(MMC_REFSTRINGLIT(tmp11),tmp12);
      {
        const char* assert_cond = "(resistor.T_heatPort >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Electrical/Analog/Interfaces/ConditionalHeatPort.mo",14,3,14,54,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta13));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Electrical/Analog/Interfaces/ConditionalHeatPort.mo",14,3,14,54,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta13));
        }
      }
      tmp14 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 40
type: ALGORITHM

  assert(capacitor.C >= 0.0, "Variable violating min constraint: 0.0 <= capacitor.C, has value: " + String(capacitor.C, "g"));
*/
OMC_DISABLE_OPT
static void RCCircuit_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  modelica_boolean tmp15;
  static const MMC_DEFSTRINGLIT(tmp16,66,"Variable violating min constraint: 0.0 <= capacitor.C, has value: ");
  modelica_string tmp17;
  modelica_metatype tmpMeta18;
  static int tmp19 = 0;
  if(!tmp19)
  {
    tmp15 = GreaterEq((data->simulationInfo->realParameter[4] /* capacitor.C PARAM */),0.0);
    if(!tmp15)
    {
      tmp17 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[4] /* capacitor.C PARAM */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta18 = stringAppend(MMC_REFSTRINGLIT(tmp16),tmp17);
      {
        const char* assert_cond = "(capacitor.C >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Electrical/Analog/Basic/Capacitor.mo",4,3,4,52,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta18));
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Electrical/Analog/Basic/Capacitor.mo",4,3,4,52,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta18));
        }
      }
      tmp19 = 1;
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void RCCircuit_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  RCCircuit_eqFunction_25(data, threadData);
  RCCircuit_eqFunction_26(data, threadData);
  RCCircuit_eqFunction_27(data, threadData);
  RCCircuit_eqFunction_28(data, threadData);
  RCCircuit_eqFunction_29(data, threadData);
  RCCircuit_eqFunction_30(data, threadData);
  RCCircuit_eqFunction_32(data, threadData);
  RCCircuit_eqFunction_13(data, threadData);
  RCCircuit_eqFunction_12(data, threadData);
  RCCircuit_eqFunction_2(data, threadData);
  RCCircuit_eqFunction_1(data, threadData);
  RCCircuit_eqFunction_37(data, threadData);
  RCCircuit_eqFunction_38(data, threadData);
  RCCircuit_eqFunction_39(data, threadData);
  RCCircuit_eqFunction_40(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int RCCircuit_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->booleanParameter[0]/* resistor.useHeatPort PARAM */) = 0 /* false */;
  data->modelData->booleanParameterData[0].time_unvarying = 1;
  RCCircuit_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

