int __stdcall sub_5E8FA0(const char *a1, char **a2)
{
  _DWORD *v2; // eax
  char *v3; // edi

  v2 = operator new(0x450u);
  if ( v2 )
    v3 = (char *)sub_5E8AC0(v2);
  else
    v3 = 0;
  strcpy(v3 + 4, a1);
  _strupr(v3 + 4);
  if ( a2 )
    *a2 = v3;
  return 0;
}
