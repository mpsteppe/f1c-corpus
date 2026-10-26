// Microsoft VisualC 2-14/net runtime
void *__stdcall unknown_libname_191(void *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD *v8; // esi
  void *result; // eax
  _DWORD v10[6]; // [esp+8h] [ebp-18h] BYREF

  v8 = std::fpos<int>::fpos<int>(v10, -1);
  result = a1;
  qmemcpy(a1, v8, 0x18u);
  return result;
}
