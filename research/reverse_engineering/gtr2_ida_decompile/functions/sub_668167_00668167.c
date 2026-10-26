int __thiscall sub_668167(int this, unsigned int a2, unsigned int a3, int a4, int a5, int a6)
{
  int v7; // eax
  unsigned int v8; // ecx
  _DWORD *v9; // eax
  unsigned int v11; // edx
  size_t v12; // ecx
  size_t v13; // edi
  int v14; // esi
  int v15; // eax
  unsigned int v16; // eax
  int v17; // ecx
  int v18; // eax
  _DWORD *v19; // ecx
  int v20; // eax
  unsigned int v21; // eax
  int v22; // esi
  size_t v23; // edi
  size_t v24; // ecx
  _DWORD *v25; // esi
  int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // eax
  size_t v29; // edx
  double *v30; // edi
  _DWORD *v31; // esi
  int v32; // ecx
  double v33; // st7
  int *v34; // edi
  double *v35; // esi
  int v36; // eax
  double v37; // st7
  int v38; // eax
  unsigned int v39; // edi
  unsigned int v40; // esi
  int v41; // eax
  unsigned int v42; // esi
  bool v43; // zf
  _DWORD **v44; // ecx
  unsigned int v45; // eax
  bool v46; // zf
  size_t v47; // ecx
  int i; // edi
  int v49; // eax
  void *v50; // edx
  char *v51; // edx
  unsigned int v52; // eax
  int v53; // edi
  char *v54; // ecx
  _DWORD *v55; // edx
  unsigned int v56; // ecx
  _DWORD *v57; // eax
  _DWORD *v58; // ecx
  unsigned int v59; // eax
  int v60; // ecx
  bool v61; // sf
  double v62; // st7
  int v63; // eax
  _DWORD *v64; // esi
  int v65; // edx
  double *v66; // ecx
  double v67; // st7
  unsigned int v68; // eax
  double v69; // st7
  int v70; // eax
  int v71; // ecx
  int v72; // eax
  _DWORD *v73; // eax
  int v74; // ecx
  _DWORD *v75; // eax
  int v76; // edx
  int v77; // ecx
  _DWORD *v78; // eax
  int v79; // ecx
  unsigned int v80; // ecx
  int v81; // eax
  int v82; // edx
  bool v83; // cf
  unsigned int v84; // ecx
  int v85; // eax
  int v86; // edx
  unsigned int v87; // ecx
  int v88; // eax
  int v89; // edx
  unsigned int v90; // ecx
  int v91; // eax
  int v92; // edx
  unsigned int v93; // ecx
  int v94; // eax
  int v95; // edx
  _DWORD *v96; // esi
  int v97; // edx
  double *v98; // ecx
  double v99; // st7
  int v100; // eax
  double v101; // st7
  int v102; // eax
  int v103; // [esp-Ch] [ebp-E8h]
  int v104; // [esp-Ch] [ebp-E8h]
  int v105; // [esp-Ch] [ebp-E8h]
  char *v106; // [esp-8h] [ebp-E4h]
  int v107; // [esp-8h] [ebp-E4h]
  _DWORD *v108; // [esp-8h] [ebp-E4h]
  char *v109; // [esp-8h] [ebp-E4h]
  _DWORD *v110; // [esp-4h] [ebp-E0h]
  char *v111; // [esp-4h] [ebp-E0h]
  _DWORD *v112; // [esp-4h] [ebp-E0h]
  _DWORD *v113; // [esp-4h] [ebp-E0h]
  __int64 v114; // [esp+0h] [ebp-DCh]
  __int64 v115; // [esp+0h] [ebp-DCh]
  double v116; // [esp+14h] [ebp-C8h] BYREF
  double v117; // [esp+1Ch] [ebp-C0h]
  double v118; // [esp+24h] [ebp-B8h] BYREF
  double v119; // [esp+2Ch] [ebp-B0h]
  double v120; // [esp+34h] [ebp-A8h] BYREF
  double v121; // [esp+3Ch] [ebp-A0h]
  int v122; // [esp+44h] [ebp-98h]
  int v123; // [esp+48h] [ebp-94h]
  int v124; // [esp+4Ch] [ebp-90h]
  int v125; // [esp+50h] [ebp-8Ch] BYREF
  double v126; // [esp+54h] [ebp-88h] BYREF
  void *v127; // [esp+5Ch] [ebp-80h]
  int v128; // [esp+60h] [ebp-7Ch] BYREF
  unsigned int v129; // [esp+64h] [ebp-78h] BYREF
  int v130; // [esp+68h] [ebp-74h]
  int v131; // [esp+6Ch] [ebp-70h]
  unsigned int v132; // [esp+70h] [ebp-6Ch]
  unsigned int v133; // [esp+74h] [ebp-68h]
  void *Block; // [esp+78h] [ebp-64h]
  char *v135; // [esp+7Ch] [ebp-60h]
  _DWORD *v136; // [esp+80h] [ebp-5Ch]
  char *v137; // [esp+84h] [ebp-58h]
  _DWORD *v138; // [esp+88h] [ebp-54h]
  _DWORD *v139; // [esp+8Ch] [ebp-50h]
  int v140; // [esp+90h] [ebp-4Ch]
  _DWORD *v141; // [esp+94h] [ebp-48h]
  _DWORD *v142; // [esp+98h] [ebp-44h]
  int v143; // [esp+9Ch] [ebp-40h]
  int v144; // [esp+A0h] [ebp-3Ch] BYREF
  BOOL v145; // [esp+A4h] [ebp-38h]
  BOOL v146; // [esp+A8h] [ebp-34h]
  void *v147; // [esp+ACh] [ebp-30h]
  void *v148; // [esp+B0h] [ebp-2Ch]
  void *v149; // [esp+B4h] [ebp-28h]
  unsigned int v150; // [esp+B8h] [ebp-24h]
  int v151; // [esp+BCh] [ebp-20h] BYREF
  void *v152; // [esp+C0h] [ebp-1Ch]
  unsigned int v153; // [esp+C4h] [ebp-18h]
  unsigned int v154; // [esp+C8h] [ebp-14h]
  size_t Size; // [esp+CCh] [ebp-10h]
  int v156; // [esp+D0h] [ebp-Ch] BYREF
  unsigned int v157; // [esp+D4h] [ebp-8h]
  size_t v158; // [esp+D8h] [ebp-4h]
  char *v159; // [esp+E4h] [ebp+8h]

  v7 = *(_DWORD *)(this + 48);
  v8 = *(_DWORD *)(this + 68);
  v130 = v7;
  v131 = *(_DWORD *)(this + 52);
  v122 = *(_DWORD *)(this + 104);
  v123 = *(_DWORD *)(this + 108);
  v127 = 0;
  v149 = 0;
  v152 = 0;
  v148 = 0;
  v147 = 0;
  v145 = a3 != 0;
  v9 = *(_DWORD **)(this + 8);
  if ( v8 >= v9[23] )
    return -2147467259;
  *(_DWORD *)(this + 68) = v8 + 1;
  v11 = v9[2];
  v12 = *(_DWORD *)(*(_DWORD *)(this + 4) + 24);
  v153 = v9[3];
  v158 = v12;
  v133 = v11;
  Block = operator new(4 * v12);
  if ( !Block )
    goto LABEL_217;
  v149 = operator new(4 * v158);
  if ( !v149 )
    goto LABEL_217;
  v152 = operator new(4 * v158);
  if ( !v152 )
    goto LABEL_217;
  Size = 16 * v158;
  v148 = operator new(16 * v158);
  if ( !v148 )
    goto LABEL_217;
  v147 = operator new(Size);
  if ( !v147 )
    goto LABEL_217;
  v13 = 0;
  if ( v158 )
  {
    a3 = (unsigned int)v148;
    do
    {
      v14 = 4 * v13;
      v15 = *(_DWORD *)(4 * v13 + *(_DWORD *)(this + 24));
      if ( v15 == -1 || sub_662830(this, v15, (double *)a3) < 0 )
      {
        v16 = a3;
        *(double *)a3 = *(double *)(this + 160);
        *(double *)(v16 + 8) = *(double *)(this + 168);
      }
      v17 = *(_DWORD *)(v14 + *(_DWORD *)(this + 24));
      if ( v17 == -1
        || (v18 = *(_DWORD *)(this + 8),
            v19 = *(_DWORD **)(*(_DWORD *)(v18 + 20) + 4 * v17),
            *(_DWORD *)(v18 + 116) == v19[1]) )
      {
        *(_DWORD *)((char *)v149 + v14) = 31;
      }
      else
      {
        *(_DWORD *)((char *)v149 + v14) = *v19 & 0x1F;
      }
      a3 += 16;
      ++v13;
    }
    while ( v13 < v158 );
  }
  v126 = 1.0;
  qmemcpy(v152, v149, 4 * ((4 * v158) >> 2));
  qmemcpy(v147, v148, Size);
  v20 = *(_DWORD *)(this + 32);
  v128 = -1;
  v129 = -1;
  v151 = v20;
  v156 = 1;
  v146 = 1;
  v150 = *(_DWORD *)(*(_DWORD *)(this + 8) + 104);
  if ( !v150 )
    v150 = 255;
  v154 = 0;
  while ( 1 )
  {
    v21 = v154;
    *(_DWORD *)(this + 104) = v154;
    v43 = a5 == 0;
    v132 = v21 + 1;
    *(_DWORD *)(this + 108) = v21 + 1;
    if ( !v43 && v145 )
    {
      v22 = sub_67051D(a5, 0);
      if ( v22 < 0 )
        goto LABEL_218;
      if ( *(_DWORD *)(this + 92) )
        goto LABEL_91;
      if ( *(_DWORD *)(this + 80) || *(_DWORD *)(this + 84) )
        goto LABEL_215;
    }
    qmemcpy(Block, *(const void **)(this + 24), 4 * v158);
    a3 = -1;
    if ( a4 )
      break;
LABEL_33:
    if ( sub_6640D2((_DWORD *)this, v151, &v126) < 0 || 0.0 == v126 )
    {
      v28 = 0;
      v157 = 0;
      if ( !v158 )
        goto LABEL_57;
      v29 = a6 - (_DWORD)v152;
      v30 = (double *)v147;
      Size = a6 - (_DWORD)v152;
      while ( 1 )
      {
        v31 = (char *)v152 + 4 * v28;
        v32 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v28);
        if ( *(_DWORD *)((char *)v31 + v29) != v32 )
          break;
LABEL_56:
        ++v28;
        v30 += 2;
        v157 = v28;
        if ( v28 >= v158 )
          goto LABEL_57;
      }
      if ( *v30 > *(double *)(this + 168) || v30[1] < *(double *)(this + 160) )
      {
        if ( sub_662830(this, v32, &v118) < 0 )
        {
          *v30 = *(double *)(this + 160);
          v33 = *(double *)(this + 168);
        }
        else
        {
          if ( *v30 > v118 )
            *v30 = v118;
          if ( v30[1] >= v119 )
            goto LABEL_55;
          v33 = v119;
        }
        v30[1] = v33;
      }
LABEL_55:
      *v31 &= **(_DWORD **)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v157));
      v29 = Size;
      v28 = v157;
      goto LABEL_56;
    }
    v23 = 0;
    if ( v158 )
    {
      v24 = a6 - (_DWORD)v152;
      v157 = (unsigned int)v147;
      Size = a6 - (_DWORD)v152;
      do
      {
        v25 = (char *)v152 + 4 * v23;
        v26 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v23);
        if ( *(_DWORD *)((char *)v25 + v24) != v26 )
        {
          if ( sub_662830(this, v26, (double *)v157) < 0 )
          {
            v27 = v157;
            *(double *)v157 = *(double *)(this + 160);
            *(double *)(v27 + 8) = *(double *)(this + 168);
          }
          v24 = Size;
          *v25 = **(_DWORD **)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20)
                             + 4 * *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v23));
        }
        v157 += 16;
        ++v23;
      }
      while ( v23 < v158 );
    }
