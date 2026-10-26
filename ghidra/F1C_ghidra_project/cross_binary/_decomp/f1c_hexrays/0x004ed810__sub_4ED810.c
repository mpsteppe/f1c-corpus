// f1c  0x004ed810  size=322
float *__thiscall sub_4ED810(float *this, float a2)
{
  float *result; // eax
  float *v3; // ecx
  float *v4; // edx
  int v5; // esi
  long double v6; // st7
  long double v7; // st7
  __int16 v8; // fps
  double v9; // st7
  bool v10; // c0
  char v11; // c2
  bool v12; // c3
  bool v13; // c0
  char v14; // c2
  bool v15; // c3
  float v16; // [esp+4h] [ebp-8h]
  float v17; // [esp+8h] [ebp-4h]

  result = this + 3447;
  v3 = this + 563;
  v17 = flt_8AFEF0 + 273.16;
  v4 = result;
  v5 = 4;
  v16 = fabs(v3[2829]);
  v6 = ((fabs(v3[2935]) * v3[2945] + fabs(v3[2873]) * v3[2883]) * v3[3163] * 0.5
      + (v16 * v3[3165] + v3[3164]) * (v17 - *result))
     * a2
     + *result;
  *result = v6;
  v3[2946] = v6;
  v7 = ((fabs(v3[3059]) * v3[3069] + fabs(v3[2997]) * v3[3007]) * v3[3168] * 0.5
      + (v16 * v3[3170] + v3[3169]) * (v17 - v3[3008]))
     * a2
     + v3[3008];
  v3[3008] = v7;
  v3[3070] = v7;
  do
  {
    v9 = (*v4 - 1023.16) * 0.004;
    v10 = v9 < 0.0;
    v11 = 0;
    v12 = v9 == 0.0;
    LOWORD(result) = v8;
    if ( v9 >= 0.0 )
    {
      v13 = v9 < 1.0;
      v14 = 0;
      v15 = v9 == 1.0;
      LOWORD(result) = v8;
      if ( v9 > 1.0 )
        v9 = 1.0;
    }
    else
    {
      v9 = 0.0;
    }
    *v3 = v9;
    v4 += 62;
    v3 += 74;
    --v5;
  }
  while ( v5 );
  return result;
}
