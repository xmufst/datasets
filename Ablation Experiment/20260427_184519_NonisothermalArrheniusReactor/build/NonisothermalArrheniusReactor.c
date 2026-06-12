/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "NonisothermalArrheniusReactor_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation NonisothermalArrheniusReactor_performSimulation
#define prefixedName_updateContinuousSystem NonisothermalArrheniusReactor_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation NonisothermalArrheniusReactor_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int NonisothermalArrheniusReactor_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NonisothermalArrheniusReactor_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NonisothermalArrheniusReactor_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NonisothermalArrheniusReactor_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NonisothermalArrheniusReactor_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int NonisothermalArrheniusReactor_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NonisothermalArrheniusReactor_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NonisothermalArrheniusReactor_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NonisothermalArrheniusReactor_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NonisothermalArrheniusReactor_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 19
type: SIMPLE_ASSIGN
$cse1 = exp((-Ea) / (R * T))
*/
void NonisothermalArrheniusReactor_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* $cse1 variable */) = exp(DIVISION_SIM((-(data->simulationInfo->realParameter[0] /* Ea PARAM */)),((data->simulationInfo->realParameter[1] /* R PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T STATE(1) */)),"R * T",equationIndexes));
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
E_thermal_observed = rho * V * cp * (-330.0 + T)
*/
void NonisothermalArrheniusReactor_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* E_thermal_observed variable */) = ((data->simulationInfo->realParameter[8] /* rho PARAM */)) * (((data->simulationInfo->realParameter[4] /* V PARAM */)) * (((data->simulationInfo->realParameter[5] /* cp PARAM */)) * (-330.0 + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T STATE(1) */))));
  TRACE_POP
}
/*
equation index: 21
type: SIMPLE_ASSIGN
energy_balance_residual = E_reaction_input + (-E_cooling_output) - E_thermal_observed
*/
void NonisothermalArrheniusReactor_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* energy_balance_residual variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* E_reaction_input STATE(1,Q_reaction) */) + (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* E_cooling_output STATE(1,Q_cooling) */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* E_thermal_observed variable */);
  TRACE_POP
}
/*
equation index: 22
type: SIMPLE_ASSIGN
Q_cooling = UA * (T - T_cool)
*/
void NonisothermalArrheniusReactor_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* Q_cooling variable */) = ((data->simulationInfo->realParameter[3] /* UA PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* T STATE(1) */) - (data->simulationInfo->realParameter[2] /* T_cool PARAM */));
  TRACE_POP
}
/*
equation index: 23
type: SIMPLE_ASSIGN
$DER.E_cooling_output = Q_cooling
*/
void NonisothermalArrheniusReactor_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* der(E_cooling_output) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* Q_cooling variable */);
  TRACE_POP
}
/*
equation index: 24
type: SIMPLE_ASSIGN
mass_total = C_A + C_B
*/
void NonisothermalArrheniusReactor_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* mass_total variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* C_A STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* C_B STATE(1,r) */);
  TRACE_POP
}
/*
equation index: 25
type: SIMPLE_ASSIGN
mass_balance_residual = -1000.0 + mass_total
*/
void NonisothermalArrheniusReactor_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* mass_balance_residual variable */) = -1000.0 + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* mass_total variable */);
  TRACE_POP
}
/*
equation index: 26
type: SIMPLE_ASSIGN
k = k0 * $cse1
*/
void NonisothermalArrheniusReactor_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* k variable */) = ((data->simulationInfo->realParameter[7] /* k0 PARAM */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* $cse1 variable */));
  TRACE_POP
}
/*
equation index: 27
type: SIMPLE_ASSIGN
r = k * C_A
*/
void NonisothermalArrheniusReactor_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* r variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* k variable */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* C_A STATE(1) */));
  TRACE_POP
}
/*
equation index: 28
type: SIMPLE_ASSIGN
$DER.C_A = -r
*/
void NonisothermalArrheniusReactor_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* der(C_A) STATE_DER */) = (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* r variable */));
  TRACE_POP
}
/*
equation index: 29
type: SIMPLE_ASSIGN
$DER.C_B = r
*/
void NonisothermalArrheniusReactor_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* der(C_B) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* r variable */);
  TRACE_POP
}
/*
equation index: 30
type: SIMPLE_ASSIGN
Q_reaction = (-dH) * r * V
*/
void NonisothermalArrheniusReactor_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* Q_reaction variable */) = ((-(data->simulationInfo->realParameter[6] /* dH PARAM */))) * (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* r variable */)) * ((data->simulationInfo->realParameter[4] /* V PARAM */)));
  TRACE_POP
}
/*
equation index: 31
type: SIMPLE_ASSIGN
$DER.T = (Q_reaction - Q_cooling) / (rho * V * cp)
*/
void NonisothermalArrheniusReactor_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* der(T) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* Q_reaction variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* Q_cooling variable */),(((data->simulationInfo->realParameter[8] /* rho PARAM */)) * ((data->simulationInfo->realParameter[4] /* V PARAM */))) * ((data->simulationInfo->realParameter[5] /* cp PARAM */)),"rho * V * cp",equationIndexes);
  TRACE_POP
}
/*
equation index: 32
type: SIMPLE_ASSIGN
$DER.E_reaction_input = Q_reaction
*/
void NonisothermalArrheniusReactor_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* der(E_reaction_input) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* Q_reaction variable */);
  TRACE_POP
}

