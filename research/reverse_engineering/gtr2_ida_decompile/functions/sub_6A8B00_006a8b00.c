int __thiscall sub_6A8B00(_DWORD *this, int a2, int a3)
{
  unsigned int i; // ecx
  int v5; // eax
  bool v6; // zf
  int v7; // esi
  _DWORD *v8; // eax
  unsigned int v9; // ecx
  int v10; // ecx
  int v11; // edx
  _DWORD *v12; // eax
  int result; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // edi
  int v17; // eax
  unsigned int v18; // eax
  unsigned int *v19; // ecx
  int *v20; // edi
  int v21; // eax
  int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // edx
  unsigned int v25; // ecx
  bool v26; // cf
  unsigned int v27; // eax
  int v28; // eax
  unsigned int v29; // ecx
  int v30; // edi
  unsigned int v31; // eax
  unsigned int v32; // edx
  int v33; // ecx
  int v34; // eax
  unsigned int v35; // eax
  int v36; // eax
  int v37; // edi
  unsigned int v38; // eax
  int v39; // ecx
  int v40; // ecx
  _DWORD *v41; // esi
  unsigned int v42; // eax
  _DWORD *v43; // eax
  unsigned int v44; // ecx
  int v45; // eax
  int *v46; // edx
  int v47; // eax
  int *v48; // ecx
  int v49; // ecx
  _DWORD *v50; // edx
  _DWORD *v51; // edi
  int v52; // eax
  int v53; // edx
  int v54; // ecx
  _DWORD *v55; // esi
  int v56; // eax
  int v57; // eax
  int v58; // ecx
  unsigned int v59; // esi
  int v60; // eax
  unsigned int v61; // eax
  _DWORD *v62; // eax
  _DWORD *v63; // eax
  int v64; // ecx
  int v65; // edi
  int v66; // edx
  int v67; // ecx
  unsigned int v68; // edi
  unsigned int v69; // eax
  unsigned int v70; // edi
  int *v71; // eax
  int v72; // ecx
  int v73; // edx
  int v74; // ecx
  _DWORD *v75; // eax
  int *v76; // eax
  int v77; // ecx
  int v78; // esi
  unsigned int v79; // edx
  unsigned int k; // edi
  unsigned int *v81; // esi
  int v82; // esi
  bool v83; // cc
  _DWORD *v84; // eax
  int v85; // edx
  int v86; // eax
  unsigned int v87; // ecx
  const void *v88; // esi
  _DWORD *v89; // eax
  int v90; // edi
  unsigned int v91; // ecx
  _DWORD *v92; // esi
  int v93; // eax
  int v94; // eax
  _DWORD *v95; // eax
  unsigned int v96; // eax
  int *v97; // esi
  int v98; // eax
  unsigned int v99; // ecx
  unsigned int v100; // eax
  unsigned int v101; // edi
  int v102; // eax
  _DWORD *v103; // edx
  _DWORD *v104; // edx
  _DWORD *v105; // eax
  int v106; // eax
  unsigned int v107; // edi
  int v108; // eax
  _DWORD *v109; // edx
  int v110; // edx
  unsigned int *v111; // eax
  int v112; // eax
  unsigned int *v113; // edx
  unsigned int *v114; // eax
  int v115; // esi
  unsigned int v116; // eax
  unsigned int v117; // eax
  int v118; // edx
  _DWORD *v119; // edi
  unsigned int v120; // edx
  unsigned int v121; // edx
  int v122; // esi
  int v123; // esi
  unsigned int v124; // eax
  unsigned int v125; // edi
  int v126; // ecx
  int v127; // eax
  int v128; // esi
  unsigned int v129; // eax
  unsigned int v130; // eax
  int v131; // edx
  int v132; // eax
  unsigned int *v133; // eax
  int v134; // eax
  int v135; // [esp-14h] [ebp-290h]
  unsigned int v136; // [esp-Ch] [ebp-288h]
  unsigned int v137; // [esp-Ch] [ebp-288h]
  int v138; // [esp-8h] [ebp-284h]
  unsigned int v139; // [esp-8h] [ebp-284h]
  int v140; // [esp-8h] [ebp-284h]
  int v141; // [esp-8h] [ebp-284h]
  unsigned int v142; // [esp-4h] [ebp-280h]
  unsigned int v143; // [esp-4h] [ebp-280h]
  int v144; // [esp-4h] [ebp-280h]
  unsigned int v145; // [esp-4h] [ebp-280h]
  int v146; // [esp-4h] [ebp-280h]
  _DWORD v147[32]; // [esp+14h] [ebp-268h] BYREF
  _DWORD v148[32]; // [esp+94h] [ebp-1E8h] BYREF
  _DWORD v149[8]; // [esp+114h] [ebp-168h] BYREF
  _DWORD v150[30]; // [esp+134h] [ebp-148h] BYREF
  _DWORD v151[24]; // [esp+1ACh] [ebp-D0h] BYREF
  _DWORD v152[6]; // [esp+20Ch] [ebp-70h] BYREF
  _DWORD v153[6]; // [esp+224h] [ebp-58h] BYREF
  int v154; // [esp+23Ch] [ebp-40h] BYREF
  unsigned int v155; // [esp+240h] [ebp-3Ch] BYREF
  unsigned int v156; // [esp+244h] [ebp-38h]
  unsigned int v157; // [esp+248h] [ebp-34h]
  int v158; // [esp+24Ch] [ebp-30h]
  unsigned int v159; // [esp+250h] [ebp-2Ch]
  unsigned int v160; // [esp+254h] [ebp-28h] BYREF
  unsigned int v161; // [esp+258h] [ebp-24h] BYREF
  int v162; // [esp+25Ch] [ebp-20h] BYREF
  unsigned int v163; // [esp+260h] [ebp-1Ch] BYREF
  unsigned int v164; // [esp+264h] [ebp-18h] BYREF
  unsigned int v165; // [esp+268h] [ebp-14h]
  unsigned int v166; // [esp+26Ch] [ebp-10h]
  unsigned int v167; // [esp+270h] [ebp-Ch]
  unsigned int j; // [esp+274h] [ebp-8h] BYREF
  unsigned int v169; // [esp+278h] [ebp-4h]

  memset(v150, 0, 0x60u);
  memset(v152, 0, sizeof(v152));
  memset(v151, 0, sizeof(v151));
  memset(v153, 0, sizeof(v153));
  for ( i = 0; i < this[2]; ++i )
  {
    v5 = *(_DWORD *)(this[5] + 4 * i);
    if ( *(_DWORD *)(v5 + 4) == this[34] )
      *(_DWORD *)(v5 + 12) = -1;
  }
  if ( this[139] )
  {
    v6 = this[136] == 0;
    v166 = 0;
    if ( !v6 )
    {
      v7 = 0;
      do
      {
        v8 = *(_DWORD **)(v7 + this[139]);
        if ( !v8 )
          goto LABEL_78;
        v9 = *v8 & 0xFFF00000;
        if ( !v9 || v9 == 285212672 )
          goto LABEL_78;
        if ( v9 != 1610612736 && v9 != 1615855616 && v9 != 1621098496 && v9 != 1626341376 && v9 != 1913651200 )
        {
          v10 = v8[3];
          v163 = 0;
          j = 0;
          if ( v10 )
          {
            v11 = this[5];
            v12 = (_DWORD *)v8[4];
            do
            {
              if ( *(_DWORD *)(*(_DWORD *)(v11 + 4 * *v12) + 12) == -1 )
                v163 = 1;
              else
                j = 1;
              ++v12;
              --v10;
            }
            while ( v10 );
            if ( j )
            {
              if ( !v163 )
                goto LABEL_78;
              sub_686791((int)this, 0, 4808, "internal error: unvectorized register found");
              return -2147467259;
            }
          }
          v14 = this[139];
          v15 = *(_DWORD *)(v14 + v7);
          v162 = 0;
          v142 = *(_DWORD *)(v15 + 12);
          v138 = *(_DWORD *)(v15 + 16);
          v156 = v166 + 1;
          sub_6A7CF3(this, v14, v166 + 1, this[136], v138, v142, (int)v147, (unsigned int *)&v162);
          v16 = 0;
          sub_6A7CF3(
            this,
            this[140],
            0,
            this[137],
            *(_DWORD *)(*(_DWORD *)(v7 + this[139]) + 16),
            *(_DWORD *)(*(_DWORD *)(v7 + this[139]) + 12),
            (int)v147,
            (unsigned int *)&v162);
          v17 = *(_DWORD *)(v7 + this[139]);
          if ( *(_DWORD *)(v17 + 12) == 1 )
          {
            v16 = *(_DWORD *)(this[5] + 4 * **(_DWORD **)(v17 + 16));
            if ( *(_DWORD *)(v16 + 16) != 4 )
              v16 = 0;
          }
          v167 = 0;
          j = (unsigned int)v150;
          while ( 1 )
          {
            result = sub_6A84FA(
                       this,
                       v167,
                       this[140],
                       this[137],
                       *(_DWORD *)(*(_DWORD *)(v7 + this[139]) + 16),
                       *(_DWORD *)(*(_DWORD *)(v7 + this[139]) + 12));
            if ( result < 0 )
              return result;
            if ( result != 1 )
            {
              v18 = 0;
              if ( v16 )
              {
                v19 = (unsigned int *)j;
                while ( *v19 > v166 )
                {
                  ++v18;
                  ++v19;
                  if ( v18 >= 3 )
                    goto LABEL_38;
                }
                v159 = v18;
LABEL_38:
                if ( v18 != 3 )
                {
LABEL_42:
                  if ( v16 )
                    *(_DWORD *)(v16 + 16) = v159;
LABEL_44:
                  if ( v167 != 6 )
                  {
                    v165 = 0;
                    v161 = 0;
                    v169 = 0;
                    if ( v162 )
                    {
                      v157 = v167;
                      do
                      {
                        v20 = &v147[v169];
                        v21 = *v20;
                        v22 = *(_DWORD *)(this[5] + 4 * *v20);
                        *(_DWORD *)(v22 + 12) = v167;
                        v139 = this[136];
                        j = v22;
                        v163 = sub_6A6403(this, this[139], v156, v139, v21, v22, &v164);
                        v23 = sub_6A6403(this, this[140], 0, this[137], *v20, j, &v164);
                        if ( v23 > v161 )
                          v161 = v23;
                        if ( v23 >= this[19] && *(_DWORD *)(j + 16) == 3 )
                          v150[v167 + 24] = 1;
                        if ( v164 )
                          v150[v167 + 24] = 1;
                        if ( v161 || v164 )
                          v24 = -1;
                        else
                          v24 = v163;
                        if ( v24 > v165 )
                          v165 = v24;
                        v25 = 4 * v167 + *(_DWORD *)(j + 16);
                        ++v169;
                        v151[v25] = v23;
                        v26 = v169 < v162;
                        v150[v25] = v24;
                      }
                      while ( v26 );
                    }
                    v27 = v167;
                    v152[v27] = v165;
                    v153[v27] = v161;
                    sub_6A7E52(this);
                    goto LABEL_78;
                  }
                  if ( !a2 && !a3 )
                  {
                    v56 = this[139];
                    goto LABEL_121;
                  }
                  return -2147467259;
                }
              }
              else if ( v152[v167] <= v166 )
              {
                goto LABEL_44;
              }
            }
            ++v167;
            j += 16;
            if ( v167 >= 6 )
              goto LABEL_42;
          }
        }
        v28 = *(_DWORD *)(v7 + this[139]);
        v143 = *(_DWORD *)(v28 + 12);
        v140 = *(_DWORD *)(v28 + 16);
        v136 = this[137];
        v161 = 0;
        v135 = this[140];
        v165 = 0;
        j = 0;
        sub_6A7CF3(this, v135, 0, v136, v140, v143, (int)v148, &j);
        v6 = *(_DWORD *)(*(_DWORD *)(this[139] + v7) + 12) == 0;
        v169 = 0;
        if ( !v6 )
        {
          v157 = v166;
          do
          {
            v29 = v169;
            v30 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this[139] + v7) + 16) + 4 * v169));
            *(_DWORD *)(v30 + 12) = v166;
            v163 = sub_6A6403(
                     this,
                     this[139],
                     v166 + 1,
                     this[136],
                     *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this[139] + v7) + 16) + 4 * v29),
                     v30,
                     &v164);
            v31 = sub_6A6403(
                    this,
                    this[140],
                    0,
                    this[137],
                    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this[139] + v7) + 16) + 4 * v169),
                    v30,
                    &v164);
            if ( v31 > v161 )
              v161 = v31;
            if ( v164 )
              v32 = -1;
            else
              v32 = v163;
            if ( v32 > v165 )
              v165 = v32;
            v33 = v7 + *(_DWORD *)(v30 + 16);
            ++v169;
            v151[v33] = v31;
            v34 = *(_DWORD *)(this[139] + v7);
            v150[v33] = v32;
          }
          while ( v169 < *(_DWORD *)(v34 + 12) );
        }
        v169 = 0;
        v35 = v157;
        v6 = j == 0;
        v152[v35] = v165;
        v153[v35] = v161;
        if ( !v6 )
        {
          v157 = v166;
          do
          {
            v36 = v148[v169];
            v37 = *(_DWORD *)(this[5] + 4 * v36);
            *(_DWORD *)(v37 + 12) = v166;
            v38 = sub_6A6403(this, this[140], 0, this[137], v36, v37, &v164);
            if ( v38 > v161 )
              v161 = v38;
            v39 = v7 + *(_DWORD *)(v37 + 16);
            ++v169;
            v151[v39] = v38;
          }
          while ( v169 < j );
        }
        v153[v157] = v161;
