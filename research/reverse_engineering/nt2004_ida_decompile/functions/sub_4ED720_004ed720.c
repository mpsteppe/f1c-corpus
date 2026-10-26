CHAR *__thiscall sub_4ED720(void *this)
{
  _DWORD *v1; // eax
  int *v2; // ecx
  int v3; // ecx
  CHAR *result; // eax

  v1 = *(_DWORD **)(sub_4ED8C0(this) + 96);
  if ( !v1 )
    return 0;
  if ( (int)v1[24] <= 0 )
    return 0;
  v2 = (int *)v1[21];
  v1[23] = v2;
  if ( !v2 )
    return 0;
  v3 = *v2;
  if ( !v3 )
    return 0;
  result = *(CHAR **)(v3 + 20);
  if ( !result )
    return &byte_629120;
  return result;
}
