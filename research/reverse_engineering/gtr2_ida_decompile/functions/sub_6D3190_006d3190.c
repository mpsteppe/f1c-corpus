int __stdcall sub_6D3190(int a1, int a2, int *a3, int a4, int a5, int *a6, int a7)
{
  int v7; // ecx
  int result; // eax

  (*(void (__stdcall **)(int, int, int, int))(*(_DWORD *)(a1 + 456) + 12))(a1, a2, *a3, a5 + 4 * *a6);
  v7 = *a6 + 1;
  result = *a3 + 1;
  *a3 = result;
  *a6 = v7;
  return result;
}
