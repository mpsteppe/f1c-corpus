int __thiscall sub_6B3A58(int this, unsigned int *a2)
{
  bool v3; // zf
  int v5; // ebx
  int *v6; // edi
  int v7; // eax
  int v8; // edx
  unsigned int v9; // eax
  int v10; // eax
  size_t v11; // ebx
  unsigned int v12; // ecx
  int v13; // edx
  int v14; // eax
  size_t v15; // eax
  _DWORD *v16; // eax
  unsigned int v17; // edi
  size_t v18; // ecx
  _DWORD *v19; // eax
  unsigned int v20; // edi
  unsigned int i; // edi
  int v22; // eax
  int v23; // edx
  int v24; // ecx
  int v25; // edi
  int v26; // eax
  unsigned int v27; // ebx
  int v28; // eax
  int v29; // ecx
  _DWORD *v30; // eax
  int v31; // ecx
  unsigned int v32; // edx
  _DWORD *v33; // eax
  _DWORD *v34; // eax
  int *v35; // eax
  int v36; // eax
  int v37; // ecx
  int v38; // eax
  unsigned int v39; // ecx
  int *v40; // ecx
  unsigned int v41; // edx
  int *v42; // eax
  int v43; // eax
  void *v44; // edx
  _DWORD *v45; // eax
  char *v46; // ecx
  _DWORD *v47; // edx
  int v48; // ecx
  int v49; // eax
  unsigned int v50; // eax
  unsigned int v51; // ebx
  unsigned int j; // edi
  unsigned int k; // edi
  int v54; // eax
  unsigned int m; // edi
  unsigned int v56; // edi
  _DWORD *v57; // ebx
  unsigned int v58; // edi
  _DWORD *v59; // ebx
  unsigned int v60; // ebx
  int v61; // edi
  _DWORD *v62; // eax
  unsigned int v63; // edi
  int v64; // eax
  _DWORD *v65; // edi
  int v66; // ebx
  int v67; // eax
  _DWORD *v68; // edi
  int v69; // ebx
  int v70; // eax
  int v71; // eax
  _DWORD v72[4]; // [esp+14h] [ebp-94h]
  _DWORD *v73; // [esp+24h] [ebp-84h]
  unsigned int v74; // [esp+28h] [ebp-80h]
  unsigned int v75; // [esp+2Ch] [ebp-7Ch]
  unsigned int v76; // [esp+30h] [ebp-78h]
  int v77; // [esp+34h] [ebp-74h]
  int v78; // [esp+38h] [ebp-70h]
  int v79; // [esp+3Ch] [ebp-6Ch] BYREF
  int v80; // [esp+40h] [ebp-68h]
  int v81; // [esp+44h] [ebp-64h]
  void *v82; // [esp+48h] [ebp-60h]
  void *v83; // [esp+4Ch] [ebp-5Ch]
  void *v84; // [esp+50h] [ebp-58h]
  unsigned int v85; // [esp+54h] [ebp-54h]
  unsigned int v86; // [esp+58h] [ebp-50h]
  unsigned int v87; // [esp+5Ch] [ebp-4Ch]
  int v88; // [esp+60h] [ebp-48h]
  unsigned int v89; // [esp+64h] [ebp-44h]
  unsigned int v90; // [esp+68h] [ebp-40h]
  unsigned int v91; // [esp+6Ch] [ebp-3Ch]
  unsigned int v92; // [esp+70h] [ebp-38h]
  int v93; // [esp+74h] [ebp-34h]
  unsigned int v94; // [esp+78h] [ebp-30h]
  void *v95; // [esp+7Ch] [ebp-2Ch]
  int v96; // [esp+80h] [ebp-28h]
  unsigned int v97; // [esp+84h] [ebp-24h]
  int v98; // [esp+88h] [ebp-20h]
  unsigned int v99; // [esp+8Ch] [ebp-1Ch]
  unsigned int v100; // [esp+90h] [ebp-18h]
  unsigned int v101; // [esp+94h] [ebp-14h] BYREF
  _DWORD *v102; // [esp+98h] [ebp-10h]
  unsigned int v103; // [esp+9Ch] [ebp-Ch]
  int v104; // [esp+A0h] [ebp-8h]
  void *Block; // [esp+A4h] [ebp-4h]

  v95 = 0;
  v89 = 0;
  v90 = 0;
  v91 = 0;
  v82 = 0;
  v83 = 0;
  v3 = *(_DWORD *)(this + 12) == 0;
  v84 = 0;
  if ( v3 )
    return 1;
  v104 = sub_694A16((_DWORD *)this, a2);
  if ( v104 < 0 )
    goto LABEL_210;
  v104 = sub_6BBB22(this, *(_DWORD *)(this + 124), *(_DWORD *)(this + 56), 512, 270464, 99);
  if ( v104 < 0 )
    goto LABEL_210;
  v97 = 0;
  v100 = 0;
  v85 = -1;
  v86 = -1;
  v87 = -1;
  v88 = -1;
  v74 = 0;
  v75 = 0;
  v76 = 0;
  v77 = 0;
  if ( *(_DWORD *)(this + 8) )
  {
    v5 = *(_DWORD *)(this + 120);
    v6 = *(int **)(this + 20);
    v102 = *(_DWORD **)(this + 8);
    do
    {
      v7 = *v6;
      v8 = *(_DWORD *)(*v6 + 4);
      if ( v5 == v8 && *(_DWORD *)(v7 + 12) + 1 > v97 )
      {
        v97 = *(_DWORD *)(v7 + 12) + 1;
      }
      else if ( *(_DWORD *)(this + 136) == v8 && *(_DWORD *)(v7 + 12) + 1 > v100 )
      {
        v100 = *(_DWORD *)(v7 + 12) + 1;
      }
      if ( *(_DWORD *)(this + 132) == v8 )
      {
        if ( *(_DWORD *)(v7 + 12) > v74 )
          v74 = *(_DWORD *)(v7 + 12);
        if ( *(_DWORD *)(this + 132) == v8 && *(_DWORD *)(v7 + 12) < v85 )
          v85 = *(_DWORD *)(v7 + 12);
      }
      if ( *(_DWORD *)(this + 180) == v8 )
      {
        if ( *(_DWORD *)(v7 + 12) > v75 )
          v75 = *(_DWORD *)(v7 + 12);
        if ( *(_DWORD *)(this + 180) == v8 && *(_DWORD *)(v7 + 12) < v86 )
          v86 = *(_DWORD *)(v7 + 12);
      }
      if ( *(_DWORD *)(this + 184) == v8 )
      {
        if ( *(_DWORD *)(v7 + 12) > v76 )
          v76 = *(_DWORD *)(v7 + 12);
        if ( *(_DWORD *)(this + 184) == v8 )
        {
          v9 = *(_DWORD *)(v7 + 12);
          if ( v9 < v87 )
            v87 = v9;
        }
      }
      ++v6;
      v102 = (_DWORD *)((char *)v102 - 1);
    }
    while ( v102 );
  }
  v10 = *(_DWORD *)(this + 132);
  v99 = 0;
  v79 = v10;
  v80 = *(_DWORD *)(this + 180);
  v81 = *(_DWORD *)(this + 184);
  do
  {
    if ( *(unsigned int *)((char *)&v85 + v99) != -1 )
    {
      v11 = *(unsigned int *)((char *)&v74 + v99) - *(unsigned int *)((char *)&v85 + v99) + 1;
      Block = operator new(v11);
      if ( !Block )
        goto LABEL_75;
      memset(Block, 0, v11);
      v12 = 0;
      if ( *(_DWORD *)(this + 8) )
      {
        v13 = *(int *)((char *)&v79 + v99);
        do
        {
          v14 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v12);
          if ( v13 == *(_DWORD *)(v14 + 4) )
            *((_BYTE *)Block + *(_DWORD *)(v14 + 12) - *(unsigned int *)((char *)&v85 + v99)) = 1;
          ++v12;
        }
        while ( v12 < *(_DWORD *)(this + 8) );
      }
      v15 = 0;
      v103 = 0;
      if ( v11 )
      {
        while ( 1 )
        {
          if ( v15 < v11 )
            goto LABEL_42;
          do
          {
            ++v103;
            while ( v15 < v11 && *((_BYTE *)Block + v15) )
              ++v15;
            if ( ++v15 >= v11 )
              goto LABEL_50;
LABEL_42:
            ;
          }
          while ( *((_BYTE *)Block + v15) );
          ++v15;
        }
      }
LABEL_50:
      v16 = operator new(8 * v103);
      v17 = v99;
      *(void **)((char *)&v82 + v99) = v16;
      if ( !v16 )
      {
        j__free(Block);
        goto LABEL_75;
      }
      v18 = 0;
      if ( v11 )
      {
        while ( 1 )
        {
          if ( v18 < v11 )
            goto LABEL_53;
          do
          {
            *v16 = v18 + *(unsigned int *)((char *)&v85 + v17);
            v19 = v16 + 1;
            while ( v18 < v11 && *((_BYTE *)Block + v18) )
              ++v18;
            *v19 = v18 + *(unsigned int *)((char *)&v85 + v17) - *(v19 - 1);
            v16 = v19 + 1;
            if ( ++v18 >= v11 )
              goto LABEL_61;
LABEL_53:
            ;
          }
          while ( *((_BYTE *)Block + v18) );
          ++v18;
        }
      }
LABEL_61:
      j__free(Block);
      *(unsigned int *)((char *)&v89 + v17) = v103;
    }
    v99 += 4;
  }
  while ( v99 < 0xC );
  v20 = 32 * v97;
  v95 = operator new(32 * v97);
  if ( !v95 )
    goto LABEL_75;
  if ( v100 > 0x40 )
    goto LABEL_210;
  memset(v95, 0, v20);
  for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
  {
    v22 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * i);
    if ( *(_DWORD *)(this + 120) == *(_DWORD *)(v22 + 4) && *(_DWORD *)(v22 + 8) == -1 )
      *((double *)v95 + 4 * *(_DWORD *)(v22 + 12) + *(_DWORD *)(v22 + 16)) = *(double *)(v22 + 32);
    if ( *(_DWORD *)(this + 200) == 1415053568 )
    {
      v23 = *(_DWORD *)(v22 + 4);
      if ( *(_DWORD *)(this + 128) == v23 )
      {
        if ( *(_DWORD *)(v22 + 12) > 1u )
        {
          sub_686791(this, 0, 4500, "too many arguments to target TX");
          goto LABEL_210;
        }
        v24 = (unsigned __int8)*(_DWORD *)(v22 + 108);
        if ( v24 == 2 )
        {
          *(_DWORD *)(v22 + 12) = 0;
        }
        else if ( v24 == 3 )
        {
          *(_DWORD *)(v22 + 12) = 1;
        }
      }
      if ( *(_DWORD *)(this + 132) == v23 && *(_DWORD *)(v22 + 12) )
      {
        sub_686791(this, 0, 4500, "too many outputs to target TX");
        goto LABEL_210;
      }
    }
  }
  v92 = *(_DWORD *)(this + 12);
  v100 = 0;
  if ( v92 )
  {
    while ( 2 )
    {
      v25 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v100);
      v26 = *(_DWORD *)v25;
      v98 = 0;
      *(_DWORD *)(v25 + 40) = 0;
      v94 = v26 & 0xFFF00000;
      v27 = v26 & 0xFFFFF;
      if ( (v26 & 0xFFFFF) != 0 )
      {
        v28 = *(_DWORD *)(v25 + 4) / v27;
        v29 = *(_DWORD *)(this + 20);
        v103 = 0;
        v99 = v28;
        v3 = v28 == 0;
        v30 = *(_DWORD **)(v25 + 16);
        v78 = *(_DWORD *)(*(_DWORD *)(v29 + 4 * *v30) + 16);
        if ( !v3 )
        {
          Block = *(void **)(v25 + 8);
          do
          {
            v31 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)Block) + 16);
            v32 = v103++;
            *(&v79 + v32) = v31;
            Block = (char *)Block + 4 * v27;
          }
          while ( v103 < v99 );
        }
        if ( v27 == *(_DWORD *)(v25 + 12) && v27 > 1 )
        {
          v103 = v78 + 1;
          v33 = v30 + 1;
          v102 = (_DWORD *)(v27 - 1);
          do
          {
            if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v33) + 16) == v103 )
            {
              ++v78;
              ++v103;
            }
            else
            {
              v98 = 1;
            }
            ++v33;
            v102 = (_DWORD *)((char *)v102 - 1);
          }
          while ( v102 );
        }
        if ( v99 != 2 || v98 )
          goto LABEL_117;
        v104 = 1;
        Block = (void *)(v80 + 1);
        if ( v27 <= 1 )
          goto LABEL_116;
        v34 = *(_DWORD **)(v25 + 8);
        v93 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v34) + 16);
        v73 = v34 + 1;
        v103 = (unsigned int)(v34 + 1);
        v35 = &v34[v27];
        v96 = (int)(v35 + 1);
        v102 = v35 + 1;
        v101 = v27 - 1;
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)v103) + 16) != v93 )
            v104 = 0;
          if ( *(void **)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v102) + 16) == Block )
            Block = (char *)Block + 1;
          else
            v104 = 0;
          v103 += 4;
          ++v102;
          --v101;
        }
        while ( v101 );
        if ( v104 )
        {
LABEL_116:
          *(_DWORD *)(v25 + 40) = 1;
        }
        else
        {
          v36 = *v35;
          Block = (void *)(v79 + 1);
          v37 = *(_DWORD *)(this + 20);
          v93 = *(_DWORD *)(*(_DWORD *)(v37 + 4 * v36) + 16);
          v103 = (unsigned int)v73;
          v102 = (_DWORD *)v96;
          v104 = 1;
          v101 = v27 - 1;
          do
          {
            if ( *(_DWORD *)(*(_DWORD *)(v37 + 4 * *v102) + 16) != v93 )
              v104 = 0;
            if ( *(void **)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)v103) + 16) == Block )
              Block = (char *)Block + 1;
            else
              v104 = 0;
            ++v102;
            v103 += 4;
            --v101;
          }
          while ( v101 );
          if ( v104 )
          {
            v103 = 0;
            v101 = 4 * v27;
            do
            {
              v38 = *(_DWORD *)(v25 + 8);
              v39 = v103++;
              v40 = (int *)(v38 + 4 * v39);
              v96 = *v40;
              v41 = v101;
              *v40 = *(_DWORD *)(v101 + v38);
              *(_DWORD *)(v41 + *(_DWORD *)(v25 + 8)) = v96;
              v101 = v41 + 4;
            }
            while ( v103 < v27 );
            goto LABEL_116;
          }
