int __cdecl sub_558C8B(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, int a7)
{
  int v7; // ebx
  int v8; // esi
  _DWORD *v9; // edi
  unsigned int v10; // eax
  int result; // eax

  v7 = a1;
  v8 = *(_DWORD *)(a1 + 392);
  v9 = a6;
  v10 = a7 - *a6;
  if ( v10 > *(_DWORD *)(v8 + 16) )
    v10 = *(_DWORD *)(v8 + 16);
  a1 = 0;
  (*(void (__cdecl **)(int, int, int, int, _DWORD, int *, unsigned int))(*(_DWORD *)(v7 + 412) + 4))(
    v7,
    a2,
    a3,
    a4,
    *(_DWORD *)(v8 + 12),
    &a1,
    v10);
  (*(void (__cdecl **)(int, _DWORD, int, int))(*(_DWORD *)(v7 + 420) + 4))(v7, *(_DWORD *)(v8 + 12), a5 + 4 * *v9, a1);
  result = a1;
  *v9 += a1;
  return result;
}
