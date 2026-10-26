CHAR *__thiscall sub_4ED6F0(void *this)
{
  int v1; // eax
  CHAR *result; // eax

  v1 = *(_DWORD *)(sub_4ED8C0(this) + 96);
  if ( !v1 )
    return 0;
  result = *(CHAR **)(v1 + 4);
  if ( !result )
    return &byte_629120;
  return result;
}
