unsigned __int8 *__cdecl _mbsrchr(const unsigned __int8 *String, unsigned int C)
{
  unsigned __int8 *v2; // esi
  const unsigned __int8 *v4; // ecx
  unsigned __int8 v5; // dl
  int v6; // eax
  bool v7; // zf

  v2 = 0;
  if ( !dword_80019C )
    return (unsigned __int8 *)strrchr((const char *)String, C);
  _lock(25);
  v4 = String;
  do
  {
    v5 = *v4;
    v6 = *v4;
    if ( (byte_8002A1[(unsigned __int8)v6] & 4) != 0 )
    {
      v5 = *++v4;
      if ( v5 )
      {
        if ( C == (v5 | (v6 << 8)) )
          v2 = (unsigned __int8 *)(v4 - 1);
        goto LABEL_12;
      }
      v7 = v2 == 0;
    }
    else
    {
      v7 = C == v6;
    }
    if ( v7 )
      v2 = (unsigned __int8 *)v4;
LABEL_12:
    ++v4;
  }
  while ( v5 );
  _unlock(25);
  return v2;
}
