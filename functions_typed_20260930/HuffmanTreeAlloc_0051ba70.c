int __cdecl sub_51BA70(int a1)
{
  int (__cdecl **v1)(int *); // eax
  int result; // eax
  int v3; // edx
  bool v4; // cc
  char *v5; // ebx
  void *v6; // edi

  v1 = (int (__cdecl **)(int *))(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 80);
  *(_DWORD *)(a1 + 404) = v1;
  *v1 = sub_51B7CD;
  v1[14] = 0;
  v1[15] = 0;
  v1[16] = 0;
  v1[17] = 0;
  result = (**(int (__cdecl ***)(int, int, _DWORD))(a1 + 4))(a1, 1, *(_DWORD *)(a1 + 32) << 8);
  v3 = 0;
  v4 = *(_DWORD *)(a1 + 32) <= 0;
  *(_DWORD *)(a1 + 140) = result;
  v5 = (char *)result;
  if ( !v4 )
  {
    do
    {
      result = -1;
      v6 = v5;
      v5 += 256;
      ++v3;
      memset(v6, 0xFFu, 0x100u);
    }
    while ( v3 < *(_DWORD *)(a1 + 32) );
  }
  return result;
}

