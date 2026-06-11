#if defined(__cplusplus)
  extern "C" {
#endif
  int TankLevelPI_mayer(DATA* data, modelica_real** res, short*);
  int TankLevelPI_lagrange(DATA* data, modelica_real** res, short *, short *);
  int TankLevelPI_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int TankLevelPI_setInputData(DATA *data, const modelica_boolean file);
  int TankLevelPI_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif