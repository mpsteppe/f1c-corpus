bool __thiscall sub_514FD0(int this)
{
  _DWORD *v3; // ebx
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c2
  int v7; // edx
  int v8; // eax
  int v9; // edx
  int v10; // ebp
  int v11; // ecx
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  int v16; // edi
  float *v17; // ecx
  unsigned __int8 v19; // c0
  unsigned __int8 v20; // c2
  int v21; // ecx
  double v22; // st7
  double v23; // st7
  double v24; // st6
  int v25; // edi
  float *v26; // ecx
  double v27; // st7
  unsigned __int8 v29; // c0
  unsigned __int8 v30; // c3
  unsigned __int8 v32; // c0
  unsigned __int8 v33; // c2
  unsigned __int8 v35; // c0
  unsigned __int8 v36; // c2
  float v37; // [esp+10h] [ebp-20h]
  float v38; // [esp+14h] [ebp-1Ch]
  float v39; // [esp+18h] [ebp-18h]
  float v40; // [esp+1Ch] [ebp-14h]
  float v41; // [esp+20h] [ebp-10h]
  float v42; // [esp+24h] [ebp-Ch]
  float v43; // [esp+28h] [ebp-8h]
  float v44; // [esp+2Ch] [ebp-4h]

  if ( !*(_DWORD *)(this + 16500) )
    return 1;
  v3 = (_DWORD *)(this + 17520);
  if ( v5 | v6 )
    return 0;
  v7 = *(_DWORD *)(this + 17524);
  v8 = *(_DWORD *)(this + 17528);
  *(_DWORD *)(this + 19016) = *v3;
  *(_DWORD *)(this + 19020) = v7;
  *(_DWORD *)(this + 19024) = v8;
  if ( *(float *)(this + 17500) < 0.94999999 )
  {
    if ( *(float *)(this + 17500) < 0.70710677 )
      return 1;
    if ( !*(_BYTE *)(this + 2212) || !*(_BYTE *)(this + 2516) || !*(_BYTE *)(this + 2820) || !*(_BYTE *)(this + 3124) )
      return 1;
  }
  v9 = sub_514EE0((_DWORD *)this);
  v39 = *(float *)(v9 + 44);
  v42 = *(float *)v3 - *(float *)v9;
  v41 = *(float *)(v9 + 52);
  v10 = *(_DWORD *)(v9 + 296);
  v11 = *(_DWORD *)(v9 + 292);
  v43 = *(float *)(this + 17524) - *(float *)(v9 + 4);
  v40 = *(float *)(v9 + 48);
  v44 = *(float *)(this + 17528) - *(float *)(v9 + 8);
  v12 = v41 * v44 + v40 * v43 + v39 * v42;
  v37 = v12;
  if ( v12 < *(float *)(this + 19220) )
  {
    v13 = *(float *)(v11 + 132) <= (double)*(float *)(v10 + 132) ? *(float *)(v11 + 132) : *(float *)(v10 + 132);
    if ( *(float *)(v9 + 132) >= v13 )
      v14 = *(float *)(v11 + 132) <= (double)*(float *)(v10 + 132) ? *(float *)(v11 + 132) : *(float *)(v10 + 132);
    else
      v14 = *(float *)(v9 + 132);
    v38 = -v14;
    v15 = v37 - *(float *)(this + 19220);
    if ( v15 < v38 )
    {
      if ( v15 < v38 - 1.75 )
        return 1;
      v16 = 0;
      v17 = (float *)(this + 19032);
      while ( v41
            * (v17[1] * *(float *)(this + 17516)
             + *(float *)(this + 17508) * *(v17 - 1)
             + *v17 * *(float *)(this + 17512))
            + (*(v17 - 1) * *(float *)(this + 17496)
             + *v17 * *(float *)(this + 17500)
             + v17[1] * *(float *)(this + 17504))
            * v40
            + (v17[1] * *(float *)(this + 17492)
             + *v17 * *(float *)(this + 17488)
             + *(float *)(this + 17484) * *(v17 - 1))
            * v39 >= v38 - v37 + 0.1 )
      {
        ++v16;
        v17 += 3;
        if ( v16 >= 13 )
        {
          if ( !(v19 | v20) )
            goto LABEL_29;
          return 1;
        }
      }
      return 1;
    }
  }
LABEL_29:
  if ( -*(float *)(this + 19220) < v37 )
  {
    v21 = *(_DWORD *)(v9 + 292);
    v22 = *(float *)(v21 + 136) <= (double)*(float *)(v10 + 136) ? *(float *)(v21 + 136) : *(float *)(v10 + 136);
    if ( *(float *)(v9 + 136) >= v22 )
      v23 = *(float *)(v21 + 136) <= (double)*(float *)(v10 + 136) ? *(float *)(v21 + 136) : *(float *)(v10 + 136);
    else
      v23 = *(float *)(v9 + 136);
    v24 = v37 + *(float *)(this + 19220);
    if ( v24 > v23 )
    {
      if ( v24 <= v23 + 1.75 )
      {
        v25 = 0;
        v26 = (float *)(this + 19032);
        v27 = v23 - v37 - 0.1;
        while ( v41
              * (*(float *)(this + 17516) * v26[1]
               + *v26 * *(float *)(this + 17512)
               + *(float *)(this + 17508) * *(v26 - 1))
              + (*v26 * *(float *)(this + 17500)
               + *(float *)(this + 17504) * v26[1]
               + *(float *)(this + 17496) * *(v26 - 1))
              * v40
              + (*v26 * *(float *)(this + 17488)
               + *(float *)(this + 17492) * v26[1]
               + *(v26 - 1) * *(float *)(this + 17484))
              * v39 <= v27 )
        {
          ++v25;
          v26 += 3;
          if ( v25 >= 13 )
          {
            if ( v29 | v30 )
              goto LABEL_46;
            return 1;
          }
        }
      }
      return 1;
    }
  }
LABEL_46:
  if ( v32 | v33 )
    return 1;
  return (v35 | v36) != 0;
}
