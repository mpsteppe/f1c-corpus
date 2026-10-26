void __stdcall sub_63153D(DWORD a1, DWORD a2)
{
  DWORD dwExceptionCode[8]; // [esp+8h] [ebp-20h] BYREF

  qmemcpy(dwExceptionCode, off_16C9978, sizeof(dwExceptionCode));
  dwExceptionCode[6] = a1;
  dwExceptionCode[7] = a2;
  RaiseException(dwExceptionCode[0], dwExceptionCode[1], dwExceptionCode[4], &dwExceptionCode[5]);
}
