double __thiscall sub_4F01B0(int this)
{
  int v2; // eax
  int v3; // edi
  int v4; // edx
  double v5; // st7
  int v6; // ecx
  int v7; // eax
  double result; // st7
  double v9; // st6
  long double v10; // st6
  double v11; // st6
  double v12; // st5
  double v13; // st4
  double v14; // st3
  float v15; // [esp+8h] [ebp-2Ch]
  float v16; // [esp+Ch] [ebp-28h]
  float v17; // [esp+10h] [ebp-24h]
  float v18; // [esp+14h] [ebp-20h]
  float v19; // [esp+18h] [ebp-1Ch]
  float v20; // [esp+1Ch] [ebp-18h]
  float v21; // [esp+20h] [ebp-14h]
  float v22; // [esp+24h] [ebp-10h]
  float v23; // [esp+2Ch] [ebp-8h]
  float v24; // [esp+2Ch] [ebp-8h]
  float v25; // [esp+30h] [ebp-4h]
  float v26; // [esp+30h] [ebp-4h]

  v2 = PositionChangeMonitor((_DWORD *)this);
  v3 = *(_DWORD *)(*(_DWORD *)this + 16448);
  v4 = v2;
  v5 = *(float *)(v2 + 144);
  v6 = *(_DWORD *)(v2 + 268);
  v7 = *(_DWORD *)(v2 + 272);
  v15 = v5;
  result = *(float *)(v6 + 144);
  v16 = *(float *)(v7 + 144);
  if ( v3 )
  {
    if ( v3 == 2 )
    {
      if ( !*(_DWORD *)(v4 + 68) )
        v15 = flt_5EA408 + v15;
      if ( !*(_DWORD *)(v6 + 68) )
        result = result + flt_5EA408;
      if ( !*(_DWORD *)(v7 + 68) )
      {
        v9 = flt_5EA408 + v16;
        goto LABEL_15;
      }
    }
  }
  else
  {
    if ( *(_DWORD *)(v4 + 68) == 2 )
      v15 = v15 - flt_5EA408;
    if ( *(_DWORD *)(v6 + 68) == 2 )
      result = result - flt_5EA408;
    if ( *(_DWORD *)(v7 + 68) == 2 )
    {
      v9 = v16 - flt_5EA408;
LABEL_15:
      v16 = v9;
    }
  }
  v20 = *(float *)v7 - *(float *)v6;
  v21 = *(float *)(v7 + 4) - *(float *)(v6 + 4);
  v22 = *(float *)(v7 + 8) - *(float *)(v6 + 8);
  v10 = sqrt(v22 * v22 + v21 * v21 + v20 * v20);
  v18 = v10;
  if ( v10 == 0.0 )
    return v15;
  v11 = 1.0 / v18;
  v12 = v20 * v11;
  v13 = v21 * v11;
  v14 = v22 * v11;
  v23 = *(float *)(v4 + 4) - *(float *)(v6 + 4);
  v25 = *(float *)(v4 + 8) - *(float *)(v6 + 8);
  v19 = v14 * v25 + v13 * v23 + (*(float *)v4 - *(float *)v6) * v12;
  v24 = *(float *)(this + 13528) - *(float *)(v6 + 4);
  v26 = *(float *)(this + 13532) - *(float *)(v6 + 8);
  v17 = v14 * v26 + v13 * v24 + (*(float *)(this + 13524) - *(float *)v6) * v12;
  if ( v17 > 0.0 )
  {
    if ( v17 >= (double)v19 )
    {
      if ( v17 >= (double)v18 )
        return v16;
      else
        return (v17 - v19) / (v18 - v19) * (v16 - v15) + v15;
    }
    else
    {
      return result + v17 / v19 * (v15 - result);
    }
  }
  return result;
}
