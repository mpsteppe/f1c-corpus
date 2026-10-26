// Address: 0x0051176b
// Size: 17 bytes
// Name: sub_51176B
// Type: int __cdecl(int *)
// Source: IDA Hex-Rays decompilation

int __cdecl sub_51176B(int *a1)
{
  int result; // eax

  *(_DWORD *)(*a1 + 108) = 0;
  result = *a1;
  *(_DWORD *)(*a1 + 20) = 0;
  return result;
}
