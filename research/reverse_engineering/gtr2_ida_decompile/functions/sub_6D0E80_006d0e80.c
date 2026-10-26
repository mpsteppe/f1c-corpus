int __stdcall sub_6D0E80(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, int a7)
{
  _DWORD *v7; // ebx
  int v8; // esi
  int v9; // edi
  unsigned int v10; // eax
  int v11; // ecx
  int result; // eax

  v7 = a6;
  v8 = a1;
  v9 = *(_DWORD *)(a1 + 436);
  v10 = a7 - *a6;
  if ( v10 > *(_DWORD *)(v9 + 16) )
    v10 = *(_DWORD *)(v9 + 16);
  v11 = *(_DWORD *)(a1 + 456);
  a1 = 0;
  (*(void (__stdcall **)(int, int, int, int, _DWORD, int *, unsigned int))(v11 + 4))(
    v8,
    a2,
    a3,
    a4,
    *(_DWORD *)(v9 + 12),
    &a1,
    v10);
  (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)(v8 + 464) + 4))(v8, *(_DWORD *)(v9 + 12), a5 + 4 * *v7, a1);
  result = a1 + *v7;
  *v7 = result;
  return result;
}
