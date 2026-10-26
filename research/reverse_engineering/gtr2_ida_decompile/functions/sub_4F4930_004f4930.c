double __thiscall sub_4F4930(int this, int a2, int a3, int a4)
{
  int v5; // eax
  float v6; // ecx
  float *v7; // eax
  double v8; // st7
  float v9; // ecx
  float v10; // eax
  double v11; // st7
  double v12; // st7
  _DWORD *v13; // edx
  int v14; // esi
  int v15; // ecx
  float *v16; // eax
  float *v17; // ebp
  double v18; // st7
  double v19; // st6
  double v20; // st5
  double v21; // st4
  double v22; // st7
  double v23; // st7
  long double v24; // st6
  int v25; // esi
  bool v26; // cc
  float v27; // ebp
  float v28; // edx
  char v29; // bl
  double v30; // st7
  double v31; // st7
  double v32; // st6
  double v33; // st5
  double v34; // st7
  double v35; // st7
  float v36; // edx
  char v37; // dl
  char v38; // cl
  double v39; // st7
  double v40; // st6
  double v41; // st5
  double v42; // st5
  double v43; // st7
  double v44; // st7
  int v45; // edx
  double v46; // st7
  double v47; // st6
  float *v48; // ecx
  double v49; // st7
  double v50; // st6
  float v51; // ecx
  int v52; // eax
  double result; // st7
  int v54; // edx
  int v55; // eax
  float v56; // ecx
  int v57; // edx
  int v58; // esi
  float *v59; // ebp
  float *v60; // ebx
  double v61; // st7
  double v62; // st6
  double v63; // st4
  double v64; // st7
  int v65; // eax
  double v66; // st6
  double v67; // st7
  int v68; // esi
  int v69; // ecx
  int v70; // eax
  double v71; // st7
  double v72; // st6
  _DWORD *v73; // eax
  int v74; // ecx
  int *v75; // eax
  int v76; // edx
  float v77; // ecx
  int v78; // ecx
  float v79; // [esp+0h] [ebp-D4h]
  float v80; // [esp+0h] [ebp-D4h]
  float v81; // [esp+0h] [ebp-D4h]
  float v82; // [esp+0h] [ebp-D4h]
  int v83; // [esp+4h] [ebp-D0h]
  float *v84; // [esp+18h] [ebp-BCh]
  float v85; // [esp+18h] [ebp-BCh]
  float v86; // [esp+18h] [ebp-BCh]
  float v87; // [esp+18h] [ebp-BCh]
  float v88; // [esp+18h] [ebp-BCh]
  float v89; // [esp+1Ch] [ebp-B8h]
  float v90; // [esp+20h] [ebp-B4h] BYREF
  float v91; // [esp+24h] [ebp-B0h]
  float v92; // [esp+28h] [ebp-ACh]
  int v93; // [esp+2Ch] [ebp-A8h] BYREF
  float v94; // [esp+30h] [ebp-A4h]
  int v95; // [esp+34h] [ebp-A0h]
  float v96; // [esp+38h] [ebp-9Ch]
  int v97; // [esp+3Ch] [ebp-98h] BYREF
  float v98; // [esp+40h] [ebp-94h]
  float v99; // [esp+44h] [ebp-90h]
  float v100; // [esp+48h] [ebp-8Ch]
  float v101; // [esp+4Ch] [ebp-88h] BYREF
  char String2[4]; // [esp+50h] [ebp-84h] BYREF
  float v103; // [esp+54h] [ebp-80h]
  float v104; // [esp+58h] [ebp-7Ch]
  int v105; // [esp+5Ch] [ebp-78h] BYREF
  float v106; // [esp+60h] [ebp-74h]
  float v107; // [esp+64h] [ebp-70h]
  int v108; // [esp+68h] [ebp-6Ch] BYREF
  int v109; // [esp+6Ch] [ebp-68h]
  float v110; // [esp+70h] [ebp-64h]
  int v111; // [esp+74h] [ebp-60h]
  float v112; // [esp+78h] [ebp-5Ch] BYREF
  float v113; // [esp+7Ch] [ebp-58h] BYREF
  float v114; // [esp+80h] [ebp-54h]
  float v115; // [esp+84h] [ebp-50h]
  int v116; // [esp+88h] [ebp-4Ch] BYREF
  float v117; // [esp+8Ch] [ebp-48h] BYREF
  float v118; // [esp+90h] [ebp-44h]
  int v119; // [esp+94h] [ebp-40h] BYREF
  int v120; // [esp+98h] [ebp-3Ch] BYREF
  float v121; // [esp+9Ch] [ebp-38h]
  int v122[2]; // [esp+A0h] [ebp-34h] BYREF
  float v123; // [esp+A8h] [ebp-2Ch]
  float v124; // [esp+B0h] [ebp-24h]
  int v125; // [esp+BCh] [ebp-18h]
  float v126; // [esp+C0h] [ebp-14h]
  int v127; // [esp+C4h] [ebp-10h]
  char v128[12]; // [esp+C8h] [ebp-Ch] BYREF

  v5 = *(_DWORD *)(*(_DWORD *)(this + 140) + 8);
  v115 = *(float *)(v5 + 228);
  v6 = *(float *)(v5 + 236);
  v116 = *(int *)(v5 + 232);
  v117 = v6;
  sub_4F2290((float *)(v5 + 212), &v112);
  sub_54FDF0(&unk_FADD40, **(_DWORD **)(this + 4), &v120, v128);
  sub_5D7810(&v117, &v101, *(_DWORD *)(this + 4) + 224);
  v7 = *(float **)(this + 4);
  v8 = v126 - v7[53];
  v9 = v118;
  v117 = 0.0;
  v118 = 0.0;
  *(float *)&v119 = 0.0;
  *(float *)&v116 = v8;
  v10 = *v7;
  v104 = v9;
  if ( *(int *)(LODWORD(v10) + 22548) < 0 )
    sub_53E8B0(LODWORD(v10));
  sub_4014E0();
  if ( v113 == 0.0 && v114 == 0.0 && v115 == 0.0 )
  {
    v117 = v98;
    v116 = v97;
    v118 = v99;
    if ( byte_91BDD4 )
      v12 = 2.0;
    else
      v12 = -2.0;
    *(float *)&v116 = v12 + *(float *)&v116;
    v11 = v112 + 3.1417794;
  }
  else
  {
    v83 = *(_DWORD *)(this + 4) + 224;
    v114 = v100;
    sub_5D7810(&v113, &v116, v83);
    v11 = v124 * 0.01745433 - *(float *)(*(_DWORD *)(this + 4) + 212) + 1.5708897;
  }
  v13 = *(_DWORD **)(this + 4);
  v101 = v11;
  v14 = v13[72];
  v15 = 0;
  if ( v14 <= 0 )
  {
    v17 = v84;
  }
  else
  {
    v16 = (float *)v13[73];
    do
    {
      v17 = v16;
      v84 = v16;
      if ( *(_DWORD *)v16 == 6 )
        break;
      ++v15;
      v16 += 192;
    }
    while ( v15 < *(_DWORD *)(*(_DWORD *)(this + 4) + 288) );
  }
  if ( v15 == v14 )
  {
    v17 = 0;
    v84 = 0;
    goto LABEL_35;
  }
  if ( *(_DWORD *)(dword_BE1BD8 + 2824 * *(_DWORD *)(*v13 + 22472) + 272) > 1u )
  {
    v18 = 1.55;
    v19 = -0.30000001;
  }
  else
  {
    v18 = 0.0;
    v19 = -2.1500001;
  }
  if ( byte_91BDD4 )
  {
    v20 = 3.0999999;
    v21 = 1.8;
  }
  else
  {
    v20 = -3.0999999;
    v21 = -1.8;
  }
  v94 = v20 + v17[21];
  v89 = v21 + v17[21];
  v96 = v18 + v17[23];
  *(float *)&v95 = v19 + v17[23];
  if ( byte_91BDD4 )
  {
    if ( fabs(*(float *)&v97) < 4.0 )
    {
      v22 = *(float *)&v97 - (flt_91BCA0 - 1.2);
      if ( v22 <= v89 )
        *(float *)&v97 = v89;
      else
        *(float *)&v97 = v22;
      goto LABEL_35;
    }
    v23 = v94 + 0.5;
  }
  else
  {
    v23 = v94 - 0.5;
  }
  v24 = fabs(v99) * 0.40000001;
  if ( v24 >= 1.0 )
    v24 = 1.0;
  *(float *)&v97 = (v23 - *(float *)&v97) * v24 + *(float *)&v97;
LABEL_35:
  v25 = v125;
  v26 = v125 < 10;
  *(_DWORD *)(this + 268) = 0;
  v93 = 0;
  if ( v26 )
  {
    sub_4F0AA0((_DWORD *)this, &v93, &v116, v101, 0);
    sub_4F0B80((_DWORD *)this, &v93, &v97, 0);
    v27 = *(float *)(this + 124);
    v28 = *(float *)(this + 128);
    v105 = *(int *)(this + 120);
    v106 = v27;
    v107 = v28;
    if ( v25 == 2 && v127 )
    {
      sub_405E20(*(float **)(v127 + 112), String2);
      *(float *)&v105 = *(float *)&v105 - *(float *)String2;
      v107 = v107 - v104;
    }
    if ( (*(_DWORD *)(*(_DWORD *)(this + 4) + 12) & 4) == 0 )
      goto LABEL_42;
    if ( byte_91BDD4 )
    {
      if ( *(float *)&v105 >= 0.0 )
      {
LABEL_42:
        v29 = 0;
        *(float *)String2 = *(float *)&v105;
        v103 = v27;
        v104 = v107;
        goto LABEL_43;
      }
    }
    else if ( *(float *)&v105 <= 0.0 )
    {
      goto LABEL_42;
    }
    v29 = 1;
    if ( byte_91BDD4 )
      v30 = 1.8;
    else
      v30 = -1.8;
    *(float *)String2 = v30;
    v103 = v106;
    v104 = -4.5;
LABEL_43:
    if ( !v84 )
    {
LABEL_76:
      if ( v29 )
      {
        sub_4F0B80((_DWORD *)this, &v93, String2, 0);
        *(float *)String2 = -*(float *)String2;
        sub_4F0B80((_DWORD *)this, &v93, String2, 1);
      }
      v79 = v126 + 3.1415927;
      sub_4F0AA0((_DWORD *)this, &v93, &v105, v79, 0);
      v36 = *(float *)(this + 132);
      goto LABEL_120;
    }
    v90 = *(float *)&v97;
    v92 = v99;
    v91 = v98;
    if ( fabs(v99 - *(float *)&v95) <= fabs(v99 - v96) )
      v85 = *(float *)&v95;
    else
      v85 = v96;
    if ( byte_91BDD4 )
    {
      if ( v90 <= (double)v94 || v94 <= (double)*(float *)String2 )
      {
LABEL_68:
        if ( v90 <= (double)v89 || v89 <= (double)*(float *)String2 )
          goto LABEL_76;
LABEL_73:
        v35 = (v89 - v90) / (*(float *)String2 - v90) * (v104 - v92) + v92;
        if ( v96 > v35 && v35 > *(float *)&v95 )
        {
          v90 = v89;
          v92 = v85;
          sub_4F0B80((_DWORD *)this, &v93, &v90, 0);
        }
        goto LABEL_76;
      }
    }
    else if ( v90 >= (double)v94 || v94 >= (double)*(float *)String2 )
    {
      goto LABEL_71;
    }
    v31 = *(float *)String2 - v90;
    v32 = v104 - v92;
    v33 = (v94 - v90) / v31 * v32 + v92;
    if ( v96 > v33 && v33 > *(float *)&v95 )
    {
      v90 = v94;
      v92 = v85;
      sub_4F0B80((_DWORD *)this, &v93, &v90, 0);
      v90 = v89;
      v92 = v85;
      sub_4F0B80((_DWORD *)this, &v93, &v90, 0);
      goto LABEL_71;
    }
    v34 = v31 * ((v85 - v92) / v32) + v90;
    if ( byte_91BDD4 )
    {
      if ( v89 >= v34 || v34 >= v94 )
        goto LABEL_68;
      goto LABEL_67;
    }
    if ( v94 < v34 && v34 < v89 )
    {
LABEL_67:
      v90 = v89;
      v92 = v85;
      sub_4F0B80((_DWORD *)this, &v93, &v90, 0);
    }
LABEL_71:
    if ( v90 >= (double)v89 || v89 >= (double)*(float *)String2 )
      goto LABEL_76;
    goto LABEL_73;
  }
  sub_4F0AA0((_DWORD *)this, &v93, &v108, v106, 0);
  if ( v25 != 11 || **(_DWORD **)(this + 4) != ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) )
  {
    if ( !v17 )
    {
LABEL_119:
      sub_4F0B80((_DWORD *)this, &v93, &v97, 0);
      v106 = v117;
      *(float *)&v105 = sin(v101) + *(float *)&v116;
      v107 = cos(v101) + v118;
      sub_4F0B80((_DWORD *)this, &v93, &v105, 0);
      v80 = v101 + 3.1415927;
      sub_4F0AA0((_DWORD *)this, &v93, &v116, v80, 0);
      v36 = v101;
LABEL_120:
      *(float *)(this + 752) = v36;
      goto LABEL_121;
    }
    v92 = v110;
    v112 = fabs(v99 - v96);
    v90 = *(float *)&v108;
    v91 = *(float *)&v109;
    v100 = fabs(v99 - *(float *)&v95);
    if ( v112 >= (double)v100 )
      v86 = *(float *)&v95;
    else
      v86 = v96;
    v37 = byte_91BDD4;
    v38 = 0;
    if ( byte_91BDD4 )
    {
      if ( v90 >= (double)v89 || v89 >= (double)*(float *)&v97 )
      {
LABEL_104:
        if ( v37 )
        {
          if ( v90 >= (double)v94 || v94 >= (double)*(float *)&v97 )
            goto LABEL_119;
LABEL_110:
          v44 = (v94 - v90) / (*(float *)&v97 - v90) * (v99 - v92) + v92;
          if ( v96 <= v44 || v44 <= *(float *)&v95 )
            goto LABEL_119;
          if ( v38 || !v37 )
          {
            if ( v90 <= (double)v89 )
            {
LABEL_118:
              v90 = v94;
              v92 = v86;
              sub_4F0B80((_DWORD *)this, &v93, &v90, 0);
              goto LABEL_119;
            }
          }
          else if ( v90 >= (double)v89 )
          {
            goto LABEL_118;
          }
          v90 = v89;
          v92 = v86;
          sub_4F0B80((_DWORD *)this, &v93, &v90, 0);
          goto LABEL_118;
        }
LABEL_108:
        if ( v90 <= (double)v94 || v94 <= (double)*(float *)&v97 )
          goto LABEL_119;
        goto LABEL_110;
      }
    }
    else if ( v90 <= (double)v89 || v89 <= (double)*(float *)&v97 )
    {
      goto LABEL_108;
    }
    v39 = *(float *)&v97 - v90;
    v40 = v99 - v92;
    v41 = (v89 - v90) / v39 * v40 + v92;
    if ( v96 <= v41 || v41 <= *(float *)&v95 )
    {
      if ( v112 >= (double)v100 )
        v42 = v96;
      else
        v42 = *(float *)&v95;
      v43 = v39 * ((v42 - v92) / v40) + v90;
      if ( byte_91BDD4 )
      {
        if ( v89 >= v43 || v43 >= v94 )
          goto LABEL_104;
      }
      else if ( v94 >= v43 || v43 >= v89 )
      {
        goto LABEL_108;
      }
    }
    v90 = v89;
    v92 = v86;
    sub_4F0B80((_DWORD *)this, &v93, &v90, 0);
    v37 = byte_91BDD4;
    v38 = 1;
    goto LABEL_104;
  }
  sub_4F0AA0((_DWORD *)this, &v93, (_DWORD *)(this + 120), 0.0, 0);
  *(_DWORD *)(this + 752) = *(_DWORD *)(this + 132);
