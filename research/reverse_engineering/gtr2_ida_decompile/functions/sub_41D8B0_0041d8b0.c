const char *__thiscall sub_41D8B0(_DWORD *this, char *String1)
{
  const char *v2; // ebx
  const char **v4; // eax
  const char *v5; // esi
  int v6; // eax
  const char **v7; // eax
  unsigned int v9; // kr00_4
  const char *v10; // eax

  v2 = String1;
  if ( !String1 )
  {
    v9 = __readeflags();
    v10 = *(const char **)__ROR4__(dword_16C6D18, 139);
    __writeeflags(v9);
    v2 = v10;
    if ( !v10 )
      v2 = WindowName;
  }
  v4 = (const char **)this[5];
  this[7] = v4;
  if ( !v4 )
    return 0;
  v5 = *v4;
  if ( *v4 )
  {
    while ( _stricmp(v2, v5) )
    {
      v6 = this[7];
      if ( v6 )
        this[7] = *(_DWORD *)(v6 + 4);
      v7 = (const char **)this[7];
      if ( !v7 )
        return 0;
      v5 = *v7;
      if ( !*v7 )
        return v5;
    }
  }
  return v5;
}
