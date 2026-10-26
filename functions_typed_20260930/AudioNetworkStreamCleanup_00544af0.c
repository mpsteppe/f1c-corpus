int __thiscall sub_544AF0(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  void *v4; // edi
  void *v5; // edi
  int v6; // ebx
  int v7; // edi
  int v8; // edi
  int i; // esi

  if ( (this[59] & 0x100000) != 0 )
  {
    if ( this[89] )
    {
      v2 = 0;
      if ( (int)this[88] > 0 )
      {
        v3 = 0;
        do
        {
          DestructorWithConditionalFreeFlagClear(v3 + this[89]);
          ++v2;
          v3 += 96;
        }
        while ( v2 < this[88] );
      }
      DoublyLinkedListNodeRemovalWithArrayCleanup(this[89]);
      this[89] = 0;
      this[88] = 0;
      SubBufferFree(dword_8B78A0);
    }
    this[59] &= ~0x100000u;
  }
  if ( dword_8B8DBC )
  {
    sub_542E50((_DWORD *)dword_8B8DBC);
    v4 = (void *)dword_8B8DBC;
    if ( dword_8B8DBC )
    {
      EmptyStub_7470(dword_8B8DBC);
      FreeWrapper_7bcf(v4);
    }
    dword_8B8DBC = 0;
  }
  if ( dword_8B8DC0 )
  {
    sub_542E50((_DWORD *)dword_8B8DC0);
    v5 = (void *)dword_8B8DC0;
    if ( dword_8B8DC0 )
    {
      EmptyStub_7470(dword_8B8DC0);
      FreeWrapper_7bcf(v5);
    }
    dword_8B8DC0 = 0;
  }
  v6 = this[64];
  if ( v6 )
  {
    while ( 1 )
    {
      v7 = *(_DWORD *)(v6 + 236);
      if ( v7 )
        break;
LABEL_20:
      v6 = *(_DWORD *)(v6 + 260);
      if ( !v6 )
        goto LABEL_21;
    }
    while ( !TreeActiveCheck(v7, 0) )
    {
      v7 = *(_DWORD *)(v7 + 76);
      if ( !v7 )
        goto LABEL_20;
    }
    return -1;
  }
LABEL_21:
  v8 = this[66];
  if ( v8 )
  {
    while ( !TreeActiveCheck(v8, 0) )
    {
      v8 = *(_DWORD *)(v8 + 76);
      if ( !v8 )
        goto LABEL_24;
    }
    return -1;
  }
LABEL_24:
  for ( i = this[82]; i; i = *(_DWORD *)(i + 104) )
    TextureFlagTestWithDispatch(i);
  sub_540760(dword_8B78A0);
  return 0;
}

