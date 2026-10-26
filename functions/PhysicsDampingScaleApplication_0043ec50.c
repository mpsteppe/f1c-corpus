void __thiscall sub_43EC50(double *this, double a2)
{
  double *v2; // ecx

  PhysicsAccumulatorIntegrate(this, a2 * 0.25);
  DoubleAccumulatorClamp(v2, a2 * 0.75);
}
