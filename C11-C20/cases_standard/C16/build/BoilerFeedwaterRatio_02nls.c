/* Non Linear Systems */
#include "BoilerFeedwaterRatio_model.h"
#include "BoilerFeedwaterRatio_12jac.h"
#include "simulation/jacobian_util.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* inner equations */

/*
equation index: 3
type: SIMPLE_ASSIGN
valve_opening = homotopy(smooth(0, if u_pi > valveLimiter.uMax then valveLimiter.uMax else if u_pi < valveLimiter.uMin then valveLimiter.uMin else u_pi), u_pi)
*/
void BoilerFeedwaterRatio_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */),(data->simulationInfo->realParameter[19] /* valveLimiter.uMax PARAM */));
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = (data->simulationInfo->realParameter[19] /* valveLimiter.uMax PARAM */);
  }
  else
  {
    tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */),(data->simulationInfo->realParameter[20] /* valveLimiter.uMin PARAM */));
    tmp3 = (tmp1?(data->simulationInfo->realParameter[20] /* valveLimiter.uMin PARAM */):(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */));
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* valve_opening variable */) = homotopy(tmp3, (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */));
  TRACE_POP
}
/*
equation index: 4
type: SIMPLE_ASSIGN
ratio_error = u_pi / piController.k - piController.x
*/
void BoilerFeedwaterRatio_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* ratio_error variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */),(data->simulationInfo->realParameter[9] /* piController.k PARAM */),"piController.k",equationIndexes) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piController.x STATE(1) */);
  TRACE_POP
}
/*
equation index: 5
type: SIMPLE_ASSIGN
W_feedwater = K_fw * valve_opening
*/
void BoilerFeedwaterRatio_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* W_feedwater variable */) = ((data->simulationInfo->realParameter[1] /* K_fw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* valve_opening variable */));
  TRACE_POP
}
/*
equation index: 6
type: SIMPLE_ASSIGN
ratio_actual = ratioSetpoint.k - ratio_error
*/
void BoilerFeedwaterRatio_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* ratio_actual variable */) = (data->simulationInfo->realParameter[13] /* ratioSetpoint.k PARAM */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* ratio_error variable */);
  TRACE_POP
}

void residualFunc12(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,12};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(OMC_LOG_NLS, 0, "residualFunc12: Iteration variable `%s` is inf or nan.",
        modelInfoGetEquation(&data->modelData->modelDataXml, 12).vars[i]);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc12 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  BoilerFeedwaterRatio_eqFunction_3(data, threadData);

  /* local constraints */
  BoilerFeedwaterRatio_eqFunction_4(data, threadData);

  /* local constraints */
  BoilerFeedwaterRatio_eqFunction_5(data, threadData);

  /* local constraints */
  BoilerFeedwaterRatio_eqFunction_6(data, threadData);
  /* body */
  res[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* W_feedwater variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* ratio_actual variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* W_steam variable */)));
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS12(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}

void freeSparsePatternNLS12(NONLINEAR_SYSTEM_DATA* inSysData)
{
  if (inSysData->isPatternAvailable) {
    freeSparsePattern(inSysData->sparsePattern);
    free(inSysData->sparsePattern);
    inSysData->sparsePattern = NULL;
    inSysData->isPatternAvailable = FALSE;
  }
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS12(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 1;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(1*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,1};
  const int index_eqn[1+1] = {0,1};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[1] = {0};
  const int rows[1] = {0};
  memcpy(inSysData->nonlinearPattern->columns, columns, 1*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 1*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS12(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for u_pi */
  sysData->nominal[i] = data->modelData->realVarsData[8].attribute /* u_pi */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[8].attribute /* u_pi */.min;
  sysData->max[i++]   = data->modelData->realVarsData[8].attribute /* u_pi */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS12(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS12(sysData);
  }
}

OMC_DISABLE_OPT
void freeStaticDataNLS12(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData)
{
  freeSparsePatternNLS12(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS12(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */);
}


/* inner equations */

/*
equation index: 33
type: SIMPLE_ASSIGN
valve_opening = smooth(0, if u_pi > valveLimiter.uMax then valveLimiter.uMax else if u_pi < valveLimiter.uMin then valveLimiter.uMin else u_pi)
*/
void BoilerFeedwaterRatio_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Greater((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */),(data->simulationInfo->realParameter[19] /* valveLimiter.uMax PARAM */));
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = (data->simulationInfo->realParameter[19] /* valveLimiter.uMax PARAM */);
  }
  else
  {
    tmp1 = Less((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */),(data->simulationInfo->realParameter[20] /* valveLimiter.uMin PARAM */));
    tmp3 = (tmp1?(data->simulationInfo->realParameter[20] /* valveLimiter.uMin PARAM */):(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */));
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* valve_opening variable */) = tmp3;
  TRACE_POP
}
/*
equation index: 34
type: SIMPLE_ASSIGN
W_feedwater = K_fw * valve_opening
*/
void BoilerFeedwaterRatio_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* W_feedwater variable */) = ((data->simulationInfo->realParameter[1] /* K_fw PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* valve_opening variable */));
  TRACE_POP
}
/*
equation index: 35
type: SIMPLE_ASSIGN
ratio_error = u_pi / piController.k - piController.x
*/
void BoilerFeedwaterRatio_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* ratio_error variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */),(data->simulationInfo->realParameter[9] /* piController.k PARAM */),"piController.k",equationIndexes) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piController.x STATE(1) */);
  TRACE_POP
}
/*
equation index: 36
type: SIMPLE_ASSIGN
ratio_actual = ratioSetpoint.k - ratio_error
*/
void BoilerFeedwaterRatio_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* ratio_actual variable */) = (data->simulationInfo->realParameter[13] /* ratioSetpoint.k PARAM */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* ratio_error variable */);
  TRACE_POP
}

