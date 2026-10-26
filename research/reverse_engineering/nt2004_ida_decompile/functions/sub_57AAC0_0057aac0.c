int __thiscall sub_57AAC0(_DWORD *this, char *String2, int a3)
{
  int v3; // eax
  int v5; // esi
  const char *v6; // eax

  v3 = a3;
  if ( a3 == -1 )
  {
    v3 = sub_57AA10(String2);
    if ( v3 == -1 )
      return 0;
  }
  v5 = this[v3];
  if ( !v5 )
    return 0;
  while ( 1 )
  {
    v6 = *(const char **)(v5 + 12);
    if ( !v6 )
      v6 = &byte_629120;
    if ( !_strcmpi(v6, String2) )
      break;
    v5 = *(_DWORD *)(v5 + 4);
    if ( !v5 )
      return 0;
  }
  return v5;
}
