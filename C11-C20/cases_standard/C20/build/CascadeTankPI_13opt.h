#if defined(__cplusplus)
  extern "C" {
#endif
  int CascadeTankPI_mayer(DATA* data, modelica_real** res, short*);
  int CascadeTankPI_lagrange(DATA* data, modelica_real** res, short *, short *);
  int CascadeTankPI_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int CascadeTankPI_setInputData(DATA *data, const modelica_boolean file);
  int CascadeTankPI_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif