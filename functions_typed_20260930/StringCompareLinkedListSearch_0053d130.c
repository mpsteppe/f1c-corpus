void __stdcall sub_53D130(char *a1)
{
  int v1; // edi

  v1 = dword_8B8E20;
  if ( dword_8B8E20 )
  {
    while ( strcmp((const char *)(v1 + 20), a1 + 20) )
    {
      v1 = *(_DWORD *)(v1 + 2160);
      if ( !v1 )
        return;
    }
    DoublyLinkedListNodeRemoval_d3a0(a1);
    AudioResourceCleanup(a1);
    if ( a1 )
    {
      EmptyStub_7470(a1);
      FreeWrapper_7bcf(a1);
    }
  }
}

