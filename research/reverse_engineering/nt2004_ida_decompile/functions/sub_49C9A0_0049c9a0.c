CHAR *__thiscall sub_49C9A0(_DWORD *this)
{
  int v1; // eax
  CHAR *result; // eax

  v1 = this[61];
  if ( !v1 )
    return 0;
  result = *(CHAR **)(v1 + 56);
  if ( !result )
    return &byte_629120;
  return result;
}
