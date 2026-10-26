int __thiscall sub_66F3C1(
        int this,
        _DWORD *a2,
        __int64 a3,
        unsigned int *a4,
        unsigned int a5,
        _DWORD *a6,
        unsigned int a7,
        unsigned int a8)
{
  unsigned int v9; // ebx
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c2
  double v13; // st6
  double v14; // st7
  __int64 v15; // rax
  unsigned int v16; // eax
  int result; // eax
  __int16 v18; // ax
  unsigned int v19; // edx
  int v20; // ecx
  _DWORD *v21; // ebx
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  unsigned int *v25; // edi
  unsigned int *v26; // esi
  unsigned int v27; // eax
  int v28; // ecx
  _DWORD *v29; // edx
  _DWORD *v30; // ecx
  int v31; // edx
  int v32; // ecx
  int v33; // edx
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // eax
  int v38; // ebx
  int v39; // eax
  int v40; // ecx
  int v41; // edi
  unsigned int v42; // edx
  bool v43; // cf
  unsigned int v44; // edx
  unsigned int *v45; // ebx
  int v46; // ecx
  int v47; // eax
  _DWORD *v48; // edx
  unsigned int n; // eax
  _DWORD *v50; // edx
  unsigned int v51; // ebx
  void *v52; // eax
  _DWORD *v53; // edx
  _DWORD *v54; // eax
  unsigned int m; // ecx
  unsigned int v56; // ecx
  int v57; // ebx
  int v58; // eax
  int v59; // ecx
  int v60; // ecx
  int v61; // eax
  int v62; // eax
  int v63; // ebx
  int v64; // edi
  double v65; // st7
  int v66; // ebx
  int v67; // eax
  int v68; // eax
  unsigned int v69; // ecx
  int *v70; // edi
  unsigned int v71; // ebx
  int v72; // ecx
  int v73; // eax
  int v74; // edi
  _DWORD *v75; // ebx
  int v76; // edi
  unsigned int v77; // edx
  unsigned int *v78; // eax
  void *v79; // eax
  _DWORD *v80; // edx
  _DWORD *v81; // eax
  unsigned int i; // ecx
  unsigned int v83; // ecx
  int v84; // ebx
  unsigned int j; // ecx
  int v86; // eax
  int v87; // ecx
  int v88; // ecx
  int v89; // eax
  int v90; // eax
  int v91; // ebx
  int v92; // edi
  double v93; // st7
  int v94; // ebx
  int v95; // eax
  int v96; // eax
  unsigned int v97; // ecx
  int *v98; // edi
  unsigned int v99; // ebx
  int v100; // ecx
  int v101; // eax
  int v102; // edi
  unsigned int k; // eax
  int v104; // edi
  _DWORD *v105; // eax
  char *v106; // ecx
  char *v107; // edx
  int v108; // eax
  __int64 X; // [esp+0h] [ebp-7Ch]
  __int64 Xa; // [esp+0h] [ebp-7Ch]
  __int64 Xb; // [esp+0h] [ebp-7Ch]
  __int64 Xc; // [esp+0h] [ebp-7Ch]
  __int64 Xd; // [esp+0h] [ebp-7Ch]
  int v114; // [esp+14h] [ebp-68h]
  _DWORD *v115; // [esp+18h] [ebp-64h]
  _DWORD *v116; // [esp+1Ch] [ebp-60h]
  int *v117; // [esp+20h] [ebp-5Ch]
  char *v118; // [esp+24h] [ebp-58h]
  int *v119; // [esp+28h] [ebp-54h]
  unsigned int v120; // [esp+2Ch] [ebp-50h]
  unsigned int v121; // [esp+30h] [ebp-4Ch]
  _DWORD *v122; // [esp+34h] [ebp-48h]
  unsigned int v123; // [esp+38h] [ebp-44h]
  _DWORD *v124; // [esp+3Ch] [ebp-40h]
  char *v125; // [esp+40h] [ebp-3Ch]
  int v126; // [esp+44h] [ebp-38h] BYREF
  double v127; // [esp+48h] [ebp-34h] BYREF
  double v128; // [esp+50h] [ebp-2Ch] BYREF
  int v129; // [esp+58h] [ebp-24h]
  BOOL v130; // [esp+5Ch] [ebp-20h]
  int v131; // [esp+60h] [ebp-1Ch]
  unsigned int v132; // [esp+64h] [ebp-18h]
  unsigned int *v133; // [esp+68h] [ebp-14h]
  unsigned int v134; // [esp+6Ch] [ebp-10h]
  int v135; // [esp+70h] [ebp-Ch]
  unsigned int v136; // [esp+74h] [ebp-8h]
  unsigned int v137; // [esp+78h] [ebp-4h]
  unsigned int *v138; // [esp+84h] [ebp+8h]
  int v139; // [esp+88h] [ebp+Ch]
  char *v140; // [esp+90h] [ebp+14h]

  if ( !a5 )
    goto LABEL_41;
  v9 = HIDWORD(a3);
  v137 = 0;
  if ( HIDWORD(a3) )
    v136 = a5 / HIDWORD(a3);
  else
    v136 = 1;
  if ( sub_662830(this, *(_DWORD *)a7, &v127) < 0 )
    goto LABEL_27;
  if ( v11 | v12 )
  {
    v13 = v127 - *(double *)(this + 176);
  }
  else if ( v127 <= 0.0 )
  {
    v13 = 0.0;
  }
  else
  {
    v13 = v127 + *(double *)(this + 176);
  }
  v127 = v13;
  if ( v128 >= 0.0 )
  {
    if ( v128 <= 0.0 )
      v14 = 0.0;
    else
      v14 = v128 + *(double *)(this + 176);
  }
  else
  {
    v14 = v128 - *(double *)(this + 176);
  }
  v128 = v14;
  if ( _finite(v127) && v127 >= 0.0 )
    v137 = (__int64)v127;
  else
    v137 = 0;
  if ( v128 < 0.0 || HIDWORD(a3) * v137 >= a5 )
  {
    if ( *(_DWORD *)(this + 88) )
    {
      *(_DWORD *)(this + 92) = 1;
      v25 = (unsigned int *)a3;
      if ( (_DWORD)a3 )
      {
        v26 = a4;
LABEL_40:
        qmemcpy(v25, v26, 4 * v9);
      }
      return 0;
    }
LABEL_41:
    sub_663C07((_DWORD *)this, a2, 3504, "array index out of bounds");
    return -2147467259;
  }
  if ( _finite(v128) )
    v15 = (__int64)v128;
  else
    LODWORD(v15) = v136 - 1;
  v16 = v15 + 1;
  if ( v136 > v16 )
    v136 = v16;
LABEL_27:
  if ( !(_DWORD)a3 )
    return 0;
  if ( !a8 )
  {
    result = sub_666F65((_DWORD *)this, a6, a4, a5);
    if ( result < 0 )
      return result;
  }
  v18 = -1;
  v19 = 0;
  v134 = 0;
  if ( a5 )
  {
    v20 = *(_DWORD *)(this + 8);
    v21 = *(_DWORD **)(v20 + 20);
    v22 = *(_DWORD *)(v20 + 16);
    a6 = v21;
    v131 = v22;
    do
    {
      v23 = *(_DWORD *)(*(_DWORD *)(v131 + 4 * *(_DWORD *)(a6[a4[v19]] + 4)) + 4);
      v134 |= v23;
      v18 &= v23;
      ++v19;
    }
    while ( v19 < a5 );
  }
  v9 = HIDWORD(a3);
  v130 = ((v134 >> 7) & 1) == 0;
  v131 = v18 & 2;
  v24 = v18 & 0x40;
  v129 = v24;
  a6 = (_DWORD *)(v18 & 0x400);
  if ( (v134 & 0x100000) != 0 )
  {
    if ( v137 < *(_DWORD *)(this + 104) || v136 > *(_DWORD *)(this + 108) )
    {
      a6 = 0;
LABEL_44:
      *(_DWORD *)(this + 96) = 1;
    }
  }
  else if ( !a6 && (*(_BYTE *)(*(_DWORD *)(this + 8) + 113) & 2) == 0 )
  {
    goto LABEL_44;
  }
  if ( v137 + 1 == v136 )
  {
    v26 = &a4[HIDWORD(a3) * v137];
LABEL_65:
    v25 = (unsigned int *)a3;
    goto LABEL_40;
  }
  v27 = HIDWORD(a3);
  v135 = v24;
  v134 = v24;
  v132 = HIDWORD(a3);
  if ( HIDWORD(a3) < a5 )
  {
    v133 = a4;
    do
    {
      if ( !v135 && !v134 )
        goto LABEL_61;
      v28 = *(_DWORD *)(*(_DWORD *)(this + 8) + 20);
      v29 = *(_DWORD **)(v28 + 4 * *v133);
      v30 = *(_DWORD **)(v28 + 4 * a4[v27]);
      if ( v29[1] == v30[1] && v29[2] == v30[2] )
      {
        if ( v29[3] != v30[3] )
          v135 = 0;
        if ( v29[4] == v30[4] )
          goto LABEL_59;
      }
      else
      {
        v135 = 0;
      }
      v134 = 0;
LABEL_59:
      ++v133;
      v27 = ++v132;
    }
    while ( v132 < a5 );
  }
  if ( !v134 )
LABEL_61:
    a6 = 0;
  if ( v135 && v134 )
  {
    v26 = a4;
    goto LABEL_65;
  }
  if ( !a6 )
    goto LABEL_76;
  if ( !v135 )
  {
    v31 = *(_DWORD *)(this + 8);
    v32 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v31 + 20) + 4 * a4[HIDWORD(a3)]) + 12)
        - *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v31 + 20) + 4 * *a4) + 12);
    v9 = HIDWORD(a3);
    v134 = 1;
    if ( HIDWORD(a3) > 1 )
    {
      v33 = *(_DWORD *)(v31 + 20);
      v133 = &a4[HIDWORD(a3) + 1];
      while ( v32 == *(_DWORD *)(*(_DWORD *)(v33 + 4 * *v133) + 12) - *(_DWORD *)(*(_DWORD *)(v33 + 4 * a4[v134]) + 12) )
      {
        ++v134;
        ++v133;
        if ( v134 >= HIDWORD(a3) )
          goto LABEL_74;
      }
      a6 = 0;
LABEL_74:
      v9 = HIDWORD(a3);
    }
  }
  if ( !a6 )
