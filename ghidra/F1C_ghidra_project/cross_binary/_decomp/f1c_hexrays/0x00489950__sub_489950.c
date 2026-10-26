// f1c  0x00489950  size=28
char *__thiscall sub_489950(_DWORD *this)
{
  int v1; // eax
  char *result; // eax

  v1 = sub_489450(this);
  if ( !v1 )
    return 0;
  result = *(char **)(v1 + 168);
  if ( !result )
    return byte_5EA438;
  return result;
}
