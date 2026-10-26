CHAR *__thiscall sub_4E4800(CHAR ****this, int a2)
{
  int v2; // edx
  CHAR *result; // eax
  CHAR ***v4; // ecx
  CHAR **v5; // ecx

  v2 = a2;
  result = 0;
  if ( a2 >= 0 && a2 < (int)this[3] )
  {
    v4 = *this;
    if ( a2 <= 0 )
    {
LABEL_6:
      if ( v4 )
      {
        v5 = *v4;
        if ( v5 )
        {
          result = *v5;
          if ( !*v5 )
            return &byte_629120;
        }
      }
    }
    else
    {
      while ( v4 )
      {
        v4 = (CHAR ***)v4[1];
        if ( --v2 <= 0 )
          goto LABEL_6;
      }
    }
  }
  return result;
}
