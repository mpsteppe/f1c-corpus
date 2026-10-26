int __thiscall sub_68CCED(_DWORD *this, int *a2, unsigned int a3, int a4, int *a5, _DWORD *a6, __int64 a7)
{
  unsigned int i; // esi
  unsigned int v10; // eax
  int *v11; // esi
  int j; // edi
  unsigned int v13; // ecx
  unsigned int v14; // edi
  int v15; // eax
  int v16; // eax
  bool v17; // zf
  double v18; // st7
  int v19; // eax
  int v20; // eax
  int v21; // esi
  int v22; // ecx
  int v23; // eax
  int v24; // eax
  int v25; // edi
  int v26; // esi
  int v27; // eax
  int v28; // eax
  double v29; // st7
  int v30; // eax
  int *v31; // edi
  int v32; // eax
  unsigned int v33; // esi
  int v34; // eax
  unsigned int v35; // esi
  int v36; // edi
  int v37; // eax
  int v38; // edx
  unsigned int v39; // ecx
  int v40; // esi
  int v41; // eax
  _DWORD *v42; // edi
  unsigned int v43; // eax
  unsigned int v44; // esi
  int v45; // ecx
  int v46; // edx
  unsigned int kk; // edi
  int v48; // eax
  unsigned int v49; // eax
  int v50; // edx
  _DWORD *v51; // eax
  int v52; // ecx
  _DWORD *v53; // edi
  unsigned int v54; // eax
  int v55; // edx
  int v56; // eax
  _DWORD *v57; // ecx
  int *v58; // eax
  unsigned int nn; // ecx
  int v60; // eax
  unsigned int v61; // eax
  unsigned int v62; // eax
  int v63; // esi
  int v64; // edi
  int v65; // ecx
  unsigned int i2; // edi
  _DWORD *v67; // esi
  int v68; // eax
  unsigned int i3; // edx
  _DWORD *v70; // eax
  _DWORD *v71; // eax
  unsigned int v72; // eax
  unsigned int v73; // eax
  int *v74; // edi
  int v75; // esi
  int v76; // eax
  int *v77; // eax
  int v78; // edx
  double v79; // st7
  double *v80; // eax
  unsigned int v81; // esi
  int v82; // edi
  double *v83; // ecx
  int v84; // eax
  int v85; // esi
  _DWORD *v86; // edi
  int v87; // esi
  _DWORD *v88; // edi
  int v89; // eax
  int v90; // esi
  int v91; // edi
  int v92; // eax
  unsigned int v93; // edi
  int v94; // ecx
  int v95; // eax
  unsigned int v96; // ecx
  int v97; // edx
  int v98; // ecx
  _DWORD *v99; // ecx
  int v100; // edi
  int *v101; // eax
  unsigned int v102; // ecx
  bool v103; // zf
  int *v104; // edx
  int v105; // eax
  int v106; // eax
  int v107; // edx
  _DWORD *v108; // ecx
  int v109; // edi
  _DWORD *v110; // eax
  int *v111; // edx
  int *v112; // ecx
  int *v113; // eax
  unsigned int v114; // edx
  int v115; // eax
  int v116; // [esp-4h] [ebp-E4h]
  int v117; // [esp-4h] [ebp-E4h]
  int v118; // [esp+4h] [ebp-DCh]
  _DWORD v119[20]; // [esp+14h] [ebp-CCh] BYREF
  double v120; // [esp+64h] [ebp-7Ch]
  double v121; // [esp+6Ch] [ebp-74h]
  int v122; // [esp+74h] [ebp-6Ch]
  _DWORD v123[4]; // [esp+78h] [ebp-68h] BYREF
  int *v124; // [esp+88h] [ebp-58h]
  _DWORD *v125; // [esp+8Ch] [ebp-54h]
  double n; // [esp+90h] [ebp-50h] BYREF
  double jj; // [esp+98h] [ebp-48h] BYREF
  int *v128; // [esp+A0h] [ebp-40h]
  int v129[4]; // [esp+A4h] [ebp-3Ch] BYREF
  unsigned int v130; // [esp+B4h] [ebp-2Ch]
  unsigned int ii; // [esp+B8h] [ebp-28h]
  int v132; // [esp+BCh] [ebp-24h]
  unsigned int v133; // [esp+C0h] [ebp-20h]
  int v134; // [esp+C4h] [ebp-1Ch]
  int v135; // [esp+C8h] [ebp-18h]
  unsigned int v136; // [esp+CCh] [ebp-14h]
  unsigned int v137; // [esp+D0h] [ebp-10h]
  unsigned int m; // [esp+D4h] [ebp-Ch]
  unsigned int k; // [esp+D8h] [ebp-8h]
  unsigned int v140; // [esp+DCh] [ebp-4h]
  int v141; // [esp+FCh] [ebp+1Ch]
  __int64 v142; // [esp+FCh] [ebp+1Ch]
  int v143; // [esp+FCh] [ebp+1Ch]
  unsigned int i1; // [esp+FCh] [ebp+1Ch]
  __int64 v145; // [esp+FCh] [ebp+1Ch]
  int v146; // [esp+FCh] [ebp+1Ch]
  unsigned int mm; // [esp+100h] [ebp+20h]
  _DWORD *v148; // [esp+100h] [ebp+20h]
  int v149; // [esp+100h] [ebp+20h]
  _DWORD *v150; // [esp+100h] [ebp+20h]
  _DWORD *v151; // [esp+100h] [ebp+20h]
  _DWORD *v152; // [esp+100h] [ebp+20h]

  if ( !a3 )
    return 1;
  if ( a3 > 4 )
    return 0;
  for ( i = 1; i < a3; ++i )
  {
    if ( !sub_6854B0(this, *a2, a2[i]) )
      break;
  }
  if ( i == a3 )
    return 1;
  qmemcpy(v129, a2, 4 * ((4 * a3) >> 2));
  v130 = 4 * a3;
  memset(v123, 0, 4 * ((4 * a3) >> 2));
  if ( !a4 || (v10 = *a6 & 0xFFF00000, v134 = 0, v10 == 287309824) )
    v134 = 1;
  m = 0;
  v140 = 0;
  v11 = v129;
  v135 = (int)v129;
  do
  {
    for ( j = *v11; ; j = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v133) + 52) )
    {
      v133 = j;
      if ( sub_685446(this, j, (int)a6, a7, HIDWORD(a7)) )
      {
        n = 1.0;
        v13 = j;
        jj = 0.0;
        if ( j != -1 )
        {
          v14 = this[5];
          while ( 1 )
          {
            v15 = *(_DWORD *)(v14 + 4 * v13);
            if ( (*(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v15 + 4)) + 4) & 0x100) != 0
              && *(_DWORD *)(v15 + 8) == -1 )
            {
              break;
            }
            v13 = sub_685503(this, v13, &n, &jj);
            if ( v13 == -1 )
            {
              v11 = (int *)v135;
              goto LABEL_34;
            }
          }
          if ( 1.0 != n || 0.0 != jj )
          {
            v16 = *(_DWORD *)(v14 + 4 * v13);
            v13 = 0;
            v17 = this[2] == 0;
            v18 = n * *(double *)(v16 + 32) + jj;
            if ( this[2] )
            {
              v137 = v14;
              do
              {
                v19 = *(_DWORD *)v137;
                if ( (*(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)v137 + 4)) + 4) & 0x100) != 0
                  && *(_DWORD *)(v19 + 8) == -1
                  && v18 == *(double *)(v19 + 32) )
                {
                  break;
                }
                v137 += 4;
                ++v13;
              }
              while ( v13 < this[2] );
              v17 = v13 == this[2];
            }
            if ( v17 )
            {
              v13 = sub_681AAA(this, this[30], 0, 0, v18);
              if ( v13 == -1 )
                return 0;
            }
          }
          v11 = (int *)v135;
          v20 = 2 * v140;
          ++m;
          *(double *)&v119[v20 + 4] = 1.0;
          *(double *)&v119[v20 + 12] = 0.0;
          *v11 = v13;
          if ( v13 != -1 )
            break;
        }
      }
