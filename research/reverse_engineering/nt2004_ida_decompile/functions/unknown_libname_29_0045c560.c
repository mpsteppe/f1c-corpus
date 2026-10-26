// Microsoft VisualC 2-14/net runtime
char *unknown_libname_29()
{
  void *v0; // eax
  int v1; // eax
  CHAR *v2; // eax

  v0 = operator new(0x4BCu);
  if ( v0 )
    v1 = sub_45CE40(v0);
  else
    v1 = 0;
  *(_DWORD *)&byte_764D68 = v1;
  sub_578600("ARIAL.TTF");
  v2 = **(CHAR ***)&byte_764D68;
  if ( !**(_DWORD **)&byte_764D68 )
    v2 = &byte_629120;
  sub_506CA0(v2);
  return &byte_764D68;
}
