int __cdecl sub_516937(int a1)
{
  int result; // eax

  (*(void (__cdecl **)(int, int))(*(_DWORD *)(a1 + 4) + 36))(a1, 1);
  result = *(_BYTE *)(a1 + 12) != 0 ? 200 : 100;
  *(_DWORD *)(a1 + 16) = result;
  return result;
}
