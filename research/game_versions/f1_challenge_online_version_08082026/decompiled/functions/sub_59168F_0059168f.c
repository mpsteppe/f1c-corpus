double __cdecl sub_59168F(DWORD dwExceptionCode, int a2, double a3, double a4, int a5)
{
  int v5; // eax
  double result; // st7
  ULONG_PTR Arguments[14]; // [esp+1Ch] [ebp-58h] BYREF
  int v8; // [esp+54h] [ebp-20h]

  if ( !sub_5919DA(dwExceptionCode, &a4, a5) )
  {
    v8 &= ~1u;
    sub_591727((ULONG_PTR)Arguments, (int)&a5, dwExceptionCode, a2, (int)&a3, (int)&a4);
  }
  v5 = sub_591CC6(dwExceptionCode);
  if ( dword_5E9AD0 || !v5 )
  {
    sub_591C79(v5);
    sub_591E66(a5, 0xFFFF);
    return a4;
  }
  else
  {
    result = a3;
    sub_591BF1(
      v5,
      a2,
      SLODWORD(a3),
      SHIDWORD(a3),
      COERCE_UNSIGNED_INT64(0.0),
      HIDWORD(COERCE_UNSIGNED_INT64(0.0)),
      a4,
      a5);
  }
  return result;
}
