int __cdecl sub_516853(int a1)
{
  signed int i; // edi

  for ( i = 1; i >= 0; --i )
    sub_516772((_DWORD *)a1, i);
  FreeWrapper_9351(a1, *(LPVOID *)(a1 + 4));
  *(_DWORD *)(a1 + 4) = 0;
  return EmptyStub_7b96(a1);
}

