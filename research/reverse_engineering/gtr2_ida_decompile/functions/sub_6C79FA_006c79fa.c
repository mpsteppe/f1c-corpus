int __thiscall sub_6C79FA(_DWORD *this, int a2)
{
  int *v3; // edx
  int v4; // esi
  unsigned int v5; // eax
  int v6; // eax
  unsigned int v7; // ecx
  int v8; // edi
  unsigned int v9; // ecx
  _DWORD *v10; // esi
  int v11; // eax
  int v12; // edi
  unsigned int v13; // edx
  _DWORD *v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // ecx
  int v17; // esi
  int v18; // ecx
  unsigned int v19; // edi
  int v20; // edx
  _DWORD *v21; // eax
  int *v22; // eax
  _DWORD *v23; // ecx
  int v24; // edi
  int v25; // esi
  _DWORD *v26; // edx
  unsigned int j; // eax
  int v28; // esi
  unsigned int v29; // edi
  int v30; // ecx
  int *v31; // eax
  _DWORD *v32; // ecx
  unsigned int v33; // eax
  unsigned int m; // eax
  int v35; // ecx
  unsigned int v36; // edx
  int v37; // eax
  unsigned int v38; // edx
  char *v39; // eax
  unsigned int v40; // ecx
  int v41; // edi
  unsigned int v42; // ecx
  _DWORD *v43; // esi
  int v44; // eax
  int v45; // edi
  unsigned int v46; // edx
  _DWORD *v47; // ecx
  unsigned int v48; // eax
  int v49; // esi
  unsigned int v50; // ecx
  int v51; // ecx
  unsigned int v52; // edi
  int v53; // edx
  _DWORD *v54; // eax
  int *v55; // eax
  _DWORD *v56; // ecx
  int *v57; // edi
  int v58; // esi
  _DWORD *v59; // edx
  unsigned int ii; // eax
  int v61; // esi
  unsigned int v62; // edi
  int v63; // ecx
  int *v64; // eax
  _DWORD *v65; // ecx
  unsigned int v66; // eax
  unsigned int jj; // eax
  int v68; // ecx
  unsigned int v69; // edi
  int v70; // eax
  unsigned int kk; // ecx
  int v72; // eax
  int v73; // esi
  unsigned int v74; // ecx
  int v75; // eax
  unsigned int v76; // ecx
  int v77; // eax
  unsigned int v78; // ecx
  char *v79; // esi
  int v81; // eax
  int v82; // eax
  int v83; // eax
  unsigned int v84; // eax
  int v85; // ecx
  int v86; // edx
  int v87; // edi
  int v88; // edx
  unsigned int v89; // ecx
  _DWORD *v90; // esi
  int *v91; // esi
  int v92; // eax
  _DWORD *v93; // eax
  unsigned int v94; // edi
  int v95; // eax
  int v96; // eax
  char *v97; // eax
  unsigned int v98; // eax
  _DWORD *v99; // ecx
  int v100; // eax
  _DWORD *v101; // edx
  _DWORD **v102; // edi
  int v103; // ecx
  int v104; // eax
  unsigned int v105; // edx
  int v106; // [esp+0h] [ebp-2D8h]
  int v107; // [esp+0h] [ebp-2D8h]
  _DWORD v108[40]; // [esp+14h] [ebp-2C4h] BYREF
  _DWORD v109[40]; // [esp+B4h] [ebp-224h] BYREF
  _DWORD v110[8]; // [esp+154h] [ebp-184h] BYREF
  _DWORD v111[32]; // [esp+174h] [ebp-164h] BYREF
  char v112[64]; // [esp+1F4h] [ebp-E4h] BYREF
  _DWORD v113[16]; // [esp+234h] [ebp-A4h] BYREF
  int v114[4]; // [esp+274h] [ebp-64h] BYREF
  char *v115; // [esp+284h] [ebp-54h]
  int v116[4]; // [esp+288h] [ebp-50h] BYREF
  int v117; // [esp+298h] [ebp-40h]
  int mm; // [esp+29Ch] [ebp-3Ch]
  int *v119; // [esp+2A0h] [ebp-38h]
  int v120; // [esp+2A4h] [ebp-34h]
  unsigned int v121; // [esp+2A8h] [ebp-30h]
  unsigned int v122; // [esp+2ACh] [ebp-2Ch] BYREF
  int *v123; // [esp+2B0h] [ebp-28h]
  unsigned int v124; // [esp+2B4h] [ebp-24h]
  unsigned int i; // [esp+2B8h] [ebp-20h]
  unsigned int v126; // [esp+2BCh] [ebp-1Ch] BYREF
  unsigned int k; // [esp+2C0h] [ebp-18h]
  unsigned int v128; // [esp+2C4h] [ebp-14h]
  unsigned int v129; // [esp+2C8h] [ebp-10h]
  _DWORD **v130; // [esp+2CCh] [ebp-Ch]
  unsigned int n; // [esp+2D0h] [ebp-8h]
  int nn; // [esp+2D4h] [ebp-4h]

  v3 = (int *)this[64];
  v4 = *v3;
  v124 = *v3 & 0xFFFFF;
  v5 = v124;
  v115 = 0;
  v122 = 0;
  v116[0] = 0;
  v116[1] = 1;
  v116[2] = 2;
  v116[3] = 3;
  mm = 0;
  n = (unsigned int)v3;
  v121 = v124;
  if ( (v4 & 0xFFF00000) == 0x20400000 )
  {
    v120 = 0;
LABEL_3:
    v129 = 0;
LABEL_4:
    memset(v109, 0xFFu, sizeof(v109));
    memset(v108, 0xFFu, sizeof(v108));
    v6 = 0;
    v126 = 0;
    nn = 0;
    v128 = 0;
    k = 0;
    while ( 1 )
    {
      if ( v129 )
        v7 = 1 - v128;
      else
        v7 = v128;
      v8 = *(_DWORD *)(n + 8);
      v9 = dword_74577C[v7];
      v10 = (_DWORD *)(v8 + 4 * v6);
      if ( v9 >= 0x10 )
      {
        v13 = 0;
        v14 = &v109[4 * v9 - 64];
        do
        {
          v15 = v116[v13];
          if ( v15 >= v124 )
            *v14 = -1;
          else
            *v14 = *(_DWORD *)(v8 + 4 * (v15 + k));
          ++v13;
          ++v14;
        }
        while ( v13 < 4 );
      }
      else
      {
        v11 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v10) + 72);
        if ( v11 == -1
          || (v12 = 8 * v9,
              v106 = dword_745788[8 * v9],
              v123 = *(int **)(this[6] + 4 * v11),
              sub_6BB1AA(this, v123, (int)v10, v124, v116, v114, v106, 0)) )
        {
          nn = 1;
LABEL_21:
          v128 = 0;
          v130 = 0;
          do
          {
            if ( v129 )
              v16 = 1 - v128;
            else
              v16 = v128;
            if ( (unsigned int)dword_74577C[v16] >= 0x10 )
            {
              for ( i = 0; i < v126; ++i )
              {
                v17 = 0;
                if ( v124 )
                {
                  v18 = v113[i];
                  v19 = *(_DWORD *)(v18 + 12);
                  while ( 1 )
                  {
                    k = 0;
                    if ( v19 )
                      break;
LABEL_33:
                    if ( ++v17 >= v124 )
                      goto LABEL_36;
                  }
                  v20 = *(_DWORD *)(*(_DWORD *)(n + 8) + 4 * ((_DWORD)v130 + v17));
                  v21 = *(_DWORD **)(v18 + 16);
                  while ( v20 != *v21 )
                  {
                    ++k;
                    v19 = *(_DWORD *)(v18 + 12);
                    ++v21;
                    if ( k >= v19 )
                      goto LABEL_33;
                  }
                  nn = 1;
                }
LABEL_36:
                ;
              }
            }
            ++v128;
            v130 = (_DWORD **)((char *)v130 + v124);
          }
          while ( v128 < 2 );
          if ( nn )
            goto LABEL_77;
          if ( !v120 )
          {
            for ( i = 0; i < v126; ++i )
            {
              v22 = *(int **)(v113[i] + 12);
              k = 0;
              v119 = v22;
              if ( v22 )
              {
                do
                {
                  if ( this[3] )
                  {
                    v130 = (_DWORD **)this[6];
                    v123 = (int *)this[3];
                    do
                    {
                      v23 = *v130;
                      if ( *v130 && *v23 )
                      {
                        v24 = v23[1];
                        v128 = 0;
                        if ( v24 )
                        {
                          v25 = *(_DWORD *)(*(_DWORD *)(v113[i] + 16) + 4 * k);
                          v26 = (_DWORD *)v23[2];
                          v117 = v24;
                          do
                          {
                            if ( *v26 == v25 || *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v26) + 56) == v25 )
                              v128 = 1;
                            ++v26;
                            --v117;
                          }
                          while ( v117 );
                        }
                        if ( v23 == (_DWORD *)n )
                          v128 = 0;
                        if ( v128 )
                        {
                          for ( j = 0; j < v126; ++j )
                          {
                            if ( v23 == (_DWORD *)v113[j] )
                              v128 = 0;
                          }
                          if ( v128 )
                            nn = 1;
                        }
                      }
                      ++v130;
                      v123 = (int *)((char *)v123 - 1);
                    }
                    while ( v123 );
                  }
                  ++k;
                }
                while ( k < (unsigned int)v119 );
              }
            }
            for ( k = 0; k < 0x28; ++k )
            {
              v28 = v109[k];
              if ( v28 != -1 )
              {
                v29 = 0;
                if ( v126 )
                {
                  v119 = *(int **)(this[5] + 4 * v28);
                  do
                  {
                    v30 = v113[v29];
                    v31 = *(int **)(v30 + 12);
                    if ( v31 )
                    {
                      v32 = *(_DWORD **)(v30 + 16);
                      v123 = v31;
                      do
                      {
                        if ( v28 == *v32 || v119[14] == *v32 )
                          nn = 1;
                        ++v32;
                        v123 = (int *)((char *)v123 - 1);
                      }
                      while ( v123 );
                    }
                    ++v29;
                  }
                  while ( v29 < v126 );
                }
              }
            }
            if ( nn )
            {
LABEL_77:
              if ( ++v129 < 2 )
                goto LABEL_4;
              if ( ++v120 )
                goto LABEL_86;
              goto LABEL_3;
            }
          }
          v33 = 4 * v126;
          qmemcpy(v112, v113, 4 * v126);
          *(_DWORD *)&v112[v33] = n;
          v122 = v126 + 1;
          for ( m = 0; m < 40; ++m )
          {
            v35 = v109[m];
            if ( v35 == -1 )
            {
              v35 = v108[m];
              if ( v35 == -1 )
                continue;
            }
            v110[m] = v35;
          }
          nn = 0;
LABEL_86:
          if ( nn )
          {
            v5 = v121;
            break;
          }
LABEL_231:
          v93 = (_DWORD *)sub_681186(116);
          if ( v93 )
            v79 = (char *)sub_680CEC(v93);
          else
            v79 = 0;
          if ( !v79 )
            return -2147024882;
          v94 = v121;
          v95 = v121 & 0xFFFFF;
          if ( mm )
            v96 = v95 | 0x70400000;
          else
            v96 = v95 | 0x70300000;
          nn = sub_6811D1(v79, v96, 3 * v121, v121, 0);
          if ( nn >= 0 )
          {
            nn = sub_680D22(v79, this[64]);
            if ( nn >= 0 )
            {
              v97 = 0;
              v123 = 0;
              if ( v94 )
              {
                n = 8 * v94;
                v130 = (_DWORD **)(4 * v94);
                do
                {
                  v98 = 4 * (_DWORD)v97;
                  *(_DWORD *)(v98 + *((_DWORD *)v79 + 4)) = *(_DWORD *)(v98 + *(_DWORD *)(this[64] + 16));
                  v99 = &v110[v98 / 4 + 4];
                  *(_DWORD *)(v98 + *((_DWORD *)v79 + 2)) = v110[v98 / 4];
                  v100 = *((_DWORD *)v79 + 2);
                  v101 = (_DWORD *)*v99;
                  v102 = v130;
                  v103 = v99[4];
                  ++v130;
                  *(_DWORD **)((char *)v102 + v100) = v101;
                  v104 = *((_DWORD *)v79 + 2);
                  v105 = n;
                  n += 4;
                  *(_DWORD *)(v105 + v104) = v103;
                  v97 = (char *)v123 + 1;
                  v123 = (int *)((char *)v123 + 1);
                }
                while ( (unsigned int)v123 < v121 );
              }
              if ( !a2 )
                return sub_6C29D6(this, v79, (int)v112, v122);
              nn = sub_681430((char *)this[64], v79);
              if ( nn >= 0 )
LABEL_202:
                nn = 0;
            }
          }
          if ( v79 )
            sub_66238F(v79, 1);
          return nn;
        }
        nn = sub_6BB35B(this, v123, &dword_745770[v12], (char *)v113, &v126, (int)v108, v114, v121, 0);
      }
      if ( nn != 1 )
      {
        v6 = v124 + k;
        ++v128;
        k += v124;
        if ( v128 < 2 )
          continue;
      }
      goto LABEL_21;
    }
  }
  k = this[64];
  v36 = *(_DWORD *)k;
  v124 = *(_DWORD *)k;
  v124 &= 0xFFFFFu;
  if ( v124 > v5 || (v36 & 0xFFF00000) != 0x20400000 )
  {
    v37 = 1;
    goto LABEL_176;
  }
  v120 = 0;
