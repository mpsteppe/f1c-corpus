int __cdecl sub_54F432(int a1, double a2, double a3)
{
  int result; // eax

  result = a1;
  if ( fabs(a2 * a3 - 1.0) > 0.05 )
    *(_BYTE *)(a1 + 97) |= 0x20u;
  *(float *)(a1 + 304) = a3;
  *(float *)(a1 + 308) = a2;
  return result;
}
