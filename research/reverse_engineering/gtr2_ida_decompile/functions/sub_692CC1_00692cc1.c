int __thiscall sub_692CC1(int this)
{
  unsigned int v2; // eax
  bool v4; // zf
  int v5; // ecx
  unsigned int i; // edx
  int v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int v14; // edx
  unsigned int v15; // esi
  unsigned int v16; // edx
  int v17; // ecx
  int v18; // eax
  unsigned int j; // edx
  _DWORD *v20; // eax
  int v21; // ecx
  int v22; // ecx
  unsigned int *v23; // ecx
  unsigned int v24; // eax
  _DWORD *v25; // eax
  unsigned int k; // edi
  int v27; // ecx
  int v28; // edx
  int v29; // edi
  _DWORD *v30; // eax
  _DWORD *v31; // eax
  int v32; // edx
  int v33; // ecx
  int v34; // esi
  int v35; // eax
  unsigned int v36; // esi
  unsigned int v37; // edi
  int v38; // eax
  unsigned int v39; // eax
  unsigned int v40; // eax
  int v41; // ecx
  int v42; // edx
  unsigned int v43; // eax
  char *v44; // esi
  char v45; // dl
  unsigned int v46; // ecx
  int *v47; // edi
  char *v48; // esi
  unsigned int v49; // edx
  const void *v50; // esi
  char *v51; // edx
  char *v52; // eax
  char *v53; // esi
  char *v54; // edi
  char v55; // dl
  unsigned int v56; // ecx
  char *v57; // edi
  char *v58; // esi
  unsigned int v59; // edx
  _DWORD *v60; // eax
  char *v61; // edi
  int v62; // esi
  int *v63; // esi
  unsigned int v64; // eax
  int *v65; // esi
  char *v66; // edx
  int *v67; // edi
  int v68; // eax
  unsigned int v69; // ecx
  int v70; // ecx
  int v71; // edx
  char *v72; // eax
  int m; // eax
  _DWORD *v74; // ecx
  _DWORD *v75; // eax
  _DWORD *v76; // esi
  _DWORD *v77; // eax
  int v78; // eax
  char *v79; // eax
  void *v80; // ecx
  int v81; // ecx
  int v82; // ecx
  _DWORD *v83; // esi
  int *v84; // edi
  unsigned int v85; // edx
  int v86; // eax
  int v87; // edi
  const void *v88; // esi
  unsigned int v89; // ecx
  int v90; // eax
  int v91; // eax
  unsigned int v92; // eax
  _DWORD *v93; // esi
  char v94; // dl
  unsigned int v95; // ecx
  int *v96; // edi
  _DWORD *v97; // esi
  int v98; // edx
  const void *v99; // esi
  unsigned int v100; // edx
  int v101; // eax
  int v102; // edi
  int v103; // eax
  unsigned int v104; // eax
  char *v105; // esi
  char v106; // dl
  unsigned int v107; // ecx
  char *v108; // edi
  char *v109; // esi
  int v110; // edx
  int v111; // eax
  int v112; // edi
  int v113; // eax
  int v114; // eax
  _DWORD *v115; // esi
  char v116; // dl
  unsigned int v117; // ecx
  int *v118; // edi
  _DWORD *v119; // esi
  int v120; // edx
  int v121; // edi
  int v122; // eax
  int *v123; // esi
  int v124; // edi
  _DWORD *v125; // edx
  _DWORD *v126; // ecx
  int v127; // eax
  unsigned int v128; // esi
  void *v129; // eax
  _DWORD *v130; // eax
  _DWORD *v131; // edi
  unsigned int v132; // edx
  unsigned int v133; // ecx
  unsigned int ii; // esi
  _DWORD *v135; // eax
  _DWORD *v136; // eax
  _DWORD *v137; // ecx
  char *v138; // esi
  unsigned int v139; // eax
  char *v140; // edi
  unsigned int v141; // edx
  char *v142; // edi
  char *v143; // esi
  char v144; // cl
  unsigned int v145; // edx
  char *v146; // esi
  char *v147; // edi
  unsigned int v148; // edx
  char *v149; // edi
  char *v150; // esi
  char v151; // cl
  int v152; // edx
  unsigned int v153; // ecx
  int *v154; // esi
  int *v155; // edi
  int *v156; // esi
  unsigned int v157; // ecx
  int *v158; // edi
  int *v159; // edi
  char v160; // dl
  unsigned int v161; // ecx
  int *v162; // edi
  int *v163; // esi
  int v164; // edx
  _DWORD *v165; // esi
  unsigned int v166; // edi
  int v167; // eax
  unsigned int v168; // eax
  unsigned int v169; // edx
  void *v170; // [esp-18h] [ebp-D4h]
  _DWORD *v171; // [esp-14h] [ebp-D0h]
  __int64 v172; // [esp-10h] [ebp-CCh]
  __int64 v173; // [esp-10h] [ebp-CCh]
  __int64 v174; // [esp-10h] [ebp-CCh]
  __int64 v175; // [esp-10h] [ebp-CCh]
  __int64 v176; // [esp-10h] [ebp-CCh]
  __int64 v177; // [esp-10h] [ebp-CCh]
  __int64 v178; // [esp-10h] [ebp-CCh]
  __int64 v179; // [esp-10h] [ebp-CCh]
  _BYTE v180[16]; // [esp+4h] [ebp-B8h] BYREF
  int v181[4]; // [esp+14h] [ebp-A8h] BYREF
  int v182[4]; // [esp+24h] [ebp-98h] BYREF
  int v183[4]; // [esp+34h] [ebp-88h] BYREF
  int v184; // [esp+44h] [ebp-78h]
  int v185[4]; // [esp+48h] [ebp-74h] BYREF
  int v186; // [esp+58h] [ebp-64h]
  void *v187; // [esp+5Ch] [ebp-60h]
  int v188; // [esp+60h] [ebp-5Ch]
  int v189; // [esp+64h] [ebp-58h]
  unsigned int v190; // [esp+68h] [ebp-54h]
  void *v191; // [esp+6Ch] [ebp-50h]
  int v192[4]; // [esp+70h] [ebp-4Ch] BYREF
  char *v193; // [esp+80h] [ebp-3Ch]
  int v194; // [esp+84h] [ebp-38h]
  unsigned int v195; // [esp+88h] [ebp-34h]
  char *v196; // [esp+8Ch] [ebp-30h]
  unsigned int v197; // [esp+90h] [ebp-2Ch]
  void *Block; // [esp+94h] [ebp-28h]
  int v199; // [esp+98h] [ebp-24h]
  unsigned int v200; // [esp+9Ch] [ebp-20h]
  int n; // [esp+A0h] [ebp-1Ch]
  unsigned int v202; // [esp+A4h] [ebp-18h]
  int v203; // [esp+A8h] [ebp-14h]
  unsigned int v204; // [esp+ACh] [ebp-10h]
  unsigned int v205; // [esp+B0h] [ebp-Ch]
  unsigned int v206; // [esp+B4h] [ebp-8h]
  int v207; // [esp+B8h] [ebp-4h]

  v2 = 0;
  if ( (*(_BYTE *)(this + 204) & 4) != 0 )
    return 1;
  v4 = *(_DWORD *)(this + 4) == 0;
  v186 = 0;
  if ( !v4 )
  {
    do
    {
      v5 = *(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v2++);
      *(_DWORD *)(v5 + 16) = 0;
    }
    while ( v2 < *(_DWORD *)(this + 4) );
  }
  for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
  {
    v7 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * i);
    v8 = *(_DWORD *)(v7 + 4);
    if ( *(_DWORD *)(this + 116) != v8 )
    {
      v9 = *(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v8);
      v10 = *(_DWORD *)(v9 + 4);
      if ( (v10 & 2) != 0 && (v10 & 0x400) == 0 )
      {
        v11 = *(_DWORD *)(v7 + 12) + 1;
        if ( *(_DWORD *)(v9 + 16) < v11 )
          *(_DWORD *)(v9 + 16) = v11;
      }
    }
  }
  v12 = 0;
  if ( *(_DWORD *)(this + 4) )
  {
    v13 = *(_DWORD *)(this + 16);
    v14 = *(_DWORD *)(this + 4);
    do
    {
      v12 += *(_DWORD *)(*(_DWORD *)v13 + 16);
      v13 += 4;
      --v14;
    }
    while ( v14 );
  }
  v15 = 4 * v12;
  v191 = operator new(4 * v12);
  if ( !v191 )
  {
LABEL_178:
    v62 = -2147024882;
    goto LABEL_177;
  }
  memset(v191, 0, v15);
  v16 = 0;
  v17 = 0;
  if ( *(_DWORD *)(this + 4) )
  {
    v18 = *(_DWORD *)(this + 16);
    do
    {
      *(_DWORD *)(*(_DWORD *)(v18 + 4 * v16) + 28) = *(_DWORD *)(*(_DWORD *)(v18 + 4 * v16) + 16) != 0
                                                   ? (char *)v191 + 4 * v17
                                                   : 0;
      v18 = *(_DWORD *)(this + 16);
      v17 += *(_DWORD *)(*(_DWORD *)(v18 + 4 * v16++) + 16);
    }
    while ( v16 < *(_DWORD *)(this + 4) );
  }
  for ( j = 0; j < *(_DWORD *)(this + 8); ++j )
  {
    v20 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * j);
    v21 = v20[1];
    if ( *(_DWORD *)(this + 116) != v21 )
    {
      v22 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v21) + 28);
      if ( v22 )
      {
        v23 = (unsigned int *)(v22 + 4 * v20[3]);
        v24 = v20[4] + 1;
        if ( *v23 < v24 )
          *v23 = v24;
      }
    }
  }
  v4 = *(_DWORD *)(this + 12) == 0;
  v202 = 0;
  if ( !v4 )
  {
    do
    {
      v25 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v202);
      if ( (*v25 & 0xF0000000) == 0x60000000 || (*v25 & 0xFFF00000) == 0x11000000 )
      {
        for ( k = 0; k < v25[1]; ++k )
        {
          v27 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(v25[2] + 4 * k));
          v28 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v27 + 4)) + 28);
          if ( v28 )
            *(_DWORD *)(v28 + 4 * *(_DWORD *)(v27 + 12)) = 4;
        }
      }
      ++v202;
    }
    while ( v202 < *(_DWORD *)(this + 12) );
  }
  if ( (*(_DWORD *)(this + 108) & 6) != 0 || (sub_686074(this), v206 = 0, !*(_DWORD *)(this + 12)) )
  {
LABEL_66:
    sub_686074(this);
    v203 = 0;
    if ( !*(_DWORD *)(this + 12) )
    {
LABEL_176:
      v62 = v186 == 0;
      goto LABEL_177;
    }
    while ( 1 )
    {
      v67 = *(int **)(*(_DWORD *)(this + 24) + 4 * v203);
      v68 = *v67;
      v69 = *v67 & 0xF0000000;
      Block = v67;
      if ( v69 >= 0x10000000
        && v69 <= 0x40000000
        && ((v68 & 0xFFF00000) == 0x10000000 || (*(_BYTE *)(this + 108) & 6) == 0)
        && !sub_680F76(v67) )
      {
        v70 = *(_DWORD *)(this + 20);
        v71 = *(_DWORD *)(this + 16);
        v189 = *(_DWORD *)(*(_DWORD *)(v70 + 4 * *(_DWORD *)v67[4]) + 4);
        v200 = *(_DWORD *)(*(_DWORD *)(v71 + 4 * v189) + 28);
        if ( v200 )
          break;
      }
LABEL_175:
      if ( (unsigned int)++v203 >= *(_DWORD *)(this + 12) )
        goto LABEL_176;
    }
    v72 = *(char **)(this + 12);
    v196 = 0;
    v4 = v67[1] == 0;
    v193 = v72;
    v195 = (unsigned int)v72;
    if ( !v4 )
    {
      v202 = v67[2];
      v197 = v67[1];
      do
      {
        for ( m = *(_DWORD *)v202; m != -1; m = v75[2] )
        {
          v75 = *(_DWORD **)(v70 + 4 * m);
          if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v75[1]) + 4) & 2) != 0
            && (unsigned int)v196 < v75[18] + 1 )
          {
            v196 = (char *)(v75[18] + 1);
          }
        }
        v202 += 4;
        --v197;
      }
      while ( v197 );
    }
    if ( v67[3] )
    {
      v76 = (_DWORD *)v67[4];
      v197 = v67[3];
      do
      {
        v77 = *(_DWORD **)(v70 + 4 * *v76);
        if ( (unsigned int)v193 > v77[21] )
          v193 = (char *)v77[21];
        while ( 1 )
        {
          v78 = v77[2];
          if ( v78 == -1 )
            break;
          v77 = *(_DWORD **)(v70 + 4 * v78);
          if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v77[1]) + 4) & 2) != 0
            && (unsigned int)v196 < v77[18] + 1 )
          {
            v196 = (char *)(v77[18] + 1);
          }
        }
        ++v76;
        --v197;
      }
      while ( v197 );
    }
    v79 = v196;
    for ( n = (int)v196; ; v79 = (char *)n )
    {
      if ( v79 >= v193 )
        goto LABEL_175;
      if ( v203 != n )
      {
        v80 = *(void **)(*(_DWORD *)(this + 24) + 4 * n);
        v187 = v80;
        v206 = (unsigned int)(v203 >= (unsigned int)n ? Block : v80);
        v207 = (int)(v203 >= (unsigned int)n ? v80 : Block);
        v81 = *(_DWORD *)v207;
        v205 = *(_DWORD *)v206;
        v190 = v205;
        v205 &= 0xFFF00000;
        if ( v205 == (v81 & 0xFFF00000) )
        {
          v82 = *(_DWORD *)(this + 20);
          v83 = *(_DWORD **)(v82 + 4 * **(_DWORD **)(v207 + 16));
          v84 = *(int **)(v82 + 4 * **(_DWORD **)(v206 + 16));
          v4 = v84[1] == v83[1];
          v194 = v84[1];
          if ( v4 && v84[2] == v83[2] && v84[5] == v83[5] && v84[6] == v83[6] )
          {
            v85 = *(_DWORD *)(v206 + 12);
            v184 = *(_DWORD *)(v206 + 4) + *(_DWORD *)(v207 + 4);
            v86 = *(_DWORD *)(v207 + 12);
            v204 = v85;
            v188 = v86;
            v199 = v86 + v85;
            if ( v86 + v85 <= 4 )
            {
              v87 = v84[3];
              v88 = (const void *)v83[3];
              v202 = v87;
              v197 = (unsigned int)v88;
              if ( (const void *)v87 == v88
                || (*(_BYTE *)(this + 108) & 6) == 0
                && (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v194) + 4) & 0x20) == 0
                && (unsigned int)(*(_DWORD *)(v200 + 4 * v87) + *(_DWORD *)(v200 + 4 * v197)) <= 4 )
              {
                break;
              }
            }
          }
        }
      }
