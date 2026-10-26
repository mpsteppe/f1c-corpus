int __thiscall sub_6C201D(int this)
{
  unsigned int *v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // edi
  int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // edi
  unsigned int v8; // ecx
  _DWORD *v9; // esi
  int v10; // eax
  int v11; // edi
  unsigned int v12; // edx
  _DWORD *v13; // ecx
  unsigned int v14; // eax
  int v15; // esi
  unsigned int v16; // ecx
  int v17; // ecx
  unsigned int v18; // edi
  int v19; // edx
  _DWORD *v20; // eax
  unsigned int v21; // eax
  int *v22; // eax
  unsigned int *v23; // ecx
  unsigned int v24; // edx
  int v25; // edi
  _DWORD *v26; // esi
  unsigned int k; // eax
  int v28; // esi
  unsigned int v29; // edi
  int v30; // ecx
  int *v31; // eax
  _DWORD *v32; // ecx
  int v33; // eax
  unsigned int n; // eax
  int v35; // ecx
  int v36; // esi
  _DWORD *v37; // ecx
  int v38; // eax
  unsigned int ii; // edx
  int v40; // eax
  _DWORD *v41; // ecx
  _DWORD *v42; // eax
  unsigned int *v43; // esi
  int v45; // edi
  unsigned int *v46; // ecx
  char *v47; // esi
  unsigned int *v48; // eax
  char *v49; // edi
  char v50; // dl
  unsigned int v51; // ecx
  char *v52; // edi
  char *v53; // esi
  unsigned int v54; // edx
  unsigned int v55; // esi
  _DWORD *v56; // ecx
  int v57; // edx
  _DWORD *v58; // ecx
  _DWORD *v59; // ecx
  int v60; // [esp-8h] [ebp-28Ch]
  _DWORD v61[40]; // [esp+Ch] [ebp-278h] BYREF
  _DWORD v62[40]; // [esp+ACh] [ebp-1D8h] BYREF
  _DWORD v63[40]; // [esp+14Ch] [ebp-138h] BYREF
  int v64[4]; // [esp+1ECh] [ebp-98h] BYREF
  _DWORD v65[16]; // [esp+1FCh] [ebp-88h] BYREF
  int v66[4]; // [esp+23Ch] [ebp-48h] BYREF
  unsigned int v67; // [esp+24Ch] [ebp-38h]
  unsigned int j; // [esp+250h] [ebp-34h]
  int v69; // [esp+254h] [ebp-30h]
  unsigned int **v70; // [esp+258h] [ebp-2Ch]
  unsigned int v71; // [esp+25Ch] [ebp-28h] BYREF
  unsigned int v72; // [esp+260h] [ebp-24h]
  unsigned int *v73; // [esp+264h] [ebp-20h]
  int v74; // [esp+268h] [ebp-1Ch]
  unsigned int v75; // [esp+26Ch] [ebp-18h]
  int *v76; // [esp+270h] [ebp-14h]
  unsigned int i; // [esp+274h] [ebp-10h]
  int v78; // [esp+278h] [ebp-Ch]
  unsigned int m; // [esp+27Ch] [ebp-8h]
  unsigned int v80; // [esp+280h] [ebp-4h]

  v66[0] = 0;
  memset(v63, 0xFFu, sizeof(v63));
  v2 = *(unsigned int **)(this + 256);
  v3 = *v2;
  v72 = *v2;
  v4 = v72;
  v72 &= 0xFFFFFu;
  v66[1] = 1;
  v66[2] = 2;
  v66[3] = 3;
  v73 = v2;
  v75 = v4 & 0xFFFFF;
  if ( v72 > (v4 & 0xFFFFF) || (v3 & 0xFFF00000) != 0x20500000 )
  {
    v78 = 1;
    goto LABEL_90;
  }
  v69 = 0;
LABEL_5:
  v78 = 0;
  while ( 2 )
  {
    memset(v62, 0xFFu, sizeof(v62));
    memset(v61, 0xFFu, sizeof(v61));
    v5 = 0;
    v71 = 0;
    v74 = 0;
    v80 = 0;
    m = 0;
    while ( 1 )
    {
      if ( v78 )
        v6 = 1 - v80;
      else
        v6 = v80;
      v7 = v73[2];
      v8 = dword_745E9C[v6];
      v9 = (_DWORD *)(v7 + 4 * v5);
      if ( v8 >= 0x10 )
      {
        v12 = 0;
        v13 = &v62[4 * v8 - 64];
        do
        {
          v14 = v66[v12];
          if ( v14 >= v72 )
            *v13 = -1;
          else
            *v13 = *(_DWORD *)(v7 + 4 * (m + v14));
          ++v12;
          ++v13;
        }
        while ( v12 < 4 );
        goto LABEL_19;
      }
      v10 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v9) + 72);
      if ( v10 == -1 )
        break;
      v11 = 32 * v8;
      v60 = dword_745EA8[8 * v8];
      v76 = *(int **)(*(_DWORD *)(this + 24) + 4 * v10);
      if ( sub_6BB1AA((_DWORD *)this, v76, (int)v9, v72, v66, v64, v60, 0) )
        break;
      v74 = sub_6BB35B((_DWORD *)this, v76, (char *)&unk_745E90 + v11, (char *)v65, &v71, (int)v61, v64, v75, 0);
LABEL_19:
      if ( v74 != 1 )
      {
        v5 = v72 + m;
        ++v80;
        m += v72;
        if ( v80 < 2 )
          continue;
      }
      goto LABEL_23;
    }
    v74 = 1;