LABEL_78:
        ++v166;
        v7 += 4;
      }
      while ( v166 < this[136] );
    }
  }
  if ( !this[140] || (v6 = this[137] == 0, v166 = 0, v6) )
  {
LABEL_263:
    if ( !this[139] )
      return 0;
    if ( (unsigned __int16)this[50] != 260 )
      return 0;
    if ( a2 )
      return 0;
    result = sub_6A8A82(this);
    if ( result >= 0 )
      return 0;
    return result;
  }
  while ( 1 )
  {
    v40 = 4 * v166;
    v41 = *(_DWORD **)(4 * v166 + this[140]);
    v159 = 4 * v166;
    if ( v41 )
    {
      v42 = *v41 & 0xFFF00000;
      if ( v42 )
      {
        if ( v42 != 285212672 )
        {
          if ( v42 == 1610612736
            || v42 == 1615855616
            || v42 == 1621098496
            || v42 == 1626341376
            || v42 == 1915748352
            || v42 == 1917845504
            || v42 == 1913651200
            || v42 == 1918894080
            || v42 == 1919942656
            || v42 == 1920991232
            || v42 == 1923088384
            || v42 == 1922039808
            || v42 == 1924136960 )
          {
            v120 = 0;
            v6 = v41[3] == 0;
            v167 = 0;
            v169 = 0;
            if ( !v6 )
            {
              v121 = v166;
              do
              {
                v122 = v41[4];
                v155 = 4 * v169;
                v123 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(4 * v169 + v122));
                if ( (unsigned __int16)this[50] == 260 )
                {
                  *(_DWORD *)(v123 + 12) = v121;
                  v157 = v121;
                }
                else
                {
                  *(_DWORD *)(v123 + 12) = v121 + 2;
                  v157 = v121 + 2;
                }
                v124 = sub_6A6403(
                         this,
                         this[140],
                         v121 + 1,
                         this[137],
                         *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v40 + this[140]) + 16) + v155),
                         v123,
                         &v164);
                if ( v124 > v167 )
                  v167 = v124;
                v125 = v157;
                v126 = this[140];
                v151[4 * v157 + *(_DWORD *)(v123 + 16)] = v124;
                v127 = *(_DWORD *)(v159 + v126);
                v145 = *(_DWORD *)(v127 + 12);
                v141 = *(_DWORD *)(v127 + 16);
                v137 = this[137];
                v163 = 0;
                sub_6A7CF3(this, v126, v166 + 1, v137, v141, v145, (int)v148, &v163);
                for ( j = 0; j < v163; v151[v131] = v130 )
                {
                  v128 = *(_DWORD *)(this[5] + 4 * v148[j]);
                  v146 = v148[j];
                  v129 = v166;
                  *(_DWORD *)(v128 + 12) = v125;
                  v130 = sub_6A6403(this, this[140], v129 + 1, this[137], v146, v128, &v164);
                  if ( v130 > v167 )
                    v167 = v130;
                  v131 = 4 * v125 + *(_DWORD *)(v128 + 16);
                  ++j;
                }
                sub_6A7E52(this);
                v121 = v166;
                v132 = this[140];
                ++v169;
                v40 = 4 * v166;
                v41 = *(_DWORD **)(4 * v166 + v132);
                v26 = v169 < v41[3];
                v159 = 4 * v166;
              }
              while ( v26 );
              v120 = v167;
            }
            v133 = &v153[v157];
            if ( *v133 < v120 )
              *v133 = v120;
            goto LABEL_262;
          }
          if ( v42 != 1914699776 && v42 != 1916796928 )
            break;
        }
      }
    }
