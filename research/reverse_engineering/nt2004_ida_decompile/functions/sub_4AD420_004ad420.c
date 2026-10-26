const char **__thiscall sub_4AD420(_DWORD *this, char *String2)
{
  const char ***v3; // eax
  const char **v4; // esi
  const char *v5; // eax
  int v6; // eax
  const char ***v7; // eax

  if ( !String2 )
    return 0;
  v3 = (const char ***)this[87];
  this[89] = v3;
  if ( !v3 )
    return 0;
  v4 = *v3;
  if ( !*v3 )
    return 0;
  while ( 1 )
  {
    v5 = *v4;
    if ( !*v4 )
      v5 = &byte_629120;
    if ( !_strcmpi(v5, String2) )
      break;
    v6 = this[89];
    if ( v6 )
      this[89] = *(_DWORD *)(v6 + 4);
    v7 = (const char ***)this[89];
    if ( v7 )
    {
      v4 = *v7;
      if ( *v7 )
        continue;
    }
    return 0;
  }
  return v4;
}