LABEL_76:
    v131 = 0;
  if ( a8 && !v131 )
  {
    if ( !*(_DWORD *)(this + 88) || !*(_DWORD *)(this + 68) )
      sub_663C07((_DWORD *)this, a2, 3500, "array reference cannot be used as an l-value; not natively addressable");
    return -2147467259;
  }
  if ( a6 )
  {
    v34 = 1;
    if ( a5 > v9 )
      v34 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * a4[v9]) + 12)
          - *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * *a4) + 12);
    a5 = *(_DWORD *)a7;
    if ( v34 != 1 || (*(_BYTE *)(*(_DWORD *)(this + 8) + 111) & 1) == 0 )
    {
      v35 = *(_DWORD *)(this + 8);
      a7 = v34;
      a8 = sub_681AAA(*(_DWORD *)(v35 + 120), 0, 0, (double)(unsigned int)v34);
      if ( a8 == -1 )
        return -2147024882;
      v126 = -1;
      v127 = NAN;
      v128 = NAN;
      if ( (**(_BYTE **)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * a5) & 2) == 0 )
      {
        result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 270532609, (int)&v126, &a5, 0x400000000LL);
        if ( result < 0 )
          return result;
        result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 272629761, (int)&v127, &v126, 0x400000000LL);
        if ( result < 0 )
          return result;
        result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 269484033, (int)&v127 + 4, &v127, 0x800000000LL);
        if ( result < 0 )
          return result;
        HIDWORD(X) = 6;
        LODWORD(X) = &v126;
        result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 541065217, (int)&v128, (_DWORD *)&v127 + 1, X);
        if ( result < 0 )
          return result;
        a5 = LODWORD(v128);
      }
      HIDWORD(Xa) = 2;
      LODWORD(Xa) = &a8;
      result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 542113793, (int)&v128 + 4, &a5, Xa);
      if ( result < 0 )
        return result;
      a5 = HIDWORD(v128);
    }
    v36 = *(_DWORD *)(this + 8);
    a7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v36 + 20) + 4 * *a4) + 8);
    if ( a7 == -1 )
    {
LABEL_105:
      if ( *(_DWORD *)(*(_DWORD *)(this + 8) + 48) )
      {
        a8 = -1;
        result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 268435457, (int)&a8, &a5, 0x400000000LL);
        if ( result < 0 )
          return result;
        v37 = *(_DWORD *)(this + 8);
        a5 = a8;
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v37 + 20) + 4 * a8) + 4) = *(_DWORD *)(v37 + 140);
      }
      a8 = 0;
      if ( !HIDWORD(a3) )
        return 0;
      v38 = a3 - (_DWORD)a4;
      v138 = a4;
      v139 = a3 - (_DWORD)a4;
      while ( 1 )
      {
        v39 = sub_681AAA(*(_DWORD *)(*(_DWORD *)(this + 8) + 136), 0, 0, 0.0);
        *(unsigned int *)((char *)v138 + v38) = v39;
        if ( v39 == -1 )
          break;
        v40 = *(_DWORD *)(*(_DWORD *)(this + 8) + 20);
        v41 = *(_DWORD *)(v40 + 4 * v39);
        sub_6815D6(*(_DWORD *)(v40 + 4 * *v138));
        *(_DWORD *)(v41 + 52) = -1;
        v42 = v136;
        v43 = v137 < v136;
        *(_DWORD *)(v41 + 8) = a5;
        *(_DWORD *)v41 = 31;
        *(double *)(v41 + 32) = *(double *)(this + 160);
        *(double *)(v41 + 40) = *(double *)(this + 168);
        if ( v43 )
        {
          v44 = v42 - v137;
          v45 = &a4[a8 + HIDWORD(a3) * v137];
          do
          {
            v46 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * *v45);
            *(_DWORD *)v41 &= *(_DWORD *)v46;
            if ( (*(_BYTE *)(v46 + 1) & 1) != 0 )
            {
              if ( *(double *)(v41 + 32) > *(double *)(v46 + 32) )
                *(double *)(v41 + 32) = *(double *)(v46 + 32);
              if ( *(double *)(v41 + 40) < *(double *)(v46 + 40) )
                *(double *)(v41 + 40) = *(double *)(v46 + 40);
            }
            v45 += HIDWORD(a3);
            --v44;
          }
          while ( v44 );
          v38 = v139;
        }
        if ( *(double *)(v41 + 32) <= *(double *)(v41 + 40) )
          *(_BYTE *)(v41 + 1) |= 1u;
        if ( *(double *)(v41 + 32) == *(double *)(v41 + 40) )
          *(_BYTE *)v41 |= 0x80u;
        ++a8;
        ++v138;
        if ( a8 >= HIDWORD(a3) )
          return 0;
      }
      return -2147024882;
    }
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v36 + 20) + 4 * a7) + 4) = *(_DWORD *)(v36 + 136);
    v126 = -1;
    v127 = NAN;
    v128 = NAN;
    if ( (**(_BYTE **)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * a7) & 2) != 0 )
    {
LABEL_103:
      result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 541065217, (int)&v128 + 4, &a7, (unsigned int)&a5);
      if ( result < 0 )
        return result;
      a5 = HIDWORD(v128);
      goto LABEL_105;
    }
    result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 270532609, (int)&v126, &a7, 0x400000000LL);
    if ( result >= 0 )
    {
      result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 272629761, (int)&v127, &v126, 0x400000000LL);
      if ( result >= 0 )
      {
        result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 269484033, (int)&v127 + 4, &v127, 0x800000000LL);
        if ( result >= 0 )
        {
          HIDWORD(Xb) = 6;
          LODWORD(Xb) = &v126;
          result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 541065217, (int)&v128, (_DWORD *)&v127 + 1, Xb);
          if ( result >= 0 )
          {
            a7 = LODWORD(v128);
            goto LABEL_103;
          }
        }
      }
    }
    return result;
  }
  if ( !v130 )
  {
    if ( *(_DWORD *)(this + 88) )
      *(_DWORD *)(this + 96) = 1;
    else
      sub_663C07((_DWORD *)this, a2, 3512, "sampler array index must be a literal expression");
    return -2147467259;
  }
  v47 = *(_DWORD *)(this + 8);
  if ( (**(_BYTE **)(*(_DWORD *)(v47 + 20) + 4 * *(_DWORD *)a7) & 1) == 0 )
  {
    v51 = v136 - v137;
    a5 = v136 - v137;
    if ( v136 - v137 > 4 || (HIDWORD(a3) != 1 || v129) && (HIDWORD(a3) > 4 || !v135) )
    {
      if ( *(_DWORD *)(this + 88) )
        *(_DWORD *)(this + 96) = 1;
      v79 = sub_6623AF(this, 2 * (v51 + HIDWORD(a3) + 2 * v51) + 4);
      if ( !v79 )
        return -2147024882;
      result = sub_6624CC(v79, 2 * (v51 + HIDWORD(a3) + 2 * v51) + 4);
      if ( result < 0 )
        return result;
      v81 = v80;
      for ( i = 0; i < 4; ++i )
        *(&v114 + i) = (int)v81++;
      v83 = 4;
      v84 = 4 * v51;
      do
      {
        *(&v114 + v83) = (int)v81;
        v81 = (_DWORD *)((char *)v81 + v84);
        ++v83;
      }
      while ( v83 < 0xA );
      for ( j = 10; j < 0xC; ++j )
      {
        *(&v114 + j) = (int)v81;
        v81 += HIDWORD(a3);
      }
      v86 = *(_DWORD *)a7;
      v87 = *(_DWORD *)(this + 8);
      a8 = v86;
      if ( (**(_BYTE **)(*(_DWORD *)(v87 + 20) + 4 * v86) & 2) == 0 )
      {
        result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 270532609, v114, &a8, 0x400000000LL);
        if ( result < 0 )
          return result;
        result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 272629761, (int)v115, (_DWORD *)v114, 0x400000000LL);
        if ( result < 0 )
          return result;
        result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 269484033, (int)v116, v115, 0x800000000LL);
        if ( result < 0 )
          return result;
        result = sub_6641F3(
                   (_DWORD *)this,
                   (unsigned int)a2,
                   541065217,
                   (int)v117,
                   v116,
                   (unsigned int)v114 | 0x600000000LL);
        if ( result < 0 )
          return result;
        v86 = *v117;
        a8 = *v117;
      }
      v88 = *(_DWORD *)(this + 8);
      if ( (*(_BYTE *)(v88 + 113) & 2) != 0 && a5 <= 4 )
      {
        if ( v137 )
        {
          a7 = v137;
          a6 = (_DWORD *)sub_681AAA(*(_DWORD *)(v88 + 120), 0, 0, -(double)v137);
          if ( a6 == (_DWORD *)-1 )
            return -2147024882;
          a7 = -1;
          HIDWORD(Xd) = 4;
          LODWORD(Xd) = &a6;
          result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 541065217, (int)&a7, &a8, Xd);
          if ( result < 0 )
            return result;
          a8 = a7;
        }
        if ( *(_DWORD *)(*(_DWORD *)(this + 8) + 48) )
        {
          a7 = -1;
          result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 268435457, (int)&a7, &a8, 0x400000000LL);
          if ( result < 0 )
            return result;
          v89 = *(_DWORD *)(this + 8);
          a8 = a7;
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v89 + 20) + 4 * a7) + 4) = *(_DWORD *)(v89 + 140);
        }
        if ( *(_DWORD *)(this + 72) == -1 )
        {
          v90 = sub_681A51("l", 1873, 4, 4);
          *(_DWORD *)(this + 72) = v90;
          if ( v90 != -1 )
          {
            v91 = 0;
LABEL_228:
            v92 = 0;
            while ( 1 )
            {
              v93 = v91 == v92 ? 1.0 : 0.0;
              if ( sub_681AAA(*(_DWORD *)(this + 72), v91, v92, v93) == -1 )
                break;
              if ( (unsigned int)++v92 >= 4 )
              {
                if ( (unsigned int)++v91 < 4 )
                  goto LABEL_228;
                goto LABEL_235;
              }
            }
          }
          return -2147024882;
        }
