// Address: 0x00588884
// Size: 34 bytes
// Name: sub_588884
// Type: int __cdecl(int, int, int, _DWORD *)
// Source: IDA Hex-Rays decompilation

int __cdecl sub_588884(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    *a4 = a2;
    return 3;
  }
  return result;
}
