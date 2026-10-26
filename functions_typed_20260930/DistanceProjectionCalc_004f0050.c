double __thiscall sub_4F0050(int this)
{
  int v2; // ecx
  float *v3; // edx
  float *v4; // eax
  double result; // st7
  long double v6; // st4
  double v7; // st4
  float v8; // [esp+4h] [ebp-18h]
  float v9; // [esp+8h] [ebp-14h]
  float v10; // [esp+Ch] [ebp-10h]
  float v11; // [esp+10h] [ebp-Ch]
  float v12; // [esp+14h] [ebp-8h]

  v2 = PositionChangeMonitor((_DWORD *)this);
  v3 = *(float **)(v2 + 272);
  v4 = *(float **)(v2 + 268);
  v8 = *v3 - *v4;
  v9 = v3[1] - v4[1];
  v10 = v3[2] - v4[2];
  if ( v8 == 0.0 && v9 == 0.0 && v10 == 0.0 )
    return *(float *)(v2 + 72);
  v6 = 1.0 / sqrt(v10 * v10 + v9 * v9 + v8 * v8);
  v11 = v8 * v6;
  v12 = v9 * v6;
  v7 = v6 * v10 * (*(float *)(this + 13532) - *(float *)(v2 + 8))
     + v12 * (*(float *)(this + 13528) - *(float *)(v2 + 4))
     + v11 * (*(float *)(this + 13524) - *(float *)v2)
     + *(float *)(v2 + 72);
  result = v7;
  if ( v7 >= 0.0 )
  {
    if ( v7 > flt_5EA3FC[0] )
    {
      result = v7 - flt_5EA3FC[0];
      if ( result > flt_5EA3FC[0] )
        return flt_5EA3FC[0];
    }
  }
  else
  {
    result = v7 + flt_5EA3FC[0];
    if ( result < 0.0 )
      return 0.0;
  }
  return result;
}

