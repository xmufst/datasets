/* Initialization */
#include "RCLeadCompensator_model.h"
#include "RCLeadCompensator_11mix.h"
#include "RCLeadCompensator_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void RCLeadCompensator_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void RCLeadCompensator_eqFunction_22(DATA *data, threadData_t *threadData);


/*
equation index: 2
type: SIMPLE_ASSIGN
Vc = Vc0
*/
void RCLeadCompensator_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Vc STATE(1) */) = (data->simulationInfo->realParameter[5] /* Vc0 PARAM */);
  TRACE_POP
}
extern void RCLeadCompensator_eqFunction_23(DATA *data, threadData_t *threadData);


/*
equation index: 4
type: SIMPLE_ASSIGN
leadComp.x_scaled[1] = leadComp.x_start[1] * leadComp.a_end
*/
void RCLeadCompensator_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* leadComp.x_scaled[1] STATE(1) */) = ((data->simulationInfo->realParameter[14] /* leadComp.x_start[1] PARAM */)) * ((data->simulationInfo->realParameter[8] /* leadComp.a_end PARAM */));
  TRACE_POP
}
extern void RCLeadCompensator_eqFunction_24(DATA *data, threadData_t *threadData);

extern void RCLeadCompensator_eqFunction_25(DATA *data, threadData_t *threadData);

extern void RCLeadCompensator_eqFunction_26(DATA *data, threadData_t *threadData);


/*
equation index: 8
type: SIMPLE_ASSIGN
V_in = homotopy(smooth(0, if u_compensator > limiter.uMax then limiter.uMax else if u_compensator < limiter.uMin then limiter.uMin else u_compensator), u_compensator)
*/
void RCLeadCompensator_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* u_compensator variable */),(data->simulationInfo->realParameter[16] /* limiter.uMax PARAM */));
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = (data->simulationInfo->realParameter[16] /* limiter.uMax PARAM */);
  }
  else
  {
    tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* u_compensator variable */),(data->simulationInfo->realParameter[17] /* limiter.uMin PARAM */));
    tmp3 = (tmp1?(data->simulationInfo->realParameter[17] /* limiter.uMin PARAM */):(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* u_compensator variable */));
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* V_in variable */) = homotopy(tmp3, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* u_compensator variable */));
  TRACE_POP
}
extern void RCLeadCompensator_eqFunction_28(DATA *data, threadData_t *threadData);

extern void RCLeadCompensator_eqFunction_29(DATA *data, threadData_t *threadData);


/*
equation index: 11
type: ALGORITHM

  assert(limiter.uMax >= limiter.uMin, "Limiter: Limits must be consistent. However, uMax (=" + String(limiter.uMax, 6, 0, true) + ") < uMin (=" + String(limiter.uMin, 6, 0, true) + ")");
*/
void RCLeadCompensator_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
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
    tmp4 = GreaterEq((data->simulationInfo->realParameter[16] /* limiter.uMax PARAM */),(data->simulationInfo->realParameter[17] /* limiter.uMin PARAM */));
    if(!tmp4)
    {
      tmp6 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[16] /* limiter.uMax PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta7 = stringAppend(MMC_REFSTRINGLIT(tmp5),tmp6);
      tmpMeta9 = stringAppend(tmpMeta7,MMC_REFSTRINGLIT(tmp8));
      tmp10 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[17] /* limiter.uMin PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
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
void RCLeadCompensator_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  RCLeadCompensator_eqFunction_22(data, threadData);
  RCLeadCompensator_eqFunction_2(data, threadData);
  RCLeadCompensator_eqFunction_23(data, threadData);
  RCLeadCompensator_eqFunction_4(data, threadData);
  RCLeadCompensator_eqFunction_24(data, threadData);
  RCLeadCompensator_eqFunction_25(data, threadData);
  RCLeadCompensator_eqFunction_26(data, threadData);
  RCLeadCompensator_eqFunction_8(data, threadData);
  RCLeadCompensator_eqFunction_28(data, threadData);
  RCLeadCompensator_eqFunction_29(data, threadData);
  RCLeadCompensator_eqFunction_11(data, threadData);
  TRACE_POP
}

int RCLeadCompensator_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  RCLeadCompensator_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
extern void RCLeadCompensator_eqFunction_22(DATA *data, threadData_t *threadData);

extern void RCLeadCompensator_eqFunction_2(DATA *data, threadData_t *threadData);

extern void RCLeadCompensator_eqFunction_23(DATA *data, threadData_t *threadData);

extern void RCLeadCompensator_eqFunction_4(DATA *data, threadData_t *threadData);

extern void RCLeadCompensator_eqFunction_24(DATA *data, threadData_t *threadData);

extern void RCLeadCompensator_eqFunction_25(DATA *data, threadData_t *threadData);

extern void RCLeadCompensator_eqFunction_26(DATA *data, threadData_t *threadData);


/*
equation index: 19
type: SIMPLE_ASSIGN
V_in = u_compensator
*/
void RCLeadCompensator_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* V_in variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* u_compensator variable */);
  TRACE_POP
}
extern void RCLeadCompensator_eqFunction_28(DATA *data, threadData_t *threadData);

extern void RCLeadCompensator_eqFunction_29(DATA *data, threadData_t *threadData);

int RCLeadCompensator_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  RCLeadCompensator_eqFunction_22(data, threadData);

  RCLeadCompensator_eqFunction_2(data, threadData);

  RCLeadCompensator_eqFunction_23(data, threadData);

  RCLeadCompensator_eqFunction_4(data, threadData);

  RCLeadCompensator_eqFunction_24(data, threadData);

  RCLeadCompensator_eqFunction_25(data, threadData);

  RCLeadCompensator_eqFunction_26(data, threadData);

  RCLeadCompensator_eqFunction_19(data, threadData);

  RCLeadCompensator_eqFunction_28(data, threadData);

  RCLeadCompensator_eqFunction_29(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int RCLeadCompensator_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

