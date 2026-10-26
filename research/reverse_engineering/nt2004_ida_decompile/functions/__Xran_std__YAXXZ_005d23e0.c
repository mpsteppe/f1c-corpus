void __cdecl __noreturn std::_Xran()
{
  size_t v0; // eax
  _DWORD pExceptionObject[7]; // [esp+4h] [ebp-3Ch] BYREF
  _DWORD v2[4]; // [esp+20h] [ebp-20h] BYREF
  char v3; // [esp+33h] [ebp-Dh]
  int v4; // [esp+3Ch] [ebp-4h]

  LOBYTE(v2[0]) = v3;
  std::string::_Tidy(v2, 0);
  v0 = strlen("invalid string position");
  std::string::assign((int)v2, (void *)"invalid string position", v0);
  v4 = 0;
  sub_5D221B((exception *)pExceptionObject, v2);
  pExceptionObject[0] = &std::out_of_range::`vftable';
  _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI3_AVout_of_range_std__);
}
