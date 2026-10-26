void __thiscall sub_428180(int this, int a2, int a3, int a4)
{
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  _DWORD *v13; // eax
  float *v14; // ecx
  _DWORD *v15; // eax
  int v16; // ecx
  bool v17; // c0
  float *v18; // ecx
  double v19; // st7
  double v20; // st6
  double v21; // st7
  int v22; // eax
  _DWORD *v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // ecx
  _DWORD *v28; // eax
  int v29; // ecx
  int v30; // ecx
  int v31; // ecx
  double v32; // st7
  int v33; // ecx
  int v34; // ecx
  int v35; // edx
  double v36; // st7
  _DWORD *v37; // edx
  double v38; // st7
  double v39; // st6
  double v40; // st7
  int v41; // ebp
  int v42; // eax
  double v43; // st7
  int v44; // ebp
  int v45; // edx
  int v46; // ecx
  int v47; // ecx
  double v48; // st7
  double v49; // st6
  double v50; // st7
  int v51; // ebp
  int v52; // edx
  int v53; // eax
  int v54; // ecx
  int v55; // eax
  double v56; // st7
  double v57; // st7
  double v58; // st7
  double v59; // st6
  int v60; // eax
  double v61; // st7
  double v62; // st7
  double v63; // st7
  double v64; // st7
  double v65; // st6
  double v66; // st5
  double v67; // st7
  double v68; // st7
  int v69; // eax
  int v70; // edx
  double v71; // st7
  double v72; // st7
  double v73; // st7
  double v74; // st6
  double v75; // st5
  double v76; // st7
  int v77; // edx
  int v78; // eax
  int v79; // eax
  float v80; // [esp+0h] [ebp-24h]
  float v81; // [esp+0h] [ebp-24h]
  float v82; // [esp+0h] [ebp-24h]
  float v83; // [esp+4h] [ebp-20h]
  float v84; // [esp+4h] [ebp-20h]
  float v85; // [esp+4h] [ebp-20h]
  int v86; // [esp+1Ch] [ebp-8h]
  float v87; // [esp+20h] [ebp-4h]
  float v88; // [esp+20h] [ebp-4h]
  float v89; // [esp+28h] [ebp+4h]
  float v90; // [esp+28h] [ebp+4h]
  float v91; // [esp+30h] [ebp+Ch]
  float v92; // [esp+30h] [ebp+Ch]
  float v93; // [esp+30h] [ebp+Ch]
  float v94; // [esp+30h] [ebp+Ch]

  v5 = (a2 << 7) + this;
  *(_DWORD *)(v5 + 21372) = 0;
  *(_DWORD *)(v5 + 21364) = 0;
  v6 = *(_DWORD *)(this + 24024);
  v86 = -2;
  if ( v6 == 18 || v6 == 19 || v6 == 14 )
    v86 = sub_4F82E0(*(_DWORD *)(this + 80));
  v7 = *(_DWORD *)(this + 24024);
  if ( v7 == 14 )
  {
LABEL_6:
    *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 0;
    goto LABEL_183;
  }
  if ( v7 == 19 || v7 == 18 )
  {
    *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 0;
    if ( flt_5FD0F0 > (double)*(float *)(this + 23852) )
    {
      switch ( a4 )
      {
        case 1:
LABEL_166:
          v47 = *(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248);
          goto LABEL_161;
        case 2:
          *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 11;
          goto LABEL_183;
        case 3:
          goto LABEL_170;
        case 4:
          v31 = *(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248);
          goto LABEL_101;
      }
    }
    if ( !a4 )
    {
      v48 = *(float *)(v5 + 21304) - 5.0;
      if ( v48 >= 1.0 )
        v49 = v48;
      else
        v49 = 1.0;
      if ( v49 * *(float *)(this + 23768) <= 0.0 )
      {
        if ( v48 < 1.0 )
          v48 = 1.0;
        v50 = v48 * *(float *)(this + 23768);
      }
      else
      {
        v50 = 0.0;
      }
      v51 = *(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248);
      v85 = *(float *)(v5 + 21320) + *(float *)(this + 23728);
      v82 = *(float *)(v5 + 21340) - (v50 + *(float *)(this + 23764));
      *(_DWORD *)(this + 32 * (v51 + 685)) = sub_42BD90(this, *(float *)(v5 + 21304), v82, v85, *(_DWORD *)(v5 + 21348));
    }
    goto LABEL_183;
  }
  if ( v7 != 5 )
  {
    if ( v7 != 6 && v7 != 7 && v7 != 11 )
    {
      if ( v7 != 8 && v7 != 16 )
        goto LABEL_183;
      if ( *(float *)(v5 + 21316) + *(float *)(this + 23764) < 5.0 )
      {
        if ( *(float *)(v5 + 21296) > 0.0 )
        {
LABEL_94:
          v29 = *(_DWORD *)(v5 + 21256);
LABEL_162:
          *(_DWORD *)(32 * (*(_DWORD *)(v29 + 25248) + 685) + this) = 11;
          goto LABEL_183;
        }
        goto LABEL_166;
      }
      if ( a4 == 1 )
      {
        v30 = *(_DWORD *)(v5 + 21256);
        if ( *(float *)(v30 + 23776) < 0.5 )
        {
LABEL_97:
          *(_DWORD *)(32 * (*(_DWORD *)(v30 + 25248) + 685) + this) = 10;
          goto LABEL_183;
        }
LABEL_110:
        *(_DWORD *)(32 * (*(_DWORD *)(v30 + 25248) + 685) + this) = 20;
        goto LABEL_183;
      }
      if ( a4 == 2 )
      {
        v12 = *(_DWORD *)(v5 + 21256);
        if ( *(float *)(v12 + 23776) >= 0.5 )
        {
          *(_DWORD *)(32 * (*(_DWORD *)(v12 + 25248) + 685) + this) = 20;
          goto LABEL_183;
        }
LABEL_100:
        v31 = *(_DWORD *)(v12 + 25248);
LABEL_101:
        *(_DWORD *)(32 * (v31 + 685) + this) = 11;
        goto LABEL_183;
      }
      if ( a4 != 3 )
      {
        if ( a4 != 4 )
        {
          if ( !a4 )
          {
            *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 20;
            goto LABEL_183;
          }
          goto LABEL_6;
        }
        if ( *(float *)(v5 + 21268) < 0.0 )
          goto LABEL_94;
        v30 = *(_DWORD *)(v5 + 21256);
        if ( *(float *)(v30 + 23776) < 0.5 )
          goto LABEL_94;
        goto LABEL_110;
      }
      if ( *(float *)(v5 + 21268) >= 0.0 )
      {
        v30 = *(_DWORD *)(v5 + 21256);
        if ( *(float *)(v30 + 23776) >= 0.5 )
          goto LABEL_110;
      }
LABEL_170:
      v30 = *(_DWORD *)(v5 + 21256);
      goto LABEL_97;
    }
    switch ( a4 )
    {
      case 1:
      case 2:
        v29 = *(_DWORD *)(v5 + 21256);
        if ( *(float *)(v29 + 23776) >= *(float *)(this + 23776) * 0.80000001 )
        {
          *(_DWORD *)(v5 + 21372) = 2;
          *(_DWORD *)(v5 + 21364) = 0;
          *(_DWORD *)(32 * (*(_DWORD *)(v29 + 25248) + 685) + this) = 0;
          goto LABEL_183;
        }
        if ( a4 != 1 )
          goto LABEL_162;
        v47 = *(_DWORD *)(v29 + 25248);
LABEL_161:
        *(_DWORD *)(32 * (v47 + 685) + this) = 10;
        goto LABEL_183;
      case 3:
        *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 0;
        *(_DWORD *)(v5 + 21372) = 2;
        if ( *(_DWORD *)(this + 21892) == *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 328)
          && (!(unsigned __int8)sub_4EED40(*(_DWORD *)(v5 + 21256))
           || *(float *)(v5 + 21304) >= 0.0
           || fabs(*(float *)(v5 + 21296)) >= 1.5) )
        {
          goto LABEL_35;
        }
        goto LABEL_120;
      case 4:
        *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 0;
        *(_DWORD *)(v5 + 21372) = 2;
        if ( *(_DWORD *)(this + 21892) == *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 328) )
        {
          if ( (unsigned __int8)sub_4EED40(*(_DWORD *)(v5 + 21256))
            && *(float *)(v5 + 21304) < 0.0
            && fabs(*(float *)(v5 + 21296)) < 1.5 )
          {
            *(_DWORD *)(v5 + 21364) = 0;
            goto LABEL_183;
          }
          goto LABEL_45;
        }
LABEL_120:
        *(_DWORD *)(v5 + 21364) = 0;
        goto LABEL_183;
    }
    v11 = *(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248);
    if ( a4 )
      goto LABEL_23;
    *(_DWORD *)(32 * (v11 + 685) + this) = 20;
    if ( *(float *)(this + 23776) >= 0.30000001 )
      v32 = *(float *)(this + 23776);
    else
      v32 = 0.30000001;
    v33 = *(_DWORD *)(v5 + 21256);
    if ( *(float *)(v33 + 23776) + 0.039999999 >= v32 )
    {
      v42 = 32 * *(_DWORD *)(v33 + 25248);
      v43 = *(float *)(v42 + this + 21896) - *(float *)(this + 23856);
      if ( v43 < 0.0 )
        v43 = 0.0;
      *(float *)(v42 + this + 21896) = v43;
    }
    else
    {
      *(float *)(32 * *(_DWORD *)(v33 + 25248) + this + 21896) = *(float *)(this + 23856)
                                                               + *(float *)(32 * *(_DWORD *)(v33 + 25248) + this + 21896);
      v34 = *(_DWORD *)(v5 + 21256);
      v35 = 32 * *(_DWORD *)(v34 + 25248);
      v36 = *(float *)(v35 + this + 21896);
      v37 = (_DWORD *)(v35 + this + 21896);
      if ( v36 > 2.0 || *(float *)(this + 23776) * 0.5 > *(float *)(v34 + 23776) )
      {
        *v37 = 0;
        v38 = *(float *)(v5 + 21304) - 5.0;
        if ( v38 >= 1.0 )
          v39 = v38;
        else
          v39 = 1.0;
        if ( v39 * *(float *)(this + 23768) <= 0.0 )
        {
          if ( v38 < 1.0 )
            v38 = 1.0;
          v40 = v38 * *(float *)(this + 23768);
        }
        else
        {
          v40 = 0.0;
        }
        v41 = *(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248);
        v84 = *(float *)(v5 + 21320) + *(float *)(this + 23728);
        v81 = *(float *)(v5 + 21340) - (v40 + *(float *)(this + 23764));
        *(_DWORD *)(this + 32 * (v41 + 685)) = sub_42BD90(
                                                 this,
                                                 *(float *)(v5 + 21304),
                                                 v81,
                                                 v84,
                                                 *(_DWORD *)(v5 + 21348));
      }
    }
    if ( *(_DWORD *)(this + 24024) == 18 )
    {
      v44 = sub_4F8370(*(_DWORD *)(this + 80));
      if ( v44 >= sub_4F8370(*(_DWORD *)(v5 + 21256)) )
      {
        *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 20;
      }
      else
      {
        *(_DWORD *)(this + 24024) = 19;
        *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 8;
      }
    }
    if ( !*(_DWORD *)(this + 23804) )
    {
      if ( !*(_DWORD *)(this + 23800) )
      {
LABEL_155:
        if ( *(_DWORD *)(this + 23804) )
        {
          v46 = 32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685);
          if ( *(_DWORD *)(v46 + this) == 8 )
            *(_DWORD *)(v46 + this) = 9;
        }
        goto LABEL_183;
      }
      v45 = 32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685);
      if ( *(_DWORD *)(v45 + this) == 9 )
        *(_DWORD *)(v45 + this) = 8;
    }
    if ( *(_DWORD *)(this + 23800) )
      goto LABEL_183;
    goto LABEL_155;
  }
  switch ( a4 )
  {
    case 1:
      if ( *(float *)(v5 + 21360) < 3.0 || *(float *)(v5 + 21304) < 8.0 )
      {
        v9 = *(_DWORD *)(v5 + 21256);
        if ( *(float *)(v9 + 23776) >= *(float *)(this + 23776) * 0.80000001 )
        {
          *(_DWORD *)(v5 + 21372) = 2;
          *(_DWORD *)(v5 + 21364) = 0;
          *(_DWORD *)(32 * (*(_DWORD *)(v9 + 25248) + 685) + this) = 0;
        }
        else
        {
          *(_DWORD *)(32 * (*(_DWORD *)(v9 + 25248) + 685) + this) = 10;
        }
      }
      else
      {
        v8 = *(_DWORD *)(v5 + 21256);
        if ( *(_DWORD *)(32 * (*(_DWORD *)(v8 + 25248) + 685) + this) != 22 )
        {
          *(_DWORD *)(v5 + 21372) = 2;
          *(_DWORD *)(v5 + 21364) = 0;
          *(_DWORD *)(32 * (*(_DWORD *)(v8 + 25248) + 685) + this) = 0;
        }
      }
      goto LABEL_183;
    case 2:
      if ( *(float *)(v5 + 21360) >= 3.0 && *(float *)(v5 + 21304) >= 8.0 )
      {
        v10 = *(_DWORD *)(v5 + 21256);
        if ( *(_DWORD *)(32 * (*(_DWORD *)(v10 + 25248) + 685) + this) == 22 )
          goto LABEL_183;
        *(_DWORD *)(v5 + 21372) = 2;
        *(_DWORD *)(v5 + 21364) = 0;
        v11 = *(_DWORD *)(v10 + 25248);
LABEL_23:
        *(_DWORD *)(32 * (v11 + 685) + this) = 0;
        goto LABEL_183;
      }
      v12 = *(_DWORD *)(v5 + 21256);
      if ( *(float *)(v12 + 23776) >= *(float *)(this + 23776) * 0.80000001 )
      {
        *(_DWORD *)(v5 + 21372) = 2;
        *(_DWORD *)(v5 + 21364) = 0;
LABEL_82:
        *(_DWORD *)(32 * (*(_DWORD *)(v12 + 25248) + 685) + this) = 0;
        goto LABEL_183;
      }
      goto LABEL_100;
    case 3:
      v13 = (_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this);
      if ( *v13 == 22 )
      {
        *v13 = 22;
      }
      else
      {
        *v13 = 0;
        *(_DWORD *)(v5 + 21372) = 2;
        if ( *(_DWORD *)(this + 24064) != -1 )
          goto LABEL_35;
        if ( *(_DWORD *)(this + 24072) != -1 )
          goto LABEL_35;
        v14 = (float *)(32 * *(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + this + 21900);
        if ( flt_5FD200 * 6.0 >= *v14 )
          goto LABEL_35;
        *v14 = *v14 * 0.25;
        v89 = *(float *)(*(_DWORD *)(v5 + 21256) + 23964);
        v87 = (double)(rand() % 100) * *(float *)(this + 23964);
        if ( (double)(rand() % 100) * v89 >= v87 )
          goto LABEL_35;
        *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 22;
      }
      *(_DWORD *)(v5 + 21372) = 3;
LABEL_35:
      *(_DWORD *)(v5 + 21364) = 8;
      goto LABEL_183;
    case 4:
      v15 = (_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this);
      if ( *v15 == 22 )
      {
        *v15 = 22;
      }
      else
      {
        *v15 = 0;
        *(_DWORD *)(v5 + 21372) = 2;
        if ( *(_DWORD *)(this + 24064) != -1 )
          goto LABEL_45;
        if ( *(_DWORD *)(this + 24068) != -1 )
          goto LABEL_45;
        v16 = 32 * *(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248);
        v17 = flt_5FD200 * 6.0 < *(float *)(v16 + this + 21900);
        v18 = (float *)(v16 + this + 21900);
        if ( !v17 )
          goto LABEL_45;
        *v18 = *v18 * 0.25;
        v90 = *(float *)(*(_DWORD *)(v5 + 21256) + 23964);
        v88 = (double)(rand() % 100) * *(float *)(this + 23964);
        if ( (double)(rand() % 100) * v90 >= v88 )
          goto LABEL_45;
        *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 22;
      }
      *(_DWORD *)(v5 + 21372) = 3;
LABEL_45:
      *(_DWORD *)(v5 + 21364) = 9;
      goto LABEL_183;
  }
  if ( a4 )
  {
    if ( a4 == 5 )
    {
      v12 = *(_DWORD *)(v5 + 21256);
      goto LABEL_82;
    }
    if ( a4 == 6 )
    {
      *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 0;
    }
    else
    {
      v26 = 32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685);
      v27 = *(_DWORD *)(v26 + this);
      v28 = (_DWORD *)(this + v26);
      if ( v27 != 22 )
        *v28 = 0;
    }
  }
  else
  {
    v19 = *(float *)(v5 + 21304) - 3.0;
    if ( v19 >= 1.0 )
      v20 = v19;
    else
      v20 = 1.0;
    if ( v20 * *(float *)(this + 23768) <= 0.0 )
    {
      if ( v19 < 1.0 )
        v19 = 1.0;
      v21 = v19 * *(float *)(this + 23768);
    }
    else
    {
      v21 = 0.0;
    }
    v83 = *(float *)(v5 + 21320) + *(float *)(this + 23728);
    v80 = *(float *)(v5 + 21340) - (v21 + *(float *)(this + 23764));
    v22 = sub_42BD90(this, *(float *)(v5 + 21304), v80, v83, *(_DWORD *)(v5 + 21348));
    if ( (v22 == 8 || v22 == 9) && *(float *)(this + 24296) < (double)*(float *)(this + 23852) )
    {
      *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = v22;
    }
    else if ( v22 == 20 && *(float *)(this + 24296) < (double)*(float *)(this + 23852) )
    {
      v23 = (_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this);
      if ( *v23 != 23 && *v23 != 21 )
      {
        *v23 = 20;
        if ( *(_BYTE *)(this + 24764) )
        {
          v24 = *(_DWORD *)(v5 + 21256);
          if ( !*(_WORD *)(this + 4 * *(_DWORD *)(v24 + 25248) + 24300)
            && *(float *)(v24 + 24168) < (double)*(float *)(this + 24168) )
          {
            if ( *(float *)(this + 23964) * 100.0 >= (double)(rand() % 100) )
            {
              *(_DWORD *)(this + 24756) = (__int64)(*(float *)(this + 23964) * 5.0);
              *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 13;
            }
            else
            {
              *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 23;
            }
          }
        }
      }
    }
    if ( *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) == 9 )
    {
      sub_42CBC0(0);
      if ( !*(_DWORD *)(this + 23804) )
        *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 20;
    }
    if ( *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) == 8 )
    {
      sub_42CBC0(1);
      if ( !*(_DWORD *)(this + 23800) )
        *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 20;
    }
    v25 = *(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248);
    if ( v25 == *(_DWORD *)(this + 24288) )
      *(_DWORD *)(32 * (v25 + 685) + this) = 1;
    if ( *(float *)(v5 + 21340) < 10.0 && !*(_DWORD *)(*(_DWORD *)(this + 23432) + 328) )
      *(float *)(this + 24296) = *(float *)(this + 23852) + 4.0;
  }
