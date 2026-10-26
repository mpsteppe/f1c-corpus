void __cdecl sub_41ECE0()
{
  int v0; // ecx
  void *v1; // edi
  LPVOID *v2; // esi
  int v3; // ecx
  int v4; // ebx
  void *v5; // eax

  if ( unk_62A178 )
  {
    v0 = *(_DWORD *)(unk_62A178 - 4);
    v1 = (void *)(unk_62A178 - 4);
    v2 = (LPVOID *)(unk_62A178 + 16 * v0);
    v3 = v0 - 1;
    if ( v3 >= 0 )
    {
      v4 = v3 + 1;
      do
      {
        v5 = *(v2 - 2);
        v2 -= 4;
        if ( v5 )
          sub_5BE8AE(v5);
        if ( *v2 )
          sub_5BE8AE(*v2);
        --v4;
      }
      while ( v4 );
    }
    sub_5BE8AE(v1);
  }
}
