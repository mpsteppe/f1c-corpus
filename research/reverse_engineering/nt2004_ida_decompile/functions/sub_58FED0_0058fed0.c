int __cdecl sub_58FED0(int a1)
{
  int result; // eax

  result = a1;
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = -1;
  *(_DWORD *)(a1 + 8) = 0;
  *(_BYTE *)(a1 + 12) = -1;
  *(_BYTE *)(a1 + 13) = -1;
  *(_BYTE *)(a1 + 14) = -1;
  *(_BYTE *)(a1 + 15) = -1;
  return result;
}