LABEL_183:
  if ( *(_DWORD *)(this + 21892) != *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 328) )
  {
    v52 = 32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685);
    v53 = *(_DWORD *)(v52 + this);
    if ( v53 == 10 || v53 == 11 )
      *(_DWORD *)(v52 + this) = 0;
  }
  v54 = *(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248);
  v55 = *(_DWORD *)(32 * (v54 + 685) + this);
  if ( v55 == 17 )
  {
    v56 = *(float *)(v5 + 21296);
    *(_DWORD *)(v5 + 21356) = 0;
    *(_DWORD *)(v5 + 21372) = 1;
    if ( v56 >= 0.0 )
      *(_DWORD *)(v5 + 21364) = 5;
    else
      *(_DWORD *)(v5 + 21364) = 4;
    goto LABEL_261;
  }
  if ( v55 != 10 )
  {
    switch ( v55 )
    {
      case 11:
        v60 = *(_DWORD *)(this + 24024);
        if ( v60 == 18 )
        {
          *(_DWORD *)(v5 + 21364) = 9;
          *(_DWORD *)(v5 + 21372) = 2 * (v54 == v86) + 2;
        }
        else if ( v60 == 7
               && (*(float *)(v5 + 21304) >= 10.0 || *(float *)(this + 23764) * 0.5 >= -*(float *)(v5 + 21316)) )
        {
          *(_DWORD *)(v5 + 21372) = 1;
          *(_DWORD *)(v5 + 21364) = 9;
        }
        else
        {
          *(_DWORD *)(v5 + 21372) = 2;
          *(_DWORD *)(v5 + 21364) = 9;
        }
        goto LABEL_261;
      case 8:
        if ( *(_DWORD *)(this + 24024) == 18 )
        {
          v61 = *(float *)(this + 23856) + *(float *)(this + 23708);
          *(float *)(this + 23708) = v61;
          if ( v61 > 5.0 )
            *(_DWORD *)(this + 24024) = 19;
        }
        if ( *(_DWORD *)(this + 24076) == -1 || *(float *)(v5 + 21296) > 2.0999999 )
        {
          *(_DWORD *)(this + 24680) = -1;
          if ( *(float *)(v5 + 21296) >= 2.0999999 || *(_DWORD *)(this + 23800) )
          {
            if ( *(float *)(v5 + 21304) > 0.0 )
            {
              v62 = *(float *)(v5 + 21316);
              *(_DWORD *)(v5 + 21364) = 5;
              v63 = v62 * -3.0;
              if ( v63 >= 0.001 )
                v91 = v63;
              else
                v91 = 0.001;
              v64 = *(float *)(v5 + 21304) - 5.0;
              if ( v64 >= 0.0 )
                v65 = v64;
              else
                v65 = 0.0;
              v66 = 1.0 / v91;
              if ( v66 * v65 <= 1.0 )
              {
                if ( v64 < 0.0 )
                  v64 = 0.0;
                v92 = v66;
                v67 = v64 * v92;
              }
              else
              {
                v67 = 1.0;
              }
              if ( (1.0 - v67) * 3.0 >= fabs(*(float *)(v5 + 21296))
                && *(float *)(this + 24296) <= (double)*(float *)(this + 23852) )
              {
                *(_DWORD *)(v5 + 21372) = 1;
                *(_DWORD *)(v5 + 21356) = *(_DWORD *)(this + 23932);
                goto LABEL_261;
              }
              goto LABEL_259;
            }
            goto LABEL_260;
          }
        }
        break;
      case 9:
        if ( *(_DWORD *)(this + 24024) == 18 )
        {
          v68 = *(float *)(this + 23856) + *(float *)(this + 23708);
          *(float *)(this + 23708) = v68;
          if ( v68 > 5.0 )
            *(_DWORD *)(this + 24024) = 19;
        }
        if ( *(_DWORD *)(this + 24080) == -1 || *(float *)(v5 + 21296) < -2.0999999 )
        {
          *(_DWORD *)(this + 24680) = 1;
          if ( *(float *)(v5 + 21296) > -2.0999999 && !*(_DWORD *)(this + 23804) )
          {
            *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 20;
            v70 = *(_DWORD *)(this + 23932);
            *(_DWORD *)(v5 + 21364) = 0;
            *(_DWORD *)(v5 + 21356) = v70;
            *(_DWORD *)(v5 + 21372) = 1;
            return;
          }
          if ( *(float *)(v5 + 21304) > -5.0 )
          {
            if ( *(float *)(v5 + 21316) > 0.0 )
            {
              if ( *(float *)(v5 + 21304) <= 0.0 || *(float *)(v5 + 21304) >= 6.0 )
                *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 20;
              else
                *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 20;
              goto LABEL_261;
            }
            v71 = *(float *)(v5 + 21316);
            *(_DWORD *)(v5 + 21364) = 4;
            v72 = v71 * -3.0;
            if ( v72 >= 0.001 )
              v93 = v72;
            else
              v93 = 0.001;
            v73 = *(float *)(v5 + 21304) - 5.0;
            if ( v73 >= 0.0 )
              v74 = v73;
            else
              v74 = 0.0;
            v75 = 1.0 / v93;
            if ( v75 * v74 <= 1.0 )
            {
              if ( v73 < 0.0 )
                v73 = 0.0;
              v94 = v75;
              v76 = v73 * v94;
            }
            else
            {
              v76 = 1.0;
            }
            if ( (1.0 - v76) * 3.0 >= fabs(*(float *)(v5 + 21296))
              && *(float *)(this + 24296) <= (double)*(float *)(this + 23852) )
            {
              *(_DWORD *)(v5 + 21372) = 1;
              *(_DWORD *)(v5 + 21356) = *(_DWORD *)(this + 23932);
              goto LABEL_261;
            }
LABEL_259:
            *(_DWORD *)(v5 + 21372) = 2;
            goto LABEL_261;
          }
LABEL_260:
          *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 0;
          goto LABEL_261;
        }
        break;
      default:
        goto LABEL_261;
    }
    *(_DWORD *)(32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685) + this) = 20;
    v69 = *(_DWORD *)(this + 23932);
    *(_DWORD *)(v5 + 21364) = 0;
    *(_DWORD *)(v5 + 21356) = v69;
    *(_DWORD *)(v5 + 21372) = 1;
    return;
  }
  if ( *(_DWORD *)(this + 24024) == 18 && v54 == v86 )
  {
    v57 = *(float *)(v5 + 21304);
    *(_DWORD *)(v5 + 21372) = 1;
    *(_DWORD *)(v5 + 21356) = 1090519040;
    v58 = v57 * 0.0099999998 + 1.0;
    if ( v58 > 1.5 )
      v58 = 1.5;
    v59 = flt_7D74E0;
    *(_BYTE *)(this + 24693) = 1;
    *(float *)(this + 24028) = v59 * v58;
    *(_DWORD *)(v5 + 21364) = 8;
  }
  else
  {
    *(_DWORD *)(v5 + 21372) = 2;
    *(_DWORD *)(v5 + 21364) = 8;
  }
