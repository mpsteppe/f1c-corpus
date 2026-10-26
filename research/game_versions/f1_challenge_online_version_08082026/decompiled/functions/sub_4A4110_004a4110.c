char __thiscall sub_4A4110(float *this, int a2)
{
  int v2; // edx
  double v3; // st7
  int i; // esi
  int v7; // ecx
  int v8; // eax
  double v9; // st7
  float v10; // ecx
  int v11; // eax
  char result; // al
  int v13; // ebx
  int v14; // ecx
  int v15; // eax
  double v16; // st6
  double v17; // st5
  double v18; // st4
  double v19; // st5
  double v20; // st6
  int v21; // eax
  int v22; // ecx
  double v23; // st7
  double v24; // st6
  double v25; // st6
  double v26; // st6
  double v27; // st6
  double v28; // st6
  double v29; // st6
  double v30; // st7
  double v31; // st7
  double v32; // st6
  double v33; // st5
  double v34; // st6
  double v35; // st6
  int v36; // esi
  float v37; // [esp+4h] [ebp-Ch]
  float v38; // [esp+8h] [ebp-8h]
  float v39; // [esp+8h] [ebp-8h]
  float v40; // [esp+Ch] [ebp-4h]
  float v41; // [esp+Ch] [ebp-4h]
  float v42; // [esp+Ch] [ebp-4h]
  float v43; // [esp+Ch] [ebp-4h]
  int v44; // [esp+14h] [ebp+4h]
  float v45; // [esp+14h] [ebp+4h]

  v2 = dword_5C329C;
  v3 = 1.0;
  for ( i = 0; i < v2; ++i )
  {
    v7 = LODWORD(this[i]);
    if ( v7 )
    {
      if ( *(_DWORD *)(v7 + 17744) )
      {
        v8 = sub_42ADD0(v7);
        v9 = sub_426CC0((_DWORD *)a2, v8);
        if ( v9 < 0.0 && v9 > -55.0 )
        {
          v10 = this[i];
          v11 = *(_DWORD *)(LODWORD(v10) + 17680);
          if ( v11 != 4 && v11 != 5 && *(float *)(LODWORD(v10) + 17472) > 2.0 )
            return 0;
        }
        v3 = (float)1.0;
      }
      else
      {
        this[i] = 0.0;
      }
      v2 = dword_5C329C;
    }
  }
  if ( dword_7C56A4 == 7 )
    return 1;
  v13 = *(_DWORD *)(a2 + 17800);
  if ( v13 <= *(_DWORD *)(a2 + 17888) )
    return 0;
  v14 = v2;
  v15 = 0;
  v44 = v2;
  if ( v2 > 0 )
  {
    do
    {
      if ( LODWORD(this[v15]) )
        --v14;
      ++v15;
    }
    while ( v15 < v2 );
    v44 = v14;
  }
  if ( dword_7C56A4 == 3 || dword_7C56A4 == 4 || dword_7C56A4 == 5 )
    v16 = (double)v44 * 0.090909094;
  else
    v16 = (double)v44 * 0.071428575;
  v37 = 1.0 - v16;
  if ( v37 < 0.0099999998 )
    v37 = 0.0099999998;
  v38 = dbl_8AFEA0;
  v17 = flt_8ACF90 + 3600.0;
  if ( v17 >= flt_8ACF94 )
    v18 = flt_8ACF94;
  else
    v18 = v17;
  if ( v18 - flt_8ACF90 >= 1.0 )
  {
    if ( v17 >= flt_8ACF94 )
      v17 = flt_8ACF94;
    v19 = v17 - flt_8ACF90;
  }
  else
  {
    v19 = 1.0;
  }
  v20 = (v38 - flt_8ACF90) / v19;
  if ( v20 < 0.25 )
  {
    v40 = (float)*(int *)(a2 + 16444);
    if ( (double)sub_42AE90((_DWORD *)a2) * 0.34999999 > v40 )
    {
      v14 = *(_DWORD *)a2;
      v21 = *(_DWORD *)(*(_DWORD *)a2 + 18596);
      if ( v21 >= 4 )
      {
        if ( v21 >= 8 )
          v3 = 0.85000002;
        else
          v3 = 0.69999999;
      }
      else
      {
        v3 = 0.25;
      }
      goto LABEL_88;
    }
    if ( v37 > 0.80000001 )
    {
      v3 = 0.80000001;
      goto LABEL_88;
    }
    if ( v37 > 0.40000001 )
    {
      v3 = 0.1;
      goto LABEL_88;
    }
LABEL_48:
    v3 = 0.0099999998;
    goto LABEL_88;
  }
  if ( v20 >= 0.5 )
  {
    if ( v20 >= 0.75 )
    {
      if ( this[104] < (double)v38 )
      {
        v30 = v38;
        goto LABEL_86;
      }
    }
    else
    {
      v22 = *(_DWORD *)(a2 + 16444);
      v23 = (double)(*(_DWORD *)(16 * (v13 + 1112) + a2) - v22) * *(float *)(a2 + 16540);
      if ( v23 < 360.0 )
        v23 = 360.0;
      v45 = flt_8ACF90 + 7200.0;
      if ( flt_8ACF94 <= (double)v45 )
        v24 = flt_8ACF94;
      else
        v24 = v45;
      if ( v24 - v38 >= 1.0 )
      {
        if ( flt_8ACF94 <= (double)v45 )
          v26 = flt_8ACF94;
        else
          v26 = v45;
        v25 = v26 - v38;
      }
      else
      {
        v25 = 1.0;
      }
      if ( v23 <= v25 )
      {
        if ( flt_8ACF94 <= (double)v45 )
          v27 = flt_8ACF94;
        else
          v27 = v45;
        if ( v27 - v38 >= 1.0 )
        {
          if ( flt_8ACF94 <= (double)v45 )
            v29 = flt_8ACF94;
          else
            v29 = v45;
          v28 = v29 - v38;
        }
        else
        {
          v28 = 1.0;
        }
        v42 = v23 / v28;
      }
      else
      {
        v42 = 1.0;
      }
      v39 = (float)v22;
      if ( (double)sub_42AE90((_DWORD *)a2) * 0.5 <= v39 )
        v3 = v42;
      else
        v3 = 1.0;
    }
  }
  else
  {
    v41 = (float)*(int *)(a2 + 16444);
    if ( (double)sub_42AE90((_DWORD *)a2) * 0.69999999 <= v41 )
    {
      if ( v37 > 0.80000001 )
      {
        v3 = 0.80000001;
        goto LABEL_88;
      }
      if ( v37 > 0.40000001 )
      {
        v3 = 0.2;
        goto LABEL_88;
      }
      goto LABEL_48;
    }
    if ( *(int *)(*(_DWORD *)a2 + 18596) >= 4 )
      v3 = 0.66000003;
    else
      v3 = 0.40000001;
  }
LABEL_88:
  v31 = v3 * v37 * 18.0;
  if ( v31 == 0.0 )
    v31 = 0.001;
  v32 = flt_8ACF90 + 1300.0;
  if ( v32 >= flt_8ACF94 )
    v33 = flt_8ACF94;
  else
    v33 = v32;
  if ( v33 - flt_8ACF90 >= 1.0 )
  {
    if ( v32 >= flt_8ACF94 )
      v32 = flt_8ACF94;
    v34 = v32 - flt_8ACF90;
  }
  else
  {
    v34 = 1.0;
  }
  v35 = 0.25 / v31 * v34;
  if ( v35 < 1.0 )
  {
    v30 = dbl_8AFEA0;
    if ( dbl_8AFEA0 <= this[104] )
      return 0;
LABEL_86:
    result = 1;
    this[104] = v30 + 18.0;
    return result;
  }
  v36 = sub_5884ED(v14);
  if ( dword_7C56A4 == 7 || (v43 = v35, !(v36 % sub_587BDC(v43))) )
  {
    v30 = dbl_8AFEA0;
    if ( dbl_8AFEA0 >= this[104] )
      goto LABEL_86;
  }
  return 0;
}
