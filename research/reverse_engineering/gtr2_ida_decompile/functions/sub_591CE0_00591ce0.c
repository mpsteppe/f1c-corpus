double __thiscall sub_591CE0(float *this, int a2)
{
  double v4; // st7
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c3
  double result; // st7
  float v8; // [esp+4h] [ebp+4h]

  v8 = *(float *)(a2 + 76) - this[19];
  v4 = flt_91BDE4[0];
  if ( v5 | v6 )
    result = v4 - this[19] + *(float *)(a2 + 76);
  else
    result = -(v4 - *(float *)(a2 + 76) + this[19]);
  if ( fabs(result) > fabs(v8) )
    return v8;
  return result;
}
