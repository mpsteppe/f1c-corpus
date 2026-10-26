int __thiscall sub_6BB35B(
        _DWORD *this,
        int *a2,
        _DWORD *a3,
        char *a4,
        unsigned int *a5,
        int a6,
        int *a7,
        unsigned int a8,
        int a9)
{
  int v9; // ecx
  unsigned int v10; // edx
  _DWORD *v12; // ebx
  bool v13; // zf
  int v14; // ecx
  unsigned int v15; // edx
  int v16; // ecx
  int v17; // edx
  unsigned int v18; // eax
  int v19; // ebx
  unsigned int v20; // ecx
  int v21; // eax
  _DWORD *v22; // edi
  int v23; // esi
  unsigned int v24; // edi
  _DWORD *v25; // ecx
  unsigned int v26; // esi
  _DWORD *v27; // edx
  unsigned int v28; // ecx
  unsigned int v29; // eax
  int v30; // edi
  int v31; // edx
  unsigned int v32; // ebx
  int v33; // esi
  _DWORD *v34; // ecx
  unsigned int v35; // eax
  int v36; // eax
  int *v37; // ecx
  int v38; // edi
  int v39; // esi
  _DWORD *v40; // edx
  unsigned int v41; // eax
  unsigned int m; // edx
  int v43; // edi
  unsigned int v44; // ebx
  int v45; // eax
  int v46; // ecx
  int v47; // edx
  _DWORD *v48; // ecx
  int v49; // eax
  unsigned int i; // eax
  int v51; // ecx
  _DWORD v52[40]; // [esp+0h] [ebp-1C4h] BYREF
  _DWORD v53[40]; // [esp+A0h] [ebp-124h] BYREF
  _DWORD v54[4]; // [esp+140h] [ebp-84h] BYREF
  _DWORD v55[16]; // [esp+150h] [ebp-74h] BYREF
  unsigned int k; // [esp+190h] [ebp-34h]
  int v57; // [esp+194h] [ebp-30h]
  unsigned int v58; // [esp+198h] [ebp-2Ch]
  int v59; // [esp+19Ch] [ebp-28h]
  unsigned int v60; // [esp+1A0h] [ebp-24h]
  unsigned int v61; // [esp+1A4h] [ebp-20h]
  unsigned int v62; // [esp+1A8h] [ebp-1Ch]
  int **v63; // [esp+1ACh] [ebp-18h]
  _DWORD *v64; // [esp+1B0h] [ebp-14h]
  unsigned int v65; // [esp+1B4h] [ebp-10h] BYREF
  int v66; // [esp+1B8h] [ebp-Ch]
  unsigned int j; // [esp+1BCh] [ebp-8h]
  unsigned int n; // [esp+1C0h] [ebp-4h]

  v64 = this;
  v9 = *a2;
  v10 = *a2 & 0xFFFFF;
  v66 = 0;
  v65 = 0;
  v62 = v10;
  if ( v10 > a8 && !a9 )
    return 1;
  v12 = a3;
  if ( (v9 & 0xFFF00000) != a3[1] )
    return 1;
  v13 = *a3 == 0;
  v58 = 1;
  if ( v13 && a9 )
    v58 = 2;
  v59 = 0;
  while ( 1 )
  {
    v14 = v12[7] + 1;
    v61 = 0;
    if ( v14 )
      break;
LABEL_91:
    if ( !v66 )
    {
LABEL_95:
      v49 = 4 * v65;
      qmemcpy(a4, v55, 4 * v65);
      *(_DWORD *)&a4[v49] = a2;
      *a5 = v65 + 1;
      for ( i = 0; i < 40; ++i )
      {
        v51 = v53[i];
        if ( v51 == -1 )
        {
          v51 = v52[i];
          if ( v51 == -1 )
            continue;
        }
        *(_DWORD *)(i * 4 + a6) = v51;
      }
      return 0;
    }
    if ( ++v59 >= v58 )
      return v66;
  }
  while ( 1 )
  {
    v15 = *a5;
    qmemcpy(v55, a4, 4 * *a5);
    memset(v53, 0xFFu, sizeof(v53));
    memset(v52, 0xFFu, sizeof(v52));
    v13 = v12[2] == 0;
    v65 = v15;
    v66 = 0;
    j = 0;
    if ( !v13 )
      break;
LABEL_30:
    v27 = a3;
    v13 = a3[2] == 0;
    j = 0;
    if ( !v13 )
    {
      v63 = 0;
      do
      {
        if ( v61 )
          v28 = 1 - j;
        else
          v28 = j;
        if ( v27[v28 + 3] >= 0x10u )
        {
          v29 = 0;
          v60 = 0;
          if ( v65 )
          {
            do
            {
              v30 = 0;
              if ( v62 )
              {
                v31 = v55[v29];
                v32 = *(_DWORD *)(v31 + 12);
                while ( 1 )
                {
                  n = 0;
                  if ( v32 )
                    break;
LABEL_43:
                  if ( ++v30 >= v62 )
                    goto LABEL_46;
                }
                v33 = *(_DWORD *)(a2[2] + 4 * ((_DWORD)v63 + v30));
                v34 = *(_DWORD **)(v31 + 16);
                while ( v33 != *v34 )
                {
                  ++n;
                  ++v34;
                  if ( n >= v32 )
                    goto LABEL_43;
                }
                v66 = 1;
              }
LABEL_46:
              v29 = ++v60;
            }
            while ( v60 < v65 );
            v27 = a3;
          }
        }
        ++j;
        v63 = (int **)((char *)v63 + v62);
      }
      while ( j < v27[2] );
    }
    if ( !v66 )
    {
      if ( v59 || *a3 )
        goto LABEL_95;
      for ( j = 0; j < v65; ++j )
      {
        v35 = *(_DWORD *)(v55[j] + 12);
        n = 0;
        for ( k = v35; n < k; ++n )
        {
          v36 = v64[3];
          if ( v36 )
          {
            v63 = (int **)v64[6];
            v57 = v36;
            do
            {
              v37 = *v63;
              if ( *v63 && *v37 )
              {
                v38 = v37[1];
                v60 = 0;
                if ( v38 )
                {
                  v39 = *(_DWORD *)(*(_DWORD *)(v55[j] + 16) + 4 * n);
                  v40 = (_DWORD *)v37[2];
                  do
                  {
                    if ( *v40 == v39 || *(_DWORD *)(*(_DWORD *)(v64[5] + 4 * *v40) + 56) == v39 )
                      v60 = 1;
                    ++v40;
                    --v38;
                  }
                  while ( v38 );
                }
                if ( v37 == a2 )
                  v41 = 0;
                else
                  v41 = v60;
                if ( v41 )
                {
                  for ( m = 0; m < v65; ++m )
                  {
                    if ( v37 == (int *)v55[m] )
                      v41 = 0;
                  }
                  if ( v41 )
                    v66 = 1;
                }
              }
              ++v63;
              --v57;
            }
            while ( v57 );
          }
        }
      }
      for ( n = 0; n < 0x28; ++n )
      {
        v43 = v53[n];
        if ( v43 != -1 )
        {
          v44 = 0;
          if ( v65 )
          {
            v45 = *(_DWORD *)(v64[5] + 4 * v43);
            do
            {
              v46 = v55[v44];
              v47 = *(_DWORD *)(v46 + 12);
              if ( v47 )
              {
                v48 = *(_DWORD **)(v46 + 16);
                do
                {
                  if ( v43 == *v48 || *(_DWORD *)(v45 + 56) == *v48 )
                    v66 = 1;
                  ++v48;
                  --v47;
                }
                while ( v47 );
              }
              ++v44;
            }
            while ( v44 < v65 );
          }
        }
      }
      if ( !v66 )
        goto LABEL_95;
    }
    ++v61;
    v12 = a3;
    if ( v61 >= a3[7] + 1 )
      goto LABEL_91;
  }
  n = 0;
  while ( 1 )
  {
    v16 = v61 ? 1 - j : j;
    if ( (unsigned int)*a7 >= 4 )
      return 1;
    v17 = a2[2];
    v18 = n;
    v19 = *(_DWORD *)(v64[5] + 4 * *(_DWORD *)(v17 + 4 * (n + *a7)));
    v20 = a3[v16 + 3];
    if ( v20 >= 0x10 )
    {
      v24 = 0;
      v25 = &v53[4 * v20 - 64];
      do
      {
        v26 = a7[v24];
        if ( v26 >= v62 )
          *v25 = -1;
        else
          *v25 = *(_DWORD *)(v17 + 4 * (v18 + v26));
        ++v24;
        ++v25;
      }
      while ( v24 < 4 );
    }
    else
    {
      v21 = *(_DWORD *)(v19 + 72);
      if ( v21 == -1
        || (v22 = &a3[8 * (v20 - *a3)],
            v23 = v64[6],
            sub_6BB1AA(v64, *(int **)(v23 + 4 * v21), v17 + 4 * n, v62, a7, v54, v22[6], a9)) )
      {
        v66 = 1;
        goto LABEL_30;
      }
      v66 = sub_6BB35B(*(_DWORD *)(v23 + 4 * *(_DWORD *)(v19 + 72)), v22, v55, &v65, v52, v54, a8, a9);
    }
    if ( v66 != 1 )
    {
      ++j;
      n += v62;
      if ( j < a3[2] )
        continue;
    }
    goto LABEL_30;
  }
}
