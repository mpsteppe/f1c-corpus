// f1c  0x005020bf  size=67
unsigned int __cdecl sub_5020BF(int a1, void *a2, unsigned int a3)
{
  int v3; // ebx
  unsigned int result; // eax

  v3 = *(_DWORD *)(a1 + 84);
  if ( a3 > *(_DWORD *)(v3 + 4) )
    sub_511869(a1, "read error");
  qmemcpy(a2, *(const void **)v3, a3);
  result = a3;
  *(_DWORD *)v3 += a3;
  *(_DWORD *)(v3 + 4) -= a3;
  return result;
}
