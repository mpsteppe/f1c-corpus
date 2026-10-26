int __thiscall sub_6714D6(int this, __int64 a2, unsigned int ArgList)
{
  int v3; // esi
  _DWORD *v6; // eax
  unsigned int v7; // edi
  int v8; // ecx
  _DWORD *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  unsigned int i; // eax
  unsigned int v15; // eax
  unsigned int v16; // esi
  unsigned int v17; // eax
  unsigned int v18; // edx
  int v19; // ecx
  const void *v20; // esi
  void *v21; // edi
  int v22; // eax
  _DWORD *v23; // eax
  int v24; // ecx
  int v25; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // eax
  _DWORD *v29; // eax
  unsigned int j; // ecx
  unsigned int k; // ecx
  const void *v32; // esi
  char *v33; // eax
  unsigned int m; // ecx
  int v35; // eax
  int v36; // eax
  int v37; // eax
  void *v38; // eax
  int v39; // eax
  char *v40; // eax
  unsigned int v41; // ecx
  char *v42; // edx
  char *v43; // eax
  unsigned int v44; // ecx
  char *v45; // edx
  int v46; // eax
  int v47; // eax
  _DWORD *v48; // ecx
  int v49; // eax
  char *v50; // eax
  unsigned int jj; // ecx
  char *v52; // eax
  unsigned int kk; // ecx
  int v54; // eax
  void *v55; // eax
  _DWORD *v56; // eax
  unsigned int n; // ecx
  unsigned int ii; // edx
  int v59; // edx
  _DWORD *v60; // esi
  int v61; // eax
  unsigned int v62; // ecx
  _DWORD *mm; // eax
  char *v64; // eax
  unsigned int v65; // edx
  int v66; // ecx
  int v67; // esi
  int *v68; // eax
  int v69; // eax
  _DWORD *v70; // eax
  int v71; // eax
  _BYTE *v72; // edx
  unsigned int v73; // ecx
  _DWORD *v74; // eax
  int v75; // ecx
  int v76; // eax
  int v77; // esi
  int v78; // esi
  char *v79; // eax
  unsigned int i1; // ecx
  int *v81; // eax
  int *v82; // edx
  int v83; // ecx
  int v84; // ecx
  _DWORD *v85; // eax
  _DWORD *v86; // ecx
  unsigned int v87; // edx
  int v88; // esi
  _DWORD *v89; // eax
  unsigned int i2; // ecx
  int *v91; // eax
  int *v92; // edx
  int v93; // ecx
  int v94; // ecx
  unsigned int i3; // edx
  int v96; // edx
  _DWORD *v97; // ecx
  int v98; // eax
  double *v99; // esi
  int v100; // eax
  int v101; // eax
  double v102; // st7
  double v104; // st7
  char v105; // c0
  double v107; // st7
  char v108; // c0
  double v109; // st7
  double *v110; // edx
  double v111; // st7
  int v112; // ecx
  unsigned int v113; // ecx
  int v114; // eax
  _DWORD *v115; // esi
  unsigned int *v116; // ecx
  unsigned int v117; // eax
  unsigned int v118; // edi
  unsigned int v119; // edx
  bool v120; // zf
  _DWORD *v121; // [esp-4h] [ebp-7Ch]
  __int64 X; // [esp+0h] [ebp-78h]
  __int64 Xa; // [esp+0h] [ebp-78h]
  __int64 Xb; // [esp+0h] [ebp-78h]
  _DWORD *v125; // [esp+14h] [ebp-64h]
  int v126; // [esp+18h] [ebp-60h]
  int v127; // [esp+1Ch] [ebp-5Ch]
  _DWORD *v128; // [esp+20h] [ebp-58h]
  int v129; // [esp+24h] [ebp-54h]
  int v130; // [esp+28h] [ebp-50h]
  char *v131; // [esp+2Ch] [ebp-4Ch]
  double v132; // [esp+30h] [ebp-48h] BYREF
  double v133; // [esp+38h] [ebp-40h]
  _DWORD *v134; // [esp+40h] [ebp-38h]
  int v135; // [esp+44h] [ebp-34h]
  int v136; // [esp+48h] [ebp-30h]
  _DWORD *v137; // [esp+4Ch] [ebp-2Ch]
  unsigned int v138; // [esp+50h] [ebp-28h]
  char *v139; // [esp+54h] [ebp-24h]
  int nn; // [esp+58h] [ebp-20h]
  char v141[4]; // [esp+5Ch] [ebp-1Ch]
  int v142; // [esp+60h] [ebp-18h]
  int v143; // [esp+64h] [ebp-14h]
  int v144; // [esp+68h] [ebp-10h]
  int v145; // [esp+6Ch] [ebp-Ch]
  int v146; // [esp+70h] [ebp-8h]
  int v147; // [esp+74h] [ebp-4h]
  double *v148; // [esp+80h] [ebp+8h]
  unsigned int v149; // [esp+84h] [ebp+Ch]

  v3 = a2;
  if ( !(_DWORD)a2 )
  {
    if ( !HIDWORD(a2) )
      return 0;
    return -2147467259;
  }
  if ( *(_DWORD *)(a2 + 4) != 13 )
    return -2147467259;
  v6 = *(_DWORD **)(a2 + 32);
  v7 = *(_DWORD *)(a2 + 24) * *(_DWORD *)(a2 + 20);
  v8 = 0;
  v145 = v7;
  v142 = 0;
  nn = 0;
  v147 = 0;
  v146 = 0;
  v144 = 0;
  v143 = 0;
  if ( v6 && v6[1] == 13 )
  {
    v8 = v6[5] * v6[6];
    v144 = (int)v6;
    v142 = v8;
  }
  v9 = *(_DWORD **)(a2 + 36);
  if ( v9 && v9[1] == 13 )
  {
    v10 = v9[5] * v9[6];
    v143 = *(_DWORD *)(a2 + 36);
    nn = v10;
  }
  if ( v144 )
  {
    v147 = (int)sub_662412((_DWORD *)this, v8);
    if ( !v147 )
      goto LABEL_328;
  }
  if ( v143 )
  {
    v146 = (int)sub_662412((_DWORD *)this, nn);
    if ( !v146 )
      goto LABEL_328;
  }
  v11 = *(_DWORD *)(a2 + 28);
  *(_DWORD *)v141 = 0;
  if ( v11 >= 0 )
  {
    if ( v11 <= 3 )
    {
LABEL_20:
      *(_DWORD *)v141 = ArgList;
      goto LABEL_21;
    }
    if ( v11 <= 19 )
      goto LABEL_21;
    if ( v11 > 21 )
    {
      if ( v11 > 23 )
        goto LABEL_21;
      goto LABEL_20;
    }
    *(_DWORD *)v141 = 1;
  }
LABEL_21:
  if ( *(_DWORD *)(a2 + 40) )
  {
    if ( v144 )
    {
      v12 = sub_6714D6(v144, v147, v141[0]);
      if ( v12 < 0 )
        goto LABEL_385;
      v3 = a2;
    }
    if ( !v143 )
      goto LABEL_35;
    v13 = sub_6714D6(v143, v146, 0);
  }
  else
  {
    if ( v143 )
    {
      v12 = sub_6714D6(v143, v146, 0);
      if ( v12 < 0 )
        goto LABEL_385;
      v3 = a2;
    }
    if ( !v144 )
      goto LABEL_35;
    v13 = sub_6714D6(v144, v147, v141[0]);
  }
  v12 = v13;
  if ( v13 < 0 )
    goto LABEL_385;
  v3 = a2;
LABEL_35:
  switch ( *(_DWORD *)(v3 + 28) )
  {
    case 0:
    case 1:
      if ( !v144 )
      {
        v22 = sub_672B87(*(_DWORD *)(a2 + 32), HIDWORD(a2), v7);
        goto LABEL_100;
      }
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      if ( v142 == 1 )
      {
        for ( i = 0; i < v7; ++i )
          *(_DWORD *)(HIDWORD(a2) + 4 * i) = *(_DWORD *)v147;
        goto LABEL_41;
      }
      if ( v7 == v142 )
        goto LABEL_86;
      v17 = *(_DWORD *)(a2 + 20);
      if ( v17 == 1 && v7 < v142 )
        goto LABEL_86;
      if ( v17 > *(_DWORD *)(v144 + 20) || *(_DWORD *)(a2 + 24) > *(_DWORD *)(v144 + 24) )
        goto LABEL_384;
      v18 = 0;
      if ( !v17 )
        goto LABEL_41;
      do
      {
        v19 = *(_DWORD *)(a2 + 24);
        v20 = (const void *)(v147 + 4 * v18 * *(_DWORD *)(v144 + 24));
        v21 = (void *)(HIDWORD(a2) + 4 * v18 * v19);
        ++v18;
        qmemcpy(v21, v20, 4 * v19);
      }
      while ( v18 < *(_DWORD *)(a2 + 20) );
      goto LABEL_248;
    case 2:
      if ( !v144 )
        goto LABEL_384;
      v29 = sub_6623AF(this, v7);
      if ( !v29 )
        goto LABEL_328;
      for ( j = 0; j < v7; ++j )
        v29[j] = *(_DWORD *)(this + 32);
      goto LABEL_83;
    case 3:
      if ( !v144 )
        goto LABEL_384;
      v29 = sub_6623AF(this, v7);
      if ( !v29 )
        goto LABEL_328;
      for ( k = 0; k < v7; ++k )
        v29[k] = *(_DWORD *)(this + 40);
LABEL_83:
      v27 = sub_6641F3((_DWORD *)this, a2, v7 & 0xFFFFF | 0x20400000, v147, (_DWORD *)v147, (unsigned int)v29);
      goto LABEL_84;
    case 4:
      if ( !v144 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v33 = (char *)sub_6623AF(this, 2 * v7);
      if ( !v33 )
        goto LABEL_328;
      for ( m = 0; m < 2; ++m )
      {
        *(&v138 + m) = (unsigned int)v33;
        v33 += 4 * v7;
      }
      v12 = sub_6624CC((void *)v138, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6624CC(v139, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_666C0F((_DWORD *)this, a2, (void *)v138, v139, v147, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      X = v138 | 0x1700000000LL;
      v121 = v139;
      goto LABEL_97;
    case 5:
      if ( !v144 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v22 = sub_6641F3((_DWORD *)this, a2, v7 & 0xFFFFF | 0x10100000, SHIDWORD(a2), (_DWORD *)v147, 0);
      goto LABEL_100;
    case 6:
      if ( !v144 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      X = 0;
      v121 = (_DWORD *)v147;
      goto LABEL_273;
    case 7:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      HIDWORD(Xb) = 0;
      goto LABEL_210;
    case 8:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v55 = sub_6623AF(this, v7);
      v143 = (int)v55;
      if ( !v55 )
        goto LABEL_328;
      v12 = sub_6624CC(v55, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      ArgList = v7 & 0xFFFFF;
      v12 = sub_6641F3((_DWORD *)this, a2, v7 & 0xFFFFF | 0x10300000, v143, (_DWORD *)v146, 0);
      if ( v12 < 0 )
        goto LABEL_385;
      v54 = ArgList;
      Xb = (unsigned int)v143;
      goto LABEL_211;
    case 9:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v56 = sub_6623AF(this, 8 * v7);
      if ( !v56 )
        goto LABEL_328;
      for ( n = 0; n < 8; ++n )
      {
        (&v128)[n] = v56;
        v56 += v7;
      }
      for ( ii = 0; ii < 8; ii = v59 + 1 )
      {
        v12 = sub_6624CC((&v128)[ii], v7);
        if ( v12 < 0 )
          goto LABEL_385;
      }
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v143 = v7 & 0xFFFFF | 0x20500000;
      ArgList = v7 & 0xFFFFF;
      v12 = sub_6641F3((_DWORD *)this, a2, v143, (int)v128, (_DWORD *)v147, (unsigned int)v146);
      if ( v12 < 0 )
        goto LABEL_385;
      v139 = (char *)(ArgList | 0x10100000);
      v12 = sub_6641F3((_DWORD *)this, a2, ArgList | 0x10100000, v129, v128, 0);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6641F3((_DWORD *)this, a2, ArgList | 0x20300000, v130, v128, (unsigned int)v129 | 0x1700000000LL);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6641F3((_DWORD *)this, a2, (int)v139, (int)v131, (_DWORD *)v146, 0);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_666305((_DWORD *)this, a2, (void *)LODWORD(v132), v131, (char *)v146, (_DWORD *)v130, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6641F3(
              (_DWORD *)this,
              a2,
              ArgList | 0x10300000,
              SHIDWORD(v132),
              (_DWORD *)LODWORD(v132),
              0x4000000000LL);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6641F3((_DWORD *)this, a2, v143, SLODWORD(v133), (_DWORD *)v147, HIDWORD(v132));
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6641F3((_DWORD *)this, a2, ArgList | 0x10400000, SHIDWORD(v133), (_DWORD *)LODWORD(v133), 0x400000000LL);
      if ( v12 < 0 )
        goto LABEL_385;
      v22 = sub_6641F3((_DWORD *)this, a2, v143, SHIDWORD(a2), (_DWORD *)LODWORD(v132), HIDWORD(v133));
      goto LABEL_100;
    case 0xA:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      Xa = (unsigned int)v146;
      v37 = v7 & 0xFFFFF;
      goto LABEL_115;
    case 0xB:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v38 = sub_6623AF(this, v7);
      v143 = (int)v38;
      if ( !v38 )
        goto LABEL_328;
      v12 = sub_6624CC(v38, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      ArgList = v7 & 0xFFFFF;
      v12 = sub_6641F3((_DWORD *)this, a2, v7 & 0xFFFFF | 0x10100000, v143, (_DWORD *)v146, 0);
      if ( v12 < 0 )
        goto LABEL_385;
      v37 = ArgList;
      Xa = (unsigned int)v143;
LABEL_115:
      v22 = sub_6641F3((_DWORD *)this, a2, v37 | 0x20400000, SHIDWORD(a2), (_DWORD *)v147, Xa);
      goto LABEL_100;
    case 0xC:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      X = (unsigned int)v146 | 0x1700000000LL;
      v121 = (_DWORD *)v147;
      goto LABEL_134;
    case 0xD:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      X = (unsigned int)v147 | 0x1700000000LL;
      v121 = (_DWORD *)v146;
LABEL_134:
      v39 = v7 & 0xFFFFF;
      goto LABEL_135;
    case 0xE:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      X = (unsigned int)v147 | 0x1700000000LL;
      v121 = (_DWORD *)v146;
      goto LABEL_97;
    case 0xF:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      X = (unsigned int)v146 | 0x1700000000LL;
      v121 = (_DWORD *)v147;
LABEL_97:
      v35 = v7 & 0xFFFFF;
      goto LABEL_98;
    case 0x10:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v40 = (char *)sub_6623AF(this, 4 * v7);
      if ( !v40 )
        goto LABEL_328;
      v41 = 0;
      v42 = v40;
      do
      {
        (&v134)[v41++] = v42;
        v42 += 4 * v7;
      }
      while ( v41 < 4 );
      v12 = sub_6624CC(v40, 4 * v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      ArgList = v7 & 0xFFFFF;
      v12 = sub_6641F3((_DWORD *)this, a2, v7 & 0xFFFFF | 0x10100000, (int)v134, (_DWORD *)v146, 0);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6641F3((_DWORD *)this, a2, ArgList | 0x20400000, v135, (_DWORD *)v147, (unsigned int)v134);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_666C0F((_DWORD *)this, a2, (void *)v136, v137, v135, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v35 = ArgList;
      X = (unsigned int)v136 | 0x1700000000LL;
      v121 = v137;
LABEL_98:
      v36 = v35 | 0x20300000;
      goto LABEL_99;
    case 0x11:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v43 = (char *)sub_6623AF(this, 4 * v7);
      if ( !v43 )
        goto LABEL_328;
      v44 = 0;
      v45 = v43;
      do
      {
        (&v134)[v44++] = v45;
        v45 += 4 * v7;
      }
      while ( v44 < 4 );
      v12 = sub_6624CC(v43, 4 * v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      ArgList = v7 & 0xFFFFF;
      v12 = sub_6641F3((_DWORD *)this, a2, v7 & 0xFFFFF | 0x10100000, (int)v134, (_DWORD *)v146, 0);
      if ( v12 < 0 )
        goto LABEL_385;
      v46 = sub_6641F3((_DWORD *)this, a2, ArgList | 0x20400000, v135, (_DWORD *)v147, (unsigned int)v134);
      goto LABEL_168;
    case 0x12:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      ArgList = 0;
      if ( !v7 )
        goto LABEL_178;
      v48 = (_DWORD *)v146;
      v49 = *(_DWORD *)(*(_DWORD *)(this + 8) + 20);
      while ( (**(_BYTE **)(v49 + 4 * *(_DWORD *)((char *)v48 + v147 - v146)) & 1) != 0
           && (**(_BYTE **)(v49 + 4 * *v48) & 1) != 0 )
      {
        ++ArgList;
        ++v48;
        if ( ArgList >= v7 )
        {
LABEL_178:
          v12 = sub_6624CC((void *)HIDWORD(a2), v7);
          if ( v12 < 0 )
            goto LABEL_385;
          HIDWORD(Xb) = 23;
LABEL_210:
          LODWORD(Xb) = v146;
          v54 = v7 & 0xFFFFF;
LABEL_211:
          v22 = sub_6641F3((_DWORD *)this, a2, v54 | 0x20500000, SHIDWORD(a2), (_DWORD *)v147, Xb);
          goto LABEL_100;
        }
      }
      v50 = (char *)sub_6623AF(this, 3 * v7);
      if ( !v50 )
        goto LABEL_328;
      for ( jj = 0; jj < 3; ++jj )
      {
        *(&v135 + jj) = (int)v50;
        v50 += 4 * v7;
      }
      v12 = sub_6624CC((void *)v135, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6624CC((void *)v136, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6624CC(v137, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      ArgList = v7 & 0xFFFFF;
      v46 = sub_6641F3((_DWORD *)this, a2, v7 & 0xFFFFF | 0x20500000, v135, (_DWORD *)v147, (unsigned int)v146);
LABEL_168:
      v12 = v46;
      if ( v46 < 0 )
        goto LABEL_385;
      v47 = sub_666C0F((_DWORD *)this, a2, (void *)v136, v137, v135, v7);
LABEL_203:
      v12 = v47;
      if ( v47 < 0 )
        goto LABEL_385;
      v39 = ArgList;
      X = (unsigned int)v136 | 0x1700000000LL;
      v121 = v137;
LABEL_135:
      v36 = v39 | 0x20200000;
      goto LABEL_99;
    case 0x13:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v52 = (char *)sub_6623AF(this, 4 * v7);
      if ( !v52 )
        goto LABEL_328;
      for ( kk = 0; kk < 4; ++kk )
      {
        (&v134)[kk] = v52;
        v52 += 4 * v7;
      }
      v12 = sub_6624CC(v134, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6624CC((void *)v135, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6624CC((void *)v136, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6624CC(v137, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_6624CC((void *)HIDWORD(a2), v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_666C0F((_DWORD *)this, a2, v134, 0, v147, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      v12 = sub_666C0F((_DWORD *)this, a2, (void *)v135, 0, v146, v7);
      if ( v12 < 0 )
        goto LABEL_385;
      ArgList = v7 & 0xFFFFF;
      v12 = sub_6641F3((_DWORD *)this, a2, v7 & 0xFFFFF | 0x20400000, v136, v134, (unsigned int)v135 | 0x400000000LL);
      if ( v12 < 0 )
        goto LABEL_385;
      v47 = sub_6641F3((_DWORD *)this, a2, ArgList | 0x10100000, (int)v137, (_DWORD *)v136, 0x800000000LL);
      goto LABEL_203;
    case 0x14:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !v7 )
        goto LABEL_41;
      v23 = *(_DWORD **)(this + 8);
      if ( *(_DWORD *)v147 >= v23[2] )
        v24 = 0;
      else
        v24 = *(_DWORD *)(v23[5] + 4 * *(_DWORD *)v147);
      if ( !v24 || v23[29] != *(_DWORD *)(v24 + 4) )
        goto LABEL_85;
      v25 = 0;
      v26 = v23[5];
      while ( *(_DWORD *)(*(_DWORD *)(v26 + 4 * *(_DWORD *)(v147 + 4 * v25)) + 48) != -1 )
      {
        if ( ++v25 >= v7 )
          goto LABEL_65;
      }
      goto LABEL_73;
    case 0x15:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !v7 )
        goto LABEL_41;
      v28 = 0;
      while ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * *(_DWORD *)(v147 + 4 * v28)) + 48) != -1 )
      {
        if ( ++v28 >= v7 )
        {
LABEL_65:
          v27 = sub_6641F3((_DWORD *)this, a2, v7 & 0xFFFFF | 0x10000000, v147, (_DWORD *)v146, 0);
LABEL_84:
          v12 = v27;
          if ( v27 < 0 )
            goto LABEL_385;
LABEL_85:
          if ( HIDWORD(a2) )
          {
LABEL_86:
            v32 = (const void *)v147;
LABEL_247:
            qmemcpy((void *)HIDWORD(a2), v32, 4 * v145);
LABEL_248:
            v7 = v145;
            goto LABEL_41;
          }
          goto LABEL_382;
        }
      }
LABEL_73:
      sub_663C07((_DWORD *)this, (_DWORD *)a2, 0, "internal error: l-value expected");
      goto LABEL_384;
    case 0x16:
      if ( !v143 )
        goto LABEL_384;
      v22 = sub_66F3C1(
              this,
              (_DWORD *)a2,
              __SPAIR64__(v7, HIDWORD(a2)),
              (unsigned int *)v147,
              v142,
              *(_DWORD **)(v144 + 16),
              v146,
              ArgList);
      goto LABEL_100;
    case 0x17:
      if ( !v144 )
        goto LABEL_384;
      v60 = *(_DWORD **)(v3 + 36);
      if ( !v60 )
        goto LABEL_384;
      v61 = v60[1];
      if ( v61 == 14 )
      {
        if ( v60[4] != 2 )
          goto LABEL_384;
        if ( HIDWORD(a2) )
        {
          v32 = (const void *)(v147 + 4 * v60[6]);
          goto LABEL_247;
        }
      }
      else
      {
        if ( v61 != 1 )
          goto LABEL_384;
        if ( HIDWORD(a2) )
        {
          v62 = 0;
          for ( mm = v60; v62 < v7; ++v62 )
          {
            *(_DWORD *)(HIDWORD(a2) + 4 * v62) = *(_DWORD *)(v147 + 4 * *(_DWORD *)(mm[2] + 24));
            mm = (_DWORD *)mm[3];
          }
          goto LABEL_41;
        }
      }
      goto LABEL_382;
    case 0x18:
      if ( !v144 || !v143 )
        goto LABEL_384;
      if ( !HIDWORD(a2) )
        goto LABEL_382;
      v64 = (char *)sub_6623AF(this, 3 * v7);
      if ( !v64 )
        goto LABEL_328;
      v65 = 0;
      v66 = 4 * v7;
      do
      {
        *(&v135 + v65++) = (int)v64;
        v64 += v66;
      }
      while ( v65 < 3 );
      *(_DWORD *)v141 = 0;
      v67 = v135;
      if ( !v7 )
        goto LABEL_270;
      v142 = v146 + v66;
      ArgList = v146 - v135;
      v139 = (char *)(v147 - v146);
      break;
    case 0x19:
      v70 = (_DWORD *)sub_66397F((_DWORD *)this, *(_DWORD *)(v3 + 32), &ArgList);
      if ( !v70 )
      {
        sub_663C07(
          (_DWORD *)this,
          (_DWORD *)v3,
          3510,
          "function '%s' missing implementation",
          *(const char **)(v3 + 56));
        goto LABEL_384;
      }
      ++*(_DWORD *)(this + 56);
      v22 = sub_67091B(this, (const char *)ArgList, v70, *(_DWORD *)(a2 + 36), (_DWORD *)HIDWORD(a2), 0, 0);
      --*(_DWORD *)(this + 56);
      goto LABEL_100;
    case 0x1A:
      v22 = sub_66963D(this, a2, HIDWORD(a2));
      goto LABEL_100;
    default:
      sub_663C07((_DWORD *)this, 0, 0, "internal error: unrecognized expression");
      goto LABEL_384;
  }
  while ( sub_662830(this, *(_DWORD *)&v139[v67 + ArgList], &v132) >= 0 )
  {
    if ( v132 > 0.0 || v133 < 0.0 )
    {
      v68 = (int *)(v67 + ArgList);
    }
    else
    {
      if ( v132 != 0.0 || v133 != 0.0 )
        break;
      v68 = (int *)v142;
    }
    v69 = *v68;
    ++*(_DWORD *)v141;
    v142 += 4;
    *(_DWORD *)v67 = v69;
    v67 += 4;
    if ( *(_DWORD *)v141 >= v7 )
      break;
  }
LABEL_270:
  if ( *(_DWORD *)v141 == v7 )
  {
    v12 = sub_6624CC((void *)HIDWORD(a2), v7);
    if ( v12 < 0 )
      goto LABEL_385;
    X = 0;
    v121 = (_DWORD *)v135;
LABEL_273:
    v36 = v7 & 0xFFFFF | 0x10000000;
LABEL_99:
    v22 = sub_6641F3((_DWORD *)this, a2, v36, SHIDWORD(a2), v121, X);
  }
  else
  {
    v12 = sub_6624CC((void *)v135, v7);
    if ( v12 < 0 )
      goto LABEL_385;
    v12 = sub_6624CC((void *)v136, v7);
    if ( v12 < 0 )
      goto LABEL_385;
    v12 = sub_6624CC(v137, v7);
    if ( v12 < 0 )
      goto LABEL_385;
    v12 = sub_666C0F((_DWORD *)this, a2, (void *)v135, (void *)v136, v147, v7);
    if ( v12 < 0 )
      goto LABEL_385;
    v12 = sub_6641F3(
            (_DWORD *)this,
            a2,
            v7 & 0xFFFFF | 0x20200000,
            (int)v137,
            (_DWORD *)v136,
            (unsigned int)v135 | 0x1700000000LL);
    if ( v12 < 0 )
      goto LABEL_385;
    v22 = sub_666305((_DWORD *)this, a2, (void *)HIDWORD(a2), (char *)(v146 + 4 * v7), (char *)v146, v137, v7);
  }
LABEL_100:
  v12 = v22;
  if ( v22 < 0 )
    goto LABEL_385;
LABEL_41:
  if ( !HIDWORD(a2) )
  {
LABEL_382:
    v12 = 0;
    goto LABEL_385;
  }
  v15 = *(_DWORD *)(this + 156);
  if ( v7 <= v15 )
    goto LABEL_289;
  if ( v15 )
    v16 = 2 * v15;
  else
    v16 = 16;
  while ( v16 < v7 )
    v16 *= 2;
  ArgList = (unsigned int)operator new(8 * v16);
  if ( !ArgList )
  {
LABEL_328:
    sub_663C07((_DWORD *)this, (_DWORD *)a2, 0, "internal error: out of memory");
    v12 = -2147024882;
    goto LABEL_385;
  }
  j__free(*(void **)(this + 152));
  *(_DWORD *)(this + 152) = ArgList;
  *(_DWORD *)(this + 156) = v16;
LABEL_289:
  v145 = *(_DWORD *)(this + 152);
  v139 = (char *)(v145 + 4 * v7);
  sub_663D59(this, *(_DWORD **)(a2 + 16), v139);
  ArgList = 0;
  v144 = 0;
  v142 = 0;
  if ( !v7 )
    goto LABEL_372;
  v71 = HIDWORD(a2) - (_DWORD)v139;
  *(_DWORD *)v141 = &v139[-v145];
  v143 = v145;
  for ( nn = HIDWORD(a2) - (_DWORD)v139; ; v71 = nn )
  {
    v72 = (_BYTE *)(*(_DWORD *)v141 + v143);
    v73 = *(_DWORD *)(*(_DWORD *)v141 + v143 + v71);
    v74 = *(_DWORD **)(this + 8);
    if ( v73 >= v74[2] )
      v75 = 0;
    else
      v75 = *(_DWORD *)(v74[5] + 4 * v73);
    if ( !v75 )
    {
      sub_663C07((_DWORD *)this, 0, 0, "internal error: result register invalid");
LABEL_384:
      v12 = -2147467259;
      goto LABEL_385;
    }
    v76 = v74[29];
    v77 = *(_DWORD *)(v75 + 4);
    if ( v76 == v77 )
      goto LABEL_304;
    if ( (*v72 & 1) != 0 && (*(_BYTE *)v75 & 1) == 0 )
    {
      ++ArgList;
      *(_DWORD *)v143 = 1;
      goto LABEL_305;
    }
    if ( v76 == v77 || (*v72 & 2) == 0 || (*(_BYTE *)v75 & 2) != 0 )
    {
LABEL_304:
      *(_DWORD *)v143 = 0;
    }
    else
    {
      ++v144;
      *(_DWORD *)v143 = 2;
    }
LABEL_305:
    ++v142;
    v143 += 4;
    if ( v142 >= v7 )
      break;
  }
  if ( !ArgList )
    goto LABEL_326;
  v78 = 4 * ArgList;
  v79 = (char *)sub_6623AF(this, 4 * ArgList);
  if ( !v79 )
    goto LABEL_328;
  for ( i1 = 0; i1 < 4; ++i1 )
  {
    (&v134)[i1] = v79;
    v79 += v78;
  }
  v12 = sub_6624CC((void *)v135, ArgList);
  if ( v12 < 0 )
    goto LABEL_385;
  v12 = sub_6624CC((void *)v136, ArgList);
  if ( v12 < 0 )
    goto LABEL_385;
  v81 = (int *)HIDWORD(a2);
  v82 = v137;
  v83 = v145 - HIDWORD(a2);
  v142 = v145 - HIDWORD(a2);
  *(_DWORD *)v141 = (char *)v134 - (char *)v137;
  nn = v7;
  do
  {
    if ( *(int *)((char *)v81 + v83) == 1 )
    {
      *(int *)((char *)v82 + *(_DWORD *)v141) = *v81;
      if ( *(_DWORD *)(a2 + 28) )
        v84 = *v81;
      else
        v84 = -1;
      *v82 = v84;
      v83 = v142;
      ++v82;
    }
    ++v81;
    --nn;
  }
  while ( nn );
  v12 = sub_666C0F((_DWORD *)this, a2, (void *)v135, (void *)v136, (unsigned int)v134, ArgList);
  if ( v12 < 0 )
    goto LABEL_385;
  v12 = sub_6641F3(
          (_DWORD *)this,
          a2,
          ArgList & 0xFFFFF | 0x20200000,
          (int)v137,
          (_DWORD *)v136,
          (unsigned int)v135 | 0x1700000000LL);
  if ( v12 < 0 )
    goto LABEL_385;
  v85 = (_DWORD *)HIDWORD(a2);
  v86 = v137;
  v87 = v7;
  do
  {
    if ( *(_DWORD *)((char *)v85 + v142) == 1 )
      *v85 = *v86++;
    ++v85;
    --v87;
  }
  while ( v87 );
LABEL_326:
  if ( !v144 )
  {
LABEL_372:
    if ( !v7 )
      goto LABEL_382;
    v115 = v139;
    nn = HIDWORD(a2) - (_DWORD)v139;
    v149 = v7;
    while ( 1 )
    {
      v116 = *(unsigned int **)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * *(_DWORD *)((char *)v115 + nn));
      v117 = *v116 | *v115 & 0xF1FFFFFF;
      *v116 = v117;
      v118 = v117 & 0xE000000;
      v119 = *v115 & 0xE000000;
      if ( (v117 & 0xE000000) == 0 )
        v118 = *v115 & 0xE000000;
      if ( v116[23] )
      {
        if ( v118 > v119 )
LABEL_380:
          v119 = v118;
      }
      else if ( v118 < v119 )
      {
        goto LABEL_380;
      }
      ++v115;
      v120 = v149-- == 1;
      *v116 = v119 | v117 & 0xF1FFFFFF;
      if ( v120 )
        goto LABEL_382;
    }
  }
  v88 = v144;
  v89 = sub_6623AF(this, 11 * v144);
  if ( !v89 )
    goto LABEL_328;
  for ( i2 = 0; i2 < 0xB; ++i2 )
  {
    (&v125)[i2] = v89;
    v89 += v88;
  }
  v91 = (int *)HIDWORD(a2);
  v92 = (int *)HIDWORD(v133);
  v93 = v145 - HIDWORD(a2);
  v142 = v145 - HIDWORD(a2);
  v143 = (int)v125 - HIDWORD(v133);
  ArgList = v7;
  do
  {
    if ( *(int *)((char *)v91 + v93) == 2 )
    {
      *(int *)((char *)v92 + v143) = *v91;
      if ( *(_DWORD *)(a2 + 28) )
        v94 = *v91;
      else
        v94 = -1;
      *v92 = v94;
      v93 = v142;
      ++v92;
    }
    ++v91;
    --ArgList;
  }
  while ( ArgList );
  for ( i3 = 1; i3 < 0xA; i3 = v96 + 1 )
  {
    v12 = sub_6624CC((&v125)[i3], v144);
    if ( v12 < 0 )
      goto LABEL_385;
  }
  ArgList = v144 & 0xFFFFF;
  v12 = sub_6641F3((_DWORD *)this, a2, v144 & 0xFFFFF | 0x10200000, v126, v125, 0);
  if ( v12 >= 0 )
  {
    v12 = sub_6641F3((_DWORD *)this, a2, ArgList | 0x10400000, v127, (_DWORD *)v126, 0x1400000000LL);
    if ( v12 >= 0 )
    {
      nn = ArgList | 0x10100000;
      v12 = sub_6641F3((_DWORD *)this, a2, ArgList | 0x10100000, (int)v128, (_DWORD *)v127, 0x1800000000LL);
      if ( v12 >= 0 )
      {
        v144 = ArgList | 0x20400000;
        v12 = sub_6641F3((_DWORD *)this, a2, ArgList | 0x20400000, v129, v128, (unsigned int)v126 | 0x200000000LL);
        if ( v12 >= 0 )
        {
          v12 = sub_6641F3((_DWORD *)this, a2, nn, v130, v125, 0);
          if ( v12 >= 0 )
          {
            *(_DWORD *)v141 = ArgList | 0x20200000;
            v12 = sub_6641F3(
                    (_DWORD *)this,
                    a2,
                    ArgList | 0x20200000,
                    (int)v131,
                    v125,
                    (unsigned int)v130 | 0x1700000000LL);
            if ( v12 >= 0 )
            {
              v12 = sub_6641F3((_DWORD *)this, a2, nn, SLODWORD(v132), (_DWORD *)v127, 0);
              if ( v12 >= 0 )
              {
                v12 = sub_6641F3(
                        (_DWORD *)this,
                        a2,
                        *(int *)v141,
                        SHIDWORD(v132),
                        (_DWORD *)LODWORD(v132),
                        (unsigned int)v127 | 0x1700000000LL);
                if ( v12 >= 0 )
                {
                  v12 = sub_6641F3(
                          (_DWORD *)this,
                          a2,
                          ArgList | 0x20500000,
                          SLODWORD(v133),
                          v131,
                          HIDWORD(v132) | 0x1700000000LL);
                  if ( v12 >= 0 )
                  {
                    v12 = sub_6641F3(
                            (_DWORD *)this,
                            a2,
                            v144,
                            SHIDWORD(v133),
                            (_DWORD *)v129,
                            LODWORD(v133) | 0x200000000LL);
                    if ( v12 >= 0 )
                    {
                      v97 = (_DWORD *)HIDWORD(v133);
                      *(_DWORD *)v141 = HIDWORD(a2);
                      ArgList = HIDWORD(v133);
                      nn = v7;
                      do
                      {
                        if ( *(_DWORD *)(v142 + *(_DWORD *)v141) == 2 )
                        {
                          v98 = *(_DWORD *)(*(_DWORD *)(this + 8) + 20);
                          v99 = *(double **)(v98 + 4 * *(_DWORD *)((char *)v97 + v143));
                          v148 = *(double **)(v98 + 4 * *v97);
                          v100 = *(_DWORD *)v99;
                          if ( (*(_DWORD *)v99 & 0x80u) != 0 )
                          {
                            v99[5] = v99[4];
                            *(_DWORD *)v99 = v100 | 0x100;
                          }
                          if ( (*((_BYTE *)v99 + 1) & 1) != 0 )
                          {
                            v101 = _finite(v99[4]);
                            v102 = v99[4];
                            if ( v101 )
                            {
                              v104 = *(double *)(this + 176);
                              if ( v105 )
                                v102 = -floor(v104 - v99[4]);
                              else
                                v102 = floor(v104 + v99[4]);
                            }
                            v148[4] = v102;
                            if ( _finite(v99[5]) )
                            {
                              v107 = *(double *)(this + 176);
                              if ( v108 )
                                v109 = -floor(v107 - v99[5]);
                              else
                                v109 = floor(v107 + v99[5]);
                              v148[5] = v109;
                              v110 = v148;
                            }
                            else
                            {
                              v110 = v148;
                              v148[5] = v99[5];
                            }
                            v111 = v110[5];
                            *((_BYTE *)v110 + 1) |= 1u;
                            v112 = *(_DWORD *)v110;
                            if ( v110[4] == v111 )
                              v113 = v112 | 0x80;
                            else
                              v113 = v112 & 0xFFFFFF7F;
                            *(_DWORD *)v110 = v113;
                          }
                          v114 = *(_DWORD *)ArgList;
                          ArgList += 4;
                          **(_DWORD **)v141 = v114;
                          v97 = (_DWORD *)ArgList;
                        }
                        *(_DWORD *)v141 += 4;
                        --nn;
                      }
                      while ( nn );
                      goto LABEL_372;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_385:
  sub_662493((_DWORD *)this, v146);
  sub_662493((_DWORD *)this, v147);
  return v12;
}
