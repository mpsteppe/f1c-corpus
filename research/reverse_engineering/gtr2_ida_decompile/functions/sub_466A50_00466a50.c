int __cdecl sub_466A50(float a1, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v5; // ecx
  double v6; // st7
  double v7; // st7
  double v8; // st7
  int v9; // eax
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  bool v17; // c0
  bool v18; // c3
  int v19; // eax
  double v20; // st7
  char v21; // fps^1
  double v22; // st6
  bool v23; // c0
  char v24; // c2
  bool v25; // c3
  bool v26; // zf
  char v27; // ah
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7

  if ( byte_B739A8 )
  {
    v6 = flt_B73900 * a1 * 10.0;
    if ( *(_DWORD *)(v5 + 3440) )
    {
      v7 = v6 + *(float *)(v5 + 11612);
      *(float *)(v5 + 11612) = v7;
      if ( v7 > 1.0 )
        *(_DWORD *)(v5 + 11612) = 1065353216;
      goto LABEL_15;
    }
    goto LABEL_5;
  }
  if ( *(_DWORD *)(v5 + 8076) == 2 )
  {
    *(_DWORD *)(v5 + 11612) = *(_DWORD *)(v5 + 8116);
    goto LABEL_15;
  }
  v6 = flt_B73900 * a1 * 10.0;
  if ( !*(_DWORD *)(v5 + 8112) )
  {
LABEL_5:
    if ( *(_DWORD *)(v5 + 8156) )
      *(float *)(v5 + 11612) = *(float *)(v5 + 11612) - v6 * 1.5;
    else
      *(float *)(v5 + 11612) = *(float *)(v5 + 11612) - v6;
    if ( *(float *)(v5 + 11612) < 0.0 )
      *(_DWORD *)(v5 + 11612) = 0;
    goto LABEL_15;
  }
  v8 = v6 + *(float *)(v5 + 11612);
  *(float *)(v5 + 11612) = v8;
  if ( v8 > 1.0 )
    *(_DWORD *)(v5 + 11612) = 1065353216;
LABEL_15:
  *a3 = *(_DWORD *)(v5 + 11612);
  if ( byte_B739C0 )
  {
    v9 = *(_DWORD *)(v5 + 3448);
  }
  else
  {
    if ( *(_DWORD *)(v5 + 8120) == 2 )
    {
      *(_DWORD *)(v5 + 11616) = *(_DWORD *)(v5 + 8160);
      goto LABEL_25;
    }
    v9 = *(_DWORD *)(v5 + 8156);
  }
  v10 = flt_B73924 * a1 * 10.0;
  if ( v9 )
  {
    v11 = v10 + *(float *)(v5 + 11616);
    *(float *)(v5 + 11616) = v11;
    if ( v11 > 1.0 )
      *(_DWORD *)(v5 + 11616) = 1065353216;
  }
  else
  {
    v12 = *(float *)(v5 + 11616) - v10;
    *(float *)(v5 + 11616) = v12;
    if ( v12 < 0.0 )
      *(_DWORD *)(v5 + 11616) = 0;
  }
LABEL_25:
  *a4 = *(_DWORD *)(v5 + 11616);
  if ( *(_DWORD *)(v5 + 10056) == 2 )
  {
    *(_DWORD *)(v5 + 11620) = *(_DWORD *)(v5 + 10096);
  }
  else
  {
    v13 = flt_B73924 * a1 * 10.0;
    if ( *(_DWORD *)(v5 + 10092) )
    {
      v14 = v13 + *(float *)(v5 + 11620);
      *(float *)(v5 + 11620) = v14;
      if ( v14 > 1.0 )
        *(_DWORD *)(v5 + 11620) = 1065353216;
    }
    else
    {
      v15 = *(float *)(v5 + 11620) - v13;
      *(float *)(v5 + 11620) = v15;
      if ( v15 < 0.0 )
        *(_DWORD *)(v5 + 11620) = 0;
    }
  }
  *a5 = *(_DWORD *)(v5 + 11620);
  if ( byte_B73990 )
  {
    *(float *)(v5 + 11624) = (double)*(int *)(v5 + 3288) * *(float *)(v5 + 3296);
    if ( *(float *)(v5 + 11624) < -1.0 )
    {
      *(_DWORD *)(v5 + 11624) = -1082130432;
      return off_16C9844();
    }
    v16 = *(float *)(v5 + 11624);
    v17 = v16 < 1.0;
    v18 = v16 == 1.0;
    goto LABEL_36;
  }
  if ( *(_DWORD *)(v5 + 8164) == 2 && *(_DWORD *)(v5 + 8208) == 2 )
  {
    if ( *(float *)(v5 + 8204) <= 0.0 )
      *(_DWORD *)(v5 + 11624) = *(_DWORD *)(v5 + 8248);
    else
      *(float *)(v5 + 11624) = -*(float *)(v5 + 8204);
    return off_16C9844();
  }
  v19 = *(_DWORD *)(v5 + 8244);
  v20 = flt_B738DC * a1 * 10.0;
  v22 = *(float *)(v5 + 11624);
  v23 = v22 < 0.0;
  v24 = 0;
  v25 = v22 == 0.0;
  if ( !*(_DWORD *)(v5 + 8200) )
  {
    v26 = v19 == 0;
    v27 = v21;
    if ( !v26 )
    {
      if ( v22 < 0.0 )
        *(float *)(v5 + 11624) = 3.0 * v20 + *(float *)(v5 + 11624);
      v30 = v20 + *(float *)(v5 + 11624);
      *(float *)(v5 + 11624) = v30;
      v17 = v30 < 1.0;
      v18 = v30 == 1.0;
LABEL_36:
      if ( !v17 && !v18 )
        *(_DWORD *)(v5 + 11624) = 1065353216;
      return off_16C9844();
    }
LABEL_45:
    if ( (v27 & 0x41) != 0 )
    {
      v31 = v20 + *(float *)(v5 + 11624);
      *(float *)(v5 + 11624) = v31;
      if ( v31 <= 0.0 )
        return off_16C9844();
    }
    else
    {
      v28 = *(float *)(v5 + 11624) - v20;
      *(float *)(v5 + 11624) = v28;
      if ( v28 >= 0.0 )
        return off_16C9844();
    }
    *(_DWORD *)(v5 + 11624) = 0;
    return off_16C9844();
  }
  v26 = v19 == 0;
  v27 = v21;
  if ( !v26 )
    goto LABEL_45;
  if ( !v23 && !v25 )
    *(float *)(v5 + 11624) = *(float *)(v5 + 11624) - 3.0 * v20;
  v29 = *(float *)(v5 + 11624) - v20;
  *(float *)(v5 + 11624) = v29;
  if ( v29 < -1.0 )
    *(_DWORD *)(v5 + 11624) = -1082130432;
  return off_16C9844();
}
