const char *__thiscall sub_41D920(_DWORD *this, char *String1)
{
  const char *v2; // ebx
  const char **v4; // eax
  const char *v5; // esi
  int v6; // eax
  const char **v7; // eax

  v2 = String1;
  if ( !String1 )
  {
    v2 = Str;
    if ( !Str )
      v2 = WindowName;
  }
  v4 = (const char **)this[9];
  this[11] = v4;
  if ( !v4 )
    return 0;
  v5 = *v4;
  if ( *v4 )
  {
    while ( _stricmp(v2, v5) )
    {
      v6 = this[11];
      if ( v6 )
        this[11] = *(_DWORD *)(v6 + 4);
      v7 = (const char **)this[11];
      if ( !v7 )
        return 0;
      v5 = *v7;
      if ( !*v7 )
        return v5;
    }
  }
  return v5;
}
