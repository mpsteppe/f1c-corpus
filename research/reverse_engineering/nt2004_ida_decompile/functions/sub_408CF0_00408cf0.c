int __thiscall sub_408CF0(_DWORD *this, char *String2)
{
  int *v3; // eax
  int v4; // esi
  const char *v5; // eax
  int v6; // eax
  int *v7; // eax

  if ( !String2 )
    return -1;
  if ( !strcmp(String2, &byte_629120) )
    return -1;
  v3 = (int *)this[6];
  this[8] = v3;
  if ( !v3 )
    return -1;
  v4 = *v3;
  if ( !*v3 )
    return -1;
  while ( 1 )
  {
    if ( *(_DWORD *)(v4 + 92) != -1 )
    {
      v5 = (const char *)unknown_libname_44(v4);
      if ( !_strcmpi(v5, String2) )
        break;
    }
    v6 = this[8];
    if ( v6 )
      this[8] = *(_DWORD *)(v6 + 4);
    v7 = (int *)this[8];
    if ( v7 )
    {
      v4 = *v7;
      if ( *v7 )
        continue;
    }
    return -1;
  }
  return *(_DWORD *)(v4 + 92);
}
