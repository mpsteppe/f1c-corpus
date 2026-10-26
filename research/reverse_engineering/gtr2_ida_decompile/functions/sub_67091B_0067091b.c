int __thiscall sub_67091B(int this, const char *ArgList, _DWORD *a3, int a4, _DWORD *a5, int a6, int a7)
{
  _DWORD *v7; // edi
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // edx
  size_t v14; // esi
  int v15; // edx
  int v16; // esi
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  unsigned int v23; // ecx
  int v24; // eax
  int v25; // ecx
  int v26; // esi
  _DWORD *v27; // eax
  int v28; // ecx
  int v29; // eax
  unsigned int v30; // eax
  int v31; // ecx
  _DWORD *v32; // ecx
  int v33; // ecx
  int v34; // eax
  int v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // edx
  int v38; // esi
  int v39; // eax
  int v40; // ecx
  _DWORD *v41; // edx
  _DWORD *v42; // eax
  int v43; // ecx
  int v44; // eax
  int v45; // edx
  int v46; // eax
  unsigned int v47; // esi
  void *v48; // eax
  int v49; // esi
  unsigned int v50; // eax
  BOOL v51; // ecx
  unsigned int v52; // ecx
  int v53; // esi
  int v54; // edi
  int v55; // eax
  int v56; // edi
  int v57; // ecx
  unsigned int v58; // esi
  int v59; // edi
  unsigned int v60; // eax
  _DWORD *v61; // ecx
  int v62; // eax
  int v63; // edi
  int v64; // eax
  const char *v65; // eax
  unsigned int v66; // kr00_4
  int v67; // eax
  _DWORD *v68; // [esp-8h] [ebp-50h]
  _DWORD *v69; // [esp-8h] [ebp-50h]
  unsigned int v70; // [esp+0h] [ebp-48h]
  int v71; // [esp+14h] [ebp-34h]
  int v72; // [esp+14h] [ebp-34h]
  int v73; // [esp+18h] [ebp-30h]
  unsigned int v74; // [esp+18h] [ebp-30h]
  unsigned int v75; // [esp+18h] [ebp-30h]
  _DWORD *v76; // [esp+18h] [ebp-30h]
  _BYTE *v77; // [esp+1Ch] [ebp-2Ch]
  void *Block; // [esp+20h] [ebp-28h]
  int v79; // [esp+24h] [ebp-24h]
  unsigned int v80; // [esp+24h] [ebp-24h]
  _DWORD *v81; // [esp+24h] [ebp-24h]
  unsigned int k; // [esp+24h] [ebp-24h]
  _DWORD *v83; // [esp+28h] [ebp-20h]
  _DWORD *v84; // [esp+2Ch] [ebp-1Ch]
  int v85; // [esp+30h] [ebp-18h]
  unsigned int v86; // [esp+30h] [ebp-18h]
  int v87; // [esp+30h] [ebp-18h]
  int v88; // [esp+30h] [ebp-18h]
  int v89; // [esp+34h] [ebp-14h]
  unsigned int j; // [esp+34h] [ebp-14h]
  int v91; // [esp+34h] [ebp-14h]
  int *v92; // [esp+38h] [ebp-10h]
  int v93; // [esp+3Ch] [ebp-Ch]
  _DWORD *v94; // [esp+3Ch] [ebp-Ch]
  int v95; // [esp+3Ch] [ebp-Ch]
  unsigned int v96; // [esp+40h] [ebp-8h]
  int v97; // [esp+44h] [ebp-4h]
  unsigned int i; // [esp+44h] [ebp-4h]
  unsigned int m; // [esp+54h] [ebp+Ch]
  _DWORD *v100; // [esp+54h] [ebp+Ch]
  int v101; // [esp+54h] [ebp+Ch]
  int v102; // [esp+58h] [ebp+10h]
  int v103; // [esp+58h] [ebp+10h]
  int v104; // [esp+58h] [ebp+10h]
  int v105; // [esp+58h] [ebp+10h]
  int v106; // [esp+58h] [ebp+10h]
  int v107; // [esp+58h] [ebp+10h]
  unsigned int v108; // [esp+5Ch] [ebp+14h]
  int v109; // [esp+5Ch] [ebp+14h]

  v7 = a3;
  Block = 0;
  v84 = 0;
  v77 = 0;
  v83 = 0;
  v92 = 0;
  v96 = 0;
  if ( !a3 || a3[1] != 10 )
    return -2147467259;
  if ( a3[14] )
  {
    sub_663C07((_DWORD *)this, a3, 3500, "'%s': recursive functions not yet implemented", ArgList);
    return -2147467263;
  }
  if ( a6 )
  {
    v97 = sub_682468(ArgList);
    if ( v97 < 0 )
      goto LABEL_137;
  }
  if ( a4 )
    v79 = *(_DWORD *)(a4 + 8);
  else
    v79 = 0;
  if ( a4 )
    v71 = *(_DWORD *)(a4 + 12);
  else
    v71 = 0;
  v10 = a3[9];
  v11 = 0;
  while ( v10 )
  {
    v12 = *(_DWORD *)(v10 + 8);
    v10 = *(_DWORD *)(v10 + 12);
    v102 = v12;
    if ( v10 )
    {
      v13 = *(_DWORD *)(v10 + 8);
      if ( v13 )
      {
        if ( *(_DWORD *)(v13 + 4) == 12 )
          v10 = *(_DWORD *)(v10 + 12);
      }
    }
    v11 += *(_DWORD *)(*(_DWORD *)(v102 + 24) + 20);
  }
  v14 = 4 * v11;
  v84 = operator new(4 * v11);
  if ( !v84 )
    goto LABEL_182;
  if ( a6 )
  {
    v92 = (int *)operator new(v14);
    if ( !v92 )
      goto LABEL_182;
  }
  v15 = v79;
  v16 = a3[9];
  v17 = (int)v84;
  v103 = v79;
  while ( 1 )
  {
    v93 = v17;
    if ( !v16 )
      break;
    v18 = *(_DWORD *)(v16 + 8);
    v16 = *(_DWORD *)(v16 + 12);
    if ( v16 )
    {
      v19 = *(_DWORD *)(v16 + 8);
      if ( v19 )
      {
        if ( *(_DWORD *)(v19 + 4) == 12 )
          v16 = *(_DWORD *)(v16 + 12);
      }
    }
    v20 = *(_DWORD *)(v18 + 24);
    v73 = v20;
    if ( (!a6 || a7 && (*(_BYTE *)(v20 + 28) & 0x40) != 0) && v15 )
    {
      v21 = *(_DWORD *)(v15 + 8);
      if ( v21 )
      {
        v97 = sub_6714D6(v21, v93, 0);
        if ( v97 < 0 )
          goto LABEL_137;
        v20 = v73;
        v15 = v103;
      }
      v15 = *(_DWORD *)(v15 + 12);
      v103 = v15;
    }
    v17 = v93 + 4 * *(_DWORD *)(v20 + 20);
  }
  v22 = a3[9];
  v104 = v79;
  v94 = v84;
  if ( v22 )
  {
    while ( 1 )
    {
      v23 = *(_DWORD *)(v22 + 8);
      v24 = *(_DWORD *)(v22 + 12);
      v74 = 0;
      v80 = v23;
      v85 = v24;
      if ( v24 )
      {
        v25 = *(_DWORD *)(v24 + 8);
        if ( v25 )
        {
          if ( *(_DWORD *)(v25 + 4) == 12 )
          {
            v74 = *(_DWORD *)(v24 + 8);
            v85 = *(_DWORD *)(v24 + 12);
          }
        }
      }
      v26 = *(_DWORD *)(v80 + 24);
      if ( a6 )
      {
        if ( !a7 || (*(_BYTE *)(v26 + 28) & 0x40) == 0 )
          break;
      }
      v97 = sub_67051D(this, v80, 0);
      if ( v97 < 0 )
        goto LABEL_137;
      if ( !v104 )
      {
        v35 = sub_67051D(this, v74, 0);
LABEL_79:
        v97 = v35;
        if ( v35 < 0 )
          goto LABEL_137;
        goto LABEL_80;
      }
      if ( (*(_BYTE *)(v26 + 28) & 0x10) != 0 )
      {
        v97 = sub_6641F3(
                (_DWORD *)this,
                *(_DWORD *)(v104 + 8),
                *(_DWORD *)(v26 + 20) & 0xFFFFF | 0x10000000,
                *(_DWORD *)(this + 24) + 4 * *(_DWORD *)(v26 + 16),
                v94,
                0);
        if ( v97 < 0 )
          goto LABEL_137;
      }
      v104 = *(_DWORD *)(v104 + 12);
LABEL_80:
      v94 += *(_DWORD *)(v26 + 20);
      if ( !v85 )
        goto LABEL_81;
      v22 = v85;
    }
    v27 = *(_DWORD **)(this + 8);
    v89 = v27[29];
    v28 = *(_DWORD *)(v26 + 28);
    if ( (v28 & 0x40) != 0 )
    {
      v29 = v27[31];
    }
    else
    {
      if ( (v28 & 0x10) == 0 )
      {
LABEL_53:
        for ( i = 0; i < *(_DWORD *)(v26 + 20); *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v75) = v30 )
        {
          v75 = i + *(_DWORD *)(v26 + 16);
          v30 = sub_681AAA(v89, 0, 0, 0.0);
          v31 = *(_DWORD *)(this + 8);
          if ( v30 >= *(_DWORD *)(v31 + 8) )
            v32 = 0;
          else
            v32 = *(_DWORD **)(*(_DWORD *)(v31 + 20) + 4 * v30);
          if ( v32 )
          {
            v32[12] = v75;
            v32[24] = v80;
            v32[25] = i;
          }
          ++i;
        }
        v33 = v89;
        if ( *(_DWORD *)(*(_DWORD *)(this + 8) + 116) != v89 )
        {
          v97 = sub_664A09(
                  (_DWORD *)this,
                  *(_DWORD **)(v26 + 32),
                  *(_DWORD *)(this + 24) + 4 * *(_DWORD *)(v26 + 16),
                  *(_DWORD *)(v26 + 20));
          if ( v97 < 0 )
            goto LABEL_137;
          v33 = v89;
        }
        v34 = *(_DWORD *)(this + 8);
        if ( *(_DWORD *)(v34 + 124) != v33 )
        {
          if ( *(_DWORD *)(v34 + 128) == v33 )
          {
            v97 = sub_666E91(
                    (_DWORD *)this,
                    *(_DWORD **)(v26 + 32),
                    (unsigned int *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(v26 + 16)),
                    v89,
                    0,
                    0,
                    *(_DWORD *)(v26 + 44),
                    *(_DWORD *)(v26 + 48));
            if ( v97 < 0 )
              goto LABEL_137;
            if ( sub_6634FA((_DWORD *)this, *(_DWORD *)(this + 24) + 4 * *(_DWORD *)(v26 + 16), *(_DWORD *)(v26 + 20)) )
            {
              for ( j = 0; j < *(_DWORD *)(v26 + 20); v92[v37] = v36 )
              {
                v36 = j + *(_DWORD *)(v26 + 16);
                v37 = v96++;
                ++j;
              }
            }
            else
            {
              sub_663C07(
                (_DWORD *)this,
                (_DWORD *)v26,
                3502,
                "'%s': input parameter '%s' missing semantics",
                ArgList,
                *(const char **)(*(_DWORD *)(v80 + 20) + 24));
            }
          }
          goto LABEL_80;
        }
        v97 = sub_666E91(
                (_DWORD *)this,
                *(_DWORD **)(v26 + 32),
                (unsigned int *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(v26 + 16)),
                v89,
                1,
                0,
                0,
                *(_DWORD *)(v26 + 48));
        if ( v97 < 0 )
          goto LABEL_137;
        v35 = sub_66264A((_DWORD *)this, v26);
        goto LABEL_79;
      }
      v29 = v27[32];
    }
    v89 = v29;
    goto LABEL_53;
  }
