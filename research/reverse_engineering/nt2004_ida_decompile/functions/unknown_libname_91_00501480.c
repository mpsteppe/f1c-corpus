// Microsoft VisualC 2-14/net runtime
int *unknown_libname_91()
{
  int *result; // eax
  _DWORD *v1; // edx
  int v2; // esi

  result = &dword_7D7928;
  v1 = &unk_7D795C;
  v2 = 3;
  do
  {
    v1[3] = 0;
    *v1++ = 0;
    --v2;
  }
  while ( v2 );
  return result;
}
