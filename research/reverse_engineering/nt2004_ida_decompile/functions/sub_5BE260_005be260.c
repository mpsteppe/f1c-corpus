unsigned int __fastcall sub_5BE260(int a1, const void *a2, int a3)
{
  int v4; // ecx
  void *v5; // edi
  unsigned int result; // eax

  v5 = (void *)sub_5BE1B0(a1, a3);
  result = *(_DWORD *)(v4 + 8);
  qmemcpy(v5, a2, result);
  return result;
}
