int __thiscall sub_558990(_DWORD *this)
{
  int v2; // ecx
  int v3; // edx
  unsigned int *v4; // eax
  int i; // ecx
  unsigned int v6; // edx

  if ( *(_DWORD *)(this[20] + 28) )
  {
    ObjectResetWithVirtualRelease(dword_8B78A0, *(_DWORD *)(this[20] + 28));
    v2 = this[20];
    if ( *(_DWORD *)(v2 + 28) )
      FreeWrapper_7bcf(*(LPVOID *)(v2 + 28));
    *(_DWORD *)(this[20] + 28) = 0;
    DrainingLoopFinalizer(dword_8B78A0, *(_DWORD *)(this[20] + 36));
    v3 = this[20];
    if ( *(_DWORD *)(v3 + 36) )
      FreeWrapper_7bcf(*(LPVOID *)(v3 + 36));
    *(_DWORD *)(this[20] + 36) = 0;
    this[8] &= ~0x100u;
  }
  v4 = (unsigned int *)this[13];
  for ( i = 0; i < this[11]; ++i )
  {
    v6 = *v4 & 0xFFFFFFBF;
    v4[30] = 0;
    v4[31] = 0;
    *v4 = v6;
    v4 += 32;
  }
  this[12] = 0;
  this[14] = 0;
  return 0;
}