LABEL_117:
          Block = (void *)1;
          if ( v27 > 1 )
          {
            do
            {
              v103 = 0;
              if ( v99 )
              {
                v102 = (_DWORD *)(*(_DWORD *)(v25 + 8) + 4 * (_DWORD)Block);
                do
                {
                  v42 = &v79 + v103;
                  v96 = *v42 + 1;
                  if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v102) + 16) == v96 )
                    *v42 = v96;
                  else
                    v98 = 1;
                  ++v103;
                  v102 += v27;
                }
                while ( v103 < v99 );
              }
              Block = (char *)Block + 1;
            }
            while ( (unsigned int)Block < v27 );
          }
          if ( v98 )
          {
            if ( v94 != 1342177280 )
            {
              if ( v94 == 1345323008 )
              {
                Block = 0;
                while ( 1 )
                {
                  if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20)
                                             + 4 * *(_DWORD *)(*(_DWORD *)(v25 + 16) + 4 * (_DWORD)Block))
                                 + 92) )
                  {
                    if ( Block )
                      v43 = sub_681B0A((void *)this, 276824065, 1, 1);
                    else
                      v43 = sub_681B0A((void *)this, 277872641, 1, 1);
                    if ( v43 == -1 )
                      goto LABEL_75;
                    v101 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v43);
                    v104 = sub_680D22((_DWORD *)v101, v25);
                    if ( v104 < 0 )
                      goto LABEL_210;
                    v44 = Block;
                    **(_DWORD **)(v101 + 16) = *(_DWORD *)(*(_DWORD *)(v25 + 16) + 4 * (_DWORD)Block);
                    **(_DWORD **)(v101 + 8) = *(_DWORD *)(*(_DWORD *)(v25 + 8) + 4 * (_DWORD)v44);
                  }
                  Block = (char *)Block + 1;
                  if ( (unsigned int)Block >= v27 )
                    goto LABEL_151;
                }
              }
              v103 = 0;
              while ( 1 )
              {
                v45 = (_DWORD *)sub_681186(116);
                Block = v45 ? sub_680CEC(v45) : 0;
                v46 = (char *)Block;
                v3 = Block == 0;
                v72[v103] = Block;
                if ( v3 )
                  break;
                v104 = sub_6811D1(v46, v94 | 1, v99, 1, 0);
                if ( v104 < 0 )
                  goto LABEL_210;
                v104 = sub_680D22(Block, v25);
                if ( v104 < 0 )
                  goto LABEL_210;
                v47 = (_DWORD *)*((_DWORD *)Block + 4);
                v48 = *(_DWORD *)(v25 + 16);
                v101 = 0;
                v49 = 4 * v103;
                v3 = v99 == 0;
                *v47 = *(_DWORD *)(4 * v103 + v48);
                if ( !v3 )
                {
                  v102 = (_DWORD *)v49;
                  do
                  {
                    v50 = v101;
                    *(_DWORD *)(*((_DWORD *)Block + 2) + 4 * v101) = *(_DWORD *)((char *)v102 + *(_DWORD *)(v25 + 8));
                    v102 += v27;
                    v101 = v50 + 1;
                  }
                  while ( v50 + 1 < v99 );
                }
                sub_681C03((void *)this, Block);
                sub_66238F(Block, 1);
                if ( ++v103 >= v27 )
                  goto LABEL_151;
              }
