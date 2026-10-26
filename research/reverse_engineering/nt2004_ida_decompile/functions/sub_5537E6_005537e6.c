int __cdecl sub_5537E6(int a1)
{
  signed int i; // edi

  for ( i = 1; i >= 0; --i )
    sub_553705((_DWORD *)a1, i);
  sub_5562DF(a1, *(LPVOID *)(a1 + 4));
  *(_DWORD *)(a1 + 4) = 0;
  return nullsub_9(a1);
}
