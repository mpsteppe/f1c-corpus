void __cdecl _except1(DWORD dwExceptionCode, int a2, double a3, double a4, int a5)
{
  int v5; // eax
  ULONG_PTR Arguments[16]; // [esp+1Ch] [ebp-80h] BYREF
  int v7; // [esp+5Ch] [ebp-40h]
  int v8; // [esp+98h] [ebp-4h]

  v8 = dword_912B08;
  if ( !_handle_exc(dwExceptionCode, &a4, a5) )
  {
    v7 &= ~1u;
    _raise_exc((ULONG_PTR)Arguments, (unsigned int *)&a5, dwExceptionCode, a2, &a3, &a4);
  }
  v5 = _errcode(dwExceptionCode);
  if ( dword_9137D8[0] || !v5 )
  {
    sub_63EC68(v5);
    _ctrlfp(a5, 0xFFFF);
  }
  else
  {
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
}
