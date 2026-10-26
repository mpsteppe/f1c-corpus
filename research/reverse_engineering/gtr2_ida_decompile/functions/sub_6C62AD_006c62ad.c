int __thiscall sub_6C62AD(_DWORD *this, unsigned int a2, int a3, unsigned int a4, int a5, unsigned int a6)
{
  unsigned int v6; // eax
  int v7; // edx
  int v9; // ecx
  char *v10; // edi
  unsigned int v11; // edx
  char *v12; // edi
  unsigned int v13; // ecx
  unsigned int v14; // edx
  _DWORD *v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // ecx
  unsigned int *v18; // eax
  int v19; // edx
  unsigned int v20; // eax
  unsigned int v21; // ecx
  _DWORD *v22; // ecx
  int v23; // edi
  int v24; // eax
  _DWORD *v25; // eax
  int v26; // ecx
  int v27; // esi
  _DWORD *Block; // [esp+14h] [ebp-4h]
  int v30; // [esp+2Ch] [ebp+14h]
  int *v31; // [esp+30h] [ebp+18h]

  Block = 0;
  v6 = 0;
  v7 = 0;
  if ( a6 )
  {
    v9 = this[84];
    do
    {
      if ( v9 == *(_DWORD *)(a5 + 4 * v6) )
        v7 = 1;
      ++v6;
    }
    while ( v6 < a6 );
  }
  if ( this[83] <= a2 || v7 )
  {
    this[79] = -1;
    this[80] = -1;
    this[81] = -1;
    this[82] = -1;
    v10 = (char *)operator new(4 * this[11]);
    Block = v10;
    if ( !v10 )
    {
LABEL_42:
      v27 = -2147024882;
      goto LABEL_41;
    }
    v11 = 4 * this[11];
    memset(v10, 0xFFu, 4 * (v11 >> 2));
    v12 = &v10[4 * (v11 >> 2)];
    v13 = v11 & 3;
    v14 = 0;
    memset(v12, -1, v13);
    if ( this[2] )
    {
      do
      {
        v15 = *(_DWORD **)(this[5] + 4 * v14);
        if ( this[34] == v15[1] && v15[2] == -1 )
        {
          v16 = v15[3];
          if ( v16 < this[11] )
          {
            if ( v15[18] < a2 && v15[22] >= a2 )
              Block[v16] = 0;
            v17 = v15[18];
            if ( v17 >= a2 )
            {
              v18 = &Block[v15[3]];
              if ( v17 < *v18 )
                *v18 = v17;
            }
          }
        }
        ++v14;
      }
      while ( v14 < this[2] );
    }
    v19 = this[11];
    v20 = 0;
    this[84] = 0;
    this[83] = 0;
    if ( v19 )
    {
      do
      {
        v21 = 0;
        if ( !a6 )
          goto LABEL_45;
        do
        {
          if ( v20 == *(_DWORD *)(a5 + 4 * v21) )
            break;
          ++v21;
        }
        while ( v21 < a6 );
        if ( v21 >= a6 )
        {
LABEL_45:
          v22 = &Block[v20];
          if ( this[83] < *v22 )
          {
            this[84] = v20;
            this[83] = *v22;
          }
        }
        ++v20;
      }
      while ( v20 < this[11] );
    }
    if ( this[83] <= a2 )
    {
      this[83] = -1;
      this[84] = v19;
    }
  }
  v30 = 0;
  v23 = a4 != 1 ? 0 : 3;
  if ( a4 )
  {
    v31 = &this[v23 + 79];
    do
    {
      if ( *v31 != -1 )
        *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v31) + 80) = a2;
      v24 = sub_681AAA(this, this[34], this[84], v23, 0.0);
      *v31 = v24;
      if ( v24 == -1 )
        goto LABEL_42;
      v25 = *(_DWORD **)(this[5] + 4 * v24);
      v25[15] = 0;
      v25[12] = 0;
      v25[18] = a2;
      v25[20] = this[83];
      v25[21] = a2;
      v25[22] = a2;
      v25[23] = 1;
      v26 = *(_DWORD *)(this[6] + 4 * a2);
      if ( *(_DWORD *)(v26 + 12) )
      {
        v25[6] = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(v26 + 16)) + 24);
        v25[5] = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(*(_DWORD *)(this[6] + 4 * a2) + 16)) + 20);
      }
      if ( a3 )
        *(_DWORD *)(a3 + 4 * v30) = *v31;
      ++v31;
      ++v23;
    }
    while ( ++v30 < a4 );
  }
  v27 = 0;
LABEL_41:
  j__free(Block);
  return v27;
}
