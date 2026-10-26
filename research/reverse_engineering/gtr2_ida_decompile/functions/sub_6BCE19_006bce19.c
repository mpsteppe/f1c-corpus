int __thiscall sub_6BCE19(_DWORD *this)
{
  int *v1; // edx
  int v2; // eax
  int result; // eax
  int v4; // eax
  int v5; // ebx
  unsigned int v6; // ecx
  int v7; // esi
  unsigned int v8; // ecx
  _DWORD *v9; // edx
  int v10; // eax
  int v11; // esi
  int *v12; // edi
  unsigned int v13; // edi
  _DWORD *v14; // ecx
  unsigned int v15; // edx
  int v16; // edi
  int v17; // edx
  unsigned int v18; // ebx
  int v19; // esi
  _DWORD *v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // eax
  int v23; // eax
  _DWORD **v24; // ecx
  _DWORD *v25; // ecx
  int v26; // edi
  int v27; // esi
  _DWORD *v28; // edx
  int v29; // eax
  int v30; // eax
  unsigned int m; // edx
  bool v32; // zf
  int v33; // eax
  unsigned int v34; // edi
  int v35; // ebx
  int v36; // ecx
  int v37; // edx
  _DWORD *v38; // ecx
  unsigned int n; // eax
  int v40; // ecx
  _DWORD *v41; // eax
  char *v42; // ebx
  int v43; // esi
  char *v44; // ecx
  _DWORD *v45; // edx
  _DWORD v46[40]; // [esp+8h] [ebp-274h] BYREF
  _DWORD v47[40]; // [esp+A8h] [ebp-1D4h] BYREF
  _DWORD v48[40]; // [esp+148h] [ebp-134h]
  int v49[4]; // [esp+1E8h] [ebp-94h] BYREF
  _DWORD v50[16]; // [esp+1F8h] [ebp-84h] BYREF
  int v51[4]; // [esp+238h] [ebp-44h] BYREF
  unsigned int k; // [esp+248h] [ebp-34h]
  int v53; // [esp+24Ch] [ebp-30h]
  _DWORD **v54; // [esp+250h] [ebp-2Ch]
  int v55; // [esp+254h] [ebp-28h]
  int v56; // [esp+258h] [ebp-24h]
  _DWORD *v57; // [esp+25Ch] [ebp-20h]
  int v58; // [esp+260h] [ebp-1Ch]
  unsigned int j; // [esp+264h] [ebp-18h]
  unsigned int v60; // [esp+268h] [ebp-14h]
  unsigned int v61; // [esp+26Ch] [ebp-10h] BYREF
  _DWORD *v62; // [esp+270h] [ebp-Ch]
  int v63; // [esp+274h] [ebp-8h]
  unsigned int i; // [esp+278h] [ebp-4h]

  v51[0] = 0;
  v1 = (int *)this[64];
  v2 = *v1 & 0xFFFFF;
  v62 = this;
  v51[1] = 1;
  v51[2] = 2;
  v51[3] = 3;
  v57 = v1;
  if ( v2 != 1 )
    return 1;
  if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)v1[4]) + 4)) + 4) & 0x20) != 0 )
    return 1;
  v4 = *v1;
  v60 = *v1 & 0xFFFFF;
  if ( v60 > 1 || (v4 & 0xFFF00000) != 0x10500000 )
    return 1;
  v56 = 0;
