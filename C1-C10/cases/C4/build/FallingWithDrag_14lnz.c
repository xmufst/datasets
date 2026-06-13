/* Linearization */
#include "FallingWithDrag_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *FallingWithDrag_linear_model_frame()
{
  return "model linearized_model \"FallingWithDrag\"\n"
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
  "  Real 'x_E_dissipated' = x[1];\n"
  "  Real 'x_v' = x[2];\n"
  "  Real 'x_y' = x[3];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "end linearized_model;\n";
}
const char *FallingWithDrag_linear_model_datarecovery_frame()
{
  return "model linearized_model \"FallingWithDrag\"\n"
  "  parameter Integer n = 3 \"number of states\";\n"
  "  parameter Integer m = 0 \"number of inputs\";\n"
  "  parameter Integer p = 0 \"number of outputs\";\n"
  "  parameter Integer nz = 8 \"data recovery variables\";\n"
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
  "  Real 'x_E_dissipated' = x[1];\n"
  "  Real 'x_v' = x[2];\n"
  "  Real 'x_y' = x[3];\n"
  "  Real 'z_E_kinetic' = z[1];\n"
  "  Real 'z_E_potential_lost' = z[2];\n"
  "  Real 'z_F_drag' = z[3];\n"
  "  Real 'z_F_gravity' = z[4];\n"
  "  Real 'z_F_net' = z[5];\n"
  "  Real 'z_a' = z[6];\n"
  "  Real 'z_v_ratio' = z[7];\n"
  "  Real 'z_v_terminal' = z[8];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "  z = Cz * x + Dz * u;\n"
  "end linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

