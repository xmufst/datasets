/* Initialization */
#include "GravityTank_model.h"
#include "GravityTank_11mix.h"
#include "GravityTank_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void GravityTank_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
h = h0
*/
void GravityTank_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* h STATE(1) */) = (data->simulationInfo->realParameter[5] /* h0 PARAM */);
  TRACE_POP
}
extern void GravityTank_eqFunction_9(DATA *data, threadData_t *threadData);

extern void GravityTank_eqFunction_10(DATA *data, threadData_t *threadData);

extern void GravityTank_eqFunction_11(DATA *data, threadData_t *threadData);

extern void GravityTank_eqFunction_12(DATA *data, threadData_t *threadData);

extern void GravityTank_eqFunction_13(DATA *data, threadData_t *threadData);

extern void GravityTank_eqFunction_14(DATA *data, threadData_t *threadData);


/*
equation index: 8
type: ALGORITHM

  assert(h0 >= 0.0, "Initial liquid level must be non-negative");
*/
void GravityTank_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,41,"Initial liquid level must be non-negative");
  static int tmp2 = 0;
  {
    tmp0 = GreaterEq((data->simulationInfo->realParameter[5] /* h0 PARAM */),0.0);
    if(!tmp0)
    {
      {
        const char* assert_cond = "(h0 >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/FST/Desktop/AFM/cases/20260330_183240_GravityTank/build/src/GravityTank.mo",43,3,43,63,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp1)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/FST/Desktop/AFM/cases/20260330_183240_GravityTank/build/src/GravityTank.mo",43,3,43,63,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp1)));
        }
      }
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void GravityTank_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  GravityTank_eqFunction_1(data, threadData);
  GravityTank_eqFunction_9(data, threadData);
  GravityTank_eqFunction_10(data, threadData);
  GravityTank_eqFunction_11(data, threadData);
  GravityTank_eqFunction_12(data, threadData);
  GravityTank_eqFunction_13(data, threadData);
  GravityTank_eqFunction_14(data, threadData);
  GravityTank_eqFunction_8(data, threadData);
  TRACE_POP
}

int GravityTank_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  GravityTank_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No GravityTank_functionInitialEquations_lambda0 function */

int GravityTank_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

