const char **__thiscall sub_40E220(_DWORD *this, char *String1)
{
  const char ***v3; // eax
  const char **v4; // esi
  const char *v5; // eax
  int v6; // eax
  const char ***v7; // eax

  v3 = (const char ***)this[5];
  this[7] = v3;
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
    if ( !_strcmpi(String1, v5) )
      break;
    v6 = this[7];
    if ( v6 )
      this[7] = *(_DWORD *)(v6 + 4);
    v7 = (const char ***)this[7];
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