LABEL_261:
  v77 = 32 * (*(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + 685);
  v78 = *(_DWORD *)(v77 + this);
  switch ( v78 )
  {
    case 1:
      *(_DWORD *)(v5 + 21356) = *(_DWORD *)(this + 23932);
      *(_DWORD *)(v5 + 21372) = 1;
      *(_DWORD *)(v5 + 21364) = 1;
      break;
    case 20:
      *(_DWORD *)(v5 + 21356) = *(_DWORD *)(this + 23932);
      goto LABEL_265;
    case 23:
      if ( *(float *)(v5 + 21304) > 20.0 )
        *(_DWORD *)(v77 + this) = 21;
      *(float *)(v5 + 21356) = *(float *)(v5 + 21304) + 1.0;
      goto LABEL_265;
    case 21:
      if ( !*(_DWORD *)(*(_DWORD *)(this + 23432) + 328) && *(float *)(v5 + 21304) < 7.0 )
        sub_42C150(7, 1000593162, 0.0);
      *(float *)(*(_DWORD *)(v5 + 21256) + 24760) = *(float *)(this + 23852) + 1.0;
      *(float *)(this + 24296) = *(float *)(this + 23852) + 2.0;
      *(_DWORD *)(v5 + 21372) = 2;
      goto LABEL_266;
    case 13:
      if ( !*(_DWORD *)(*(_DWORD *)(this + 23432) + 328) && *(float *)(v5 + 21304) < 5.4000001 )
        sub_42C150(7, 1000593162, 0.0);
      *(float *)(*(_DWORD *)(v5 + 21256) + 24760) = *(float *)(this + 23852) + 1.0;
      *(float *)(this + 24296) = *(float *)(this + 23852) + 4.0;
      if ( *(float *)(v5 + 21296) > 0.0 )
      {
        *(_DWORD *)(v5 + 21372) = 2;
        goto LABEL_266;
      }
LABEL_265:
      *(_DWORD *)(v5 + 21372) = 1;
LABEL_266:
      *(_DWORD *)(v5 + 21364) = 0;
      break;
  }
  if ( v86 != -2 && *(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) == v86 )
  {
    if ( *(float *)(v5 + 21304) > 0.0 )
    {
      *(_DWORD *)(v5 + 21372) = 1;
      *(_DWORD *)(v5 + 21356) = 1090519040;
    }
    v79 = *(_DWORD *)(this + 24024);
    *(_BYTE *)(this + 24693) = 1;
    if ( v79 == 19 || v79 == 18 )
      *(_DWORD *)(this + 24024) = 19 - ((unsigned __int8)sub_4F83B0(*(_DWORD *)(this + 80)) != 0);
  }
  if ( *(_DWORD *)(v5 + 21364) == 4 && *(float *)(*(_DWORD *)(v5 + 21256) + 23776) * 1.5 < *(float *)(this + 23776) )
    *(_DWORD *)(v5 + 21364) = 8;
  if ( *(_DWORD *)(v5 + 21364) == 5 && *(float *)(*(_DWORD *)(v5 + 21256) + 23776) * 1.5 < *(float *)(this + 23776) )
    *(_DWORD *)(v5 + 21364) = 9;
}
