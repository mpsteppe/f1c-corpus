CHAR *__thiscall sub_4ED700(void *this)
{
  int v1; // eax
  CHAR ***v2; // eax
  CHAR **v3; // eax
  CHAR *result; // eax

  v1 = *(_DWORD *)(sub_4ED8C0(this) + 96);
  if ( !v1 || *(int *)(v1 + 96) <= 0 )
    return 0;
  v2 = *(CHAR ****)(v1 + 84);
  if ( v2 )
    v3 = *v2;
  else
    v3 = 0;
  result = *v3;
  if ( !result )
    return &byte_629120;
  return result;
}
