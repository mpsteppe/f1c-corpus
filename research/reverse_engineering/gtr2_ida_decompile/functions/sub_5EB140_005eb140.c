int __thiscall sub_5EB140(_DWORD *this, int a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  int v5; // edx
  int i; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // eax

  v3 = this[90];
  v4 = 0;
  v5 = 0;
  if ( v3 <= 0 )
    return 0;
  for ( i = 0; a2 < v4 || a2 >= v4 + *(_DWORD *)(i + this[91] + 8); i += 108 )
  {
    v4 += *(_DWORD *)(i + this[91] + 8);
    if ( ++v5 >= v3 )
      return 0;
  }
  switch ( a3 )
  {
    case 1:
      v8 = 108 * v5 + this[91];
      v9 = a2 - v4;
      if ( (*(_BYTE *)v8 & 8) != 0 )
        v10 = 88 * v9;
      else
        v10 = v9 << 6;
      return *(_DWORD *)(v8 + 32) + v10;
    case 0x1000:
      return *(_DWORD *)(this[91] + 108 * v5 + 32) + ((a2 - v4) << 6);
    case 0x8000:
      return *(_DWORD *)(this[91] + 108 * v5 + 32) + 88 * (a2 - v4);
    default:
      return 0;
  }
}
