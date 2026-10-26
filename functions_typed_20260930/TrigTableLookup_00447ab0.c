double __thiscall sub_447AB0(double *this)
{
  double v1; // st7
  float v3; // [esp+4h] [ebp-Ch]
  double v4; // [esp+8h] [ebp-8h]

  v4 = this[12] * 4.0;
  v3 = v4 - 0.5;
  v1 = flt_8AAE74[(unsigned __int8)(int)v3];
  return v1 + (flt_8AAE74[(unsigned __int8)((int)v3 + 1)] - v1) * (v4 - (double)(int)v3);
}

