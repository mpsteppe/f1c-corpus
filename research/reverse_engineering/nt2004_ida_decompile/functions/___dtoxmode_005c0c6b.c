unsigned int __cdecl __dtoxmode(char a1, unsigned __int8 *String)
{
  unsigned __int8 *v2; // ecx
  unsigned __int8 v3; // dl
  int v4; // edi
  unsigned int v5; // edi
  unsigned __int8 *v6; // eax
  const unsigned __int8 *v7; // esi

  v2 = String;
  if ( String[1] == 58 )
    v2 = String + 2;
  v3 = *v2;
  if ( (*v2 == 92 || v3 == 47) && !v2[1] || (a1 & 0x10) != 0 || (v4 = 0x8000, !v3) )
    v4 = 16448;
  v5 = ((((a1 & 1) == 0) | 2) << 7) | v4;
  v6 = _mbsrchr(String, 0x2Eu);
  v7 = v6;
  if ( v6 && (!_mbsicmp(v6, ".exe") || !_mbsicmp(v7, ".cmd") || !_mbsicmp(v7, ".bat") || !_mbsicmp(v7, ".com")) )
    v5 |= 0x40u;
  return (v5 >> 3) & 0x38 | v5 | (((v5 >> 3) & 0x38 | v5) >> 6) & 7;
}
