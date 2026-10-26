int __stdcall sub_6B7BD3(int a1, int a2, int a3)
{
  int result; // eax

  result = sub_6B7904(a1, (int)"IDAT", a2, a3);
  *(_DWORD *)(a1 + 88) |= 4u;
  return result;
}
