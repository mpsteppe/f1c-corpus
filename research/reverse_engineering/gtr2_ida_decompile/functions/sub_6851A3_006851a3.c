int __thiscall sub_6851A3(_DWORD *this, int a2, _DWORD *a3, char *a4)
{
  unsigned int v4; // edx
  unsigned int i; // eax
  char *v7; // ebx
  unsigned int v8; // ecx
  int v9; // edi
  int v10; // esi
  _DWORD *v11; // eax
  unsigned int v12; // edi
  int v13; // ecx
  unsigned int j; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // esi
  int v19; // ecx
  int v20; // eax
  unsigned int k; // ecx
  unsigned int v22; // eax
  _DWORD *v23; // edx
  unsigned int v24; // esi
  int v25; // ecx
  int v26; // eax
  unsigned int n; // ebx
  int v28; // esi
  int v29; // eax
  _DWORD v30[4]; // [esp+4h] [ebp-28h] BYREF
  int v31; // [esp+14h] [ebp-18h]
  unsigned int v32; // [esp+18h] [ebp-14h]
  char *m; // [esp+1Ch] [ebp-10h]
  _DWORD *v34; // [esp+20h] [ebp-Ch]
  unsigned int v35; // [esp+24h] [ebp-8h]
  unsigned int v36; // [esp+28h] [ebp-4h]
  int v37; // [esp+3Ch] [ebp+10h]

  v4 = 0;
  v34 = this;
  v36 = 0;
  for ( i = 0; i < 4; ++i )
  {
    if ( a3[i] == -1 )
      break;
    ++v36;
  }
  if ( !v36 )
    return 0;
  v7 = a4;
  if ( (this[27] & 6) == 0 )
  {
    memset(a4, 0, 4 * v36);
    goto LABEL_8;
  }
  v12 = 1;
  if ( v36 > 1 )
  {
    v13 = this[5];
    do
    {
      if ( *(double *)(*(_DWORD *)(v13 + 4 * *a3) + 32) != *(double *)(*(_DWORD *)(v13 + 4 * a3[v12]) + 32) )
        break;
      ++v12;
    }
    while ( v12 < v36 );
  }
  if ( v12 == v36 )
  {
    *(_DWORD *)a4 = 0;
    v36 = 1;
  }
  for ( j = 0; j < v36; ++j )
    v4 += *(_DWORD *)&a4[4 * j] == 0;
  if ( (v34[27] & 4) != 0 && v4 )
  {
    if ( v4 <= 1 )
    {
      v15 = 0;
      while ( 1 )
      {
        v16 = *(_DWORD *)&a4[4 * v15];
        if ( (v16 & 8) != 0 )
          break;
        if ( !v16 )
          *(_DWORD *)&a4[4 * v15] = 8;
        if ( ++v15 >= v36 )
        {
          v4 = 0;
          goto LABEL_31;
        }
      }
    }
    return -2147467259;
  }
LABEL_31:
  v17 = 0;
  v18 = 0;
  if ( v36 )
  {
    do
    {
      v19 = *(_DWORD *)&a4[4 * v17];
      if ( (v19 & v18) != 0 )
        return -2147467259;
      v18 |= v19;
    }
    while ( ++v17 < v36 );
  }
  v20 = 0;
  for ( k = 0; k < 4; ++k )
  {
    if ( ((1 << k) & v18) != 0 )
      ++v20;
  }
  if ( v4 + v20 > 4 )
    return -2147467259;
LABEL_8:
  v31 = 0;
  for ( m = (char *)a2; ; m += 16 )
  {
    v35 = 0;
    v30[0] = *(_DWORD *)m;
    v30[1] = *((_DWORD *)m + 1);
    v30[2] = *((_DWORD *)m + 2);
    v30[3] = *((_DWORD *)m + 3);
    if ( !v36 )
      goto LABEL_59;
    do
    {
      v8 = 0;
      v9 = v35;
      v10 = *(_DWORD *)&v7[4 * v35];
      do
      {
        if ( ((1 << v8) & v10) != 0 )
        {
          v11 = &v30[v8];
          if ( *v11 == -1 )
          {
            *v11 = a3[v9];
          }
          else
          {
            v7 = a4;
            if ( *(double *)(*(_DWORD *)(v34[5] + 4 * *v11) + 32) != *(double *)(*(_DWORD *)(v34[5] + 4 * a3[v9]) + 32) )
              break;
          }
        }
        ++v8;
      }
      while ( v8 < 4 );
      if ( v8 < 4 )
        break;
      ++v35;
    }
    while ( v35 < v36 );
    if ( v35 >= v36 )
    {
LABEL_59:
      v22 = 0;
      v32 = 0;
      if ( !v36 )
        break;
      v23 = a3;
      v35 = v7 - (char *)a3;
      do
      {
        v24 = 0;
        if ( !*(_DWORD *)((char *)v23 + v35) )
        {
          do
          {
            v25 = v30[v24];
            if ( v25 != -1 )
            {
              v7 = a4;
              if ( *(double *)(*(_DWORD *)(v34[5] + 4 * v25) + 32) == *(double *)(*(_DWORD *)(v34[5] + 4 * a3[v22]) + 32) )
                break;
            }
            ++v24;
          }
          while ( v24 < 4 );
          if ( v24 >= 4 )
          {
            v26 = 0;
            while ( v30[v26] != -1 )
            {
              if ( (unsigned int)++v26 >= 4 )
                goto LABEL_57;
            }
            v30[v26] = *v23;
LABEL_57:
            if ( v26 == 4 )
              break;
          }
        }
        v22 = v32 + 1;
        ++v23;
        ++v32;
      }
      while ( v32 < v36 );
      if ( v32 >= v36 )
        break;
    }
    ++v31;
  }
  v37 = m - (char *)v30;
  for ( n = 0; n < 4; ++n )
  {
    v28 = 4 * n;
    v29 = v30[n];
    if ( v29 != *(_DWORD *)((char *)&v30[n] + v37) )
      v29 = sub_685050(v34, a2, v31, n, v30[n]);
    *(_DWORD *)((char *)v30 + (char *)a3 - (char *)v30 + v28) = v29;
  }
  return 0;
}
