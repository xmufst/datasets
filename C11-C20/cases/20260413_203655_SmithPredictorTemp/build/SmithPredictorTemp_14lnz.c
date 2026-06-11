/* Linearization */
#include "SmithPredictorTemp_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *SmithPredictorTemp_linear_model_frame()
{
  return "model linearized_model \"SmithPredictorTemp\"\n"
  "  parameter Integer n = 3 \"number of states\";\n"
  "  parameter Integer m = 0 \"number of inputs\";\n"
  "  parameter Integer p = 0 \"number of outputs\";\n"
  "\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[m] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] = zeros(p, m);%s\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m];\n"
  "  output Real y[p];\n"
  "\n"
  "  Real 'x_T_model' = x[1];\n"
  "  Real 'x_T_process' = x[2];\n"
  "  Real 'x_pi_ctrl.x' = x[3];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "end linearized_model;\n";
}
const char *SmithPredictorTemp_linear_model_datarecovery_frame()
{
  return "model linearized_model \"SmithPredictorTemp\"\n"
  "  parameter Integer n = 3 \"number of states\";\n"
  "  parameter Integer m = 0 \"number of inputs\";\n"
  "  parameter Integer p = 0 \"number of outputs\";\n"
  "  parameter Integer nz = 6 \"data recovery variables\";\n"
  "\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[m] = %s;\n"
  "  parameter Real z0[nz] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] = zeros(p, m);%s\n\n"
  "  parameter Real Cz[nz, n] =\n\t[%s];\n\n"
  "  parameter Real Dz[nz, m] = zeros(nz, m);%s\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m];\n"
  "  output Real y[p];\n"
  "  output Real z[nz];\n"
  "\n"
  "  Real 'x_T_model' = x[1];\n"
  "  Real 'x_T_process' = x[2];\n"
  "  Real 'x_pi_ctrl.x' = x[3];\n"
  "  Real 'z_T_error' = z[1];\n"
  "  Real 'z_T_measured' = z[2];\n"
  "  Real 'z_T_model_delayed' = z[3];\n"
  "  Real 'z_T_predicted' = z[4];\n"
  "  Real 'z_T_ref_signal' = z[5];\n"
  "  Real 'z_u_pi' = z[6];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "  z = Cz * x + Dz * u;\n"
  "end linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

