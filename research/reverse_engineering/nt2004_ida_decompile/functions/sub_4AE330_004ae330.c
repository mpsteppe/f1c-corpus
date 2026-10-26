CHAR *__thiscall sub_4AE330(_DWORD *this)
{
  CHAR **v1; // eax
  CHAR *result; // eax

  v1 = (CHAR **)this[92];
  if ( !v1 )
    return 0;
  result = *v1;
  if ( !result )
    return &byte_629120;
  return result;
}
