unsigned int __stdcall sub_6B7E46(int a1, int a2)
{
  _BYTE *v3; // edi
  unsigned int v4; // eax
  unsigned int v5; // ebx
  int v6; // ecx
  int v7; // edx
  unsigned int v8; // ecx
  int v9; // ebx
  unsigned int v10; // eax
  unsigned int v11; // ebx
  char *v12; // edi
  _BYTE *v13; // eax
  char *v14; // ecx
  char v15; // dl
  char *v16; // edx
  unsigned int v17; // edi
  char v18; // bl
  unsigned int v19; // ebx
  int v20; // eax
  unsigned int v21; // edx
  unsigned int v22; // ecx
  int v23; // edi
  unsigned int v24; // eax
  unsigned int v25; // ebx
  int v26; // edi
  unsigned int v27; // edx
  int j; // ecx
  int v29; // ebx
  unsigned int v30; // eax
  unsigned int v31; // eax
  _BYTE *v32; // ecx
  unsigned __int8 *v33; // eax
  unsigned __int8 *v34; // edx
  int v35; // edi
  int v36; // ecx
  unsigned __int8 v37; // cl
  int v38; // edi
  int v39; // edx
  unsigned int v40; // ecx
  int v41; // ebx
  unsigned int v42; // eax
  _BYTE *v43; // eax
  _BYTE *v44; // ecx
  char v45; // dl
  int v46; // edi
  unsigned int v47; // edx
  unsigned int kk; // ecx
  int v49; // ebx
  unsigned int v50; // eax
  _BYTE *v51; // edx
  unsigned __int8 *ii; // eax
  unsigned __int8 v53; // cl
  int v54; // edi
  int v55; // edx
  unsigned int v56; // ecx
  int v57; // ebx
  unsigned int v58; // eax
  _BYTE *v59; // ecx
  _BYTE *v60; // edi
  unsigned int v61; // ebx
  int v62; // edi
  unsigned int v63; // edx
  unsigned int v64; // ecx
  int v65; // ebx
  unsigned int v66; // eax
  unsigned __int8 *v67; // eax
  unsigned __int8 *v68; // ecx
  _BYTE *v69; // edi
  _BYTE *v70; // ebx
  unsigned __int8 v71; // al
  int v72; // edx
  __int64 v73; // rax
  unsigned __int8 v74; // al
  int v75; // edx
  int v76; // edx
  unsigned int v77; // ecx
  int v78; // ebx
  unsigned int v79; // eax
  unsigned __int8 *v80; // eax
  _BYTE *v81; // ecx
  unsigned __int8 *v82; // edi
  int v83; // ebx
  int v84; // eax
  int v85; // eax
  int v86; // edx
  int v87; // ebx
  int v88; // eax
  char v89; // al
  bool v90; // cc
  unsigned __int8 *v91; // edx
  unsigned __int8 *v92; // ecx
  unsigned __int8 v93; // al
  int v94; // edi
  unsigned int v95; // ebx
  int v96; // edi
  int v97; // eax
  int v98; // edx
  int v99; // eax
  int v100; // edx
  int v101; // edi
  int v102; // eax
  char v103; // dl
  unsigned __int8 v104; // al
  int v105; // edx
  int v106; // edx
  unsigned int v107; // ecx
  int v108; // ebx
  unsigned int v109; // eax
  unsigned int result; // eax
  int i1; // ecx
  _BYTE *v112; // eax
  char v113; // [esp+Ch] [ebp-30h]
  int v114; // [esp+10h] [ebp-2Ch]
  int v115; // [esp+10h] [ebp-2Ch]
  unsigned int v116; // [esp+10h] [ebp-2Ch]
  int v117; // [esp+10h] [ebp-2Ch]
  unsigned int v118; // [esp+10h] [ebp-2Ch]
  unsigned int v119; // [esp+14h] [ebp-28h]
  _BYTE *k; // [esp+14h] [ebp-28h]
  unsigned int v121; // [esp+14h] [ebp-28h]
  unsigned __int8 *v122; // [esp+14h] [ebp-28h]
  unsigned int v123; // [esp+14h] [ebp-28h]
  int v124; // [esp+14h] [ebp-28h]
  unsigned __int8 *v125; // [esp+14h] [ebp-28h]
  unsigned int i; // [esp+18h] [ebp-24h]
  unsigned int v127; // [esp+18h] [ebp-24h]
  unsigned int v128; // [esp+18h] [ebp-24h]
  unsigned int v129; // [esp+18h] [ebp-24h]
  unsigned __int8 *v130; // [esp+18h] [ebp-24h]
  unsigned int v131; // [esp+18h] [ebp-24h]
  int v132; // [esp+18h] [ebp-24h]
  int v133; // [esp+18h] [ebp-24h]
  unsigned int v134; // [esp+1Ch] [ebp-20h]
  unsigned int v135; // [esp+1Ch] [ebp-20h]
  char v136; // [esp+1Ch] [ebp-20h]
  unsigned int v137; // [esp+1Ch] [ebp-20h]
  int v138; // [esp+20h] [ebp-1Ch]
  char v139; // [esp+20h] [ebp-1Ch]
  char v140; // [esp+20h] [ebp-1Ch]
  int v141; // [esp+24h] [ebp-18h]
  char v142; // [esp+24h] [ebp-18h]
  _BYTE *v143; // [esp+28h] [ebp-14h]
  _BYTE *v144; // [esp+28h] [ebp-14h]
  _BYTE *v145; // [esp+28h] [ebp-14h]
  _BYTE *v146; // [esp+2Ch] [ebp-10h]
  unsigned int v147; // [esp+30h] [ebp-Ch]
  unsigned int v148; // [esp+34h] [ebp-8h]
  int v149; // [esp+38h] [ebp-4h]
  _BYTE *v150; // [esp+44h] [ebp+8h]
  _BYTE *v151; // [esp+44h] [ebp+8h]
  char v152; // [esp+47h] [ebp+Bh]
  int v153; // [esp+48h] [ebp+Ch]
  int n; // [esp+48h] [ebp+Ch]
  unsigned int m; // [esp+48h] [ebp+Ch]
  unsigned int v156; // [esp+48h] [ebp+Ch]
  unsigned int v157; // [esp+48h] [ebp+Ch]
  unsigned int jj; // [esp+48h] [ebp+Ch]
  _BYTE *v159; // [esp+48h] [ebp+Ch]
  unsigned int mm; // [esp+48h] [ebp+Ch]
  int v161; // [esp+48h] [ebp+Ch]
  int v162; // [esp+48h] [ebp+Ch]
  int v163; // [esp+48h] [ebp+Ch]
  int v164; // [esp+48h] [ebp+Ch]
  unsigned int nn; // [esp+48h] [ebp+Ch]

  v149 = *(unsigned __int8 *)(a1 + 385);
  v3 = *(_BYTE **)(a1 + 220);
  v152 = *(_BYTE *)(a1 + 277);
  v147 = *(_DWORD *)(a2 + 4);
  v143 = v3;
  v146 = v3;
  v148 = 0x7FFFFFFF;
  v141 = (*(unsigned __int8 *)(a2 + 11) + 7) / 8;
  v138 = *(_DWORD *)(a1 + 216);
  if ( (v152 & 8) != 0 && v152 != 8 )
  {
    v4 = 0;
    v5 = 0;
    if ( *(_DWORD *)(a2 + 4) )
    {
      do
      {
        if ( (unsigned __int8)v3[v5 + 1] >= 0x80u )
          v6 = 256 - (unsigned __int8)v3[v5 + 1];
        else
          v6 = (unsigned __int8)v3[v5 + 1];
        v4 += v6;
        ++v5;
      }
      while ( v5 < v147 );
    }
    if ( *(_BYTE *)(a1 + 384) == 2 )
    {
      v7 = 0;
      v8 = (unsigned __int16)v4;
      for ( i = (v4 >> 10) & 0x3FFFC0; v7 < v149; ++v7 )
      {
        if ( !*(_BYTE *)(*(_DWORD *)(a1 + 388) + v7) )
        {
          v9 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 392) + 2 * v7);
          v8 = (v8 * v9) >> 8;
          i = (i * v9) >> 8;
        }
      }
      v10 = (i * **(unsigned __int16 **)(a1 + 400)) >> 3;
      if ( v10 <= 0x3FFFC0 )
        v4 = (v10 << 10) + ((v8 * **(unsigned __int16 **)(a1 + 400)) >> 3);
      else
        v4 = 0x7FFFFFFF;
    }
    v148 = v4;
  }
  if ( v152 == 16 )
  {
    v11 = 0;
    v12 = v3 + 1;
    v13 = (_BYTE *)(*(_DWORD *)(a1 + 224) + 1);
    v14 = v12;
    if ( v141 )
    {
      v153 = (*(unsigned __int8 *)(a2 + 11) + 7) / 8;
      v11 = v141;
      do
      {
        v15 = *v14++;
        *v13++ = v15;
        --v153;
      }
      while ( v153 );
    }
    v16 = v12;
    if ( v11 < v147 )
    {
      v17 = v147 - v11;
      do
      {
        v18 = *v14++ - *v16++;
        *v13++ = v18;
        --v17;
      }
      while ( v17 );
    }
    v146 = *(_BYTE **)(a1 + 224);
  }
  else
  {
    if ( (v152 & 0x10) != 0 )
    {
      v25 = 0;
      v127 = v148;
      if ( *(_BYTE *)(a1 + 384) == 2 )
      {
        v26 = 0;
        v27 = (unsigned __int16)v148;
        for ( j = (v148 >> 10) & 0x3FFFC0; v26 < v149; ++v26 )
        {
          if ( *(_BYTE *)(*(_DWORD *)(a1 + 388) + v26) == 1 )
          {
            v29 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 396) + 2 * v26);
            v30 = (unsigned int)(j * v29) >> 8;
            v27 = (v27 * v29) >> 8;
            v25 = 0;
            j = v30;
          }
        }
        v31 = (j * (unsigned int)*(unsigned __int16 *)(*(_DWORD *)(a1 + 404) + 2)) >> 3;
        if ( v31 <= 0x3FFFC0 )
          v127 = (v31 << 10) + ((v27 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 404) + 2)) >> 3);
        else
          v127 = 0x7FFFFFFF;
      }
      v134 = 0;
      v32 = v143 + 1;
      v33 = (unsigned __int8 *)(*(_DWORD *)(a1 + 224) + 1);
      v34 = v143 + 1;
      if ( v141 )
      {
        v114 = (*(unsigned __int8 *)(a2 + 11) + 7) / 8;
        v134 = v114;
        do
        {
          v35 = *v34;
          *v33 = *v34;
          if ( v35 >= 128 )
            v36 = 256 - v35;
          else
            v36 = v35;
          v25 += v36;
          ++v34;
          ++v33;
          --v114;
        }
        while ( v114 );
        v32 = v143 + 1;
      }
      for ( k = v32; v134 < *(_DWORD *)(a2 + 4); ++k )
      {
        v37 = *v34 - *k;
        *v33 = v37;
        v38 = v37 >= 0x80u ? 256 - v37 : v37;
        v25 += v38;
        if ( v25 > v127 )
          break;
        ++v134;
        ++v34;
        ++v33;
      }
      if ( *(_BYTE *)(a1 + 384) == 2 )
      {
        v39 = 0;
        v40 = (unsigned __int16)v25;
        for ( m = (v25 >> 10) & 0x3FFFC0; v39 < v149; ++v39 )
        {
          if ( *(_BYTE *)(v39 + *(_DWORD *)(a1 + 388)) == 1 )
          {
            v41 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 396) + 2 * v39);
            v40 = (v40 * v41) >> 8;
            m = (m * v41) >> 8;
          }
        }
        v42 = (m * *(unsigned __int16 *)(*(_DWORD *)(a1 + 404) + 2)) >> 3;
        if ( v42 <= 0x3FFFC0 )
          v25 = (v42 << 10) + ((v40 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 404) + 2)) >> 3);
        else
          v25 = 0x7FFFFFFF;
      }
      if ( v25 < v148 )
      {
        v148 = v25;
        v146 = *(_BYTE **)(a1 + 224);
      }
    }
    if ( v152 == 32 )
    {
      v156 = 0;
      v43 = (_BYTE *)(*(_DWORD *)(a1 + 228) + 1);
      if ( v147 )
      {
        v44 = (_BYTE *)(v138 + 1);
        do
        {
          v45 = v143[++v156] - *v44;
          *v43 = v45;
          ++v44;
          ++v43;
        }
        while ( v156 < v147 );
      }
      v146 = *(_BYTE **)(a1 + 228);
      goto LABEL_71;
    }
  }
  if ( (v152 & 0x20) != 0 )
  {
    v19 = 0;
    v119 = v148;
    if ( *(_BYTE *)(a1 + 384) == 2 )
    {
      v20 = 0;
      v21 = (unsigned __int16)v148;
      v22 = (v148 >> 10) & 0x3FFFC0;
      for ( n = 0; v20 < v149; n = v20 )
      {
        if ( *(_BYTE *)(v20 + *(_DWORD *)(a1 + 388)) == 2 )
        {
          v23 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 396) + 2 * v20);
          v22 = (v22 * v23) >> 8;
          v20 = n;
          v21 = (v21 * v23) >> 8;
        }
        ++v20;
      }
      v24 = (v22 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 404) + 4)) >> 3;
      if ( v24 <= 0x3FFFC0 )
        v119 = (v24 << 10) + ((v21 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 404) + 4)) >> 3);
      else
        v119 = 0x7FFFFFFF;
    }
    v129 = 0;
    v51 = v143 + 1;
    for ( ii = (unsigned __int8 *)(*(_DWORD *)(a1 + 228) + 1); v129 < v147; ++v129 )
    {
      v53 = *v51 - v51[v138 - (_DWORD)v143];
      *ii++ = v53;
      ++v51;
      if ( v53 >= 0x80u )
        v54 = 256 - v53;
      else
        v54 = v53;
      v19 += v54;
      if ( v19 > v119 )
        break;
    }
    if ( *(_BYTE *)(a1 + 384) == 2 )
    {
      v55 = 0;
      v56 = (unsigned __int16)v19;
      for ( jj = (v19 >> 10) & 0x3FFFC0; v55 < v149; ++v55 )
      {
        if ( *(_BYTE *)(v55 + *(_DWORD *)(a1 + 388)) == 2 )
        {
          v57 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 392) + 2 * v55);
          v56 = (v56 * v57) >> 8;
          jj = (jj * v57) >> 8;
        }
      }
      v58 = (jj * *(unsigned __int16 *)(*(_DWORD *)(a1 + 400) + 4)) >> 3;
      if ( v58 <= 0x3FFFC0 )
        v19 = (v58 << 10) + ((v56 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 400) + 4)) >> 3);
      else
        v19 = 0x7FFFFFFF;
    }
    if ( v19 < v148 )
    {
      v148 = v19;
      v146 = *(_BYTE **)(a1 + 228);
    }
  }
  if ( v152 == 64 )
  {
    v121 = 0;
    v59 = (_BYTE *)(*(_DWORD *)(a1 + 232) + 1);
    v60 = (_BYTE *)(v138 + 1);
    v159 = v143 + 1;
    if ( v141 )
    {
      v115 = v141;
      v121 = v141;
      do
      {
        *v59++ = *v159++ - (*v60++ >> 1);
        --v115;
      }
      while ( v115 );
    }
    v130 = v143 + 1;
    if ( v121 < v147 )
    {
      v61 = v147 - v121;
      do
      {
        *v59++ = *v159++ - (*v130++ + (unsigned __int8)*v60++) / 2;
        --v61;
      }
      while ( v61 );
    }
    v146 = *(_BYTE **)(a1 + 232);
    goto LABEL_104;
  }
