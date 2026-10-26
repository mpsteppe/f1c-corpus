// Function: FUN_00585d70 @ 00585d70
// Size (bytes): 106


undefined4 __thiscall FUN_00585d70(int param_1,int param_2)

{
  char cVar1;
  DWORD DVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x618),5);
  if ((DVar2 != 0x102) && (DVar2 != 0xffffffff)) {
    uVar4 = *(undefined4 *)(param_1 + 0x5c4);
    *(undefined4 *)(param_1 + 0x5c4) = 0;
    if (param_2 != 0) {
      pcVar3 = (char *)(param_1 + 0x5c8);
      param_2 = param_2 - (int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[param_2] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
    }
    *(undefined1 *)(param_1 + 0x5c8) = 0;
    if (*(HANDLE *)(param_1 + 0x618) != (HANDLE)0x0) {
      ReleaseMutex(*(HANDLE *)(param_1 + 0x618));
    }
  }
  return uVar4;
}