LABEL_8:
  v58 = 0;
  while ( 2 )
  {
    memset(v47, 0xFFu, sizeof(v47));
    v5 = 0;
    memset(v46, 0xFFu, sizeof(v46));
    v61 = 0;
    v63 = 0;
    i = 0;
    while ( 1 )
    {
      if ( v58 )
        v6 = 1 - i;
      else
        v6 = i;
      v7 = v57[2];
      v8 = dword_74687C[v6];
      v9 = (_DWORD *)(v7 + 4 * v5);
      if ( v8 >= 0x10 )
      {
        v13 = 0;
        v14 = &v47[4 * v8 - 64];
        do
        {
          v15 = v51[v13];
          if ( v15 >= v60 )
            *v14 = -1;
          else
            *v14 = *(_DWORD *)(v7 + 4 * (v5 + v15));
          ++v13;
          ++v14;
        }
        while ( v13 < 4 );
        goto LABEL_22;
      }
      v10 = *(_DWORD *)(*(_DWORD *)(v62[5] + 4 * *v9) + 72);
      if ( v10 == -1 )
        break;
      v11 = 32 * v8;
      v12 = *(int **)(v62[6] + 4 * v10);
      if ( sub_6BB1AA(v62, v12, (int)v9, v60, v51, v49, dword_746888[8 * v8], 0) )
        break;
      v63 = sub_6BB35B(v62, v12, (char *)&unk_746870 + v11, (char *)v50, &v61, (int)v46, v49, 1u, 0);
LABEL_22:
      if ( v63 != 1 )
      {
        ++i;
        v5 += v60;
        if ( !i )
          continue;
      }
      goto LABEL_26;
    }
    v63 = 1;
LABEL_26:
    if ( (unsigned int)dword_74687C[v58 != 0] >= 0x10 )
    {
      for ( i = 0; i < v61; ++i )
      {
        v16 = 0;
        if ( v60 )
        {
          v17 = v50[i];
          v18 = *(_DWORD *)(v17 + 12);
          while ( 1 )
          {
            j = 0;
            if ( v18 )
              break;
LABEL_34:
            if ( ++v16 >= v60 )
              goto LABEL_37;
          }
          v19 = *(_DWORD *)(v57[2] + 4 * v16);
          v20 = *(_DWORD **)(v17 + 16);
          while ( v19 != *v20 )
          {
            ++j;
            ++v20;
            if ( j >= v18 )
              goto LABEL_34;
          }
          v63 = 1;
        }
LABEL_37:
        ;
      }
    }
    if ( v63 )
      goto LABEL_78;
    if ( !v56 )
    {
      v21 = 0;
      for ( j = 0; j < v61; ++j )
      {
        v22 = *(_DWORD *)(v50[v21] + 12);
        i = 0;
        for ( k = v22; i < k; ++i )
        {
          v23 = v62[3];
          if ( v23 )
          {
            v24 = (_DWORD **)v62[6];
            v54 = v24;
            v53 = v23;
            do
            {
              v25 = *v24;
              if ( v25 && *v25 )
              {
                v26 = v25[1];
                v55 = 0;
                if ( v26 )
                {
                  v27 = *(_DWORD *)(*(_DWORD *)(v50[j] + 16) + 4 * i);
                  v28 = (_DWORD *)v25[2];
                  v29 = v26;
                  do
                  {
                    if ( *v28 == v27 || *(_DWORD *)(*(_DWORD *)(v62[5] + 4 * *v28) + 56) == v27 )
                      v55 = 1;
                    ++v28;
                    --v29;
                  }
                  while ( v29 );
                }
                if ( v25 == v57 )
                  v30 = 0;
                else
                  v30 = v55;
                if ( v30 )
                {
                  for ( m = 0; m < v61; ++m )
                  {
                    if ( v25 == (_DWORD *)v50[m] )
                      v30 = 0;
                  }
                  if ( v30 )
                    v63 = 1;
                }
              }
              v24 = v54 + 1;
              v32 = v53-- == 1;
              ++v54;
            }
            while ( !v32 );
          }
        }
        v21 = j + 1;
      }
      for ( i = 0; i < 0x28; ++i )
      {
        v33 = v47[i];
        if ( v33 != -1 )
        {
          v34 = 0;
          if ( v61 )
          {
            v35 = *(_DWORD *)(v62[5] + 4 * v33);
            do
            {
              v36 = v50[v34];
              v37 = *(_DWORD *)(v36 + 12);
              if ( v37 )
              {
                v38 = *(_DWORD **)(v36 + 16);
                do
                {
                  if ( v33 == *v38 || *(_DWORD *)(v35 + 56) == *v38 )
                    v63 = 1;
                  ++v38;
                  --v37;
                }
                while ( v37 );
              }
              ++v34;
            }
            while ( v34 < v61 );
          }
        }
      }
      if ( v63 )
      {
LABEL_78:
        if ( !++v58 )
          continue;
        if ( ++v56 )
          goto LABEL_87;
        goto LABEL_8;
      }
    }
    break;
  }
  v50[v61] = v57;
  for ( n = 0; n < 40; ++n )
  {
    v40 = v47[n];
    if ( v40 == -1 )
    {
      v40 = v46[n];
      if ( v40 == -1 )
        continue;
    }
    v48[n] = v40;
  }
  v63 = 0;
LABEL_87:
  result = v63;
  if ( !v63 )
  {
    v41 = (_DWORD *)sub_681186(116);
    if ( v41 )
      v42 = (char *)sub_680CEC(v41);
    else
      v42 = 0;
    if ( v42 )
    {
      v43 = sub_6811D1(v42, 1892679681, 2, 1, 0);
      v44 = v42;
      if ( v43 >= 0 )
      {
        v43 = sub_680D22(v42, v62[64]);
        if ( v43 >= 0 )
        {
          v45 = v62;
          qmemcpy(*((void **)v42 + 4), *(const void **)(v62[64] + 16), 4 * *(_DWORD *)(v62[64] + 12));
          **((_DWORD **)v42 + 2) = v48[4];
          *(_DWORD *)(*((_DWORD *)v42 + 2) + 4) = v48[0];
          v43 = sub_681430((char *)v45[64], v42);
        }
        v44 = v42;
      }
      sub_66238F(v44, 1);
      return v43;
    }
    else
    {
      return -2147024882;
    }
  }
  return result;
}
