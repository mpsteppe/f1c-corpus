CHAR *__thiscall sub_4EAD00(_DWORD *this)
{
  int v1; // eax
  CHAR *result; // eax

  v1 = this[24];
  if ( !v1 )
    return 0;
  result = *(CHAR **)(v1 + 12);
  if ( !result )
    return &byte_629120;
  return result;
}
