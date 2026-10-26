// Address: 0x0051dfa8
// Size: 34 bytes
// Name: sub_51DFA8
// Type: int __cdecl(int)
// Source: IDA Hex-Rays decompilation

int __cdecl sub_51DFA8(int a1)
{
  int v1; // esi
  int result; // eax

  v1 = *(_DWORD *)(a1 + 420);
  *(_DWORD *)(a1 + 116) = *(_DWORD *)(v1 + 16);
  result = sub_51D80A(*(_DWORD *)(v1 + 20));
  *(_BYTE *)(v1 + 28) = 1;
  return result;
}
