void __cdecl sub_4B27E0()
{
  int v0; // esi
  LPVOID *v1; // edi
  bool v2; // zf
  int v3; // edi
  LPVOID **v4; // esi
  LPVOID *v5; // ebp

  v0 = dword_765E60;
  while ( v0 )
  {
    v1 = (LPVOID *)v0;
    v2 = *(_BYTE *)(v0 + 8) == 0;
    v0 = *(_DWORD *)(v0 + 4);
    if ( !v2 )
      sub_5BE8AE(*v1);
    sub_5BE8AE(v1);
  }
  v3 = dword_765E50;
  dword_765E60 = 0;
  dword_765E64 = 0;
  dword_765E68 = 0;
  dword_765E6C = 0;
  while ( v3 )
  {
    v4 = (LPVOID **)v3;
    v2 = *(_BYTE *)(v3 + 8) == 0;
    v3 = *(_DWORD *)(v3 + 4);
    if ( !v2 )
    {
      v5 = *v4;
      if ( *v4 )
      {
        sub_5BE8AE(*v5);
        sub_5BE8AE(v5);
      }
    }
    sub_5BE8AE(v4);
  }
  dword_765E50 = 0;
  dword_765E54 = 0;
  dword_765E58 = 0;
  dword_765E5C = 0;
}