LABEL_235:
        v94 = 0;
        if ( a5 )
        {
          do
          {
            v95 = sub_681AAA(*(_DWORD *)(this + 72), 0, v94, 0.0);
            *(_DWORD *)(v123 + 4 * v94) = v95;
            if ( v95 == -1 )
              return -2147024882;
            v96 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * v95);
            v97 = a8;
            *(double *)(v96 + 32) = 0.0;
            v43 = ++v94 < a5;
            *(double *)(v96 + 40) = 1.0;
            *(_DWORD *)(v96 + 8) = v97;
            *(_DWORD *)v96 = 279;
          }
          while ( v43 );
        }
      }
      else
      {
        v98 = v119;
        v99 = 0;
        if ( a5 )
        {
          a7 = v118 - (char *)v119;
          while ( 1 )
          {
            *(int *)((char *)v98 + a7) = v86;
            v100 = *(_DWORD *)(this + 8);
            a6 = (_DWORD *)(v99 + v137);
            v101 = sub_681AAA(*(_DWORD *)(v100 + 120), 0, 0, -(double)(v99 + v137));
            *v98 = v101;
            if ( v101 == -1 )
              return -2147024882;
            ++v99;
            ++v98;
            if ( v99 >= a5 )
              break;
            v86 = a8;
          }
        }
        v102 = a5 & 0xFFFFF;
        result = sub_6641F3(
                   (_DWORD *)this,
                   (unsigned int)a2,
                   a5 & 0xFFFFF | 0x20400000,
                   v120,
                   v118,
                   (unsigned int)v119 | 0x200000000LL);
        if ( result < 0 )
          return result;
        result = sub_666C0F((_DWORD *)this, (unsigned int)a2, (void *)v121, v122, v120, a5);
        if ( result < 0 )
          return result;
        result = sub_6641F3((_DWORD *)this, (unsigned int)a2, v102 | 0x20300000, v123, v122, v121 | 0x1700000000LL);
        if ( result < 0 )
          return result;
      }
      for ( k = 0; k < HIDWORD(a3); ++k )
        *(_DWORD *)(a3 + 4 * k) = *(_DWORD *)(this + 36);
      a6 = 0;
      if ( !a5 )
        return 0;
      a7 = v123;
      v140 = (char *)&a4[HIDWORD(a3) * v137];
      while ( 1 )
      {
        v104 = HIDWORD(a3);
        if ( HIDWORD(a3) )
        {
          v105 = (_DWORD *)a3;
          v106 = (char *)v124 - a3;
          v107 = &v125[-a3];
          do
          {
            *(_DWORD *)((char *)v105 + (_DWORD)v106) = *(_DWORD *)a7;
            *(_DWORD *)((char *)v105 + (_DWORD)v107) = *v105;
            ++v105;
            --v104;
          }
          while ( v104 );
        }
        result = sub_6624CC((void *)a3, SHIDWORD(a3));
        if ( result < 0 )
          break;
        v108 = *(_DWORD *)(*(_DWORD *)(this + 8) + 108);
        if ( (v108 & 0x80u) == 0 || (v108 & 4) != 0 )
        {
          result = sub_6641F3(
                     (_DWORD *)this,
                     (unsigned int)a2,
                     HIDWORD(a3) & 0xFFFFF | 0x20500000,
                     a3,
                     v124,
                     (unsigned int)v140);
          if ( result < 0 )
            return result;
          result = sub_6641F3(
                     (_DWORD *)this,
                     (unsigned int)a2,
                     HIDWORD(a3) & 0xFFFFF | 0x20400000,
                     a3,
                     (_DWORD *)a3,
                     (unsigned int)v125);
        }
        else
        {
          result = sub_666305((_DWORD *)this, (unsigned int)a2, (void *)a3, v125, v140, v124, HIDWORD(a3));
        }
        if ( result < 0 )
          break;
        a6 = (_DWORD *)((char *)a6 + 1);
        a7 += 4;
        v140 += 4 * HIDWORD(a3);
        if ( (unsigned int)a6 >= a5 )
          return 0;
      }
      return result;
    }
    if ( *(_DWORD *)(this + 88) && (HIDWORD(a3) > 1 || (*(_BYTE *)(v47 + 113) & 2) == 0) )
      *(_DWORD *)(this + 96) = 1;
    v52 = sub_6623AF(this, 7 * v51 + 4);
    if ( !v52 )
      return -2147024882;
    result = sub_6624CC(v52, 7 * v51 + 4);
    if ( result < 0 )
      return result;
    v54 = v53;
    for ( m = 0; m < 4; ++m )
      *(&v114 + m) = (int)v54++;
    v56 = 4;
    v57 = 4 * v51;
    do
    {
      *(&v114 + v56) = (int)v54;
      v54 = (_DWORD *)((char *)v54 + v57);
      ++v56;
    }
    while ( v56 < 0xB );
    v58 = *(_DWORD *)a7;
    v59 = *(_DWORD *)(this + 8);
    a8 = v58;
    if ( (**(_BYTE **)(*(_DWORD *)(v59 + 20) + 4 * v58) & 2) == 0
      && ((*(_BYTE *)(v59 + 113) & 2) == 0 || (*(_BYTE *)(v59 + 111) & 1) == 0) )
    {
      result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 270532609, v114, &a8, 0x400000000LL);
      if ( result < 0 )
        return result;
      result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 272629761, (int)v115, (_DWORD *)v114, 0x400000000LL);
      if ( result < 0 )
        return result;
      result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 269484033, (int)v116, v115, 0x800000000LL);
      if ( result < 0 )
        return result;
      result = sub_6641F3(
                 (_DWORD *)this,
                 (unsigned int)a2,
                 541065217,
                 (int)v117,
                 v116,
                 (unsigned int)v114 | 0x600000000LL);
      if ( result < 0 )
        return result;
      v58 = *v117;
      a8 = *v117;
    }
    v60 = *(_DWORD *)(this + 8);
    if ( (*(_BYTE *)(v60 + 113) & 2) != 0 )
    {
      if ( v137 )
      {
        a7 = v137;
        a6 = (_DWORD *)sub_681AAA(*(_DWORD *)(v60 + 120), 0, 0, -(double)v137);
        if ( a6 == (_DWORD *)-1 )
          return -2147024882;
        a7 = -1;
        HIDWORD(Xc) = 4;
        LODWORD(Xc) = &a6;
        result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 541065217, (int)&a7, &a8, Xc);
        if ( result < 0 )
          return result;
        a8 = a7;
      }
      if ( *(_DWORD *)(*(_DWORD *)(this + 8) + 48) )
      {
        a7 = -1;
        result = sub_6641F3((_DWORD *)this, (unsigned int)a2, 268435457, (int)&a7, &a8, 0x400000000LL);
        if ( result < 0 )
          return result;
        v61 = *(_DWORD *)(this + 8);
        a8 = a7;
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v61 + 20) + 4 * a7) + 4) = *(_DWORD *)(v61 + 140);
      }
      if ( *(_DWORD *)(this + 72) == -1 )
      {
        v62 = sub_681A51("l", 1873, 4, 4);
        *(_DWORD *)(this + 72) = v62;
        if ( v62 != -1 )
        {
          v63 = 0;
LABEL_172:
          v64 = 0;
          while ( 1 )
          {
            v65 = v63 == v64 ? 1.0 : 0.0;
            if ( sub_681AAA(*(_DWORD *)(this + 72), v63, v64, v65) == -1 )
              break;
            if ( (unsigned int)++v64 >= 4 )
            {
              if ( (unsigned int)++v63 < 4 )
                goto LABEL_172;
              goto LABEL_179;
            }
          }
        }
        return -2147024882;
      }
