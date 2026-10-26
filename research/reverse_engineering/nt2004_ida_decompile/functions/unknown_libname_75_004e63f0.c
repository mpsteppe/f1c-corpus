// Microsoft VisualC 2-14/net runtime
void __cdecl unknown_libname_75()
{
  int v0; // eax
  void *v1; // edi
  LPVOID *v2; // esi
  int v3; // eax
  int v4; // ebx
  void *v5; // eax

  if ( dword_7D6A5C )
  {
    v0 = *(_DWORD *)(dword_7D6A5C - 4);
    v1 = (void *)(dword_7D6A5C - 4);
    v2 = (LPVOID *)(dword_7D6A5C + 1232 * v0);
    v3 = v0 - 1;
    if ( v3 >= 0 )
    {
      v4 = v3 + 1;
      do
      {
        v5 = *(v2 - 294);
        v2 -= 308;
        if ( v5 )
          sub_5BE8AE(v5);
        if ( v2[8] )
          sub_5BE8AE(v2[8]);
        if ( v2[6] )
          sub_5BE8AE(v2[6]);
        if ( v2[4] )
          sub_5BE8AE(v2[4]);
        if ( v2[2] )
          sub_5BE8AE(v2[2]);
        if ( *v2 )
          sub_5BE8AE(*v2);
        --v4;
      }
      while ( v4 );
    }
    sub_5BE8AE(v1);
  }
}
