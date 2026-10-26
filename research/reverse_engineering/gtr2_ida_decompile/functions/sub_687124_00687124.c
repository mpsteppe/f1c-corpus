int __thiscall sub_687124(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  unsigned int v4; // edx
  int v5; // edi
  int v6; // eax
  _DWORD *v7; // edx
  int v8; // ecx
  int v9; // eax
  _DWORD *v10; // ebx
  int v11; // eax
  int result; // eax
  unsigned int j; // ecx
  _DWORD *v14; // eax
  int v15; // [esp+14h] [ebp-18h]
  int v16; // [esp+18h] [ebp-14h]
  int v17; // [esp+1Ch] [ebp-10h]
  _DWORD *v18; // [esp+1Ch] [ebp-10h]
  unsigned int i; // [esp+20h] [ebp-Ch]
  unsigned int v20; // [esp+24h] [ebp-8h]
  unsigned int v21; // [esp+28h] [ebp-4h]
  int v22; // [esp+28h] [ebp-4h]

  v2 = this[2];
  v21 = 0;
  if ( v2 )
  {
    v3 = this[5];
    do
    {
      v4 = *(_DWORD *)(*(_DWORD *)v3 + 12);
      if ( v4 > v21 && v4 != -1 )
        v21 = *(_DWORD *)(*(_DWORD *)v3 + 12);
      v3 += 4;
      --v2;
    }
    while ( v2 );
  }
  v22 = v21 + 1;
  for ( i = 0; i < this[3]; ++i )
  {
    v5 = *(_DWORD *)(this[6] + 4 * i);
    v6 = *(_DWORD *)(v5 + 12);
    if ( v6 )
    {
      v7 = *(_DWORD **)(v5 + 16);
      v17 = *(_DWORD *)(v5 + 12);
      do
      {
        v8 = *(_DWORD *)(this[5] + 4 * *v7);
        if ( *(_DWORD *)(v8 + 68) == -1 && (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v8 + 4)) + 4) & 0x20) != 0 )
          --v6;
        ++v7;
        --v17;
      }
      while ( v17 );
    }
    if ( v6 != *(_DWORD *)(v5 + 12) )
    {
      v18 = 0;
      if ( v6 )
      {
        v9 = sub_681B0A(this, v6 & 0xFFFFF | 0x10000000, v6, v6);
        if ( v9 == -1 )
          return -2147024882;
        v18 = *(_DWORD **)(this[6] + 4 * v9);
        sub_680D22(v18, v5);
      }
      v20 = 0;
      if ( *(_DWORD *)(v5 + 12) )
      {
        v16 = 0;
        do
        {
          v10 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v5 + 16) + 4 * v20));
          v15 = *(_DWORD *)(this[4] + 4 * v10[1]);
          v11 = sub_681AAA(this, this[34], v22, v10[4], 0.0);
          if ( v10[17] != -1 || (*(_BYTE *)(v15 + 4) & 0x20) == 0 )
          {
            *(_DWORD *)(v16 + v18[4]) = *(_DWORD *)(*(_DWORD *)(v5 + 16) + 4 * v20);
            *(_DWORD *)(v16 + v18[2]) = v11;
            v16 += 4;
          }
          *(_DWORD *)(*(_DWORD *)(v5 + 16) + 4 * v20++) = v11;
        }
        while ( v20 < *(_DWORD *)(v5 + 12) );
      }
      ++v22;
    }
  }
  result = sub_686074((int)this);
  if ( result >= 0 )
  {
    for ( j = 0; j < this[2]; ++j )
    {
      v14 = *(_DWORD **)(this[5] + 4 * j);
      if ( v14[18] == -1 && v14[21] == -1 )
        v14[1] = this[29];
    }
    return 0;
  }
  return result;
}
