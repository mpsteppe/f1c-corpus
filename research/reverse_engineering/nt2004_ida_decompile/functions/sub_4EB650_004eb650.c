CHAR *__thiscall sub_4EB650(_DWORD *this, char *String1)
{
  int *v3; // eax
  int v4; // esi
  const char *v5; // eax
  int v6; // eax
  int *v7; // eax
  CHAR *result; // eax

  v3 = (int *)this[4];
  this[6] = v3;
  if ( !v3 )
    return 0;
  v4 = *v3;
  if ( !*v3 )
    return 0;
  while ( 1 )
  {
    v5 = *(const char **)v4;
    if ( !*(_DWORD *)v4 )
      v5 = &byte_629120;
    if ( !_strcmpi(String1, v5) )
      break;
    v6 = this[6];
    if ( v6 )
      this[6] = *(_DWORD *)(v6 + 4);
    v7 = (int *)this[6];
    if ( v7 )
    {
      v4 = *v7;
      if ( *v7 )
        continue;
    }
    return 0;
  }
  result = *(CHAR **)(v4 + 16);
  if ( !result )
    return &byte_629120;
  return result;
}
