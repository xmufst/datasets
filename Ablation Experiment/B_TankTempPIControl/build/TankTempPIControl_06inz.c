/* Initialization */
#include "TankTempPIControl_model.h"
#include "TankTempPIControl_11mix.h"
#include "TankTempPIControl_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void TankTempPIControl_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
piController.I.local_reset = false
*/
void TankTempPIControl_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* piController.I.local_reset DISCRETE */) = 0 /* false */;
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
piController.I.local_set = 0.0
*/
void TankTempPIControl_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* piController.I.local_set variable */) = 0.0;
  TRACE_POP
}
extern void TankTempPIControl_eqFunction_42(DATA *data, threadData_t *threadData);


/*
equation index: 4
type: SIMPLE_ASSIGN
T_water = $START.T_water
*/
void TankTempPIControl_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_water STATE(1) */) = (data->modelData->realVarsData[0] /* T_water STATE(1) */).attribute .start;
  TRACE_POP
}
extern void TankTempPIControl_eqFunction_43(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_44(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_54(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_55(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_57(DATA *data, threadData_t *threadData);


/*
equation index: 10
type: SIMPLE_ASSIGN
piController.I.y = piController.I.y_start
*/
void TankTempPIControl_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piController.I.y STATE(1) */) = (data->simulationInfo->realParameter[19] /* piController.I.y_start PARAM */);
  TRACE_POP
}
extern void TankTempPIControl_eqFunction_45(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_46(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_47(DATA *data, threadData_t *threadData);


/*
equation index: 14
type: SIMPLE_ASSIGN
u_pi = homotopy(smooth(0, if piController.limiter.u > piController.limiter.uMax then piController.limiter.uMax else if piController.limiter.u < piController.limiter.uMin then piController.limiter.uMin else piController.limiter.u), piController.limiter.u)
*/
void TankTempPIControl_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* piController.limiter.u variable */),(data->simulationInfo->realParameter[45] /* piController.limiter.uMax PARAM */));
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = (data->simulationInfo->realParameter[45] /* piController.limiter.uMax PARAM */);
  }
  else
  {
    tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* piController.limiter.u variable */),(data->simulationInfo->realParameter[46] /* piController.limiter.uMin PARAM */));
    tmp3 = (tmp1?(data->simulationInfo->realParameter[46] /* piController.limiter.uMin PARAM */):(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* piController.limiter.u variable */));
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* u_pi variable */) = homotopy(tmp3, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* piController.limiter.u variable */));
  TRACE_POP
}
extern void TankTempPIControl_eqFunction_49(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_50(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_51(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_52(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_53(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_56(DATA *data, threadData_t *threadData);


/*
equation index: 21
type: ALGORITHM

  assert(piController.limiter.uMax >= piController.limiter.uMin, "Limiter: Limits must be consistent. However, uMax (=" + String(piController.limiter.uMax, 6, 0, true) + ") < uMin (=" + String(piController.limiter.uMin, 6, 0, true) + ")");
*/
void TankTempPIControl_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  modelica_boolean tmp4;
  static const MMC_DEFSTRINGLIT(tmp5,52,"Limiter: Limits must be consistent. However, uMax (=");
  modelica_string tmp6;
  modelica_metatype tmpMeta7;
  static const MMC_DEFSTRINGLIT(tmp8,11,") < uMin (=");
  modelica_metatype tmpMeta9;
  modelica_string tmp10;
  modelica_metatype tmpMeta11;
  modelica_metatype tmpMeta12;
  static int tmp13 = 0;
  {
    tmp4 = GreaterEq((data->simulationInfo->realParameter[45] /* piController.limiter.uMax PARAM */),(data->simulationInfo->realParameter[46] /* piController.limiter.uMin PARAM */));
    if(!tmp4)
    {
      tmp6 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[45] /* piController.limiter.uMax PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta7 = stringAppend(MMC_REFSTRINGLIT(tmp5),tmp6);
      tmpMeta9 = stringAppend(tmpMeta7,MMC_REFSTRINGLIT(tmp8));
      tmp10 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[46] /* piController.limiter.uMin PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta11 = stringAppend(tmpMeta9,tmp10);
      tmpMeta12 = stringAppend(tmpMeta11,(modelica_string) mmc_strings_len1[41]);
      {
        const char* assert_cond = "(piController.limiter.uMax >= piController.limiter.uMin)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta12));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta12));
        }
      }
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void TankTempPIControl_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  TankTempPIControl_eqFunction_1(data, threadData);
  TankTempPIControl_eqFunction_2(data, threadData);
  TankTempPIControl_eqFunction_42(data, threadData);
  TankTempPIControl_eqFunction_4(data, threadData);
  TankTempPIControl_eqFunction_43(data, threadData);
  TankTempPIControl_eqFunction_44(data, threadData);
  TankTempPIControl_eqFunction_54(data, threadData);
  TankTempPIControl_eqFunction_55(data, threadData);
  TankTempPIControl_eqFunction_57(data, threadData);
  TankTempPIControl_eqFunction_10(data, threadData);
  TankTempPIControl_eqFunction_45(data, threadData);
  TankTempPIControl_eqFunction_46(data, threadData);
  TankTempPIControl_eqFunction_47(data, threadData);
  TankTempPIControl_eqFunction_14(data, threadData);
  TankTempPIControl_eqFunction_49(data, threadData);
  TankTempPIControl_eqFunction_50(data, threadData);
  TankTempPIControl_eqFunction_51(data, threadData);
  TankTempPIControl_eqFunction_52(data, threadData);
  TankTempPIControl_eqFunction_53(data, threadData);
  TankTempPIControl_eqFunction_56(data, threadData);
  TankTempPIControl_eqFunction_21(data, threadData);
  TRACE_POP
}

int TankTempPIControl_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  TankTempPIControl_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
extern void TankTempPIControl_eqFunction_1(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_2(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_42(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_4(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_43(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_44(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_54(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_55(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_57(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_10(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_45(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_46(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_47(DATA *data, threadData_t *threadData);


/*
equation index: 35
type: SIMPLE_ASSIGN
u_pi = piController.limiter.u
*/
void TankTempPIControl_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* u_pi variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* piController.limiter.u variable */);
  TRACE_POP
}
extern void TankTempPIControl_eqFunction_49(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_50(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_51(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_52(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_53(DATA *data, threadData_t *threadData);

extern void TankTempPIControl_eqFunction_56(DATA *data, threadData_t *threadData);

int TankTempPIControl_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  TankTempPIControl_eqFunction_1(data, threadData);

  TankTempPIControl_eqFunction_2(data, threadData);

  TankTempPIControl_eqFunction_42(data, threadData);

  TankTempPIControl_eqFunction_4(data, threadData);

  TankTempPIControl_eqFunction_43(data, threadData);

  TankTempPIControl_eqFunction_44(data, threadData);

  TankTempPIControl_eqFunction_54(data, threadData);

  TankTempPIControl_eqFunction_55(data, threadData);

  TankTempPIControl_eqFunction_57(data, threadData);

  TankTempPIControl_eqFunction_10(data, threadData);

  TankTempPIControl_eqFunction_45(data, threadData);

  TankTempPIControl_eqFunction_46(data, threadData);

  TankTempPIControl_eqFunction_47(data, threadData);

  TankTempPIControl_eqFunction_35(data, threadData);

  TankTempPIControl_eqFunction_49(data, threadData);

  TankTempPIControl_eqFunction_50(data, threadData);

  TankTempPIControl_eqFunction_51(data, threadData);

  TankTempPIControl_eqFunction_52(data, threadData);

  TankTempPIControl_eqFunction_53(data, threadData);

  TankTempPIControl_eqFunction_56(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int TankTempPIControl_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

