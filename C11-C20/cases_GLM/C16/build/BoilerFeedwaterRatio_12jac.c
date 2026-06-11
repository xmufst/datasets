/* Jacobians 9 */
#include "BoilerFeedwaterRatio_model.h"
#include "BoilerFeedwaterRatio_12jac.h"
#include "simulation/jacobian_util.h"
#include "util/omc_file.h"
/* constant equations */
/* dynamic equations */

/*
equation index: 9
type: SIMPLE_ASSIGN
ratio_error.$pDERNLSJac0.dummyVarNLSJac0 = u_pi.SeedNLSJac0 / piController.k
*/
void BoilerFeedwaterRatio_eqFunction_9(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,9};
  jacobian->tmpVars[1] /* ratio_error.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* u_pi.SeedNLSJac0 SEED_VAR */,(data->simulationInfo->realParameter[11] /* piController.k PARAM */),"piController.k");
  TRACE_POP
}

/*
equation index: 10
type: SIMPLE_ASSIGN
valve_opening.$pDERNLSJac0.dummyVarNLSJac0 = __HOM_LAMBDA * (if u_pi > valveLimiter.uMax then 0.0 else if u_pi < valveLimiter.uMin then 0.0 else u_pi.SeedNLSJac0) + (1.0 - __HOM_LAMBDA) * u_pi.SeedNLSJac0
*/
void BoilerFeedwaterRatio_eqFunction_10(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,10};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */),(data->simulationInfo->realParameter[21] /* valveLimiter.uMax PARAM */));
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = 0.0;
  }
  else
  {
    tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */),(data->simulationInfo->realParameter[22] /* valveLimiter.uMin PARAM */));
    tmp3 = (tmp1?0.0:jacobian->seedVars[0] /* u_pi.SeedNLSJac0 SEED_VAR */);
  }
  jacobian->tmpVars[0] /* valve_opening.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */ = (data->simulationInfo->lambda) * (tmp3) + (1.0 - data->simulationInfo->lambda) * (jacobian->seedVars[0] /* u_pi.SeedNLSJac0 SEED_VAR */);
  TRACE_POP
}

/*
equation index: 11
type: SIMPLE_ASSIGN
W_feedwater.$pDERNLSJac0.dummyVarNLSJac0 = valve_opening.$pDERNLSJac0.dummyVarNLSJac0 * maxFlowConstant.k
*/
void BoilerFeedwaterRatio_eqFunction_11(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,11};
  jacobian->tmpVars[2] /* W_feedwater.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[0] /* valve_opening.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[8] /* maxFlowConstant.k PARAM */));
  TRACE_POP
}

/*
equation index: 12
type: SIMPLE_ASSIGN
$res_NLSJac0_1.$pDERNLSJac0.dummyVarNLSJac0 = W_feedwater.$pDERNLSJac0.dummyVarNLSJac0 + ratio_error.$pDERNLSJac0.dummyVarNLSJac0 * W_steam
*/
void BoilerFeedwaterRatio_eqFunction_12(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,12};
  jacobian->resultVars[0] /* $res_NLSJac0_1.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_VAR */ = jacobian->tmpVars[2] /* W_feedwater.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */ + (jacobian->tmpVars[1] /* ratio_error.$pDERNLSJac0.dummyVarNLSJac0 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* W_steam variable */));
  TRACE_POP
}

OMC_DISABLE_OPT
int BoilerFeedwaterRatio_functionJacNLSJac0_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = BoilerFeedwaterRatio_INDEX_JAC_NLSJac0;
  
  TRACE_POP
  return 0;
}

int BoilerFeedwaterRatio_functionJacNLSJac0_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = BoilerFeedwaterRatio_INDEX_JAC_NLSJac0;
  BoilerFeedwaterRatio_eqFunction_9(data, threadData, jacobian, parentJacobian);
  BoilerFeedwaterRatio_eqFunction_10(data, threadData, jacobian, parentJacobian);
  BoilerFeedwaterRatio_eqFunction_11(data, threadData, jacobian, parentJacobian);
  BoilerFeedwaterRatio_eqFunction_12(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 25
type: SIMPLE_ASSIGN
W_feedwater.$pDERLSJac1.dummyVarLSJac1 = (-ratio_error.SeedLSJac1) * W_steam
*/
void BoilerFeedwaterRatio_eqFunction_25(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,25};
  jacobian->tmpVars[2] /* W_feedwater.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_TMP_VAR */ = ((-jacobian->seedVars[0] /* ratio_error.SeedLSJac1 SEED_VAR */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* W_steam variable */));
  TRACE_POP
}

