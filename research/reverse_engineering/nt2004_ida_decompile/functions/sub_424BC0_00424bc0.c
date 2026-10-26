double __thiscall sub_424BC0(float *this, int a2)
{
  double v4; // st7
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c3
  double result; // st7
  float v8; // [esp+4h] [ebp+4h]

  v8 = *(float *)(a2 + 24200) - this[6050];
  v4 = flt_6290D0;
  if ( v5 | v6 )
    result = v4 - this[6050] + *(float *)(a2 + 24200);
  else
    result = -(v4 - *(float *)(a2 + 24200) + this[6050]);
  if ( fabs(result) > fabs(v8) )
    return v8;
  return result;
}
