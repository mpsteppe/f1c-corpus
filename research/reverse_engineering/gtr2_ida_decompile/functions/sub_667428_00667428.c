int __thiscall sub_667428(int this, _DWORD *a2, int a3, unsigned int a4, _DWORD *a5)
{
  int v6; // eax
  int v7; // esi
  int v8; // ecx
  int v9; // eax
  _DWORD *v10; // eax
  unsigned int v11; // edx
  _DWORD *i; // edi
  int v13; // eax
  int v14; // edi
  unsigned int v15; // eax
  int v16; // edx
  int v17; // esi
  _DWORD *v18; // esi
  _DWORD *v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // edi
  int v24; // ecx
  int v25; // esi
  bool v26; // zf
  _DWORD *v27; // eax
  int v28; // ecx
  int v29; // eax
  _DWORD *v30; // eax
  int v31; // ecx
  unsigned int v32; // eax
  char *v33; // edi
  char *v34; // esi
  char *v35; // edi
  char *v36; // esi
  char v37; // cl
  int v38; // eax
  int v39; // eax
  int v40; // eax
  unsigned int v41; // eax
  char *v42; // edi
  char *v43; // esi
  char *v44; // edi
  char *v45; // esi
  char v46; // cl
  int v47; // eax
  int v48; // eax
  int v49; // eax
  unsigned int v50; // edx
  _DWORD *v51; // eax
  unsigned int v52; // eax
  int v53; // ecx
  unsigned int v54; // edx
  _DWORD **v55; // ecx
  unsigned int v56; // esi
  unsigned int j; // esi
  void *v58; // ecx
  void *v59; // esi
  unsigned int *v60; // eax
  unsigned int v61; // eax
  int v62; // eax
  int v63; // eax
  unsigned int *v64; // eax
  unsigned int v65; // eax
  int v66; // ecx
  int *v67; // ecx
  int v68; // edx
  int v69; // eax
  int v70; // ecx
  int v71; // edx
  int v72; // esi
  int v73; // edx
  unsigned int v74; // edx
  unsigned int v75; // edx
  unsigned int v76; // edi
  char *v77; // edx
  unsigned int k; // eax
  char *v79; // eax
  int *v80; // esi
  int v81; // ecx
  unsigned int v82; // ecx
  int v83; // ecx
  int v84; // ecx
  int v85; // eax
  int v86; // edi
  unsigned int v87; // ecx
  int v88; // eax
  int v89; // edx
  bool v90; // cf
  unsigned int v91; // ecx
  int v92; // eax
  int v93; // edx
  unsigned int v94; // ecx
  int v95; // edx
  _DWORD *v96; // edi
  int v97; // eax
  int v98; // esi
  int v99; // ecx
  unsigned int v100; // edx
  BOOL v101; // eax
  int v102; // ecx
  BOOL v103; // eax
  int v105; // [esp-14h] [ebp-9Ch]
  int v106; // [esp-14h] [ebp-9Ch]
  char *v107; // [esp-10h] [ebp-98h]
  int v108; // [esp-10h] [ebp-98h]
  char *v109; // [esp-Ch] [ebp-94h]
  _DWORD *v110; // [esp-Ch] [ebp-94h]
  __int64 v111; // [esp-8h] [ebp-90h]
  __int64 v112; // [esp-8h] [ebp-90h]
  __int64 v113; // [esp-8h] [ebp-90h]
  unsigned int v114; // [esp-8h] [ebp-90h]
  _DWORD *v115; // [esp-8h] [ebp-90h]
  void *v116; // [esp-8h] [ebp-90h]
  void *v117; // [esp-4h] [ebp-8Ch]
  void *v118; // [esp-4h] [ebp-8Ch]
  int v119; // [esp-4h] [ebp-8Ch]
  char *v120; // [esp+Ch] [ebp-7Ch]
  char *v121; // [esp+10h] [ebp-78h]
  double v122; // [esp+14h] [ebp-74h] BYREF
  double v123; // [esp+1Ch] [ebp-6Ch]
  int v124; // [esp+24h] [ebp-64h]
  int v125; // [esp+28h] [ebp-60h]
  int v126; // [esp+2Ch] [ebp-5Ch]
  void *v127; // [esp+30h] [ebp-58h]
  int v128; // [esp+34h] [ebp-54h]
  int v129; // [esp+38h] [ebp-50h] BYREF
  int v130; // [esp+3Ch] [ebp-4Ch]
  int v131; // [esp+40h] [ebp-48h]
  int v132; // [esp+44h] [ebp-44h] BYREF
  int v133; // [esp+48h] [ebp-40h]
  int v134; // [esp+4Ch] [ebp-3Ch]
  int v135; // [esp+50h] [ebp-38h]
  int v136; // [esp+54h] [ebp-34h] BYREF
  int v137; // [esp+58h] [ebp-30h] BYREF
  int v138; // [esp+5Ch] [ebp-2Ch] BYREF
  unsigned int m; // [esp+60h] [ebp-28h]
  int v140; // [esp+64h] [ebp-24h]
  unsigned int v141; // [esp+68h] [ebp-20h] BYREF
  void *v142; // [esp+6Ch] [ebp-1Ch]
  void *v143; // [esp+70h] [ebp-18h]
  unsigned int v144; // [esp+74h] [ebp-14h] BYREF
  int v145; // [esp+78h] [ebp-10h]
  void *Block; // [esp+7Ch] [ebp-Ch]
  unsigned int v147; // [esp+80h] [ebp-8h]
  unsigned int v148; // [esp+84h] [ebp-4h]

  v132 = *(_DWORD *)(this + 44);
  v131 = *(_DWORD *)(this + 48);
  v130 = *(_DWORD *)(this + 52);
  v126 = *(_DWORD *)(this + 60);
  v125 = *(_DWORD *)(this + 64);
  Block = 0;
  v143 = 0;
  v142 = 0;
  v127 = 0;
  v128 = 0;
  v135 = 0;
  v133 = 0;
  v134 = 0;
  if ( sub_662830(this, a3, &v122) >= 0 )
  {
    if ( v122 > 0.0 || v123 < 0.0 )
    {
      v6 = sub_67051D(a4, 0);
      goto LABEL_8;
    }
    if ( v122 == 0.0 && v123 == 0.0 )
    {
      v6 = sub_67051D(a5, 0);
LABEL_8:
      v7 = v6;
      goto LABEL_219;
    }
  }
  v7 = sub_666F65((_DWORD *)this, 0, (unsigned int *)&a3, 1u);
  if ( v7 < 0 )
    goto LABEL_219;
  v137 = -1;
  v8 = *(_DWORD *)(this + 8);
  v145 = *(_DWORD *)(*(_DWORD *)(v8 + 20) + 4 * a3);
  v9 = *(_DWORD *)(v145 + 72);
  if ( v9 != -1 )
  {
    v10 = *(_DWORD **)(*(_DWORD *)(v8 + 24) + 4 * v9);
    if ( (*v10 & 0xFFF00000) == 0x20300000 )
    {
      v11 = 0;
      m = v10[3];
      if ( m )
      {
        for ( i = (_DWORD *)v10[4]; *i != a3; i = (_DWORD *)v140 )
        {
          ++v11;
          v140 = (int)(i + 1);
          if ( v11 >= m )
            break;
        }
      }
      v13 = v10[2];
      v14 = *(_DWORD *)(v13 + 4 * v11);
      v15 = *(_DWORD *)(v13 + 4 * (v11 + m));
      v141 = v15;
      v16 = *(_DWORD *)(v8 + 20);
      v17 = *(_DWORD *)(*(_DWORD *)(v16 + 4 * v14) + 72);
      if ( v17 != -1 && (**(_BYTE **)(v16 + 4 * v15) & 1) != 0 )
      {
        v18 = *(_DWORD **)(*(_DWORD *)(v8 + 24) + 4 * v17);
        if ( (*v18 & 0xFFF00000) == 0x10100000 )
        {
          m = 0;
          if ( v18[3] )
          {
            v19 = (_DWORD *)v18[4];
            do
            {
              if ( *v19 == v14 )
                break;
              ++m;
              ++v19;
            }
            while ( m < v18[3] );
          }
          if ( *(_DWORD *)(v18[2] + 4 * m) == v15 )
          {
            v7 = sub_666F65((_DWORD *)this, 0, &v141, 1u);
            if ( v7 < 0 )
              goto LABEL_219;
            v144 = -1;
            v138 = -1;
            v7 = sub_6641F3((_DWORD *)this, (unsigned int)a2, 268435457, (int)&v144, &v141, 0x1700000000LL);
            if ( v7 < 0 )
              goto LABEL_219;
            v7 = sub_6641F3((_DWORD *)this, (unsigned int)a2, 268435457, (int)&v138, &a3, 0x1700000000LL);
            if ( v7 < 0 )
              goto LABEL_219;
            v20 = *(_DWORD *)(this + 8);
            v21 = *(_DWORD *)(*(_DWORD *)(v20 + 20) + 4 * v141);
            v22 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v20 + 16) + 4 * *(_DWORD *)(v21 + 4)) + 4);
            v140 = 0;
            if ( (v22 & 0x10) == 0 || (v22 & 0x200) == 0 || *(_DWORD *)(v21 + 8) != -1 )
            {
              v141 = 0;
              goto LABEL_45;
            }
            goto LABEL_39;
          }
        }
      }
    }
  }
  v23 = v145;
  if ( (*(_BYTE *)v145 & 1) != 0 )
  {
    v136 = -1;
    v144 = -1;
    v138 = -1;
    v7 = sub_6641F3((_DWORD *)this, (unsigned int)a2, 269484033, (int)&v136, &a3, 0x1000000000LL);
    if ( v7 < 0 )
      goto LABEL_219;
    v7 = sub_6641F3((_DWORD *)this, (unsigned int)a2, 268435457, (int)&v144, &a3, 0x1700000000LL);
    if ( v7 < 0 )
      goto LABEL_219;
    HIDWORD(v111) = 23;
    LODWORD(v111) = &a3;
    v7 = sub_6641F3((_DWORD *)this, (unsigned int)a2, 540016641, (int)&v138, &v136, v111);
    if ( v7 < 0 )
      goto LABEL_219;
    v24 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 16) + 4 * *(_DWORD *)(v23 + 4)) + 4);
    v140 = 1;
    if ( (v24 & 0x10) != 0 && (v24 & 0x200) != 0 && *(_DWORD *)(v23 + 8) == -1 )
    {
LABEL_39:
      v141 = 1;
      goto LABEL_45;
    }
  }
  else
  {
    v129 = -1;
    v136 = -1;
    v144 = -1;
    v138 = -1;
    v7 = sub_666C0F((_DWORD *)this, (unsigned int)a2, &v129, &v136, (unsigned int)&a3, 1u);
    if ( v7 < 0 )
      goto LABEL_219;
    HIDWORD(v112) = 23;
    LODWORD(v112) = &v129;
    v7 = sub_6641F3((_DWORD *)this, (unsigned int)a2, 538968065, (int)&v144, &v136, v112);
    if ( v7 < 0 )
      goto LABEL_219;
    HIDWORD(v113) = 23;
    LODWORD(v113) = &v129;
    v7 = sub_6641F3((_DWORD *)this, (unsigned int)a2, 540016641, (int)&v138, &v136, v113);
    if ( v7 < 0 )
      goto LABEL_219;
    v140 = 1;
  }
  v141 = 0;
