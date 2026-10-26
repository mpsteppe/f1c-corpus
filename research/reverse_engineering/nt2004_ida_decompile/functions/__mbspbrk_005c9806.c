unsigned __int8 *__cdecl _mbspbrk(const unsigned __int8 *String, const unsigned __int8 *Control)
{
  const unsigned __int8 *i; // esi
  const unsigned __int8 *j; // eax
  unsigned __int8 v5; // cl

  if ( !dword_80019C )
    return (unsigned __int8 *)strpbrk((const char *)String, (const char *)Control);
  _lock(25);
  for ( i = String; *i; ++i )
  {
    for ( j = Control; *j; ++j )
    {
      v5 = *j;
      if ( (byte_8002A1[*j] & 4) != 0 )
      {
        if ( v5 == *i && j[1] == i[1] || !j[1] )
          break;
        ++j;
      }
      else if ( v5 == *i )
      {
        break;
      }
    }
    if ( !*j )
    {
      if ( (byte_8002A1[*i] & 4) == 0 )
        continue;
      if ( *++i )
        continue;
    }
    break;
  }
  _unlock(25);
  return *i != 0 ? (unsigned __int8 *)i : 0;
}
