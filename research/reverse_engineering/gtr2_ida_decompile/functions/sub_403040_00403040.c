double __thiscall sub_403040(_DWORD *this, float *a2)
{
  float *v2; // ecx
  int v3; // eax
  double v4; // st7
  double result; // st7
  long double v6; // st7
  float v7; // [esp+4h] [ebp-24h]
  float v8; // [esp+4h] [ebp-24h]
  float v9; // [esp+8h] [ebp-20h]
  float v10; // [esp+8h] [ebp-20h]
  float v11; // [esp+Ch] [ebp-1Ch]
  float v12; // [esp+10h] [ebp-18h]
  float v13; // [esp+14h] [ebp-14h]
  float v14; // [esp+18h] [ebp-10h]
  float v15; // [esp+1Ch] [ebp-Ch]
  float v16; // [esp+20h] [ebp-8h]

  v2 = sub_402D40(this, a2, 0);
  v7 = *a2 - v2[1];
  v15 = v7;
  v9 = a2[1] - v2[2];
  v16 = v9;
  v3 = *((_DWORD *)v2 + 68);
  v4 = *(float *)(*((_DWORD *)v2 + 69) + 4) - *(float *)(v3 + 4);
  v3 += 4;
  v12 = v4;
  v13 = *(float *)(*((_DWORD *)v2 + 69) + 8) - *(float *)(v3 + 4);
  v14 = *(float *)(*((_DWORD *)v2 + 69) + 12) - *(float *)(v3 + 8);
  if ( v12 == 0.0 && v13 == 0.0 && v14 == 0.0 )
    return v2[19];
  v6 = 1.0 / sqrt(v14 * v14 + v12 * v12 + v13 * v13);
  v8 = v12 * v6;
  v10 = v13 * v6;
  v11 = a2[2] - v2[3];
  result = v6 * v14 * v11 + v16 * v10 + v15 * v8 + v2[19];
  if ( result >= 0.0 )
  {
    if ( result > flt_91BDE4 )
    {
      result = result - flt_91BDE4;
      if ( result > flt_91BDE4 )
        return flt_91BDE4;
    }
  }
  else
  {
    result = result + flt_91BDE4;
    if ( result < 0.0 )
      return 0.0;
  }
  return result;
}
