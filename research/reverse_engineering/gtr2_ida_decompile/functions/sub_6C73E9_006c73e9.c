int __thiscall sub_6C73E9(int this, int a2, int a3, char *a4, int a5, int a6, int a7)
{
  int v7; // ebx
  char *v9; // edi
  int v10; // edx
  int *v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // edx
  unsigned int v20; // ecx
  bool v21; // zf
  _DWORD *v22; // eax
  _DWORD *v23; // edi
  _DWORD *v24; // edx
  int v25; // ebx
  int v26; // edi
  int v27; // ebx
  int v28; // ecx
  unsigned int v29; // edi
  _DWORD *v30; // eax
  int v31; // ebx
  int v32; // edx
  int v33; // ebx
  _DWORD *v34; // ecx
  unsigned int v35; // ecx
  int *v36; // eax
  unsigned int v37; // ecx
  int v38; // eax
  char *v39; // edx
  unsigned int v40; // eax
  _DWORD *k; // edx
  unsigned int v42; // edx
  unsigned int v43; // eax
  unsigned int j; // edx
  _DWORD *v45; // ecx
  int v46; // edi
  int v47; // eax
  int v49; // eax
  unsigned int v50; // edx
  unsigned int *v51; // ecx
  unsigned int *v52; // eax
  unsigned int v53; // edi
  unsigned int v54; // edx
  _DWORD v55[20]; // [esp+Ch] [ebp-A4h]
  _DWORD v56[4]; // [esp+5Ch] [ebp-54h] BYREF
  _DWORD v57[4]; // [esp+6Ch] [ebp-44h] BYREF
  _DWORD v58[4]; // [esp+7Ch] [ebp-34h] BYREF
  char *v59; // [esp+8Ch] [ebp-24h]
  int v60; // [esp+90h] [ebp-20h]
  char *v61; // [esp+94h] [ebp-1Ch]
  char *v62; // [esp+98h] [ebp-18h]
  int v63; // [esp+9Ch] [ebp-14h]
  int i; // [esp+A0h] [ebp-10h]
  int v65; // [esp+A4h] [ebp-Ch]
  _DWORD *v66; // [esp+A8h] [ebp-8h]
  unsigned int v67; // [esp+ACh] [ebp-4h]
  unsigned int v68; // [esp+B8h] [ebp+8h]
  int *v69; // [esp+B8h] [ebp+8h]
  unsigned int v70; // [esp+B8h] [ebp+8h]
  int v71; // [esp+B8h] [ebp+8h]
  int v72; // [esp+BCh] [ebp+Ch]
  unsigned int v73; // [esp+BCh] [ebp+Ch]
  unsigned int v74; // [esp+BCh] [ebp+Ch]
  unsigned int v75; // [esp+C8h] [ebp+18h]
  int v76; // [esp+C8h] [ebp+18h]
  unsigned int v77; // [esp+CCh] [ebp+1Ch]

  v7 = a6;
  if ( !a6 )
  {
    v7 = *(_DWORD *)(this + 256);
    a6 = v7;
  }
  v9 = *(char **)(v7 + 16);
  v10 = *(_DWORD *)(this + 20);
  if ( *(_DWORD *)(this + 136) != *(_DWORD *)(*(_DWORD *)(v10 + 4 * *(_DWORD *)v9) + 4) )
    return 1;
  v11 = *(int **)(this + 256);
  v12 = *v11;
  v13 = v11[3];
  v65 = 0;
  v63 = v12;
  if ( (v12 & 0xFFFFF) != v13 )
    return 1;
  v67 = 0;
  if ( v13 )
  {
    v14 = (int)(*(_DWORD *)(this + 108) << 14) >> 31;
    v15 = a4 - v9;
    v66 = v9;
    for ( i = a4 - v9; ; v15 = i )
    {
      v16 = *(_DWORD *)(v10 + 4 * *(_DWORD *)((char *)v66 + v15));
      v60 = *(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v16 + 4));
      if ( v14 && (*(_BYTE *)(v16 + 61) & 2) != 0 && a2 == 0x80000 )
        v65 = 1;
      v17 = *(_DWORD *)(v16 + 60);
      if ( (v17 & 0x1F0000) != 0 && (v17 & ~a3 & 0x1F0000) != 0 )
      {
        if ( a2 != 0x80000 )
          return 1;
        v65 = 1;
      }
      v10 = *(_DWORD *)(this + 20);
      if ( (*(_BYTE *)(*(_DWORD *)(v10 + 4 * *v66) + 61) & 0xFE) != 0 )
        break;
      if ( (*(_BYTE *)(this + 108) & 0x10) != 0 && (*(_BYTE *)(v60 + 5) & 2) != 0 )
      {
        if ( (v63 & 0xFFF00000) != 0x10100000 )
          return 1;
        v65 = 1;
      }
      ++v67;
      v18 = *(_DWORD *)(this + 256);
      ++v66;
      if ( v67 >= *(_DWORD *)(v18 + 12) )
        goto LABEL_22;
    }
    return 1;
  }
