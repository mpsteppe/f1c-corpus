// Function: FUN_00585770 @ 00585770
// Size (bytes): 67


undefined4 __fastcall FUN_00585770(int param_1)

{
  undefined4 uVar1;
  DWORD DVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 + 0xec);
  if ((*(HANDLE *)(param_1 + 0xf0) == (HANDLE)0x0) ||
     ((DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xf0),*(DWORD *)(param_1 + 0xf4)),
      DVar2 != 0 && (DVar2 != 0x80)))) {
    puVar3 = (undefined4 *)0x0;
  }
  uVar1 = *puVar3;
  if (*(HANDLE *)(param_1 + 0xf0) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xf0));
  }
  return uVar1;
}


