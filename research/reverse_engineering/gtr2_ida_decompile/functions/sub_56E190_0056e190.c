void __thiscall sub_56E190(int this)
{
  int v2; // edi
  int v3; // ebp
  int v4; // eax
  int v5; // edi
  int v6; // eax
  double v7; // st7
  int v8; // edi
  float v9; // ebx
  int v10; // ebp
  float v11; // ebx
  _DWORD *v12; // ebp
  int v13; // ebx
  bool v14; // cl
  bool v15; // al
  float *v16; // eax
  double v17; // st7
  double v18; // st7
  int v19; // edi
  int v20; // ebx
  double v21; // st7
  float v22; // edx
  float v23; // eax
  double v24; // st7
  float v25; // ecx
  float v26; // edx
  int v27; // ecx
  char v28; // al
  int v29; // ecx
  double v30; // st7
  int v31; // edi
  int *v32; // ebp
  int *v33; // ebx
  char v34; // bl
  unsigned __int8 v35; // al
  double v36; // st7
  double v37; // st7
  int v38; // edi
  int v39; // eax
  int v40; // edi
  double v41; // st7
  double v42; // st7
  long double v43; // st7
  float v44; // [esp+0h] [ebp-D0h]
  float v45; // [esp+0h] [ebp-D0h]
  float v46; // [esp+4h] [ebp-CCh]
  float v47; // [esp+10h] [ebp-C0h]
  float v48; // [esp+18h] [ebp-B8h]
  float v49; // [esp+1Ch] [ebp-B4h]
  float v50; // [esp+20h] [ebp-B0h]
  float v51; // [esp+24h] [ebp-ACh]
  float v52; // [esp+58h] [ebp-78h]
  float v53; // [esp+70h] [ebp-60h]
  int v54; // [esp+70h] [ebp-60h]
  int v55; // [esp+78h] [ebp-58h]
  float v56; // [esp+7Ch] [ebp-54h] BYREF
  float v57; // [esp+80h] [ebp-50h]
  float v58; // [esp+84h] [ebp-4Ch]
  float v59; // [esp+88h] [ebp-48h]
  float v60; // [esp+8Ch] [ebp-44h] BYREF
  float v61; // [esp+90h] [ebp-40h] BYREF
  float v62; // [esp+94h] [ebp-3Ch]
  int v63; // [esp+98h] [ebp-38h]
  float v64; // [esp+9Ch] [ebp-34h]
  int v65; // [esp+A0h] [ebp-30h]
  int v66; // [esp+A4h] [ebp-2Ch]
  int v67; // [esp+A8h] [ebp-28h]
  float v68; // [esp+ACh] [ebp-24h]
  int v69; // [esp+B0h] [ebp-20h]
  float v70; // [esp+B4h] [ebp-1Ch]

  sub_5DB2B0(
    *(_DWORD *)(this + 12),
    *(_DWORD *)(this + 16),
    *(_DWORD *)(this + 20),
    *(float *)(this + 24),
    *(float *)(this + 28),
    *(float *)(this + 32));
  v2 = this + 596;
  v3 = 4;
  do
  {
    if ( *(_DWORD *)(v2 - 132) && *(_BYTE *)(v2 - 68) )
      sub_5DB2B0(
        *(_DWORD *)(v2 - 128),
        *(_DWORD *)(v2 - 124),
        *(_DWORD *)(v2 - 120),
        *(float *)(v2 - 116),
        *(float *)(v2 - 112),
        *(float *)(v2 - 108));
    if ( *(_DWORD *)(v2 - 64) && *(_BYTE *)v2 )
      sub_5DB2B0(
        *(_DWORD *)(v2 - 60),
        *(_DWORD *)(v2 - 56),
        *(_DWORD *)(v2 - 52),
        *(float *)(v2 - 48),
        *(float *)(v2 - 44),
        *(float *)(v2 - 40));
    if ( *(_DWORD *)(v2 + 24) )
    {
      sub_5EC5C0(&byte_FFFFFF[0x1000000 * (unsigned int)(unsigned __int64)(*(float *)(v2 + 32) * 254.0 + 0.5)]);
      if ( *(_DWORD *)(v2 + 28) )
        sub_5EC5C0(&byte_FFFFFF[0x1000000 * (unsigned int)(unsigned __int64)(*(float *)(v2 + 32) * 254.0 + 0.5)]);
    }
    v2 += 296;
    --v3;
  }
  while ( v3 );
  v4 = *(_DWORD *)(this + 12100);
  v59 = 0.0;
  if ( v4 > 0 )
  {
    v58 = 0.0;
    do
    {
      v5 = *(_DWORD *)(this + 12104);
      v6 = *(_DWORD *)(v5 + LODWORD(v58));
      v7 = *(float *)(v5 + LODWORD(v58) + 4);
      v8 = LODWORD(v58) + v5;
      v6 *= 296;
      *(float *)&v65 = v7 + *(float *)(v6 + this + 468);
      v9 = *(float *)(v6 + this + 488);
      *(float *)&v66 = *(float *)(v6 + this + 472) + *(float *)(v8 + 8);
      v10 = v6 + this + 352;
      v53 = v9;
      v11 = *(float *)(v6 + this + 484);
      *(float *)&v67 = *(float *)(v6 + this + 476) + *(float *)(v8 + 12);
      sub_5DB2B0(v65, v66, v67, *(float *)(v6 + this + 480), v11, v53);
      if ( *(_DWORD *)(this + 3040) )
      {
        sub_5DB320(0, 0, 0);
      }
      else
      {
        sub_5DA890(&v61, &v60, 0);
        sub_5DB320(LODWORD(v61), LODWORD(v60), 1);
      }
      sub_5E37F0(*(_DWORD *)(v10 + 280), 0, 0);
      v12 = (_DWORD *)(this + 3796);
      v13 = 3;
      do
      {
        if ( *v12 )
          sub_5E37F0(*(_DWORD *)(this + 3808), *v12, 0);
        ++v12;
        --v13;
      }
      while ( v13 );
    }
    while ( v54 + 1 < *(_DWORD *)(this + 12100) );
  }
  v14 = !*(_BYTE *)(this + 3048) && dword_91BF28 == dword_91BF40 && *(_DWORD *)(dword_91BF40 + 52) == 1;
  v15 = *(_DWORD *)(*(_DWORD *)this + 22468) == *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468) && dword_B711C4 > 0;
  if ( !v14 && (v15 || dword_BE1204 == 2) )
  {
    v16 = (float *)sub_40DCE0(&dword_91BF20);
    if ( v16 )
    {
      v59 = *(float *)(this + 12) + v16[3];
      v60 = *(float *)(this + 16) + v16[4];
      v17 = *(float *)(this + 20);
      v57 = v60;
      v18 = v17 + v16[5];
      v56 = v59;
      v61 = v18;
      v58 = v61;
      if ( v61 * v61 + v60 * v60 + v59 * v59 < 2500.0 && !*(_DWORD *)(this + 3040) )
      {
        v19 = this + 352;
        v20 = 4;
        do
        {
          sub_56B9F0((_DWORD *)this, v19);
          v19 += 296;
          --v20;
        }
        while ( v20 );
      }
    }
  }
  if ( *(_DWORD *)(this + 2460) )
  {
    v21 = *(float *)(this + 2984) * 2.0943952;
    v22 = *(float *)(this + 3008);
    v23 = *(float *)(this + 3012);
    v56 = *(float *)(this + 3004);
    v56 = v56 * v21;
    v62 = 1.0;
    v63 = 0;
    v57 = v22 * v21;
    v64 = 0.0;
    *(float *)&v65 = 0.0;
    *(float *)&v66 = 1.0;
    *(float *)&v67 = 0.0;
    v68 = 0.0;
    v58 = v23 * v21;
    v69 = 0;
    v70 = 1.0;
    sub_614F40(&v56);
    v59 = -asin(*(float *)&v67);
    if ( 1.0 == fabs(*(float *)&v67) )
    {
      v61 = 0.0;
      v60 = atan2(-v68, v62);
    }
    else
    {
      v60 = atan2(v64, v70);
      v61 = atan2(*(float *)&v65, *(float *)&v66);
    }
    sub_5DB1E0(v59, v60, v61);
  }
  if ( *(_DWORD *)(this + 2464) )
  {
    v24 = *(float *)(this + 2984) * 2.0943952;
    v25 = *(float *)(this + 3008);
    v26 = *(float *)(this + 3012);
    v56 = *(float *)(this + 3004);
    v56 = v56 * v24;
    v62 = 1.0;
    v63 = 0;
    v57 = v25 * v24;
    v64 = 0.0;
    *(float *)&v65 = 0.0;
    *(float *)&v66 = 1.0;
    *(float *)&v67 = 0.0;
    v68 = 0.0;
    v58 = v26 * v24;
    v69 = 0;
    v70 = 1.0;
    sub_614F40(&v56);
    v59 = -asin(*(float *)&v67);
    if ( 1.0 == fabs(*(float *)&v67) )
    {
      v61 = 0.0;
      v60 = atan2(-v68, v62);
    }
    else
    {
      v60 = atan2(v64, v70);
      v61 = atan2(*(float *)&v65, *(float *)&v66);
    }
    sub_5DB1E0(v59, v60, v61);
  }
  v27 = *(_DWORD *)(this + 2552);
  if ( v27 )
  {
    sub_54D140(v27, *(float *)(this + 2984));
    sub_54CB20(*(float **)(this + 2552), *(float *)(this + 2988));
    if ( *(_BYTE *)(this + 3057) )
      sub_54CB40(*(float **)(this + 2552), *(float *)(this + 2992));
    else
      sub_54CB40(*(float **)(this + 2552), 0.0);
  }
  v28 = sub_521050(&dword_BE120C);
  v29 = *(_DWORD *)(this + 2552);
  if ( v28 )
  {
    if ( v29 )
    {
      v30 = dbl_FB1D08;
LABEL_58:
      v52 = v30;
      sub_54D920(v29, v52);
    }
  }
  else if ( v29 )
  {
    v30 = dbl_FB1D10;
    goto LABEL_58;
  }
  if ( *(_DWORD *)(this + 2452) && *(_BYTE *)(this + 3050) )
  {
    if ( *(_DWORD *)(*(_DWORD *)this + 22468) == *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468) )
    {
      sub_5DB320(1, 1, 0);
      v31 = 0;
      *(float *)&v55 = *(float *)(this + 2984) + 1.0 - 0.025;
      if ( *(int *)(this + 2500) > 0 )
      {
        v32 = (int *)(this + 2504);
        v33 = (int *)(this + 2516);
        do
        {
          sub_5F1530(*v32, *v33, v55);
          ++v31;
          ++v32;
          v33 += 4;
        }
        while ( v31 < *(_DWORD *)(this + 2500) );
      }
    }
    else
    {
      sub_5DB320(0, 0, 0);
    }
  }
  v34 = 0;
  if ( *(_BYTE *)(this + 3072) )
  {
    if ( fmod(dbl_FB1D18, *(float *)(this + 3076)) >= 0.33500001 )
      goto LABEL_72;
  }
  else if ( (flt_FB1F28 + flt_FB1F24) * 0.5 <= *(float *)(this + 2980) )
  {
    goto LABEL_72;
  }
  v34 = 1;