LABEL_140:
      ++n;
    }
    v194 = v203;
    if ( v203 >= (unsigned int)n )
      v194 = n;
    if ( v205 == 0x10000000 || v205 == 269484032 )
    {
      v123 = *(int **)(v207 + 8);
      v124 = *v123;
      v205 = *(_DWORD *)(v206 + 8);
      v125 = *(_DWORD **)(v82 + 4 * *(_DWORD *)v205);
      v126 = *(_DWORD **)(v82 + 4 * v124);
      if ( v125[1] == v126[1] && v125[2] == v126[2] && v125[3] == v126[3] )
      {
        v127 = v86;
        qmemcpy(v192, v123, v127 * 4);
        qmemcpy(&v192[v127], (const void *)v205, 4 * v204);
LABEL_133:
        v204 = 0;
        goto LABEL_134;
      }
    }
    else
    {
      v89 = v190 & 0xF0000000;
      if ( (v190 & 0xF0000000) == 0x10000000 )
      {
        HIDWORD(v172) = v194;
        v90 = v86;
        qmemcpy(v192, *(const void **)(v207 + 8), v90 * 4);
        LODWORD(v172) = 0;
        v171 = (_DWORD *)v207;
        qmemcpy(&v192[v90], *(const void **)(v206 + 8), 4 * v204);
        v91 = sub_68CCED((_DWORD *)this, v192, v199, 0, 0, v171, v172);
      }
      else
      {
        if ( v89 == 0x20000000 )
        {
          v92 = 4 * v86;
          qmemcpy(v192, *(const void **)(v207 + 8), v92);
          v93 = *(_DWORD **)(v206 + 8);
          v204 *= 4;
          v94 = v204;
          v95 = v204 >> 2;
          v205 = (unsigned int)v93;
          qmemcpy(&v192[v92 / 4], v93, 4 * (v204 >> 2));
          v97 = &v93[v95];
          v96 = &v192[v92 / 4 + v95];
          LOBYTE(v95) = v94;
          v98 = *(_DWORD *)(v207 + 8);
          qmemcpy(v96, v97, v95 & 3);
          HIDWORD(v173) = v194;
          qmemcpy(v185, (const void *)(v98 + v92), 4 * (v92 >> 2));
          v99 = (const void *)(v98 + v92 + 4 * (v92 >> 2));
          v100 = v205;
          qmemcpy(&v185[v92 >> 2], v99, v92 & 3);
          v190 = v92;
          qmemcpy(&v185[v92 / 4], (const void *)(v100 + v204), v204);
          LODWORD(v173) = 0;
          v101 = sub_68CCED((_DWORD *)this, v192, v199, 0, 0, (_DWORD *)v207, v173);
          HIDWORD(v174) = v194;
          LODWORD(v174) = 0;
          v102 = v101;
          v103 = sub_68CCED((_DWORD *)this, v185, v199, 0, 0, (_DWORD *)v207, v174);
          if ( v102 && v103 )
            goto LABEL_133;
          if ( sub_680DDB((_DWORD *)v206) )
          {
            v104 = v190;
            qmemcpy(v183, *(const void **)(v207 + 8), v190);
            v105 = (char *)(*(_DWORD *)(v206 + 8) + v204);
            v205 = *(_DWORD *)(v206 + 8);
            v106 = v204;
            v107 = v204 >> 2;
            qmemcpy((char *)v183 + v104, v105, 4 * (v204 >> 2));
            v109 = &v105[4 * v107];
            v108 = (char *)&v183[v107] + v104;
            HIDWORD(v175) = v194;
            LOBYTE(v107) = v106;
            v110 = *(_DWORD *)(v207 + 8);
            qmemcpy(v108, v109, v107 & 3);
            qmemcpy(v182, (const void *)(v110 + v104), v104);
            qmemcpy((char *)v182 + v104, (const void *)v205, v204);
            LODWORD(v175) = 0;
            v111 = sub_68CCED((_DWORD *)this, v183, v199, 0, 0, (_DWORD *)v207, v175);
            HIDWORD(v176) = v194;
            LODWORD(v176) = 0;
            v112 = v111;
            v113 = sub_68CCED((_DWORD *)this, v182, v199, 0, 0, (_DWORD *)v207, v176);
            if ( v112 )
            {
              if ( v113 )
              {
                v204 = 1;
LABEL_134:
                if ( v202 == v197 || (unsigned int)(*(_DWORD *)(v200 + 4 * v202) + *(_DWORD *)(v200 + 4 * v197)) <= 4 )
                {
                  v130 = (_DWORD *)sub_681186(116);
                  if ( v130 )
                    v205 = (unsigned int)sub_680CEC(v130);
                  else
                    v205 = 0;
                  if ( !v205 )
                    goto LABEL_178;
                  v131 = (_DWORD *)v206;
                  v62 = sub_6811D1((char *)v205, *(_DWORD *)v206 ^ (v199 ^ *(_DWORD *)v206) & 0xFFFFF, v184, v199, 0);
                  if ( v62 < 0 || (v62 = sub_680D22((_DWORD *)v205, (int)v131), v62 < 0) )
                  {
                    v74 = (_DWORD *)v205;
                    goto LABEL_77;
                  }
                  v132 = v197;
                  if ( v202 != v197 )
                  {
                    v133 = v200;
                    for ( ii = 0; ii < *(_DWORD *)(this + 8); ++ii )
                    {
                      v135 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * ii);
                      if ( v189 == v135[1] && v202 == v135[3] )
                      {
                        v135[3] = v132;
                        v135[4] += *(_DWORD *)(v133 + 4 * v132);
                      }
                    }
                    v136 = (_DWORD *)(v133 + 4 * v132);
                    v137 = (_DWORD *)(v133 + 4 * v202);
                    *v136 += *v137;
                    *v137 = 0;
                  }
                  v138 = *(char **)(v207 + 16);
                  v139 = v205;
                  v140 = *(char **)(v205 + 16);
                  v141 = 4 * *(_DWORD *)(v207 + 12);
                  qmemcpy(v140, v138, 4 * (v141 >> 2));
                  v143 = &v138[4 * (v141 >> 2)];
                  v142 = &v140[4 * (v141 >> 2)];
                  v144 = v141;
                  v145 = v206;
                  qmemcpy(v142, v143, v144 & 3);
                  v146 = *(char **)(v145 + 16);
                  v147 = (char *)(*(_DWORD *)(v139 + 16) + 4 * *(_DWORD *)(v207 + 12));
                  v148 = 4 * *(_DWORD *)(v145 + 12);
                  qmemcpy(v147, v146, 4 * (v148 >> 2));
                  v150 = &v146[4 * (v148 >> 2)];
                  v149 = &v147[4 * (v148 >> 2)];
                  v151 = v148;
                  v152 = v199;
                  qmemcpy(v149, v150, v151 & 3);
                  if ( (*(_DWORD *)v206 & 0xF0000000) == 0x10000000 )
                    qmemcpy(*(void **)(v139 + 8), v192, 4 * v152);
                  v153 = *(_DWORD *)v206 & 0xF0000000;
                  if ( v153 == 0x20000000 )
                  {
                    v154 = v192;
                    if ( v204 )
                      v154 = v183;
                    v155 = *(int **)(v139 + 8);
                    v189 = 4 * v152;
                    qmemcpy(v155, v154, 4 * v152);
                    v156 = v185;
                    if ( v204 )
                      v156 = v182;
                    v157 = v189;
                    v158 = (int *)(v189 + *(_DWORD *)(v139 + 8));
LABEL_166:
                    qmemcpy(v158, v156, v157);
                  }
                  else if ( v153 == 805306368 )
                  {
                    qmemcpy(*(void **)(v139 + 8), v192, 4 * v152);
                    v159 = (int *)(4 * v199 + *(_DWORD *)(v139 + 8));
                    v160 = 4 * v199;
                    v161 = (unsigned int)(4 * v199) >> 2;
                    qmemcpy(v159, v185, 4 * v161);
                    v163 = &v185[v161];
                    v162 = &v159[v161];
                    LOBYTE(v161) = v160;
                    v164 = v199;
                    qmemcpy(v162, v163, v161 & 3);
                    v157 = 4 * v164;
                    v156 = v181;
                    v158 = (int *)(*(_DWORD *)(v139 + 8) + 8 * v164);
                    goto LABEL_166;
                  }
                  v165 = Block;
                  v166 = v205;
                  Block = (void *)(*((_DWORD *)Block + 1) / (*(_DWORD *)Block & 0xFFFFFu));
                  sub_685E08((_DWORD *)this, *(_DWORD **)(v205 + 16), (int)v180, v199, 1);
                  v200 = 0;
                  if ( Block )
                  {
                    do
                    {
                      sub_685E08(
                        (_DWORD *)this,
                        (_DWORD *)(*(_DWORD *)(v166 + 8) + 4 * v200 * *(_DWORD *)(v166 + 12)),
                        (int)v180,
                        v199,
                        0);
                      ++v200;
                    }
                    while ( v200 < (unsigned int)Block );
                  }
                  if ( v187 )
                    sub_66238F(v187, 1);
                  v167 = 4 * n;
                  *(_DWORD *)(v167 + *(_DWORD *)(this + 24)) = v166;
                  v200 = v167;
                  *v165 = 0;
                  v165[1] = 0;
                  v165[3] = 0;
                  v168 = *(_DWORD *)(this + 12);
                  if ( v168 > v195 )
                  {
                    v187 = (void *)(v168 - v195);
                    v197 = 4 * (v168 - v195);
                    Block = operator new(v197);
                    if ( !Block )
                      goto LABEL_178;
                    v169 = v195;
                    qmemcpy(Block, (const void *)(*(_DWORD *)(this + 24) + 4 * v195), v197);
                    memcpy(
                      (void *)(*(_DWORD *)(this + 24) + 4 * ((_DWORD)v187 + n)),
                      (const void *)(*(_DWORD *)(this + 24) + v200),
                      4 * (v169 - n));
                    v170 = Block;
                    qmemcpy((void *)(v200 + *(_DWORD *)(this + 24)), Block, v197);
                    j__free(v170);
                  }
                  sub_686074(this);
                  v186 = 1;
                  v203 = (int)(v196 - 1);
                  goto LABEL_175;
                }
                goto LABEL_136;
              }
            }
          }
          goto LABEL_136;
        }
        if ( v89 != 805306368 )
          goto LABEL_136;
        v114 = v86;
        qmemcpy(v192, *(const void **)(v207 + 8), v114 * 4);
        v205 = *(_DWORD *)(v206 + 8);
        qmemcpy(&v192[v114], (const void *)v205, 4 * v204);
        qmemcpy(v185, (const void *)(*(_DWORD *)(v207 + 8) + v114 * 4), v114 * 4);
        v115 = (_DWORD *)(v205 + 4 * v204);
        v116 = 4 * v204;
        v117 = (4 * v204) >> 2;
        qmemcpy(&v185[v114], v115, 4 * v117);
        v119 = &v115[v117];
        v118 = &v185[v114 + v117];
        LOBYTE(v117) = v116;
        v120 = *(_DWORD *)(v207 + 8);
        qmemcpy(v118, v119, v117 & 3);
        HIDWORD(v177) = v194;
        qmemcpy(v181, (const void *)(v120 + 8 * v188), v114 * 4);
        qmemcpy(&v181[v114], (const void *)(v205 + 8 * v204), 4 * v204);
        LODWORD(v177) = 0;
        v121 = sub_68CCED((_DWORD *)this, v192, v199, 0, 0, (_DWORD *)v207, v177);
        HIDWORD(v178) = v194;
        LODWORD(v178) = 0;
        v122 = sub_68CCED((_DWORD *)this, v185, v199, 0, 0, (_DWORD *)v207, v178);
        HIDWORD(v179) = v194;
        v188 = v122;
        LODWORD(v179) = 0;
        v91 = sub_68CCED((_DWORD *)this, v181, v199, 0, 0, (_DWORD *)v207, v179);
        if ( !v121 || !v188 )
          goto LABEL_136;
      }
      if ( v91 )
        goto LABEL_133;
    }
