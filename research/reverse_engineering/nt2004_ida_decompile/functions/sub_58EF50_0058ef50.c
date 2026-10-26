int __cdecl sub_58EF50(int a1, int a2)
{
  return *(_BYTE *)(a2 / 8 + a1) & (unsigned __int8)(1 << (a2 % 8));
}