LABEL_45:
  v7 = sub_666F65((_DWORD *)this, 0, &v144, 1u);
  if ( v7 < 0 )
    goto LABEL_219;
  v25 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 16)
                  + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * v144) + 4));
  m = 0;
  v26 = (*(_DWORD *)(v25 + 4) & 0x800) == 0;
  v145 = 1;
  if ( v26 )
  {
LABEL_60:
    v27 = *(_DWORD **)(this + 8);
    if ( !v27[22] && (!v27[21] || !v141) && (!v27[13] || *(_DWORD *)(this + 48) != -1) )
      goto LABEL_67;
    v28 = 1;
    m = 1;
    goto LABEL_66;
  }
  if ( !strchr(*(const char **)v25, 98) && !strchr(*(const char **)v25, 66) )
  {
    if ( (*(_DWORD *)(v25 + 4) & 0x800) != 0 && (strchr(*(const char **)v25, 99) || strchr(*(const char **)v25, 67)) )
    {
      v27 = *(_DWORD **)(this + 8);
      if ( v27[22] || v27[13] && *(_DWORD *)(this + 48) == -1 )
      {
        v145 = 1;
        m = 1;
      }
      v141 = 0;
      goto LABEL_67;
    }
    goto LABEL_60;
  }
  v27 = *(_DWORD **)(this + 8);
  v28 = 0;
  if ( !v27[21] || !v141 )
    goto LABEL_67;
  m = 1;