LABEL_92:
  v128 = 0;
  while ( 2 )
  {
    v38 = v122;
    qmemcpy(v113, v112, 4 * v122);
    memset(v109, 0xFFu, sizeof(v109));
    memset(v108, 0xFFu, sizeof(v108));
    v39 = 0;
    v126 = v38;
    nn = 0;
    v129 = 0;
    v130 = 0;
    while ( 1 )
    {
      if ( v128 )
        v40 = 1 - v129;
      else
        v40 = v129;
      v41 = *(_DWORD *)(k + 8);
      v42 = dword_7457DC[v40];
      v43 = (_DWORD *)(v41 + 4 * (_DWORD)v39);
      if ( v42 >= 0x10 )
      {
        v46 = 0;
        v47 = &v109[4 * v42 - 64];
        do
        {
          v48 = v116[v46];
          if ( v48 >= v124 )
            *v47 = -1;
          else
            *v47 = *(_DWORD *)(v41 + 4 * ((_DWORD)v130 + v48));
          ++v46;
          ++v47;
        }
        while ( v46 < 4 );
        goto LABEL_106;
      }
      v44 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v43) + 72);
      if ( v44 == -1 )
        break;
      v45 = 8 * v42;
      v107 = dword_7457E8[8 * v42];
      v119 = *(int **)(this[6] + 4 * v44);
      if ( sub_6BB1AA(this, v119, (int)v43, v124, v116, v114, v107, 0) )
        break;
      nn = sub_6BB35B(this, v119, &dword_7457D0[v45], (char *)v113, &v126, (int)v108, v114, v121, 0);
