CHAR *__thiscall sub_4EC3A0(int **this, int a2)
{
  int *v3; // eax
  bool v4; // zf
  int v5; // esi
  const char *v6; // eax
  const char *v7; // ecx
  int *v8; // eax
  int *v9; // eax
  CHAR *result; // eax
  int v11; // ecx
  CHAR ***v12; // eax
  CHAR **v13; // eax

  if ( !this[24] )
    return 0;
  if ( a2 < 0 )
    return 0;
  v3 = *this;
  v4 = *this == 0;
  this[2] = *this;
  if ( v4 )
    return 0;
  v5 = *v3;
  if ( !*v3 )
    return 0;
  while ( 1 )
  {
    v6 = (const char *)this[24][5];
    if ( !v6 )
      v6 = &byte_629120;
    v7 = *(const char **)v5;
    if ( !*(_DWORD *)v5 )
      v7 = &byte_629120;
    if ( !_strcmpi(v7, v6) )
      break;
    v8 = this[2];
    if ( v8 )
    {
      v9 = (int *)v8[1];
      this[2] = v9;
      if ( v9 )
      {
        v5 = *v9;
        if ( *v9 )
          continue;
      }
    }
    return 0;
  }
  if ( a2 >= *(_DWORD *)(v5 + 20) )
    return 0;
  v11 = a2;
  v12 = *(CHAR ****)(v5 + 8);
  if ( a2 > 0 )
  {
    while ( v12 )
    {
      v12 = (CHAR ***)v12[1];
      if ( --v11 <= 0 )
        goto LABEL_19;
    }
    goto LABEL_20;
  }
LABEL_19:
  if ( !v12 )
  {
LABEL_20:
    v13 = 0;
    goto LABEL_22;
  }
  v13 = *v12;
LABEL_22:
  result = *v13;
  if ( !result )
    return &byte_629120;
  return result;
}
