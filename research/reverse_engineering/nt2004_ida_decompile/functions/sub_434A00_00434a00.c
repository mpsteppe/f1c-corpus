int sub_434A00()
{
  int v0; // esi
  void *v1; // edi
  int v2; // esi
  void *v3; // edi
  int result; // eax

  sub_435F50(&dword_75E8F0);
  v0 = dword_75E920;
  while ( v0 )
  {
    v1 = (void *)v0;
    v0 = *(_DWORD *)(v0 + 4);
    sub_4A82F0(v1);
    sub_5BE8AE(v1);
  }
  v2 = dword_75E90C;
  dword_75E920 = 0;
  dword_75E924 = 0;
  dword_75E928 = 0;
  dword_75E92C = 0;
  while ( v2 )
  {
    v3 = (void *)v2;
    v2 = *(_DWORD *)(v2 + 4);
    sub_436F20(v3);
    sub_5BE8AE(v3);
  }
  dword_75E90C = 0;
  dword_75E910 = 0;
  dword_75E914 = 0;
  dword_75E918 = 0;
  if ( dword_75E900 )
    sub_5BE8AE((LPVOID)dword_75E900);
  if ( dword_75E8F8 )
    sub_5BE8AE((LPVOID)dword_75E8F8);
  result = dword_75E8F0;
  if ( dword_75E8F0 )
    return sub_5BE8AE((LPVOID)dword_75E8F0);
  return result;
}
