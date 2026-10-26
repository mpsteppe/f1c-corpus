void __thiscall sub_4D1D80(int this)
{
  double v2; // st7
  int v3; // ecx
  char v4; // bl
  int i; // edi
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // eax
  float *v10; // esi
  float *v11; // eax
  long double v12; // st7
  long double v13; // st7
  long double v14; // st7
  float *v15; // eax
  unsigned __int8 v17; // c0
  unsigned __int8 v18; // c2
  _DWORD *v19; // ecx
  int j; // eax
  char v21; // dl
  int v22; // eax
  char v23; // cl
  char v24; // al
  _DWORD *v25; // esi
  int v26; // eax
  _DWORD *v27; // ecx
  int v28; // edx
  int k; // eax
  int v30; // [esp+0h] [ebp-9Ch]
  int v31; // [esp+0h] [ebp-9Ch]
  float v32; // [esp+18h] [ebp-84h]
  float v33; // [esp+1Ch] [ebp-80h]
  float v34; // [esp+20h] [ebp-7Ch]
  float v35; // [esp+24h] [ebp-78h]
  float v36; // [esp+28h] [ebp-74h]
  float v37; // [esp+2Ch] [ebp-70h]
  _BYTE v38[104]; // [esp+34h] [ebp-68h] BYREF

  v2 = *(float *)(this + 288) - dbl_8AFE98;
  *(float *)(this + 288) = v2;
  if ( v2 <= 0.0 )
  {
    *(_DWORD *)(this + 288) = 1048576000;
    v3 = dword_5C329C;
    v4 = 0;
    for ( i = 0; i < dword_5C329C; ++i )
    {
      v6 = PositionChangeMonitor(dword_7C54F0[i] + 12);
      v7 = dword_7C54F0[i];
      v8 = v6;
      v9 = *(_DWORD *)(v7 + 16448);
      if ( v9 != 2 || *(_DWORD *)(v8 + 68) )
      {
        if ( v9 || *(_DWORD *)(v8 + 68) != 2 )
        {
          v10 = *(float **)(v8 + 272);
          v11 = *(float **)(v8 + 268);
          v32 = *v10 - *v11;
          v33 = v10[1] - v11[1];
          v36 = v32;
          v34 = v10[2] - v11[2];
          v37 = v33;
          v12 = v34 * v34 + v33 * v33 + v32 * v32;
          if ( v12 <= 0.0 )
          {
            v14 = v34;
          }
          else
          {
            v13 = 1.0 / sqrt(v12);
            v36 = v32 * v13;
            v37 = v33 * v13;
            v14 = v13 * v34;
          }
          *(float *)(v7 + 16452) = v14 * (*(float *)(v7 + 13544) - *(float *)(v8 + 8))
                                 + v37 * (*(float *)(v7 + 13540) - *(float *)(v8 + 4))
                                 + (*(float *)(v7 + 13536) - *(float *)v8) * v36
                                 + *(float *)(v8 + 72);
        }
        else
        {
          *(_DWORD *)(v7 + 16452) = 0;
        }
      }
      else
      {
        *(float *)(v7 + 16452) = flt_5EA3FC;
      }
      if ( *(_DWORD *)(v8 + 300) )
        goto LABEL_21;
      v15 = (float *)dword_7C54F0[i];
      v35 = *(float *)(this + 256) - sqrt(v15[3390] * v15[3390] + v15[3391] * v15[3391] + v15[3392] * v15[3392]) * 5.0;
      if ( v17 | v18 )
      {
        if ( *(float *)(v7 + 16452) >= (double)*(float *)(this + 256) && flt_5EA3FC + v35 >= *(float *)(v7 + 16452) )
          goto LABEL_21;
      }
      else if ( *(float *)(v7 + 16452) >= (double)*(float *)(this + 256) || *(float *)(v7 + 16452) <= (double)v35 )
      {
        goto LABEL_21;
      }
      v4 = 1;
LABEL_21:
      v3 = dword_5C329C;
    }
    if ( v4 != *(_BYTE *)(this + 260) )
    {
      v19 = (_DWORD *)dword_8AAE64;
      if ( dword_83EE60 < 1023 )
      {
        ++dword_83EE60;
        dword_8AAE64 += 432;
      }
      *(float *)&v30 = dbl_8AFEA0;
      if ( v4 )
        ProgressBarEventEncode(v19, 4, 33, 0, 255, v30, 0);
      else
        ProgressBarEventEncode(v19, 4, 34, 0, 255, v30, 0);
      v3 = dword_5C329C;
    }
    for ( j = 0; j < v3; ++j )
      v38[j] = *(_BYTE *)(dword_7C54F0[j] + 18580);
    if ( dword_7C56A4 == 7 )
      sub_5890AA(v38, v3, 1, DriverSortComparator);
    else
      sub_5890AA(v38, v3, 1, DriverStandingComparator);
    v21 = 0;
    v22 = 0;
    if ( dword_5C329C > 0 )
    {
      do
      {
        v23 = v38[v22];
        if ( *(_BYTE *)(v22 + this + 296) != v23 )
          v21 = 1;
        *(_BYTE *)(v22 + this + 296) = v23;
        ++v22;
      }
      while ( v22 < dword_5C329C );
      if ( v21 )
        goto LABEL_40;
    }
    v24 = *(_BYTE *)(this + 292) + 1;
    ++*(_DWORD *)(this + 292);
    if ( (v24 & 0xF) == 0 )
    {
LABEL_40:
      *(_DWORD *)(this + 292) = 0;
      v25 = (_DWORD *)dword_8AAE64;
      if ( dword_83EE60 < 1023 )
      {
        ++dword_83EE60;
        dword_8AAE64 += 432;
      }
      *(float *)&v31 = dbl_8AFEA0;
      ProgressBarEventEncode(v25, 4, 7, dword_5C329C + 12, 255, v31, 0);
      if ( dword_5C329C <= 0 )
      {
        v25[2] = -1082130432;
        v25[3] = -1082130432;
        v25[4] = -1082130432;
      }
      else
      {
        v26 = 0;
        v27 = v25 + 2;
        do
        {
          v28 = v26 + 4656 * *(unsigned __int8 *)(this + 296);
          ++v26;
          *((float *)++v27 - 1) = flt_5F0780[v28];
        }
        while ( v26 < 3 );
      }
      for ( k = 0; k < dword_5C329C; ++k )
        *((_BYTE *)v25 + k + 20) = *(_BYTE *)(k + this + 296);
    }
    sub_4D1730(this);
  }
}
