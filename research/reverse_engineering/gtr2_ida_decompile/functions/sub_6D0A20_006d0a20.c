int __stdcall sub_6D0A20(int a1)
{
  int (__stdcall **v1)(int *); // eax
  int (__stdcall **v2)(int, int, int); // ecx
  void *v3; // edi
  int result; // eax
  unsigned int v5; // ecx
  int v6; // [esp-4h] [ebp-10h]

  v1 = (int (__stdcall **)(int *))(**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 64);
  v2 = *(int (__stdcall ***)(int, int, int))(a1 + 4);
  v6 = *(_DWORD *)(a1 + 36) << 8;
  *v1 = sub_6D07D0;
  *(_DWORD *)(a1 + 448) = v1;
  v1[11] = 0;
  v1[12] = 0;
  v1[13] = 0;
  v1[14] = 0;
  v3 = (void *)(*v2)(a1, 1, v6);
  result = *(_DWORD *)(a1 + 36);
  *(_DWORD *)(a1 + 164) = v3;
  if ( result > 0 )
  {
    v5 = ((unsigned int)byte_FFFFFF & result) << 6;
    result = -1;
    memset(v3, 0xFFu, 4 * v5);
  }
  return result;
}
