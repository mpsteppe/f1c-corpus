int __thiscall sub_616840(_DWORD *this, char *String2)
{
  int v3; // eax
  int v4; // esi
  const char *v5; // eax

  v3 = sub_616750(String2);
  if ( v3 == -1 )
    return 0;
  v4 = this[v3];
  if ( !v4 )
    return 0;
  while ( 1 )
  {
    v5 = *(const char **)(v4 + 12);
    if ( !v5 )
      v5 = WindowName;
    if ( !_stricmp(v5, String2) )
      break;
    v4 = *(_DWORD *)(v4 + 4);
    if ( !v4 )
      return 0;
  }
  return v4;
}
