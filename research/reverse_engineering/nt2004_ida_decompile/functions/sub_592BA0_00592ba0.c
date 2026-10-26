int __stdcall sub_592BA0(const char *a1)
{
  int v1; // eax
  char v2; // cl
  signed int v3; // ecx
  int result; // eax
  char String[512]; // [esp+4h] [ebp-200h] BYREF

  strcpy(String, a1);
  _strupr(String);
  v1 = 0;
  do
  {
    v2 = String[v1];
    String[v1++ + 256] = v2;
  }
  while ( v2 );
  v3 = strlen(String) - 1;
  if ( v3 > 0 )
  {
    while ( String[v3] != 46 )
    {
      if ( --v3 <= 0 )
        goto LABEL_8;
    }
    String[v3] = 0;
  }
LABEL_8:
  result = sub_592CD0(String);
  if ( result )
    return sub_592C40(result);
  return result;
}
