// Microsoft VisualC 2-14/net runtime
void __cdecl unknown_libname_2()
{
  int v0; // edi
  _DWORD *v1; // esi
  void *v2; // ebx

  v0 = dword_629124;
  if ( dword_629124 )
  {
    if ( *(_DWORD *)(dword_629124 + 100) )
      sub_5BE8AE(*(LPVOID *)(dword_629124 + 100));
    v1 = *(_DWORD **)(v0 + 68);
    while ( v1 )
    {
      v2 = v1;
      v1 = (_DWORD *)v1[1];
      sub_4145A0(v2);
      sub_5BE8AE(v2);
    }
    *(_DWORD *)(v0 + 68) = 0;
    *(_DWORD *)(v0 + 72) = 0;
    *(_DWORD *)(v0 + 76) = 0;
    *(_DWORD *)(v0 + 80) = 0;
    if ( *(_DWORD *)(v0 + 60) )
      sub_5BE8AE(*(LPVOID *)(v0 + 60));
    if ( *(_DWORD *)(v0 + 52) )
      sub_5BE8AE(*(LPVOID *)(v0 + 52));
    if ( *(_DWORD *)(v0 + 44) )
      sub_5BE8AE(*(LPVOID *)(v0 + 44));
    sub_5BE8AE((LPVOID)v0);
  }
}