LABEL_121:
  v45 = *(_DWORD *)(this + 268);
  if ( v45
    && (v46 = *(float *)(60 * v45 + this + 244) - *(float *)&v108,
        v47 = *(float *)(60 * v45 + this + 252) - v110,
        v48 = (float *)(60 * v45 + this),
        v47 * v47 + v46 * v46 < 0.25) )
  {
    v49 = v48[61];
    v50 = v48[62];
    v51 = v48[63];
    v52 = *(_DWORD *)(*(_DWORD *)(this + 140) + 8) + 228;
    *(float *)v52 = v49;
    *(float *)(v52 + 8) = v51;
    *(float *)(v52 + 4) = v50;
    v81 = *(float *)(this + 752);
    v110 = v51;
    sub_4F21D0((float *)&v108, 0.0, v81, 0.0);
    result = 0.0;
    v54 = v109;
    v55 = *(_DWORD *)(*(_DWORD *)(this + 140) + 8) + 212;
    *(float *)v55 = *(float *)&v108;
    v56 = v110;
    *(_DWORD *)(v55 + 4) = v54;
    v57 = v111;
    *(float *)(v55 + 8) = v56;
    *(_DWORD *)(v55 + 12) = v57;
    *(_BYTE *)(this + 240) = 0;
  }
  else
  {
    v100 = 0.0;
    if ( v45 > 0 )
    {
      v58 = this + 300;
      do
      {
        v59 = (float *)(v58 + 16);
        v60 = (float *)(v58 - 8);
        *(_DWORD *)(v58 - 24) = 0;
        sub_5A988B((int)v122, v58 - 20, v58 - 8, v58 + 4, v58 + 16, 0.0);
        *(float *)&v95 = 0.0;
        do
        {
          v61 = (double)v95 * 0.1;
          v87 = v61;
          if ( v61 >= 0.0 )
          {
            if ( v87 > 1.0 )
              v87 = 1.0;
            sub_5A988B((int)&v119, v58 - 20, v58 - 8, v58 + 4, v58 + 16, v87);
          }
          else
          {
            sub_5A988B((int)&v119, v58 - 20, v58 - 8, v58 + 4, v58 + 16, 0.0);
          }
          v62 = *(float *)&v119 - *(float *)v122;
          v122[0] = v119;
          v26 = v95 + 1 < 10;
          v122[1] = v120;
          v63 = (v121 - v123) * (v121 - v123);
          v123 = v121;
          ++v95;
          *(float *)(v58 - 24) = sqrt(v62 * v62 + v63) + *(float *)(v58 - 24);
        }
        while ( v26 );
        v64 = *(float *)(v58 - 24);
        v66 = v64 * *v60;
        v58 += 60;
        v65 = ++LODWORD(v100);
        *v60 = v66;
        *(float *)(v58 - 64) = v64 * *(float *)(v58 - 64);
        *(float *)(v58 - 60) = v64 * *(float *)(v58 - 60);
        v67 = *(float *)(v58 - 84);
        *v59 = v67 * *v59;
        *(float *)(v58 - 40) = v67 * *(float *)(v58 - 40);
        *(float *)(v58 - 36) = v67 * *(float *)(v58 - 36);
      }
      while ( v65 < *(_DWORD *)(this + 268) );
    }
    v68 = *(_DWORD *)(this + 268);
    v69 = 0;
    v70 = this + 272;
    *(_DWORD *)(this + 244) = 0;
    if ( v68 > 0 )
    {
      do
      {
        v71 = *(float *)(v70 + 4);
        *(_DWORD *)v70 = *(_DWORD *)(this + 244);
        ++v69;
        v70 += 60;
        *(float *)(this + 244) = v71 + *(float *)(this + 244);
      }
      while ( v69 < *(_DWORD *)(this + 268) );
    }
    if ( *(_DWORD *)this == 1 )
      v72 = 5.0;
    else
      v72 = 6.0;
    v88 = *(float *)(this + 244) * 0.77419358 / v72;
    if ( v88 < 1.0 )
      v88 = 1.0;
    v73 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 140) + 8) + 228);
    *v73 = *(_DWORD *)(this + 280);
    v73[1] = *(_DWORD *)(this + 284);
    v73[2] = *(_DWORD *)(this + 288);
    if ( v125 < 10 )
    {
      v82 = v101 + 3.1415927;
      sub_4F21D0((float *)&v108, 0.0, v82, 0.0);
      v74 = v108;
      v75 = (int *)(*(_DWORD *)(*(_DWORD *)(this + 140) + 8) + 212);
      v75[1] = v109;
      v76 = v111;
      *v75 = v74;
      v77 = v110;
      v75[3] = v76;
      *((float *)v75 + 2) = v77;
    }
    result = v88;
    *(_DWORD *)(this + 252) = *(_DWORD *)(this + 280);
    *(_DWORD *)(this + 256) = *(_DWORD *)(this + 284);
    v78 = *(_DWORD *)(this + 288);
    *(_DWORD *)(this + 248) = 0;
    *(_DWORD *)(this + 264) = 0;
    *(_BYTE *)(this + 240) = 1;
    *(_DWORD *)(this + 260) = v78;
  }
  return result;
}
