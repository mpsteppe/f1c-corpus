__int16 __cdecl sub_58CE20(__int16 a1)
{
  __int16 result; // ax
  int v2; // ecx
  _WORD *v3; // ecx

  if ( !dword_7E483C )
    return -1;
  result = 0;
  if ( dword_7E4840 <= 0 )
    return -1;
  v2 = 0;
  while ( 1 )
  {
    v3 = *(_WORD **)(dword_7E483C + 4 * v2);
    if ( v3 )
    {
      if ( *v3 == a1 )
        break;
    }
    v2 = ++result;
    if ( result >= dword_7E4840 )
      return -1;
  }
  return result;
}
