// Microsoft VisualC 2-14/net runtime
void *__stdcall unknown_libname_190(void *a1, int a2, int a3, int a4)
{
  _DWORD *v4; // esi
  void *result; // eax
  _DWORD v6[6]; // [esp+8h] [ebp-18h] BYREF

  v4 = std::fpos<int>::fpos<int>(v6, -1);
  result = a1;
  qmemcpy(a1, v4, 0x18u);
  return result;
}
