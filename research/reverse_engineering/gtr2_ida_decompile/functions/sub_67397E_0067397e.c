int __stdcall sub_67397E(int a1, int a2, const void *a3, int a4, int a5)
{
  qmemcpy(
    (void *)(16 * a2 + (*(int (__stdcall **)(int))(*(_DWORD *)a1 + 12))(a1)),
    a3,
    4 * ((unsigned int)(16 * a5) >> 2));
  return 0;
}