LABEL_66:
  v145 = v28;
LABEL_67:
  if ( !v27[13] )
  {
    if ( !v145 )
      goto LABEL_78;
    if ( m )
    {
      if ( v141 )
      {
        if ( *(_DWORD *)(this + 60) < v27[21] )
          goto LABEL_75;
        goto LABEL_74;
      }
      if ( *(_DWORD *)(this + 64) >= v27[22] )
LABEL_74:
        m = 0;
    }
  }
LABEL_75:
  if ( v145 && (*(_BYTE *)(this + 21) & 2) != 0 )
    m = 0;
LABEL_78:
  if ( m && (*(_BYTE *)(this + 21) & 4) != 0 )
    v145 = 0;
  v148 = *(_DWORD *)(*(_DWORD *)(this + 4) + 24);
  v147 = 0;
  Block = operator new(4 * v148);
  if ( !Block )
    goto LABEL_218;
  v143 = operator new(4 * v148);
  if ( !v143 )
    goto LABEL_218;
  v142 = operator new(4 * v148);
  if ( !v142 )
    goto LABEL_218;
  qmemcpy(Block, *(const void **)(this + 24), 4 * v148);
  if ( m )
  {
    v29 = *(_DWORD *)(this + 8);
    v26 = *(_DWORD *)(v29 + 52) == 0;
    m = *(_DWORD *)(v29 + 12);
    if ( v26 )
    {
      if ( v141 )
        ++*(_DWORD *)(this + 60);
      else
        ++*(_DWORD *)(this + 64);
    }
    v137 = -1;
    v7 = sub_6641F3((_DWORD *)this, (unsigned int)a2, 284164097, (int)&v137, &v144, 0);
    if ( v7 < 0 )
      goto LABEL_219;
    v30 = *(_DWORD **)(this + 8);
    if ( v30[13] )
      v31 = v30[36];
    else
      v31 = v30[40];
    v26 = a4 == 0;
    *(_DWORD *)(*(_DWORD *)(v30[5] + 4 * v137) + 4) = v31;
    if ( v26 )
    {
      qmemcpy(v143, Block, 4 * v148);
    }
    else
    {
      v117 = Block;
      *(_DWORD *)(this + 48) = v137;
      v114 = a4;
      *(_DWORD *)(this + 52) = v140;
      v7 = sub_67051D(v114, v117);
      if ( v7 < 0 )
        goto LABEL_219;
      v32 = 4 * v148;
      qmemcpy(v143, *(const void **)(this + 24), 4 * v148);
      v33 = *(char **)(this + 24);
      v34 = (char *)Block;
      qmemcpy(v33, Block, 4 * (v32 >> 2));
      v36 = &v34[4 * (v32 >> 2)];
      v35 = &v33[4 * (v32 >> 2)];
      v37 = v32;
      v38 = v131;
      qmemcpy(v35, v36, v37 & 3);
      *(_DWORD *)(this + 48) = v38;
      *(_DWORD *)(this + 52) = v130;
      v39 = *(_DWORD *)(this + 80);
      *(_DWORD *)(this + 80) = 0;
      v128 = v39;
      v40 = *(_DWORD *)(this + 84);
      *(_DWORD *)(this + 84) = 0;
      v133 = v40;
    }
    if ( a5 )
    {
      v118 = Block;
      *(_DWORD *)(this + 48) = v137;
      v115 = a5;
      *(_DWORD *)(this + 52) = v140 == 0;
      v7 = sub_67051D(v115, v118);
      if ( v7 < 0 )
        goto LABEL_219;
      v41 = 4 * v148;
      qmemcpy(v142, *(const void **)(this + 24), 4 * v148);
      v42 = *(char **)(this + 24);
      v43 = (char *)Block;
      qmemcpy(v42, Block, 4 * (v41 >> 2));
      v45 = &v43[4 * (v41 >> 2)];
      v44 = &v42[4 * (v41 >> 2)];
      v46 = v41;
      v47 = v131;
      qmemcpy(v44, v45, v46 & 3);
      *(_DWORD *)(this + 48) = v47;
      *(_DWORD *)(this + 52) = v130;
      v48 = *(_DWORD *)(this + 80);
      *(_DWORD *)(this + 80) = 0;
      v135 = v48;
      v49 = *(_DWORD *)(this + 84);
      *(_DWORD *)(this + 84) = 0;
      v134 = v49;
    }
    else
    {
      qmemcpy(v142, Block, 4 * v148);
    }
    v50 = v148;
    v147 = 0;
    if ( v148 )
    {
      v51 = v143;
      do
      {
        if ( *v51 != *(_DWORD *)((char *)v51 + (_BYTE *)v142 - (_BYTE *)v143) )
          ++v147;
        ++v51;
        --v50;
      }
      while ( v50 );
    }
    v26 = v145 == 0;
    *(_DWORD *)(this + 60) = v126;
    *(_DWORD *)(this + 64) = v125;
    if ( v26 )
    {
      v52 = m;
      goto LABEL_122;
    }
    if ( v147 > 0x10 )
    {
      v52 = m;
    }
    else
    {
      v52 = m;
      if ( *(_DWORD *)(*(_DWORD *)(this + 8) + 12) - m <= 0x20 )
      {
LABEL_112:
        if ( v145 )
        {
          v53 = *(_DWORD *)(this + 8);
          v54 = v52;
          if ( v52 < *(_DWORD *)(v53 + 12) )
          {
            v55 = (_DWORD **)(*(_DWORD *)(v53 + 24) + 4 * v52);
            while ( (**v55 & 0xF0000000) != 0x60000000 )
            {
              ++v54;
              ++v55;
              if ( v54 >= *(_DWORD *)(*(_DWORD *)(this + 8) + 12) )
                goto LABEL_119;
            }
            v145 = 0;
          }
LABEL_119:
          if ( v145 )
          {
LABEL_130:
            for ( j = v52; j < *(_DWORD *)(*(_DWORD *)(this + 8) + 12); ++j )
            {
              v58 = *(void **)(*(_DWORD *)(*(_DWORD *)(this + 8) + 24) + 4 * j);
              if ( v58 )
              {
                sub_66238F(v58, 1);
                v52 = m;
              }
              *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 24) + 4 * j) = 0;
            }
            v59 = Block;
            *(_DWORD *)(*(_DWORD *)(this + 8) + 12) = v52;
            qmemcpy(*(void **)(this + 24), v59, 4 * v148);
            goto LABEL_135;
          }
        }
LABEL_122:
        if ( !v141 )
        {
          v56 = v52;
          if ( v52 < *(_DWORD *)(*(_DWORD *)(this + 8) + 12) )
          {
            while ( !sub_6810DD(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 24) + 4 * v56)) )
            {
              if ( ++v56 >= *(_DWORD *)(*(_DWORD *)(this + 8) + 12) )
                goto LABEL_128;
            }
            v145 = 1;
          }
        }