LABEL_57:
    if ( a3 != -1 )
    {
      if ( sub_662830(this, a3, &v116) >= 0 )
      {
        if ( 0.0 == v116 && 0.0 == v117 )
          goto LABEL_91;
        if ( v116 <= 0.0 && v117 >= 0.0 )
          v156 = 0;
      }
      *(double *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * a3) + 32) = 1.0;
      *(double *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * a3) + 40) = 1.0;
    }
    if ( v158 )
    {
      v34 = (int *)Block;
      v35 = (double *)v148;
      v36 = a6 - (_DWORD)Block;
      v157 = (_BYTE *)v149 - (_BYTE *)Block;
      v124 = a6 - (_DWORD)Block;
      Size = v158;
      while ( *(int *)((char *)v34 + v36) == *v34 )
      {
LABEL_78:
        v35 += 2;
        ++v34;
        if ( !--Size )
          goto LABEL_79;
      }
      if ( *v35 > *(double *)(this + 168) || v35[1] < *(double *)(this + 160) )
      {
        if ( sub_662830(this, *v34, &v120) < 0 )
        {
          *v35 = *(double *)(this + 160);
          v37 = *(double *)(this + 168);
LABEL_76:
          v35[1] = v37;
        }
        else
        {
          if ( *v35 > v120 )
            *v35 = v120;
          if ( v35[1] < v121 )
          {
            v37 = v121;
            goto LABEL_76;
          }
        }
      }
      *(int *)((char *)v34 + v157) &= **(_DWORD **)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * *v34);
      v36 = v124;
      goto LABEL_78;
    }
