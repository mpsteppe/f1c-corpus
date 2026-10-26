int __thiscall sub_5B0870(_DWORD *this)
{
  unsigned int *v2; // eax
  int i; // ecx
  unsigned int v4; // edx

  if ( *(_DWORD *)(this[20] + 28) )
  {
    sub_5A7FD0(dword_7E6B48, *(_DWORD *)(this[20] + 28));
    if ( *(_DWORD *)(this[20] + 28) )
      sub_5BE8AE();
    *(_DWORD *)(this[20] + 28) = 0;
    sub_5A8170(dword_7E6B48, *(_DWORD *)(this[20] + 36));
    if ( *(_DWORD *)(this[20] + 36) )
      sub_5BE8AE();
    *(_DWORD *)(this[20] + 36) = 0;
    this[8] &= ~0x100u;
  }
  v2 = (unsigned int *)this[13];
  for ( i = 0; i < this[11]; ++i )
  {
    v4 = *v2 & 0xFFFFFFBF;
    v2[30] = 0;
    v2[31] = 0;
    *v2 = v4;
    v2 += 32;
  }
  this[12] = 0;
  this[14] = 0;
  return 0;
}