LABEL_179:
      v66 = 0;
      if ( a5 )
      {
        do
        {
          v67 = sub_681AAA(*(_DWORD *)(this + 72), 0, v66, 0.0);
          *(_DWORD *)(v123 + 4 * v66) = v67;
          if ( v67 == -1 )
            return -2147024882;
          v68 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * v67);
          v69 = a8;
          *(double *)(v68 + 32) = 0.0;
          v43 = ++v66 < a5;
          *(double *)(v68 + 40) = 1.0;
          *(_DWORD *)(v68 + 8) = v69;
          *(_DWORD *)v68 = 279;
        }
        while ( v43 );
      }
    }
    else
    {
      v70 = v119;
      v71 = 0;
      if ( a5 )
      {
        a7 = v118 - (char *)v119;
        while ( 1 )
        {
          *(int *)((char *)v70 + a7) = v58;
          v72 = *(_DWORD *)(this + 8);
          a6 = (_DWORD *)(v71 + v137);
          v73 = sub_681AAA(*(_DWORD *)(v72 + 120), 0, 0, -(double)(v71 + v137));
          *v70 = v73;
          if ( v73 == -1 )
            return -2147024882;
          ++v71;
          ++v70;
          if ( v71 >= a5 )
            break;
          v58 = a8;
        }
      }
      v74 = a5 & 0xFFFFF;
      result = sub_6641F3(
                 (_DWORD *)this,
                 (unsigned int)a2,
                 a5 & 0xFFFFF | 0x20400000,
                 v120,
                 v118,
                 (unsigned int)v119 | 0x200000000LL);
      if ( result < 0 )
        return result;
      result = sub_666C0F((_DWORD *)this, (unsigned int)a2, (void *)v121, v122, v120, a5);
      if ( result < 0 )
        return result;
      result = sub_6641F3((_DWORD *)this, (unsigned int)a2, v74 | 0x20300000, v123, v122, v121 | 0x1700000000LL);
      if ( result < 0 )
        return result;
    }
    result = sub_6624CC((void *)a3, SHIDWORD(a3));
    if ( result < 0 )
      return result;
    a7 = 0;
    if ( !HIDWORD(a3) )
      return 0;
    v75 = v124;
    v76 = a5 & 0xFFFFF | 0x50000000;
    while ( 1 )
    {
      v77 = 0;
      if ( a5 )
      {
        v78 = &a4[a7 + HIDWORD(a3) * v137];
        do
        {
          v75[v77++] = *v78;
          v78 += HIDWORD(a3);
        }
        while ( v77 < a5 );
      }
      result = sub_6641F3((_DWORD *)this, (unsigned int)a2, v76, a3, v75, v123);
      if ( result < 0 )
        break;
      ++a7;
      LODWORD(a3) = a3 + 4;
      if ( a7 >= HIDWORD(a3) )
        return 0;
    }
    return result;
  }
  v48 = sub_6623AF(this, v9);
  if ( !v48 )
    return -2147024882;
  for ( n = 0; n < v9; ++n )
    v48[n] = *(_DWORD *)a7;
  result = sub_6624CC((void *)a3, v9);
  if ( result >= 0 )
  {
    result = sub_666305((_DWORD *)this, (unsigned int)a2, (void *)a3, (char *)a4, (char *)&a4[v9], v50, v9);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