LABEL_128:
        if ( !v145 )
        {
LABEL_164:
          if ( !v147 )
            goto LABEL_199;
          v76 = v147;
          v77 = (char *)operator new(24 * v147);
          v127 = v77;
          if ( v77 )
          {
            for ( k = 0; k < 6; ++k )
            {
              (&v120)[k] = v77;
              v77 += 4 * v76;
            }
            v79 = v121;
            if ( v148 )
            {
              v80 = (int *)v142;
              m = v120 - v121;
              v81 = (_BYTE *)v143 - (_BYTE *)v142;
              a4 = LODWORD(v122) - (_DWORD)v121;
              v124 = (_BYTE *)v143 - (_BYTE *)v142;
              a5 = (_DWORD *)v148;
              do
              {
                v141 = (unsigned int)v80 + v81;
                if ( *(int *)((char *)v80 + v81) != *v80 )
                {
                  v82 = v144;
                  if ( !v140 )
                    v82 = v138;
                  *(_DWORD *)&v79[m] = v82;
                  v83 = *(_DWORD *)v141;
                  if ( *(_DWORD *)v141 == -1
                    || *(_DWORD *)(*(_DWORD *)(this + 8) + 116) == *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20)
                                                                                         + 4 * v83)
                                                                             + 4) )
                  {
                    v83 = *(_DWORD *)(this + 36);
                  }
                  *(_DWORD *)v79 = v83;
                  v84 = *v80;
                  if ( *v80 == -1
                    || *(_DWORD *)(*(_DWORD *)(this + 8) + 116) == *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20)
                                                                                         + 4 * v84)
                                                                             + 4) )
                  {
                    v84 = *(_DWORD *)(this + 36);
                  }
                  v76 = v147;
                  *(_DWORD *)&v79[a4] = v84;
                  v81 = v124;
                  v79 += 4;
                }
                ++v80;
                a5 = (_DWORD *)((char *)a5 - 1);
              }
              while ( a5 );
            }
            if ( v145 )
            {
              v85 = sub_666305(
                      (_DWORD *)this,
                      (unsigned int)a2,
                      (void *)HIDWORD(v122),
                      (char *)LODWORD(v122),
                      v121,
                      v120,
                      v76);
            }
            else
            {
              v109 = v121;
              v86 = v147 & 0xFFFFF;
              v107 = v121;
              a4 = v147 & 0xFFFFF | 0x10000000;
              v105 = a4;
              *(_DWORD *)(this + 48) = v137;
              *(_DWORD *)(this + 52) = v140;
              v7 = sub_6641F3((_DWORD *)this, (unsigned int)a2, v105, (int)v107, v109, 0);
              if ( v7 < 0 )
                goto LABEL_219;
              v87 = 0;
              if ( v147 )
              {
                do
                {
                  v88 = *(_DWORD *)(this + 8);
                  v89 = *(_DWORD *)(*(_DWORD *)(v88 + 20) + 4 * *(_DWORD *)&v121[4 * v87++]);
                  v90 = v87 < v147;
                  *(_DWORD *)(v89 + 4) = *(_DWORD *)(v88 + 152);
                }
                while ( v90 );
              }
              *(_DWORD *)(this + 48) = v137;
              v110 = (_DWORD *)LODWORD(v122);
              v108 = LODWORD(v122);
              v106 = a4;
              *(_DWORD *)(this + 52) = v140 == 0;
              v7 = sub_6641F3((_DWORD *)this, (unsigned int)a2, v106, v108, v110, 0);
              if ( v7 < 0 )
                goto LABEL_219;
              v91 = 0;
              if ( v147 )
              {
                do
                {
                  v92 = *(_DWORD *)(this + 8);
                  v93 = *(_DWORD *)(*(_DWORD *)(v92 + 20) + 4 * *(_DWORD *)(LODWORD(v122) + 4 * v91++));
                  v90 = v91 < v147;
                  *(_DWORD *)(v93 + 4) = *(_DWORD *)(v92 + 152);
                }
                while ( v90 );
              }
              v119 = v147;
              *(_DWORD *)(this + 48) = v131;
              v116 = (void *)HIDWORD(v122);
              *(_DWORD *)(this + 52) = v130;
              v7 = sub_6624CC(v116, v119);
              if ( v7 < 0 )
                goto LABEL_219;
              v85 = sub_6641F3((_DWORD *)this, (unsigned int)a2, v86 | 0x20700000, SHIDWORD(v122), v121, LODWORD(v122));
            }
            v7 = v85;
            if ( v85 < 0 )
              goto LABEL_219;
            v94 = 0;
            a4 = 0;
            if ( v148 )
            {
              v95 = (_BYTE *)v142 - (_BYTE *)v143;
              v96 = (_DWORD *)HIDWORD(v122);
              m = (_BYTE *)v142 - (_BYTE *)v143;
              do
              {
                if ( *((_DWORD *)v143 + v94) != *(_DWORD *)((char *)v143 + 4 * v94 + v95) )
                {
                  v97 = *(_DWORD *)(*(_DWORD *)(this + 8) + 20);
                  v98 = *(_DWORD *)(v97 + 4 * *v96);
                  v99 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v94);
                  if ( v99 != -1 )
                    sub_681692(*(_DWORD *)(v97 + 4 * v99));
                  v100 = a4;
                  *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * a4) = *v96;
                  v94 = v100;
                  v95 = m;
                  *(_DWORD *)(v98 + 48) = v94;
                  ++v96;
                }
                a4 = ++v94;
              }
              while ( v94 < v148 );
            }
            goto LABEL_199;
          }
