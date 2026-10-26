double __thiscall sub_577D40(float *this)
{
  int v2; // ecx
  int v3; // eax
  double v4; // st7
  double result; // st7
  long double v6; // st7
  int v7; // eax
  float v8; // [esp+4h] [ebp-24h]
  float v9; // [esp+4h] [ebp-24h]
  float v10; // [esp+8h] [ebp-20h]
  float v11; // [esp+8h] [ebp-20h]
  float v12; // [esp+Ch] [ebp-1Ch]
  float v13; // [esp+10h] [ebp-18h]
  float v14; // [esp+14h] [ebp-14h]
  float v15; // [esp+18h] [ebp-10h]
  float v16; // [esp+1Ch] [ebp-Ch]
  float v17; // [esp+20h] [ebp-8h]

  v2 = sub_5761B0((int)this);
  v8 = this[3993] - *(float *)(v2 + 4);
  v16 = v8;
  v10 = this[3994] - *(float *)(v2 + 8);
  v17 = v10;
  v3 = *(_DWORD *)(v2 + 272);
  v4 = *(float *)(*(_DWORD *)(v2 + 276) + 4) - *(float *)(v3 + 4);
  v3 += 4;
  v13 = v4;
  v14 = *(float *)(*(_DWORD *)(v2 + 276) + 8) - *(float *)(v3 + 4);
  v15 = *(float *)(*(_DWORD *)(v2 + 276) + 12) - *(float *)(v3 + 8);
  if ( v13 == 0.0 && v14 == 0.0 && v15 == 0.0 )
  {
    result = *(float *)(v2 + 76);
  }
  else
  {
    v6 = 1.0 / sqrt(v15 * v15 + v14 * v14 + v13 * v13);
    v9 = v13 * v6;
    v11 = v14 * v6;
    v12 = this[3995] - *(float *)(v2 + 12);
    result = v6 * v15 * v12 + v17 * v11 + v16 * v9 + *(float *)(v2 + 76);
  }
  v7 = *(_DWORD *)(*(_DWORD *)this + 19288);
  if ( v7 == 2 )
  {
    if ( !*(_DWORD *)(v2 + 72) )
      return result + flt_91BDE4[0];
  }
  else if ( !v7 && *(_DWORD *)(v2 + 72) == 2 )
  {
    return result - flt_91BDE4[0];
  }
  return result;
}
