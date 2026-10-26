char *__thiscall sub_455560(_DWORD *this, int a2)
{
  char *result; // eax

  result = 0;
  if ( a2 < 44 )
  {
    result = (char *)this[2 * a2 + 2220];
    if ( !result )
      return byte_5EA438;
  }
  return result;
}
