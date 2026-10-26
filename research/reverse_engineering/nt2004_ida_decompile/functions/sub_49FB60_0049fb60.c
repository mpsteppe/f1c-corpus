CHAR *__thiscall sub_49FB60(_DWORD *this)
{
  int v1; // eax
  CHAR *result; // eax

  v1 = sub_49F5C0(this);
  if ( !v1 )
    return 0;
  result = *(CHAR **)(v1 + 280);
  if ( !result )
    return &byte_629120;
  return result;
}
