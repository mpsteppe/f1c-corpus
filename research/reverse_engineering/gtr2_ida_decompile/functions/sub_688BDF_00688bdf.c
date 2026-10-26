BOOL __thiscall sub_688BDF(_DWORD *this)
{
  int v1; // ebx
  unsigned int i; // edx
  int v4; // ecx
  int v5; // eax
  int v6; // edi
  unsigned int v7; // edx
  _DWORD *v8; // eax
  int v9; // ecx
  unsigned int j; // edi
  int v12; // eax
  _DWORD *v13; // ecx
  int v14; // [esp+Ch] [ebp-4h]

  v1 = 0;
  v14 = 0;
  sub_686074((int)this);
  for ( i = 0; i < this[1]; ++i )
  {
    v4 = *(_DWORD *)(this[4] + 4 * i);
    v5 = *(_DWORD *)(v4 + 4);
    if ( (v5 & 0x400) != 0 && *(_DWORD *)(v4 + 40) == -1 )
    {
      *(_DWORD *)(v4 + 4) = v5 & 0xFFFFFBFF;
      v14 = 1;
    }
  }
  v6 = 0;
  v7 = 0;
  if ( this[2] )
  {
    do
    {
      v8 = *(_DWORD **)(this[5] + 4 * v7);
      v9 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * v8[1]) + 4);
      if ( (v9 & 0x100) != 0 && (v9 & 0x800) != 0 )
        v8[21] = 1;
      if ( v8[21] == -1 && v8[18] == -1 )
        v8[12] = -1;
      else
        v8[12] = v6++;
      ++v7;
    }
    while ( v7 < this[2] );
    v1 = 0;
  }
  if ( v6 == this[2] )
    return v14 == 0;
  sub_68661F(this);
  for ( j = 0; j < this[2]; ++j )
  {
    v12 = this[5];
    v13 = *(_DWORD **)(v12 + 4 * j);
    if ( v13[21] == -1 && v13[18] == -1 )
      sub_663A9B(v13, 1);
    else
      *(_DWORD *)(v12 + 4 * v1++) = v13;
  }
  memset((void *)(this[5] + 4 * v1), 0, 4 * (this[2] - v1));
  this[2] = v1;
  return 0;
}
