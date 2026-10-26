int __usercall sub_6AF40D@<eax>(int a1@<ecx>, int a2@<esi>)
{
  int *v4; // eax
  int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // esi
  BOOL v8; // ecx
  _DWORD *v9; // edi
  bool v10; // zf
  int v11; // eax
  unsigned int v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  _DWORD *v16; // eax
  int v17; // edi
  int v18; // esi
  int v19; // eax
  int v20; // ecx
  _DWORD *v21; // eax
  BOOL v22; // eax
  unsigned int v23; // esi
  char *v24; // edi
  int v25; // edi
  char *v26; // edi
  unsigned int v27; // esi
  _DWORD *v28; // eax
  unsigned int v29; // ecx
  int v30; // edx
  int v31; // esi
  int v32; // ecx
  _DWORD *v33; // eax
  unsigned int v34; // esi
  int v35; // edi
  unsigned int v36; // eax
  unsigned int i; // edi
  int v38; // eax
  _DWORD *v39; // eax
  void **v40; // edx
  unsigned int n; // esi
  unsigned int v42; // eax
  _DWORD *v43; // edi
  unsigned int v44; // esi
  unsigned int v45; // ecx
  _DWORD *v46; // edi
  int v47; // eax
  int v48; // eax
  int v49; // eax
  unsigned int j; // eax
  unsigned int m; // esi
  int v52; // ecx
  unsigned int v53; // edi
  int v54; // edx
  int v55; // esi
  int v56; // ecx
  _DWORD *v57; // edx
  _DWORD *v58; // edi
  _DWORD *v59; // eax
  char *v60; // edi
  _DWORD *v61; // eax
  char *v62; // esi
  int v63; // eax
  int v64; // ecx
  int v65; // edx
  int v66; // eax
  unsigned int v67; // edx
  _DWORD *v68; // eax
  char *v69; // esi
  unsigned int v70; // eax
  unsigned int v71; // edi
  int v72; // eax
  unsigned int v73; // [esp+0h] [ebp-E8h]
  unsigned int v74; // [esp+4h] [ebp-E4h]
  int v75; // [esp+8h] [ebp-E0h]
  _DWORD v77[16]; // [esp+18h] [ebp-D0h] BYREF
  _DWORD v78[4]; // [esp+58h] [ebp-90h] BYREF
  int v79; // [esp+68h] [ebp-80h] BYREF
  int v80; // [esp+6Ch] [ebp-7Ch]
  int v81; // [esp+70h] [ebp-78h]
  int v82; // [esp+74h] [ebp-74h]
  int v83; // [esp+78h] [ebp-70h] BYREF
  int v84; // [esp+7Ch] [ebp-6Ch]
  int v85; // [esp+80h] [ebp-68h]
  int v86; // [esp+84h] [ebp-64h]
  _DWORD v87[4]; // [esp+88h] [ebp-60h] BYREF
  _DWORD v88[4]; // [esp+98h] [ebp-50h] BYREF
  _DWORD v89[4]; // [esp+A8h] [ebp-40h] BYREF
  unsigned int v90; // [esp+B8h] [ebp-30h]
  void *v91; // [esp+BCh] [ebp-2Ch] BYREF
  int v92; // [esp+C0h] [ebp-28h]
  void **v93; // [esp+C4h] [ebp-24h] BYREF
  unsigned int v94; // [esp+C8h] [ebp-20h]
  int v95; // [esp+CCh] [ebp-1Ch]
  unsigned int k; // [esp+D0h] [ebp-18h]
  int v97; // [esp+D4h] [ebp-14h]
  unsigned int v98; // [esp+D8h] [ebp-10h]
  unsigned int v99; // [esp+DCh] [ebp-Ch]
  unsigned int v100; // [esp+E0h] [ebp-8h]
  int v101; // [esp+E4h] [ebp-4h]

  v91 = 0;
  v93 = 0;
  v98 = **(_DWORD **)(a1 + 256) & 0xFFF00000;
  if ( !v98 )
    return 0;
  v4 = *(int **)(a1 + 256);
  v5 = *v4;
  v6 = v4[1];
  v7 = v5 & 0xFFFFF;
  v94 = v5 & 0xFFFFF;
  v90 = v6 % (v5 & 0xFFFFFu);
  v99 = v6 / (v5 & 0xFFFFFu);
  v8 = (v5 & 0xFFF00000) == 0x50000000 || v98 == 1344274432 || v98 == 1887436800;
  v101 = 0;
  if ( v98 == 1615855616 || v98 == 1621098496 || v98 == 1626341376 || v98 == 285212672 )
  {
    v25 = sub_681C03((void *)a1, *(_DWORD **)(a1 + 256));
    if ( v25 >= 0 )
    {
      **(_DWORD **)(a1 + 256) = 0;
      goto LABEL_201;
    }
    return v25;
  }
  if ( v8 )
  {
    if ( v98 == 1344274432 || v98 == 1887436800 )
    {
      v25 = sub_681C03((void *)a1, *(_DWORD **)(a1 + 256));
      if ( v25 >= 0 )
        **(_DWORD **)(a1 + 256) = 0;
      return v25;
    }
    if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 20) + 4 * **(_DWORD **)(*(_DWORD *)(a1 + 256) + 16)) + 4) == *(_DWORD *)(a1 + 132) )
    {
      sub_686791(
        a1,
        *(_DWORD *)(*(_DWORD *)(a1 + 256) + 60),
        4817,
        "internal error: write to output with instruction other than mov");
      return -2147467259;
    }
    v100 = 0;
    if ( !v99 )
      goto LABEL_167;
    v92 = 0;
    v101 = (int)v77;
    v98 = 4 * v7;
    while ( 1 )
    {
      v57 = (_DWORD *)v101;
      v58 = (_DWORD *)v101;
      *(_DWORD *)v101 = -1;
      *++v58 = -1;
      *++v58 = -1;
      v58[1] = -1;
      if ( v7 )
      {
        v59 = (_DWORD *)(v92 + *(_DWORD *)(*(_DWORD *)(a1 + 256) + 8));
        v95 = v7;
        do
        {
          *v57++ = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 20) + 4 * *v59++) + 16);
          --v95;
        }
        while ( v95 );
      }
      v97 = 0;
      v60 = (char *)&unk_91A658;
      while ( !sub_6A323B((_DWORD *)v101, (int)v60) )
      {
        v97 += 16;
        v60 += 16;
        if ( (unsigned int)v97 >= 0x80 )
        {
          if ( (*(_BYTE *)(a1 + 108) & 2) != 0 )
          {
            v25 = sub_6AF146((_DWORD *)a1, (char **)&v93, v7, v99);
            if ( v25 < 0 )
              goto LABEL_203;
            if ( v93 )
            {
              v25 = sub_681997(a1, v93);
              if ( v25 < 0 )
                goto LABEL_203;
              v93 = 0;
            }
            v61 = (_DWORD *)sub_681186(116);
            if ( v61 )
              v62 = (char *)sub_680CEC(v61);
            else
              v62 = 0;
            if ( !v62 )
              goto LABEL_192;
            v63 = *(_DWORD *)(a1 + 8);
            v101 = 0;
            if ( v63 )
            {
              v64 = *(_DWORD *)(a1 + 20);
              v95 = v63;
              do
              {
                v65 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 16) + 4 * *(_DWORD *)(*(_DWORD *)v64 + 4)) + 4);
                if ( (v65 & 1) != 0 && (v65 & 2) != 0 && v101 < (unsigned int)(*(_DWORD *)(*(_DWORD *)v64 + 12) + 1) )
                  v101 = *(_DWORD *)(*(_DWORD *)v64 + 12) + 1;
                v64 += 4;
                --v95;
              }
              while ( v95 );
            }
            v25 = sub_6811D1(v62, 542113793, 2, 1, 0);
            if ( v25 < 0 )
              goto LABEL_203;
            v25 = sub_680D22(v62, *(_DWORD *)(a1 + 256));
            if ( v25 < 0 )
              goto LABEL_203;
            v66 = sub_681AAA((void *)a1, *(_DWORD *)(a1 + 136), v101++, 0, 0.0);
            v95 = v66;
            if ( v66 == -1 )
              goto LABEL_192;
            v67 = v98;
            **((_DWORD **)v62 + 4) = v66;
            **((_DWORD **)v62 + 2) = **(_DWORD **)(*(_DWORD *)(a1 + 256) + 8);
            *(_DWORD *)(*((_DWORD *)v62 + 2) + 4) = *(_DWORD *)(v67 + *(_DWORD *)(*(_DWORD *)(a1 + 256) + 8));
            v25 = sub_681997(a1, v62);
            if ( v25 < 0 )
              goto LABEL_203;
            k = 1;
            if ( v94 > 1 )
            {
              v98 += 4;
              while ( 1 )
              {
                v68 = (_DWORD *)sub_681186(116);
                v69 = v68 ? (char *)sub_680CEC(v68) : 0;
                if ( !v69 )
                  break;
                v25 = sub_6811D1(v69, 1882193921, 3, 1, 0);
                if ( v25 < 0 )
                  goto LABEL_203;
                v25 = sub_680D22(v69, *(_DWORD *)(a1 + 256));
                if ( v25 < 0 )
                  goto LABEL_203;
                v70 = k;
                v71 = v98;
                **((_DWORD **)v69 + 2) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 256) + 8) + 4 * k);
                *(_DWORD *)(*((_DWORD *)v69 + 2) + 4) = *(_DWORD *)(v71 + *(_DWORD *)(*(_DWORD *)(a1 + 256) + 8));
                *(_DWORD *)(*((_DWORD *)v69 + 2) + 8) = v95;
                if ( v70 == v94 - 1 )
                {
                  v72 = **(_DWORD **)(*(_DWORD *)(a1 + 256) + 16);
                }
                else
                {
                  v72 = sub_681AAA((void *)a1, *(_DWORD *)(a1 + 136), v101++, 0, 0.0);
                  v95 = v72;
                  if ( v72 == -1 )
                    break;
                }
                **((_DWORD **)v69 + 4) = v72;
                v25 = sub_681997(a1, v69);
                if ( v25 < 0 )
                  goto LABEL_203;
                ++k;
                v98 += 4;
                if ( k >= v94 )
                  return off_16C9914();
              }
