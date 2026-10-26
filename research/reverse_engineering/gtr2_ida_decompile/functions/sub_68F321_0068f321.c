int __thiscall sub_68F321(_DWORD *this)
{
  unsigned int v1; // ebx
  int v3; // ecx
  bool v4; // zf
  unsigned int *v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // edx
  _DWORD *v9; // ecx
  unsigned int v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // ebx
  unsigned int v14; // ecx
  int *v15; // ecx
  int *v16; // edx
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // ebx
  int result; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  unsigned int v25; // eax
  unsigned int v26; // ecx
  unsigned int v27; // edx
  int v28; // eax
  int v29; // ecx
  int v30; // ecx
  int v31; // eax
  _DWORD *v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ecx
  int v35; // ebx
  int v36; // eax
  unsigned int v37; // edx
  int v38; // edx
  unsigned int v39; // ecx
  int *v40; // ecx
  int *v41; // eax
  int v42; // edx
  int v43; // ecx
  int v44; // ebx
  int v45; // ecx
  int v46; // ebx
  int v47; // eax
  int v48; // ecx
  int v49; // edx
  unsigned int v50; // eax
  _DWORD *v51; // ecx
  int v52; // eax
  int v53; // edx
  _DWORD *v54; // ecx
  int v55; // eax
  int v56; // ecx
  _DWORD *v57; // eax
  unsigned int v58; // edx
  int v59; // ecx
  int v60; // eax
  _DWORD *v61; // edx
  unsigned int v62; // eax
  unsigned int j; // ebx
  void *v64; // ecx
  unsigned int v65; // eax
  unsigned int v66; // ecx
  int v67; // edx
  int v68; // eax
  unsigned int v69; // edx
  int v70; // edx
  unsigned int v71; // ecx
  int *v72; // ecx
  int *v73; // eax
  int v74; // edx
  int v75; // ecx
  int v76; // ebx
  int v77; // ecx
  int v78; // ebx
  int v79; // eax
  int v80; // ecx
  int *v81; // edx
  unsigned int v83; // eax
  _DWORD *v84; // ecx
  int v85; // eax
  int v86; // edx
  _DWORD *v87; // ecx
  int v88; // eax
  int v89; // ecx
  _DWORD *v90; // eax
  unsigned int v91; // edx
  int v92; // ecx
  int v93; // eax
  unsigned int *v94; // edx
  unsigned int v95; // eax
  unsigned int m; // ebx
  void *v97; // ecx
  _DWORD *v98; // ecx
  int v99; // eax
  int v100; // ecx
  _DWORD *v101; // eax
  int v102; // ecx
  _DWORD *v103; // eax
  int v104; // ebx
  unsigned int v105; // edx
  int v106; // eax
  int v107; // edx
  unsigned int v108; // ebx
  int v109; // eax
  int v110; // eax
  int v111; // eax
  int v112; // eax
  int v113; // eax
  int v114; // ecx
  int v115; // eax
  int v116; // ecx
  int v117; // eax
  int v118; // ecx
  int v119; // eax
  int v120; // edx
  _DWORD *v121; // eax
  _DWORD *v122; // ecx
  int *v123; // eax
  int v124; // eax
  int v125; // ecx
  unsigned int k; // ecx
  int v127; // edx
  int v128; // [esp+18h] [ebp-48h]
  int v129; // [esp+1Ch] [ebp-44h]
  int v130; // [esp+20h] [ebp-40h]
  int v131; // [esp+24h] [ebp-3Ch]
  unsigned int *v132; // [esp+28h] [ebp-38h]
  int v133; // [esp+2Ch] [ebp-34h]
  int v134; // [esp+30h] [ebp-30h]
  int *v135; // [esp+34h] [ebp-2Ch]
  int v136; // [esp+38h] [ebp-28h]
  int v137; // [esp+3Ch] [ebp-24h]
  int v138; // [esp+40h] [ebp-20h]
  unsigned int v139; // [esp+44h] [ebp-1Ch]
  int v140; // [esp+48h] [ebp-18h]
  unsigned int v141; // [esp+4Ch] [ebp-14h]
  int v142; // [esp+50h] [ebp-10h]
  unsigned int n; // [esp+54h] [ebp-Ch]
  unsigned int i; // [esp+58h] [ebp-8h]
  unsigned int v145; // [esp+5Ch] [ebp-4h]

  v1 = 0;
  v145 = 0;
  sub_686606(this);
  sub_686074(v3);
  v138 = -1;
  v142 = -1;
  v4 = this[3] == 0;
  v140 = 0;
  if ( v4 )
    return 1;
  while ( 1 )
  {
    v5 = *(unsigned int **)(this[6] + 4 * v140);
    v6 = *v5;
    v7 = *v5 & 0xFFF00000;
    if ( !v7 )
      goto LABEL_207;
    n = this[2];
    if ( v7 == 285212672 )
    {
      v8 = 0;
      if ( v5[1] )
      {
        v9 = (_DWORD *)v5[2];
        do
        {
          if ( (**(_BYTE **)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v9) + 48)) & 4) == 0 )
            break;
          ++v8;
          ++v9;
        }
        while ( v8 < v5[1] );
      }
      if ( v8 == v5[1] )
        goto LABEL_192;
      goto LABEL_194;
    }
    v10 = v6 & 0xF0000000;
    if ( (v6 & 0xF0000000) == 0x10000000 )
    {
      v4 = v5[3] == 0;
      i = 0;
      n = 0;
      if ( !v4 )
      {
        do
        {
          v11 = *(_DWORD *)(4 * n + v5[4]);
          v12 = this[5];
          v13 = *(_DWORD *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)(4 * n + v5[2])) + 48);
          v14 = *v5 & 0xFFF00000;
          v137 = v11;
          v136 = v13;
          if ( v14 == 0x10000000 || v14 == 269484032 )
          {
            v15 = *(int **)(v12 + 4 * v11);
            v16 = *(int **)(v12 + 4 * v13);
            v17 = *v16;
            v135 = v15;
            v18 = *v15;
            v19 = (v18 | v17) & 0xE000000;
            v20 = (int)&dword_2000000;
            if ( (v19 & (unsigned int)&dword_2000000) != 0
              || (v20 = 0x4000000, (v19 & 0x4000000) != 0)
              || (v20 = 0x8000000, (v19 & 0x8000000) != 0) )
            {
              v19 = v20;
            }
            if ( v19 != (v18 & 0xE000000) )
            {
              *v135 = v19 | v18 & 0xF1FFFFFF;
              v145 = 1;
            }
            v135 = (int *)*v16;
            if ( v19 != ((unsigned int)v135 & 0xE000000)
              && (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v16[1]) + 4) & 2) != 0
              && v16[23] == 1 )
            {
              *v16 = v19 | (unsigned int)v135 & 0xF1FFFFFF;
              v145 = 1;
            }
          }
          result = sub_689020(this, v5, v137, v136);
          if ( result < 0 )
            return result;
          v22 = this[5];
          v23 = v22 + 4 * v137;
          v24 = *(_DWORD *)(*(_DWORD *)v23 + 48);
          if ( v24 == v137 )
          {
            ++i;
          }
          else if ( *(_DWORD *)(*(_DWORD *)(v22 + 4 * v24) + 48) == -1 )
          {
            *(_DWORD *)(*(_DWORD *)(v22 + 4 * *(_DWORD *)(*(_DWORD *)v23 + 48)) + 48) = *(_DWORD *)(*(_DWORD *)v23 + 48);
          }
        }
        while ( ++n < v5[3] );
      }
      v25 = v5[3];
      if ( i != v25 )
      {
        v26 = 0;
        i = 0;
        v145 = 0;
        if ( v25 )
        {
          do
          {
            v27 = v5[4];
            v28 = *(_DWORD *)(v27 + 4 * v145);
            v29 = this[5];
            if ( *(_DWORD *)(*(_DWORD *)(v29 + 4 * v28) + 48) == v28 )
            {
              v30 = 4 * i++;
              *(_DWORD *)(v30 + v27) = v28;
              *(_DWORD *)(v30 + v5[2]) = *(_DWORD *)(v5[2] + 4 * v145);
            }
            else
            {
              v31 = *(_DWORD *)(v29 + 4 * v28);
              v32 = *(_DWORD **)(v29 + 4 * *(_DWORD *)(v31 + 48));
              if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v32[1]) + 4) & 2) != 0 && !v32[24] )
              {
                v33 = v145;
                v32[24] = *(_DWORD *)(v31 + 96);
                v32[25] = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v5[4] + 4 * v33)) + 100);
              }
            }
            ++v145;
          }
          while ( v145 < v5[3] );
          v26 = i;
        }
        v5[1] = v26;
        v5[3] = v26;
        return off_16C9908();
      }
      goto LABEL_194;
    }
    if ( v10 == 0x20000000 )
    {
      v4 = v5[3] == 0;
      v141 = 0;
      i = 0;
      if ( !v4 )
      {
        do
        {
          v34 = v5[2];
          v35 = *(_DWORD *)(4 * i + v5[4]);
          v36 = this[5];
          v136 = *(_DWORD *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)(4 * i + v34)) + 48);
          v37 = i + v5[3];
          v133 = v35;
          v38 = *(_DWORD *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)(v34 + 4 * v37)) + 48);
          v39 = *v5 & 0xFFF00000;
          v134 = v38;
          if ( v39 == 0x20000000 || v39 == 537919488 )
          {
            v135 = *(int **)(v36 + 4 * v35);
            v40 = *(int **)(v36 + 4 * v136);
            v41 = *(int **)(v36 + 4 * v38);
            v42 = *v40;
            v137 = (int)v40;
            v43 = (v42 | *v41) & 0xE000000;
            v44 = 0x8000000;
            v4 = ((v42 | *v41) & 0x8000000) == 0;
            v139 = (unsigned int)v41;
            if ( !v4
              || (v44 = 0x4000000, (v43 & 0x4000000) != 0)
              || (v44 = (int)&dword_2000000, (v43 & (unsigned int)&dword_2000000) != 0) )
            {
              v43 = v44;
            }
            v45 = *v135 & 0xE000000 | v43;
            v46 = (int)&dword_2000000;
            if ( (v45 & (unsigned int)&dword_2000000) != 0
              || (v46 = 0x4000000, (v45 & 0x4000000) != 0)
              || (v46 = 0x8000000, (v45 & 0x8000000) != 0) )
            {
              v45 = v46;
            }
            if ( v45 != (v42 & 0xE000000) )
            {
              if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v137 + 4)) + 4) & 2) != 0
                && *(_DWORD *)(v137 + 92) == 1 )
              {
                *(_DWORD *)v137 = v45 | v42 & 0xF1FFFFFF;
                v145 = 1;
              }
              v41 = (int *)v139;
            }
            v135 = (int *)*v41;
            if ( v45 != ((unsigned int)v135 & 0xE000000)
              && (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v41[1]) + 4) & 2) != 0
              && v41[23] == 1 )
            {
              *v41 = v45 | (unsigned int)v135 & 0xF1FFFFFF;
              v145 = 1;
            }
          }
          result = sub_689751(this, v5, v133, v136, v134);
          if ( result < 0 )
            return result;
          v47 = this[5];
          v48 = v47 + 4 * v133;
          v49 = *(_DWORD *)(*(_DWORD *)v48 + 48);
          if ( v49 == v133 )
          {
            ++v141;
          }
          else if ( *(_DWORD *)(*(_DWORD *)(v47 + 4 * v49) + 48) == -1 )
          {
            *(_DWORD *)(*(_DWORD *)(v47 + 4 * *(_DWORD *)(*(_DWORD *)v48 + 48)) + 48) = *(_DWORD *)(*(_DWORD *)v48 + 48);
          }
        }
        while ( ++i < v5[3] );
      }
      v50 = v5[3];
      if ( v141 == v50 )
        goto LABEL_194;
      if ( !v141 )
      {
        v139 = 1;
        if ( v50 <= 1 )
          goto LABEL_75;
        v51 = (_DWORD *)v5[4];
        v52 = this[5];
        v53 = *(_DWORD *)(*(_DWORD *)(v52 + 4 * *(_DWORD *)(*(_DWORD *)(v52 + 4 * *v51) + 48)) + 4);
        v54 = v51 + 1;
        while ( v53 == *(_DWORD *)(*(_DWORD *)(v52 + 4 * *(_DWORD *)(*(_DWORD *)(v52 + 4 * *v54) + 48)) + 4) )
        {
          ++v139;
          ++v54;
          if ( v139 >= v5[3] )
            goto LABEL_75;
        }
        v50 = v5[3];
        if ( !v50 )
        {
LABEL_75:
          for ( i = 0; i < v5[3]; ++i )
          {
            v55 = this[5];
            v56 = *(_DWORD *)(v55 + 4 * *(_DWORD *)(v5[4] + 4 * i));
            v57 = *(_DWORD **)(v55 + 4 * *(_DWORD *)(v56 + 48));
            if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v57[1]) + 4) & 2) != 0 && !v57[24] )
            {
              v58 = i;
              v57[24] = *(_DWORD *)(v56 + 96);
              v57[25] = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v5[4] + 4 * v58)) + 100);
            }
          }
          goto LABEL_192;
        }
      }
      v141 = 0;
      if ( v50 )
      {
        do
        {
          v59 = *(_DWORD *)(v5[4] + 4 * v141);
          v60 = this[5];
          v61 = *(_DWORD **)(v60 + 4 * v59);
          v4 = v61[12] == v59;
          v133 = (int)v61;
          if ( !v4 )
          {
            v62 = *v61 | **(_DWORD **)(v60 + 4 * v61[12]) & 0xF1FFFFFF;
            if ( *v61 != v62 )
            {
              *(_DWORD *)v133 = v62;
              v145 = 1;
            }
            *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v59) + 48) = v59;
          }
          ++v141;
        }
        while ( v141 < v5[3] );
      }
      for ( j = n; j < this[2]; ++j )
      {
        v64 = *(void **)(this[5] + 4 * j);
        if ( v64 )
          sub_663A9B(v64, 1);
      }
      v65 = n;
      goto LABEL_142;
    }
    if ( v10 == 805306368 )
      break;
    if ( v7 == 1342177280 )
    {
      result = sub_682AEE((int)this, (int)v5, 1);
      if ( result < 0 )
        return result;
      if ( result != 1 )
        v145 = 1;
      v98 = (_DWORD *)v5[4];
      v99 = this[5];
      if ( *(_DWORD *)(*(_DWORD *)(v99 + 4 * *v98) + 48) != *v98 )
      {
        v100 = *(_DWORD *)(v99 + 4 * *v98);
        v101 = *(_DWORD **)(v99 + 4 * *(_DWORD *)(v100 + 48));
        if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v101[1]) + 4) & 2) != 0 && !v101[24] )
        {
          v101[24] = *(_DWORD *)(v100 + 96);
          v101[25] = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)v5[4]) + 100);
        }
        v5[1] = 0;
        v5[3] = 0;
        *v5 = 0;
      }
      goto LABEL_194;
    }
    if ( v6 == 1343225860 )
    {
      v102 = this[5];
      v130 = -1;
      v129 = -1;
      v131 = 1;
      v128 = 1;
      v103 = (_DWORD *)v5[2];
      v104 = *(_DWORD *)(v102 + 4 * *v103);
      v105 = *(_DWORD *)(v102 + 4 * v103[1]);
      v141 = *(_DWORD *)(v102 + 4 * v103[3]);
      v106 = *(_DWORD *)(v104 + 4);
      v139 = v105;
      v107 = this[4];
      if ( (*(_BYTE *)(*(_DWORD *)(v107 + 4 * v106) + 5) & 1) == 0 || *(_DWORD *)(v104 + 8) != -1 )
      {
        if ( !*(_DWORD *)(*(_DWORD *)(v102 + 4 * *(_DWORD *)(v5[4] + 4)) + 92) )
          v129 = 0;
        goto LABEL_169;
      }
      if ( *(double *)(v104 + 32) > 0.0 )
      {
        v4 = (*(_BYTE *)(*(_DWORD *)(v107 + 4 * *(_DWORD *)(v139 + 4)) + 5) & 1) == 0;
        v129 = 2;
        if ( !v4 && *(_DWORD *)(v139 + 8) == -1 )
        {
          if ( *(double *)(v139 + 32) <= 0.0 )
            goto LABEL_166;
          if ( (*(_BYTE *)(*(_DWORD *)(v107 + 4 * *(_DWORD *)(v141 + 4)) + 5) & 1) != 0 && *(_DWORD *)(v141 + 8) == -1 )
          {
            if ( 0.0 == *(double *)(v141 + 32) )
            {
              v130 = 1;
              goto LABEL_173;
            }
            if ( 1.0 == *(double *)(v141 + 32) )
            {
              v130 = 3;
              goto LABEL_173;
            }
          }
        }
LABEL_169:
        if ( !*(_DWORD *)(*(_DWORD *)(v102 + 4 * *(_DWORD *)(v5[4] + 8)) + 92) )
          v130 = 0;
        if ( v129 != -1 && v130 != -1 )
          goto LABEL_173;
        goto LABEL_194;
      }
      v129 = 0;
LABEL_166:
      v130 = 0;
LABEL_173:
      v108 = 0;
      while ( 2 )
      {
        v109 = *(int *)((char *)&v128 + v108);
        if ( v109 )
        {
          v110 = v109 - 1;
          if ( v110 )
          {
            v111 = v110 - 1;
            if ( v111 )
            {
              if ( v111 == 1 )
              {
                v112 = *(_DWORD *)(v5[2] + 4);
                goto LABEL_179;
              }
            }
            else
            {
              v112 = *(_DWORD *)v5[2];
LABEL_179:
              *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v108 + v5[4])) + 48) = v112;
            }
LABEL_188:
            v119 = this[5];
            v120 = this[4];
            v132 = *(unsigned int **)(v119 + 4 * *(_DWORD *)(v108 + v5[4]));
            v121 = *(_DWORD **)(v119 + 4 * v132[12]);
            if ( (*(_BYTE *)(*(_DWORD *)(v120 + 4 * v121[1]) + 4) & 2) != 0 && !v121[24] )
            {
              v121[24] = v132[24];
              v121[25] = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v108 + v5[4])) + 100);
            }
            v108 += 4;
            if ( v108 >= 0x10 )
              goto LABEL_192;
            continue;
          }
          if ( v138 == -1 )
          {
            v113 = sub_681AAA(this, this[30], 0, 0, 1.0);
            v114 = *(_DWORD *)(this[5] + 4 * v113);
            v138 = v113;
            *(_DWORD *)(v114 + 48) = v113;
          }
          v115 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v108 + v5[4]));
          v116 = v138;
        }
        else
        {
          if ( v142 == -1 )
          {
            v117 = sub_681AAA(this, this[30], 0, 0, 0.0);
            v118 = *(_DWORD *)(this[5] + 4 * v117);
            v142 = v117;
            *(_DWORD *)(v118 + 48) = v117;
          }
          v115 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v108 + v5[4]));
          v116 = v142;
        }
        break;
      }
      *(_DWORD *)(v115 + 48) = v116;
      goto LABEL_188;
    }
