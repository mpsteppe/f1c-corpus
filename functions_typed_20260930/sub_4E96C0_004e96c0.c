char __thiscall sub_4E96C0(int this)
{
  int v2; // esi
  double v3; // st6
  double v4; // st5
  double v5; // st3
  double v6; // st4
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // edi
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  unsigned __int8 v21; // c0
  unsigned __int8 v22; // c2
  unsigned __int8 v24; // c0
  unsigned __int8 v25; // c2
  float v26; // [esp+Ch] [ebp-10h]
  float v27; // [esp+10h] [ebp-Ch]
  float v28; // [esp+14h] [ebp-8h]

  v2 = this + 13524;
  v3 = *(float *)(this + 15024) - *(float *)(this + 13528);
  v4 = *(float *)(this + 15028) - *(float *)(this + 13532);
  v5 = *(float *)(this + 15020) - *(float *)(this + 13524);
  v6 = v4 * v4 + v3 * v3 + v5 * v5;
  if ( v6 < 0.0009 )
  {
    if ( *(_DWORD *)(this + 12988) )
      return 0;
    if ( v6 < 0.000009 )
      return 0;
  }
  v8 = *(_DWORD *)(this + 13528);
  v9 = *(_DWORD *)(this + 13532);
  *(_DWORD *)(this + 15020) = *(_DWORD *)v2;
  *(_DWORD *)(this + 15024) = v8;
  *(_DWORD *)(this + 15028) = v9;
  if ( *(float *)(this + 13504) >= 0.94999999 )
  {
LABEL_13:
    v12 = PositionChangeMonitor((_DWORD *)this);
    v13 = *(_DWORD *)(v12 + 272);
    v14 = *(_DWORD *)(v12 + 268);
    v27 = *(float *)v2 - *(float *)v12;
    v28 = *(float *)(v2 + 4) - *(float *)(v12 + 4);
    v15 = (*(float *)(v2 + 8) - *(float *)(v12 + 8)) * *(float *)(v12 + 40)
        + v28 * *(float *)(v12 + 36)
        + v27 * *(float *)(v12 + 32);
    v26 = v15;
    if ( v15 < *(float *)(this + 15212) )
    {
      v16 = *(float *)(v14 + 88) <= (double)*(float *)(v13 + 88) ? *(float *)(v14 + 88) : *(float *)(v13 + 88);
      if ( *(float *)(v12 + 88) >= v16 )
        v17 = *(float *)(v14 + 88) <= (double)*(float *)(v13 + 88) ? *(float *)(v14 + 88) : *(float *)(v13 + 88);
      else
        v17 = *(float *)(v12 + 88);
      if ( *(float *)(this + 15212) - v26 > v17 )
        return 1;
    }
    if ( -*(float *)(this + 15212) < v26 )
    {
      v18 = *(float *)(v14 + 92) <= (double)*(float *)(v13 + 92) ? *(float *)(v14 + 92) : *(float *)(v13 + 92);
      if ( *(float *)(v12 + 92) >= v18 )
        v19 = *(float *)(v14 + 92) <= (double)*(float *)(v13 + 92) ? *(float *)(v14 + 92) : *(float *)(v13 + 92);
      else
        v19 = *(float *)(v12 + 92);
      if ( v26 + *(float *)(this + 15212) > v19 )
        return 1;
    }
    if ( v21 | v22 )
      return 1;
    if ( !(v24 | v25) )
      return 0;
  }
  else
  {
    if ( *(float *)(this + 13504) < 0.70710677 )
      return 1;
    v10 = 0;
    v11 = this + 2088;
    while ( *(_DWORD *)v11 && *(_BYTE *)(v11 + 64) )
    {
      ++v10;
      v11 += 296;
      if ( v10 >= 4 )
        goto LABEL_13;
    }
  }
  return 1;
}