LABEL_22:
  v68 = 0;
  if ( *(_DWORD *)(v7 + 12) )
  {
    v72 = ~a5;
    v63 = a4 - (char *)v58;
    do
    {
      v19 = *(_DWORD *)(this + 20);
      v20 = v68;
      v21 = v65 == 0;
      v22 = *(_DWORD **)(v19 + 4 * *(_DWORD *)(4 * v68 + *(_DWORD *)(v7 + 16)));
      v23 = &v58[v68];
      v24 = *(_DWORD **)(v19 + 4 * *(_DWORD *)((char *)v23 + v63));
      *v23 = v22[2];
      v25 = v22[18];
      v56[v20] = v22[3];
      v57[v20] = v22[4];
      v55[v20 + 4] = v22[5];
      v55[v20 + 16] = v22[6];
      v26 = v22[15];
      v55[v20 + 8] = v25;
      v27 = v22[26];
      v55[v20 + 12] = v26;
      v55[v20] = v27;
      if ( v21 )
      {
        v22[1] = v24[1];
        v22[2] = v24[2];
        v22[3] = v24[3];
        v22[4] = v24[4];
        v22[5] = v24[5];
        v22[6] = v24[6];
        v22[18] = v24[18];
        v22[26] = v24[26];
        v28 = v26 | v72 & v24[15] | a5 ^ v24[15];
      }
      else
      {
        v28 = v26 & v72 | a5 ^ v26;
      }
      ++v68;
      v7 = a6;
      v22[15] = v28;
    }
    while ( v68 < *(_DWORD *)(a6 + 12) );
  }
  v73 = 0;
  v63 = *(_DWORD *)(v7 + 12);
  v29 = v63;
  if ( v63 )
  {
    v69 = *(int **)(v7 + 16);
    while ( sub_6C32A9(this, *v69) != 1 )
    {
      ++v73;
      ++v69;
      if ( v73 >= v29 )
        goto LABEL_32;
    }
    goto LABEL_81;
  }