LABEL_194:
    if ( v5[3] )
    {
      v141 = 0;
      v122 = (_DWORD *)v5[4];
      do
      {
        v123 = *(int **)(this[5] + 4 * *v122);
        v135 = (int *)*v123;
        if ( ((unsigned __int8)v135 & 0x40) != 0 )
          break;
        if ( (*(_DWORD *)(*(_DWORD *)(this[4] + 4 * v123[1]) + 4) & 0x11028) != 0 )
          break;
        if ( ((unsigned __int8)v135 & 4) == 0 )
          break;
        if ( ((unsigned __int8)v135 & 8) == 0 )
          break;
        ++v141;
        ++v122;
      }
      while ( v141 < v5[3] );
      if ( v141 == v5[3] )
      {
        v124 = v142;
        if ( v142 == -1 )
        {
          v124 = sub_681AAA(this, this[30], 0, 0, 0.0);
          v125 = *(_DWORD *)(this[5] + 4 * v124);
          v142 = v124;
          *(_DWORD *)(v125 + 48) = v124;
        }
        for ( k = 0; k < v5[3]; *(_DWORD *)(v127 + 48) = v124 )
          v127 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v5[4] + 4 * k++));
        *v5 = 0;
        v5[1] = 0;
        v5[3] = 0;
        v145 = 1;
      }
    }
