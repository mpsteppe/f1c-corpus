// Function: FUN_004066c0 @ 004066c0
// Size (bytes): 58


undefined4 __fastcall FUN_004066c0(int param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (*(HANDLE *)(param_1 + 0x50) != (HANDLE)0x0) {
    DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x50),*(DWORD *)(param_1 + 0x54));
    if ((DVar1 == 0) || (DVar1 == 0x80)) {
      uVar2 = *(undefined4 *)(param_1 + 0x4c);
      if (*(HANDLE *)(param_1 + 0x50) != (HANDLE)0x0) {
        ReleaseMutex(*(HANDLE *)(param_1 + 0x50));
      }
    }
  }
  return uVar2;
}


