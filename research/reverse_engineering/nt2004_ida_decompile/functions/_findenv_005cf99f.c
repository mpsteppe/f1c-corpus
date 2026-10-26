int __cdecl findenv(unsigned __int8 *Str1, size_t MaxCount)
{
  char *v2; // esi
  const unsigned __int8 *v3; // eax
  char v4; // al

  v2 = (char *)dword_7FF138;
  v3 = *(const unsigned __int8 **)dword_7FF138;
  if ( !*(_DWORD *)dword_7FF138 )
    return -((v2 - (_BYTE *)dword_7FF138) >> 2);
  while ( 1 )
  {
    if ( !_mbsnbicoll(Str1, v3, MaxCount) )
    {
      v4 = *(_BYTE *)(*(_DWORD *)v2 + MaxCount);
      if ( v4 == 61 || !v4 )
        break;
    }
    v3 = (const unsigned __int8 *)*((_DWORD *)v2 + 1);
    v2 += 4;
    if ( !v3 )
      return -((v2 - (_BYTE *)dword_7FF138) >> 2);
  }
  return (v2 - (_BYTE *)dword_7FF138) >> 2;
}
