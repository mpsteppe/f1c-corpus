int __thiscall sub_4F7D30(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax

  v2 = this[96];
  result = 0;
  if ( v2 <= 0 )
    return -2;
  while ( a2 != this[2 * result] )
  {
    if ( ++result >= v2 )
      return -2;
  }
  return result;
}
