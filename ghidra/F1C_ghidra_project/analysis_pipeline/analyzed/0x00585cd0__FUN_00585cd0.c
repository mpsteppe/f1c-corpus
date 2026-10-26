// Function: FUN_00585cd0 @ 00585cd0
// Size (bytes): 69


void __thiscall FUN_00585cd0(int param_1,undefined4 param_2)

{
  DWORD DVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x5b4);
  if ((*(HANDLE *)(param_1 + 0x5b8) == (HANDLE)0x0) ||
     ((DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x5b8),*(DWORD *)(param_1 + 0x5bc)),
      DVar1 != 0 && (DVar1 != 0x80)))) {
    puVar2 = (undefined4 *)0x0;
  }
  *puVar2 = param_2;
  if (*(HANDLE *)(param_1 + 0x5b8) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0x5b8));
  }
  return;
}


