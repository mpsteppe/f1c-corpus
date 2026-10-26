int sub_53CED0()
{
  int v0; // edi
  int i; // eax
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v0 = dword_8B8F14;
  if ( dword_8B8F14 )
  {
    for ( i = *(_DWORD *)(dword_8B8F14 + 304); i; i = *(_DWORD *)(v0 + 304) )
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
          dword_8B8F14 = *(_DWORD *)(v2 + 304);
        sub_55FE30(v2);
        j_nullsub_3(v2);
        sub_587BCF((LPVOID)v2);
        --dword_8B6AC0;
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
        dword_8B8F14 = *(_DWORD *)(v0 + 304);
      sub_55FE30(v0);
      j_nullsub_3(v0);
      sub_587BCF((LPVOID)v0);
      --dword_8B6AC0;
    }
  }
  return 0;
}