LABEL_192:
              v25 = -2147024882;
              goto LABEL_203;
            }
            return off_16C9914();
          }
LABEL_167:
          v25 = sub_681C03((void *)a1, *(_DWORD **)(a1 + 256));
          if ( v25 < 0 )
            return v25;
          return off_16C9914();
        }
      }
      ++v100;
      v92 += v98;
      v101 += 16;
      if ( v100 >= v99 )
        goto LABEL_167;
    }
  }
  v100 = 0;
  if ( v99 )
  {
    v97 = 0;
    v92 = (int)v77;
    do
    {
      v9 = (_DWORD *)v92;
      v10 = v94 == 0;
      *(_DWORD *)v92 = -1;
      *++v9 = -1;
      *++v9 = -1;
      v9[1] = -1;
      if ( !v10 )
      {
        v11 = *(_DWORD *)(a1 + 256);
        v12 = *(_DWORD *)(v11 + 16);
        v13 = *(_DWORD *)(v11 + 8);
        v14 = *(_DWORD *)(a1 + 20);
        k = v12;
        v15 = 4 * v100;
        v16 = (_DWORD *)(v97 + v13);
        v98 = v94;
        do
        {
          v17 = *(_DWORD *)(*(_DWORD *)(v14 + 4 * *(_DWORD *)k) + 16);
          v18 = *(_DWORD *)(*(_DWORD *)(v14 + 4 * *v16) + 16);
          k += 4;
          ++v16;
          v10 = v98-- == 1;
          v77[v15 + v17] = v18;
        }
        while ( !v10 );
      }
      ++v100;
      v92 += 16;
      v97 += 4 * v94;
    }
    while ( v100 < v99 );
  }
  if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(a1 + 16)
                             + 4
                             * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 20)
                                                     + 4 * **(_DWORD **)(*(_DWORD *)(a1 + 256) + 16))
                                         + 4))
                 + 4)
      & 0x20) == 0 )
  {
    v100 = 0;
    if ( v99 )
    {
      v97 = (int)v77;
      do
      {
        v26 = (char *)&unk_91A658;
        v27 = 0;
        while ( !sub_6A323B((_DWORD *)v97, (int)v26) )
        {
          v27 += 16;
          v26 += 16;
          if ( v27 >= 0x80 )
          {
            v101 = 1;
            goto LABEL_46;
          }
        }
        ++v100;
        v97 += 16;
      }
      while ( v100 < v99 );
    }
    goto LABEL_46;
  }
  v19 = *(_DWORD *)(a1 + 256);
  v20 = *(_DWORD *)(a1 + 20);
  v75 = *(_DWORD *)(*(_DWORD *)(v20 + 4 * **(_DWORD **)(v19 + 16)) + 108);
  v95 = *(_DWORD *)(v20 + 4 * **(_DWORD **)(v19 + 8));
  v21 = (_DWORD *)(*(int (__thiscall **)(int, int, int))(*(_DWORD *)a1 + 84))(a1, v75, a2);
  v97 = (int)v21;
  if ( v21 != (_DWORD *)0xFFFF )
  {
    if ( v21 == (_DWORD *)11 )
    {
      v22 = sub_6A323B(v77, (int)&unk_91A698) == 0;
      v101 = v22;
    }
    else
    {
      if ( v21 != (_DWORD *)13 )
        goto LABEL_31;
      v23 = 0;
      v98 = 0;
      v24 = (char *)&unk_91A658;
      while ( !sub_6A323B(v77, (int)v24) )
      {
        v23 += 16;
        v24 += 16;
        if ( v23 >= 0x40 )
          goto LABEL_29;
      }
      v98 = 1;
LABEL_29:
      v22 = v98 == 0;
      v101 = v22;
    }
    if ( v22 )
    {
LABEL_32:
      v25 = sub_6AF2EE((_DWORD *)a1, (int)&v91, v94);
      if ( v25 < 0 )
        goto LABEL_201;
LABEL_33:
      v79 = 0;
      v80 = 0;
      v81 = 0;
      v82 = 0;
      if ( sub_6AF0F0((int)v77, &v79) || v97 == 13 && !v77[0] )
      {
        v25 = sub_6C5456(&v79, v99, v94);
        if ( v25 < 0 )
          goto LABEL_201;
        **(_DWORD **)(a1 + 256) = 0;
        if ( v91 )
        {
          v25 = sub_681997(a1, v91);
          if ( v25 < 0 )
            goto LABEL_201;
        }
        return v25;
      }
      goto LABEL_46;
    }
LABEL_31:
    if ( (*(_BYTE *)(v95 + 62) & 0x1F) == 0 )
      goto LABEL_33;
    goto LABEL_32;
  }
