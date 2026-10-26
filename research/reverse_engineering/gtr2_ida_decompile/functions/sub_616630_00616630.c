int __thiscall sub_616630(_DWORD *this, char *String1)
{
  int v2; // esi
  const char *v4; // eax

  v2 = this[2];
  if ( !String1 )
    return 0;
  for ( ; v2; v2 = *(_DWORD *)(v2 + 4) )
  {
    v4 = *(const char **)(v2 + 12);
    if ( !v4 )
      v4 = WindowName;
    if ( !_stricmp(String1, v4) )
      break;
  }
  return v2;
}
