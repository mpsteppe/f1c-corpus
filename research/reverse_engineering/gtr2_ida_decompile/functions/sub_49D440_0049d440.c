char *__thiscall sub_49D440(void *this)
{
  char *result; // eax
  int v2; // edx
  char v3; // cl
  char *v4; // eax
  char v5[256]; // [esp+0h] [ebp-100h] BYREF

  result = (char *)sub_4CE170(this);
  if ( result )
  {
    v2 = &unk_B6DCD0 - (_UNKNOWN *)result;
    do
    {
      v3 = *result;
      result[v2] = *result;
      ++result;
    }
    while ( v3 );
  }
  else
  {
    sub_617A70(256);
    v4 = &v5[strlen(v5)];
    if ( v4 > v5 )
    {
      while ( *v4 != 46 )
      {
        if ( --v4 <= v5 )
          goto LABEL_10;
      }
      *v4 = 0;
    }
LABEL_10:
    result = &v5[strlen(v5)];
    if ( result > v5 )
    {
      while ( *result != 92 )
      {
        if ( --result <= v5 )
          goto LABEL_15;
      }
      ++result;
    }
LABEL_15:
    if ( result )
    {
      result = (char *)sub_630FE0(&unk_B6DCD0, result, 25);
      byte_B6DCE9 = 0;
    }
  }
  return result;
}
