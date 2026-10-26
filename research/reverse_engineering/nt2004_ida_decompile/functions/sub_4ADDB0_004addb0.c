int __thiscall sub_4ADDB0(_DWORD *this, char *String2)
{
  int v2; // esi

  if ( !String2 )
    return 0;
  v2 = this[85];
  if ( !v2 )
    return 0;
  while ( _strcmpi((const char *)v2, String2) )
  {
    v2 = *(_DWORD *)(v2 + 84);
    if ( !v2 )
      return 0;
  }
  return *(_DWORD *)(v2 + 80);
}