LABEL_34:
      if ( *v11 == *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v133) + 52) )
        break;
    }
    ++v140;
    v135 = (int)++v11;
  }
  while ( v140 < a3 );
  if ( m == a3 )
    goto LABEL_103;
  for ( k = 0; k < a3; ++k )
  {
    v17 = v123[k] == 0;
    v125 = &v123[k];
    if ( v17 )
    {
      v21 = this[4];
      v22 = v129[k];
      v124 = &v129[k];
      v23 = *(_DWORD *)(this[5] + 4 * v22);
      if ( (*(_BYTE *)(*(_DWORD *)(v21 + 4 * *(_DWORD *)(v23 + 4)) + 5) & 1) == 0 || *(_DWORD *)(v23 + 8) != -1 )
      {
        v136 = -1;
        v135 = 0;
        v133 = 0;
        for ( m = v22; ; m = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * m) + 52) )
        {
          if ( sub_685446(this, m, (int)a6, a7, HIDWORD(a7)) )
          {
            v24 = m;
            jj = 1.0;
            for ( n = 0.0; ; v24 = sub_685503(this, v132, &jj, &n) )
            {
              v132 = v24;
              if ( v24 == -1 )
                break;
              v17 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v132) + 72) == -1;
              v137 = 0;
              v140 = 0;
              if ( v17 )
                v140 = -1;
              for ( ii = 0; ii < a3; ++ii )
              {
                if ( !v123[ii] )
                {
                  v25 = v129[ii];
                  v128 = (int *)v25;
                  while ( 1 )
                  {
                    if ( sub_685446(this, v25, (int)a6, a7, HIDWORD(a7)) )
                    {
                      v26 = v25;
                      if ( v25 != -1 )
                      {
                        while ( !sub_6854B0(this, v132, v26) )
                        {
                          if ( v134 )
                          {
                            v26 = -1;
                            goto LABEL_59;
                          }
                          v26 = sub_685503(this, v26, 0, 0);
                          if ( v26 == -1 )
                            goto LABEL_60;
                        }
                        v27 = *(_DWORD *)(this[5] + 4 * v26);
                        ++v137;
                        if ( *(_DWORD *)(v27 + 72) != -1 )
                        {
                          v28 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v26) + 72) - a7;
                          v140 += v28 * v28;
                        }
LABEL_59:
                        if ( v26 != -1 )
                          break;
                      }
                    }
LABEL_60:
                    if ( v128 == *(int **)(*(_DWORD *)(this[5] + 4 * v25) + 52) )
                      break;
                    v25 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v25) + 52);
                  }
                }
              }
              if ( v135 < v137 || v135 == v137 && v133 < v140 )
              {
                v121 = jj;
                v135 = v137;
                v120 = n;
                v136 = v132;
                v133 = v140;
              }
              if ( v134 )
                break;
            }
          }
          if ( *v124 == *(_DWORD *)(*(_DWORD *)(this[5] + 4 * m) + 52) )
            break;
        }
        if ( v136 == -1 )
          return 0;
        v29 = v121;
        *v124 = v136;
        v30 = 2 * k;
        v140 = 0;
        *(double *)&v119[v30 + 4] = v29;
        *(double *)&v119[v30 + 12] = v120;
        *v125 = 1;
        do
        {
          v17 = v123[v140] == 0;
          v128 = &v123[v140];
          if ( v17 )
          {
            v31 = &v129[v140];
            v32 = *v31;
            do
            {
              m = v32;
              if ( sub_685446(this, v32, (int)a6, a7, HIDWORD(a7)) )
              {
                v33 = m;
                n = 1.0;
                for ( jj = 0.0; ; v33 = sub_685503(this, v33, &n, &jj) )
                {
                  if ( v33 == -1 )
                    goto LABEL_86;
                  if ( sub_6854B0(this, v136, v33) )
                    break;
                  if ( v134 )
                  {
                    v33 = -1;
LABEL_85:
                    if ( v33 != -1 )
                      goto LABEL_87;
                    goto LABEL_86;
                  }
                }
                v34 = 2 * v140;
                *(double *)&v119[v34 + 4] = n;
                *v31 = v33;
                *(double *)&v119[v34 + 12] = jj;
                *v128 = 1;
                goto LABEL_85;
              }
LABEL_86:
              v32 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * m) + 52);
            }
            while ( *v31 != v32 );
          }
