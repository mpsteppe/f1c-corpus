// Address: 0x0051e0cd
// Size: 15 bytes
// Name: sub_51E0CD
// Type: int __cdecl(int)
// Source: IDA Hex-Rays decompilation

int __cdecl sub_51E0CD(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 420);
  *(_BYTE *)(result + 28) = 1;
  return result;
}
