/* Linearization */
#include "TankTempPIControl_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *TankTempPIControl_linear_model_frame()
{
  return "model linearized_model \"TankTempPIControl\"\n"
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
  "  Real 'x_T_water' = x[1];\n"
  "  Real 'x_piController.I.y' = x[2];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "end linearized_model;\n";
}
const char *TankTempPIControl_linear_model_datarecovery_frame()
{
  return "model linearized_model \"TankTempPIControl\"\n"
  "  parameter Integer n = 2 \"number of states\";\n"
  "  parameter Integer m = 0 \"number of inputs\";\n"
  "  parameter Integer p = 0 \"number of outputs\";\n"
  "  parameter Integer nz = 15 \"data recovery variables\";\n"
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
  "  Real 'x_T_water' = x[1];\n"
  "  Real 'x_piController.I.y' = x[2];\n"
  "  Real 'z_P_heat' = z[1];\n"
  "  Real 'z_P_loss' = z[2];\n"
  "  Real 'z_T_ambient' = z[3];\n"
  "  Real 'z_T_error' = z[4];\n"
  "  Real 'z_T_water_C' = z[5];\n"
  "  Real 'z_piController.I.local_set' = z[6];\n"
  "  Real 'z_piController.P.y' = z[7];\n"
  "  Real 'z_piController.addI.y' = z[8];\n"
  "  Real 'z_piController.addP.y' = z[9];\n"
  "  Real 'z_piController.addPID.y' = z[10];\n"
  "  Real 'z_piController.addSat.y' = z[11];\n"
  "  Real 'z_piController.gainPID.y' = z[12];\n"
  "  Real 'z_piController.gainTrack.y' = z[13];\n"
  "  Real 'z_piController.limiter.u' = z[14];\n"
  "  Real 'z_u_pi' = z[15];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "  z = Cz * x + Dz * u;\n"
  "end linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

