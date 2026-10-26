// Function: FUN_00584f30 @ 00584f30
// Size (bytes): 83


bool __thiscall FUN_00584f30(int param_1,undefined4 param_2)

{
  char cVar1;
  DWORD DVar2;
  bool bVar3;
  
  bVar3 = false;
  if ((*(HANDLE *)(param_1 + 0x5a8) != (HANDLE)0x0) &&
     ((DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x5a8),*(DWORD *)(param_1 + 0x5ac)),
      DVar2 == 0 || (DVar2 == 0x80)))) {
    cVar1 = FUN_00586000(param_2,0);
    bVar3 = cVar1 != '\0';
    if (*(HANDLE *)(param_1 + 0x5a8) != (HANDLE)0x0) {
      ReleaseMutex(*(HANDLE *)(param_1 + 0x5a8));
    }
  }
  return bVar3;
}


