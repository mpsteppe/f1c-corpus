int __stdcall sub_6DCE00(int a1, int a2, __m64 *a3, int a4, int a5)
{
  __m64 v6[36]; // [esp+0h] [ebp-120h] BYREF

  return sub_6DC6E0(a3, *(__m64 **)(a2 + 80), v6, a4, a5, *(_DWORD *)(a1 + 328) + 128);
}
