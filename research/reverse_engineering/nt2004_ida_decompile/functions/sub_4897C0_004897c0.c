CHAR *__thiscall sub_4897C0(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // eax
  CHAR **v5; // eax
  CHAR *result; // eax

  v2 = a2;
  v3 = this[219];
  if ( a2 >= v3 || a2 < 0 || a2 >= v3 )
    return &byte_629120;
  v4 = this[216];
  if ( a2 > 0 )
  {
    while ( v4 )
    {
      v4 = *(_DWORD *)(v4 + 4);
      if ( --v2 <= 0 )
        goto LABEL_7;
    }
    return &byte_629120;
  }
LABEL_7:
  if ( !v4 )
    return &byte_629120;
  v5 = *(CHAR ***)v4;
  if ( !v5 )
    return &byte_629120;
  result = *v5;
  if ( !result )
    return &byte_629120;
  return result;
}
