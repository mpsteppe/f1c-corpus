// Function: FUN_00582360 @ 00582360
// Size (bytes): 92


undefined1 __fastcall FUN_00582360(int param_1)

{
  BOOL BVar1;
  HANDLE pvVar2;
  _SECURITY_ATTRIBUTES local_c;
  
  if (*(char *)(param_1 + 0x18) != '\0') {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 0x10));
    if (BVar1 != 0) {
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
  }
  local_c.nLength = 0xc;
  local_c.lpSecurityDescriptor = (LPVOID)0x0;
  local_c.bInheritHandle = 1;
  pvVar2 = CreateMutexA(&local_c,0,(LPCSTR)0x0);
  *(HANDLE *)(param_1 + 0x10) = pvVar2;
  if (pvVar2 != (HANDLE)0x0) {
    *(undefined1 *)(param_1 + 0x18) = 1;
  }
  return *(undefined1 *)(param_1 + 0x18);
}