LABEL_72:
  if ( v34 != *(_BYTE *)(this + 3056) )
  {
    *(_BYTE *)(this + 3056) = v34;
    sub_41F350();
    sub_41F350();
  }
  if ( *(_BYTE *)(this + 3061) != *(_BYTE *)(this + 3062) )
  {
    sub_56BE90(this);
    *(_BYTE *)(this + 3062) = *(_BYTE *)(this + 3061);
    sub_41F350();
    sub_41F350();
    sub_41F350();
    sub_41F350();
  }
  if ( *(_BYTE *)(this + 3057) != *(_BYTE *)(this + 3058) )
  {
    sub_41F350();
    sub_41F350();
    *(_BYTE *)(this + 3058) = *(_BYTE *)(this + 3057);
  }
  if ( *(_BYTE *)(this + 3059) != *(_BYTE *)(this + 3060) )
  {
    sub_41F350();
    *(_BYTE *)(this + 3060) = *(_BYTE *)(this + 3059);
  }
  if ( *(_DWORD *)(this + 2468) )
  {
    v35 = *(_BYTE *)(this + 3063);
    if ( v35 && *(int *)(this + 3068) > 2 )
    {
      if ( dword_BE1204 == 2 )
        v36 = sub_5210A0(&dword_BE120C);
      else
        v36 = dbl_FB1D18;
      v47 = flt_B71044 * v36;
      sub_4015C0(v47);
      off_16C96D0();
      return;
    }
    if ( v35 != *(_DWORD *)(this + 3064) )
    {
      *(_DWORD *)(this + 3064) = v35;
      sub_5E37F0(v35, 0, 0);
    }
  }
  if ( *(_DWORD *)(this + 2472) )
  {
    if ( dword_BE1204 == 2 )
      v37 = sub_5210A0(&dword_BE120C);
    else
      v37 = dbl_FB1D18;
    v38 = 0;
    v48 = v37 - *(float *)(this + 3084);
    if ( v48 > 0.0 && v48 < (double)*(float *)(this + 3088) )
    {
      v46 = flt_B71020 * v48 + 0.5;
      v38 = sub_4015C0(v46);
    }
    if ( v38 != *(_DWORD *)(this + 3080) )
    {
      *(_DWORD *)(this + 3080) = v38;
      sub_5E37F0(0, 0, 0);
      sub_5E37F0(v38, 0, 0);
    }
  }
  if ( *(_DWORD *)(this + 2484) )
  {
    if ( sub_592960(&dword_FB1EF8) <= 0.0 || (unsigned __int8)sub_577A80(*(_DWORD *)this + 16) )
    {
      sub_5DB320(0, 0, 0);
    }
    else if ( *(_DWORD *)(this + 2488) )
    {
      v39 = sub_5E80D0(0);
      v40 = v39;
      if ( v39 )
      {
        if ( *(int *)(v39 + 4) > 1 )
        {
          if ( !byte_B6413C || sub_521050(&dword_BE120C) )
          {
            v41 = sub_4E4DE0();
            v44 = v41;
            if ( v41 <= 200.0 )
            {
              if ( v44 >= 60.0 )
              {
                *(_DWORD *)(v40 + 84) = 1;
                *(float *)(v40 + 88) = 0.1 - v44 * 0.00050000002;
              }
              else
              {
                *(float *)(v40 + 88) = 0.1;
                *(_DWORD *)(v40 + 84) = 1;
              }
              sub_5DB320(1, 1, 0);
            }
            else
            {
              *(float *)(v40 + 88) = 0.0099999998;
              *(_DWORD *)(v40 + 84) = 1;
              sub_5DB320(1, 1, 0);
            }
          }
          else
          {
            *(_DWORD *)(v40 + 84) = 6;
          }
        }
      }
    }
  }
  if ( *(_BYTE *)(this + 12112) && (*(_DWORD *)(*(_DWORD *)this + 22580) & 2) != 0 )
  {
    if ( (!byte_B6F118 || *(_DWORD *)dword_B72314 == 6)
      && (*(_DWORD *)dword_B72314 != 8 || byte_91E048 == 2 && flt_91DE0C <= 0.0) )
    {
      v49 = *(float *)(this + 12) - *(float *)(dword_91E084 + 2716);
      v50 = *(float *)(this + 16) - *(float *)(dword_91E084 + 2720);
      v51 = *(float *)(this + 20) - *(float *)(dword_91E084 + 2724);
      v43 = sqrt(v51 * v51 + v50 * v50 + v49 * v49);
      v45 = v43;
      if ( v43 > flt_B71C30 )
      {
        if ( v45 < (double)flt_B71C54 )
          v42 = (v45 - flt_B71C30) / (flt_B71C54 - flt_B71C30) * (flt_B71C9C - flt_B71C78) + flt_B71C78;
        else
          v42 = flt_B71C9C;
      }
      else
      {
        v42 = flt_B71C78;
      }
    }
    else
    {
      v42 = 1.0;
    }
    if ( dword_FB27AC )
      sub_5E8460(2, (unsigned __int64)(v42 * 255.0));
  }
}
