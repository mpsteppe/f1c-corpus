void __cdecl _except2(DWORD dwExceptionCode, int a2, double a3, double a4, double a5, int a6)
{
  int v6; // eax
  ULONG_PTR Arguments[12]; // [esp+1Ch] [ebp-80h] BYREF
  double v8; // [esp+4Ch] [ebp-50h]
  unsigned int v9; // [esp+5Ch] [ebp-40h]
  int v10; // [esp+98h] [ebp-4h]

  v10 = dword_912B08;
  if ( !_handle_exc(dwExceptionCode, &a5, a6) )
  {
    v8 = a4;
    v9 = v9 & 0xFFFFFFE0 | 3;
    _raise_exc((ULONG_PTR)Arguments, (unsigned int *)&a6, dwExceptionCode, a2, &a3, &a5);
  }
  v6 = _errcode(dwExceptionCode);
  if ( dword_9137D8[0] || !v6 )
  {
    sub_63EC68(v6);
    _ctrlfp(a6, 0xFFFF);
  }
  else
  {
    _umatherr(v6, a2, SLODWORD(a3), SHIDWORD(a3), SLODWORD(a4), SHIDWORD(a4), a5, a6);
  }
}