LABEL_106:
      if ( nn != 1 )
      {
        v39 = (char *)v130 + v124;
        ++v129;
        v130 = (_DWORD **)((char *)v130 + v124);
        if ( v129 < 2 )
          continue;
      }
      goto LABEL_110;
    }
    nn = 1;
LABEL_110:
    v49 = 0;
    v129 = 0;
    i = 0;
    do
    {
      if ( v128 )
        v50 = 1 - v129;
      else
        v50 = v129;
      if ( (unsigned int)dword_7457DC[v50] >= 0x10 )
      {
        for ( n = 0; n < v126; v49 = 0 )
        {
          if ( v124 )
          {
            v51 = v113[n];
            v52 = *(_DWORD *)(v51 + 12);
            while ( 1 )
            {
              v130 = 0;
              if ( v52 )
                break;
LABEL_122:
              if ( ++v49 >= v124 )
                goto LABEL_125;
            }
            v53 = *(_DWORD *)(*(_DWORD *)(k + 8) + 4 * (v49 + i));
            v54 = *(_DWORD **)(v51 + 16);
            while ( v53 != *v54 )
            {
              v130 = (_DWORD **)((char *)v130 + 1);
              v52 = *(_DWORD *)(v51 + 12);
              ++v54;
              if ( (unsigned int)v130 >= v52 )
                goto LABEL_122;
            }
            nn = 1;
          }
LABEL_125:
          ++n;
        }
      }
      ++v129;
      i += v124;
    }
    while ( v129 < 2 );
    if ( nn )
      goto LABEL_166;
    if ( !v120 )
    {
      for ( i = 0; i < v126; ++i )
      {
        v55 = *(int **)(v113[i] + 12);
        n = 0;
        v119 = v55;
        if ( v55 )
        {
          do
          {
            if ( this[3] )
            {
              v130 = (_DWORD **)this[6];
              v117 = this[3];
              do
              {
                v56 = *v130;
                if ( *v130 && *v56 )
                {
                  v57 = (int *)v56[1];
                  v129 = 0;
                  if ( v57 )
                  {
                    v58 = *(_DWORD *)(*(_DWORD *)(v113[i] + 16) + 4 * n);
                    v59 = (_DWORD *)v56[2];
                    v123 = v57;
                    do
                    {
                      if ( *v59 == v58 || *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v59) + 56) == v58 )
                        v129 = 1;
                      ++v59;
                      v123 = (int *)((char *)v123 - 1);
                    }
                    while ( v123 );
                  }
                  if ( v56 == (_DWORD *)k )
                    v129 = 0;
                  if ( v129 )
                  {
                    for ( ii = 0; ii < v126; ++ii )
                    {
                      if ( v56 == (_DWORD *)v113[ii] )
                        v129 = 0;
                    }
                    if ( v129 )
                      nn = 1;
                  }
                }
                ++v130;
                --v117;
              }
              while ( v117 );
            }
            ++n;
          }
          while ( n < (unsigned int)v119 );
        }
      }
      for ( n = 0; n < 0x28; ++n )
      {
        v61 = v109[n];
        if ( v61 != -1 )
        {
          v62 = 0;
          if ( v126 )
          {
            v119 = *(int **)(this[5] + 4 * v61);
            do
            {
              v63 = v113[v62];
              v64 = *(int **)(v63 + 12);
              if ( v64 )
              {
                v65 = *(_DWORD **)(v63 + 16);
                v123 = v64;
                do
                {
                  if ( v61 == *v65 || v119[14] == *v65 )
                    nn = 1;
                  ++v65;
                  v123 = (int *)((char *)v123 - 1);
                }
                while ( v123 );
              }
              ++v62;
            }
            while ( v62 < v126 );
          }
        }
      }
      if ( nn )
      {
LABEL_166:
        if ( ++v128 < 2 )
          continue;
        if ( ++v120 )
          goto LABEL_175;
        goto LABEL_92;
      }
    }
    break;
  }
  v66 = 4 * v126;
  qmemcpy(v112, v113, 4 * v126);
  *(_DWORD *)&v112[v66] = k;
  v122 = v126 + 1;
  for ( jj = 0; jj < 40; ++jj )
  {
    v68 = v109[jj];
    if ( v68 == -1 )
    {
      v68 = v108[jj];
      if ( v68 == -1 )
        continue;
    }
    v110[jj] = v68;
  }
  nn = 0;
