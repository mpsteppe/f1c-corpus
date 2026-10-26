// Function: FUN_00583d40 @ 00583d40
// Size (bytes): 66


undefined1 __fastcall FUN_00583d40(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  HANDLE hHandle;
  DWORD DVar3;
  undefined1 *puVar4;
  
  puVar1 = (undefined1 *)(param_1 + 0xc + param_2 * 0x28);
  hHandle = *(HANDLE *)(param_1 + 0x10 + param_2 * 0x28);
  if ((hHandle == (HANDLE)0x0) ||
     ((DVar3 = WaitForSingleObject(hHandle,*(DWORD *)(puVar1 + 8)), puVar4 = puVar1, DVar3 != 0 &&
      (DVar3 != 0x80)))) {
    puVar4 = (undefined1 *)0x0;
  }
  uVar2 = *puVar4;
  if (*(HANDLE *)(puVar1 + 4) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(puVar1 + 4));
  }
  return uVar2;
}