void residualFunc42(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,42};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(OMC_LOG_NLS, 0, "residualFunc42: Iteration variable `%s` is inf or nan.",
        modelInfoGetEquation(&data->modelData->modelDataXml, 42).vars[i]);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc42 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  BoilerFeedwaterRatio_eqFunction_33(data, threadData);

  /* local constraints */
  BoilerFeedwaterRatio_eqFunction_34(data, threadData);

  /* local constraints */
  BoilerFeedwaterRatio_eqFunction_35(data, threadData);

  /* local constraints */
  BoilerFeedwaterRatio_eqFunction_36(data, threadData);
  /* body */
  res[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* W_feedwater variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* ratio_actual variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* W_steam variable */)));
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS42(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}

void freeSparsePatternNLS42(NONLINEAR_SYSTEM_DATA* inSysData)
{
  if (inSysData->isPatternAvailable) {
    freeSparsePattern(inSysData->sparsePattern);
    free(inSysData->sparsePattern);
    inSysData->sparsePattern = NULL;
    inSysData->isPatternAvailable = FALSE;
  }
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS42(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 1;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(1*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,1};
  const int index_eqn[1+1] = {0,1};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[1] = {0};
  const int rows[1] = {0};
  memcpy(inSysData->nonlinearPattern->columns, columns, 1*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 1*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS42(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for u_pi */
  sysData->nominal[i] = data->modelData->realVarsData[8].attribute /* u_pi */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[8].attribute /* u_pi */.min;
  sysData->max[i++]   = data->modelData->realVarsData[8].attribute /* u_pi */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS42(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS42(sysData);
  }
}

OMC_DISABLE_OPT
void freeStaticDataNLS42(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData)
{
  freeSparsePatternNLS42(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS42(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */);
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize non-linear systems */
void BoilerFeedwaterRatio_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA* nonLinearSystemData)
{
  
  nonLinearSystemData[1].equationIndex = 42;
  nonLinearSystemData[1].size = 1;
  nonLinearSystemData[1].homotopySupport = 0 /* false */;
  nonLinearSystemData[1].mixedSystem = 1 /* true */;
  nonLinearSystemData[1].residualFunc = residualFunc42;
  nonLinearSystemData[1].strictTearingFunctionCall = NULL;
  nonLinearSystemData[1].analyticalJacobianColumn = BoilerFeedwaterRatio_functionJacNLSJac2_column;
  nonLinearSystemData[1].initialAnalyticalJacobian = BoilerFeedwaterRatio_initialAnalyticJacobianNLSJac2;
  nonLinearSystemData[1].jacobianIndex = 2 /*jacInx*/;
  nonLinearSystemData[1].initializeStaticNLSData = initializeStaticDataNLS42;
  nonLinearSystemData[1].freeStaticNLSData = freeStaticDataNLS42;
  nonLinearSystemData[1].getIterationVars = getIterationVarsNLS42;
  nonLinearSystemData[1].checkConstraints = NULL;
  
  const int tmp_eqn_indices_1[5] = {33, 34, 35, 36, 37};
  nonLinearSystemData[1].eqn_simcode_indices = malloc(5 * sizeof(int));
  memcpy(nonLinearSystemData[1].eqn_simcode_indices, tmp_eqn_indices_1, 5 * sizeof(int));
  
  
  nonLinearSystemData[0].equationIndex = 12;
  nonLinearSystemData[0].size = 1;
  nonLinearSystemData[0].homotopySupport = 1 /* true */;
  nonLinearSystemData[0].mixedSystem = 1 /* true */;
  nonLinearSystemData[0].residualFunc = residualFunc12;
  nonLinearSystemData[0].strictTearingFunctionCall = NULL;
  nonLinearSystemData[0].analyticalJacobianColumn = BoilerFeedwaterRatio_functionJacNLSJac0_column;
  nonLinearSystemData[0].initialAnalyticalJacobian = BoilerFeedwaterRatio_initialAnalyticJacobianNLSJac0;
  nonLinearSystemData[0].jacobianIndex = 0 /*jacInx*/;
  nonLinearSystemData[0].initializeStaticNLSData = initializeStaticDataNLS12;
  nonLinearSystemData[0].freeStaticNLSData = freeStaticDataNLS12;
  nonLinearSystemData[0].getIterationVars = getIterationVarsNLS12;
  nonLinearSystemData[0].checkConstraints = NULL;
  
  const int tmp_eqn_indices_0[5] = {3, 4, 5, 6, 7};
  nonLinearSystemData[0].eqn_simcode_indices = malloc(5 * sizeof(int));
  memcpy(nonLinearSystemData[0].eqn_simcode_indices, tmp_eqn_indices_0, 5 * sizeof(int));
}

#if defined(__cplusplus)
}
#endif

