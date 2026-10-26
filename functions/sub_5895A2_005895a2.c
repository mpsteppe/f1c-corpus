double __cdecl sub_5895A2(double a1)
{
  double result; // st7
  int v2; // ebx
  int v3; // eax

  result = a1;
  v2 = ReturnFPUControlWord(dword_5E65A0, 0xFFFF);
  if ( (HIWORD(a1) & 0x7FF0) == 0x7FF0 )
  {
    v3 = UtilityFunction_1d2e(LODWORD(a1), HIDWORD(a1));
    if ( v3 > 0 )
    {
      if ( v3 <= 2 )
      {
        ReturnFPUControlWord(v2, 0xFFFF);
        return a1;
      }
      if ( v3 == 3 )
      {
        result = a1;
        MathDispatchWithErrorFallback(11, a1, v2);
        return result;
      }
    }
    result = a1;
    ConditionalMathWithDAT005e9ad0Flag(
      8u,
      11,
      SLODWORD(a1),
      SHIDWORD(a1),
      COERCE_UNSIGNED_INT64(a1 + 1.0),
      HIDWORD(COERCE_UNSIGNED_INT64(a1 + 1.0)),
      v2);
  }
  else
  {
    FrndMSVCCRTRounding(a1);
    ReturnFPUControlWord(v2, 0xFFFF);
  }
  return result;
}
