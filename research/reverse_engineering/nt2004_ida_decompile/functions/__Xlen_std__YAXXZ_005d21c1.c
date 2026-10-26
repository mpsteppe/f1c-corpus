void __stdcall __noreturn std::_Xlen(int a1)
{
  size_t v1; // eax
  void **pExceptionObject; // [esp+4h] [ebp-3Ch] BYREF
  _DWORD v3[4]; // [esp+20h] [ebp-20h] BYREF
  char v4; // [esp+33h] [ebp-Dh]
  int v5; // [esp+3Ch] [ebp-4h]

  LOBYTE(v3[0]) = v4;
  std::string::_Tidy(v3, 0);
  v1 = strlen("string too long");
  std::string::assign((int)v3, (void *)"string too long", v1);
  v5 = 0;
  sub_5D221B(v3);
  pExceptionObject = &std::length_error::`vftable';
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI3_AVlength_error_std__);
}
