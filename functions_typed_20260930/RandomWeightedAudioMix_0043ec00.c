void __thiscall sub_43EC00(double *this, double a2)
{
  double *v2; // ecx
  double v3; // [esp+8h] [ebp-8h]

  v3 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
  ClampedSpringIntegrator(this, v3 * a2);
  DoubleAccumulatorClamp(v2, (1.0 - v3) * a2);
}

