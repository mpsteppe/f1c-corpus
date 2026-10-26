double __thiscall sub_51C900(int this)
{
  int v2; // ecx
  float *v3; // edx
  float *v4; // eax
  double result; // st7
  long double v6; // st4
  int v7; // eax
  float v8; // [esp+4h] [ebp-18h]
  float v9; // [esp+8h] [ebp-14h]
  float v10; // [esp+Ch] [ebp-10h]
  float v11; // [esp+10h] [ebp-Ch]
  float v12; // [esp+14h] [ebp-8h]

  v2 = sub_514EE0((_DWORD *)this);
  v3 = *(float **)(v2 + 296);
  v4 = *(float **)(v2 + 292);
  v8 = *v3 - *v4;
  v9 = v3[1] - v4[1];
  v10 = v3[2] - v4[2];
  if ( v8 == 0.0 && v9 == 0.0 && v10 == 0.0 )
  {
    result = *(float *)(v2 + 116);
  }
  else
  {
    v6 = 1.0 / sqrt(v10 * v10 + v9 * v9 + v8 * v8);
    v11 = v8 * v6;
    v12 = v9 * v6;
    result = v6 * v10 * (*(float *)(this + 17528) - *(float *)(v2 + 8))
           + v12 * (*(float *)(this + 17524) - *(float *)(v2 + 4))
           + v11 * (*(float *)(this + 17520) - *(float *)v2)
           + *(float *)(v2 + 116);
  }
  v7 = *(_DWORD *)(*(_DWORD *)this + 20852);
  if ( v7 == 2 )
  {
    if ( !*(_DWORD *)(v2 + 112) )
      return result + flt_6290D0[0];
  }
  else if ( !v7 && *(_DWORD *)(v2 + 112) == 2 )
  {
    return result - flt_6290D0[0];
  }
  return result;
}
