/* Initialization */
#include "TankLevelPI_model.h"
#include "TankLevelPI_11mix.h"
#include "TankLevelPI_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void TankLevelPI_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
h = $START.h
*/
void TankLevelPI_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* h STATE(1) */) = (data->modelData->realVarsData[1] /* h STATE(1) */).attribute .start;
  TRACE_POP
}
extern void TankLevelPI_eqFunction_20(DATA *data, threadData_t *threadData);

extern void TankLevelPI_eqFunction_21(DATA *data, threadData_t *threadData);

extern void TankLevelPI_eqFunction_25(DATA *data, threadData_t *threadData);


/*
equation index: 5
type: SIMPLE_ASSIGN
PI_controller.x = PI_controller.x_start
*/
void TankLevelPI_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* PI_controller.x STATE(1) */) = (data->simulationInfo->realParameter[4] /* PI_controller.x_start PARAM */);
  TRACE_POP
}
extern void TankLevelPI_eqFunction_22(DATA *data, threadData_t *threadData);


/*
equation index: 7
type: SIMPLE_ASSIGN
limiter.y = homotopy(smooth(0, if u_pi > limiter.uMax then limiter.uMax else if u_pi < limiter.uMin then limiter.uMin else u_pi), u_pi)
*/
void TankLevelPI_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */),(data->simulationInfo->realParameter[15] /* limiter.uMax PARAM */));
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = (data->simulationInfo->realParameter[15] /* limiter.uMax PARAM */);
  }
  else
  {
    tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */),(data->simulationInfo->realParameter[16] /* limiter.uMin PARAM */));
    tmp3 = (tmp1?(data->simulationInfo->realParameter[16] /* limiter.uMin PARAM */):(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */));
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* limiter.y variable */) = homotopy(tmp3, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */));
  TRACE_POP
}
extern void TankLevelPI_eqFunction_24(DATA *data, threadData_t *threadData);

extern void TankLevelPI_eqFunction_26(DATA *data, threadData_t *threadData);


/*
equation index: 10
type: ALGORITHM

  assert(limiter.uMax >= limiter.uMin, "Limiter: Limits must be consistent. However, uMax (=" + String(limiter.uMax, 6, 0, true) + ") < uMin (=" + String(limiter.uMin, 6, 0, true) + ")");
*/
void TankLevelPI_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
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
    tmp4 = GreaterEq((data->simulationInfo->realParameter[15] /* limiter.uMax PARAM */),(data->simulationInfo->realParameter[16] /* limiter.uMin PARAM */));
    if(!tmp4)
    {
      tmp6 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[15] /* limiter.uMax PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta7 = stringAppend(MMC_REFSTRINGLIT(tmp5),tmp6);
      tmpMeta9 = stringAppend(tmpMeta7,MMC_REFSTRINGLIT(tmp8));
      tmp10 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[16] /* limiter.uMin PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta11 = stringAppend(tmpMeta9,tmp10);
      tmpMeta12 = stringAppend(tmpMeta11,(modelica_string) mmc_strings_len1[41]);
      {
        const char* assert_cond = "(limiter.uMax >= limiter.uMin)";
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
void TankLevelPI_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  TankLevelPI_eqFunction_1(data, threadData);
  TankLevelPI_eqFunction_20(data, threadData);
  TankLevelPI_eqFunction_21(data, threadData);
  TankLevelPI_eqFunction_25(data, threadData);
  TankLevelPI_eqFunction_5(data, threadData);
  TankLevelPI_eqFunction_22(data, threadData);
  TankLevelPI_eqFunction_7(data, threadData);
  TankLevelPI_eqFunction_24(data, threadData);
  TankLevelPI_eqFunction_26(data, threadData);
  TankLevelPI_eqFunction_10(data, threadData);
  TRACE_POP
}

int TankLevelPI_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  TankLevelPI_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
extern void TankLevelPI_eqFunction_1(DATA *data, threadData_t *threadData);

extern void TankLevelPI_eqFunction_20(DATA *data, threadData_t *threadData);

extern void TankLevelPI_eqFunction_21(DATA *data, threadData_t *threadData);

extern void TankLevelPI_eqFunction_25(DATA *data, threadData_t *threadData);

extern void TankLevelPI_eqFunction_5(DATA *data, threadData_t *threadData);

extern void TankLevelPI_eqFunction_22(DATA *data, threadData_t *threadData);


/*
equation index: 17
type: SIMPLE_ASSIGN
limiter.y = u_pi
*/
void TankLevelPI_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* limiter.y variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */);
  TRACE_POP
}
extern void TankLevelPI_eqFunction_24(DATA *data, threadData_t *threadData);

extern void TankLevelPI_eqFunction_26(DATA *data, threadData_t *threadData);

int TankLevelPI_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  TankLevelPI_eqFunction_1(data, threadData);

  TankLevelPI_eqFunction_20(data, threadData);

  TankLevelPI_eqFunction_21(data, threadData);

  TankLevelPI_eqFunction_25(data, threadData);

  TankLevelPI_eqFunction_5(data, threadData);

  TankLevelPI_eqFunction_22(data, threadData);

  TankLevelPI_eqFunction_17(data, threadData);

  TankLevelPI_eqFunction_24(data, threadData);

  TankLevelPI_eqFunction_26(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int TankLevelPI_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

