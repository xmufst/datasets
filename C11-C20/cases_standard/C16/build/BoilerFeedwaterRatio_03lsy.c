/* Linear Systems */
#include "BoilerFeedwaterRatio_model.h"
#include "BoilerFeedwaterRatio_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* linear systems */

/*
equation index: 19
type: SIMPLE_ASSIGN
u_pi = piController.k * (piController.x + ratio_error)
*/
void BoilerFeedwaterRatio_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */) = ((data->simulationInfo->realParameter[9] /* piController.k PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* piController.x STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* ratio_error variable */));
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
ratio_actual = ratioSetpoint.k - ratio_error
*/
void BoilerFeedwaterRatio_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* ratio_actual variable */) = (data->simulationInfo->realParameter[13] /* ratioSetpoint.k PARAM */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* ratio_error variable */);
  TRACE_POP
}
/*
equation index: 21
type: SIMPLE_ASSIGN
W_feedwater = ratio_actual * W_steam
*/
void BoilerFeedwaterRatio_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* W_feedwater variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* ratio_actual variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* W_steam variable */));
  TRACE_POP
}
/*
equation index: 22
type: SIMPLE_ASSIGN
valve_opening = W_feedwater / K_fw
*/
void BoilerFeedwaterRatio_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* valve_opening variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* W_feedwater variable */),(data->simulationInfo->realParameter[1] /* K_fw PARAM */),"K_fw",equationIndexes);
  TRACE_POP
}

void residualFunc28(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,28};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* ratio_error variable */) = xloc[0];
  /* local constraints */
  BoilerFeedwaterRatio_eqFunction_19(data, threadData);

  /* local constraints */
  BoilerFeedwaterRatio_eqFunction_20(data, threadData);

  /* local constraints */
  BoilerFeedwaterRatio_eqFunction_21(data, threadData);

  /* local constraints */
  BoilerFeedwaterRatio_eqFunction_22(data, threadData);
  res[0] = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* u_pi variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* valve_opening variable */);
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData28(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  const int indices[1] = {
    7 /* ratio_error */
  };
  for (int i = 0; i < 1; ++i) {
    linearSystemData->nominal[i] = data->modelData->realVarsData[indices[i]].attribute.nominal;
    linearSystemData->min[i]     = data->modelData->realVarsData[indices[i]].attribute.min;
    linearSystemData->max[i]     = data->modelData->realVarsData[indices[i]].attribute.max;
  }
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize linear systems */
void BoilerFeedwaterRatio_initialLinearSystem(int nLinearSystems, LINEAR_SYSTEM_DATA* linearSystemData)
{
  /* linear systems */
  assertStreamPrint(NULL, nLinearSystems > 0, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[0].equationIndex = 28;
  linearSystemData[0].size = 1;
  linearSystemData[0].nnz = 0;
  linearSystemData[0].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[0].residualFunc = residualFunc28;
  linearSystemData[0].strictTearingFunctionCall = NULL;
  linearSystemData[0].analyticalJacobianColumn = BoilerFeedwaterRatio_functionJacLSJac1_column;
  linearSystemData[0].initialAnalyticalJacobian = BoilerFeedwaterRatio_initialAnalyticJacobianLSJac1;
  linearSystemData[0].jacobianIndex = 1 /*jacInx*/;
  linearSystemData[0].setA = NULL;  //setLinearMatrixA28;
  linearSystemData[0].setb = NULL;  //setLinearVectorb28;
  linearSystemData[0].initializeStaticLSData = initializeStaticLSData28;
}

#if defined(__cplusplus)
}
#endif