/*
equation index: 26
type: SIMPLE_ASSIGN
valve_opening.$pDERLSJac1.dummyVarLSJac1 = W_feedwater.$pDERLSJac1.dummyVarLSJac1 / maxFlowConstant.k
*/
void BoilerFeedwaterRatio_eqFunction_26(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,26};
  jacobian->tmpVars[3] /* valve_opening.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_TMP_VAR */ = DIVISION(jacobian->tmpVars[2] /* W_feedwater.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_TMP_VAR */,(data->simulationInfo->realParameter[8] /* maxFlowConstant.k PARAM */),"maxFlowConstant.k");
  TRACE_POP
}

/*
equation index: 27
type: SIMPLE_ASSIGN
u_pi.$pDERLSJac1.dummyVarLSJac1 = piController.k * ratio_error.SeedLSJac1
*/
void BoilerFeedwaterRatio_eqFunction_27(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,27};
  jacobian->tmpVars[0] /* u_pi.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_TMP_VAR */ = ((data->simulationInfo->realParameter[11] /* piController.k PARAM */)) * (jacobian->seedVars[0] /* ratio_error.SeedLSJac1 SEED_VAR */);
  TRACE_POP
}

/*
equation index: 28
type: SIMPLE_ASSIGN
$res_LSJac1_1.$pDERLSJac1.dummyVarLSJac1 = u_pi.$pDERLSJac1.dummyVarLSJac1 - valve_opening.$pDERLSJac1.dummyVarLSJac1
*/
void BoilerFeedwaterRatio_eqFunction_28(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,28};
  jacobian->resultVars[0] /* $res_LSJac1_1.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_VAR */ = jacobian->tmpVars[0] /* u_pi.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_TMP_VAR */ - jacobian->tmpVars[3] /* valve_opening.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_TMP_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int BoilerFeedwaterRatio_functionJacLSJac1_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = BoilerFeedwaterRatio_INDEX_JAC_LSJac1;
  
  TRACE_POP
  return 0;
}

int BoilerFeedwaterRatio_functionJacLSJac1_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = BoilerFeedwaterRatio_INDEX_JAC_LSJac1;
  BoilerFeedwaterRatio_eqFunction_25(data, threadData, jacobian, parentJacobian);
  BoilerFeedwaterRatio_eqFunction_26(data, threadData, jacobian, parentJacobian);
  BoilerFeedwaterRatio_eqFunction_27(data, threadData, jacobian, parentJacobian);
  BoilerFeedwaterRatio_eqFunction_28(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 38
type: SIMPLE_ASSIGN
ratio_error.$pDERNLSJac2.dummyVarNLSJac2 = u_pi.SeedNLSJac2 / piController.k
*/
void BoilerFeedwaterRatio_eqFunction_38(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,38};
  jacobian->tmpVars[2] /* ratio_error.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */ = DIVISION(jacobian->seedVars[0] /* u_pi.SeedNLSJac2 SEED_VAR */,(data->simulationInfo->realParameter[11] /* piController.k PARAM */),"piController.k");
  TRACE_POP
}

/*
equation index: 39
type: SIMPLE_ASSIGN
valve_opening.$pDERNLSJac2.dummyVarNLSJac2 = if u_pi > valveLimiter.uMax then 0.0 else if u_pi < valveLimiter.uMin then 0.0 else u_pi.SeedNLSJac2
*/
void BoilerFeedwaterRatio_eqFunction_39(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,39};
  modelica_boolean tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_boolean tmp10;
  modelica_real tmp11;
  tmp5 = 1.0;
  tmp6 = fabs((data->simulationInfo->realParameter[21] /* valveLimiter.uMax PARAM */));
  relationhysteresis(data, &tmp4, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */), (data->simulationInfo->realParameter[21] /* valveLimiter.uMax PARAM */), tmp5, tmp6, 1, Greater, GreaterZC);
  tmp10 = (modelica_boolean)tmp4;
  if(tmp10)
  {
    tmp11 = 0.0;
  }
  else
  {
    tmp8 = 1.0;
    tmp9 = fabs((data->simulationInfo->realParameter[22] /* valveLimiter.uMin PARAM */));
    relationhysteresis(data, &tmp7, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */), (data->simulationInfo->realParameter[22] /* valveLimiter.uMin PARAM */), tmp8, tmp9, 2, Less, LessZC);
    tmp11 = (tmp7?0.0:jacobian->seedVars[0] /* u_pi.SeedNLSJac2 SEED_VAR */);
  }
  jacobian->tmpVars[0] /* valve_opening.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */ = tmp11;
  TRACE_POP
}

