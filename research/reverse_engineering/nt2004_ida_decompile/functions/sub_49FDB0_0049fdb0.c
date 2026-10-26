int __thiscall sub_49FDB0(_DWORD *this, char *String2, char a3)
{
  int v4; // esi
  int v5; // edi
  const char *v6; // eax

  v4 = this[36];
  v5 = 1;
  if ( !String2 || !v4 )
    return -1;
  while ( 1 )
  {
    v6 = *(const char **)(v4 + 160);
    if ( !v6 )
      v6 = &byte_629120;
    if ( !_strcmpi(v6, String2) )
      break;
    v4 = *(_DWORD *)(v4 + 140);
    ++v5;
    if ( !v4 )
      return -1;
  }
  sub_49FCC0(this, v5, a3);
  return 0;
}
