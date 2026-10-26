unsigned int __thiscall sub_4E9620(_DWORD *this)
{
  unsigned int result; // eax
  unsigned int i; // eax
  unsigned int v3; // eax
  int v4; // edx

  result = this[1];
  if ( result )
  {
    for ( i = 0; i < 0x18; i += 4 )
      *(_DWORD *)(i + this[1]) = 0;
    *(_DWORD *)(this[1] + 24) = -1082130432;
    *(_DWORD *)(this[1] + 28) = -1082130432;
    *(_DWORD *)(this[1] + 32) = -1082130432;
    *(_DWORD *)(this[1] + 36) = -1082130432;
    *(_DWORD *)(this[1] + 40) = -1082130432;
    *(_DWORD *)(this[1] + 44) = -1082130432;
    *(_DWORD *)(this[1] + 48) = -1082130432;
    *(_DWORD *)(this[1] + 52) = -1082130432;
    *(_DWORD *)(this[1] + 56) = 0;
    *(_DWORD *)(this[1] + 60) = -1;
    *(_DWORD *)(this[1] + 64) = -1;
    *(_DWORD *)(this[1] + 68) = -1082130432;
    *(_DWORD *)(this[1] + 72) = -1082130432;
    *(_DWORD *)(this[1] + 76) = -1082130432;
    *(_DWORD *)(this[1] + 80) = -1;
    *(_DWORD *)(this[1] + 84) = -1;
    *(_DWORD *)(this[1] + 88) = -2;
    v3 = 92;
    do
    {
      v4 = 3;
      do
      {
        *(_DWORD *)(v3 + this[1]) = -1082130432;
        v3 += 4;
        --v4;
      }
      while ( v4 );
    }
    while ( v3 < 0x8C );
    *(_DWORD *)(this[1] + 140) = -1;
    for ( result = 156; result < 0xA8; result += 4 )
    {
      *(_DWORD *)(result + this[1] - 12) = 0;
      *(_DWORD *)(result + this[1]) = 0;
      *(_DWORD *)(result + this[1] + 12) = 0;
    }
  }
  return result;
}
