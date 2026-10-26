char __stdcall sub_56D280(unsigned int a1, _WORD *a2)
{
  const void *v2; // esi
  _WORD *v3; // edi
  _DWORD *v4; // ecx
  unsigned int v5; // ebx
  char result; // al

  v2 = *(const void **)(a1 + 20);
  v3 = a2;
  v4 = (_DWORD *)(a1 + 8);
  v5 = (*(_DWORD *)(a1 + 36) >> 3) + ((*(_DWORD *)(a1 + 36) & 7) != 0);
  *a2 = v5;
  v3[1] = sub_4AFC50(v4);
  qmemcpy(v3 + 2, v2, v5);
  sub_577610(&a2, &a1);
  result = 1;
  qmemcpy((char *)v3 + v5 + 4, a2, a1);
  return result;
}
