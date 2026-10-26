// Address: 0x0051cd3e
// Size: 21 bytes
// Name: sub_51CD3E
// Type: int __cdecl(int)
// Source: IDA Hex-Rays decompilation

int __cdecl sub_51CD3E(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 412);
  *(_BYTE *)(result + 36) = 0;
  *(_DWORD *)(result + 44) = *(_DWORD *)(a1 + 96);
  return result;
}
