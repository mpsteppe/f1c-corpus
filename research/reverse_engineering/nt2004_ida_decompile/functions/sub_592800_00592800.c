int sub_592800()
{
  size_t v0; // edi
  size_t i; // eax
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v0 = ElementCount;
  if ( ElementCount )
  {
    for ( i = *(_DWORD *)(ElementCount + 304); i; i = *(_DWORD *)(v0 + 304) )
    {
      v0 = i;
      v2 = *(_DWORD *)(i + 300);
      if ( (*(_BYTE *)(v2 + 276) & 8) != 0 )
      {
        v3 = *(_DWORD *)(v2 + 300);
        if ( v3 )
          *(_DWORD *)(v3 + 304) = *(_DWORD *)(v2 + 304);
        v4 = *(_DWORD *)(v2 + 304);
        if ( v4 )
          *(_DWORD *)(v4 + 300) = *(_DWORD *)(v2 + 300);
        if ( !*(_DWORD *)(v2 + 300) )
          ElementCount = *(_DWORD *)(v2 + 304);
        sub_5AED40(v2);
        j_nullsub_6((void *)v2);
        sub_5BE8AE();
        --dword_7E5D54;
      }
    }
    if ( (*(_BYTE *)(v0 + 276) & 8) != 0 )
    {
      v5 = *(_DWORD *)(v0 + 300);
      if ( v5 )
        *(_DWORD *)(v5 + 304) = *(_DWORD *)(v0 + 304);
      v6 = *(_DWORD *)(v0 + 304);
      if ( v6 )
        *(_DWORD *)(v6 + 300) = *(_DWORD *)(v0 + 300);
      if ( !*(_DWORD *)(v0 + 300) )
        ElementCount = *(_DWORD *)(v0 + 304);
      sub_5AED40(v0);
      j_nullsub_6((void *)v0);
      sub_5BE8AE();
      --dword_7E5D54;
    }
  }
  return 0;
}
