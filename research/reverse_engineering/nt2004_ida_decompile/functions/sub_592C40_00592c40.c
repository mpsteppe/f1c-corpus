void __stdcall sub_592C40(char *a1)
{
  int v1; // edi

  v1 = dword_7E8D34;
  if ( a1 && dword_7E8D34 )
  {
    while ( strcmp((const char *)(v1 + 36), a1 + 36) )
    {
      v1 = *(_DWORD *)(v1 + 32);
      if ( !v1 )
        return;
    }
    if ( (*(_DWORD *)a1)-- == 1 )
    {
      sub_592EB0(a1);
      sub_5A3180(a1);
      j_nullsub_6(a1);
      sub_5BE8AE();
    }
  }
}
