int __thiscall sub_6863CE(_DWORD *this)
{
  unsigned int i; // ecx
  _DWORD *v3; // eax
  int v4; // esi
  unsigned int k; // ebx
  unsigned int m; // ebx
  int v7; // eax
  unsigned int v8; // ebx
  int *v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // esi
  unsigned int ii; // ebx
  unsigned int jj; // ebx
  int v15; // eax
  int v17; // esi
  unsigned int v18; // eax
  unsigned int mm; // edx
  int v20; // eax
  int v21; // ecx
  int v22; // ebx
  unsigned int v23; // eax
  unsigned int nn; // edx
  int v25; // eax
  int v26; // ecx
  int v27; // ebx
  unsigned int kk; // [esp+Ch] [ebp-8h]
  unsigned int j; // [esp+10h] [ebp-4h]
  unsigned int n; // [esp+10h] [ebp-4h]
  int v31; // [esp+10h] [ebp-4h]
  int v32; // [esp+10h] [ebp-4h]

  sub_686074((int)this);
  for ( i = 0; i < this[3]; v3[7] = 0 )
  {
    v3 = *(_DWORD **)(this[6] + 4 * i++);
    v3[6] = 0;
    v3[8] = 0;
    v3[5] = 0;
  }
  for ( j = 0; j < this[3]; ++j )
  {
    v4 = *(_DWORD *)(this[6] + 4 * j);
    if ( (*(_WORD *)(v4 + 2) & 0xFFF0) != 0 )
    {
      for ( k = 0; k < *(_DWORD *)(v4 + 12); ++k )
        sub_686341(this, *(_DWORD *)(*(_DWORD *)(v4 + 16) + 4 * k), j, 0);
      for ( m = 0; m < *(_DWORD *)(v4 + 4); ++m )
      {
        v7 = *(_DWORD *)(*(_DWORD *)(v4 + 8) + 4 * m);
        if ( v7 != -1 && *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v7) + 56) != -1 )
          v7 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v7) + 56);
        sub_686341(this, v7, j, 1);
      }
    }
  }
  v8 = 0;
  if ( this[3] )
  {
    while ( 1 )
    {
      v9 = *(int **)(this[6] + 4 * v8);
      if ( v9[5] )
      {
        v10 = sub_681169(v9[5]);
        v9[6] = v10;
        if ( !v10 )
          return -2147024882;
      }
      if ( v9[7] )
      {
        v11 = sub_681169(v9[7]);
        v9[8] = v11;
        if ( !v11 )
          return -2147024882;
      }
      ++v8;
      v9[5] = 0;
      v9[7] = 0;
      if ( v8 >= this[3] )
        goto LABEL_19;
    }
  }
  else
  {
LABEL_19:
    for ( n = 0; n < this[3]; ++n )
    {
      v12 = *(_DWORD *)(this[6] + 4 * n);
      if ( (*(_WORD *)(v12 + 2) & 0xFFF0) != 0 )
      {
        for ( ii = 0; ii < *(_DWORD *)(v12 + 12); ++ii )
          sub_686341(this, *(_DWORD *)(*(_DWORD *)(v12 + 16) + 4 * ii), n, 0);
        for ( jj = 0; jj < *(_DWORD *)(v12 + 4); ++jj )
        {
          v15 = *(_DWORD *)(*(_DWORD *)(v12 + 8) + 4 * jj);
          if ( v15 != -1 && *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v15) + 56) != -1 )
            v15 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v15) + 56);
          sub_686341(this, v15, n, 1);
        }
      }
    }
    for ( kk = 0; kk < this[3]; ++kk )
    {
      v17 = *(_DWORD *)(this[6] + 4 * kk);
      v18 = *(_DWORD *)(v17 + 20);
      if ( v18 )
      {
        sub_682274(sub_6CD35F, *(int **)(v17 + 24), v18, 0);
        v31 = 1;
        for ( mm = 1; mm < *(_DWORD *)(v17 + 20); ++mm )
        {
          v20 = *(_DWORD *)(v17 + 24);
          v21 = *(_DWORD *)(v20 + 4 * mm);
          if ( v21 != *(_DWORD *)(v20 + 4 * mm - 4) )
          {
            v22 = v31++;
            *(_DWORD *)(v20 + 4 * v22) = v21;
          }
        }
        *(_DWORD *)(v17 + 20) = v31;
      }
      v23 = *(_DWORD *)(v17 + 28);
      if ( v23 )
      {
        sub_682274(sub_6CD35F, *(int **)(v17 + 32), v23, 0);
        v32 = 1;
        for ( nn = 1; nn < *(_DWORD *)(v17 + 28); ++nn )
        {
          v25 = *(_DWORD *)(v17 + 32);
          v26 = *(_DWORD *)(v25 + 4 * nn);
          if ( v26 != *(_DWORD *)(v25 + 4 * nn - 4) )
          {
            v27 = v32++;
            *(_DWORD *)(v25 + 4 * v27) = v26;
          }
        }
        *(_DWORD *)(v17 + 28) = v32;
      }
    }
    return 0;
  }
}