LABEL_81:
  if ( a6 )
  {
    v38 = 0;
    if ( v96 )
    {
      while ( (*(int (__thiscall **)(_DWORD, _DWORD, int))(**(_DWORD **)(this + 8) + 4))(
                *(_DWORD *)(this + 8),
                *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20)
                          + 4 * *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v92[v38])),
                1) >= 0 )
      {
        if ( ++v38 >= v96 )
          goto LABEL_85;
      }
LABEL_114:
      v97 = -2147467259;
      goto LABEL_137;
    }
LABEL_85:
    sub_682274(sub_663CC2, v92, v96, this);
    v105 = 0;
    if ( v96 )
    {
      v39 = *(_DWORD *)(this + 24);
      v40 = *(_DWORD *)(*(_DWORD *)(this + 8) + 20);
      v81 = *(_DWORD **)(v40 + 4 * *(_DWORD *)(v39 + 4 * *v92));
      v86 = 1;
      if ( v96 > 1 )
      {
        do
        {
          v41 = *(_DWORD **)(v40 + 4 * *(_DWORD *)(v39 + 4 * v92[v86]));
          if ( v81[27] == v41[27] && v81[4] == v41[4] && *v81 == *v41 )
            ++v105;
          else
            v81 = *(_DWORD **)(v40 + 4 * *(_DWORD *)(v39 + 4 * v92[v86]));
          ++v86;
        }
        while ( v86 < v96 );
        if ( v105 )
        {
          v77 = operator new(4 * v105);
          if ( !v77 )
            goto LABEL_182;
          v42 = operator new(4 * v105);
          v83 = v42;
          if ( !v42 )
            goto LABEL_182;
          v43 = *v92;
          v87 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * *v92));
          v76 = v42;
          v44 = 0;
          v106 = 0;
          for ( k = 1; k < v96; ++k )
          {
            v91 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v92[k]);
            v45 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * v91);
            if ( *(_DWORD *)(v87 + 108) == *(_DWORD *)(v45 + 108) && *(_DWORD *)(v87 + 16) == *(_DWORD *)(v45 + 16) )
            {
              *(_DWORD *)((char *)v76 + v77 - (_BYTE *)v83) = v91;
              *v76 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v43);
              v44 = ++v106;
              ++v76;
            }
            else
            {
              v43 = v92[k];
              v87 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20) + 4 * v91);
            }
          }
          v97 = sub_6641F3((_DWORD *)this, (unsigned int)a3, v44 & 0xFFFFF | 0x10000000, (int)v77, v83, 0);
          if ( v97 < 0 )
            goto LABEL_137;
        }
      }
    }
  }
  v46 = *(_DWORD *)(*(_DWORD *)(this + 4) + 24);
  if ( !a6 )
    goto LABEL_106;
  v47 = 4 * v46;
  v48 = operator new(4 * v46);
  Block = v48;
  if ( !v48 )
  {
LABEL_182:
    v97 = -2147024882;
    goto LABEL_137;
  }
  qmemcpy(v48, *(const void **)(this + 24), v47);
  v7 = a3;
