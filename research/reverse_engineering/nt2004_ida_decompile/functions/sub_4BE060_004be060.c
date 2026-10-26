char *__stdcall sub_4BE060(const char *a1, char *String)
{
  int v2; // ebx
  signed int i; // edx
  char v4; // al

  v2 = 0;
  for ( i = 0; i < (int)strlen(a1); ++i )
  {
    v4 = a1[i];
    if ( v4 != 34 )
      String[v2++] = v4;
  }
  String[v2] = 0;
  return _strupr(String);
}
