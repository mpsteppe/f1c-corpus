// Microsoft VisualC 2-14/net runtime
void __cdecl unknown_libname_28()
{
  char *v0; // esi
  int v1; // edi
  void *v2; // eax

  v0 = (char *)&unk_764504;
  v1 = 61;
  do
  {
    v2 = (void *)*((_DWORD *)v0 - 2);
    v0 -= 8;
    if ( v2 )
      sub_5BE8AE(v2);
    --v1;
  }
  while ( v1 );
}