LABEL_136:
    v128 = v195;
    while ( *(_DWORD *)(this + 12) > v128 )
    {
      --*(_DWORD *)(this + 12);
      v129 = *(void **)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(this + 12));
      if ( v129 )
        sub_66238F(v129, 1);
    }
    goto LABEL_140;
  }
  while ( 1 )
  {
    v29 = *(_DWORD *)(this + 24);
    v30 = *(_DWORD **)(v29 + 4 * v206);
    v4 = *v30 == 541065217;
    n = (int)v30;
    if ( v4 )
    {
      v31 = (_DWORD *)v30[2];
      v32 = *(_DWORD *)(this + 20);
      v33 = *(_DWORD *)(v32 + 4 * *v31);
      v34 = *(_DWORD *)(v33 + 4);
      Block = *(void **)(v32 + 4 * v31[1]);
      v35 = *(_DWORD *)(this + 16);
      if ( (*(_BYTE *)(*(_DWORD *)(v35 + 4 * v34) + 4) & 2) != 0
        && (*(_BYTE *)(*(_DWORD *)(v35 + 4 * *((_DWORD *)Block + 1)) + 4) & 2) != 0 )
      {
        v36 = *(_DWORD *)(v29 + 4 * *(_DWORD *)(v33 + 72));
        v37 = *(_DWORD *)(v29 + 4 * *((_DWORD *)Block + 18));
        v38 = *(_DWORD *)v36;
        v4 = *(_DWORD *)v36 == 542113793;
        v202 = v36;
        v204 = v37;
        if ( (v4 || (v38 & 0xFFF00000) == 0x50000000)
          && (*(_DWORD *)v37 == 542113793 || (*(_DWORD *)v37 & 0xFFF00000) == 0x50000000) )
        {
          v39 = *(_DWORD *)(v36 + 4);
          Block = (void *)(*(_DWORD *)(v37 + 4) >> 1);
          v40 = v39 >> 1;
          v203 = (int)Block + v40;
          if ( (unsigned int)Block + v40 >= (~(unsigned __int8)*(_DWORD *)(this + 108) & 0x20 | 0x40u) >> 5
            && (unsigned int)v203 <= 4 )
          {
            v41 = *(_DWORD *)(v32 + 4 * **(_DWORD **)(v36 + 16));
            if ( v206 == *(_DWORD *)(v41 + 84) && v206 == *(_DWORD *)(v41 + 88) )
            {
              v42 = *(_DWORD *)(v32 + 4 * **(_DWORD **)(v37 + 16));
              if ( v206 == *(_DWORD *)(v42 + 84) && v206 == *(_DWORD *)(v42 + 88) )
              {
                v43 = 4 * v40;
                v197 = *(_DWORD *)(v202 + 8);
                qmemcpy(v185, (const void *)v197, v43);
                v44 = *(char **)(v204 + 8);
                v200 = 4 * (_DWORD)Block;
                v45 = 4 * (_BYTE)Block;
                v46 = (unsigned int)(4 * (_DWORD)Block) >> 2;
                v193 = v44;
                qmemcpy(&v185[v43 / 4], v44, 4 * v46);
                v48 = &v44[4 * v46];
                v47 = &v185[v43 / 4 + v46];
                LOBYTE(v46) = v45;
                v49 = v197;
                qmemcpy(v47, v48, v46 & 3);
                qmemcpy(v182, (const void *)(v49 + v43), 4 * (v43 >> 2));
                v50 = (const void *)(v49 + v43 + 4 * (v43 >> 2));
                v51 = v193;
                qmemcpy(&v182[v43 >> 2], v50, v43 & 3);
                v195 = v43;
                qmemcpy(&v182[v43 / 4], &v51[v200], v200);
                if ( sub_68CCED((_DWORD *)this, v185, v203, 0, 0, (_DWORD *)n, 0xFFFFFFFF00000000uLL)
                  && sub_68CCED((_DWORD *)this, v182, v203, 0, 0, (_DWORD *)n, 0xFFFFFFFF00000000uLL) )
                {
                  v195 = 0;
                  goto LABEL_54;
                }
                v52 = *(char **)(v202 + 8);
                qmemcpy(v192, v52, v195);
                v53 = (char *)(*(_DWORD *)(v204 + 8) + v200);
                v54 = (char *)v192 + v195;
                v193 = *(char **)(v204 + 8);
                v55 = v200;
                v56 = v200 >> 2;
                qmemcpy((char *)v192 + v195, v53, 4 * (v200 >> 2));
                v58 = &v53[4 * v56];
                v57 = &v54[4 * v56];
                LOBYTE(v56) = v55;
                v59 = v195;
                qmemcpy(v57, v58, v56 & 3);
                qmemcpy(v183, &v52[v59], v59);
                qmemcpy((char *)v183 + v59, v193, v200);
                if ( sub_68CCED((_DWORD *)this, v192, v203, 0, 0, (_DWORD *)n, 0xFFFFFFFF00000000uLL) )
                {
                  if ( sub_68CCED((_DWORD *)this, v183, v203, 0, 0, (_DWORD *)n, 0xFFFFFFFF00000000uLL) )
                    break;
                }
              }
            }
          }
        }
      }
    }
LABEL_65:
    if ( ++v206 >= *(_DWORD *)(this + 12) )
      goto LABEL_66;
  }
  v195 = 1;
