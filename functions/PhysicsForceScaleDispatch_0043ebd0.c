void __thiscall sub_43EBD0(double *this, double a2)
{
  double *v2; // ecx

  SuspensionDamperForceAccumulation(this, a2 * 0.25);
  ClampedSpringIntegrator(v2, a2 * 0.75);
}
