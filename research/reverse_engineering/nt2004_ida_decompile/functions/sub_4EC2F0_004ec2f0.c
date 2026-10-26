CHAR *__thiscall sub_4EC2F0(int *this, int a2)
{
  int v2; // edx
  int v3; // eax
  CHAR **v4; // eax
  CHAR *result; // eax

  v2 = a2;
  if ( a2 < 0 || a2 >= this[3] )
    return 0;
  v3 = *this;
  if ( a2 > 0 )
  {
    while ( v3 )
    {
      v3 = *(_DWORD *)(v3 + 4);
      if ( --v2 <= 0 )
        goto LABEL_6;
    }
    goto LABEL_7;
  }
LABEL_6:
  if ( !v3 )
  {
LABEL_7:
    v4 = 0;
    goto LABEL_9;
  }
  v4 = *(CHAR ***)v3;
LABEL_9:
  result = *v4;
  if ( !result )
    return &byte_629120;
  return result;
}
