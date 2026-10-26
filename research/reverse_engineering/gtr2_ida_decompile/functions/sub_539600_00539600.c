void __stdcall sub_539600(char *String2)
{
  unsigned int v1; // kr00_4
  int v2; // eax
  int v3; // edi
  int i; // esi
  const char *v5; // eax

  if ( String2 )
  {
    v1 = __readeflags();
    v2 = *(_DWORD *)((char *)off_16C6E0C - 2002349);
    __writeeflags(v1);
    v3 = 0;
    if ( v2 > 0 )
    {
      for ( i = 0; ; i += 2824 )
      {
        v5 = *(const char **)(i + dword_BE1BD8);
        if ( !v5 )
          v5 = WindowName;
        if ( !_stricmp(v5, String2) )
          break;
        if ( ++v3 >= dword_BE1BD4 )
          return;
      }
      dword_BE1BD0 = v3;
    }
  }
}
