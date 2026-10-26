int __thiscall sub_5E95C0(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // ebx
  int i; // edi

  if ( (*(_BYTE *)this & 2) != 0 )
    return -2;
  v2 = this[54];
  if ( v2 > 0 )
  {
    v3 = v2 - 1;
    this[54] = v3;
    if ( v3 )
      return -2;
  }
  v4 = 0;
  for ( i = this[65]; v4 < this[64]; ++v4 )
  {
    sub_5E4AA0(i, 1);
    i += 484;
  }
  *this |= 3u;
  return 0;
}