LABEL_207:
    if ( (unsigned int)++v140 >= this[3] )
    {
      if ( v145 )
      {
        sub_68661F(this);
        return 0;
      }
      return 1;
    }
    v1 = 0;
  }
  v4 = v5[3] == 0;
  v141 = 0;
  i = 0;
  if ( !v4 )
  {
    do
    {
      v66 = v5[2];
      v67 = *(_DWORD *)(v66 + 4 * v1);
      v135 = *(int **)(v5[4] + 4 * v1);
      v68 = this[5];
      v132 = *(unsigned int **)(*(_DWORD *)(v68 + 4 * v67) + 48);
      v69 = v5[3];
      v137 = *(_DWORD *)(*(_DWORD *)(v68 + 4 * *(_DWORD *)(v66 + 4 * (v69 + v1))) + 48);
      v70 = *(_DWORD *)(*(_DWORD *)(v68 + 4 * *(_DWORD *)(v66 + 4 * (i + 2 * v69))) + 48);
      v71 = *v5 & 0xFFF00000;
      v134 = v70;
      if ( v71 == 805306368 )
      {
        v133 = *(_DWORD *)(v68 + 4 * (_DWORD)v135);
        v72 = *(int **)(v68 + 4 * v137);
        v73 = *(int **)(v68 + 4 * v70);
        v74 = *v72;
        v136 = (int)v72;
        v75 = (v74 | *v73) & 0xE000000;
        v76 = 0x8000000;
        v4 = ((v74 | *v73) & 0x8000000) == 0;
        v139 = (unsigned int)v73;
        if ( !v4
          || (v76 = 0x4000000, (v75 & 0x4000000) != 0)
          || (v76 = (int)&dword_2000000, (v75 & (unsigned int)&dword_2000000) != 0) )
        {
          v75 = v76;
        }
        v77 = *(_DWORD *)v133 & 0xE000000 | v75;
        v78 = (int)&dword_2000000;
        if ( (v77 & (unsigned int)&dword_2000000) != 0
          || (v78 = 0x4000000, (v77 & 0x4000000) != 0)
          || (v78 = 0x8000000, (v77 & 0x8000000) != 0) )
        {
          v77 = v78;
        }
        if ( v77 != (v74 & 0xE000000) )
        {
          if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v136 + 4)) + 4) & 2) != 0
            && *(_DWORD *)(v136 + 92) == 1 )
          {
            *(_DWORD *)v136 = v77 | v74 & 0xF1FFFFFF;
            v145 = 1;
          }
          v73 = (int *)v139;
        }
        v133 = *v73;
        if ( v77 != (v133 & 0xE000000) && (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v73[1]) + 4) & 2) != 0 && v73[23] == 1 )
        {
          *v73 = v77 | v133 & 0xF1FFFFFF;
          v145 = 1;
        }
      }
      result = sub_68A6CE(this, v5, (int)v135, (int)v132, v137, v134);
      if ( result < 0 )
        return result;
      v79 = this[5];
      v80 = v79 + 4 * (_DWORD)v135;
      v81 = *(int **)(*(_DWORD *)v80 + 48);
      if ( v81 == v135 )
      {
        ++v141;
      }
      else if ( *(_DWORD *)(*(_DWORD *)(v79 + 4 * (_DWORD)v81) + 48) == -1 )
      {
        *(_DWORD *)(*(_DWORD *)(v79 + 4 * *(_DWORD *)(*(_DWORD *)v80 + 48)) + 48) = *(_DWORD *)(*(_DWORD *)v80 + 48);
      }
      v1 = i + 1;
    }
    while ( ++i < v5[3] );
  }
  v83 = v5[3];
  if ( v141 == v83 )
    goto LABEL_194;
  if ( v141 )
    goto LABEL_132;
  v139 = 1;
  if ( v83 > 1 )
  {
    v84 = (_DWORD *)v5[4];
    v85 = this[5];
    v86 = *(_DWORD *)(*(_DWORD *)(v85 + 4 * *(_DWORD *)(*(_DWORD *)(v85 + 4 * *v84) + 48)) + 4);
    v87 = v84 + 1;
    while ( v86 == *(_DWORD *)(*(_DWORD *)(v85 + 4 * *(_DWORD *)(*(_DWORD *)(v85 + 4 * *v87) + 48)) + 4) )
    {
      ++v139;
      ++v87;
      if ( v139 >= v5[3] )
        goto LABEL_125;
    }
    v83 = v5[3];
    if ( v83 )
    {
LABEL_132:
      v141 = 0;
      if ( v83 )
      {
        do
        {
          v92 = *(_DWORD *)(v5[4] + 4 * v141);
          v93 = this[5];
          v94 = *(unsigned int **)(v93 + 4 * v92);
          v4 = v94[12] == v92;
          v132 = v94;
          if ( !v4 )
          {
            v95 = *v94 | **(_DWORD **)(v93 + 4 * v94[12]) & 0xF1FFFFFF;
            if ( *v94 != v95 )
            {
              *v132 = v95;
              v145 = 1;
            }
            *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v92) + 48) = v92;
          }
          ++v141;
        }
        while ( v141 < v5[3] );
      }
      v65 = n;
      for ( m = n; m < this[2]; ++m )
      {
        v97 = *(void **)(this[5] + 4 * m);
        if ( v97 )
        {
          sub_663A9B(v97, 1);
          v65 = n;
        }
      }
LABEL_142:
      this[2] = v65;
      goto LABEL_194;
    }
  }
LABEL_125:
  for ( n = 0; n < v5[3]; ++n )
  {
    v88 = this[5];
    v89 = *(_DWORD *)(v88 + 4 * *(_DWORD *)(v5[4] + 4 * n));
    v90 = *(_DWORD **)(v88 + 4 * *(_DWORD *)(v89 + 48));
    if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v90[1]) + 4) & 2) != 0 && !v90[24] )
    {
      v91 = n;
      v90[24] = *(_DWORD *)(v89 + 96);
      v90[25] = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v5[4] + 4 * v91)) + 100);
    }
  }
LABEL_192:
  v5[1] = 0;
  v5[3] = 0;
  return off_16C9908();
}
