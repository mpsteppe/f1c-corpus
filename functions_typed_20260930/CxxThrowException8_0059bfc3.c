void __stdcall sub_59BFC3(DWORD a1, DWORD a2)
{
  DWORD dwExceptionCode[8]; // [esp+8h] [ebp-20h] BYREF

  qmemcpy(dwExceptionCode, &unk_5B9DE0, sizeof(dwExceptionCode));
  dwExceptionCode[6] = a1;
  dwExceptionCode[7] = a2;
  RaiseException(dwExceptionCode[0], dwExceptionCode[1], dwExceptionCode[4], &dwExceptionCode[5]);
}

