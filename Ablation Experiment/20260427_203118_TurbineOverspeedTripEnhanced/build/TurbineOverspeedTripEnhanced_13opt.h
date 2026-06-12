#if defined(__cplusplus)
  extern "C" {
#endif
  int TurbineOverspeedTripEnhanced_mayer(DATA* data, modelica_real** res, short*);
  int TurbineOverspeedTripEnhanced_lagrange(DATA* data, modelica_real** res, short *, short *);
  int TurbineOverspeedTripEnhanced_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int TurbineOverspeedTripEnhanced_setInputData(DATA *data, const modelica_boolean file);
  int TurbineOverspeedTripEnhanced_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif