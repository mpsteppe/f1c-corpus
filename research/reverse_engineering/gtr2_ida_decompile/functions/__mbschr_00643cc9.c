unsigned __int8 *__cdecl _mbschr(const unsigned __int8 *Str, unsigned int C)
{
  _DWORD *v2; // eax
  const unsigned __int8 *i; // ecx
  unsigned __int16 v5; // dx

  v2 = (_DWORD *)_getptd()[24];
  if ( v2 != dword_FBB260 )
    v2 = (_DWORD *)sub_640F4B();
  if ( !v2[2] )
    return (unsigned __int8 *)strchr((const char *)Str, C);
  for ( i = Str; ; ++i )
  {
    v5 = *i;
    if ( !*i )
      return *i == C ? (unsigned __int8 *)i : 0;
    if ( (*((_BYTE *)v2 + (unsigned __int8)v5 + 29) & 4) != 0 )
      break;
    if ( C == *i )
      return *i == C ? (unsigned __int8 *)i : 0;
LABEL_11:
    ;
  }
  if ( *++i )
  {
    if ( C == (*i | (v5 << 8)) )
      return (unsigned __int8 *)(i - 1);
    goto LABEL_11;
  }
  return 0;
}