LABEL_262:
    if ( ++v166 >= this[137] )
      goto LABEL_263;
  }
  if ( (unsigned __int16)this[50] == 257 )
  {
    v43 = *(_DWORD **)(v40 + this[140]);
    v44 = *v43 & 0xFFFFF;
    v45 = v43[1] / v44;
    v163 = 0;
    v160 = 0;
    v159 = v45;
    if ( v45 )
    {
      v46 = (int *)v41[2];
      v47 = this[5];
      v158 = 4 * v44;
      v48 = v46;
      v165 = (unsigned int)v46;
      do
      {
        v49 = *v48;
        v162 = 0;
        v50 = *(_DWORD **)(v47 + 4 * v49);
        if ( v160 )
        {
          j = v41[2];
          do
          {
            v51 = *(_DWORD **)(v47 + 4 * *(_DWORD *)j);
            if ( v50[1] == v51[1] && v50[2] == v51[2] && v50[3] == v51[3] )
              break;
            ++v162;
            j += v158;
          }
          while ( v162 < v160 );
        }
        if ( v160 == v162 && v50[1] == this[34] && v50[3] >= 2u )
          ++v163;
        v48 = (int *)(v158 + v165);
        ++v160;
        v165 += v158;
      }
      while ( v160 < v159 );
      if ( v163 > 2 )
      {
        if ( a2 || a3 )
          return -2147467259;
        v56 = this[140];
LABEL_121:
        v57 = *(_DWORD *)(v56 + 4 * v166);
        goto LABEL_279;
      }
    }
  }
  v52 = v41[3];
  v53 = 0;
  j = 0;
  if ( v52 )
  {
    v54 = this[5];
    v55 = (_DWORD *)v41[4];
    do
    {
      if ( *(_DWORD *)(*(_DWORD *)(v54 + 4 * *v55) + 12) == -1 )
        j = 1;
      else
        v53 = 1;
      ++v55;
      --v52;
    }
    while ( v52 );
    if ( v53 )
    {
      if ( j )
      {
        sub_686791((int)this, 0, 4809, "internal error: unvectorized register found");
        return -2147467259;
      }
      goto LABEL_262;
    }
  }
  v58 = this[140];
  v59 = v166;
  v60 = *(_DWORD *)(v58 + 4 * v166);
  v160 = 0;
  sub_6A7CF3(this, v58, v166 + 1, this[137], *(_DWORD *)(v60 + 16), *(_DWORD *)(v60 + 12), (int)v149, &v160);
  v61 = this[50];
  v164 = -1;
  v167 = -1;
  v61 = (unsigned __int16)v61;
  v169 = v61;
  if ( (unsigned __int16)v61 == 258 || (unsigned __int16)v61 == 259 )
  {
    v62 = *(_DWORD **)(this[140] + 4 * v59);
    if ( *v62 == 1342177284 )
    {
      v63 = (_DWORD *)v62[2];
      v64 = this[5];
      v65 = *(_DWORD *)(v64 + 4 * *v63);
      v66 = this[34];
      if ( *(_DWORD *)(v65 + 4) == v66 )
        v164 = *(_DWORD *)(v65 + 12);
      v67 = *(_DWORD *)(v64 + 4 * v63[4]);
      if ( *(_DWORD *)(v67 + 4) == v66 )
        v167 = *(_DWORD *)(v67 + 12);
    }
  }
  v158 = 0;
  v162 = 0;
  if ( v160 )
  {
    do
    {
      v68 = this[137];
      v69 = v59 + 1;
      if ( v59 + 1 < v68 )
      {
        j = this[140] + 4 * v69;
        v70 = v68 - v69;
        do
        {
          v71 = *(int **)j;
          if ( *(_DWORD *)j )
          {
            v72 = *v71;
            if ( (*v71 & 0xFFF00000) == 0x70F00000 )
            {
              v73 = v72 & 0xFFFFF;
              if ( (v72 & 0xFFFFF) != 0 )
              {
                v74 = v149[v162];
                v75 = (_DWORD *)v71[2];
                v163 = v73;
                do
                {
                  if ( *v75 == v74 )
                    v158 = 1;
                  ++v75;
                  --v163;
                }
                while ( v163 );
              }
            }
          }
          j += 4;
          --v70;
        }
        while ( v70 );
      }
      ++v162;
    }
    while ( v162 < v160 );
    if ( v158 )
      goto LABEL_148;
  }
  v6 = this[275] == 0;
  v165 = 1;
  if ( v6 )
