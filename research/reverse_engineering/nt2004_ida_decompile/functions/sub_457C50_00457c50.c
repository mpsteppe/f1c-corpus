CHAR *__thiscall sub_457C50(_DWORD *this, int a2)
{
  CHAR *result; // eax

  result = 0;
  if ( a2 < 61 )
  {
    result = (CHAR *)this[2 * a2 + 2409];
    if ( !result )
      return &byte_629120;
  }
  return result;
}
