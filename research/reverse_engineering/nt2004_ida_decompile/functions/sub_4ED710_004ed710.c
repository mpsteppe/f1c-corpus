CHAR *__thiscall sub_4ED710(void *this)
{
  _DWORD *v1; // eax
  CHAR ***v2; // edx
  CHAR **v3; // eax
  int v4; // eax
  int v5; // edx
  int v6; // eax
  CHAR ***v7; // eax
  CHAR *result; // eax
  int v9; // ecx

  v9 = sub_4ED8C0(this);
  v1 = *(_DWORD **)(v9 + 96);
  if ( !v1 )
    return 0;
  if ( (int)v1[20] <= 0 )
    return 0;
  v2 = (CHAR ***)v1[17];
  v1[19] = v2;
  if ( !v2 )
    return 0;
  v3 = *v2;
  if ( !*v2 )
    return 0;
  while ( v3[2] != (CHAR *)1 )
  {
    v4 = *(_DWORD *)(v9 + 96);
    v5 = *(_DWORD *)(v4 + 76);
    v6 = v4 + 68;
    if ( v5 )
      *(_DWORD *)(v6 + 8) = *(_DWORD *)(v5 + 4);
    v7 = *(CHAR ****)(v6 + 8);
    if ( v7 )
    {
      v3 = *v7;
      if ( v3 )
        continue;
    }
    return 0;
  }
  result = *v3;
  if ( !result )
    return &byte_629120;
  return result;
}
