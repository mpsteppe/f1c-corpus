// Function: FUN_00585810 @ 00585810
// Size (bytes): 72


undefined1 __fastcall FUN_00585810(int param_1)

{
  undefined1 uVar1;
  
  if (*(HANDLE *)(param_1 + 0x640) != (HANDLE)0x0) {
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x640),*(DWORD *)(param_1 + 0x644));
  }
  uVar1 = FUN_00587210();
  if (*(HANDLE *)(param_1 + 0x640) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0x640));
  }
  return uVar1;
}


