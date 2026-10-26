int __thiscall sub_6925FA(_DWORD *this)
{
  int v2; // eax
  unsigned int v3; // edx
  int v4; // esi
  unsigned int v5; // ecx
  size_t v6; // esi
  char *v7; // edx
  char *v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // esi
  _DWORD *v11; // eax
  int v12; // ecx
  unsigned int v13; // eax
  char *v14; // ecx
  int v15; // eax
  bool v16; // zf
  int *v17; // edi
  int v18; // esi
  unsigned int v19; // eax
  unsigned int v20; // ecx
  _DWORD *v21; // esi
  unsigned int v22; // ecx
  _DWORD *v23; // eax
  int v24; // edi
  int v25; // ecx
  _DWORD *v26; // edi
  unsigned int v27; // ecx
  int i; // eax
  _DWORD *v29; // eax
  int v30; // ecx
  int v31; // edx
  int v32; // ecx
  int v33; // eax
  int v34; // eax
  int result; // eax
  int v36; // eax
  int v37; // esi
  int v38; // edi
  _DWORD *v39; // ecx
  int v40; // eax
  _DWORD *v41; // edi
  unsigned int v42; // ecx
  int v43; // ecx
  int v44; // eax
  _DWORD *v45; // edi
  int v46; // esi
  int v47; // ecx
  char *v48; // esi
  char *v49; // edi
  char v50; // al
  _DWORD *v51; // edx
  unsigned int v52; // ecx
  char *v53; // edi
  char *v54; // esi
  int v55; // eax
  unsigned int v56; // ecx
  unsigned int j; // eax
  BOOL v58; // eax
  int v59; // esi
  int v60; // eax
  int v61; // eax
  _DWORD v62[3]; // [esp+14h] [ebp-78h] BYREF
  int v63; // [esp+20h] [ebp-6Ch] BYREF
  _DWORD v64[4]; // [esp+24h] [ebp-68h] BYREF
  _DWORD *v65; // [esp+34h] [ebp-58h]
  int *v66; // [esp+38h] [ebp-54h]
  void *Block; // [esp+3Ch] [ebp-50h]
  _DWORD *v68; // [esp+40h] [ebp-4Ch]
  int v69; // [esp+44h] [ebp-48h]
  int v70; // [esp+48h] [ebp-44h] BYREF
  int v71; // [esp+4Ch] [ebp-40h]
  unsigned int v72; // [esp+50h] [ebp-3Ch]
  unsigned int v73; // [esp+54h] [ebp-38h]
  int v74; // [esp+58h] [ebp-34h]
  unsigned int v75; // [esp+5Ch] [ebp-30h]
  unsigned int v76; // [esp+60h] [ebp-2Ch]
  int v77; // [esp+64h] [ebp-28h]
  unsigned int v78; // [esp+68h] [ebp-24h]
  int v79; // [esp+6Ch] [ebp-20h] BYREF
  unsigned int v80; // [esp+70h] [ebp-1Ch]
  unsigned int v81; // [esp+74h] [ebp-18h]
  int v82; // [esp+78h] [ebp-14h]
  int v83; // [esp+7Ch] [ebp-10h]
  unsigned int v84; // [esp+80h] [ebp-Ch]
  unsigned int v85; // [esp+84h] [ebp-8h]
  int v86; // [esp+88h] [ebp-4h]

  v71 = -1;
  sub_686074((int)this);
  v2 = this[2];
  v3 = 0;
  v79 = 0;
  if ( v2 )
  {
    v4 = this[5];
    do
    {
      if ( this[34] == *(_DWORD *)(*(_DWORD *)v4 + 4) )
      {
        v5 = *(_DWORD *)(*(_DWORD *)v4 + 12);
        if ( v3 <= v5 )
          v3 = v5 + 1;
      }
      v4 += 4;
      --v2;
    }
    while ( v2 );
    v79 = v3;
  }
  v6 = 4 * (v3 + 8 * this[3]);
  v7 = (char *)operator new(v6);
  Block = v7;
  if ( !v7 )
    return -2147024882;
  memset(v7, 0, 4 * (v6 >> 2));
  v8 = &v7[4 * (v6 >> 2)];
  v9 = v6 & 3;
  v10 = 0;
  memset(v8, 0, v9);
  if ( this[2] )
  {
    do
    {
      v11 = *(_DWORD **)(this[5] + 4 * v10);
      if ( this[34] == v11[1] )
      {
        v12 = v11[3];
        v13 = v11[4];
        v14 = &v7[4 * v12];
        if ( *(_DWORD *)v14 <= v13 )
          *(_DWORD *)v14 = v13 + 1;
      }
      ++v10;
    }
    while ( v10 < this[2] );
  }
  v15 = this[3];
  v75 = 0;
  v74 = v15;
  while ( v75 < v74 )
  {
    v16 = (*(_WORD *)(*(_DWORD *)(this[6] + 4 * v75) + 2) & 0xFFF0) == 0;
    v83 = *(_DWORD *)(this[6] + 4 * v75);
    if ( !v16 )
    {
      v17 = (int *)v83;
      v18 = 0;
      v72 = 1;
      v19 = sub_680D41((_DWORD *)v83, 0, &v70);
      if ( !v19 )
        goto LABEL_83;
      do
      {
        if ( !sub_68CCED(this, (int *)v70, v19, (int)Block, &v79, v17, (unsigned int)v74 | 0xFFFFFFFF00000000uLL) )
          v72 = 0;
        v19 = sub_680D41(v17, ++v18, &v70);
      }
      while ( v19 );
      if ( v72 || sub_680D7E(v17) )
      {
LABEL_83:
        v69 = sub_681B0A(this, *v17, v17[1], v17[3]);
        if ( v69 == -1 )
          goto LABEL_99;
        v46 = v83;
        v68 = *(_DWORD **)(this[6] + 4 * v69);
        v45 = v68;
        sub_680D22(v68, v83);
        v47 = *(_DWORD *)(v46 + 4);
        v48 = *(char **)(v46 + 8);
        v49 = (char *)v45[2];
        v50 = 4 * v47;
        v51 = v68;
        v52 = (unsigned int)(4 * v47) >> 2;
        qmemcpy(v49, v48, 4 * v52);
        v54 = &v48[4 * v52];
        v53 = &v49[4 * v52];
        LOBYTE(v52) = v50;
        v55 = v83;
        qmemcpy(v53, v54, v52 & 3);
        qmemcpy((void *)v51[4], *(const void **)(v55 + 16), 4 * *(_DWORD *)(v55 + 12));
        v56 = 0;
        if ( *(_DWORD *)(v55 + 12) )
        {
          do
            *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v68[4] + 4 * v56++)) + 72) = v69;
          while ( v56 < *(_DWORD *)(v83 + 12) );
        }
      }
      else
      {
        v86 = 0;
        v20 = sub_680D41(v17, 0, 0);
        v85 = v20;
        if ( v20 )
          v84 = v17[1] / v20;
        else
          v84 = 0;
        memset(v64, 0, sizeof(v64));
        v80 = 0;
        if ( v20 )
        {
          v81 = 0;
          v21 = (_DWORD *)v83;
          v66 = &v63;
          do
          {
            if ( !v66[v81 / 4 + 1] )
            {
              v22 = v80 + 1;
              v82 = 1;
              v73 = v80 + 1;
              if ( v80 + 1 < v85 )
              {
                v76 = 4;
                do
                {
                  if ( !v64[v22] )
                  {
                    v78 = 0;
                    if ( v84 )
                    {
                      v23 = (_DWORD *)(v81 + v21[2]);
                      do
                      {
                        v24 = this[5];
                        v25 = 4 * *v23;
                        v72 = 4 * *(_DWORD *)((char *)v23 + v76);
                        if ( *(_DWORD *)(*(_DWORD *)(v24 + v25) + 4) != *(_DWORD *)(*(_DWORD *)(v24 + v72) + 4) )
                          break;
                        if ( *(_DWORD *)(*(_DWORD *)(this[5] + v25) + 8) != *(_DWORD *)(*(_DWORD *)(this[5] + v72) + 8) )
                          break;
                        if ( *(_DWORD *)(*(_DWORD *)(this[5] + v25) + 12) != *(_DWORD *)(*(_DWORD *)(this[5] + v72) + 12) )
                          break;
                        ++v78;
                        v23 += v85;
                      }
                      while ( v78 < v84 );
                    }
                    if ( v78 == v84 )
                      ++v82;
                  }
                  v76 += 4;
                  v22 = ++v73;
                }
                while ( v73 < v85 );
              }
              v76 = sub_681B0A(this, *v21 ^ (v82 ^ *v21) & 0xFFFFF, -1, -1);
              if ( v76 == -1 )
                goto LABEL_99;
              v26 = *(_DWORD **)(this[6] + 4 * v76);
              sub_680D22(v26, (int)v21);
              v27 = v85;
              if ( v85 > v80 )
              {
                v77 = 4 * v82 - 4;
                for ( i = 4 * v85 - v81; ; i = v69 )
                {
                  v69 = i - 4;
                  v72 = v27 - 1;
                  v16 = v64[v27 - 1] == 0;
                  v65 = &v64[v27 - 1];
                  if ( !v16 )
                    goto LABEL_58;
                  v78 = 0;
                  if ( v84 )
                  {
                    v29 = (_DWORD *)(v81 + v21[2]);
                    v68 = v29;
                    do
                    {
                      v30 = *(_DWORD *)((char *)v29 + v69);
                      v31 = this[5];
                      v73 = 4 * *v29;
                      v32 = 4 * v30;
                      if ( *(_DWORD *)(*(_DWORD *)(v73 + v31) + 4) != *(_DWORD *)(*(_DWORD *)(v32 + v31) + 4) )
                        break;
                      if ( *(_DWORD *)(*(_DWORD *)(v73 + this[5]) + 8) != *(_DWORD *)(*(_DWORD *)(v32 + this[5]) + 8) )
                        break;
                      if ( *(_DWORD *)(*(_DWORD *)(v73 + this[5]) + 12) != *(_DWORD *)(*(_DWORD *)(v32 + this[5]) + 12) )
                        break;
                      ++v78;
                      v29 = &v68[v85];
                      v68 = v29;
                    }
                    while ( v78 < v84 );
                    if ( v78 < v84 )
                      goto LABEL_58;
                    v73 = v77;
                    v78 = 4 * v72;
                    v68 = (_DWORD *)v84;
                    do
                    {
                      *(_DWORD *)(v73 + v26[2]) = *(_DWORD *)(v78 + v21[2]);
                      v78 += 4 * v85;
                      v73 += 4 * v82;
                      v68 = (_DWORD *)((char *)v68 - 1);
                    }
                    while ( v68 );
                    *v65 = 1;
                  }
                  if ( (*v21 & 0xFFF00000) != 0x50000000 )
                  {
                    v33 = v77;
                    *(_DWORD *)(v77 + v26[4]) = *(_DWORD *)(4 * v72 + v21[4]);
                    *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v33 + v26[4])) + 72) = v76;
                  }
                  v77 -= 4;
LABEL_58:
                  v27 = v72;
                  if ( v72 <= v80 )
                    break;
                }
              }
              if ( (*v21 & 0xFFF00000) == 0x50000000 )
              {
                if ( v82 == v85 )
                {
                  *(_DWORD *)v26[4] = *(_DWORD *)v21[4];
                }
                else
                {
                  v34 = sub_681AAA(this, this[34], v79, v86, 0.0);
                  v62[v86] = v34;
                  *(_DWORD *)v26[4] = v34;
                  if ( *(_DWORD *)v26[4] == -1 )
                    goto LABEL_99;
                  *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)v26[4]) + 20) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)v21[4])
                                                                                             + 20);
                  *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)v26[4]) + 24) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)v21[4])
                                                                                             + 24);
                  result = sub_682AEE((int)this, (int)v26, 0);
                  if ( result < 0 )
                    return result;
                  ++v86;
                }
                *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)v26[4]) + 72) = v76;
              }
            }
            ++v80;
            v81 += 4;
          }
          while ( v80 < v85 );
          if ( v86 )
          {
            if ( v86 == 2 )
            {
              v36 = sub_681B0A(this, 541065217, -1, -1);
              v76 = 0;
              v37 = v36;
              do
              {
                v38 = this[6];
                v39 = &v62[v76];
                v40 = 4 * *v39;
                if ( (**(_DWORD **)(v38 + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + v40) + 72)) & 0xFFF00000) == 0x10000000 )
                {
                  **(_DWORD **)(v38 + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + v40) + 72)) = 0;
                  *v39 = **(_DWORD **)(*(_DWORD *)(this[6] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + v40) + 72)) + 8);
                }
                ++v76;
              }
              while ( v76 < 2 );
            }
            else
            {
              v37 = sub_681B0A(this, v86 & 0xFFFFF | 0x50000000, -1, -1);
            }
            if ( v37 == -1 )
              return -2147024882;
            v65 = *(_DWORD **)(this[6] + 4 * v37);
            v41 = v65;
            sub_680D22(v65, v83);
            *(_DWORD *)v41[4] = **(_DWORD **)(v83 + 16);
            v42 = 4 * v86;
            *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)v41[4]) + 72) = v37;
            qmemcpy((void *)v41[2], v62, v42);
            if ( v86 != 2 )
            {
              if ( v71 == -1 )
              {
                v71 = sub_681AAA(this, this[30], 0, 0, 1.0);
                if ( v71 == -1 )
                {
LABEL_99:
                  v59 = -2147024882;
                  goto LABEL_96;
                }
              }
              v43 = v86;
              if ( v86 )
              {
                v44 = 4 * v86;
                do
                {
                  *(_DWORD *)(v44 + v65[2]) = v71;
                  v44 += 4;
                  --v43;
                }
                while ( v43 );
              }
            }
            ++v79;
          }
        }
      }
    }
    ++v75;
  }
  for ( j = 0; j < v74; ++j )
    **(_DWORD **)(this[6] + 4 * j) = 0;
  v58 = sub_6875A0(this);
  if ( !v58 || (v59 = v58, v58 >= 0) )
  {
    v60 = sub_6825A9(this);
    if ( !v60 || (v59 = v60, v60 >= 0) )
    {
      v61 = sub_68FECA(this);
      if ( !v61 || (v59 = v61, v61 >= 0) )
        v59 = 0;
    }
  }
LABEL_96:
  j__free(Block);
  return v59;
}
