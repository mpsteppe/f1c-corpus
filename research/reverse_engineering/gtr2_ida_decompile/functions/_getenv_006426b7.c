char *__cdecl getenv(const char *VarName)
{
  int *v1; // esi
  size_t v3; // edi

  v1 = (int *)dword_FB81B4;
  if ( !dword_FBC608 )
    return 0;
  if ( dword_FB81B4 || dword_FB81BC && !__wtomb_environ() && (v1 = (int *)dword_FB81B4) != 0 )
  {
    if ( VarName )
    {
      v3 = sub_6354D0((int)VarName);
      while ( *v1 )
      {
        if ( sub_6354D0(*v1) > v3
          && *(_BYTE *)(*v1 + v3) == 61
          && !_mbsnbicoll((const unsigned __int8 *)*v1, (const unsigned __int8 *)VarName, v3) )
        {
          return (char *)(*v1 + v3 + 1);
        }
        ++v1;
      }
    }
  }
  return 0;
}
