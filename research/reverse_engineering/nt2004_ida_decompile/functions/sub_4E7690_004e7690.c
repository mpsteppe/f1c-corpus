void __stdcall sub_4E7690(char *String2)
{
  int v1; // edi
  int i; // esi
  const char *v3; // eax

  if ( String2 )
  {
    v1 = 0;
    if ( dword_7D6A58 > 0 )
    {
      for ( i = 0; ; i += 1232 )
      {
        v3 = *(const char **)(i + dword_7D6A5C);
        if ( !v3 )
          v3 = &byte_629120;
        if ( !_strcmpi(v3, String2) )
          break;
        if ( ++v1 >= dword_7D6A58 )
          return;
      }
      dword_7D6A54 = v1;
    }
  }
}