LABEL_75:
              v104 = -2147024882;
              goto LABEL_210;
            }
            *(_DWORD *)v25 = 1893728257;
          }
        }
      }
      sub_681C03((void *)this, (_DWORD *)v25);
LABEL_151:
      *(_DWORD *)v25 = 0;
      if ( ++v100 >= v92 )
        break;
      continue;
    }
  }
  sub_6825A9((_DWORD *)this);
  v104 = sub_6C9357(*(_DWORD *)(this + 200));
  if ( v104 < 0 )
    goto LABEL_210;
  if ( *(_DWORD *)(this + 200) == 1180172801 )
  {
    v51 = v89;
    sub_6C9357(((v90 + v91 + v89 + 5) << 17) & 0x7FFF0000 | 0xFFFE);
    v104 = sub_6C9357(1230197328);
    if ( v104 < 0 )
      goto LABEL_210;
    for ( j = 0; j < 3; ++j )
    {
      if ( *(&v85 + j) == -1 )
        sub_6C9357(0);
      else
        sub_6C9357(*(&v85 + j));
    }
    for ( k = 0; k < 0xC; k += 4 )
    {
      v54 = *(unsigned int *)((char *)&v85 + k);
      if ( v54 == -1 )
        sub_6C9357(0);
      else
        sub_6C9357(*(unsigned int *)((char *)&v74 + k) - v54 + 1);
    }
    sub_6C9357(v51);
    for ( m = 0; m < v51; ++m )
    {
      sub_6C9357(*((_DWORD *)v82 + 2 * m));
      sub_6C9357(*((_DWORD *)v82 + 2 * m + 1));
    }
    sub_6C9357(v90);
    v56 = 0;
    if ( v90 )
    {
      v57 = v83;
      do
      {
        sub_6C9357(v57[2 * v56]);
        sub_6C9357(v57[2 * v56++ + 1]);
      }
      while ( v56 < v90 );
    }
    sub_6C9357(v91);
    v58 = 0;
    if ( v91 )
    {
      v59 = v84;
      do
      {
        sub_6C9357(v59[2 * v58]);
        sub_6C9357(v59[2 * v58++ + 1]);
      }
      while ( v58 < v91 );
    }
  }
  v104 = sub_6C94AF(this);
  if ( v104 >= 0 )
  {
    v104 = sub_6C9357(((v97 << 19) + 0x20000) & 0x7FFF0000 | 0xFFFE);
    if ( v104 >= 0 )
    {
      v104 = sub_6C9357(1414089795);
      if ( v104 >= 0 )
      {
        v60 = 4 * v97;
        v104 = sub_6C9357(4 * v97);
        if ( v104 >= 0 )
        {
          v61 = 0;
          if ( v60 )
          {
            while ( 1 )
            {
              v104 = sub_6B37C1(
                       (_DWORD *)this,
                       COERCE_UNSIGNED_INT64(*((double *)v95 + v61)),
                       HIDWORD(COERCE_UNSIGNED_INT64(*((double *)v95 + v61))));
              if ( v104 < 0 )
                break;
              if ( ++v61 >= v60 )
                goto LABEL_180;
            }
          }
          else
          {
LABEL_180:
            v98 = *(_DWORD *)(this + 272);
            v104 = sub_6C9357(0);
            if ( v104 >= 0 )
            {
              v104 = sub_6C9357(1129076806);
              if ( v104 >= 0 )
              {
                v104 = sub_6C9357(*(_DWORD *)(this + 12));
                if ( v104 >= 0 )
                {
                  v3 = *(_DWORD *)(this + 12) == 0;
                  v97 = 0;
                  if ( v3 )
                  {
LABEL_203:
                    v104 = sub_6C9357(-252645136);
                    if ( v104 >= 0 )
                    {
                      v104 = sub_6C9357(252645135);
                      if ( v104 >= 0 )
                      {
                        *(_DWORD *)(*(_DWORD *)(this + 268) + 4 * v98) = ((*(_DWORD *)(*(_DWORD *)(this + 268) + 4 * v98)
                                                                         + 4) << 16)
                                                                       & 0x7FFF0000
                                                                       | 0xFFFE;
                        v104 = sub_6C9357(0xFFFF);
                        if ( v104 >= 0 )
                        {
                          if ( a2 )
                          {
                            v104 = sub_677265(4 * *(_DWORD *)(this + 272), &v101);
                            if ( v104 < 0 )
                              goto LABEL_210;
                            qmemcpy(
                              (void *)(*(int (__stdcall **)(unsigned int))(*(_DWORD *)v101 + 12))(v101),
                              *(const void **)(this + 268),
                              4 * *(_DWORD *)(this + 272));
                            *a2 = v101;
                          }
                          v104 = 0;
                        }
                      }
                    }
                  }
                  else
                  {
                    Block = 0;
LABEL_185:
                    v104 = sub_6C9357(
                             **(_DWORD **)((char *)Block + *(_DWORD *)(this + 24))
                           | (*(_DWORD *)(*(_DWORD *)((char *)Block + *(_DWORD *)(this + 24)) + 40) != 0 ? 0x80000000 : 0));
                    if ( v104 >= 0 )
                    {
                      v62 = *(_DWORD **)((char *)Block + *(_DWORD *)(this + 24));
                      v63 = *v62 & 0xFFFFF;
                      v101 = v62[1] / v63;
                      v104 = sub_6C9357(v101);
                      if ( v104 >= 0 )
                      {
                        v64 = *(_DWORD *)(this + 268);
                        v100 = 0;
                        *(_DWORD *)(v64 + 4 * v98) += 2;
                        if ( v101 )
                        {
                          v102 = 0;
                          v92 = 4 * v63;
                          while ( 1 )
                          {
                            v65 = *(_DWORD **)(*(_DWORD *)(this + 20)
                                             + 4
                                             * *(_DWORD *)((char *)v102
                                                         + *(_DWORD *)(*(_DWORD *)((char *)Block + *(_DWORD *)(this + 24))
                                                                     + 8)));
                            v66 = *(_DWORD *)(this + 272);
                            v104 = sub_6C9357(0);
                            if ( v104 < 0 )
                              break;
                            v67 = v65[2];
                            if ( v67 != -1 )
                            {
                              v104 = sub_6B39F1((_DWORD *)this, v67, v66);
                              if ( v104 < 0 )
                                break;
                            }
                            v104 = sub_6B3700((_DWORD *)this, (int)v65);
                            if ( v104 < 0 )
                              break;
                            v104 = sub_6C9357(v65[4] + 4 * v65[3]);
                            if ( v104 < 0 )
                              break;
                            *(_DWORD *)(*(_DWORD *)(this + 268) + 4 * v98) += 2
                                                                            * *(_DWORD *)(*(_DWORD *)(this + 268)
                                                                                        + 4 * v66)
                                                                            + 3;
                            ++v100;
                            v102 = (_DWORD *)((char *)v102 + v92);
                            if ( v100 >= v101 )
                              goto LABEL_195;
                          }
                        }
                        else
                        {
LABEL_195:
                          v100 = 0;
                          while ( 1 )
                          {
                            v68 = *(_DWORD **)(*(_DWORD *)(this + 20)
                                             + 4
                                             * *(_DWORD *)(v100
                                                         + *(_DWORD *)(*(_DWORD *)((char *)Block + *(_DWORD *)(this + 24))
                                                                     + 16)));
                            v69 = *(_DWORD *)(this + 272);
                            v104 = sub_6C9357(0);
                            if ( v104 < 0 )
                              break;
                            v70 = v68[2];
                            if ( v70 != -1 )
                            {
                              v104 = sub_6B39F1((_DWORD *)this, v70, v69);
                              if ( v104 < 0 )
                                break;
                            }
                            v104 = sub_6B3700((_DWORD *)this, (int)v68);
                            if ( v104 < 0 )
                              break;
                            v104 = sub_6C9357(v68[4] + 4 * v68[3]);
                            if ( v104 < 0 )
                              break;
                            v71 = *(_DWORD *)(this + 268);
                            v100 += 4;
                            *(_DWORD *)(v71 + 4 * v98) += 2 * *(_DWORD *)(v71 + 4 * v69) + 3;
                            if ( v100 >= 4 )
                            {
                              ++v97;
                              Block = (char *)Block + 4;
                              if ( v97 < *(_DWORD *)(this + 12) )
                                goto LABEL_185;
                              goto LABEL_203;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_210:
  j__free(v95);
  j__free(v82);
  j__free(v83);
  j__free(v84);
  return v104;
}
