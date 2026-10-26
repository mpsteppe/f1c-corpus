char __stdcall sub_521240(char *a1)
{
  char v1; // al
  char result; // al
  char *i; // ecx
  char v4; // al
  char v5; // al
  char v6; // al
  char v7; // al

  v1 = *a1;
  if ( *a1 >= 97 && v1 <= 122 )
    *a1 = v1 - 32;
  result = a1[1];
  for ( i = a1 + 1; result; result = *++i )
  {
    v4 = *(i - 1);
    if ( (v4 < 97 || v4 > 122) && (v4 < 65 || v4 > 90) )
    {
      v7 = *i;
      if ( *i < 97 || v7 > 122 )
        continue;
      v6 = v7 - 32;
    }
    else
    {
      v5 = *i;
      if ( *i < 65 || v5 > 90 )
        continue;
      v6 = v5 + 32;
    }
    *i = v6;
  }
  return result;
}
