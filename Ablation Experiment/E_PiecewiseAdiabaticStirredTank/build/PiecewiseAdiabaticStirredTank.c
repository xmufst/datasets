/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "PiecewiseAdiabaticStirredTank_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation PiecewiseAdiabaticStirredTank_performSimulation
#define prefixedName_updateContinuousSystem PiecewiseAdiabaticStirredTank_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation PiecewiseAdiabaticStirredTank_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int PiecewiseAdiabaticStirredTank_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int PiecewiseAdiabaticStirredTank_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int PiecewiseAdiabaticStirredTank_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int PiecewiseAdiabaticStirredTank_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int PiecewiseAdiabaticStirredTank_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int PiecewiseAdiabaticStirredTank_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int PiecewiseAdiabaticStirredTank_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int PiecewiseAdiabaticStirredTank_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int PiecewiseAdiabaticStirredTank_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int PiecewiseAdiabaticStirredTank_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 10
type: SIMPLE_ASSIGN
energy_stored = m_liquid * cp_liquid * (-293.15 + T_liquid)
*/
void PiecewiseAdiabaticStirredTank_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* energy_stored variable */) = ((data->simulationInfo->realParameter[4] /* m_liquid PARAM */)) * (((data->simulationInfo->realParameter[3] /* cp_liquid PARAM */)) * (-293.15 + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_liquid STATE(1,dTdt_theoretical) */)));
  TRACE_POP
}
/*
equation index: 11
type: SIMPLE_ASSIGN
energy_residual = energy_added - energy_stored
*/
void PiecewiseAdiabaticStirredTank_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* energy_residual variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* energy_added STATE(1,P_stir) */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* energy_stored variable */);
  TRACE_POP
}
/*
equation index: 12
type: SIMPLE_ASSIGN
T_liquid_C = -273.15 + T_liquid
*/
void PiecewiseAdiabaticStirredTank_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* T_liquid_C variable */) = -273.15 + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* T_liquid STATE(1,dTdt_theoretical) */);
  TRACE_POP
}
/*
equation index: 13
type: SIMPLE_ASSIGN
P_stir = if noEvent(time < t_end_phase1) then P_stir_phase1 else if noEvent(time < t_end_phase2) then P_stir_phase2 else P_stir_phase3
*/
void PiecewiseAdiabaticStirredTank_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Less(data->localData[0]->timeValue,(data->simulationInfo->realParameter[5] /* t_end_phase1 PARAM */));
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = (data->simulationInfo->realParameter[0] /* P_stir_phase1 PARAM */);
  }
  else
  {
    tmp1 = Less(data->localData[0]->timeValue,(data->simulationInfo->realParameter[6] /* t_end_phase2 PARAM */));
    tmp3 = (tmp1?(data->simulationInfo->realParameter[1] /* P_stir_phase2 PARAM */):(data->simulationInfo->realParameter[2] /* P_stir_phase3 PARAM */));
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* P_stir variable */) = tmp3;
  TRACE_POP
}
/*
equation index: 14
type: SIMPLE_ASSIGN
dTdt_theoretical = P_stir / (cp_liquid * m_liquid)
*/
void PiecewiseAdiabaticStirredTank_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* dTdt_theoretical variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* P_stir variable */),((data->simulationInfo->realParameter[3] /* cp_liquid PARAM */)) * ((data->simulationInfo->realParameter[4] /* m_liquid PARAM */)),"cp_liquid * m_liquid",equationIndexes);
  TRACE_POP
}
/*
equation index: 15
type: SIMPLE_ASSIGN
$DER.T_liquid = dTdt_theoretical
*/
void PiecewiseAdiabaticStirredTank_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* der(T_liquid) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* dTdt_theoretical variable */);
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
$DER.energy_added = P_stir
*/
void PiecewiseAdiabaticStirredTank_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* der(energy_added) STATE_DER */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* P_stir variable */);
  TRACE_POP
}