LABEL_54:
  v60 = (_DWORD *)sub_681186(116);
  if ( v60 )
    v196 = (char *)sub_680CEC(v60);
  else
    v196 = 0;
  if ( !v196 )
    goto LABEL_178;
  v61 = v196;
  v62 = sub_6811D1(v196, v203 & 0xFFFFF | 0x50000000, 2 * v203, 1, 0);
  if ( v62 >= 0 )
  {
    v62 = sub_680D22(v61, n);
    if ( v62 >= 0 )
    {
      v4 = v195 == 0;
      **((_DWORD **)v61 + 4) = **(_DWORD **)(n + 16);
      v63 = v185;
      if ( !v4 )
        v63 = v192;
      v64 = 4 * v203;
      qmemcpy(*((void **)v196 + 2), v63, 4 * v203);
      v65 = v182;
      if ( v195 )
        v65 = v183;
      v66 = v196;
      qmemcpy((void *)(v64 + *((_DWORD *)v196 + 2)), v65, v64);
      *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v206) = v66;
      sub_66238F((void *)n, 1);
      *(_DWORD *)v202 = 0;
      *(_DWORD *)v204 = 0;
      goto LABEL_65;
    }
  }
  v74 = v61;
LABEL_77:
  sub_66238F(v74, 1);
LABEL_177:
  j__free(v191);
  return v62;
}