LABEL_218:
          v7 = -2147024882;
          goto LABEL_219;
        }
        v52 = m;
        goto LABEL_130;
      }
    }
    v145 = 0;
    goto LABEL_112;
  }
LABEL_135:
  if ( !v145 )
    goto LABEL_164;
  if ( a4 )
  {
    v7 = sub_6624CC((void *)(this + 44), 1);
    if ( v7 < 0 )
      goto LABEL_219;
    v60 = &v144;
    if ( !v140 )
      v60 = (unsigned int *)&v138;
    v7 = sub_6641F3((_DWORD *)this, (unsigned int)a2, 542113793, this + 44, &v132, (unsigned int)v60 | 0x1700000000LL);
    if ( v7 < 0 )
      goto LABEL_219;
    v7 = sub_67051D(a4, Block);
    if ( v7 < 0 )
      goto LABEL_219;
    v61 = 4 * v148;
    qmemcpy(v143, *(const void **)(this + 24), 4 * v148);
    qmemcpy(*(void **)(this + 24), Block, v61);
    *(_DWORD *)(this + 44) = v132;
    v62 = *(_DWORD *)(this + 80);
    *(_DWORD *)(this + 80) = 0;
    v128 = v62;
    v63 = *(_DWORD *)(this + 84);
    *(_DWORD *)(this + 84) = 0;
    v133 = v63;
  }
  else
  {
    qmemcpy(v143, Block, 4 * v148);
  }
  if ( a5 )
  {
    v7 = sub_6624CC((void *)(this + 44), 1);
    if ( v7 < 0 )
      goto LABEL_219;
    v64 = (unsigned int *)&v138;
    if ( !v140 )
      v64 = &v144;
    v7 = sub_6641F3((_DWORD *)this, (unsigned int)a2, 542113793, this + 44, &v132, (unsigned int)v64 | 0x1700000000LL);
    if ( v7 < 0 )
      goto LABEL_219;
    v7 = sub_67051D(a5, Block);
    if ( v7 < 0 )
      goto LABEL_219;
    v65 = 4 * v148;
    qmemcpy(v142, *(const void **)(this + 24), 4 * v148);
    qmemcpy(*(void **)(this + 24), Block, v65);
    v66 = *(_DWORD *)(this + 84);
    *(_DWORD *)(this + 44) = v132;
    v135 = *(_DWORD *)(this + 80);
    *(_DWORD *)(this + 80) = 0;
    v134 = v66;
    *(_DWORD *)(this + 84) = 0;
  }
  else
  {
    qmemcpy(v142, Block, 4 * v148);
  }
  v147 = 0;
  a4 = 0;
  if ( v148 )
  {
    v67 = (int *)v143;
    v68 = (_BYTE *)v142 - (_BYTE *)v143;
    a5 = v143;
    for ( m = (_BYTE *)v142 - (_BYTE *)v143; ; v68 = m )
    {
      v69 = *v67;
      v141 = (unsigned int)v67 + v68;
      v70 = *(int *)((char *)v67 + v68);
      if ( v69 != v70 )
      {
        if ( v69 == -1
          || (v71 = *(_DWORD *)(this + 8),
              v72 = *(_DWORD *)(v71 + 20),
              v73 = *(_DWORD *)(v71 + 116),
              v73 == *(_DWORD *)(*(_DWORD *)(v72 + 4 * v69) + 4)) )
        {
          v75 = a4;
          *a5 = v70;
          *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v75) = v70;
        }
        else if ( v70 == -1 || v73 == *(_DWORD *)(*(_DWORD *)(v72 + 4 * v70) + 4) )
        {
          v74 = a4;
          *(_DWORD *)v141 = v69;
          *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v74) = v69;
        }
        else
        {
          ++v147;
        }
      }
      ++a4;
      v67 = ++a5;
      if ( a4 >= v148 )
        break;
    }
    goto LABEL_164;
  }
LABEL_199:
  v7 = 0;
  v101 = v133 && v134;
  v102 = v128;
  v26 = v128 == 0;
  *(_DWORD *)(this + 84) = v101;
  v103 = !v26 && (v135 || v134) || v135 && (v102 || v133);
  *(_DWORD *)(this + 80) = v103;
  if ( v102 )
  {
    if ( v135 )
      goto LABEL_215;
    if ( !v134 )
    {
LABEL_217:
      sub_663C07((_DWORD *)this, a2, 3500, "asymetric returns from if statements not yet implemented");
      v7 = -2147467263;
      goto LABEL_219;
    }
  }
  if ( !v135 )
    goto LABEL_219;
LABEL_215:
  if ( !v102 && !v133 )
    goto LABEL_217;
LABEL_219:
  j__free(Block);
  j__free(v143);
  j__free(v142);
  j__free(v127);
  *(_DWORD *)(this + 44) = v132;
  *(_DWORD *)(this + 48) = v131;
  *(_DWORD *)(this + 52) = v130;
  *(_DWORD *)(this + 60) = v126;
  *(_DWORD *)(this + 64) = v125;
  return v7;
}
