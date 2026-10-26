void __thiscall sub_424C60(int this)
{
  double v3; // st7
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c3
  double v6; // st7
  double v7; // st7
  int v8; // edi
  int i; // ebp
  int v10; // ecx
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v19; // st7
  unsigned __int8 v20; // c0
  unsigned __int8 v21; // c2
  double v22; // st7
  double v23; // st7
  double v24; // st7
  int v25; // eax
  bool v26; // sf
  double v27; // st7
  double v28; // st6
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  float v33; // [esp+4h] [ebp-4h]
  float v34; // [esp+4h] [ebp-4h]
  float v35; // [esp+4h] [ebp-4h]
  float v36; // [esp+4h] [ebp-4h]

  v3 = *(float *)(this + 23732);
  if ( v4 | v5 )
    v3 = -v3;
  if ( v3 > 0.69999999 )
    v3 = 0.69999999;
  v6 = v3 * 0.5;
  if ( v6 > 0.015 && *(float *)(this + 23764) > 20.0 )
  {
    v33 = v6;
    *(float *)(this + 23740) = (1.0 - v33) * *(float *)(this + 23740);
  }
  if ( *(float *)(this + 24740) >= 0.0 )
  {
    v7 = *(float *)(this + 24740) - *(float *)(this + 23856);
    *(float *)(this + 24740) = v7;
    if ( v7 < 0.0 )
    {
      v8 = 1;
      for ( i = 0; i < 4; ++i )
      {
        if ( (v8 & *(_DWORD *)(this + 24748)) != 0 )
          sub_51BF90(*(_DWORD *)(this + 24744), i);
        v8 *= 2;
      }
    }
    *(_DWORD *)(this + 23820) = 0;
  }
  v10 = *(_DWORD *)(this + 24024);
  if ( v10 == 18 )
  {
    v11 = flt_7D74E0 * 0.85000002;
    if ( *(float *)(this + 23868) > v11 )
      v11 = *(float *)(this + 23868);
    *(float *)(this + 23868) = v11;
    v12 = flt_7D74E0 * 0.85000002;
    if ( *(float *)(this + 24028) > v12 )
      v12 = *(float *)(this + 24028);
    *(float *)(this + 24028) = v12;
  }
  if ( *(_DWORD *)(this + 23832) == 20 && *(float *)(this + 23764) < 10.0 )
    *(_DWORD *)(this + 23748) = *(_DWORD *)(this + 23940);
  if ( v10 == 19 && (unsigned __int8)sub_4F83B0(*(_DWORD *)(this + 80)) )
  {
    if ( flt_7D74E0 >= (double)*(float *)(this + 23868) )
      v13 = flt_7D74E0;
    else
      v13 = *(float *)(this + 23868);
    *(float *)(this + 23868) = v13;
  }
  sub_427B50(*(float *)(this + 24032));
  v34 = sub_514000(this + 84);
  if ( fabs(*(float *)(this + 23764) - *(float *)(this + 24028)) < 5.0 && *(float *)(this + 23740) >= (double)v34 )
  {
    v14 = (*(float *)(this + 24028) - *(float *)(this + 23764)) * 0.2;
    if ( v14 <= 0.0 )
      v15 = (v14 + 1.0) * v34;
    else
      v15 = (1.0 - v14) * v34 + v14;
    *(float *)(this + 23740) = v15;
  }
  if ( *(float *)(this + 23868) + 10.0 < *(float *)(this + 23764) )
  {
    v16 = sub_5140D0(this + 84) * *(float *)(this + 23940);
    *(_DWORD *)(this + 23740) = 0;
    *(float *)(this + 23748) = v16;
    goto LABEL_58;
  }
  if ( *(float *)(this + 23868) + 3.0 < *(float *)(this + 23764) )
  {
    v35 = (*(float *)(this + 23764) - *(float *)(this + 23868)) * 0.064999998;
    v17 = sub_5140D0(this + 84) * *(float *)(this + 23940) * v35;
    if ( v17 > *(float *)(this + 23748) )
      *(float *)(this + 23748) = v17;
LABEL_53:
    v23 = sub_513FA0(this + 84);
LABEL_57:
    *(float *)(this + 23740) = v23;
    goto LABEL_58;
  }
  v19 = *(float *)(this + 23764);
  if ( v20 | v21 )
  {
    v22 = (v19 - *(float *)(this + 23868)) * 0.050000001;
    if ( v22 > 0.30000001 || v22 >= 0.0 )
    {
      if ( v22 > 0.30000001 )
        v22 = 0.30000001;
    }
    else
    {
      v22 = 0.0;
    }
    if ( *(float *)(this + 23748) != 0.0 )
      goto LABEL_58;
    *(float *)(this + 23748) = v22;
    v23 = sub_513FA0(this + 84);
    goto LABEL_57;
  }
  if ( v19 > *(float *)(this + 23868) )
  {
    if ( *(float *)(this + 23748) != 0.0 )
      goto LABEL_58;
    goto LABEL_53;
  }
  if ( *(float *)(this + 23868) - 1.0 >= *(float *)(this + 23764) )
    goto LABEL_59;
  if ( *(float *)(this + 23748) == 0.0 )
  {
    v23 = sub_514000(this + 84) * (*(float *)(this + 23868) - *(float *)(this + 23764) + 1.0);
    goto LABEL_57;
  }
LABEL_58:
  *(float *)(this + 24724) = *(float *)(this + 23852) + 1.0;
LABEL_59:
  if ( *(float *)(this + 24028) < (double)*(float *)(this + 23764) )
  {
    if ( *(float *)(this + 23748) <= 0.025 )
      v24 = 0.025;
    else
      v24 = *(float *)(this + 23748);
    *(float *)(this + 23748) = v24;
    *(_DWORD *)(this + 23740) = 1036831949;
  }
  if ( *(float *)(this + 18352) < 0.75 || *(float *)(this + 18600) < 0.75 )
  {
    if ( *(float *)(this + 23764) > 10.0 || *(_DWORD *)(this + 23832) )
    {
      v25 = *(_DWORD *)(this + 23820) + 1;
      v26 = *(_DWORD *)(this + 23820) - 4 < 0;
      *(_BYTE *)(this + 76) = 1;
      *(_DWORD *)(this + 23820) = v25;
      if ( !(v26 ^ __OFSUB__(v25, 5) | (v25 == 5)) )
        *(_DWORD *)(this + 23820) = 5;
      v27 = sub_513FA0(this + 84);
      *(float *)(this + 23740) = v27;
      if ( *(float *)(this + 23748) <= 0.1 )
        v28 = 0.1;
      else
        v28 = *(float *)(this + 23748);
      *(float *)(this + 23748) = v28;
      if ( v27 < 0.2 )
        *(_DWORD *)(this + 23740) = 1045220557;
    }
  }
  else
  {
    *(_DWORD *)(this + 23820) = 0;
  }
  *(_DWORD *)(this + 23824) = 0;
  if ( (*(float *)(this + 17856) < 0.75 || *(float *)(this + 18104) < 0.75) && *(float *)(this + 23764) > 10.0 )
  {
    v36 = *(float *)(this + 23740);
    if ( sub_514000(this + 84) <= v36 )
      v29 = sub_514000(this + 84);
    else
      v29 = *(float *)(this + 23740);
    *(float *)(this + 23740) = v29;
    v30 = *(float *)(this + 23748);
    *(_DWORD *)(this + 23824) = 1;
    *(float *)(this + 23748) = v30 * 0.80000001;
  }
  if ( *(float *)(this + 24144) > (double)*(float *)(this + 23852) )
    *(float *)(this + 23748) = *(float *)(this + 23748) * 0.89999998;
  if ( *(_DWORD *)(this + 24024) == 18 )
  {
    v31 = *(float *)(this + 23744) + 0.1;
    if ( v31 >= *(float *)(this + 23740) )
    {
      v32 = *(float *)(this + 23744) - 0.2;
      if ( v32 > *(float *)(this + 23740) )
      {
        if ( v32 < 0.0 )
          v32 = 0.0;
        *(float *)(this + 23740) = v32;
      }
    }
    else
    {
      if ( v31 > 1.0 )
        v31 = 1.0;
      *(float *)(this + 23740) = v31;
    }
  }
  if ( *(float *)(this + 23740) > (double)*(float *)(this + 24284) )
    *(_DWORD *)(this + 23740) = *(_DWORD *)(this + 24284);
}
