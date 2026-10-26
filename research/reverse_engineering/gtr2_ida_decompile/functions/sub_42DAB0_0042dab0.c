void sub_42DAB0()
{
  char *v0; // eax
  float *v1; // eax
  double v2; // st7
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c2
  double v6; // st7
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c2
  double v10; // st7
  unsigned __int8 v12; // c0
  unsigned __int8 v13; // c2
  double v14; // st7
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c2
  float v18; // [esp+0h] [ebp-8h]
  float v19; // [esp+0h] [ebp-8h]
  float v20; // [esp+0h] [ebp-8h]
  float v21; // [esp+0h] [ebp-8h]
  float v22; // [esp+4h] [ebp-4h]
  float v23; // [esp+4h] [ebp-4h]
  float v24; // [esp+4h] [ebp-4h]
  float v25; // [esp+4h] [ebp-4h]

  v0 = dword_B6F708;
  if ( !dword_B6F708 )
    v0 = (char *)WindowName;
  v1 = (float *)sub_539670(v0);
  v2 = flt_B70ED0;
  v18 = v1[33];
  v22 = v1[34];
  if ( flt_B70ED0 >= (double)v18 )
  {
    if ( v2 > v22 )
      v2 = v22;
  }
  else
  {
    v2 = v18;
  }
  flt_B70ED0 = v2;
  if ( v4 | v5 )
  {
    flt_B70ED0 = flt_B70ED8;
  }
  else if ( v2 > flt_B70EDC )
  {
    flt_B70ED0 = flt_B70EDC;
  }
  v6 = flt_B70ED0;
  v23 = v1[33];
  v19 = v1[34];
  if ( flt_B70ED0 >= (double)v23 )
  {
    if ( v6 > v19 )
      v6 = v19;
  }
  else
  {
    v6 = v23;
  }
  flt_B70ED0 = v6;
  if ( v8 | v9 )
  {
    flt_B70ED0 = flt_B70ED8;
  }
  else if ( v6 > flt_B70EDC )
  {
    flt_B70ED0 = flt_B70EDC;
  }
  v10 = flt_B70EF4 + 0.0099999998;
  v24 = v1[36];
  v20 = v1[35];
  if ( v10 >= v24 )
  {
    if ( v10 > v20 )
      v10 = v20;
  }
  else
  {
    v10 = v24;
  }
  flt_B70EF4 = v10;
  if ( v12 | v13 )
  {
    flt_B70EF4 = flt_B70EFC;
  }
  else if ( v10 > flt_B70F00 )
  {
    flt_B70EF4 = flt_B70F00;
  }
  v14 = flt_B70EF4 - 0.0099999998;
  v25 = v1[36];
  v21 = v1[35];
  if ( v14 >= v25 )
  {
    if ( v14 > v21 )
      v14 = v21;
  }
  else
  {
    v14 = v25;
  }
  flt_B70EF4 = v14;
  if ( v16 | v17 )
  {
    flt_B70EF4 = flt_B70EFC;
  }
  else if ( v14 > flt_B70F00 )
  {
    flt_B70EF4 = flt_B70F00;
  }
}
