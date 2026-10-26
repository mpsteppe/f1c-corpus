void __thiscall sub_4E0F70(int this, int a2, float a3, float a4)
{
  double v4; // st7
  signed int v6; // edx
  int v7; // ecx
  signed int v8; // edx
  int v9; // ecx
  double v10; // st6
  double v11; // st7
  double v12; // st7
  double v13; // st7
  char *v14; // ecx
  int v15; // eax
  const char *v16; // eax
  int v17; // eax
  const char *v18; // eax
  int v19; // eax
  const char *v20; // eax
  double v22; // st7
  unsigned __int8 v23; // c0
  unsigned __int8 v24; // c3
  double v25; // st6
  double v26; // st7
  double v27; // st6
  double v28; // st6
  int v29; // eax
  const char *v30; // eax
  double v31; // st7
  char *v32; // edx
  int v33; // eax
  char *v34; // edx
  const char *v35; // eax
  int v36; // eax
  const char *v37; // eax
  double v38; // st7
  double v39; // st7
  float v40; // [esp+10h] [ebp-Ch]
  float v41; // [esp+14h] [ebp-8h]
  float v42; // [esp+14h] [ebp-8h]
  float v43; // [esp+18h] [ebp-4h]
  float v44; // [esp+18h] [ebp-4h]
  float v45; // [esp+24h] [ebp+8h]
  float v46; // [esp+24h] [ebp+8h]
  float v47; // [esp+24h] [ebp+8h]
  float v48; // [esp+28h] [ebp+Ch]

  v4 = 10.0;
  *(_DWORD *)(this + 396) = 1123024896;
  v6 = 0;
  v40 = 99999.898;
  v43 = 0.0;
  v41 = 0.0;
  if ( (int)NumOfElements > 0 )
  {
    do
    {
      v7 = dword_75AAD0[v6];
      if ( *(float *)(v7 + 20960) > 1.0 && *(float *)(v7 + 20960) < (double)v40 && *(_DWORD *)(v7 + 16584) == 1 )
      {
        v40 = *(float *)(v7 + 20960);
        v43 = *(float *)(v7 + 23968);
      }
      ++v6;
    }
    while ( v6 < (int)NumOfElements );
    if ( v40 < 9000.0 )
    {
      v8 = 0;
      do
      {
        v9 = dword_75AAD0[v8];
        if ( *(float *)(v9 + 20960) > 0.0
          && *(float *)(v9 + 20960) > (double)v41
          && v40 * 1.15 > *(float *)(v9 + 20960)
          && *(_DWORD *)(v9 + 16584) == 1 )
        {
          v41 = *(float *)(v9 + 20960);
          v4 = *(float *)(v9 + 23968);
        }
        ++v8;
      }
      while ( v8 < (int)NumOfElements );
    }
  }
  *(_DWORD *)(this + 400) = 1036831949;
  if ( v40 < 9000.0 && v41 > 1.0 && v40 != v41 )
  {
    v48 = v41 - v40;
    v10 = v43 - v4;
    *(float *)(this + 400) = v48;
    if ( v10 < 0.0099999998 )
      v10 = 0.0099999998;
    if ( v43 == v4 )
    {
      v11 = 0.0;
    }
    else
    {
      v45 = v48 / v10;
      v11 = v45;
    }
    v12 = v40 - v11 * (1.0 - v43);
    *(float *)(this + 396) = v12;
    v46 = v40 * 0.97000003;
    if ( v12 < v46 )
      *(float *)(this + 396) = v46;
    v13 = *(float *)(this + 396);
    *(_BYTE *)(this + 386) = 1;
    if ( v13 > 0.0 )
      *(float *)(this + 400) = 2.0 / *(float *)(this + 396) * v48;
    return;
  }
  if ( !sub_57AE50(aSeasonraces) )
    goto LABEL_61;
  v14 = dword_766594;
  if ( !dword_766594 )
    v14 = &byte_629120;
  if ( !sub_57A720(v14) || a3 == 0.0 )
  {
LABEL_61:
    *(_BYTE *)(this + 386) = 1;
    return;
  }
  v47 = -1.0;
  v44 = -1.0;
  v42 = -1.0;
  v15 = sub_57A720(off_6105E4);
  if ( v15 )
  {
    v16 = (const char *)sub_57A6D0(v15);
    v47 = atof(v16);
  }
  v17 = sub_57A720(off_6105E8);
  if ( v17 )
  {
    v18 = (const char *)sub_57A6D0(v17);
    v44 = atof(v18);
  }
  v19 = sub_57A720(off_6105EC);
  if ( v19 )
  {
    v20 = (const char *)sub_57A6D0(v19);
    v42 = atof(v20);
  }
  if ( v47 <= 0.0 )
  {
    sub_57AE50(aSeasonraces);
    if ( a2 < 6 || a2 > 7 )
    {
      v34 = dword_766594;
      if ( !dword_766594 )
        v34 = &byte_629120;
      if ( !sub_57A720(v34) )
        goto LABEL_60;
      v33 = sub_57A720(off_6105E0);
      if ( !v33 )
        goto LABEL_60;
    }
    else
    {
      v32 = dword_766594;
      if ( !dword_766594 )
        v32 = &byte_629120;
      if ( !sub_57A720(v32) )
        goto LABEL_60;
      v33 = sub_57A720(off_6105E0);
      if ( !v33 )
        goto LABEL_60;
    }
    v35 = (const char *)sub_57A6D0(v33);
    *(float *)(this + 396) = atof(v35);
    v36 = sub_57A720(off_6105F0);
    if ( v36 )
    {
      v37 = (const char *)sub_57A6D0(v36);
      v38 = atof(v37);
      *(float *)(this + 400) = v38;
      if ( *(float *)(this + 396) > 0.0 )
        *(float *)(this + 400) = 2.0 / *(float *)(this + 396) * v38;
    }
LABEL_60:
    v39 = a4 * 0.0083333338;
    *(float *)(this + 392) = v39;
    *(float *)(this + 396) = 0.15000001 * *(float *)(this + 396) * (1.0 - v39) + *(float *)(this + 396);
    goto LABEL_61;
  }
  v22 = a4;
  if ( v23 | v24 )
  {
    v25 = v22 - 70.0;
    v26 = (1.0 - 0.033333335 * v25) * v47;
    v27 = v25 * v44 * 0.03333333333333333;
  }
  else
  {
    v28 = v22 - 100.0;
    v26 = (1.0 - 0.050000001 * v28) * v44;
    v27 = v28 * v42 * 0.05;
  }
  *(float *)(this + 396) = v26 + v27;
  v29 = sub_57A720(off_6105F0);
  if ( !v29 )
    goto LABEL_61;
  v30 = (const char *)sub_57A6D0(v29);
  v31 = atof(v30);
  *(float *)(this + 400) = v31;
  if ( *(float *)(this + 396) > 0.0 )
    *(float *)(this + 400) = 2.0 / *(float *)(this + 396) * v31;
  *(_BYTE *)(this + 386) = 1;
  *(float *)(this + 392) = a4 * 0.0083333338;
}
