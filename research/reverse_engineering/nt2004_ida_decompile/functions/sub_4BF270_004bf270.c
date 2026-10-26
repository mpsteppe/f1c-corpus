char __thiscall sub_4BF270(float *this, int a2)
{
  int v2; // edx
  double v3; // st7
  int i; // esi
  int v7; // ecx
  int v8; // eax
  double v9; // st7
  float v10; // eax
  char result; // al
  int v12; // esi
  int v13; // ecx
  int v14; // eax
  double v15; // st6
  double v16; // st5
  double v17; // st4
  double v18; // st5
  double v19; // st6
  int v20; // eax
  int v21; // ecx
  double v22; // st7
  double v23; // st6
  double v24; // st6
  double v25; // st6
  double v26; // st6
  double v27; // st6
  double v28; // st6
  double v29; // st7
  double v30; // st7
  double v31; // st6
  double v32; // st5
  double v33; // st6
  double v34; // st6
  int v35; // esi
  float v36; // [esp+4h] [ebp-Ch]
  float v37; // [esp+8h] [ebp-8h]
  float v38; // [esp+8h] [ebp-8h]
  float v39; // [esp+Ch] [ebp-4h]
  float v40; // [esp+Ch] [ebp-4h]
  float v41; // [esp+Ch] [ebp-4h]
  float v42; // [esp+Ch] [ebp-4h]
  int v43; // [esp+14h] [ebp+4h]
  float v44; // [esp+14h] [ebp+4h]

  v2 = NumOfElements;
  v3 = 1.0;
  for ( i = 0; i < v2; ++i )
  {
    v7 = LODWORD(this[i]);
    if ( v7 )
    {
      if ( *(_DWORD *)(v7 + 24244) )
      {
        v8 = sub_427FF0(v7);
        v9 = sub_424C30((_DWORD *)a2, v8);
        if ( v9 < -10.5 && v9 > -45.0 )
        {
          v10 = this[i];
          if ( *(_DWORD *)(LODWORD(v10) + 24024) != 10 && *(float *)(LODWORD(v10) + 23764) > 1.0 )
            return 0;
        }
        v3 = (float)1.0;
      }
      else
      {
        this[i] = 0.0;
      }
      v2 = NumOfElements;
    }
  }
  if ( dword_75CBB0 == 7 )
    return 1;
  v12 = *(_DWORD *)(a2 + 24496);
  if ( v12 <= *(_DWORD *)(a2 + 24584) )
    return 0;
  v13 = v2;
  v14 = 0;
  v43 = v2;
  if ( v2 > 0 )
  {
    do
    {
      if ( LODWORD(this[v14]) )
        --v13;
      ++v14;
    }
    while ( v14 < v2 );
    v43 = v13;
  }
  if ( dword_75CBB0 == 3 || dword_75CBB0 == 4 || dword_75CBB0 == 5 )
    v15 = (double)v43 * 0.090909094;
  else
    v15 = (double)v43 * 0.071428575;
  v36 = 1.0 - v15;
  if ( v36 < 0.0099999998 )
    v36 = 0.0099999998;
  v37 = dbl_7DA9D0;
  v16 = flt_7D74BC + 3600.0;
  if ( v16 >= flt_7D74C0 )
    v17 = flt_7D74C0;
  else
    v17 = v16;
  if ( v17 - flt_7D74BC >= 1.0 )
  {
    if ( v16 >= flt_7D74C0 )
      v16 = flt_7D74C0;
    v18 = v16 - flt_7D74BC;
  }
  else
  {
    v18 = 1.0;
  }
  v19 = (v37 - flt_7D74BC) / v18;
  if ( v19 < 0.25 )
  {
    v39 = (float)*(int *)(a2 + 20848);
    if ( (double)sub_428070((_DWORD *)a2) * 0.34999999 > v39 )
    {
      v20 = *(_DWORD *)(*(_DWORD *)(a2 + 80) + 25264);
      if ( v20 >= 4 )
      {
        if ( v20 >= 8 )
          v3 = 0.85000002;
        else
          v3 = 0.69999999;
      }
      else
      {
        v3 = 0.25;
      }
      goto LABEL_87;
    }
    if ( v36 > 0.80000001 )
    {
      v3 = 0.80000001;
      goto LABEL_87;
    }
    if ( v36 > 0.40000001 )
    {
      v3 = 0.1;
      goto LABEL_87;
    }
LABEL_47:
    v3 = 0.0099999998;
    goto LABEL_87;
  }
  if ( v19 >= 0.5 )
  {
    if ( v19 >= 0.75 )
    {
      if ( this[48] < (double)v37 )
      {
        v29 = v37;
        goto LABEL_85;
      }
    }
    else
    {
      v21 = *(_DWORD *)(a2 + 20848);
      v22 = (double)(*(_DWORD *)(16 * v12 + a2 + 24488) - v21) * *(float *)(a2 + 20960);
      if ( v22 < 360.0 )
        v22 = 360.0;
      v44 = flt_7D74BC + 7200.0;
      if ( flt_7D74C0 <= (double)v44 )
        v23 = flt_7D74C0;
      else
        v23 = v44;
      if ( v23 - v37 >= 1.0 )
      {
        if ( flt_7D74C0 <= (double)v44 )
          v25 = flt_7D74C0;
        else
          v25 = v44;
        v24 = v25 - v37;
      }
      else
      {
        v24 = 1.0;
      }
      if ( v22 <= v24 )
      {
        if ( flt_7D74C0 <= (double)v44 )
          v26 = flt_7D74C0;
        else
          v26 = v44;
        if ( v26 - v37 >= 1.0 )
        {
          if ( flt_7D74C0 <= (double)v44 )
            v28 = flt_7D74C0;
          else
            v28 = v44;
          v27 = v28 - v37;
        }
        else
        {
          v27 = 1.0;
        }
        v41 = v22 / v27;
      }
      else
      {
        v41 = 1.0;
      }
      v38 = (float)v21;
      if ( (double)sub_428070((_DWORD *)a2) * 0.5 <= v38 )
        v3 = v41;
      else
        v3 = 1.0;
    }
  }
  else
  {
    v40 = (float)*(int *)(a2 + 20848);
    if ( (double)sub_428070((_DWORD *)a2) * 0.69999999 <= v40 )
    {
      if ( v36 > 0.80000001 )
      {
        v3 = 0.80000001;
        goto LABEL_87;
      }
      if ( v36 > 0.40000001 )
      {
        v3 = 0.2;
        goto LABEL_87;
      }
      goto LABEL_47;
    }
    if ( *(int *)(*(_DWORD *)(a2 + 80) + 25264) >= 4 )
      v3 = 0.66000003;
    else
      v3 = 0.40000001;
  }
LABEL_87:
  v30 = v3 * v36 * 18.0;
  if ( v30 == 0.0 )
    v30 = 0.001;
  v31 = flt_7D74BC + 1300.0;
  if ( v31 >= flt_7D74C0 )
    v32 = flt_7D74C0;
  else
    v32 = v31;
  if ( v32 - flt_7D74BC >= 1.0 )
  {
    if ( v31 >= flt_7D74C0 )
      v31 = flt_7D74C0;
    v33 = v31 - flt_7D74BC;
  }
  else
  {
    v33 = 1.0;
  }
  v34 = 0.25 / v30 * v33;
  if ( v34 < 1.0 )
  {
    v29 = dbl_7DA9D0;
    if ( dbl_7DA9D0 <= this[48] )
      return 0;
LABEL_85:
    result = 1;
    this[48] = v29 + 18.0;
    return result;
  }
  v35 = rand();
  if ( dword_75CBB0 == 7 || (v42 = v34, !(v35 % (__int64)v42)) )
  {
    v29 = dbl_7DA9D0;
    if ( dbl_7DA9D0 >= this[48] )
      goto LABEL_85;
  }
  return 0;
}