LABEL_148:
    v165 = 0;
  v76 = *(int **)(4 * v59 + this[140]);
  v77 = *v76;
  v78 = *v76 & 0xFFFFF;
  v159 = (unsigned int)v76;
  if ( v78 != 1
    || (v77 & 0xFFF00000) == 0x50000000
    || v160 != 1
    || *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v149[0]) + 16) != 3
    || !v165 )
  {
    v79 = v166;
    goto LABEL_161;
  }
  v79 = v166;
  k = 1;
  v162 = 1;
  v81 = &v151[7];
  do
  {
    if ( v153[k] > v166 && *v81 <= v166 )
      break;
    ++k;
    v81 += 4;
    v162 = k;
  }
  while ( k < 6 );
  if ( k == 6 )
  {
LABEL_161:
    for ( k = v165 != 0; ; ++k )
    {
      v162 = k;
      if ( k >= 6 || v153[k] <= v79 && k != v164 && k != v167 )
        break;
    }
    v76 = (int *)v159;
  }
  if ( k && !v165 && this[275] )
  {
    if ( a2 || a3 )
      return -2147467259;
    v134 = this[139];
LABEL_278:
    v57 = *(_DWORD *)(v134 + 4 * v79);
LABEL_279:
    sub_686791((int)this, *(_DWORD *)(v57 + 60), 4521, "program too complex: out of temporary registers");
    return -2147467259;
  }
  if ( k == 6 )
  {
    if ( (unsigned __int16)this[50] == 260 && a3 )
      return -2147467259;
    v134 = this[140];
    goto LABEL_278;
  }
  v156 = 0;
  if ( (v77 & 0xFFF00000) != 0x50000000 || v169 >= 0x104 || v76[3] != 1 )
  {
LABEL_238:
    v167 = 0;
    if ( v160 )
    {
      v169 = 0;
      do
      {
        v115 = *(_DWORD *)(this[5] + 4 * v149[v169]);
        v144 = v149[v169];
        v116 = v166;
        *(_DWORD *)(v115 + 12) = k;
        v117 = sub_6A6403(this, this[140], v116 + 1, this[137], v144, v115, &v164);
        if ( v117 > v167 )
          v167 = v117;
        v118 = 4 * k + *(_DWORD *)(v115 + 16);
        ++v169;
        v151[v118] = v117;
      }
      while ( v169 < v160 );
      v119 = &v153[k];
      if ( *v119 < v167 )
        *v119 = v167;
      sub_6A7E52(this);
    }
    else
    {
      **(_DWORD **)(4 * v166 + this[140]) = 0;
    }
    goto LABEL_262;
  }
  v82 = 4 * v166;
  sub_6A7E91(
    this,
    this[140],
    v166 + 1,
    this[137],
    *(_DWORD **)(*(_DWORD *)(4 * v166 + this[140]) + 16),
    *(_DWORD *)(*(_DWORD *)(4 * v166 + this[140]) + 12),
    &v161,
    &v154,
    &v155);
  if ( v154 )
    v161 = 4;
  v83 = v161 <= 4;
  if ( v161 < 4 )
  {
    v161 = 3;
    v83 = 1;
  }
  if ( !v83 )
    v161 = 4;
  v84 = (_DWORD *)sub_681186(116);
  if ( v84 )
    v169 = (unsigned int)sub_680CEC(v84);
  else
    v169 = 0;
  if ( !v169 )
    return -2147024882;
  result = sub_6811D1(
             (char *)v169,
             **(_DWORD **)(v82 + this[140]),
             *(_DWORD *)(*(_DWORD *)(v82 + this[140]) + 4),
             v161,
             0);
  if ( result >= 0 )
  {
    result = sub_680D22((_DWORD *)v169, *(_DWORD *)(v82 + this[140]));
    if ( result >= 0 )
    {
      v85 = 4 * v166;
      qmemcpy(*(void **)(v169 + 8), *(const void **)(*(_DWORD *)(4 * v166 + this[140]) + 8), 4 * *(_DWORD *)(v169 + 4));
      v86 = *(_DWORD *)(v85 + this[140]);
      v87 = *(_DWORD *)(v86 + 12);
      v88 = *(const void **)(v86 + 16);
      v89 = (_DWORD *)v169;
      v159 = v87;
      qmemcpy(&v152[2], v88, 4 * v87);
      *(_DWORD *)(v85 + this[140]) = v89;
      result = sub_681997((int)this, v89);
      if ( result >= 0 )
      {
        v90 = 0;
        v91 = 0;
        v167 = 0;
        for ( j = 0; j < v159; ++j )
        {
          v6 = this[2] == 0;
          v165 = 0;
          if ( !v6 )
          {
            do
            {
              v92 = *(_DWORD **)(this[5] + 4 * v165);
              v93 = v152[j + 2];
              if ( v165 == v93 || v92[14] == v93 )
              {
                if ( v161 )
                {
                  do
                  {
                    v94 = sub_681AAA(this, this[34], v162, v90, 0.0);
                    *(_DWORD *)(*(_DWORD *)(v169 + 16) + 4 * v90) = v94;
                    if ( *(_DWORD *)(*(_DWORD *)(v169 + 16) + 4 * v90) == -1 )
                      return -2147024882;
                    v95 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v169 + 16) + 4 * v90));
                    v95[18] = v92[18];
                    v95[21] = v92[21];
                    v95[22] = v92[22];
                    v26 = ++v90 < v161;
                    v95[15] = v92[15];
                  }
                  while ( v26 );
                }
                v96 = v166 + 1;
                v164 = v166 + 1;
                while ( v96 < this[137] )
                {
                  v97 = *(int **)(this[140] + 4 * v164);
                  if ( v97 )
                  {
                    v98 = *v97;
                    if ( *v97 )
                    {
                      v99 = v98 & 0xFFFFF;
                      v100 = v97[1] / (v98 & 0xFFFFFu);
                      v163 = 0;
                      v156 = v99;
                      v155 = v100;
                      if ( v100 )
                      {
                        v158 = 0;
                        do
                        {
                          if ( v99 < 3 )
                          {
                            if ( v99 == 1 )
                            {
                              v104 = (_DWORD *)(v97[2] + 4 * v163);
                              if ( *v104 == v165 )
                              {
                                v105 = *(_DWORD **)(v169 + 16);
                                v106 = v161 == 4 ? v105[3] : *v105;
                                *v104 = v106;
                                if ( v164 > v167 )
                                  v167 = v164;
                              }
                            }
                            else
                            {
                              v107 = 0;
                              if ( v99 )
                              {
                                v108 = v158;
                                do
                                {
                                  v109 = (_DWORD *)(v108 + v97[2]);
                                  if ( *v109 == v165 )
                                  {
                                    *v109 = *(_DWORD *)(*(_DWORD *)(v169 + 16) + 4 * v107);
                                    if ( v164 > v167 )
                                      v167 = v164;
                                  }
                                  v99 = v156;
                                  ++v107;
                                  v108 += 4;
                                }
                                while ( v107 < v156 );
                              }
                            }
                          }
                          else
                          {
                            v101 = 0;
                            v102 = v158;
                            do
                            {
                              v103 = (_DWORD *)(v102 + v97[2]);
                              if ( *v103 == v165 )
                              {
                                *v103 = *(_DWORD *)(*(_DWORD *)(v169 + 16) + 4 * v101);
                                if ( v164 > v167 )
                                  v167 = v164;
                              }
                              v99 = v156;
                              ++v101;
                              v102 += 4;
                            }
                            while ( v101 < v156 );
                          }
                          ++v163;
                          v158 += 4 * v99;
                        }
                        while ( v163 < v155 );
                      }
                    }
                  }
                  v96 = ++v164;
                }
                v91 = v167;
                v156 = 1;
                v90 = 0;
              }
              ++v165;
            }
            while ( v165 < this[2] );
          }
        }
        v110 = v162;
        v111 = &v153[v162];
        if ( *v111 < v91 )
          *v111 = v91;
        v112 = 4 * v110;
        v113 = &v151[4 * v110];
        if ( *v113 < v91 )
          *v113 = v91;
        if ( v151[v112 + 1] < v91 )
          v151[v112 + 1] = v91;
        if ( v151[v112 + 2] < v91 )
          v151[v112 + 2] = v91;
        v114 = &v151[v112 + 3];
        if ( *v114 < v91 )
          *v114 = v91;
        if ( v156 )
          goto LABEL_262;
        k = v162;
        goto LABEL_238;
      }
    }
  }
  return result;
}
