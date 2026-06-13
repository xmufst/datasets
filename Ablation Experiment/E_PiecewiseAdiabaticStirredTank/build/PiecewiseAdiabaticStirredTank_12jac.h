/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;

#if defined(__cplusplus)
extern "C" {
#endif

/* Jacobian Variables */
#define PiecewiseAdiabaticStirredTank_INDEX_JAC_H 0
int PiecewiseAdiabaticStirredTank_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int PiecewiseAdiabaticStirredTank_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define PiecewiseAdiabaticStirredTank_INDEX_JAC_F 1
int PiecewiseAdiabaticStirredTank_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int PiecewiseAdiabaticStirredTank_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define PiecewiseAdiabaticStirredTank_INDEX_JAC_D 2
int PiecewiseAdiabaticStirredTank_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int PiecewiseAdiabaticStirredTank_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define PiecewiseAdiabaticStirredTank_INDEX_JAC_C 3
int PiecewiseAdiabaticStirredTank_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int PiecewiseAdiabaticStirredTank_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define PiecewiseAdiabaticStirredTank_INDEX_JAC_B 4
int PiecewiseAdiabaticStirredTank_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int PiecewiseAdiabaticStirredTank_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define PiecewiseAdiabaticStirredTank_INDEX_JAC_A 5
int PiecewiseAdiabaticStirredTank_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int PiecewiseAdiabaticStirredTank_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);

#if defined(__cplusplus)
}
#endif

