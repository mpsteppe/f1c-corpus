// Function: FUN_00406700 @ 00406700
// Size (bytes): 70


undefined4 __thiscall FUN_00406700(int param_1,undefined4 param_2)

{
  DWORD DVar1;
  
  if (*(HANDLE *)(param_1 + 0x50) != (HANDLE)0x0) {
    DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x50),*(DWORD *)(param_1 + 0x54));
    if ((DVar1 == 0) || (DVar1 == 0x80)) {
      *(undefined4 *)(param_1 + 0x4c) = param_2;
      if (*(HANDLE *)(param_1 + 0x50) != (HANDLE)0x0) {
        ReleaseMutex(*(HANDLE *)(param_1 + 0x50));
      }
      return 1;
    }
  }
  return 0;
}


