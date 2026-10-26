void __fastcall sub_5BE320(int a1, int (__cdecl *a2)(const void *, const void *))
{
  qsort(*(void **)(a1 + 20), *(_DWORD *)a1, *(_DWORD *)(a1 + 8), a2);
}
