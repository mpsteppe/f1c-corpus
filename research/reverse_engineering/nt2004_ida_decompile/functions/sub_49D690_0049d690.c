CHAR *__thiscall sub_49D690(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  CHAR **v4; // eax
  CHAR *result; // eax

  v2 = a2;
  if ( a2 >= 0 && a2 <= this[16] - 1 )
  {
    if ( a2 < this[16] )
    {
      v3 = this[13];
      if ( a2 <= 0 )
      {
LABEL_7:
        if ( v3 )
        {
          v4 = *(CHAR ***)v3;
LABEL_10:
          result = *v4;
          if ( result )
            return result;
          return &byte_629120;
        }
      }
      else
      {
        while ( v3 )
        {
          v3 = *(_DWORD *)(v3 + 4);
          if ( --v2 <= 0 )
            goto LABEL_7;
        }
      }
    }
    v4 = 0;
    goto LABEL_10;
  }
  return &byte_629120;
}