LABEL_79:
    if ( v146 )
      v146 = !v156 && sub_667073((_DWORD *)this, a3, v154, &v128, &v129);
    if ( a5 && !v145 )
    {
      v22 = sub_67051D(a5, 0);
      if ( v22 < 0 )
        goto LABEL_218;
      if ( *(_DWORD *)(this + 92) )
        goto LABEL_91;
      if ( *(_DWORD *)(this + 80) || *(_DWORD *)(this + 84) )
        goto LABEL_215;
    }
    v154 = v132;
    if ( v132 >= v150 )
      goto LABEL_91;
  }
  a3 = -1;
  v22 = sub_6714D6(a4, (int)&a3, 0);
  if ( v22 < 0 )
    goto LABEL_218;
  HIDWORD(v114) = 23;
  LODWORD(v114) = &a3;
  v22 = sub_6641F3((_DWORD *)this, a4, 542113793, (int)&v151, &v151, v114);
  if ( v22 < 0 )
    goto LABEL_218;
  if ( !*(_DWORD *)(this + 92) )
  {
    if ( *(_DWORD *)(this + 80) || *(_DWORD *)(this + 84) )
      goto LABEL_215;
    goto LABEL_33;
  }
LABEL_91:
  if ( v154 <= 1 )
    goto LABEL_215;
  if ( v154 < v150 )
  {
    if ( *(_DWORD *)(this + 96) || (*(_BYTE *)(this + 21) & 2) != 0 )
      goto LABEL_215;
    if ( !*(_DWORD *)(this + 92) )
      v146 = 0;
  }
  if ( v156 || v146 )
  {
    v39 = v153;
  }
  else
  {
    v38 = *(_DWORD *)(this + 8);
    if ( (*(_BYTE *)(v38 + 112) & 4) == 0 )
      goto LABEL_215;
    v39 = v153;
    v40 = v153;
    if ( v153 < *(_DWORD *)(v38 + 12) )
    {
      do
      {
        if ( sub_6810DD(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 24) + 4 * v40)) )
          goto LABEL_215;
        ++v40;
      }
      while ( v40 < *(_DWORD *)(*(_DWORD *)(this + 8) + 12) );
    }
  }
  if ( *(_DWORD *)(this + 92) )
  {
    v154 = v150;
    *(_DWORD *)(this + 92) = 0;
  }
  if ( v154 == v150 && sub_6640D2((_DWORD *)this, v151, &v126) >= 0 && 0.0 != v126 )
    goto LABEL_215;
  if ( v154 >= v150 || !v156 || (*(_BYTE *)(this + 21) & 4) != 0 )
    goto LABEL_131;
  v41 = *(_DWORD *)(this + 8);
  v42 = *(_DWORD *)(v41 + 12);
  v43 = v39 == v42;
  if ( v39 >= v42 )
    goto LABEL_130;
  v44 = (_DWORD **)(*(_DWORD *)(v41 + 24) + 4 * v39);
  while ( 2 )
  {
    v45 = **v44 & 0xFFF00000;
    if ( v45 > 0x20100000 )
    {
      if ( v45 != 538968064 && v45 != 540016640 && v45 != 541065216 && v45 != 542113792 )
      {
        v46 = v45 == 805306368;
        goto LABEL_127;
      }
    }
    else if ( v45 != 537919488 && v45 && v45 != 0x10000000 && v45 != 269484032 && v45 != 270532608 && v45 != 272629760 )
    {
      v46 = v45 == 0x20000000;
LABEL_127:
      if ( !v46 )
        break;
    }
    ++v39;
    ++v44;
    if ( v39 < *(_DWORD *)(*(_DWORD *)(this + 8) + 12) )
      continue;
    break;
  }
  v43 = v39 == v42;
