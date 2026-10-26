int __thiscall sub_689751(_DWORD *this, unsigned int *a2, int a3, int a4, int a5)
{
  unsigned int v5; // kr00_4
  _DWORD *v6; // ebx
  int v7; // eax
  int *v8; // esi
  _DWORD *v9; // ecx
  _DWORD *v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // edx
  int *v15; // edi
  int v16; // eax
  unsigned int v17; // esi
  int v18; // edx
  int v19; // ecx
  unsigned int v20; // eax
  unsigned int v21; // eax
  int v22; // eax
  char v23; // dl
  int v24; // eax
  _DWORD *v25; // eax
  int v26; // ecx
  _DWORD *v27; // eax
  unsigned int v28; // ecx
  _DWORD *v29; // edx
  bool v30; // zf
  _DWORD *v31; // eax
  unsigned int v32; // ecx
  _DWORD *v33; // edx
  int result; // eax
  int v35; // eax
  int v36; // esi
  long double v37; // st7
  _DWORD *v38; // edx
  _DWORD *v39; // eax
  int v40; // edx
  char v41; // cl
  int v42; // eax
  _DWORD *v43; // eax
  unsigned int v44; // edi
  unsigned int v45; // esi
  _DWORD *v46; // ecx
  int v47; // ecx
  int v48; // eax
  int v49; // ecx
  int v50; // eax
  bool v51; // zf
  double v52; // st6
  bool v53; // zf
  unsigned int v54; // ecx
  _DWORD *v55; // eax
  _DWORD *v56; // edx
  _DWORD *v57; // eax
  unsigned int v58; // ecx
  _DWORD *v59; // edx
  double v60; // st7
  unsigned int v61; // eax
  int v62; // ecx
  int v63; // ecx
  int v64; // eax
  _DWORD *v65; // eax
  _DWORD *j; // edx
  int v67; // eax
  _DWORD *v68; // eax
  unsigned int v69; // esi
  unsigned int v70; // ecx
  _DWORD *v71; // edx
  int v72; // eax
  int v73; // edx
  int v74; // ecx
  int v75; // eax
  unsigned int v76; // edx
  int v77; // eax
  int v78; // eax
  _DWORD *v79; // eax
  unsigned int v80; // ecx
  _DWORD *v81; // edx
  unsigned int v82; // edi
  int v83; // ecx
  _DWORD *v84; // esi
  unsigned int v85; // eax
  char *v86; // eax
  unsigned int v87; // eax
  _DWORD *k; // edx
  int v89; // eax
  double v90; // st7
  int v91; // edi
  int v92; // eax
  _DWORD *v93; // eax
  unsigned int v94; // edx
  unsigned int v95; // ecx
  _DWORD *v96; // esi
  int v97; // edx
  int v98; // eax
  int v99; // esi
  int v100; // eax
  int v101; // ecx
  _DWORD *v102; // edx
  _DWORD *v103; // ecx
  unsigned int v104; // esi
  _DWORD *v105; // eax
  unsigned int v106; // edi
  _DWORD *v107; // eax
  unsigned int v108; // esi
  _DWORD *v109; // eax
  int v110; // eax
  int v111; // ecx
  unsigned int v112; // edx
  int v113; // edx
  _DWORD *v114; // ecx
  unsigned int v115; // eax
  unsigned int v116; // eax
  _DWORD *v117; // esi
  int v118; // esi
  _DWORD *v119; // eax
  _DWORD *v120; // eax
  unsigned int v121; // edx
  int v122; // edx
  int v123; // edi
  int v124; // eax
  int v125; // ecx
  _DWORD *v126; // esi
  unsigned int v127; // ecx
  unsigned int v128; // ebx
  _DWORD *v129; // edx
  int v130; // ebx
  _DWORD *v131; // esi
  int v132; // eax
  double v133; // st7
  double v134; // [esp+0h] [ebp-60h] BYREF
  long double v135; // [esp+14h] [ebp-4Ch]
  int v136; // [esp+1Ch] [ebp-44h]
  int v137; // [esp+20h] [ebp-40h]
  int v138; // [esp+24h] [ebp-3Ch] BYREF
  int v139; // [esp+28h] [ebp-38h]
  unsigned int v140; // [esp+2Ch] [ebp-34h]
  int v141; // [esp+30h] [ebp-30h] BYREF
  int v142; // [esp+34h] [ebp-2Ch]
  unsigned int v143; // [esp+38h] [ebp-28h]
  unsigned int v144; // [esp+3Ch] [ebp-24h]
  int v145; // [esp+40h] [ebp-20h]
  _DWORD *v146; // [esp+44h] [ebp-1Ch]
  _DWORD *v147; // [esp+48h] [ebp-18h]
  _DWORD *v148; // [esp+4Ch] [ebp-14h]
  int *v149; // [esp+50h] [ebp-10h]
  unsigned int v150; // [esp+54h] [ebp-Ch]
  int v151; // [esp+58h] [ebp-8h]
  unsigned int i; // [esp+5Ch] [ebp-4h]
  int v153; // [esp+68h] [ebp+8h]
  int v154; // [esp+6Ch] [ebp+Ch]
  int v155; // [esp+70h] [ebp+10h]
  int v156; // [esp+74h] [ebp+14h]
  unsigned int v157; // [esp+74h] [ebp+14h]

  v6 = this;
  v147 = this;
  v143 = *a2;
  v7 = this[5];
  v8 = *(int **)(v7 + 4 * a3);
  v155 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * a4) + 48);
  v9 = *(_DWORD **)(v7 + 4 * v155);
  v156 = *(_DWORD *)(*(_DWORD *)(v7 + 4 * a5) + 48);
  v10 = *(_DWORD **)(v7 + 4 * v156);
  v11 = v8[1];
  v149 = v8;
  v12 = *(_DWORD *)(*(_DWORD *)(v147[4] + 4 * v11) + 4);
  v146 = v9;
  v148 = v10;
  if ( (v12 & 1) == 0 || (v12 & 0x1000) != 0 )
    return 0;
  v13 = *v9;
  v14 = *v10;
  v15 = v149;
  i = v13 & 0x1F;
  v16 = *v149;
  v151 = v14 & 0x1F;
  v144 = v16 & 0x40;
  if ( (v16 & 0xE000000) == 0 )
  {
    v17 = v143 & 0xFFF00000;
    if ( (v143 & 0xFFF00000) == 0x20000000
      || v17 == 537919488
      || v17 == 541065216
      || v17 == 544210944
      || v17 == 545259520
      || v17 == 546308096 )
    {
      v18 = v13 | v14;
      v19 = 0x8000000;
      if ( (v18 & 0x8000000) != 0
        || (v19 = 0x4000000, (v18 & 0x4000000) != 0)
        || (v19 = (int)&dword_2000000, (v18 & (unsigned int)&dword_2000000) != 0) )
      {
        *v149 = v19 | v16;
      }
    }
  }
  if ( ((*(_BYTE *)v146 | *(_BYTE *)v148) & 0x40) != 0 )
  {
    v20 = v143 & 0xFFF00000;
    if ( (v143 & 0xFFF00000) <= 0x20600000 )
    {
      if ( (v143 & 0xFFF00000) != 0x20600000
        && v20 != 0x20000000
        && v20 != 537919488
        && v20 != 541065216
        && v20 != 542113792 )
      {
        goto LABEL_26;
      }
LABEL_25:
      *v15 |= 0x40u;
      goto LABEL_26;
    }
    if ( v20 == 544210944 || v20 == 545259520 || v20 == 546308096 )
      goto LABEL_25;
  }
