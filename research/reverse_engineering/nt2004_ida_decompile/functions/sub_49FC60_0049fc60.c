char __thiscall sub_49FC60(_DWORD *this, char *String2, _DWORD *a3)
{
  int v3; // esi
  int v4; // edi
  const char *v5; // eax

  v3 = this[36];
  v4 = 0;
  if ( !String2 || !v3 )
    return 0;
  while ( 1 )
  {
    v5 = *(const char **)(v3 + 160);
    if ( !v5 )
      v5 = &byte_629120;
    if ( !_strcmpi(v5, String2) )
      break;
    v3 = *(_DWORD *)(v3 + 140);
    ++v4;
    if ( !v3 )
      return 0;
  }
  if ( a3 )
    *a3 = v4;
  return 1;
}
