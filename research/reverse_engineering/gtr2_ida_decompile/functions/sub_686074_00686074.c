int __thiscall sub_686074(int this)
{
  unsigned int v2; // ebx
  unsigned int i; // ecx
  _DWORD *v4; // eax
  unsigned int j; // ecx
  _DWORD *v6; // eax
  unsigned int k; // eax
  int v8; // ecx
  unsigned int m; // edi
  int v10; // ecx
  int v11; // eax
  int v12; // edx
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  unsigned int v17; // edi
  char *v18; // eax
  int v20; // ecx
  unsigned int v21; // edx
  int v22; // eax
  int v23; // edi
  unsigned int ii; // ebx
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  unsigned int kk; // edi
  _DWORD *v31; // eax
  int v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ecx
  unsigned int mm; // edi
  int v36; // ecx
  int v37; // eax
  int v38; // edx
  int v39; // ecx
  unsigned int v40; // edx
  unsigned int v41; // ecx
  int v42; // ecx
  int v43; // ecx
  unsigned int v44; // edx
  unsigned int v45; // ecx
  char *Block; // [esp+Ch] [ebp-Ch]
  unsigned int jj; // [esp+10h] [ebp-8h]
  unsigned int n; // [esp+14h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < *(_DWORD *)(this + 4); v4[8] = 0 )
  {
    v4 = *(_DWORD **)(*(_DWORD *)(this + 16) + 4 * i);
    v4[10] = -1;
    ++i;
    v4[11] = 0;
    v4[12] = 0;
  }
  for ( j = 0; j < *(_DWORD *)(this + 8); v6[20] = -1 )
  {
    v6 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * j);
    v6[13] = j++;
    v6[21] = -1;
    v6[22] = 0;
    v6[23] = 0;
    v6[18] = -1;
    v6[19] = -1;
  }
  Block = 0;
  if ( *(_DWORD *)(this + 220) )
  {
    for ( k = 0; k < *(_DWORD *)(this + 4); *(_DWORD *)(v8 + 16) = 0 )
      v8 = *(_DWORD *)(*(_DWORD *)(this + 16) + 4 * k++);
    for ( m = 0; m < *(_DWORD *)(this + 8); ++m )
    {
      v10 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * m);
      v11 = *(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v10 + 4));
      v12 = *(_DWORD *)(v11 + 4);
      if ( (v12 & 0x40) == 0 && (v12 & 2) != 0 )
      {
        v13 = *(_DWORD *)(v10 + 12) + 1;
        if ( *(_DWORD *)(v11 + 16) < v13 )
          *(_DWORD *)(v11 + 16) = v13;
      }
    }
    v14 = *(_DWORD *)(this + 4);
    v15 = 0;
    if ( v14 )
    {
      v16 = *(_DWORD *)(this + 16);
      do
      {
        v15 += *(_DWORD *)(*(_DWORD *)v16 + 16);
        v16 += 4;
        --v14;
      }
      while ( v14 );
    }
    v17 = 16 * v15;
    v18 = (char *)operator new(16 * v15);
    Block = v18;
    if ( !v18 )
      return -2147024882;
    memset(v18, 0xFFu, v17);
    v20 = 0;
    v21 = 0;
    if ( *(_DWORD *)(this + 4) )
    {
      v22 = *(_DWORD *)(this + 16);
      do
      {
        *(_DWORD *)(*(_DWORD *)(v22 + 4 * v21) + 32) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v21) + 16) != 0
                                                     ? &Block[16 * v20]
                                                     : 0;
        v22 = *(_DWORD *)(this + 16);
        v20 += *(_DWORD *)(*(_DWORD *)(v22 + 4 * v21++) + 16);
      }
      while ( v21 < *(_DWORD *)(this + 4) );
      v2 = 0;
    }
  }
  for ( n = 0; n < *(_DWORD *)(this + 12); ++n )
  {
    v23 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * n);
    if ( v23 && (*(_WORD *)(v23 + 2) & 0xFFF0) != 0 )
    {
      if ( *(_DWORD *)(v23 + 4) )
      {
        do
          sub_685EE9((_DWORD *)this, *(_DWORD *)(*(_DWORD *)(v23 + 8) + 4 * v2++), n);
        while ( v2 < *(_DWORD *)(v23 + 4) );
      }
      for ( ii = 0; ii < *(_DWORD *)(v23 + 12); ++ii )
        sub_685F47((_DWORD *)this, *(_DWORD *)(*(_DWORD *)(v23 + 16) + 4 * ii), n);
      if ( (*(_DWORD *)v23 & 0xFFF00000) == 0x10000000 && (*(_BYTE *)(this + 204) & 4) == 0 )
      {
        for ( jj = 0; jj < *(_DWORD *)(v23 + 12); ++jj )
        {
          v25 = *(_DWORD *)(this + 20);
          v26 = *(_DWORD *)(v25 + 4 * *(_DWORD *)(4 * jj + *(_DWORD *)(v23 + 16)));
          v27 = *(_DWORD *)(v25 + 4 * *(_DWORD *)(4 * jj + *(_DWORD *)(v23 + 8)));
          v28 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v26 + 4)) + 4);
          if ( (v28 & 0x1020) == 0 && (v28 & 1) != 0 && !*(_DWORD *)(v27 + 60) )
          {
            v29 = *(_DWORD *)(v26 + 52);
            *(_DWORD *)(v26 + 52) = *(_DWORD *)(v27 + 52);
            *(_DWORD *)(v27 + 52) = v29;
          }
        }
      }
      v2 = 0;
    }
  }
  for ( kk = 0; kk < *(_DWORD *)(this + 8); ++kk )
  {
    v31 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * kk);
    v32 = *(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v31[1]);
    v33 = *(_DWORD *)(v32 + 40);
    if ( v31[21] > v33 )
      v31[21] = v33;
    v34 = *(_DWORD *)(v32 + 44);
    if ( v31[22] < v34 )
      v31[22] = v34;
  }
  if ( *(_DWORD *)(this + 220) )
  {
    for ( mm = 0; mm < *(_DWORD *)(this + 8); ++mm )
    {
      v36 = *(_DWORD *)(this + 20);
      v37 = *(_DWORD *)(v36 + 4 * mm);
      v38 = *(_DWORD *)(v37 + 76);
      if ( v38 == -1 )
      {
        *(_DWORD *)(v37 + 76) = 0;
      }
      else
      {
        v39 = *(_DWORD *)(v36 + 4 * v38);
        v40 = *(_DWORD *)(v39 + 88);
        *(_DWORD *)(v37 + 76) = v40;
        v41 = *(_DWORD *)(v39 + 72);
        if ( v40 <= v41 )
          *(_DWORD *)(v37 + 76) = v41 + 1;
      }
      v42 = *(_DWORD *)(v37 + 80);
      if ( v42 == -1 )
      {
        *(_DWORD *)(v37 + 80) = -1;
      }
      else
      {
        v43 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v42);
        v44 = *(_DWORD *)(v43 + 84);
        *(_DWORD *)(v37 + 80) = v44;
        v45 = *(_DWORD *)(v43 + 72);
        if ( v44 > v45 )
          *(_DWORD *)(v37 + 80) = v45;
      }
    }
  }
  if ( *(_DWORD *)(this + 216) )
    sub_685FA9((_DWORD *)this);
  j__free(Block);
  return 0;
}
