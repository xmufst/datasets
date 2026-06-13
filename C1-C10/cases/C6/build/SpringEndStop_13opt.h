#if defined(__cplusplus)
  extern "C" {
#endif
  int SpringEndStop_mayer(DATA* data, modelica_real** res, short*);
  int SpringEndStop_lagrange(DATA* data, modelica_real** res, short *, short *);
  int SpringEndStop_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int SpringEndStop_setInputData(DATA *data, const modelica_boolean file);
  int SpringEndStop_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif