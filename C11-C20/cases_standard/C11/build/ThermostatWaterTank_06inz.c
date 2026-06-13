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
T = T0
*/
void ThermostatWaterTank_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T STATE(1) */) = (data->simulationInfo->realParameter[2] /* T0 PARAM */);
  TRACE_POP
}
extern void ThermostatWaterTank_eqFunction_10(DATA *data, threadData_t *threadData);

extern void ThermostatWaterTank_eqFunction_12(DATA *data, threadData_t *threadData);

extern void ThermostatWaterTank_eqFunction_13(DATA *data, threadData_t *threadData);


/*
equation index: 5
type: SIMPLE_ASSIGN
$PRE.controller.y = controller.pre_y_start
*/
void ThermostatWaterTank_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->simulationInfo->booleanVarsPre[0] /* controller.y DISCRETE */) = (data->simulationInfo->booleanParameter[0] /* controller.pre_y_start PARAM */);
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
controller.y = not $PRE.controller.y and feedback.y > controller.uHigh or $PRE.controller.y and feedback.y >= controller.uLow
*/
void ThermostatWaterTank_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  tmp0 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* feedback.y variable */),(data->simulationInfo->realParameter[6] /* controller.uHigh PARAM */));
  tmp1 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* feedback.y variable */),(data->simulationInfo->realParameter[7] /* controller.uLow PARAM */));
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* controller.y DISCRETE */) = (((!(data->simulationInfo->booleanVarsPre[0] /* controller.y DISCRETE */)) && tmp0) || ((data->simulationInfo->booleanVarsPre[0] /* controller.y DISCRETE */) && tmp1));
  TRACE_POP
}
extern void ThermostatWaterTank_eqFunction_14(DATA *data, threadData_t *threadData);

extern void ThermostatWaterTank_eqFunction_15(DATA *data, threadData_t *threadData);


/*
equation index: 9
type: ALGORITHM

  assert(controller.uHigh > controller.uLow, "Hysteresis limits wrong (uHigh <= uLow)");
*/
void ThermostatWaterTank_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  modelica_boolean tmp2;
  static const MMC_DEFSTRINGLIT(tmp3,39,"Hysteresis limits wrong (uHigh <= uLow)");
  static int tmp4 = 0;
  {
    tmp2 = Greater((data->simulationInfo->realParameter[6] /* controller.uHigh PARAM */),(data->simulationInfo->realParameter[7] /* controller.uLow PARAM */));
    if(!tmp2)
    {
      {
        const char* assert_cond = "(controller.uHigh > controller.uLow)";
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
  ThermostatWaterTank_eqFunction_10(data, threadData);
  ThermostatWaterTank_eqFunction_12(data, threadData);
  ThermostatWaterTank_eqFunction_13(data, threadData);
  ThermostatWaterTank_eqFunction_5(data, threadData);
  ThermostatWaterTank_eqFunction_6(data, threadData);
  ThermostatWaterTank_eqFunction_14(data, threadData);
  ThermostatWaterTank_eqFunction_15(data, threadData);
  ThermostatWaterTank_eqFunction_9(data, threadData);
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