LABEL_46:
  v28 = *(_DWORD **)(a1 + 256);
  v29 = *v28 & 0xFFF00000;
  if ( v29 == 282066944 || v29 == 283115520 )
  {
    v30 = v28[1];
    v31 = 0;
    if ( v30 )
    {
      v32 = *(_DWORD *)(a1 + 20);
      v33 = (_DWORD *)v28[2];
      do
      {
        if ( (*(_BYTE *)(*(_DWORD *)(v32 + 4 * *v33) + 62) & 0x1F) != 0 )
          v31 = 1;
        ++v33;
        --v30;
      }
      while ( v30 );
      if ( v31 )
      {
        v34 = 0;
        if ( *(_DWORD *)(a1 + 8) )
        {
          v35 = *(_DWORD *)(a1 + 8);
          do
          {
            if ( *(_DWORD *)(a1 + 136) == *(_DWORD *)(*(_DWORD *)v32 + 4) )
            {
              v36 = *(_DWORD *)(*(_DWORD *)v32 + 12);
              if ( v36 >= v34 )
                v34 = v36 + 1;
            }
            v32 += 4;
            --v35;
          }
          while ( v35 );
        }
        for ( i = 0; i < 4; ++i )
        {
          v38 = sub_681AAA((void *)a1, *(_DWORD *)(a1 + 136), v34, i, 0.0);
          v78[i] = v38;
          if ( v38 == -1 )
            goto LABEL_67;
        }
        v39 = (_DWORD *)sub_681186(116);
        if ( v39 )
          v93 = (void **)sub_680CEC(v39);
        else
          v93 = 0;
        if ( !v93 )
        {
LABEL_67:
          v25 = -2147024882;
          goto LABEL_201;
        }
        v25 = sub_6811D1(
                (char *)v93,
                *(_DWORD *)(*(_DWORD *)(a1 + 256) + 4) & 0xFFFFF | 0x10000000,
                *(_DWORD *)(*(_DWORD *)(a1 + 256) + 4),
                *(_DWORD *)(*(_DWORD *)(a1 + 256) + 12),
                0);
        if ( v25 < 0 )
          goto LABEL_201;
        v25 = sub_680D22(v93, *(_DWORD *)(a1 + 256));
        if ( v25 < 0 )
          goto LABEL_201;
        v40 = v93;
        qmemcpy(v93[4], v78, 4 * *(_DWORD *)(*(_DWORD *)(a1 + 256) + 12));
        qmemcpy(v40[2], *(const void **)(*(_DWORD *)(a1 + 256) + 8), 4 * *(_DWORD *)(*(_DWORD *)(a1 + 256) + 4));
        qmemcpy(*(void **)(*(_DWORD *)(a1 + 256) + 8), v78, 4 * *(_DWORD *)(*(_DWORD *)(a1 + 256) + 4));
        v25 = sub_681997(a1, v40);
        if ( v25 < 0 )
          goto LABEL_201;
        v93 = 0;
      }
    }
  }
  if ( !v101 || (*(_BYTE *)(a1 + 108) & 2) == 0 )
  {
    v25 = sub_681C03((void *)a1, *(_DWORD **)(a1 + 256));
    if ( v25 < 0 )
      goto LABEL_201;
    return off_16C9914();
  }
  v101 = 0;
  v95 = 0;
  if ( v94 != 4 )
  {
    if ( v94 != 3 )
      goto LABEL_139;
    v95 = -1;
    for ( j = 0; j < 4; ++j )
    {
      if ( v77[j] == -1 )
        v95 = j;
    }
    for ( k = 0; k < 4; ++k )
    {
      if ( v101 )
        goto LABEL_135;
      for ( m = 0; m < 4; ++m )
      {
        if ( v101 )
          break;
        if ( m != k )
        {
          v52 = v95;
          if ( m != v95 && k != v95 )
          {
            v79 = -1;
            v80 = -1;
            v81 = -1;
            v82 = -1;
            v83 = 0;
            v84 = 0;
            v85 = 0;
            v86 = 0;
            v53 = 0;
            v54 = 4 * k;
            *(int *)((char *)&v79 + v54) = 0;
            *(&v79 + m) = 0;
            *(int *)((char *)&v83 + v54) = -1;
            *(&v83 + m) = -1;
            *(&v83 + v52) = -1;
            v100 = 0;
            if ( !v99 )
              goto LABEL_131;
            v97 = (int)v77;
            do
            {
              if ( v100 )
                goto LABEL_132;
              v100 = sub_6AF0F0(v97, &v79) == 0;
              v97 += 16;
              ++v53;
            }
            while ( v53 < v99 );
            if ( !v100 )
LABEL_131:
              v101 = 1;
          }
        }
LABEL_132:
        ;
      }
    }
    if ( !v101 )
      goto LABEL_139;
LABEL_135:
    v25 = sub_6C5456(&v79, v99, 3);
    if ( v25 < 0 )
      goto LABEL_201;
    v49 = sub_6C5456(&v83, v99, 3);
    goto LABEL_137;
  }
  v100 = 1;
  for ( n = 0; n < 4; ++n )
  {
    v79 = 0;
    v80 = 0;
    v81 = 0;
    v82 = 0;
    v83 = -1;
    v84 = -1;
    v85 = -1;
    v86 = -1;
    v42 = v99;
    *(&v79 + n) = -1;
    *(&v83 + n) = 0;
    v100 = 0;
    if ( !v42 )
      goto LABEL_89;
    v43 = v77;
    v98 = v42;
    do
    {
      if ( !sub_6AF0F0((int)v43, &v79) || !sub_6AF0F0((int)v43, &v79) )
        v100 = 1;
      v43 += 4;
      --v98;
    }
    while ( v98 );
    if ( !v100 )
    {
LABEL_89:
      v25 = sub_6C5456(&v79, v99, 4);
      if ( v25 < 0 )
        goto LABEL_201;
      v25 = sub_6C5456(&v83, v99, 4);
      if ( v25 < 0 )
        goto LABEL_201;
      goto LABEL_142;
    }
  }
  k = 0;
  v100 = 1;
  do
  {
    if ( !v100 )
      break;
    v44 = 0;
    v97 = 0;
    do
    {
      v45 = k;
      if ( v44 == k )
        goto LABEL_103;
      v79 = 0;
      v80 = 0;
      v81 = 0;
      v82 = 0;
      v83 = -1;
      v84 = -1;
      v85 = -1;
      v86 = -1;
      *(&v79 + k) = -1;
      *(&v79 + v44) = -1;
      v10 = v99 == 0;
      *(&v83 + v45) = 0;
      *(&v83 + v44) = 0;
      v100 = 0;
      v92 = 0;
      if ( v10 )
      {
LABEL_105:
        v101 = 1;
        break;
      }
      v46 = v77;
      v98 = v99;
      do
      {
        v90 = sub_6AF0F0((int)v46, &v79);
        v47 = sub_6AF0F0((int)v46, &v83);
        if ( v90 )
        {
          if ( v47 )
            goto LABEL_99;
        }
        else
        {
          v92 = 1;
        }
        v100 = 1;
LABEL_99:
        v46 += 4;
        --v98;
      }
      while ( v98 );
      if ( !v100 )
        goto LABEL_105;
      if ( !v92 )
      {
        v87[0] = v79;
        v87[1] = v80;
        v87[2] = v81;
        v87[3] = v82;
        memset(v88, 255, sizeof(v88));
        memset(v89, 255, sizeof(v89));
        v88[k] = 0;
        v48 = v97;
        v89[v97] = 0;
        v95 = 1;
        v44 = v48;
      }
LABEL_103:
      v97 = ++v44;
    }
    while ( v44 < 4 );
    ++k;
  }
  while ( k < 4 );
  if ( !v101 )
  {
    if ( !v95 )
      goto LABEL_139;
    v101 = 1;
    v25 = sub_6C5456(v87, v99, 4);
    if ( v25 < 0 )
      goto LABEL_201;
    v25 = sub_6C5456(v88, v99, 4);
    if ( v25 < 0 )
      goto LABEL_201;
    v49 = sub_6C5456(v89, v99, 4);
LABEL_137:
    v25 = v49;
    if ( v49 < 0 )
      goto LABEL_201;
    if ( !v101 )
    {
LABEL_139:
      v55 = 0;
      if ( v94 )
      {
        do
        {
          v56 = *(_DWORD *)(a1 + 20);
          v74 = v94;
          v73 = v99;
          v79 = -1;
          v80 = -1;
          v81 = -1;
          v82 = -1;
          *(&v79
          + *(_DWORD *)(*(_DWORD *)(v56 + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 256) + 16) + 4 * v55)) + 16)) = 0;
          v25 = sub_6C5456(&v79, v73, v74);
          if ( v25 < 0 )
            goto LABEL_201;
        }
        while ( ++v55 < v94 );
      }
    }
LABEL_142:
    if ( v91 )
    {
      v25 = sub_681997(a1, v91);
      if ( v25 < 0 )
        goto LABEL_201;
      v91 = 0;
    }
    return off_16C9914();
  }
  v25 = sub_6C5456(&v79, v99, 4);
  if ( v25 >= 0 )
  {
    v49 = sub_6C5456(&v83, v99, 4);
    goto LABEL_137;
  }
LABEL_201:
  if ( v91 )
    sub_66238F(v91, 1);
LABEL_203:
  if ( v93 )
    sub_66238F(v93, 1);
  return v25;
}
