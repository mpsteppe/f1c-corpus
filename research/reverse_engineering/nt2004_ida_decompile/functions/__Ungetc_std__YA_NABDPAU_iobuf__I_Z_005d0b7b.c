char __cdecl std::_Ungetc(const char *a1, FILE *Stream, unsigned int a3)
{
  unsigned int v3; // esi
  bool v4; // zf
  const char *v5; // edi
  int v6; // eax
  int v8; // edi

  v3 = a3;
  v4 = a3 == 0;
  v5 = &a1[a3];
  if ( a3 )
  {
    do
    {
      v6 = *(unsigned __int8 *)--v5;
      if ( ungetc(v6, Stream) == -1 )
        break;
      --v3;
    }
    while ( v3 );
    v4 = v3 == 0;
  }
  if ( v4 )
    return 1;
  v8 = 1;
  if ( !v3 )
  {
    do
    {
      fgetc(Stream);
      --v8;
    }
    while ( v8 );
  }
  return 0;
}
