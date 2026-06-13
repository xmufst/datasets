/* Initialization */
#include "ThermostatWaterTank_model.h"
#include "ThermostatWaterTank_11mix.h"
#include "ThermostatWaterTank_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void ThermostatWaterTank_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
T = $START.T
*/
void ThermostatWaterTank_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */) = (data->modelData->realVarsData[0] /* T STATE(1) */).attribute .start;
  TRACE_POP
}
extern void ThermostatWaterTank_eqFunction_9(DATA *data, threadData_t *threadData);

extern void ThermostatWaterTank_eqFunction_12(DATA *data, threadData_t *threadData);


/*
equation index: 4
type: SIMPLE_ASSIGN
$PRE.hysteresis.y = hysteresis.pre_y_start
*/
void ThermostatWaterTank_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->simulationInfo->booleanVarsPre[0] /* hysteresis.y DISCRETE */) = (data->simulationInfo->booleanParameter[0] /* hysteresis.pre_y_start PARAM */);
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
hysteresis.y = not $PRE.hysteresis.y and T_error > hysteresis.uHigh or $PRE.hysteresis.y and T_error >= hysteresis.uLow
*/
void ThermostatWaterTank_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  tmp0 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_error variable */),(data->simulationInfo->realParameter[11] /* hysteresis.uHigh PARAM */));
  tmp1 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T_error variable */),(data->simulationInfo->realParameter[12] /* hysteresis.uLow PARAM */));
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* hysteresis.y DISCRETE */) = (((!(data->simulationInfo->booleanVarsPre[0] /* hysteresis.y DISCRETE */)) && tmp0) || ((data->simulationInfo->booleanVarsPre[0] /* hysteresis.y DISCRETE */) && tmp1));
  TRACE_POP
}
extern void ThermostatWaterTank_eqFunction_11(DATA *data, threadData_t *threadData);

extern void ThermostatWaterTank_eqFunction_13(DATA *data, threadData_t *threadData);


/*
equation index: 8
type: ALGORITHM

  assert(hysteresis.uHigh > hysteresis.uLow, "Hysteresis limits wrong (uHigh <= uLow)");
*/
void ThermostatWaterTank_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  modelica_boolean tmp2;
  static const MMC_DEFSTRINGLIT(tmp3,39,"Hysteresis limits wrong (uHigh <= uLow)");
  static int tmp4 = 0;
  {
    tmp2 = Greater((data->simulationInfo->realParameter[11] /* hysteresis.uHigh PARAM */),(data->simulationInfo->realParameter[12] /* hysteresis.uLow PARAM */));
    if(!tmp2)
    {
      {
        const char* assert_cond = "(hysteresis.uHigh > hysteresis.uLow)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Logical.mo",523,5,523,67,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp3)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Logical.mo",523,5,523,67,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp3)));
        }
      }
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void ThermostatWaterTank_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  ThermostatWaterTank_eqFunction_1(data, threadData);
  ThermostatWaterTank_eqFunction_9(data, threadData);
  ThermostatWaterTank_eqFunction_12(data, threadData);
  ThermostatWaterTank_eqFunction_4(data, threadData);
  ThermostatWaterTank_eqFunction_5(data, threadData);
  ThermostatWaterTank_eqFunction_11(data, threadData);
  ThermostatWaterTank_eqFunction_13(data, threadData);
  ThermostatWaterTank_eqFunction_8(data, threadData);
  TRACE_POP
}

int ThermostatWaterTank_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  ThermostatWaterTank_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No ThermostatWaterTank_functionInitialEquations_lambda0 function */

int ThermostatWaterTank_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

