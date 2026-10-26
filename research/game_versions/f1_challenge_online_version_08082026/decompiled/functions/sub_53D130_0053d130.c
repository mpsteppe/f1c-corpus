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
    sub_53D3A0(a1);
    sub_552760(a1);
    if ( a1 )
    {
      j_nullsub_3(a1);
      sub_587BCF(a1);
    }
  }
}