LABEL_106:
  v49 = *(_DWORD *)(this + 80);
  *(_DWORD *)(this + 80) = 0;
  v70 = v7[10];
  v7[14] = 1;
  v97 = sub_67051D(this, v70, Block);
  v50 = 0;
  v51 = *(_DWORD *)(this + 80) || *(_DWORD *)(this + 84);
  *(_DWORD *)(this + 80) = v49;
  v7[14] = 0;
  if ( v97 < 0 )
    goto LABEL_137;
  if ( !v51 && v7[5] )
  {
    sub_663C07((_DWORD *)this, v7, 3507, "'%s': function must return a value", ArgList);
    goto LABEL_114;
  }
  if ( a6 )
  {
    if ( v7[5] )
    {
      if ( *(_DWORD *)(this + 84) )
      {
        do
        {
          v52 = v50 + v7[4];
          ++v50;
          *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v52) = *(_DWORD *)(this + 36);
        }
        while ( v50 < v7[5] );
      }
      v53 = 0;
      v68 = (_DWORD *)(*(_DWORD *)(this + 24) + 4 * v7[4]);
      v97 = sub_6641F3((_DWORD *)this, (unsigned int)v7, v7[5] & 0xFFFFF | 0x10000000, (int)v68, v68, 0);
      if ( v97 < 0 )
        goto LABEL_137;
      v97 = sub_664A09((_DWORD *)this, (_DWORD *)v7[8], *(_DWORD *)(this + 24) + 4 * v7[4], v7[5]);
      if ( v97 < 0 )
        goto LABEL_137;
      v97 = sub_666E91(
              (_DWORD *)this,
              (_DWORD *)v7[8],
              (unsigned int *)(*(_DWORD *)(this + 24) + 4 * v7[4]),
              *(_DWORD *)(*(_DWORD *)(this + 8) + 132),
              0,
              1,
              v7[12],
              0);
      if ( v97 < 0 )
        goto LABEL_137;
      if ( sub_6634FA((_DWORD *)this, *(_DWORD *)(this + 24) + 4 * v7[4], v7[5]) )
      {
        if ( v7[5] )
        {
          while ( (*(int (__thiscall **)(_DWORD, _DWORD, int))(**(_DWORD **)(this + 8) + 4))(
                    *(_DWORD *)(this + 8),
                    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20)
                              + 4 * *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * (v53 + v7[4]))),
                    1) >= 0 )
          {
            if ( (unsigned int)++v53 >= v7[5] )
              goto LABEL_135;
          }
          *(_DWORD *)(this + 76) = 1;
        }
      }
      else
      {
        sub_663C07((_DWORD *)this, v7, 3503, "'%s': function return value missing semantics", ArgList);
      }
    }
  }
  else if ( a5 )
  {
    if ( *(_DWORD *)(this + 84) )
    {
      if ( v7[5] )
      {
        do
          a5[v50++] = *(_DWORD *)(this + 36);
        while ( v50 < v7[5] );
      }
    }
    else
    {
      qmemcpy(a5, (const void *)(*(_DWORD *)(this + 24) + 4 * a3[4]), 4 * a3[5]);
      v7 = a3;
    }
  }
