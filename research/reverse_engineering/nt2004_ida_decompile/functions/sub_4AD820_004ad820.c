CHAR *__thiscall sub_4AD820(_DWORD *this)
{
  int v1; // eax
  CHAR *result; // eax

  v1 = this[6];
  if ( !v1 )
    return 0;
  result = *(CHAR **)(v1 + 36);
  if ( !result )
    return &byte_629120;
  return result;
}
