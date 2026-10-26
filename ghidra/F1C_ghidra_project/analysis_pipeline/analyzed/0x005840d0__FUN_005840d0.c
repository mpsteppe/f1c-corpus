// Function: FUN_005840d0 @ 005840d0
// Size (bytes): 49


void __fastcall FUN_005840d0(int param_1)

{
  DWORD DVar1;
  
  DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xd4),1);
  if (((DVar1 != 0x102) && (DVar1 != 0xffffffff)) && (*(HANDLE *)(param_1 + 0xd4) != (HANDLE)0x0)) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xd4));
  }
  return;
}