/*
equation index: 40
type: SIMPLE_ASSIGN
W_feedwater.$pDERNLSJac2.dummyVarNLSJac2 = valve_opening.$pDERNLSJac2.dummyVarNLSJac2 * maxFlowConstant.k
*/
void BoilerFeedwaterRatio_eqFunction_40(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,40};
  jacobian->tmpVars[1] /* W_feedwater.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */ = (jacobian->tmpVars[0] /* valve_opening.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[8] /* maxFlowConstant.k PARAM */));
  TRACE_POP
}

/*
equation index: 41
type: SIMPLE_ASSIGN
$res_NLSJac2_1.$pDERNLSJac2.dummyVarNLSJac2 = W_feedwater.$pDERNLSJac2.dummyVarNLSJac2 + ratio_error.$pDERNLSJac2.dummyVarNLSJac2 * W_steam
*/
void BoilerFeedwaterRatio_eqFunction_41(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,41};
  jacobian->resultVars[0] /* $res_NLSJac2_1.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_VAR */ = jacobian->tmpVars[1] /* W_feedwater.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */ + (jacobian->tmpVars[2] /* ratio_error.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_TMP_VAR */) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* W_steam variable */));
  TRACE_POP
}

OMC_DISABLE_OPT
int BoilerFeedwaterRatio_functionJacNLSJac2_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = BoilerFeedwaterRatio_INDEX_JAC_NLSJac2;
  
  TRACE_POP
  return 0;
}

int BoilerFeedwaterRatio_functionJacNLSJac2_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = BoilerFeedwaterRatio_INDEX_JAC_NLSJac2;
  BoilerFeedwaterRatio_eqFunction_38(data, threadData, jacobian, parentJacobian);
  BoilerFeedwaterRatio_eqFunction_39(data, threadData, jacobian, parentJacobian);
  BoilerFeedwaterRatio_eqFunction_40(data, threadData, jacobian, parentJacobian);
  BoilerFeedwaterRatio_eqFunction_41(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
int BoilerFeedwaterRatio_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int BoilerFeedwaterRatio_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int BoilerFeedwaterRatio_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int BoilerFeedwaterRatio_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int BoilerFeedwaterRatio_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

OMC_DISABLE_OPT
int BoilerFeedwaterRatio_functionJacA_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = BoilerFeedwaterRatio_INDEX_JAC_A;
  
  TRACE_POP
  return 0;
}

int BoilerFeedwaterRatio_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = BoilerFeedwaterRatio_INDEX_JAC_A;
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int BoilerFeedwaterRatio_initialAnalyticJacobianNLSJac0(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "BoilerFeedwaterRatio_JacNLSJac0.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 5, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int BoilerFeedwaterRatio_initialAnalyticJacobianLSJac1(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "BoilerFeedwaterRatio_JacLSJac1.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 5, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int BoilerFeedwaterRatio_initialAnalyticJacobianNLSJac2(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "BoilerFeedwaterRatio_JacNLSJac2.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 5, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
int BoilerFeedwaterRatio_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int BoilerFeedwaterRatio_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int BoilerFeedwaterRatio_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int BoilerFeedwaterRatio_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int BoilerFeedwaterRatio_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
OMC_DISABLE_OPT
int BoilerFeedwaterRatio_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "BoilerFeedwaterRatio_JacA.bin");
  
  initAnalyticJacobian(jacobian, 2, 2, 0, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(2, 2, 1);
  jacobian->availability = JACOBIAN_ONLY_SPARSITY;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 2+1, pFile, FALSE);
  if (count != 2+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 2+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 2, pFile, FALSE);
  if (count != 2) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 2, count);
  }
  
  /* write color array */
  /* color 1 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 2, 2);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}



