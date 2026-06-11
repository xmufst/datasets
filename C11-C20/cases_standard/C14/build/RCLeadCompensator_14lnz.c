/* Linearization */
#include "RCLeadCompensator_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *RCLeadCompensator_linear_model_frame()
{
  return "model linearized_model \"RCLeadCompensator\"\n"
  "  parameter Integer n = 2 \"number of states\";\n"
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
  "  Real 'x_Vc' = x[1];\n"
  "  Real 'x_leadComp.x_scaled[1]' = x[2];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "end linearized_model;\n";
}
const char *RCLeadCompensator_linear_model_datarecovery_frame()
{
  return "model linearized_model \"RCLeadCompensator\"\n"
  "  parameter Integer n = 2 \"number of states\";\n"
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
  "  Real 'x_Vc' = x[1];\n"
  "  Real 'x_leadComp.x_scaled[1]' = x[2];\n"
  "  Real 'z_V_in' = z[1];\n"
  "  Real 'z_Vc_error' = z[2];\n"
  "  Real 'z_i_R' = z[3];\n"
  "  Real 'z_leadComp.x[1]' = z[4];\n"
  "  Real 'z_reference.y' = z[5];\n"
  "  Real 'z_u_compensator' = z[6];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "  z = Cz * x + Dz * u;\n"
  "end linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