LABEL_71:
  if ( (v152 & 0x40) != 0 )
  {
    v157 = 0;
    v128 = v148;
    if ( *(_BYTE *)(a1 + 384) == 2 )
    {
      v46 = 0;
      v47 = (unsigned __int16)v148;
      for ( kk = (v148 >> 10) & 0x3FFFC0; v46 < v149; ++v46 )
      {
        if ( *(_BYTE *)(v46 + *(_DWORD *)(a1 + 388)) == 3 )
        {
          v49 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 396) + 2 * v46);
          v47 = (v47 * v49) >> 8;
          kk = (kk * v49) >> 8;
        }
      }
      v50 = (kk * *(unsigned __int16 *)(*(_DWORD *)(a1 + 404) + 6)) >> 3;
      if ( v50 <= 0x3FFFC0 )
        v128 = (v50 << 10) + ((v47 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 404) + 6)) >> 3);
      else
        v128 = 0x7FFFFFFF;
    }
    v135 = 0;
    v67 = v143 + 1;
    v68 = (unsigned __int8 *)(*(_DWORD *)(a1 + 232) + 1);
    v69 = (_BYTE *)(v138 + 1);
    v70 = v143 + 1;
    if ( v141 )
    {
      v117 = v141;
      v135 = v141;
      do
      {
        v71 = *v70 - (*v69 >> 1);
        *v68++ = v71;
        ++v69;
        ++v70;
        if ( v71 >= 0x80u )
          v72 = 256 - v71;
        else
          v72 = v71;
        v157 += v72;
        --v117;
      }
      while ( v117 );
      v67 = v143 + 1;
    }
    v122 = v67;
    while ( v135 < v147 )
    {
      v73 = (unsigned __int8)*v69 + *v122;
      v74 = *v70 - (((int)v73 - HIDWORD(v73)) >> 1);
      *v68++ = v74;
      ++v122;
      ++v69;
      ++v70;
      v75 = v74 >= 0x80u ? 256 - v74 : v74;
      v157 += v75;
      if ( v157 > v128 )
        break;
      ++v135;
    }
    if ( *(_BYTE *)(a1 + 384) == 2 )
    {
      v76 = 0;
      v77 = (unsigned __int16)v157;
      for ( mm = (v157 >> 10) & 0x3FFFC0; v76 < v149; ++v76 )
      {
        if ( !*(_BYTE *)(v76 + *(_DWORD *)(a1 + 388)) )
        {
          v78 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 392) + 2 * v76);
          v77 = (v77 * v78) >> 8;
          mm = (mm * v78) >> 8;
        }
      }
      v79 = (mm * *(unsigned __int16 *)(*(_DWORD *)(a1 + 400) + 6)) >> 3;
      if ( v79 <= 0x3FFFC0 )
        v157 = (v79 << 10) + ((v77 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 400) + 6)) >> 3);
      else
        v157 = 0x7FFFFFFF;
    }
    if ( v157 < v148 )
    {
      v148 = v157;
      v146 = *(_BYTE **)(a1 + 232);
    }
  }
  if ( v152 == (char)0x80 )
  {
    v123 = 0;
    v80 = v143 + 1;
    v81 = (_BYTE *)(*(_DWORD *)(a1 + 236) + 1);
    v144 = v143 + 1;
    v150 = (_BYTE *)(v138 + 1);
    if ( v141 )
    {
      v161 = v141;
      v123 = v141;
      do
      {
        *v81++ = *v144++ - *v150++;
        --v161;
      }
      while ( v161 );
    }
    if ( v123 < v147 )
    {
      v162 = v138 + 1 - (_DWORD)v80;
      v82 = v80;
      v118 = v147 - v123;
      do
      {
        v83 = v82[v162];
        v84 = (unsigned __int8)*v150++;
        v136 = v84;
        v132 = *v82;
        v85 = v84 - v83;
        ++v82;
        v86 = v132 - v83;
        v139 = v83;
        if ( v85 >= 0 )
          v124 = v85;
        else
          v124 = -v85;
        v87 = v132 - v83;
        if ( v86 < 0 )
          v87 = -v86;
        v88 = v86 + v85;
        if ( v88 < 0 )
          v88 = -v88;
        if ( v124 > v87 || v124 > v88 )
        {
          v90 = v87 <= v88;
          v89 = v136;
          if ( !v90 )
            v89 = v139;
        }
        else
        {
          v89 = v132;
        }
        *v81++ = *v144++ - v89;
        --v118;
      }
      while ( v118 );
    }
    goto LABEL_194;
  }
