/* Linearization */
#include "CascadeTankPI_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *CascadeTankPI_linear_model_frame()
{
  return "model linearized_model \"CascadeTankPI\"\n"
  "  parameter Integer n = 4 \"number of states\";\n"
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
  "  Real 'x_h1' = x[1];\n"
  "  Real 'x_h2' = x[2];\n"
  "  Real 'x_inner_PI.x' = x[3];\n"
  "  Real 'x_outer_PI.x' = x[4];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "end linearized_model;\n";
}
const char *CascadeTankPI_linear_model_datarecovery_frame()
{
  return "model linearized_model \"CascadeTankPI\"\n"
  "  parameter Integer n = 4 \"number of states\";\n"
  "  parameter Integer m = 0 \"number of inputs\";\n"
  "  parameter Integer p = 0 \"number of outputs\";\n"
  "  parameter Integer nz = 9 \"data recovery variables\";\n"
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
  "  Real 'x_h1' = x[1];\n"
  "  Real 'x_h2' = x[2];\n"
  "  Real 'x_inner_PI.x' = x[3];\n"
  "  Real 'x_outer_PI.x' = x[4];\n"
  "  Real 'z_Q_12' = z[1];\n"
  "  Real 'z_Q_in' = z[2];\n"
  "  Real 'z_Q_out' = z[3];\n"
  "  Real 'z_h2_error' = z[4];\n"
  "  Real 'z_inner_feedback.y' = z[5];\n"
  "  Real 'z_outer_feedback.y' = z[6];\n"
  "  Real 'z_u_inner' = z[7];\n"
  "  Real 'z_u_outer' = z[8];\n"
  "  Real 'z_valve_limiter.y' = z[9];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "  z = Cz * x + Dz * u;\n"
  "end linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

