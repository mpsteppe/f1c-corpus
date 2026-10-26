void sub_494E60()
{
  int v0; // esi
  int v1; // eax
  _DWORD *v2; // edi
  bool v3; // zf
  void *v4; // ebp

  v0 = dword_7CDDF0;
  dword_7CDDF8 = dword_7CDDF0;
  if ( dword_7CDDF0 )
  {
    v1 = *(_DWORD *)dword_7CDDF0;
    if ( *(_DWORD *)dword_7CDDF0 )
    {
      do
      {
        StringCompareLinkedListSearch(v1);
        if ( !dword_7CDDF8 )
          break;
        dword_7CDDF8 = *(_DWORD *)(dword_7CDDF8 + 4);
        if ( !dword_7CDDF8 )
          break;
        v1 = *(_DWORD *)dword_7CDDF8;
      }
      while ( *(_DWORD *)dword_7CDDF8 );
      v0 = dword_7CDDF0;
    }
    while ( v0 )
    {
      v2 = (_DWORD *)v0;
      v3 = *(_BYTE *)(v0 + 8) == 0;
      v0 = *(_DWORD *)(v0 + 4);
      if ( !v3 )
      {
        v4 = (void *)*v2;
        if ( *v2 )
        {
          EmptyStub_7470(*v2);
          FreeWrapper_7bcf(v4);
        }
      }
      FreeWrapper_7bcf(v2);
    }
  }
  dword_7CDDF0 = 0;
  dword_7CDDF4 = 0;
  dword_7CDDF8 = 0;
  dword_7CDDFC = 0;
}
