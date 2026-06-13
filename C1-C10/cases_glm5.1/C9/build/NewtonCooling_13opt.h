#if defined(__cplusplus)
  extern "C" {
#endif
  int NewtonCooling_mayer(DATA* data, modelica_real** res, short*);
  int NewtonCooling_lagrange(DATA* data, modelica_real** res, short *, short *);
  int NewtonCooling_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int NewtonCooling_setInputData(DATA *data, const modelica_boolean file);
  int NewtonCooling_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif