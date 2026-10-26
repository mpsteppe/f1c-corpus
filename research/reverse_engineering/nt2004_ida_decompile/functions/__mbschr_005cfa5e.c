unsigned __int8 *__cdecl _mbschr(const unsigned __int8 *Str, unsigned int C)
{
  const unsigned __int8 *i; // esi
  unsigned __int16 v4; // bx
  unsigned __int8 v5; // al

  if ( !dword_80019C )
    return (unsigned __int8 *)strchr((const char *)Str, C);
  _lock(25);
  for ( i = Str; ; ++i )
  {
    v4 = *i;
    if ( !*i )
      break;
    if ( (byte_8002A1[(unsigned __int8)v4] & 4) != 0 )
    {
      v5 = *++i;
      if ( !v5 )
      {
        _unlock(25);
        return 0;
      }
      if ( C == (v5 | (v4 << 8)) )
      {
        _unlock(25);
        return (unsigned __int8 *)(i - 1);
      }
    }
    else if ( C == *i )
    {
      break;
    }
  }
  _unlock(25);
  return v4 == C ? (unsigned __int8 *)i : 0;
}
