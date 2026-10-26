// Address: 0x00515869
// Size: 35 bytes
// Name: sub_515869
// Type: int __cdecl(int, int)
// Source: IDA Hex-Rays decompilation

int __cdecl sub_515869(int a1, int a2)
{
  int result; // eax

  result = sub_51512C(a1, a2);
  if ( result >= 0 )
  {
    result = sub_513DAF(a1);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
