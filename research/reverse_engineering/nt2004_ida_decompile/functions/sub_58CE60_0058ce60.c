__int16 __cdecl sub_58CE60(__int16 a1, __int16 a2)
{
  __int16 result; // ax
  int v3; // ecx
  _WORD *v4; // ecx

  if ( !dword_7E483C )
    return -1;
  result = 0;
  if ( dword_7E4840 <= 0 )
    return -1;
  v3 = 0;
  while ( 1 )
  {
    v4 = *(_WORD **)(dword_7E483C + 4 * v3);
    if ( v4 )
    {
      if ( *v4 == a1 && v4[1] == a2 )
        break;
    }
    v3 = ++result;
    if ( result >= dword_7E4840 )
      return -1;
  }
  return result;
}
