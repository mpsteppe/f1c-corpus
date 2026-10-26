// Microsoft VisualC 2-14/net runtime
void __cdecl unknown_libname_5()
{
  LPVOID *v0; // ebp
  _DWORD *v1; // esi
  _DWORD *v2; // edi
  char v3; // al
  void *v4; // ebx

  v0 = (LPVOID *)dword_6291CC;
  if ( dword_6291CC )
  {
    sub_40A820(dword_6291CC);
    if ( v0[7] )
      sub_5BE8AE(v0[7]);
    v1 = *v0;
    if ( *v0 )
    {
      do
      {
        v2 = v1;
        v3 = *((_BYTE *)v1 + 12);
        v1 = (_DWORD *)v1[1];
        if ( v3 )
        {
          v4 = (void *)*v2;
          if ( *v2 )
          {
            sub_459AC0(*v2);
            sub_5BE8AE(v4);
          }
        }
        sub_5BE8AE(v2);
      }
      while ( v1 );
    }
    *v0 = 0;
    v0[1] = 0;
    v0[2] = 0;
    v0[3] = 0;
    sub_5BE8AE(v0);
  }
}
