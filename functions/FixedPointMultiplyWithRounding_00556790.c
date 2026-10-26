int __cdecl FixedPointMultiplyWithRounding(int a1, int a2)
{
  return (unsigned __int64)(a2 * (__int64)a1 + 0x8000) >> 16;
}
