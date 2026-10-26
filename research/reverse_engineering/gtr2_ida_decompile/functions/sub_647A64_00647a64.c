void *__stdcall sub_647A64(int a1)
{
  _DWORD *v1; // esi
  void *result; // eax

  v1 = *(_DWORD **)(a1 + 24);
  result = operator new(0x1000u);
  v1[6] = result;
  *v1 = result;
  v1[1] = 4096;
  return result;
}
