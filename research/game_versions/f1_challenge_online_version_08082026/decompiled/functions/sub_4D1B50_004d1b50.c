int __thiscall sub_4D1B50(unsigned __int8 *this, int a2)
{
  int result; // eax
  int v3; // eax

  result = this[a2 + 296];
  if ( result == 255 )
    return *(_DWORD *)(dword_7C54F0[0] + 16);
  if ( dword_5EF9A0[4656 * result] != -1 )
    return result;
  v3 = 0;
  if ( dword_5C329C <= 0 )
    return *(_DWORD *)(dword_7C54F0[0] + 16);
  while ( *(_DWORD *)(dword_7C54F0[v3] + 16480) != a2 + 2 )
  {
    if ( ++v3 >= dword_5C329C )
      return *(_DWORD *)(dword_7C54F0[0] + 16);
  }
  return *(_DWORD *)(dword_7C54F0[v3] + 16440);
}
