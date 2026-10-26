// f1c  0x00512319  size=9
int __cdecl sub_512319(int a1)
{
  int result; // eax

  result = a1;
  *(_DWORD *)(a1 + 96) |= 1u;
  return result;
}
