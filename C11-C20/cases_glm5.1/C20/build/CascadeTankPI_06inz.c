/* Initialization */
#include "CascadeTankPI_model.h"
#include "CascadeTankPI_11mix.h"
#include "CascadeTankPI_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void CascadeTankPI_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
h1 = $START.h1
*/
void CascadeTankPI_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h1 STATE(1) */) = (data->modelData->realVarsData[0] /* h1 STATE(1) */).attribute .start;
  TRACE_POP
}
extern void CascadeTankPI_eqFunction_43(DATA *data, threadData_t *threadData);


/*
equation index: 3
type: SIMPLE_ASSIGN
h2 = $START.h2
*/
void CascadeTankPI_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* h2 STATE(1) */) = (data->modelData->realVarsData[1] /* h2 STATE(1) */).attribute .start;
  TRACE_POP
}
extern void CascadeTankPI_eqFunction_36(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_37(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_44(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_45(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_46(DATA *data, threadData_t *threadData);


/*
equation index: 9
type: SIMPLE_ASSIGN
inner_PI.x = inner_PI.x_start
*/
void CascadeTankPI_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* inner_PI.x STATE(1) */) = (data->simulationInfo->realParameter[12] /* inner_PI.x_start PARAM */);
  TRACE_POP
}

/*
equation index: 10
type: SIMPLE_ASSIGN
outer_PI.x = outer_PI.x_start
*/
void CascadeTankPI_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* outer_PI.x STATE(1) */) = (data->simulationInfo->realParameter[18] /* outer_PI.x_start PARAM */);
  TRACE_POP
}
extern void CascadeTankPI_eqFunction_38(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_39(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_40(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_41(DATA *data, threadData_t *threadData);


/*
equation index: 15
type: SIMPLE_ASSIGN
valve_limiter.y = homotopy(smooth(0, if u_inner > valve_limiter.uMax then valve_limiter.uMax else if u_inner < valve_limiter.uMin then valve_limiter.uMin else u_inner), u_inner)
*/
void CascadeTankPI_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* u_inner variable */),(data->simulationInfo->realParameter[21] /* valve_limiter.uMax PARAM */));
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = (data->simulationInfo->realParameter[21] /* valve_limiter.uMax PARAM */);
  }
  else
  {
    tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* u_inner variable */),(data->simulationInfo->realParameter[22] /* valve_limiter.uMin PARAM */));
    tmp3 = (tmp1?(data->simulationInfo->realParameter[22] /* valve_limiter.uMin PARAM */):(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* u_inner variable */));
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* valve_limiter.y variable */) = homotopy(tmp3, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* u_inner variable */));
  TRACE_POP
}
extern void CascadeTankPI_eqFunction_47(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_48(DATA *data, threadData_t *threadData);


/*
equation index: 18
type: ALGORITHM

  assert(valve_limiter.uMax >= valve_limiter.uMin, "Limiter: Limits must be consistent. However, uMax (=" + String(valve_limiter.uMax, 6, 0, true) + ") < uMin (=" + String(valve_limiter.uMin, 6, 0, true) + ")");
*/
void CascadeTankPI_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
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
    tmp4 = GreaterEq((data->simulationInfo->realParameter[21] /* valve_limiter.uMax PARAM */),(data->simulationInfo->realParameter[22] /* valve_limiter.uMin PARAM */));
    if(!tmp4)
    {
      tmp6 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[21] /* valve_limiter.uMax PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta7 = stringAppend(MMC_REFSTRINGLIT(tmp5),tmp6);
      tmpMeta9 = stringAppend(tmpMeta7,MMC_REFSTRINGLIT(tmp8));
      tmp10 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[22] /* valve_limiter.uMin PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta11 = stringAppend(tmpMeta9,tmp10);
      tmpMeta12 = stringAppend(tmpMeta11,(modelica_string) mmc_strings_len1[41]);
      {
        const char* assert_cond = "(valve_limiter.uMax >= valve_limiter.uMin)";
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
void CascadeTankPI_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  CascadeTankPI_eqFunction_1(data, threadData);
  CascadeTankPI_eqFunction_43(data, threadData);
  CascadeTankPI_eqFunction_3(data, threadData);
  CascadeTankPI_eqFunction_36(data, threadData);
  CascadeTankPI_eqFunction_37(data, threadData);
  CascadeTankPI_eqFunction_44(data, threadData);
  CascadeTankPI_eqFunction_45(data, threadData);
  CascadeTankPI_eqFunction_46(data, threadData);
  CascadeTankPI_eqFunction_9(data, threadData);
  CascadeTankPI_eqFunction_10(data, threadData);
  CascadeTankPI_eqFunction_38(data, threadData);
  CascadeTankPI_eqFunction_39(data, threadData);
  CascadeTankPI_eqFunction_40(data, threadData);
  CascadeTankPI_eqFunction_41(data, threadData);
  CascadeTankPI_eqFunction_15(data, threadData);
  CascadeTankPI_eqFunction_47(data, threadData);
  CascadeTankPI_eqFunction_48(data, threadData);
  CascadeTankPI_eqFunction_18(data, threadData);
  TRACE_POP
}

int CascadeTankPI_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  CascadeTankPI_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
extern void CascadeTankPI_eqFunction_1(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_43(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_3(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_36(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_37(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_44(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_45(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_46(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_9(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_10(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_38(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_39(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_40(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_41(DATA *data, threadData_t *threadData);


/*
equation index: 33
type: SIMPLE_ASSIGN
valve_limiter.y = u_inner
*/
void CascadeTankPI_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* valve_limiter.y variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* u_inner variable */);
  TRACE_POP
}
extern void CascadeTankPI_eqFunction_47(DATA *data, threadData_t *threadData);

extern void CascadeTankPI_eqFunction_48(DATA *data, threadData_t *threadData);

int CascadeTankPI_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  CascadeTankPI_eqFunction_1(data, threadData);

  CascadeTankPI_eqFunction_43(data, threadData);

  CascadeTankPI_eqFunction_3(data, threadData);

  CascadeTankPI_eqFunction_36(data, threadData);

  CascadeTankPI_eqFunction_37(data, threadData);

  CascadeTankPI_eqFunction_44(data, threadData);

  CascadeTankPI_eqFunction_45(data, threadData);

  CascadeTankPI_eqFunction_46(data, threadData);

  CascadeTankPI_eqFunction_9(data, threadData);

  CascadeTankPI_eqFunction_10(data, threadData);

  CascadeTankPI_eqFunction_38(data, threadData);

  CascadeTankPI_eqFunction_39(data, threadData);

  CascadeTankPI_eqFunction_40(data, threadData);

  CascadeTankPI_eqFunction_41(data, threadData);

  CascadeTankPI_eqFunction_33(data, threadData);

  CascadeTankPI_eqFunction_47(data, threadData);

  CascadeTankPI_eqFunction_48(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int CascadeTankPI_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