OMC_DISABLE_OPT
int PiecewiseAdiabaticStirredTank_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  PiecewiseAdiabaticStirredTank_functionLocalKnownVars(data, threadData);
  PiecewiseAdiabaticStirredTank_eqFunction_10(data, threadData);

  PiecewiseAdiabaticStirredTank_eqFunction_11(data, threadData);

  PiecewiseAdiabaticStirredTank_eqFunction_12(data, threadData);

  PiecewiseAdiabaticStirredTank_eqFunction_13(data, threadData);

  PiecewiseAdiabaticStirredTank_eqFunction_14(data, threadData);

  PiecewiseAdiabaticStirredTank_eqFunction_15(data, threadData);

  PiecewiseAdiabaticStirredTank_eqFunction_16(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int PiecewiseAdiabaticStirredTank_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void PiecewiseAdiabaticStirredTank_eqFunction_13(DATA* data, threadData_t *threadData);
extern void PiecewiseAdiabaticStirredTank_eqFunction_14(DATA* data, threadData_t *threadData);
extern void PiecewiseAdiabaticStirredTank_eqFunction_15(DATA* data, threadData_t *threadData);
extern void PiecewiseAdiabaticStirredTank_eqFunction_16(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[4])(DATA*, threadData_t*) = {
    PiecewiseAdiabaticStirredTank_eqFunction_13,
    PiecewiseAdiabaticStirredTank_eqFunction_14,
    PiecewiseAdiabaticStirredTank_eqFunction_15,
    PiecewiseAdiabaticStirredTank_eqFunction_16
  };
  
  static const int eqIndices[4] = {
    13,
    14,
    15,
    16
  };
  
  for (id = 0; id < 4; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int PiecewiseAdiabaticStirredTank_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  PiecewiseAdiabaticStirredTank_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void PiecewiseAdiabaticStirredTank_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
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
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_liquid STATE(1,dTdt_theoretical) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* energy_added STATE(1,P_stir) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(T_liquid) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(energy_added) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* P_stir variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* T_liquid_C variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* dTdt_theoretical variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* energy_residual variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* energy_stored variable */
  
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

#include "PiecewiseAdiabaticStirredTank_12jac.h"
#include "PiecewiseAdiabaticStirredTank_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks PiecewiseAdiabaticStirredTank_callback = {
   (int (*)(DATA *, threadData_t *, void *)) PiecewiseAdiabaticStirredTank_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) PiecewiseAdiabaticStirredTank_performQSSSimulation,    /* performQSSSimulation */
   PiecewiseAdiabaticStirredTank_updateContinuousSystem,    /* updateContinuousSystem */
   PiecewiseAdiabaticStirredTank_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   PiecewiseAdiabaticStirredTank_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   PiecewiseAdiabaticStirredTank_initializeDAEmodeData,
   PiecewiseAdiabaticStirredTank_computeVarIndices,
   PiecewiseAdiabaticStirredTank_functionODE,
   PiecewiseAdiabaticStirredTank_functionAlgebraics,
   PiecewiseAdiabaticStirredTank_functionDAE,
   PiecewiseAdiabaticStirredTank_functionLocalKnownVars,
   PiecewiseAdiabaticStirredTank_input_function,
   PiecewiseAdiabaticStirredTank_input_function_init,
   PiecewiseAdiabaticStirredTank_input_function_updateStartValues,
   PiecewiseAdiabaticStirredTank_data_function,
   PiecewiseAdiabaticStirredTank_output_function,
   PiecewiseAdiabaticStirredTank_setc_function,
   PiecewiseAdiabaticStirredTank_setb_function,
   PiecewiseAdiabaticStirredTank_function_storeDelayed,
   PiecewiseAdiabaticStirredTank_function_storeSpatialDistribution,
   PiecewiseAdiabaticStirredTank_function_initSpatialDistribution,
   PiecewiseAdiabaticStirredTank_updateBoundVariableAttributes,
   PiecewiseAdiabaticStirredTank_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   PiecewiseAdiabaticStirredTank_functionRemovedInitialEquations,
   PiecewiseAdiabaticStirredTank_updateBoundParameters,
   PiecewiseAdiabaticStirredTank_checkForAsserts,
   PiecewiseAdiabaticStirredTank_function_ZeroCrossingsEquations,
   PiecewiseAdiabaticStirredTank_function_ZeroCrossings,
   PiecewiseAdiabaticStirredTank_function_updateRelations,
   PiecewiseAdiabaticStirredTank_zeroCrossingDescription,
   PiecewiseAdiabaticStirredTank_relationDescription,
   PiecewiseAdiabaticStirredTank_function_initSample,
   PiecewiseAdiabaticStirredTank_INDEX_JAC_A,
   PiecewiseAdiabaticStirredTank_INDEX_JAC_B,
   PiecewiseAdiabaticStirredTank_INDEX_JAC_C,
   PiecewiseAdiabaticStirredTank_INDEX_JAC_D,
   PiecewiseAdiabaticStirredTank_INDEX_JAC_F,
   PiecewiseAdiabaticStirredTank_INDEX_JAC_H,
   PiecewiseAdiabaticStirredTank_initialAnalyticJacobianA,
   PiecewiseAdiabaticStirredTank_initialAnalyticJacobianB,
   PiecewiseAdiabaticStirredTank_initialAnalyticJacobianC,
   PiecewiseAdiabaticStirredTank_initialAnalyticJacobianD,
   PiecewiseAdiabaticStirredTank_initialAnalyticJacobianF,
   PiecewiseAdiabaticStirredTank_initialAnalyticJacobianH,
   PiecewiseAdiabaticStirredTank_functionJacA_column,
   PiecewiseAdiabaticStirredTank_functionJacB_column,
   PiecewiseAdiabaticStirredTank_functionJacC_column,
   PiecewiseAdiabaticStirredTank_functionJacD_column,
   PiecewiseAdiabaticStirredTank_functionJacF_column,
   PiecewiseAdiabaticStirredTank_functionJacH_column,
   PiecewiseAdiabaticStirredTank_linear_model_frame,
   PiecewiseAdiabaticStirredTank_linear_model_datarecovery_frame,
   PiecewiseAdiabaticStirredTank_mayer,
   PiecewiseAdiabaticStirredTank_lagrange,
   PiecewiseAdiabaticStirredTank_pickUpBoundsForInputsInOptimization,
   PiecewiseAdiabaticStirredTank_setInputData,
   PiecewiseAdiabaticStirredTank_getTimeGrid,
   PiecewiseAdiabaticStirredTank_symbolicInlineSystem,
   PiecewiseAdiabaticStirredTank_function_initSynchronous,
   PiecewiseAdiabaticStirredTank_function_updateSynchronous,
   PiecewiseAdiabaticStirredTank_function_equationsSynchronous,
   PiecewiseAdiabaticStirredTank_inputNames,
   PiecewiseAdiabaticStirredTank_dataReconciliationInputNames,
   PiecewiseAdiabaticStirredTank_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "PiecewiseAdiabaticStirredTank"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/FST/Desktop/实验组2/cases/20260427_205711_PiecewiseAdiabaticStirredTank/build/src"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,29,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,93,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void PiecewiseAdiabaticStirredTank_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &PiecewiseAdiabaticStirredTank_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "PiecewiseAdiabaticStirredTank";
  data->modelData->modelFilePrefix = "PiecewiseAdiabaticStirredTank";
  data->modelData->modelFileName = "PiecewiseAdiabaticStirredTank.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/FST/Desktop/实验组2/cases/20260427_205711_PiecewiseAdiabaticStirredTank/build/src";
  data->modelData->modelGUID = "{4bbee995-ecbc-4a47-bb69-24fc00ebf3ed}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "PiecewiseAdiabaticStirredTank_init.c"
    ;
  static const char contents_info[] =
    #include "PiecewiseAdiabaticStirredTank_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "PiecewiseAdiabaticStirredTank_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "PiecewiseAdiabaticStirredTank_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "PiecewiseAdiabaticStirredTank_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 2;
  data->modelData->nVariablesRealArray = 9;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 0;
  data->modelData->nVariablesBooleanArray = 0;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 7;
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
  data->modelData->modelDataXml.nEquations = 17;
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
  
    PiecewiseAdiabaticStirredTank_setupDataStruc(&data, threadData);
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


