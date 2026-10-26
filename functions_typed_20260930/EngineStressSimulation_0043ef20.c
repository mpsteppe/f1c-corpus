void __thiscall sub_43EF20(int this)
{
  double v2; // st7
  double v3; // st6
  int v4; // eax
  int v5; // eax
  double v6; // st6
  double v7; // st7
  double v8; // st7
  double v9; // st6
  bool v10; // c0
  bool v11; // c3
  long double v12; // st5
  int v13; // ecx
  double v14; // st6
  double v15; // st6
  double v16; // st7
  long double v17; // st6
  double v18; // st7
  int v19; // eax
  int v20; // ecx
  double v21; // st7
  bool v22; // dl
  bool v23; // al
  double v24; // st7
  int v25; // ecx
  unsigned __int8 v27; // c0
  unsigned __int8 v28; // c3
  double v29; // st7
  double v30; // st6
  double v31; // st7
  double v32; // st7
  double v33; // st6
  double v34; // st6
  double v35; // st7
  double v36; // st7
  double v37; // st7
  double v38; // st7
  double v39; // st7
  int v40; // ecx
  double v41; // st7
  double v42; // st7
  double v43; // st7
  int v44; // ecx
  int v45; // eax
  unsigned __int8 v47; // c0
  unsigned __int8 v48; // c2
  double v49; // st7
  double v50; // st6
  unsigned __int8 v52; // c0
  unsigned __int8 v53; // c2
  double v54; // st7
  double v55; // st7
  double v56; // [esp+10h] [ebp-20h]
  double v57; // [esp+18h] [ebp-18h]
  double v58; // [esp+20h] [ebp-10h]
  double v59; // [esp+20h] [ebp-10h]
  double v60; // [esp+28h] [ebp-8h]

  v56 = fabs(*(double *)(this + 7260));
  if ( *(double *)(this + 412) <= 0.0 )
  {
    v2 = 0.0;
  }
  else
  {
    v2 = *(double *)(this + 428) * *(double *)(this + 8) * v56;
    v3 = *(double *)(this + 412) - v2 * *(double *)(this + 436);
    *(double *)(this + 412) = v3;
    if ( v3 <= 0.0 )
    {
      v4 = *(_DWORD *)(this + 7936) + 16436;
      *(_DWORD *)(this + 412) = 0;
      *(_DWORD *)(this + 416) = 0;
      if ( !*(_DWORD *)(v4 + 52) )
        *(_DWORD *)(v4 + 52) = 9;
    }
    v5 = *(_DWORD *)(this + 468);
    v6 = *(double *)(this + 412) * 0.75 + 1.0;
    *(double *)(v5 + 172) = v6;
    *(double *)(v5 + 180) = 1.0 / v6;
  }
  v60 = v2 * *(double *)(this + 7516)
      + v56 * *(double *)(this + 7524)
      + (flt_8AFEF0 + 273.16 - *(double *)(this + 7500)) * *(double *)(this + 7532);
  v7 = *(double *)(this + 7548);
  if ( *(double *)(this + 7508) - 10.0 < *(double *)(this + 7500) )
    v7 = v7 + v56 * *(double *)(this + 7556);
  v8 = v7 * (*(double *)(this + 7500) - *(double *)(this + 7564));
  v57 = (v60 - v8) * *(double *)(this + 104) + *(double *)(this + 7500);
  v9 = v56 * 0.5358549222797928;
  *(_DWORD *)(this + 7500) = LODWORD(v57);
  v10 = v57 < *(double *)(this + 7508);
  v11 = v57 == *(double *)(this + 7508);
  *(_DWORD *)(this + 7504) = HIDWORD(v57);
  if ( !v10 && !v11 )
  {
    v12 = sin(*(double *)(this + 7508) * 3.141592653589793 / (v57 + v57));
    if ( v12 < 0.0 )
      v12 = 0.0;
    v9 = v9 * v12;
  }
  v13 = *(_DWORD *)(this + 5616);
  *(double *)(this + 7540) = (v9 - *(double *)(this + 7540)) * *(double *)(this + 104) * 4.0 + *(double *)(this + 7540);
  v14 = *(double *)(v13 + 92) * *(double *)(v13 + 116)
      + *(double *)(v13 + 108) * *(double *)(v13 + 68)
      + *(double *)(v13 + 44) * *(double *)(v13 + 100);
  if ( v14 >= 0.0 )
    v15 = v14 * 0.2;
  else
    v15 = -v14;
  v58 = (v8
       + (v15 * *(double *)(this + 7580) + *(double *)(this + 7572)) * (flt_8AFEF0 + 273.16 - *(double *)(this + 7564)))
      * *(double *)(this + 104)
      + *(double *)(this + 7564);
  *(double *)(this + 7564) = v58;
  v16 = v56 * 0.301625;
  if ( v58 > 373.16 )
  {
    v17 = sin(1172.316714613567 / (v58 + v58));
    if ( v17 < 0.0 )
      v17 = 0.0;
    v16 = v16 * v17;
  }
  *(double *)(this + 7588) = (v16 - *(double *)(this + 7588)) * *(double *)(this + 104) * 4.0 + *(double *)(this + 7588);
  if ( *(double *)(this + 7604) > 0.0 )
  {
    v59 = *(double *)(this + 7604);
    sub_5881F0(2.0);
    sub_5881F0(2.0);
    v18 = *(double *)(this + 7604) - ((2.0 + 2.0) * 0.5 + *(double *)(this + 7596)) * *(double *)(this + 104);
    *(double *)(this + 7604) = v18;
    if ( v18 > 0.0 )
      return;
    v19 = *(_DWORD *)(this + 7936) + 16436;
    *(_DWORD *)(this + 7604) = 0;
    *(_DWORD *)(this + 7608) = 0;
    if ( !*(_DWORD *)(v19 + 52) )
      *(_DWORD *)(v19 + 52) = 1;
    v20 = dword_8AAE70;
    v22 = 1;
    if ( v59 == 2.225073858507201e-308 )
    {
      v21 = flt_8AB274[(unsigned __int8)dword_8AAE70];
      v20 = ++dword_8AAE70;
      if ( v21 <= 0.30000001 )
        v22 = 0;
    }
    v23 = *(double *)(this + 7652) == 0.0 && *(double *)(this + 7660) == 0.0 && *(double *)(this + 7668) == 0.0;
    v24 = flt_8AAE74[(unsigned __int8)v20];
    v25 = v20 + 1;
    dword_8AAE70 = v25;
    if ( !v23 )
      goto LABEL_57;
    if ( v24 < 0.5 )
    {
      if ( v22 )
      {
        if ( v27 | v28 )
          v29 = v24 - 0.04;
        else
          v29 = v24 + 0.04;
        if ( v29 < 0.0 )
        {
          v29 = 0.0;
LABEL_46:
          v33 = flt_8AB274[(unsigned __int8)v25];
          dword_8AAE70 = v25 + 1;
          *(double *)(this + 7652) = v33 * 0.4 - 0.1;
          v31 = v29 * 1000.0;
          goto LABEL_44;
        }
        if ( v29 <= 0.5 )
        {
          if ( v29 < 0.3 )
            goto LABEL_46;
          if ( v29 < 0.4 )
          {
            v34 = flt_8AB274[(unsigned __int8)v25];
            dword_8AAE70 = v25 + 1;
            *(double *)(this + 7660) = v34 * 0.4 - 0.1;
            v31 = (v29 - 0.3) * 450.0;
            goto LABEL_44;
          }
        }
        else
        {
          v29 = 0.5;
        }
        v30 = flt_8AB274[(unsigned __int8)v25];
        dword_8AAE70 = v25 + 1;
        *(double *)(this + 7668) = v30 * 0.4 - 0.1;
        v31 = (v29 - 0.4) * 50.0;
LABEL_44:
        *(double *)(this + 7604) = v31 + 1.0;
        v32 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.1;
        *(double *)(this + 7596) = v32 + 0.15;
        return;
      }
      goto LABEL_57;
    }
    if ( v22 )
    {
      v35 = flt_8AAE74[(unsigned __int8)v25++];
      dword_8AAE70 = v25;
      if ( v35 < 0.4 )
      {
        *(_DWORD *)(this + 7652) = 0;
        *(_DWORD *)(this + 7656) = 1072693248;
LABEL_56:
        v25 = dword_8AAE70;
        goto LABEL_57;
      }
      if ( v35 < 0.65 )
      {
        *(_DWORD *)(this + 7660) = 0;
        *(_DWORD *)(this + 7664) = 1072693248;
        goto LABEL_56;
      }
      if ( v35 < 0.9 )
      {
        *(_DWORD *)(this + 7668) = 0;
        *(_DWORD *)(this + 7672) = 1072693248;
        goto LABEL_56;
      }
    }
LABEL_57:
    if ( *(double *)(this + 7652) == 0.0 )
    {
      if ( *(double *)(this + 7660) == 0.0 )
      {
        if ( *(double *)(this + 7668) != 0.0 )
        {
          v42 = flt_8AAE74[(unsigned __int8)v25];
          dword_8AAE70 = v25 + 1;
          *(double *)(this + 7668) = 1.0 - v42 * 0.3;
          v43 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 0.3;
          *(double *)(this + 7660) = 1.0 - v43;
        }
      }
      else
      {
        v38 = flt_8AAE74[(unsigned __int8)v25];
        dword_8AAE70 = v25 + 1;
        *(double *)(this + 7660) = 1.0 - v38 * 0.3;
        v39 = flt_8AAE74[(unsigned __int8)dword_8AAE70];
        v40 = ++dword_8AAE70;
        if ( v39 >= 0.2 )
        {
          if ( v39 < 0.8 )
          {
            v41 = flt_8AAE74[(unsigned __int8)v40];
            dword_8AAE70 = v40 + 1;
            *(double *)(this + 7668) = 1.0 - v41 * 0.3;
          }
        }
        else
        {
          *(double *)(this + 7652) = v39 + 0.1;
        }
      }
    }
    else
    {
      v36 = flt_8AAE74[(unsigned __int8)v25];
      dword_8AAE70 = v25 + 1;
      *(double *)(this + 7652) = 1.0 - v36 * 0.3;
      v37 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
      if ( v37 < 0.2 )
        *(double *)(this + 7660) = v37 + 0.1;
    }
    v44 = *(_DWORD *)(this + 7432);
    v45 = 0;
    *(_DWORD *)(this + 7596) = 0;
    *(_DWORD *)(this + 7600) = 0;
    if ( v44 > 0 )
    {
      do
        *(_DWORD *)(*(_DWORD *)(this + 7420) + 8 * v45++ + 4) = 0;
      while ( v45 < *(_DWORD *)(this + 7432) );
    }
    sub_41AC50(*(_DWORD **)(this + 7936), 0);
    return;
  }
  if ( *(double *)(this + 7604) < -15.4 )
  {
    if ( *(double *)(this + 7596) > 0.0 )
    {
      v55 = *(double *)(this + 104) * 0.002 + *(double *)(this + 7596);
      *(double *)(this + 7596) = v55;
      if ( v55 > 0.6 )
      {
        *(_DWORD *)(this + 7596) = 858993459;
        *(_DWORD *)(this + 7600) = 1071854387;
      }
    }
  }
  else if ( v47 | v48 )
  {
    v49 = *(double *)(this + 7604);
    v50 = v49 - *(double *)(this + 104);
    *(double *)(this + 7604) = v50;
    if ( v52 | v53 )
    {
      *(_DWORD *)(this + 7652) = 0;
      *(_DWORD *)(this + 7656) = 0;
      *(_DWORD *)(this + 7660) = 0;
      *(_DWORD *)(this + 7664) = 0;
      *(_DWORD *)(this + 7668) = 0;
      *(_DWORD *)(this + 7672) = 0;
    }
    else if ( v50 < -10.1 && v49 >= -10.1 )
    {
      v54 = *(double *)(this + 7652);
      *(_DWORD *)(this + 7668) = 0;
      *(_DWORD *)(this + 7672) = 0;
      *(double *)(this + 7652) = v54 * 0.5;
      *(double *)(this + 7660) = *(double *)(this + 7660) * 0.5;
    }
  }
}