LABEL_26:
  v21 = v143 & 0xFFF00000;
  v150 = v143 & 0xFFF00000;
  if ( (v143 & 0xFFF00000) > 0x20400000 )
  {
    if ( v21 != 542113792 )
    {
      if ( v21 != 544210944 && v21 != 545259520 && v21 != 546308096 )
        goto LABEL_73;
      v22 = i & v151;
      goto LABEL_41;
    }
    v23 = i;
    *v15 |= (unsigned __int8)i & (unsigned __int8)v151 & 3;
    v24 = *v15;
    v140 = v23 & 4;
    if ( (v23 & 4) != 0 && (v151 & 4) != 0 || (i & 8) != 0 && (v151 & 8) != 0 )
      *v15 = v24 | 4;
    if ( v140 && (v151 & 8) != 0 || (i & 8) != 0 && (v151 & 4) != 0 )
      *v15 |= 8u;
    v25 = v148;
    if ( v146 == v148 )
    {
      *v15 |= 4u;
      goto LABEL_73;
    }
    v26 = v6[4];
    if ( (*(_BYTE *)(*(_DWORD *)(v26 + 4 * v146[1]) + 4) & 2) != 0 )
    {
      v27 = *(_DWORD **)(v6[6] + 4 * v146[18]);
      if ( (*v27 & 0xFFF00000) == 0x10100000 )
      {
        v28 = 0;
        if ( !v27[3] )
          goto LABEL_73;
        v29 = (_DWORD *)v27[4];
        do
        {
          if ( *v29 == v155 )
            break;
          ++v28;
          ++v29;
        }
        while ( v28 < v27[3] );
        if ( v28 >= v27[3] )
          goto LABEL_73;
        v30 = *(_DWORD *)(v27[2] + 4 * v28) == v156;
LABEL_71:
        if ( v30 )
          *v15 |= 8u;
        goto LABEL_73;
      }
      v25 = v148;
    }
    if ( (*(_BYTE *)(*(_DWORD *)(v26 + 4 * v25[1]) + 4) & 2) == 0 )
      goto LABEL_73;
    v31 = *(_DWORD **)(v6[6] + 4 * v25[18]);
    if ( (*v31 & 0xFFF00000) != 0x10100000 )
      goto LABEL_73;
    v32 = 0;
    if ( !v31[3] )
      goto LABEL_73;
    v33 = (_DWORD *)v31[4];
    do
    {
      if ( *v33 == v156 )
        break;
      ++v32;
      ++v33;
    }
    while ( v32 < v31[3] );
    if ( v32 >= v31[3] )
      goto LABEL_73;
    v30 = *(_DWORD *)(v31[2] + 4 * v32) == v155;
    goto LABEL_71;
  }
  if ( (v143 & 0xFFF00000) == 0x20400000 )
  {
    v22 = (unsigned __int8)i & (unsigned __int8)v151 & 0xE;
  }
  else if ( v21 == 0x20000000 )
  {
    v22 = i & 8 | v151 & (i | 8);
  }
  else
  {
    if ( v21 != 537919488 )
    {
      if ( v21 == 538968064 || v21 == 540016640 )
        *v15 |= 0x17u;
      goto LABEL_73;
    }
    v22 = i & 4 | v151 & (i | 4);
  }
