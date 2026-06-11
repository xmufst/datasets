#if defined(__cplusplus)
  extern "C" {
#endif
  int GravityTank_mayer(DATA* data, modelica_real** res, short*);
  int GravityTank_lagrange(DATA* data, modelica_real** res, short *, short *);
  int GravityTank_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int GravityTank_setInputData(DATA *data, const modelica_boolean file);
  int GravityTank_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif