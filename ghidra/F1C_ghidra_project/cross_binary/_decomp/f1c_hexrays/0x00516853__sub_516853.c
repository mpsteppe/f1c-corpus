// f1c  0x00516853  size=48
int __cdecl sub_516853(int a1)
{
  signed int i; // edi

  for ( i = 1; i >= 0; --i )
    sub_516772((_DWORD *)a1, i);
  sub_519351(a1, *(LPVOID *)(a1 + 4));
  *(_DWORD *)(a1 + 4) = 0;
  return nullsub_8(a1);
}
