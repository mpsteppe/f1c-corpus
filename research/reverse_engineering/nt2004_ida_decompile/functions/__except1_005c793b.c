double __cdecl _except1(DWORD dwExceptionCode, int a2, double a3, double a4, int a5)
{
  int v5; // eax
  double result; // st7
  ULONG_PTR Arguments[14]; // [esp+1Ch] [ebp-58h] BYREF
  int v8; // [esp+54h] [ebp-20h]

  if ( !_handle_exc(dwExceptionCode, &a4, a5) )
  {
    v8 &= ~1u;
    _raise_exc((ULONG_PTR)Arguments, (int)&a5, dwExceptionCode, a2, (int)&a3, (int)&a4);
  }
  v5 = _errcode(dwExceptionCode);
  if ( dword_628770 || !v5 )
  {
    _set_errno(v5);
    _ctrlfp(a5, 0xFFFF);
    return a4;
  }
  else
  {
    result = a3;
    _umatherr(
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
