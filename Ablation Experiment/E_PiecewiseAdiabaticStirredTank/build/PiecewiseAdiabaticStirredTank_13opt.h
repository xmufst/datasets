#if defined(__cplusplus)
  extern "C" {
#endif
  int PiecewiseAdiabaticStirredTank_mayer(DATA* data, modelica_real** res, short*);
  int PiecewiseAdiabaticStirredTank_lagrange(DATA* data, modelica_real** res, short *, short *);
  int PiecewiseAdiabaticStirredTank_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int PiecewiseAdiabaticStirredTank_setInputData(DATA *data, const modelica_boolean file);
  int PiecewiseAdiabaticStirredTank_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif