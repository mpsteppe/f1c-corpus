int __stdcall sub_6B7BF6(int a1)
{
  int result; // eax

  result = sub_6B7904(a1, (int)"IEND", 0, 0);
  *(_DWORD *)(a1 + 88) |= 0x10u;
  return result;
}