OMC_DISABLE_OPT
int NonisothermalArrheniusReactor_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  NonisothermalArrheniusReactor_functionLocalKnownVars(data, threadData);
  NonisothermalArrheniusReactor_eqFunction_19(data, threadData);

  NonisothermalArrheniusReactor_eqFunction_20(data, threadData);

  NonisothermalArrheniusReactor_eqFunction_21(data, threadData);

  NonisothermalArrheniusReactor_eqFunction_22(data, threadData);

  NonisothermalArrheniusReactor_eqFunction_23(data, threadData);

  NonisothermalArrheniusReactor_eqFunction_24(data, threadData);

  NonisothermalArrheniusReactor_eqFunction_25(data, threadData);

  NonisothermalArrheniusReactor_eqFunction_26(data, threadData);

  NonisothermalArrheniusReactor_eqFunction_27(data, threadData);

  NonisothermalArrheniusReactor_eqFunction_28(data, threadData);

  NonisothermalArrheniusReactor_eqFunction_29(data, threadData);

  NonisothermalArrheniusReactor_eqFunction_30(data, threadData);

  NonisothermalArrheniusReactor_eqFunction_31(data, threadData);

  NonisothermalArrheniusReactor_eqFunction_32(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int NonisothermalArrheniusReactor_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void NonisothermalArrheniusReactor_eqFunction_19(DATA* data, threadData_t *threadData);
extern void NonisothermalArrheniusReactor_eqFunction_22(DATA* data, threadData_t *threadData);
extern void NonisothermalArrheniusReactor_eqFunction_23(DATA* data, threadData_t *threadData);
extern void NonisothermalArrheniusReactor_eqFunction_26(DATA* data, threadData_t *threadData);
extern void NonisothermalArrheniusReactor_eqFunction_27(DATA* data, threadData_t *threadData);
extern void NonisothermalArrheniusReactor_eqFunction_28(DATA* data, threadData_t *threadData);
extern void NonisothermalArrheniusReactor_eqFunction_29(DATA* data, threadData_t *threadData);
extern void NonisothermalArrheniusReactor_eqFunction_30(DATA* data, threadData_t *threadData);
extern void NonisothermalArrheniusReactor_eqFunction_31(DATA* data, threadData_t *threadData);
extern void NonisothermalArrheniusReactor_eqFunction_32(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[10])(DATA*, threadData_t*) = {
    NonisothermalArrheniusReactor_eqFunction_19,
    NonisothermalArrheniusReactor_eqFunction_22,
    NonisothermalArrheniusReactor_eqFunction_23,
    NonisothermalArrheniusReactor_eqFunction_26,
    NonisothermalArrheniusReactor_eqFunction_27,
    NonisothermalArrheniusReactor_eqFunction_28,
    NonisothermalArrheniusReactor_eqFunction_29,
    NonisothermalArrheniusReactor_eqFunction_30,
    NonisothermalArrheniusReactor_eqFunction_31,
    NonisothermalArrheniusReactor_eqFunction_32
  };
  
  static const int eqIndices[10] = {
    19,
    22,
    23,
    26,
    27,
    28,
    29,
    30,
    31,
    32
  };
  
  for (id = 0; id < 10; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int NonisothermalArrheniusReactor_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  NonisothermalArrheniusReactor_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void NonisothermalArrheniusReactor_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
{
  TRACE_PUSH

  size_t i_real = 0;
  size_t i_integer = 0;
  size_t i_boolean = 0;
  size_t i_string = 0;

  realIndex[0] = 0;
  integerIndex[0] = 0;
  booleanIndex[0] = 0;
  stringIndex[0] = 0;

  /* stateVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* C_A STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* C_B STATE(1,r) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_cooling_output STATE(1,Q_cooling) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_reaction_input STATE(1,Q_reaction) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(C_A) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(C_B) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(E_cooling_output) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(E_reaction_input) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(T) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* $cse1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* E_thermal_observed variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_cooling variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Q_reaction variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* energy_balance_residual variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* k variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* mass_balance_residual variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* mass_total variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* r variable */
  
  /* discreteAlgVars */
  
  /* realOptimizeConstraintsVars */
  
  /* realOptimizeFinalConstraintsVars */
  
  
  /* intAlgVars */
  
  /* boolAlgVars */
  
  /* stringAlgVars */
  
  TRACE_POP
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "NonisothermalArrheniusReactor_12jac.h"
#include "NonisothermalArrheniusReactor_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks NonisothermalArrheniusReactor_callback = {
   (int (*)(DATA *, threadData_t *, void *)) NonisothermalArrheniusReactor_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) NonisothermalArrheniusReactor_performQSSSimulation,    /* performQSSSimulation */
   NonisothermalArrheniusReactor_updateContinuousSystem,    /* updateContinuousSystem */
   NonisothermalArrheniusReactor_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   NonisothermalArrheniusReactor_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   NonisothermalArrheniusReactor_initializeDAEmodeData,
   NonisothermalArrheniusReactor_computeVarIndices,
   NonisothermalArrheniusReactor_functionODE,
   NonisothermalArrheniusReactor_functionAlgebraics,
   NonisothermalArrheniusReactor_functionDAE,
   NonisothermalArrheniusReactor_functionLocalKnownVars,
   NonisothermalArrheniusReactor_input_function,
   NonisothermalArrheniusReactor_input_function_init,
   NonisothermalArrheniusReactor_input_function_updateStartValues,
   NonisothermalArrheniusReactor_data_function,
   NonisothermalArrheniusReactor_output_function,
   NonisothermalArrheniusReactor_setc_function,
   NonisothermalArrheniusReactor_setb_function,
   NonisothermalArrheniusReactor_function_storeDelayed,
   NonisothermalArrheniusReactor_function_storeSpatialDistribution,
   NonisothermalArrheniusReactor_function_initSpatialDistribution,
   NonisothermalArrheniusReactor_updateBoundVariableAttributes,
   NonisothermalArrheniusReactor_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   NonisothermalArrheniusReactor_functionRemovedInitialEquations,
   NonisothermalArrheniusReactor_updateBoundParameters,
   NonisothermalArrheniusReactor_checkForAsserts,
   NonisothermalArrheniusReactor_function_ZeroCrossingsEquations,
   NonisothermalArrheniusReactor_function_ZeroCrossings,
   NonisothermalArrheniusReactor_function_updateRelations,
   NonisothermalArrheniusReactor_zeroCrossingDescription,
   NonisothermalArrheniusReactor_relationDescription,
   NonisothermalArrheniusReactor_function_initSample,
   NonisothermalArrheniusReactor_INDEX_JAC_A,
   NonisothermalArrheniusReactor_INDEX_JAC_B,
   NonisothermalArrheniusReactor_INDEX_JAC_C,
   NonisothermalArrheniusReactor_INDEX_JAC_D,
   NonisothermalArrheniusReactor_INDEX_JAC_F,
   NonisothermalArrheniusReactor_INDEX_JAC_H,
   NonisothermalArrheniusReactor_initialAnalyticJacobianA,
   NonisothermalArrheniusReactor_initialAnalyticJacobianB,
   NonisothermalArrheniusReactor_initialAnalyticJacobianC,
   NonisothermalArrheniusReactor_initialAnalyticJacobianD,
   NonisothermalArrheniusReactor_initialAnalyticJacobianF,
   NonisothermalArrheniusReactor_initialAnalyticJacobianH,
   NonisothermalArrheniusReactor_functionJacA_column,
   NonisothermalArrheniusReactor_functionJacB_column,
   NonisothermalArrheniusReactor_functionJacC_column,
   NonisothermalArrheniusReactor_functionJacD_column,
   NonisothermalArrheniusReactor_functionJacF_column,
   NonisothermalArrheniusReactor_functionJacH_column,
   NonisothermalArrheniusReactor_linear_model_frame,
   NonisothermalArrheniusReactor_linear_model_datarecovery_frame,
   NonisothermalArrheniusReactor_mayer,
   NonisothermalArrheniusReactor_lagrange,
   NonisothermalArrheniusReactor_pickUpBoundsForInputsInOptimization,
   NonisothermalArrheniusReactor_setInputData,
   NonisothermalArrheniusReactor_getTimeGrid,
   NonisothermalArrheniusReactor_symbolicInlineSystem,
   NonisothermalArrheniusReactor_function_initSynchronous,
   NonisothermalArrheniusReactor_function_updateSynchronous,
   NonisothermalArrheniusReactor_function_equationsSynchronous,
   NonisothermalArrheniusReactor_inputNames,
   NonisothermalArrheniusReactor_dataReconciliationInputNames,
   NonisothermalArrheniusReactor_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "NonisothermalArrheniusReactor"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/Desktop/实验组4/cases/20260427_184519_NonisothermalArrheniusReactor/build/src"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,29,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,93,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void NonisothermalArrheniusReactor_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &NonisothermalArrheniusReactor_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "NonisothermalArrheniusReactor";
  data->modelData->modelFilePrefix = "NonisothermalArrheniusReactor";
  data->modelData->modelFileName = "NonisothermalArrheniusReactor.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/实验组4/cases/20260427_184519_NonisothermalArrheniusReactor/build/src";
  data->modelData->modelGUID = "{db4f6a3a-2edd-407e-a2cb-3851930d8eda}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "NonisothermalArrheniusReactor_init.c"
    ;
  static const char contents_info[] =
    #include "NonisothermalArrheniusReactor_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "NonisothermalArrheniusReactor_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "NonisothermalArrheniusReactor_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "NonisothermalArrheniusReactor_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 5;
  data->modelData->nVariablesRealArray = 19;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 9;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 33;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 6;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  data->modelData->nDelayExpressions = 0;
  data->modelData->nBaseClocks = 0;
  data->modelData->nSpatialDistributions = 0;
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
  data->modelData->nSetcVars = 0;
  data->modelData->ndataReconVars = 0;
  data->modelData->nSetbVars = 0;
  data->modelData->nRelatedBoundaryConditions = 0;
  data->modelData->linearizationDumpLanguage = OMC_LINEARIZE_DUMP_LANGUAGE_MODELICA;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}


#if defined(__MINGW32__) || defined(_MSC_VER)

#if !defined(_UNICODE)
#define _UNICODE
#endif
#if !defined(UNICODE)
#define UNICODE
#endif

#include <windows.h>
char** omc_fixWindowsArgv(int argc, wchar_t **wargv)
{
  char** newargv;
  /* Support for non-ASCII characters
  * Read the unicode command line arguments and translate it to char*
  */
  newargv = (char**)malloc(argc*sizeof(char*));
  for (int i = 0; i < argc; i++) {
    newargv[i] = omc_wchar_to_multibyte_str(wargv[i]);
  }
  return newargv;
}

#define OMC_MAIN wmain
#define OMC_CHAR wchar_t
#define OMC_EXPORT __declspec(dllexport) extern

#else
#define omc_fixWindowsArgv(N, A) (A)
#define OMC_MAIN main
#define OMC_CHAR char
#define OMC_EXPORT extern
#endif

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
#if defined(OMC_DLL_MAIN_DEFINE)
OMC_EXPORT int omcDllMain(int argc, OMC_CHAR **argv)
#else
int OMC_MAIN(int argc, OMC_CHAR** argv)
#endif
{
  char** newargv = omc_fixWindowsArgv(argc, argv);
  /*
    Set the error functions to be used for simulation.
    The default value for them is 'functions' version. Change it here to 'simulation' versions
  */
  omc_assert = omc_assert_simulation;
  omc_assert_withEquationIndexes = omc_assert_simulation_withEquationIndexes;

  omc_assert_warning_withEquationIndexes = omc_assert_warning_simulation_withEquationIndexes;
  omc_assert_warning = omc_assert_warning_simulation;
  omc_terminate = omc_terminate_simulation;
  omc_throw = omc_throw_simulation;

  int res;
  DATA data;
  MODEL_DATA modelData;
  SIMULATION_INFO simInfo;
  data.modelData = &modelData;
  data.simulationInfo = &simInfo;
  measure_time_flag = 0;
  compiledInDAEMode = 0;
  compiledWithSymSolver = 0;
  MMC_INIT(0);
  omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    NonisothermalArrheniusReactor_setupDataStruc(&data, threadData);
    res = _main_initRuntimeAndSimulation(argc, newargv, &data, threadData);
    if(res == 0) {
      res = _main_SimulationRuntime(argc, newargv, &data, threadData);
    }
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
  return res;
}

#ifdef __cplusplus
}
#endif


