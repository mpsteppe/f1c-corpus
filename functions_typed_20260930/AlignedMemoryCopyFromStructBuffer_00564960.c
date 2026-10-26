unsigned int __fastcall sub_564960(int a1, const void *a2, int a3)
{
  int v4; // ecx
  void *v5; // edi
  unsigned int result; // eax

  v5 = (void *)LinearInterpolation(a1, a3);
  result = *(_DWORD *)(v4 + 8);
  qmemcpy(v5, a2, result);
  return result;
}

