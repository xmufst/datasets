#if defined(__cplusplus)
  extern "C" {
#endif
  int ForcedDampedOscillator_mayer(DATA* data, modelica_real** res, short*);
  int ForcedDampedOscillator_lagrange(DATA* data, modelica_real** res, short *, short *);
  int ForcedDampedOscillator_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int ForcedDampedOscillator_setInputData(DATA *data, const modelica_boolean file);
  int ForcedDampedOscillator_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif