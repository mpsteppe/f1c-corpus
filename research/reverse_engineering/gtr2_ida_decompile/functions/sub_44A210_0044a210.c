double __thiscall sub_44A210(double *this)
{
  int v1; // eax
  double v2; // st7
  float v4; // [esp+0h] [ebp-10h]
  double v5; // [esp+8h] [ebp-8h]

  v5 = this[16] * 4.0;
  v4 = v5 - 0.5;
  v1 = sub_4015C0(v4);
  v2 = flt_BE08A4[(unsigned __int8)v1];
  return v2 + (flt_BE08A4[(unsigned __int8)(v1 + 1)] - v2) * (v5 - (double)v1);
}
