const char *__thiscall sub_5F38E0(_DWORD *this, char *String1)
{
  const char **v3; // eax
  const char *v4; // esi
  int v5; // eax
  const char **v6; // eax

  v3 = (const char **)this[2348];
  this[2350] = v3;
  if ( !v3 )
    return 0;
  v4 = *v3;
  if ( !*v3 )
    return 0;
  while ( _stricmp(String1, v4) )
  {
    v5 = this[2350];
    if ( v5 )
      this[2350] = *(_DWORD *)(v5 + 4);
    v6 = (const char **)this[2350];
    if ( v6 )
    {
      v4 = *v6;
      if ( *v6 )
        continue;
    }
    return 0;
  }
  return v4;
}
