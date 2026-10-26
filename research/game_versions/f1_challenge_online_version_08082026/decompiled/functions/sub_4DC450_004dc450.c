int __fastcall sub_4DC450(int a1, char a2, const char *a3, char a4)
{
  int result; // eax
  unsigned int v5; // kr04_4
  char *i; // eax
  const char *v7; // esi
  char *v8; // ecx
  int v9; // [esp+4h] [ebp-18h]

  result = 1;
  v9 = 1;
  if ( a1 && a3 )
  {
    sub_566650(a3);
    v5 = strlen(byte_5EA438) + 1;
    if ( (int)(v5 - 1) > 0 )
    {
      for ( i = &byte_5EA438[v5 - 2]; i > byte_5EA438; --i )
      {
        if ( *i == 92 )
          break;
      }
      *i = 0;
    }
    sub_53C800(byte_5EA438);
    v7 = &a3[strlen(a3)];
    if ( v7 > a3 )
    {
      while ( *v7 != 92 )
      {
        if ( --v7 <= a3 )
          goto LABEL_13;
      }
      ++v7;
    }
LABEL_13:
    if ( !sub_546AA0(a2, v7) )
    {
      v9 = 0;
      if ( a4 )
      {
        sub_566650(v7);
        v8 = &byte_5EA438[strlen(byte_5EA438)];
        if ( v8 > byte_5EA438 )
        {
          while ( *v8 != 46 )
          {
            if ( --v8 <= byte_5EA438 )
              goto LABEL_20;
          }
          *v8 = 0;
        }
LABEL_20:
        sub_589901(byte_5EA438);
        sub_5472B0(byte_5EA438);
      }
    }
    sub_53C900(byte_5EA438);
    return v9;
  }
  return result;
}
