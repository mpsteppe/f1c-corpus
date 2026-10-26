double __thiscall sub_577BC0(float *this)
{
  int v2; // ecx
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

  v2 = sub_5761B0((int)this);
  v7 = this[3993] - *(float *)(v2 + 4);
  v15 = v7;
  v9 = this[3994] - *(float *)(v2 + 8);
  v16 = v9;
  v3 = *(_DWORD *)(v2 + 272);
  v4 = *(float *)(*(_DWORD *)(v2 + 276) + 4) - *(float *)(v3 + 4);
  v3 += 4;
  v12 = v4;
  v13 = *(float *)(*(_DWORD *)(v2 + 276) + 8) - *(float *)(v3 + 4);
  v14 = *(float *)(*(_DWORD *)(v2 + 276) + 12) - *(float *)(v3 + 8);
  if ( v12 == 0.0 && v13 == 0.0 && v14 == 0.0 )
    return *(float *)(v2 + 76);
  v6 = 1.0 / sqrt(v14 * v14 + v12 * v12 + v13 * v13);
  v8 = v12 * v6;
  v10 = v13 * v6;
  v11 = this[3995] - *(float *)(v2 + 12);
  result = v6 * v14 * v11 + v16 * v10 + v15 * v8 + *(float *)(v2 + 76);
  if ( result >= 0.0 )
  {
    if ( result > flt_91BDE4[0] )
    {
      result = result - flt_91BDE4[0];
      if ( result > flt_91BDE4[0] )
        return flt_91BDE4[0];
    }
  }
  else
  {
    result = result + flt_91BDE4[0];
    if ( result < 0.0 )
      return 0.0;
  }
  return result;
}