LABEL_104:
  if ( v152 < 0 )
  {
    v62 = 0;
    v131 = 0;
    v116 = v148;
    if ( *(_BYTE *)(a1 + 384) == 2 )
    {
      v63 = (unsigned __int16)v148;
      v64 = (v148 >> 10) & 0x3FFFC0;
      if ( v149 > 0 )
      {
        do
        {
          if ( *(_BYTE *)(v62 + *(_DWORD *)(a1 + 388)) == 4 )
          {
            v65 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 396) + 2 * v62);
            v63 = (v63 * v65) >> 8;
            v64 = (v64 * v65) >> 8;
          }
          ++v62;
        }
        while ( v62 < v149 );
      }
      v66 = (v64 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 404) + 8)) >> 3;
      if ( v66 <= 0x3FFFC0 )
        v116 = (v66 << 10) + ((v63 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 404) + 8)) >> 3);
      else
        v116 = 0x7FFFFFFF;
    }
    v137 = 0;
    v91 = v143 + 1;
    v92 = (unsigned __int8 *)(*(_DWORD *)(a1 + 236) + 1);
    v145 = v143 + 1;
    v151 = (_BYTE *)(v138 + 1);
    if ( v141 )
    {
      v163 = v141;
      v137 = v141;
      do
      {
        v93 = *v145 - *v151;
        *v92++ = v93;
        ++v151;
        ++v145;
        if ( v93 >= 0x80u )
          v94 = 256 - v93;
        else
          v94 = v93;
        v131 += v94;
        --v163;
      }
      while ( v163 );
    }
    v125 = v91;
    if ( v137 >= v147 )
    {
      v95 = v131;
    }
    else
    {
      v164 = v138 + 1 - (_DWORD)v91;
      v95 = v131;
      do
      {
        v96 = v125[v164];
        v97 = (unsigned __int8)*v151;
        v98 = *v125;
        ++v151;
        ++v125;
        v142 = v97;
        v140 = v98;
        v99 = v97 - v96;
        v100 = v98 - v96;
        v113 = v96;
        if ( v99 >= 0 )
          v133 = v99;
        else
          v133 = -v99;
        v101 = v100;
        if ( v100 < 0 )
          v101 = -v100;
        v102 = v100 + v99;
        if ( v102 < 0 )
          v102 = -v102;
        if ( v133 > v101 || v133 > v102 )
        {
          v103 = v142;
          if ( v101 > v102 )
            v103 = v113;
        }
        else
        {
          v103 = v140;
        }
        v104 = *v145 - v103;
        *v92++ = v104;
        ++v145;
        if ( v104 >= 0x80u )
          v105 = 256 - v104;
        else
          v105 = v104;
        v95 += v105;
        if ( v95 > v116 )
          break;
        ++v137;
      }
      while ( v137 < v147 );
    }
    if ( *(_BYTE *)(a1 + 384) == 2 )
    {
      v106 = 0;
      v107 = (unsigned __int16)v95;
      for ( nn = (v95 >> 10) & 0x3FFFC0; v106 < v149; ++v106 )
      {
        if ( *(_BYTE *)(v106 + *(_DWORD *)(a1 + 388)) == 4 )
        {
          v108 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 392) + 2 * v106);
          v107 = (v107 * v108) >> 8;
          nn = (nn * v108) >> 8;
        }
      }
      v109 = (nn * *(unsigned __int16 *)(*(_DWORD *)(a1 + 400) + 8)) >> 3;
      if ( v109 <= 0x3FFFC0 )
        v95 = (v109 << 10) + ((v107 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 400) + 8)) >> 3);
      else
        v95 = 0x7FFFFFFF;
    }
    if ( v95 < v148 )
LABEL_194:
      v146 = *(_BYTE **)(a1 + 236);
  }
  result = sub_6B7D98((_DWORD *)a1, (int)v146);
  if ( *(_BYTE *)(a1 + 385) )
  {
    for ( i1 = 1; i1 < v149; *v112 = *(v112 - 1) )
    {
      v112 = (_BYTE *)(i1 + *(_DWORD *)(a1 + 388));
      ++i1;
    }
    result = *(_DWORD *)(a1 + 388);
    *(_BYTE *)(i1 + result) = *v146;
  }
  return result;
}
