int __stdcall sub_4A2A40(const char *a1, LPCSTR lpSrcStr)
{
  int v2; // ebx
  signed int i; // edx
  CHAR v4; // al

  v2 = 0;
  for ( i = 0; i < (int)strlen(a1); ++i )
  {
    v4 = a1[i];
    if ( v4 != 34 )
      lpSrcStr[v2++] = v4;
  }
  lpSrcStr[v2] = 0;
  return sub_589901(lpSrcStr);
}
