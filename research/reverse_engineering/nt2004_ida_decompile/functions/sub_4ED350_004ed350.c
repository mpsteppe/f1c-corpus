CHAR *__thiscall sub_4ED350(_DWORD *this, int a2)
{
  int v2; // edx
  int *v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int *v8; // eax
  CHAR *result; // eax

  v2 = this[24];
  if ( !v2 )
    return 0;
  v3 = *(int **)(v2 + 68);
  *(_DWORD *)(v2 + 76) = v3;
  if ( !v3 )
    return 0;
  v4 = *v3;
  if ( !v4 )
    return 0;
  while ( *(__int16 *)(v4 + 36) != a2 || *(_DWORD *)(v4 + 8) != 3 )
  {
    v5 = this[24];
    v6 = *(_DWORD *)(v5 + 76);
    v7 = v5 + 68;
    if ( v6 )
      *(_DWORD *)(v7 + 8) = *(_DWORD *)(v6 + 4);
    v8 = *(int **)(v7 + 8);
    if ( v8 )
    {
      v4 = *v8;
      if ( v4 )
        continue;
    }
    return 0;
  }
  result = *(CHAR **)(v4 + 12);
  if ( !result )
    return &byte_629120;
  return result;
}
