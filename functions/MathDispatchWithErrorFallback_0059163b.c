double __cdecl sub_59163B(int a1, double a2, int a3)
{
  double result; // st7

  if ( dword_5E9AD0 )
  {
    *(_DWORD *)TLSOffsetGetter() = 33;
    ReturnFPUControlWord(a3, 0xFFFF);
    return a2;
  }
  else
  {
    result = a2;
    FloatParsingWithErrorHandling(
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