LABEL_175:
  v37 = nn;
LABEL_176:
  mm = 1;
  if ( !v37 )
    goto LABEL_231;
  if ( !a2 )
    goto LABEL_180;
  mm = 0;
  if ( !sub_6BB35B(this, (int *)this[64], dword_745770, v112, &v122, (int)v110, v116, v121, a2) )
    goto LABEL_231;
  v37 = sub_6BB35B(this, (int *)this[64], dword_7457D0, v112, &v122, (int)v110, v116, v121, a2);
  mm = 1;
LABEL_180:
  if ( !v37 )
    goto LABEL_231;
  v69 = v121;
  mm = 0;
  v70 = sub_6BB35B(this, (int *)this[64], dword_745830, v112, &v122, (int)v110, v116, v121, a2);
  for ( kk = 0; kk < v69; ++kk )
  {
    if ( v110[kk] != v110[kk + 4] )
      v70 = 1;
  }
  if ( v70 )
  {
    v122 = 0;
    v72 = sub_6BB35B(this, (int *)this[64], dword_745890, v112, &v122, (int)v110, v116, v69, a2);
    v73 = 1;
    v74 = 0;
    nn = v72;
    for ( mm = 1; v74 < v69; ++v74 )
    {
      if ( v110[v74] != v110[v74 + 4] )
        nn = 1;
    }
    if ( nn )
    {
      mm = 0;
      v122 = 0;
      v75 = sub_6BB35B(this, (int *)this[64], dword_7458F0, v112, &v122, (int)v110, v116, v69, a2);
      v76 = 0;
      for ( nn = v75; v76 < v69; ++v76 )
      {
        if ( v110[v76] != v110[v76 + 4] )
          nn = 1;
      }
      if ( nn )
      {
        v122 = 0;
        v77 = sub_6BB35B(this, (int *)this[64], dword_745950, v112, &v122, (int)v110, v116, v69, a2);
        v78 = 0;
        nn = v77;
        for ( mm = 1; v78 < v69; ++v78 )
        {
          if ( v110[v78] != v110[v78 + 4] )
            nn = 1;
        }
        if ( nn )
        {
          v79 = v115;
          goto LABEL_202;
        }
      }
    }
  }
  else
  {
    v73 = 1;
  }
  v81 = 0;
  if ( !v69 )
  {
LABEL_210:
    if ( this[88] != -1
      || (v82 = sub_681A51(this, (int)"c", 785, 1, 4), this[92] = v82, v82 != -1)
      && (v83 = sub_681AAA(this, v82, 0, 0, 2.0), this[88] = v83, v83 != -1) )
    {
      v84 = 0;
      if ( v69 )
      {
        v85 = this[88];
        do
        {
          v86 = v111[v84];
          v110[v84] = v85;
          if ( v86 != v111[0] )
            v73 = 0;
          ++v84;
        }
        while ( v84 < v69 );
      }
      v87 = this[5];
      v88 = *(_DWORD *)(v87 + 4 * v111[0]);
      if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v88 + 4)) + 5) & 1) == 0 || !v73 )
        goto LABEL_231;
      v89 = 0;
      v90 = this + 89;
      do
      {
        if ( *v90 == -1 )
          break;
        if ( *(double *)(*(_DWORD *)(v87 + 4 * *v90) + 32) == *(double *)(v88 + 32) )
          break;
        ++v89;
        ++v90;
      }
      while ( v89 < 3 );
      if ( v89 == 3 )
        goto LABEL_231;
      v91 = &this[v89 + 89];
      if ( *v91 != -1 || (v92 = sub_681AAA(this, this[92], 0, v89 + 1, *(double *)(v88 + 32)), *v91 = v92, v92 != -1) )
      {
        if ( v121 )
          memset32(v111, *v91, v121);
        goto LABEL_231;
      }
    }
    return -2147024882;
  }
  while ( v110[v81] == v110[v81 + 4] )
  {
    if ( ++v81 >= v69 )
      goto LABEL_210;
  }
  return 1;
}
