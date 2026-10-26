char __stdcall sub_5E7FB0(const char *a1, char *String, char a3)
{
  char result; // al
  int v4; // ecx
  const char *v5; // esi
  char *v6; // eax
  char v7; // cl

  result = 0;
  if ( String )
  {
    v4 = strlen(a1);
    strcpy(String, ".BMP");
    if ( v4 >= 0 )
    {
      while ( a1[v4] != 46 )
      {
        if ( --v4 < 0 )
          return result;
      }
      v5 = &a1[v4];
      v6 = (char *)&a1[v4];
      do
      {
        v7 = *v6;
        v6[String - v5] = *v6;
        ++v6;
      }
      while ( v7 );
      _strupr(String);
      if ( a3 )
        *v5 = 0;
      return 1;
    }
  }
  return result;
}