LABEL_135:
  v54 = v7[9];
  v107 = v71;
  v95 = (int)v84;
  if ( !v54 )
  {
LABEL_136:
    v97 = 0;
    goto LABEL_137;
  }
  while ( 1 )
  {
    v55 = *(_DWORD *)(v54 + 8);
    v56 = *(_DWORD *)(v54 + 12);
    v72 = v55;
    v88 = v56;
    if ( v56 )
    {
      v57 = *(_DWORD *)(v56 + 8);
      if ( v57 )
      {
        if ( *(_DWORD *)(v57 + 4) == 12 )
          v88 = *(_DWORD *)(v56 + 12);
      }
    }
    v58 = *(_DWORD *)(v55 + 24);
    if ( (*(_BYTE *)(v58 + 28) & 0x20) == 0 )
      goto LABEL_170;
    v59 = *(_DWORD *)(v55 + 20) + 16;
    if ( !*(_DWORD *)(this + 84) )
      break;
    for ( m = 0; m < *(_DWORD *)(v58 + 20); *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v60) = *(_DWORD *)(this + 36) )
    {
      v60 = m + *(_DWORD *)(v58 + 16);
      ++m;
    }
LABEL_156:
    if ( a6 )
    {
      v69 = (_DWORD *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(v58 + 16));
      v97 = sub_6641F3((_DWORD *)this, v58, *(_DWORD *)(v58 + 20) & 0xFFFFF | 0x10000000, (int)v69, v69, 0);
      if ( v97 < 0 )
        goto LABEL_137;
      v97 = sub_664A09(
              (_DWORD *)this,
              *(_DWORD **)(v58 + 32),
              *(_DWORD *)(this + 24) + 4 * *(_DWORD *)(v58 + 16),
              *(_DWORD *)(v58 + 20));
      if ( v97 < 0 )
        goto LABEL_137;
      v97 = sub_666E91(
              (_DWORD *)this,
              *(_DWORD **)(v58 + 32),
              (unsigned int *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(v58 + 16)),
              *(_DWORD *)(*(_DWORD *)(this + 8) + 132),
              0,
              1,
              *(_DWORD *)(v58 + 44),
              0);
      if ( v97 < 0 )
        goto LABEL_137;
      if ( sub_6634FA((_DWORD *)this, *(_DWORD *)(this + 24) + 4 * *(_DWORD *)(v58 + 16), *(_DWORD *)(v58 + 20)) )
      {
        v63 = 0;
        if ( *(_DWORD *)(v58 + 20) )
        {
          while ( (*(int (__thiscall **)(_DWORD, _DWORD, int))(**(_DWORD **)(this + 8) + 4))(
                    *(_DWORD *)(this + 8),
                    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 20)
                              + 4 * *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * (v63 + *(_DWORD *)(v58 + 16)))),
                    1) >= 0 )
          {
            if ( (unsigned int)++v63 >= *(_DWORD *)(v58 + 20) )
              goto LABEL_170;
          }
          *(_DWORD *)(this + 76) = 1;
        }
      }
      else
      {
        sub_663C07(
          (_DWORD *)this,
          (_DWORD *)v58,
          3503,
          "'%s': output parameter '%s' missing semantics",
          ArgList,
          *(const char **)(v59 + 8));
      }
    }
    else
    {
      if ( !v107 )
        goto LABEL_179;
      v64 = *(_DWORD *)(v107 + 8);
      if ( !v64 )
      {
LABEL_177:
        if ( v107 )
          v107 = *(_DWORD *)(v107 + 12);
        goto LABEL_179;
      }
      v97 = sub_6714D6(v64, 0, 0);
      if ( v97 < 0 )
        goto LABEL_137;
    }
