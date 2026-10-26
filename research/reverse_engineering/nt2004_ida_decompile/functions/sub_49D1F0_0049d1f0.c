CHAR *__thiscall sub_49D1F0(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  CHAR **v4; // eax
  CHAR *result; // eax

  v2 = a2;
  if ( a2 < 0 || a2 >= this[20] )
    return 0;
  v3 = this[17];
  if ( a2 > 0 )
  {
    while ( v3 )
    {
      v3 = *(_DWORD *)(v3 + 4);
      if ( --v2 <= 0 )
        goto LABEL_6;
    }
    return 0;
  }
LABEL_6:
  if ( !v3 )
    return 0;
  v4 = *(CHAR ***)v3;
  if ( !v4 )
    return 0;
  result = *v4;
  if ( !result )
    return &byte_629120;
  return result;
}
