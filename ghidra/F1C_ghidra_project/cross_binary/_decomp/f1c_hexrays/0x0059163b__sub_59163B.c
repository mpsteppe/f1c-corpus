// f1c  0x0059163b  size=84
double __cdecl sub_59163B(int a1, double a2, int a3)
{
  double result; // st7

  if ( dword_5E9AD0 )
  {
    *(_DWORD *)sub_58AFCF() = 33;
    sub_591E66(a3, 0xFFFF);
    return a2;
  }
  else
  {
    result = a2;
    sub_591BF1(
      1,
      a1,
      SLODWORD(a2),
      SHIDWORD(a2),
      COERCE_UNSIGNED_INT64(0.0),
      HIDWORD(COERCE_UNSIGNED_INT64(0.0)),
      a2,
      a3);
  }
  return result;
}
