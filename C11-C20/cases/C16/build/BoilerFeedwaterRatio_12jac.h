/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;

#if defined(__cplusplus)
extern "C" {
#endif

/* Jacobian Variables */
#define BoilerFeedwaterRatio_INDEX_JAC_NLSJac0 0
int BoilerFeedwaterRatio_functionJacNLSJac0_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int BoilerFeedwaterRatio_initialAnalyticJacobianNLSJac0(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define BoilerFeedwaterRatio_INDEX_JAC_LSJac1 1
int BoilerFeedwaterRatio_functionJacLSJac1_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int BoilerFeedwaterRatio_initialAnalyticJacobianLSJac1(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define BoilerFeedwaterRatio_INDEX_JAC_NLSJac2 2
int BoilerFeedwaterRatio_functionJacNLSJac2_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int BoilerFeedwaterRatio_initialAnalyticJacobianNLSJac2(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define BoilerFeedwaterRatio_INDEX_JAC_H 3
int BoilerFeedwaterRatio_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int BoilerFeedwaterRatio_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define BoilerFeedwaterRatio_INDEX_JAC_F 4
int BoilerFeedwaterRatio_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int BoilerFeedwaterRatio_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define BoilerFeedwaterRatio_INDEX_JAC_D 5
int BoilerFeedwaterRatio_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int BoilerFeedwaterRatio_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define BoilerFeedwaterRatio_INDEX_JAC_C 6
int BoilerFeedwaterRatio_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int BoilerFeedwaterRatio_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define BoilerFeedwaterRatio_INDEX_JAC_B 7
int BoilerFeedwaterRatio_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int BoilerFeedwaterRatio_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define BoilerFeedwaterRatio_INDEX_JAC_A 8
int BoilerFeedwaterRatio_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int BoilerFeedwaterRatio_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);

#if defined(__cplusplus)
}
#endif

