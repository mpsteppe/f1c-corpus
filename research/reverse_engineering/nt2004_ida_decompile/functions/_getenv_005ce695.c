char *__cdecl getenv(const char *VarName)
{
  const char **v1; // esi
  size_t v2; // edi

  v1 = (const char **)dword_7FF138;
  if ( dword_801508 )
  {
    if ( dword_7FF138 || dword_7FF140 && !__wtomb_environ() && (v1 = (const char **)dword_7FF138) != 0 )
    {
      if ( VarName )
      {
        v2 = strlen(VarName);
        while ( *v1 )
        {
          if ( strlen(*v1) > v2
            && (*v1)[v2] == 61
            && !_mbsnbicoll((const unsigned __int8 *)*v1, (const unsigned __int8 *)VarName, v2) )
          {
            return (char *)&(*v1)[v2 + 1];
          }
          ++v1;
        }
      }
    }
  }
  return 0;
}