LABEL_170:
    if ( !a6 || a7 && (*(_BYTE *)(v58 + 28) & 0x40) != 0 )
      goto LABEL_177;
    if ( (*(_BYTE *)(v58 + 28) & 0x40) != 0 )
    {
      v65 = *(const char **)(*(_DWORD *)(v72 + 20) + 24);
      v109 = (int)v65;
      if ( *v65 != 36 )
      {
        v66 = strlen(v65);
        v67 = sub_67EB7E(v66 + 2, 1u);
        v101 = v67;
        if ( !v67 )
          goto LABEL_182;
        sub_632041(v67, v66 + 2, (const char *)&off_73ACB8, v109);
        *(_DWORD *)(*(_DWORD *)(v72 + 20) + 24) = v101;
      }
    }
LABEL_179:
    v95 += 4 * *(_DWORD *)(v58 + 20);
    if ( !v88 )
      goto LABEL_136;
    v54 = v88;
  }
  v108 = 0;
  if ( !*(_DWORD *)(v58 + 20) )
    goto LABEL_156;
  v61 = *(_DWORD **)(this + 8);
  v100 = (_DWORD *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(v58 + 16));
  while ( 1 )
  {
    v62 = *v100 >= v61[2] ? 0 : *(_DWORD *)(v61[5] + 4 * *v100);
    if ( v62 && v61[29] == *(_DWORD *)(v62 + 4) )
      break;
    ++v108;
    ++v100;
    if ( v108 >= *(_DWORD *)(v58 + 20) )
      goto LABEL_156;
  }
  sub_663C07(
    (_DWORD *)this,
    *(_DWORD **)(v62 + 96),
    3508,
    "'%s': output parameter '%s' never assigned a value",
    ArgList,
    *(const char **)(v59 + 8));
LABEL_137:
  j__free(Block);
  j__free(v84);
  j__free(v92);
  j__free(v77);
  j__free(v83);
  return v97;
}
