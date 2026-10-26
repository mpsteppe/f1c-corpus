// Microsoft VisualC 2-14/net runtime
_DWORD *unknown_libname_4()
{
  _DWORD *v0; // esi

  v0 = operator new(0x64u);
  if ( v0 )
  {
    *v0 = 0;
    v0[1] = 0;
    v0[2] = 0;
    v0[3] = 0;
    v0[7] = 0;
    v0[8] = -1;
    sub_40A820(v0);
    dword_6291CC = v0;
  }
  else
  {
    dword_6291CC = 0;
  }
  return &dword_6291CC;
}