LABEL_130:
  if ( v43 )
    goto LABEL_215;
LABEL_131:
  v47 = 0;
  for ( i = 0; v47 < v158; ++v47 )
  {
    v49 = *(_DWORD *)(a6 + 4 * v47);
    if ( v49 != -1 && *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v47) != v49 )
      ++i;
  }
  v50 = operator new(36 * i);
  v127 = v50;
  if ( !v50 )
  {
LABEL_217:
    v22 = -2147024882;
    goto LABEL_218;
  }
  v22 = sub_6624CC(v50, 9 * i);
  if ( v22 < 0 )
    goto LABEL_218;
  v52 = 0;
  v53 = 4 * i;
  v54 = v51;
  do
  {
    (&v135)[v52++] = v54;
    v54 += v53;
  }
  while ( v52 < 9 );
  v55 = v136;
  v56 = 0;
  a3 = 0;
  v157 = 0;
  if ( v158 )
  {
    Size = v137 - (char *)v136;
    v156 = v135 - v137;
    do
    {
      v57 = (_DWORD *)(4 * v56 + a6);
      if ( *v57 != -1 && *(_DWORD *)(4 * v56 + *(_DWORD *)(this + 24)) != *v57 )
      {
        v58 = (_DWORD *)((char *)v55 + Size);
        *(_DWORD *)((char *)v58 + v156) = v157;
        *v55 = *v57;
        *v58 = *v57;
        if ( *v57 == -1
          || *(_DWORD *)(*(_DWORD *)(this + 8) + 116) == *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20)
                                                                               + 4 * *v57)
                                                                   + 4) )
        {
          *v55 = *(_DWORD *)(this + 36);
        }
        ++a3;
        ++v55;
      }
      v56 = ++v157;
    }
    while ( v157 < v158 );
  }
  sub_664155(this, v133, v153, (const void *)a6);
  v59 = v154;
  v60 = *(_DWORD *)(this + 8);
  v61 = (v154 & 0x80000000) != 0;
  a6 = v154;
  v62 = (double)(int)v154;
  *(_DWORD *)(this + 104) = 0;
  *(_DWORD *)(this + 108) = v59;
  if ( v61 )
    v62 = v62 + 4294967296.0;
  v63 = sub_681AAA(*(_DWORD *)(v60 + 120), 0, 0, v62);
  v144 = -1;
  v125 = v63;
  v22 = sub_6641F3((_DWORD *)this, a2, 286261249, (int)&v144, &v125, 0);
  if ( v22 < 0 )
    goto LABEL_218;
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * v144) + 4) = *(_DWORD *)(*(_DWORD *)(this + 8)
                                                                                               + 164);
  v110 = v136;
  *(_DWORD *)(this + 48) = v144;
  v106 = v137;
  a6 = a3 & 0xFFFFF;
  v103 = a3 & 0xFFFFF | 0x11200000;
  *(_DWORD *)(this + 52) = 1;
  v22 = sub_6641F3((_DWORD *)this, a2, v103, (int)v106, v110, 0);
  if ( v22 < 0 )
    goto LABEL_218;
  v22 = sub_6641F3((_DWORD *)this, a2, a6 | 0x11300000, v143, v137, 0);
  if ( v22 < 0 )
    goto LABEL_218;
  if ( a3 )
  {
    v64 = v137;
    v156 = v135 - v137;
    v132 = v143 - (_DWORD)v137;
    v153 = a3;
    do
    {
      v65 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * *v64);
      v66 = (double *)((char *)v148 + 16 * *(_DWORD *)((char *)v64 + v156));
      if ( *v66 <= v66[1] )
      {
        *(double *)(v65 + 32) = *v66;
        v67 = v66[1];
        *(_BYTE *)(v65 + 1) |= 1u;
        v68 = *(_DWORD *)v65;
        *(double *)(v65 + 40) = v67;
        v69 = v66[1];
        v133 = v68;
        if ( *v66 == v69 )
          *(_DWORD *)v65 = v133 | 0x80;
      }
      *(_DWORD *)v65 |= *((_DWORD *)v149 + *(_DWORD *)((char *)v64 + v156));
      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * *v64) + 4) = *(_DWORD *)(*(_DWORD *)(this + 8) + 152);
      v70 = *(_DWORD *)(this + 8);
      v71 = *(_DWORD *)(*(_DWORD *)(v70 + 20) + 4 * *(_DWORD *)((char *)v64 + v132));
      v72 = *(_DWORD *)(v70 + 172);
      ++v64;
      v43 = v153-- == 1;
      *(_DWORD *)(v71 + 4) = v72;
    }
    while ( !v43 );
  }
  if ( a5 )
  {
    if ( v145 )
    {
      v22 = sub_67051D(a5, 0);
      if ( v22 < 0 )
        goto LABEL_218;
    }
  }
  v151 = -1;
  v22 = sub_6714D6(a4, (int)&v151, 0);
  if ( v22 < 0 )
    goto LABEL_218;
  if ( a3 )
  {
    v73 = v137;
    v74 = v135 - v137;
    v153 = a3;
    do
    {
      *v73 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)((char *)v73 + v74));
      ++v73;
      --v153;
    }
    while ( v153 );
  }
  if ( sub_662830(this, v151, &v120) >= 0 && (v120 > 0.0 || v121 < 0.0) )
  {
    if ( !a5 || v145 || (v22 = sub_67051D(a5, 0), v22 >= 0) )
    {
      if ( a3 )
      {
        v75 = v141;
        v76 = v135 - (char *)v141;
        a5 = a3;
        do
        {
          v77 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)((char *)v75 + v76));
          *v75 = v77;
          if ( v77 == -1 )
            *v75 = *(_DWORD *)(this + 36);
          ++v75;
          --a5;
        }
        while ( a5 );
      }
      goto LABEL_197;
    }
    goto LABEL_218;
  }
  if ( v154 < v150 && (*(_BYTE *)(*(_DWORD *)(this + 8) + 112) & 4) == 0 )
  {
LABEL_215:
    v22 = -2147467259;
    goto LABEL_218;
  }
  v156 = -1;
  v22 = sub_6641F3((_DWORD *)this, a2, 289406977, (int)&v156, &v151, 0);
  if ( v22 >= 0 )
  {
    v43 = a5 == 0;
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * v156) + 4) = *(_DWORD *)(*(_DWORD *)(this + 8)
                                                                                                 + 160);
    *(_DWORD *)(this + 48) = v156;
    *(_DWORD *)(this + 52) = 1;
    if ( v43 || v145 || (v22 = sub_67051D(a5, 0), v22 >= 0) )
    {
      v78 = v138;
      if ( a3 )
      {
        v79 = v135 - (char *)v138;
        a5 = a3;
        do
        {
          *v78 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)((char *)v78 + v79));
          ++v78;
          --a5;
        }
        while ( a5 );
      }
      a5 = a6 | 0x10000000;
      v22 = sub_6641F3((_DWORD *)this, a2, a6 | 0x10000000, (int)v139, v138, 0);
      if ( v22 >= 0 )
      {
        v80 = 0;
        if ( a3 )
        {
          do
          {
            v81 = *(_DWORD *)(this + 8);
            v82 = *(_DWORD *)(*(_DWORD *)(v81 + 20) + 4 * v139[v80++]);
            v83 = v80 < a3;
            *(_DWORD *)(v82 + 4) = *(_DWORD *)(v81 + 152);
          }
          while ( v83 );
        }
        v111 = v137;
        v107 = v140;
        *(_DWORD *)(this + 48) = v156;
        v104 = a5;
        *(_DWORD *)(this + 52) = 0;
        v22 = sub_6641F3((_DWORD *)this, a2, v104, v107, v111, 0);
        if ( v22 >= 0 )
        {
          v84 = 0;
          if ( a3 )
          {
            do
            {
              v85 = *(_DWORD *)(this + 8);
              v86 = *(_DWORD *)(*(_DWORD *)(v85 + 20) + 4 * *(_DWORD *)(v140 + 4 * v84++));
              v83 = v84 < a3;
              *(_DWORD *)(v86 + 4) = *(_DWORD *)(v85 + 152);
            }
            while ( v83 );
          }
          v115 = (unsigned int)v140;
          *(_DWORD *)(this + 48) = v144;
          v112 = v139;
          v108 = v141;
          v105 = a6 | 0x20800000;
          *(_DWORD *)(this + 52) = 1;
          v22 = sub_6641F3((_DWORD *)this, a2, v105, (int)v108, v112, v115);
          if ( v22 >= 0 )
          {
            v87 = 0;
            if ( a3 )
            {
              do
              {
                v88 = *(_DWORD *)(this + 8);
                v89 = *(_DWORD *)(*(_DWORD *)(v88 + 20) + 4 * v141[v87++]);
                v83 = v87 < a3;
                *(_DWORD *)(v89 + 4) = *(_DWORD *)(v88 + 152);
              }
              while ( v83 );
            }
LABEL_197:
            v22 = sub_6641F3((_DWORD *)this, a2, a6 | 0x10000000, (int)v141, v141, 0);
            if ( v22 >= 0 )
            {
              v90 = 0;
              if ( a3 )
              {
                do
                {
                  v91 = *(_DWORD *)(this + 8);
                  v92 = *(_DWORD *)(*(_DWORD *)(v91 + 20) + 4 * v141[v90++]);
                  v83 = v90 < a3;
                  *(_DWORD *)(v92 + 4) = *(_DWORD *)(v91 + 152);
                }
                while ( v83 );
              }
              v22 = sub_6641F3((_DWORD *)this, a2, a6 | 0x20900000, (int)v142, v141, (unsigned int)v143);
              if ( v22 >= 0 )
              {
                v93 = 0;
                if ( a3 )
                {
                  do
                  {
                    v94 = *(_DWORD *)(this + 8);
                    v95 = *(_DWORD *)(*(_DWORD *)(v94 + 20) + 4 * v142[v93++]);
                    v83 = v93 < a3;
                    *(_DWORD *)(v95 + 4) = *(_DWORD *)(v94 + 152);
                  }
                  while ( v83 );
                }
                v113 = v142;
                *(_DWORD *)(this + 48) = v130;
                v109 = v137;
                *(_DWORD *)(this + 52) = v131;
                v22 = sub_6641F3((_DWORD *)this, a2, a6 | 0x11500000, (int)v109, v113, 0);
                if ( v22 >= 0 )
                {
                  if ( a3 )
                  {
                    v96 = v135;
                    v159 = (char *)(v137 - v135);
                    a5 = a3;
                    do
                    {
                      v97 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20)
                                      + 4 * *(_DWORD *)((char *)v96 + (_DWORD)v159));
                      v98 = (double *)((char *)v147 + 16 * *v96);
                      if ( *v98 <= v98[1] )
                      {
                        *(double *)(v97 + 32) = *v98;
                        v99 = v98[1];
                        *(_BYTE *)(v97 + 1) |= 1u;
                        v100 = *(_DWORD *)v97;
                        *(double *)(v97 + 40) = v99;
                        v101 = v98[1];
                        a6 = v100;
                        if ( *v98 == v101 )
                          *(_DWORD *)v97 = a6 | 0x80;
                      }
                      *(_DWORD *)v97 |= *((_DWORD *)v152 + *v96++);
                      --a5;
                    }
                    while ( a5 );
                  }
                  if ( !v154
                    || !v146
                    || *(_DWORD *)(this + 80)
                    || *(_DWORD *)(this + 84)
                    || sub_6641F3((_DWORD *)this, a4, 268435457, *(_DWORD *)(this + 24) + 4 * v128, &v129, 0) >= 0 )
                  {
                    v22 = 0;
                    goto LABEL_218;
                  }
                  goto LABEL_215;
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_218:
  j__free(Block);
  j__free(v149);
  j__free(v152);
  j__free(v148);
  j__free(v147);
  j__free(v127);
  *(_DWORD *)(this + 48) = v130;
  *(_DWORD *)(this + 52) = v131;
  *(_DWORD *)(this + 104) = v122;
  v102 = v123;
  --*(_DWORD *)(this + 68);
  *(_DWORD *)(this + 108) = v102;
  return v22;
}
