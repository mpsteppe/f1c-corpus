char __thiscall sub_57BAA0(_DWORD *this)
{
  unsigned int v2; // edx
  unsigned int v3; // eax
  int v4; // ecx
  unsigned int i; // edi
  _WORD *v6; // eax
  _WORD *v7; // ebp
  unsigned int v8; // ecx
  unsigned int j; // eax

  v2 = this[3];
  v3 = this[5] + 1;
  if ( v3 <= v2 )
    return 1;
  v4 = this[7];
  for ( i = v4 + v2; i < v3; i += v4 )
    ;
  v6 = operator new(4 * i);
  v7 = v6;
  if ( v6 )
  {
    if ( (int)(i - 1) >= 0 )
    {
      v8 = i;
      do
      {
        v6[1] = 0;
        *v6 = 0;
        v6 += 2;
        --v8;
      }
      while ( v8 );
    }
    for ( j = 0; j < this[5]; *(_DWORD *)&v7[2 * j - 2] = *(_DWORD *)(this[2] + 4 * j - 4) )
      ++j;
    sub_5BE8AE();
    this[2] = v7;
    this[3] = i;
    return 1;
  }
  return 0;
}
