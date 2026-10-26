// f1_2002_full  0x00481140  size=68
char *__thiscall sub_481140(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  char **v4; // eax
  char *result; // eax

  v2 = a2;
  if ( a2 <= this[20] - 1 )
  {
    if ( a2 >= 0 && a2 < this[20] )
    {
      v3 = this[17];
      if ( a2 <= 0 )
      {
LABEL_7:
        if ( v3 )
        {
          v4 = *(char ***)v3;
LABEL_10:
          result = *v4;
          if ( result )
            return result;
          return &byte_5C97DC;
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
  return &byte_5C97DC;
}
