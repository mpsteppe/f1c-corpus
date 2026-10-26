char __thiscall sub_4C1820(int *this)
{
  int v2; // eax
  int v3; // esi
  char v4; // dl
  int v5; // ecx
  void *v7; // edi

  v2 = LinkedListDereference(this);
  if ( !v2 )
    return 0;
  v3 = *this;
  v4 = 0;
  v5 = 0;
  if ( *this )
  {
    while ( *(_DWORD *)v3 != v2 )
    {
      v5 = v3;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v3 )
        return 0;
    }
    if ( v3 == this[2] )
      this[2] = *(_DWORD *)(v3 + 4);
    if ( v5 )
      *(_DWORD *)(v5 + 4) = *(_DWORD *)(v3 + 4);
    else
      *this = *(_DWORD *)(v3 + 4);
    if ( this[1] == v3 )
      this[1] = v5;
    --this[3];
    if ( *(_BYTE *)(v3 + 8) )
    {
      v7 = *(void **)v3;
      if ( *(_DWORD *)v3 )
      {
        PitStopMemoryCleanup(*(LPVOID **)v3);
        FreeWrapper_7bcf(v7);
      }
    }
    FreeWrapper_7bcf((LPVOID)v3);
    return 1;
  }
  return v4;
}
