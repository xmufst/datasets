/* Initialization */
#include "BoilerFeedwaterRatio_model.h"
#include "BoilerFeedwaterRatio_11mix.h"
#include "BoilerFeedwaterRatio_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void BoilerFeedwaterRatio_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void BoilerFeedwaterRatio_eqFunction_32(DATA *data, threadData_t *threadData);


/*
equation index: 2
type: SIMPLE_ASSIGN
piController.x = piController.x_start
*/
void BoilerFeedwaterRatio_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piController.x STATE(1) */) = (data->simulationInfo->realParameter[10] /* piController.x_start PARAM */);
  TRACE_POP
}

void BoilerFeedwaterRatio_eqFunction_3(DATA*, threadData_t*);
void BoilerFeedwaterRatio_eqFunction_4(DATA*, threadData_t*);
void BoilerFeedwaterRatio_eqFunction_5(DATA*, threadData_t*);
void BoilerFeedwaterRatio_eqFunction_6(DATA*, threadData_t*);
void BoilerFeedwaterRatio_eqFunction_7(DATA*, threadData_t*);
/*
equation index: 12
indexNonlinear: 0
type: NONLINEAR

vars: {u_pi}
eqns: {3, 4, 5, 6, 7}
*/
void BoilerFeedwaterRatio_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  int retValue;
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving nonlinear system 12 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */);
  retValue = solve_nonlinear_system(data, threadData, 0);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,12};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 12 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */) = data->simulationInfo->nonlinearSystemData[0].nlsx[0];
  TRACE_POP
}
extern void BoilerFeedwaterRatio_eqFunction_44(DATA *data, threadData_t *threadData);

extern void BoilerFeedwaterRatio_eqFunction_43(DATA *data, threadData_t *threadData);


/*
equation index: 15
type: SIMPLE_ASSIGN
h_drum = h0
*/
void BoilerFeedwaterRatio_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h_drum STATE(1) */) = (data->simulationInfo->realParameter[7] /* h0 PARAM */);
  TRACE_POP
}

/*
equation index: 16
type: ALGORITHM

  assert(valveLimiter.uMax >= valveLimiter.uMin, "Limiter: Limits must be consistent. However, uMax (=" + String(valveLimiter.uMax, 6, 0, true) + ") < uMin (=" + String(valveLimiter.uMin, 6, 0, true) + ")");
*/
void BoilerFeedwaterRatio_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,52,"Limiter: Limits must be consistent. However, uMax (=");
  modelica_string tmp2;
  modelica_metatype tmpMeta3;
  static const MMC_DEFSTRINGLIT(tmp4,11,") < uMin (=");
  modelica_metatype tmpMeta5;
  modelica_string tmp6;
  modelica_metatype tmpMeta7;
  modelica_metatype tmpMeta8;
  static int tmp9 = 0;
  {
    tmp0 = GreaterEq((data->simulationInfo->realParameter[19] /* valveLimiter.uMax PARAM */),(data->simulationInfo->realParameter[20] /* valveLimiter.uMin PARAM */));
    if(!tmp0)
    {
      tmp2 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[19] /* valveLimiter.uMax PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta3 = stringAppend(MMC_REFSTRINGLIT(tmp1),tmp2);
      tmpMeta5 = stringAppend(tmpMeta3,MMC_REFSTRINGLIT(tmp4));
      tmp6 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[20] /* valveLimiter.uMin PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1 /* true */);
      tmpMeta7 = stringAppend(tmpMeta5,tmp6);
      tmpMeta8 = stringAppend(tmpMeta7,(modelica_string) mmc_strings_len1[41]);
      {
        const char* assert_cond = "(valveLimiter.uMax >= valveLimiter.uMin)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/FST/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
        }
      }
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void BoilerFeedwaterRatio_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  BoilerFeedwaterRatio_eqFunction_32(data, threadData);
  BoilerFeedwaterRatio_eqFunction_2(data, threadData);
  BoilerFeedwaterRatio_eqFunction_12(data, threadData);
  BoilerFeedwaterRatio_eqFunction_44(data, threadData);
  BoilerFeedwaterRatio_eqFunction_43(data, threadData);
  BoilerFeedwaterRatio_eqFunction_15(data, threadData);
  BoilerFeedwaterRatio_eqFunction_16(data, threadData);
  TRACE_POP
}

int BoilerFeedwaterRatio_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  BoilerFeedwaterRatio_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
extern void BoilerFeedwaterRatio_eqFunction_32(DATA *data, threadData_t *threadData);

extern void BoilerFeedwaterRatio_eqFunction_2(DATA *data, threadData_t *threadData);


/*
equation index: 28
type: LINEAR

<var>ratio_error</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void BoilerFeedwaterRatio_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  /* Linear equation system */
  int retValue;
  double aux_x[1] = { (data->localData[1]->realVars[data->simulationInfo->realVarsIndex[7]] /* ratio_error variable */) };
  if(OMC_ACTIVE_STREAM(OMC_LOG_DT))
  {
    infoStreamPrint(OMC_LOG_DT, 1, "Solving linear system 28 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(OMC_LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 0, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,28};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 28 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* ratio_error variable */) = aux_x[0];

  TRACE_POP
}
extern void BoilerFeedwaterRatio_eqFunction_44(DATA *data, threadData_t *threadData);

extern void BoilerFeedwaterRatio_eqFunction_43(DATA *data, threadData_t *threadData);

extern void BoilerFeedwaterRatio_eqFunction_15(DATA *data, threadData_t *threadData);

int BoilerFeedwaterRatio_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  BoilerFeedwaterRatio_eqFunction_32(data, threadData);

  BoilerFeedwaterRatio_eqFunction_2(data, threadData);

  BoilerFeedwaterRatio_eqFunction_28(data, threadData);

  BoilerFeedwaterRatio_eqFunction_44(data, threadData);

  BoilerFeedwaterRatio_eqFunction_43(data, threadData);

  BoilerFeedwaterRatio_eqFunction_15(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int BoilerFeedwaterRatio_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

