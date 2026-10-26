
undefined4 * __fastcall FUN_00585ea0(undefined4 *param_1)

{
  HANDLE pvVar1;
  _SECURITY_ATTRIBUTES _Stack_c;
  
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = 0xffffffff;
  _Stack_c.nLength = 0xc;
  _Stack_c.lpSecurityDescriptor = (LPVOID)0x0;
  _Stack_c.bInheritHandle = 1;
  pvVar1 = CreateMutexA(&_Stack_c,0,(LPCSTR)0x0);
  param_1[3] = pvVar1;
  if (pvVar1 != (HANDLE)0x0) {
    *(undefined1 *)(param_1 + 5) = 1;
  }
  *(undefined1 *)(param_1 + 6) = 0;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 9) = 0;
  param_1[8] = 0xffffffff;
  _Stack_c.nLength = 0xc;
  _Stack_c.lpSecurityDescriptor = (LPVOID)0x0;
  _Stack_c.bInheritHandle = 1;
  pvVar1 = CreateMutexA(&_Stack_c,0,(LPCSTR)0x0);
  param_1[7] = pvVar1;
  if (pvVar1 != (HANDLE)0x0) {
    *(undefined1 *)(param_1 + 9) = 1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