LABEL_32:
  v67 = -1;
  v74 = 0;
  v70 = -1;
  if ( v29 )
  {
    v30 = a4;
    v31 = *(_DWORD *)(v7 + 16);
    v32 = *(_DWORD *)(this + 20);
    v59 = (char *)((char *)v58 - a4);
    v61 = (char *)((char *)v56 - a4);
    v33 = v31 - (_DWORD)a4;
    v62 = (char *)((char *)v57 - a4);
    v60 = v33;
    i = v63;
    while ( 1 )
    {
      v34 = *(_DWORD **)(v32 + 4 * *v30);
      v66 = *(_DWORD **)(v32 + 4 * *(_DWORD *)((char *)v30 + v33));
      if ( v66[21] < v67 )
        v67 = v66[21];
      if ( v66[22] > v74 )
        v74 = v66[22];
      if ( *(_DWORD *)(this + 136) == v34[1]
        && *(_DWORD *)((char *)v30 + (_DWORD)v59) == v34[2]
        && *(_DWORD *)((char *)v30 + (_DWORD)v61) == v34[3]
        && *(_DWORD *)((char *)v30 + (_DWORD)v62) == v34[4] )
      {
        v34 = v66;
      }
      v35 = v34[20];
      if ( v35 < v70 )
        v70 = v35;
      ++v30;
      if ( !--i )
        break;
      v33 = v60;
    }
    v7 = a6;
  }
  if ( !a7 && v70 < v74 && (*(_DWORD *)(this + 108) & 0x10000000) == 0 )
  {
LABEL_81:
    for ( j = 0; j < *(_DWORD *)(v7 + 12); v45[26] = v47 )
    {
      v45 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(4 * j + *(_DWORD *)(v7 + 16)));
      v45[1] = *(_DWORD *)(this + 136);
      v45[2] = v58[j];
      v45[3] = v56[j];
      v45[4] = v57[j];
      v45[5] = v55[j + 4];
      v45[6] = v55[j + 16];
      v45[15] = v55[j + 12];
      v46 = v55[j + 8];
      v47 = v55[j++];
      v45[18] = v46;
    }
    return 1;
  }
  if ( v65 )
  {
    **(_DWORD **)(this + 256) = **(_DWORD **)(this + 256) & 0xFFFFF | 0x10000000;
  }
  else
  {
    v66 = (_DWORD *)v67;
    if ( v67 <= v74 )
    {
      v67 = *(_DWORD *)(this + 24) + 4 * v67;
      do
      {
        v36 = *(int **)v67;
        v65 = **(_DWORD **)v67;
        if ( v65 )
        {
          v37 = v36[2];
          v38 = v36[1];
          i = 0;
          v39 = (char *)(v37 + 4 * v38);
          v40 = v65 & 0xFFFFF;
          v61 = v39;
          if ( v37 < (unsigned int)v39 )
          {
            do
            {
              v71 = 0;
              v75 = 0;
              if ( v40 )
              {
                do
                {
                  v77 = 0;
                  if ( *(_DWORD *)(v7 + 12) )
                  {
                    for ( k = *(_DWORD **)(v7 + 16); *k != *(_DWORD *)(v37 + 4 * v75); k = v62 )
                    {
                      ++v77;
                      v62 = (char *)(k + 1);
                      if ( v77 >= *(_DWORD *)(v7 + 12) )
                        goto LABEL_64;
                    }
                    ++v71;
                  }
LABEL_64:
                  ++v75;
                }
                while ( v75 < v40 );
                if ( v71 )
                {
                  if ( v71 != v40 )
                    goto LABEL_81;
                  v42 = v65 & 0xFFF00000;
                  if ( (v65 & 0xFFF00000) == 0x70500000 || v42 == 1885339648 || v42 == 1886388224 )
                    goto LABEL_81;
                  i = 1;
                }
              }
              v37 += 4 * v40;
            }
            while ( v37 < (unsigned int)v61 );
            if ( i )
            {
              if ( (v65 & 0xF0000000) == 0x60000000
                || (v43 = v65 & 0xFFF00000, (v65 & 0xFFF00000) == 0x10D00000)
                || v43 == 283115520
                || v43 == 285212672 )
              {
                if ( *(char *)(this + 110) >= 0 )
                  goto LABEL_81;
              }
            }
          }
        }
        v66 = (_DWORD *)((char *)v66 + 1);
        v67 += 4;
      }
      while ( (unsigned int)v66 <= v74 );
    }
    if ( *(_DWORD *)(this + 348) )
    {
      *(_DWORD *)(this + 348) = 2;
      goto LABEL_81;
    }
    v76 = 0;
    if ( *(_DWORD *)(v7 + 12) )
    {
      while ( 1 )
      {
        v49 = *(_DWORD *)(this + 20);
        v50 = *(_DWORD *)&a4[4 * v76];
        v51 = *(unsigned int **)(v49 + 4 * *(_DWORD *)(4 * v76 + *(_DWORD *)(v7 + 16)));
        v52 = *(unsigned int **)(v49 + 4 * v50);
        v53 = v52[14];
        if ( v53 == -1 )
          v51[14] = v50;
        else
          v51[14] = v53;
        v54 = *v52;
        *v51 = *v52;
        if ( a5 != 0x80000 )
          goto LABEL_91;
        if ( (v54 & 4) != 0 )
          break;
LABEL_93:
        sub_681692(v51, v52);
        if ( (unsigned int)++v76 >= *(_DWORD *)(v7 + 12) )
          goto LABEL_94;
      }
      *v51 = v54 & 0xFFFFFFF3 | 8;
LABEL_91:
      if ( a5 == 0x100000 )
        *v51 |= 4u;
      goto LABEL_93;
    }
LABEL_94:
    **(_DWORD **)(this + 256) = 0;
  }
  return 0;
}