LABEL_41:
  *v15 |= v22;
LABEL_73:
  if ( !v144 )
  {
    if ( (i & 4) != 0 && (v151 & 8) != 0 )
    {
      result = v150;
      HIDWORD(v134) = 0;
      v5 = __readeflags();
      _InterlockedExchange((volatile __int32 *)&v134 + 1, dword_16C6E2C - *(_DWORD *)sub_525080);
      __writeeflags(v5);
      return result;
    }
    if ( (i & 8) != 0 && (v151 & 4) != 0 )
    {
      if ( v150 == 0x20000000 )
        goto LABEL_77;
      if ( v150 == 537919488 )
      {
        v35 = v156;
        goto LABEL_261;
      }
    }
  }
  v36 = v6[4];
  v140 = *(_DWORD *)(*(_DWORD *)(v36 + 4 * v146[1]) + 4);
  v145 = v36;
  if ( (v140 & 0x100) != 0
    && v146[2] == -1
    && (*(_DWORD *)(*(_DWORD *)(v36 + 4 * v148[1]) + 4) & 0x100) != 0
    && v148[2] == -1 )
  {
    v37 = *((double *)v146 + 4);
    v135 = *((double *)v148 + 4);
    switch ( v150 )
    {
      case 0x20000000u:
        if ( v37 >= v135 )
LABEL_104:
          v37 = v135;
        break;
      case 0x20100000u:
        if ( v37 < v135 )
          goto LABEL_104;
        break;
      case 0x20200000u:
        if ( v37 < v135 )
          goto LABEL_150;
        goto LABEL_126;
      case 0x20300000u:
        if ( v37 < v135 )
          goto LABEL_126;
LABEL_150:
        v37 = 1.0;
        break;
      default:
        switch ( v150 )
        {
          case 0x20400000u:
            v37 = v37 + v135;
            break;
          case 0x20500000u:
            v37 = v37 * v135;
            break;
          case 0x20600000u:
            v37 = atan2(v37, v135);
            break;
          default:
            return 0;
        }
        break;
    }
LABEL_105:
    v134 = v37;
LABEL_215:
    v35 = sub_681AAA(v6, v6[30], 0, 0, v134);
    goto LABEL_261;
  }
  if ( v144 )
  {
    v39 = v148;
  }
  else
  {
    if ( (v140 & 0x100) != 0 )
    {
      v38 = v146;
      if ( v146[2] == -1 )
      {
        v39 = v148;
        goto LABEL_112;
      }
    }
    v39 = v148;
    if ( (*(_DWORD *)(*(_DWORD *)(v36 + 4 * v148[1]) + 4) & 0x100) != 0 && v148[2] == -1 )
    {
      v38 = v146;
LABEL_112:
      if ( (v140 & 0x100) != 0 && v38[2] == -1 )
      {
        v37 = *((double *)v38 + 4);
        v40 = v156;
        v41 = v151;
      }
      else
      {
        v37 = *((double *)v39 + 4);
        v40 = v155;
        v41 = i;
      }
      if ( v150 == 0x20000000 )
      {
        if ( v37 < 1.0 || (v41 & 1) == 0 )
        {
          if ( v37 > 0.0 || (v41 & 4) == 0 )
            return 0;
          goto LABEL_105;
        }
        goto LABEL_183;
      }
      if ( v150 == 537919488 )
      {
        if ( v37 >= 1.0 && (v41 & 1) != 0 )
          goto LABEL_105;
        if ( v37 > 0.0 )
          return 0;
        v53 = (v41 & 4) == 0;
      }
      else
      {
        if ( v150 == 538968064 )
        {
          if ( v40 != v156 )
          {
            if ( v37 <= 0.0 && (v41 & 4) != 0 )
              goto LABEL_126;
            if ( v37 > 0.0 && (v41 & 8) != 0 )
              goto LABEL_150;
            v51 = v37 > 1.0;
            goto LABEL_174;
          }
          if ( v37 < 0.0 && (v41 & 4) != 0 )
            goto LABEL_150;
          if ( v37 >= 0.0 && (v41 & 8) != 0 || v37 >= 1.0 && (v41 & 1) != 0 )
            goto LABEL_126;
          v52 = 0.0;
        }
        else
        {
          if ( v150 != 540016640 )
          {
            if ( v150 == 541065216 )
            {
              if ( v37 != 0.0 )
                return 0;
            }
            else
            {
              if ( v150 != 542113792 )
              {
                if ( v150 != 543162368 || v37 != 0.0 || v40 != v155 )
                  return 0;
                goto LABEL_126;
              }
              if ( v37 == 0.0 )
              {
LABEL_126:
                v37 = 0.0;
                goto LABEL_105;
              }
              if ( v37 != 1.0 )
              {
                if ( v37 != 0.5 )
                  return 0;
                v42 = *(_DWORD *)(v6[5] + 4 * v40);
                if ( (*(_BYTE *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)(v42 + 4)) + 4) & 2) == 0 )
                  return 0;
                v43 = *(_DWORD **)(v6[6] + 4 * *(_DWORD *)(v42 + 72));
                if ( (*v43 & 0xFFF00000) != 0x20400000 )
                  return 0;
                v44 = v43[3];
                v45 = 0;
                if ( v44 )
                {
                  v46 = (_DWORD *)v43[4];
                  do
                  {
                    if ( *v46 == v40 )
                      break;
                    ++v45;
                    ++v46;
                  }
                  while ( v45 < v44 );
                }
                if ( v45 >= v44 )
                  return 0;
                v47 = v43[2];
                if ( *(_DWORD *)(v47 + 4 * v45) != *(_DWORD *)(v47 + 4 * (v45 + v44)) )
                  return 0;
                v48 = *(_DWORD *)(4 * v45 + v47);
                v49 = v6[5];
                goto LABEL_139;
              }
            }
LABEL_183:
            v15[12] = v40;
            return 0;
          }
          if ( v40 == v156 )
          {
            if ( v37 < 0.0 && (v41 & 4) != 0 )
              goto LABEL_126;
            if ( v37 >= 0.0 && (v41 & 8) != 0 )
              goto LABEL_150;
            v51 = v37 >= 1.0;
LABEL_174:
            if ( !v51 || (v41 & 1) == 0 )
              return 0;
            goto LABEL_150;
          }
          if ( v37 <= 0.0 && (v41 & 4) != 0 )
            goto LABEL_150;
          if ( v37 > 0.0 && (v41 & 8) != 0 || v37 > 1.0 && (v41 & 1) != 0 )
            goto LABEL_126;
          v52 = 1.0;
        }
        if ( v37 != v52 )
          return 0;
        v53 = (v41 & 1) == 0;
      }
      if ( v53 )
        return 0;
      goto LABEL_183;
    }
  }
  if ( v146 == v39 )
  {
    switch ( v150 )
    {
      case 0x20000000u:
      case 0x20100000u:
        goto LABEL_77;
      case 0x20200000u:
        if ( v144 )
          return 0;
        goto LABEL_213;
      case 0x20300000u:
        if ( v144 )
          return 0;
        v60 = 1.0;
        goto LABEL_214;
    }
    if ( v150 == 542113792 && (i & 1) != 0 )
    {
LABEL_77:
      v35 = v155;
      goto LABEL_261;
    }
  }
  v54 = 0;
  if ( v144 )
    return 0;
  if ( v150 == 541065216 )
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v36 + 4 * v39[1]) + 4) & 2) != 0 )
    {
      v55 = *(_DWORD **)(v6[6] + 4 * v39[18]);
      if ( (*v55 & 0xFFF00000) == 0x10100000 )
      {
        if ( v55[3] )
        {
          v56 = (_DWORD *)v55[4];
          do
          {
            if ( *v56 == v156 )
              break;
            ++v54;
            ++v56;
          }
          while ( v54 < v55[3] );
          if ( v54 < v55[3] && v155 == *(_DWORD *)(v55[2] + 4 * v54) )
            goto LABEL_213;
        }
      }
    }
    if ( (v140 & 2) != 0 )
    {
      v57 = *(_DWORD **)(v6[6] + 4 * v146[18]);
      if ( (*v57 & 0xFFF00000) == 0x10100000 )
      {
        v58 = 0;
        if ( v57[3] )
        {
          v59 = (_DWORD *)v57[4];
          do
          {
            if ( *v59 == v155 )
              break;
            ++v58;
            ++v59;
          }
          while ( v58 < v57[3] );
          if ( v58 < v57[3] && v156 == *(_DWORD *)(v57[2] + 4 * v58) )
          {
LABEL_213:
            v60 = 0.0;
LABEL_214:
            v134 = v60;
            goto LABEL_215;
          }
        }
      }
    }
    for ( i = 0; i < 8; ++i )
    {
      if ( (i & 4) != 0 )
      {
        v61 = v155;
        v62 = v156;
      }
      else
      {
        v61 = v156;
        v62 = v155;
      }
      v142 = v62;
      v143 = v61;
      v137 = i & 2;
      if ( (i & 2) != 0 )
      {
        v63 = v6[5];
        v64 = *(_DWORD *)(v63 + 4 * v61);
        if ( (*(_BYTE *)(*(_DWORD *)(v145 + 4 * *(_DWORD *)(v64 + 4)) + 4) & 2) == 0 )
          continue;
        v65 = *(_DWORD **)(v6[6] + 4 * *(_DWORD *)(v64 + 72));
        if ( (*v65 & 0xFFF00000) != 0x10100000 )
          continue;
        v144 = 0;
        if ( v65[3] )
        {
          for ( j = (_DWORD *)v65[4]; v143 != *j; j = (_DWORD *)v139 )
          {
            ++v144;
            v139 = (int)(j + 1);
            if ( v144 >= v65[3] )
              goto LABEL_234;
          }
          v143 = *(_DWORD *)(*(_DWORD *)(v63 + 4 * *(_DWORD *)(v65[2] + 4 * v144)) + 48);
        }
      }
LABEL_234:
      v67 = *(_DWORD *)(v6[5] + 4 * v142);
      if ( (*(_BYTE *)(*(_DWORD *)(v145 + 4 * *(_DWORD *)(v67 + 4)) + 4) & 2) != 0 )
      {
        v68 = *(_DWORD **)(v6[6] + 4 * *(_DWORD *)(v67 + 72));
        if ( (*v68 & 0xFFF00000) == 0x20400000 )
        {
          v69 = v68[3];
          v70 = 0;
          if ( v69 )
          {
            v71 = (_DWORD *)v68[4];
            while ( v142 != *v71 )
            {
              ++v70;
              ++v71;
              if ( v70 >= v69 )
                goto LABEL_245;
            }
            v72 = v68[2];
            if ( (i & 1) != 0 )
            {
              v73 = *(_DWORD *)(v72 + 4 * v70);
              v70 += v69;
            }
            else
            {
              v73 = *(_DWORD *)(v72 + 4 * (v70 + v69));
            }
            v74 = *(_DWORD *)(v72 + 4 * v70);
            v75 = v6[5];
            v76 = *(_DWORD *)(*(_DWORD *)(v75 + 4 * v73) + 48);
            v77 = *(_DWORD *)(*(_DWORD *)(v75 + 4 * v74) + 48);
            v140 = v76;
            HIDWORD(v135) = v77;
LABEL_245:
            v15 = v149;
          }
          if ( !v137 )
          {
            v78 = *(_DWORD *)(v6[5] + 4 * v140);
            if ( (*(_BYTE *)(*(_DWORD *)(v145 + 4 * *(_DWORD *)(v78 + 4)) + 4) & 2) == 0 )
              continue;
            v79 = *(_DWORD **)(v6[6] + 4 * *(_DWORD *)(v78 + 72));
            if ( (*v79 & 0xFFF00000) != 0x10100000 )
              continue;
            v80 = 0;
            if ( v79[3] )
            {
              v81 = (_DWORD *)v79[4];
              while ( v140 != *v81 )
              {
                ++v80;
                ++v81;
                if ( v80 >= v79[3] )
                  goto LABEL_255;
              }
              v140 = *(_DWORD *)(*(_DWORD *)(v6[5] + 4 * *(_DWORD *)(v79[2] + 4 * v80)) + 48);
            }
          }
LABEL_255:
          if ( v143 == v140 )
          {
            v35 = HIDWORD(v135);
LABEL_261:
            v15[12] = v35;
            return 0;
          }
        }
      }
    }
  }
  if ( v150 == 542113792 )
  {
    v82 = 0;
    v136 = v155;
    v137 = v156;
    v142 = 0;
    v141 = 0;
    v139 = 0;
    v138 = 0;
    while ( 2 )
    {
      v83 = *(int *)((char *)&v136 + v82);
      while ( 1 )
      {
        v89 = *(_DWORD *)(v6[5] + 4 * v83);
        if ( (*(_BYTE *)(*(_DWORD *)(v145 + 4 * *(_DWORD *)(v89 + 4)) + 4) & 2) == 0 )
          break;
        v84 = *(_DWORD **)(v6[6] + 4 * *(_DWORD *)(v89 + 72));
        v85 = *v84 & 0xFFF00000;
        if ( v85 == 269484032 )
        {
          v86 = (char *)&v141 + v82;
        }
        else
        {
          if ( v85 != 271581184 )
            break;
          v86 = (char *)&v138 + v82;
        }
        *(_DWORD *)v86 = *(_DWORD *)v86 == 0;
        v87 = 0;
        v140 = v84[3];
        if ( v140 )
        {
          for ( k = (_DWORD *)v84[4]; *k != v83; k = (_DWORD *)HIDWORD(v135) )
          {
            ++v87;
            HIDWORD(v135) = k + 1;
            if ( v87 >= v140 )
              goto LABEL_273;
          }
          v83 = *(_DWORD *)(v84[2] + 4 * v87);
        }
LABEL_273:
        if ( v87 >= v140 )
          return -2147467259;
      }
      *(int *)((char *)&v136 + v82) = v83;
      v82 += 4;
      if ( v82 < 8 )
        continue;
      break;
    }
    if ( v136 == v137 && v138 != v139 )
    {
      if ( v141 == v142 )
        v90 = 1.0;
      else
        v90 = -1.0;
      v50 = sub_681AAA(v6, v6[30], 0, 0, v90);
      goto LABEL_377;
    }
  }
  v91 = v155;
  if ( v150 == 538968064 )
  {
    v92 = *(_DWORD *)(v6[5] + 4 * v155);
    if ( (*(_BYTE *)(*(_DWORD *)(v145 + 4 * *(_DWORD *)(v92 + 4)) + 4) & 2) != 0 && (v151 & 1) != 0 )
    {
      v93 = *(_DWORD **)(v6[6] + 4 * *(_DWORD *)(v92 + 72));
      if ( (*v93 & 0xFFF00000) == 0x10100000 )
      {
        v94 = v93[3];
        v95 = 0;
        if ( v94 )
        {
          v96 = (_DWORD *)v93[4];
          do
          {
            if ( *v96 == v155 )
              break;
            ++v95;
            ++v96;
          }
          while ( v95 < v94 );
        }
        v97 = v93[2];
        v50 = v156;
        if ( *(_DWORD *)(v97 + 4 * v95) == v156 )
          goto LABEL_377;
      }
    }
  }
  v98 = v6[5];
  v99 = *(_DWORD *)(v98 + 4 * v155);
  if ( (*(_BYTE *)(*(_DWORD *)(v145 + 4 * *(_DWORD *)(v99 + 4)) + 4) & 2) == 0
    || (*(_BYTE *)(*(_DWORD *)(v145 + 4 * *(_DWORD *)(*(_DWORD *)(v98 + 4 * v156) + 4)) + 4) & 2) == 0 )
  {
    return 0;
  }
  if ( v150 == 542113792 || v150 == 538968064 || v150 == 540016640 )
  {
    v100 = v6[5];
    v101 = v6[6];
    v102 = *(_DWORD **)(v101 + 4 * *(_DWORD *)(*(_DWORD *)(v100 + 4 * v155) + 72));
    v103 = *(_DWORD **)(v101 + 4 * *(_DWORD *)(*(_DWORD *)(v100 + 4 * v156) + 72));
    if ( (*v102 & 0xFFF00000) == 0x10100000 && (*v103 & 0xFFF00000) == 0x10100000 )
    {
      v104 = a2[3];
      v143 = 0;
      if ( v104 )
      {
        v105 = (_DWORD *)a2[4];
        do
        {
          if ( a3 == *v105 )
            break;
          ++v143;
          ++v105;
        }
        while ( v143 < v104 );
      }
      v106 = 0;
      if ( v102[3] )
      {
        v107 = (_DWORD *)v102[4];
        do
        {
          if ( v155 == *v107 )
            break;
          ++v106;
          ++v107;
        }
        while ( v106 < v102[3] );
      }
      v108 = 0;
      if ( v103[3] )
      {
        v109 = (_DWORD *)v103[4];
        do
        {
          if ( v156 == *v109 )
            break;
          ++v108;
          ++v109;
        }
        while ( v108 < v103[3] );
        v6 = v147;
      }
      if ( v150 == 542113792 )
      {
        v110 = *(_DWORD *)(v102[2] + 4 * v106);
        v111 = *(_DWORD *)(v103[2] + 4 * v108);
      }
      else
      {
        v110 = *(_DWORD *)(v103[2] + 4 * v108);
        v111 = *(_DWORD *)(v102[2] + 4 * v106);
      }
      v112 = v143;
      *(_DWORD *)(a2[2] + 4 * v143) = *(_DWORD *)(*(_DWORD *)(v6[5] + 4 * v110) + 48);
      *(_DWORD *)(a2[2] + 4 * (v112 + a2[3])) = *(_DWORD *)(*(_DWORD *)(v6[5] + 4 * v111) + 48);
      return 0;
    }
    v91 = v155;
  }
  if ( v150 != 542113792 )
    return 0;
  if ( v91 == v156 )
  {
    v113 = v6[6];
    v114 = *(_DWORD **)(v113 + 4 * *(_DWORD *)(v99 + 72));
    v115 = *v114 & 0xFFF00000;
    if ( v115 == 271581184 || v115 == 275775488 )
    {
      v116 = 0;
      if ( v114[3] )
      {
        v117 = (_DWORD *)v114[4];
        do
        {
          if ( *v117 == v91 )
            break;
          ++v116;
          ++v117;
        }
        while ( v116 < v114[3] );
      }
      v118 = 4 * v116;
      v119 = *(_DWORD **)(v6[5] + 4 * *(_DWORD *)(4 * v116 + v114[2]));
      if ( (*(_BYTE *)(*(_DWORD *)(v145 + 4 * v119[1]) + 4) & 2) != 0 && v119[2] == -1 )
      {
        v120 = *(_DWORD **)(v113 + 4 * v119[18]);
        v121 = *v120 & 0xFFF00000;
        if ( (v121 == 271581184 || v121 == 275775488) && (*v114 & 0xFFF00000) != v121 )
        {
          v157 = 0;
          if ( v120[3] )
          {
            v122 = v120[4];
            do
            {
              *(_DWORD *)(v122 + 4 * v157) = *(_DWORD *)(v118 + v114[2]);
              v122 = v120[4];
              if ( *(_DWORD *)(v122 + 4 * v157) )
                break;
              ++v157;
            }
            while ( v157 < v120[3] );
          }
          v48 = *(_DWORD *)(v120[2] + 4 * v157);
          v49 = v147[5];
LABEL_139:
          v50 = *(_DWORD *)(*(_DWORD *)(v49 + 4 * v48) + 48);
LABEL_377:
          v149[12] = v50;
          return 0;
        }
      }
      v91 = v155;
      v6 = v147;
    }
  }
  HIDWORD(v135) = *v146 & 1;
  if ( HIDWORD(v135) && sub_683158(v6, v91, v156) )
  {
    v50 = v156;
    goto LABEL_377;
  }
  v139 = *v148 & 1;
  if ( v139 && sub_683158(v6, v156, v91) )
  {
    v149[12] = v91;
    return 0;
  }
  v154 = 0;
  v153 = 0;
  v143 = 1;
  v144 = 1;
  v123 = v149[6];
  v124 = v149[5];
  if ( v124 == -1 )
    return 0;
  do
  {
    v125 = *(_DWORD *)(4 * v124 + v147[5]);
    v140 = 4 * v124;
    v126 = *(_DWORD **)(v147[6] + 4 * *(_DWORD *)(v125 + 72));
    v127 = v126[3];
    v128 = 0;
    if ( v127 )
    {
      v129 = (_DWORD *)v126[4];
      do
      {
        if ( *v129 == v124 )
          break;
        ++v128;
        ++v129;
      }
      while ( v128 < v127 );
    }
    if ( HIDWORD(v135) )
    {
      v137 = *(_DWORD *)(v126[2] + 4 * v128);
      if ( (sub_683158(v147, v155, v137) & v123) != 0 )
        v154 = 1;
      if ( !v123 && sub_683158(v147, v137, v155) )
      {
        v143 = 0;
        v154 = 1;
      }
    }
    if ( v139 )
    {
      v130 = *(_DWORD *)(v126[2] + 4 * v128);
      if ( (sub_683158(v147, v156, v130) & v123) != 0 )
        v153 = 1;
      v131 = v147;
      if ( !v123 && sub_683158(v147, v130, v156) )
      {
        v144 = 0;
        v153 = 1;
      }
    }
    else
    {
      v131 = v147;
    }
    v132 = *(_DWORD *)(v131[5] + v140);
    v123 = *(_DWORD *)(v132 + 24);
    v124 = *(_DWORD *)(v132 + 20);
  }
  while ( v124 != -1 );
  if ( v154 )
  {
    if ( v153 )
    {
      if ( !v143 )
        goto LABEL_369;
      if ( v144 )
      {
        v133 = 1.0;
LABEL_370:
        v50 = sub_681AAA(v131, v131[30], 0, 0, v133);
        goto LABEL_377;
      }
    }
    if ( v143 )
      goto LABEL_367;
LABEL_369:
    v133 = 0.0;
    goto LABEL_370;
  }
LABEL_367:
  if ( v153 && !v144 )
    goto LABEL_369;
  if ( v154 && v143 )
  {
    v149[12] = v156;
    return 0;
  }
  if ( v153 && v144 )
  {
    v50 = v155;
    goto LABEL_377;
  }
  return 0;
}