LABEL_87:
          ++v140;
        }
        while ( v140 < a3 );
      }
    }
  }
  v35 = 0;
  v141 = 0;
  v137 = 0;
  v135 = 0;
  ii = 0;
  do
  {
    v36 = *(_DWORD *)(this[5] + 4 * v129[v35]);
    if ( !sub_6854B0(this, v129[v35], v129[0]) )
      v141 = 1;
    if ( 1.0 != *(double *)&v119[2 * v35 + 4] )
      v137 = 1;
    if ( 0.0 != *(double *)&v119[2 * v35 + 12] )
      v135 = 1;
    if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v36 + 4)) + 5) & 1) != 0 && *(_DWORD *)(v36 + 8) == -1 )
      ii = 1;
    ++v35;
  }
  while ( v35 < a3 );
  if ( !v137 && !v135 && !v141 )
  {
LABEL_103:
    qmemcpy(a2, v129, v130);
    return 1;
  }
  if ( v134 )
    return 0;
  v37 = (int)(this[27] << 29) >> 31;
  k = 0;
  m = v37;
  v142 = 0;
  do
  {
    v38 = *(_DWORD *)(this[5] + 4 * v129[k]);
    v39 = 0;
    if ( m || (this[27] & 2) != 0 )
    {
      v39 = k;
    }
    else
    {
      v40 = *(_DWORD *)(v38 + 4);
      if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v40) + 5) & 1) != 0 && *(_DWORD *)(v38 + 8) == -1 )
      {
        if ( (_DWORD)v142 )
        {
          do
          {
            v41 = *(_DWORD *)(this[5] + 4 * v129[v39]);
            if ( v40 == *(_DWORD *)(v41 + 4)
              && *(_DWORD *)(v41 + 8) == -1
              && *(double *)(v38 + 32) == *(double *)(v41 + 32) )
            {
              break;
            }
            ++v39;
          }
          while ( v39 < k );
        }
      }
      else if ( (_DWORD)v142 )
      {
        do
        {
          v42 = *(_DWORD **)(this[5] + 4 * v129[v39]);
          if ( *(double *)((char *)&v119[4] + v142) == *(double *)&v119[2 * v39 + 4]
            && *(double *)((char *)&v119[12] + v142) == *(double *)&v119[2 * v39 + 12]
            && v40 == v42[1]
            && *(_DWORD *)(v38 + 8) == v42[2]
            && *(_DWORD *)(v38 + 12) == v42[3]
            && *(_DWORD *)(v38 + 16) == v42[4] )
          {
            break;
          }
          ++v39;
        }
        while ( v39 < k );
      }
    }
    v43 = k;
    v17 = k == v39;
    v119[k] = v39;
    if ( v17 )
      ++HIDWORD(v142);
    LODWORD(v142) = v142 + 8;
    k = v43 + 1;
  }
  while ( v43 + 1 < a3 );
  v133 = -1;
  v44 = 0;
  v143 = 1;
  v140 = 0;
  k = 0;
  do
  {
    if ( v44 == v119[v44] )
    {
      v45 = *(_DWORD *)(this[5] + 4 * v129[v44]);
      v46 = this[34];
      if ( v46 == *(_DWORD *)(v45 + 4) )
      {
        v136 = HIDWORD(v142);
        for ( kk = 0; kk < a3; ++kk )
        {
          if ( kk == v119[kk] )
          {
            v48 = *(_DWORD *)(this[5] + 4 * v129[kk]);
            if ( v46 == *(_DWORD *)(v48 + 4)
              && *(_DWORD *)(v45 + 12) == *(_DWORD *)(v48 + 12)
              && 1.0 == *(double *)&v119[2 * kk + 4]
              && 0.0 == *(double *)&v119[2 * kk + 12] )
            {
              --v136;
            }
            v44 = k;
          }
        }
        if ( v136 + *(_DWORD *)(a4 + 4 * *(_DWORD *)(v45 + 12)) <= 4 && v136 < v133 )
        {
          v143 = 0;
          v133 = v136;
          v140 = v44;
        }
      }
    }
    k = ++v44;
  }
  while ( v44 < a3 );
  if ( m || (this[27] & 2) != 0 )
  {
    v49 = *a6 & 0xF0000000;
    if ( v49 >= 0x10000000 && v49 <= 0x40000000 )
    {
      for ( m = 0; m < a3; ++m )
      {
        if ( v143 )
          break;
        v50 = this[5];
        v51 = *(_DWORD **)(v50 + 4 * v129[m]);
        v52 = v51[1];
        if ( ((*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v52) + 5) & 1) == 0 || v51[2] == -1)
          && v51[4] != *(_DWORD *)(*(_DWORD *)(v50 + 4 * *(_DWORD *)(4 * m + a6[4])) + 16) )
        {
          v136 = 0;
          for ( mm = 0; mm < a3; ++mm )
          {
            v53 = *(_DWORD **)(v50 + 4 * v129[mm]);
            if ( v53[1] == v52 && v53[3] == v51[3] && v53[2] == v51[2] )
              ++v136;
          }
          if ( v136 > 1 )
            v143 = 1;
        }
      }
    }
  }
  v54 = *a6 & 0xFFF00000;
  if ( (v54 != 0x10000000
     || (this[27] & 8) != 0
     || (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)a6[4]) + 4)) + 4) & 0x20) == 0)
    && v54 == 0x10000000
    && !v137
    && !v135
    && !ii )
  {
    qmemcpy(a2, v129, v130);
    return 0;
  }
  v122 = -1;
  if ( v143 )
    v55 = (*a5)++;
  else
    v55 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v129[v140]) + 12);
  v56 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)a6[4]);
  v57 = *(_DWORD **)(v56 + 20);
  v58 = *(int **)(v56 + 24);
  v125 = v57;
  v124 = v58;
  memset(v123, 0, v130);
  v135 = v55;
  for ( nn = 0; nn < a3; ++nn )
  {
    if ( nn == v119[nn] )
    {
      v60 = *(_DWORD *)(this[5] + 4 * v129[nn]);
      if ( this[34] != *(_DWORD *)(v60 + 4)
        || v55 != *(_DWORD *)(v60 + 12)
        || 1.0 != *(double *)&v119[2 * nn + 4]
        || 0.0 != *(double *)&v119[2 * nn + 12] )
      {
        continue;
      }
    }
    v123[nn] = 1;
  }
  if ( !v143 )
  {
    v61 = 0;
    for ( k = 0; k < a3; ++k )
    {
      v62 = v61;
      if ( !v123[v62] )
      {
        v63 = v129[v62];
        v64 = *(_DWORD *)(this[5] + 4 * v63);
        if ( this[34] == *(_DWORD *)(v64 + 4) )
        {
          v137 = 0;
          v136 = 0;
          for ( i1 = 0; i1 < a3; ++i1 )
          {
            if ( !v123[i1] )
            {
              v118 = v129[i1];
              ++v137;
              if ( sub_6854B0(this, v63, v118) )
              {
                ++v136;
                if ( 1.0 != *(double *)&v119[2 * i1 + 4] || 0.0 != *(double *)&v119[2 * i1 + 12] )
                  break;
              }
            }
          }
          if ( i1 >= a3 )
          {
            v65 = *(_DWORD *)(v64 + 12);
            v148 = (_DWORD *)(a4 + 4 * v135);
            if ( v137 + *v148 + *(_DWORD *)(a4 + 4 * v65) - v136 <= 4 )
            {
              for ( i2 = 0; i2 < a3; ++i2 )
              {
                v67 = &v123[i2];
                if ( !*v67 )
                {
                  v68 = *(_DWORD *)(this[5] + 4 * v129[i2]);
                  if ( this[34] == *(_DWORD *)(v68 + 4) && v65 == *(_DWORD *)(v68 + 12) )
                    *v67 = 1;
                }
              }
              for ( i3 = 0; i3 < this[2]; ++i3 )
              {
                v70 = *(_DWORD **)(this[5] + 4 * i3);
                if ( this[34] == v70[1] && v65 == v70[3] )
                {
                  v70[3] = v135;
                  v70[4] += *v148;
                }
              }
              v71 = (_DWORD *)(a4 + 4 * v65);
              *v148 += *v71;
              *v71 = 0;
            }
          }
        }
      }
      v61 = k + 1;
    }
  }
  if ( (this[27] & 6) == 0 )
  {
    v72 = 0;
    for ( k = 0; k < a3; ++k )
    {
      v73 = v72;
      if ( !v123[v73] )
      {
        v74 = &v129[v73];
        v75 = v129[v73];
        v76 = *(_DWORD *)(this[5] + 4 * v75);
        if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v76 + 4)) + 5) & 1) == 0 || *(_DWORD *)(v76 + 8) != -1 )
        {
          v145 = 0;
          do
          {
            if ( !v123[HIDWORD(v145)] && sub_6854B0(this, v75, v129[HIDWORD(v145)]) )
              LODWORD(v145) = v145 + 1;
            ++HIDWORD(v145);
          }
          while ( HIDWORD(v145) < a3 );
          HIDWORD(v145) = 0;
          do
          {
            if ( (unsigned int)v145 >= 4 )
              break;
            if ( !v123[HIDWORD(v145)] )
            {
              v77 = &v129[HIDWORD(v145)];
              v78 = *(_DWORD *)(this[5] + 4 * *v77);
              if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v78 + 4)) + 5) & 1) != 0
                && *(_DWORD *)(v78 + 8) == -1 )
              {
                v79 = *(double *)(v78 + 32);
                *v77 = *v74;
                LODWORD(v145) = v145 + 1;
                v80 = (double *)&v119[2 * HIDWORD(v145) + 4];
                *(double *)&v119[2 * HIDWORD(v145) + 12] = v79 * *v80 + *(double *)&v119[2 * HIDWORD(v145) + 12];
                *v80 = 0.0;
              }
            }
            ++HIDWORD(v145);
          }
          while ( HIDWORD(v145) < a3 );
        }
      }
      v72 = k + 1;
    }
  }
  for ( k = 0; k < a3; ++k )
  {
    v81 = 0;
    if ( !v123[k] )
    {
      v82 = v129[k];
      HIDWORD(v120) = v82;
      v149 = 0;
      v132 = 0;
      v136 = 1;
      v134 = 0;
      v130 = 1;
      do
      {
        if ( !v123[v81] && sub_6854B0(this, v82, v129[v81]) )
        {
          ++v149;
          v83 = (double *)&v119[2 * v81 + 4];
          if ( 1.0 != *v83 )
            v132 = 1;
          if ( -1.0 != *v83 )
            v136 = 0;
          if ( 0.0 != *(double *)&v119[2 * v81 + 12] )
            v134 = 1;
          if ( 0.0 != *v83 )
            v130 = 0;
        }
        ++v81;
      }
      while ( v81 < a3 );
      if ( v130 )
      {
        v132 = 0;
        v134 = 0;
      }
      if ( v132 )
      {
        if ( v136 )
          v84 = v149 & 0xFFFFF | 0x10100000;
        else
          v84 = v149 & 0xFFFFF | 0x20500000;
        v85 = sub_681B0A(this, v84, -1, -1);
        m = v85;
        if ( v85 == -1 )
          return 0;
        ii = *(_DWORD *)(this[6] + 4 * v85);
        v86 = (_DWORD *)ii;
        sub_680D22((_DWORD *)ii, (int)a6);
        if ( v134 )
        {
LABEL_250:
          v87 = sub_681B0A(this, v149 & 0xFFFFF | 0x20400000, -1, -1);
          v133 = v87;
          if ( v87 == -1 )
            return 0;
          v140 = *(_DWORD *)(this[6] + 4 * v87);
          v88 = (_DWORD *)v140;
          sub_680D22((_DWORD *)v140, (int)a6);
          if ( v132 )
          {
LABEL_257:
            v137 = 4 * v149;
            v90 = 0;
            v146 = 0;
            HIDWORD(jj) = (char *)a2 - (char *)v129;
            while ( 1 )
            {
              v17 = v123[v146] == 0;
              HIDWORD(n) = &v123[v146];
              if ( v17 )
              {
                v91 = v129[v146];
                v128 = &v129[v146];
                if ( sub_6854B0(this, SHIDWORD(v120), v91) )
                  break;
              }
LABEL_292:
              if ( ++v146 >= a3 )
                goto LABEL_293;
            }
            if ( v130 )
              v92 = sub_681AAA(this, this[30], 0, 0, *(double *)&v119[2 * v146 + 12]);
            else
              v92 = v91;
            if ( v92 == -1 )
              return 0;
            v93 = ii;
            v94 = *(_DWORD *)(this[5] + 4 * v92);
            *(_DWORD *)(v90 + *(_DWORD *)(ii + 8)) = v92;
            HIDWORD(v121) = v94;
            if ( v130 )
              *(_DWORD *)(v94 + 52) = v92;
            if ( v132 )
            {
              if ( !v136 )
              {
                v95 = sub_681AAA(this, this[30], 0, 0, *(double *)&v119[2 * v146 + 4]);
                v96 = v137;
                *(_DWORD *)(v137 + *(_DWORD *)(v93 + 8)) = v95;
                if ( *(_DWORD *)(v96 + *(_DWORD *)(v93 + 8)) == -1 )
                  return 0;
              }
              if ( !v134 )
                goto LABEL_288;
              v97 = v122;
              if ( v122 == -1 )
              {
                v97 = *a5;
                v98 = *a5 + 1;
                v122 = *a5;
                *a5 = v98;
              }
              v99 = (_DWORD *)(a4 + 4 * v97);
              v116 = (*v99)++;
              v150 = v99;
              v100 = sub_681AAA(this, this[34], v97, v116, 0.0);
              if ( v100 == -1 )
                return 0;
              if ( *v150 > 4u )
                sub_686791((int)this, 0, 0, "internal error: component out of range");
              v101 = *(int **)(this[5] + 4 * v100);
              v101[5] = (int)v125;
              v101[6] = (int)v124;
              *v101 = *(_DWORD *)HIDWORD(v121) & 0xE000000;
              v101[18] = m;
              *(_DWORD *)(v90 + *(_DWORD *)(v140 + 8)) = v100;
              *(_DWORD *)(v90 + *(_DWORD *)(ii + 16)) = v100;
            }
            v102 = 0;
            if ( v134 )
            {
              v103 = this[2] == 0;
              if ( this[2] )
              {
                v104 = (int *)this[5];
                do
                {
                  v105 = *v104;
                  if ( this[30] == *(_DWORD *)(*v104 + 4)
                    && *(_DWORD *)(v105 + 8) == -1
                    && *(double *)(v105 + 32) == *(double *)&v119[2 * v146 + 12] )
                  {
                    break;
                  }
                  ++v102;
                  ++v104;
                }
                while ( v102 < this[2] );
                v103 = v102 == this[2];
              }
              if ( v103 )
              {
                v106 = sub_681AAA(this, this[30], 0, 0, *(double *)&v119[2 * v146 + 12]);
                v102 = v106;
                if ( v106 == -1 )
                  return 0;
                *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v106) + 52) = v106;
              }
              *(_DWORD *)(v137 + *(_DWORD *)(v140 + 8)) = v102;
            }
LABEL_288:
            v107 = v135;
            v108 = (_DWORD *)(a4 + 4 * v135);
            v117 = (*v108)++;
            v151 = v108;
            v109 = sub_681AAA(this, this[34], v107, v117, 0.0);
            if ( v109 == -1 )
              return 0;
            if ( *v151 > 4u )
              sub_686791((int)this, 0, 0, "internal error: component out of range");
            v110 = *(_DWORD **)(this[5] + 4 * v109);
            v111 = v128;
            v110[5] = v125;
            v110[6] = v124;
            v152 = (int *)((char *)v111 + HIDWORD(jj));
            *v110 = **(_DWORD **)(this[5] + 4 * *(int *)((char *)v111 + HIDWORD(jj)));
            v110[18] = v133;
            *(_DWORD *)(v90 + *(_DWORD *)(v140 + 16)) = v109;
            *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v109) + 52) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v152) + 52);
            v112 = v128;
            *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v152) + 52) = v109;
            *v112 = *(_DWORD *)(v90 + *(_DWORD *)(v140 + 16));
            v90 += 4;
            v137 += 4;
            *(_DWORD *)HIDWORD(n) = 1;
            goto LABEL_292;
          }
          m = v87;
          ii = (unsigned int)v88;
LABEL_253:
          if ( !v132 && !v134 )
          {
            v89 = sub_681B0A(this, v149 & 0xFFFFF | 0x10000000, -1, -1);
            v133 = v89;
            m = v89;
            if ( v89 == -1 )
              return 0;
            v140 = *(_DWORD *)(this[6] + 4 * v89);
            ii = v140;
            sub_680D22((_DWORD *)v140, (int)a6);
          }
          goto LABEL_257;
        }
        v133 = v85;
        v140 = (unsigned int)v86;
      }
      if ( !v134 )
        goto LABEL_253;
      goto LABEL_250;
    }
LABEL_293:
    ;
  }
  v113 = a2;
  v114 = a3;
  do
  {
    *v113 = v129[*(int *)((char *)v113 + (char *)v119 - (char *)a2)];
    ++v113;
    --v114;
  }
  while ( v114 );
  v115 = 0;
  while ( v123[v115] )
  {
    if ( ++v115 >= a3 )
      return 1;
  }
  return 0;
}