LABEL_23:
    v15 = 0;
    v80 = 0;
    v70 = 0;
    do
    {
      if ( v78 )
        v16 = 1 - v80;
      else
        v16 = v80;
      if ( (unsigned int)dword_745E9C[v16] >= 0x10 )
      {
        for ( i = 0; i < v71; v15 = 0 )
        {
          if ( v72 )
          {
            v17 = v65[i];
            v18 = *(_DWORD *)(v17 + 12);
            while ( 1 )
            {
              m = 0;
              if ( v18 )
                break;
LABEL_35:
              if ( ++v15 >= v72 )
                goto LABEL_38;
            }
            v19 = *(_DWORD *)(v73[2] + 4 * ((_DWORD)v70 + v15));
            v20 = *(_DWORD **)(v17 + 16);
            while ( v19 != *v20 )
            {
              ++m;
              v18 = *(_DWORD *)(v17 + 12);
              ++v20;
              if ( m >= v18 )
                goto LABEL_35;
            }
            v74 = 1;
          }
LABEL_38:
          ++i;
        }
      }
      ++v80;
      v70 = (unsigned int **)((char *)v70 + v72);
    }
    while ( v80 < 2 );
    if ( v74 )
      goto LABEL_79;
    if ( !v69 )
    {
      for ( i = 0; i < v71; ++i )
      {
        v21 = *(_DWORD *)(v65[i] + 12);
        m = 0;
        for ( j = v21; m < j; ++m )
        {
          v22 = *(int **)(this + 12);
          if ( v22 )
          {
            v70 = *(unsigned int ***)(this + 24);
            v76 = v22;
            do
            {
              v23 = *v70;
              if ( *v70 && *v23 )
              {
                v24 = v23[1];
                v80 = 0;
                if ( v24 )
                {
                  v25 = *(_DWORD *)(*(_DWORD *)(v65[i] + 16) + 4 * m);
                  v26 = (_DWORD *)v23[2];
                  v67 = v24;
                  do
                  {
                    if ( *v26 == v25 || *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v26) + 56) == v25 )
                      v80 = 1;
                    ++v26;
                    --v67;
                  }
                  while ( v67 );
                }
                if ( v23 == v73 )
                  v80 = 0;
                if ( v80 )
                {
                  for ( k = 0; k < v71; ++k )
                  {
                    if ( v23 == (unsigned int *)v65[k] )
                      v80 = 0;
                  }
                  if ( v80 )
                    v74 = 1;
                }
              }
              ++v70;
              v76 = (int *)((char *)v76 - 1);
            }
            while ( v76 );
          }
        }
      }
      for ( m = 0; m < 0x28; ++m )
      {
        v28 = v62[m];
        if ( v28 != -1 )
        {
          v29 = 0;
          if ( v71 )
          {
            j = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v28);
            do
            {
              v30 = v65[v29];
              v31 = *(int **)(v30 + 12);
              if ( v31 )
              {
                v32 = *(_DWORD **)(v30 + 16);
                v76 = v31;
                do
                {
                  if ( v28 == *v32 || *(_DWORD *)(j + 56) == *v32 )
                    v74 = 1;
                  ++v32;
                  v76 = (int *)((char *)v76 - 1);
                }
                while ( v76 );
              }
              ++v29;
            }
            while ( v29 < v71 );
          }
        }
      }
      if ( v74 )
      {
LABEL_79:
        if ( (unsigned int)++v78 < 2 )
          continue;
        v33 = v74;
        if ( ++v69 )
          goto LABEL_89;
        goto LABEL_5;
      }
    }
    break;
  }
  v65[v71] = v73;
  for ( n = 0; n < 40; ++n )
  {
    v35 = v62[n];
    if ( v35 == -1 )
    {
      v35 = v61[n];
      if ( v35 == -1 )
        continue;
    }
    v63[n] = v35;
  }
  v33 = 0;
