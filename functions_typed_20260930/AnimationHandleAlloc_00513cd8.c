int __cdecl sub_513CD8(int a1)
{
  int result; // eax

  result = CRC32Computation(0, 0, 0);
  *(_DWORD *)(a1 + 256) = result;
  return result;
}

