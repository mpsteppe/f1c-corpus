int __stdcall sub_6A4B6D(int a1, int a2)
{
  int v2; // eax
  void *v3; // eax

  v2 = *(_DWORD *)(a1 + 28);
  if ( (v2 & 7) == 0 )
  {
    v3 = (void *)sub_681169(v2 + 8);
    if ( !v3 )
      return -2147024882;
    qmemcpy(v3, *(const void **)(a1 + 32), 4 * *(_DWORD *)(a1 + 28));
    *(_DWORD *)(a1 + 32) = v3;
  }
  *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4 * (*(_DWORD *)(a1 + 28))++) = a2;
  return 0;
}