LABEL_89:
  v78 = v33;
LABEL_90:
  if ( v75 < 3 )
    return 1;
  v76 = 0;
  v36 = *(_DWORD *)(this + 16);
  v37 = *(_DWORD **)(*(_DWORD *)(this + 256) + 16);
  do
  {
    v38 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v37);
    if ( (*(_BYTE *)(*(_DWORD *)(v36 + 4 * *(_DWORD *)(v38 + 4)) + 4) & 0x20) != 0 || *(int **)(v38 + 16) != v76 )
      return 1;
    ++v37;
    v76 = (int *)((char *)v76 + 1);
  }
  while ( (unsigned int)v76 < v75 );
  if ( v78 )
    return v78;
  for ( ii = 0; ii < 3; ++ii )
  {
    v40 = v63[ii];
    v41 = &v63[ii + 8];
    if ( v40 != *(v41 - 4)
      || v40 != *v41
      || *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v40) + 16) != ii && (*(_BYTE *)(this + 108) & 2) != 0 )
    {
      return 1;
    }
  }
  if ( v63[7] != -1 || v63[11] != -1 )
    return 1;
  v42 = (_DWORD *)sub_681186(116);
  if ( v42 )
    v43 = sub_680CEC(v42);
  else
    v43 = 0;
  v73 = v43;
  if ( !v43 )
    return -2147024882;
  v45 = sub_6811D1((char *)v43, v75 & 0xFFFFF | 0x70200000, v75, v75, 0);
  v46 = v43;
  if ( v45 < 0 )
    goto LABEL_114;
  v45 = sub_680D22(v43, *(_DWORD *)(this + 256));
  if ( v45 < 0 )
  {
    v46 = v43;
LABEL_114:
    sub_66238F(v46, 1);
    return v45;
  }
  v47 = *(char **)(*(_DWORD *)(this + 256) + 16);
  v48 = v73;
  v49 = (char *)v73[4];
  v50 = 4 * v75;
  v51 = (4 * v75) >> 2;
  qmemcpy(v49, v47, 4 * v51);
  v53 = &v47[4 * v51];
  v52 = &v49[4 * v51];
  LOBYTE(v51) = v50;
  v54 = v75;
  qmemcpy(v52, v53, v51 & 3);
  qmemcpy((void *)v48[2], v63, 4 * ((4 * v54) >> 2));
  v55 = 0;
  if ( v54 )
  {
    do
    {
      if ( (*(_BYTE *)(this + 108) & 2) != 0 )
      {
        v56 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 256) + 8) + 4 * v55));
        *v56 |= 0x80000000;
        v57 = *(_DWORD *)(this + 20);
        if ( *(_DWORD *)(*(_DWORD *)(v57 + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 256) + 8) + 4 * v55)) + 56) != -1 )
        {
          v58 = *(_DWORD **)(*(_DWORD *)(this + 20)
                           + 4
                           * *(_DWORD *)(*(_DWORD *)(v57
                                                   + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 256) + 8) + 4 * v55))
                                       + 56));
          *v58 |= 0x80000000;
        }
      }
      v59 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 256) + 16) + 4 * v55));
      *v59 |= 0x80000000;
      ++v55;
    }
    while ( v55 < v75 );
  }
  v78 = sub_681430(*(char **)(this + 256), v73);
  sub_66238F(v73, 1);
  return v78;
}
