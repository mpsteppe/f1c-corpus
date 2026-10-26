
int __fastcall FUN_005805c0(int param_1)

{
  int *piVar1;
  char cVar2;
  DWORD DVar3;
  int iVar4;
  int iVar5;
  int iStack_8;
  
  iVar4 = param_1 + 0xb74;
  if ((*(HANDLE *)(param_1 + 0xb94) == (HANDLE)0x0) ||
     ((DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xb94),*(DWORD *)(param_1 + 0xb98)),
      DVar3 != 0 && (DVar3 != 0x80)))) {
    iVar4 = 0;
  }
  iStack_8 = 0;
  FUN_004ba780();
  piVar1 = *(int **)(iVar4 + 0x18);
  if (piVar1 != (int *)0x0) {
    iStack_8 = *piVar1;
    *(undefined1 *)(piVar1 + 2) = 0;
    cVar2 = FUN_00583430(iStack_8,1);
    if (cVar2 == '\0') {
      iStack_8 = 0;
    }
  }
  if (iStack_8 == 0) {
    FUN_00582780();
    iStack_8 = FUN_00582b10();
  }
  if (*(HANDLE *)(param_1 + 0xb94) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xb94));
  }
  iVar4 = param_1 + 0xb48;
  if ((*(HANDLE *)(param_1 + 0xb68) == (HANDLE)0x0) ||
     ((DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xb68),*(DWORD *)(param_1 + 0xb6c)),
      DVar3 != 0 && (DVar3 != 0x80)))) {
    iVar4 = 0;
  }
  piVar1 = *(int **)(iVar4 + 0x10);
  iVar5 = 0;
  *(int **)(iVar4 + 0x18) = piVar1;
  if (piVar1 != (int *)0x0) {
    iVar5 = *piVar1;
    *(undefined1 *)(piVar1 + 2) = 0;
    cVar2 = FUN_005832e0(iVar5,1);
    if (cVar2 == '\0') {
      iVar5 = 0;
    }
  }
  if (iVar5 == 0) {
    FUN_005823c0();
    FUN_004ba780();
    piVar1 = *(int **)(iVar4 + 0x18);
    if (piVar1 != (int *)0x0) {
      iVar5 = *piVar1;
      *(undefined1 *)(piVar1 + 2) = 0;
      cVar2 = FUN_005832e0(iVar5,1);
      if (cVar2 == '\0') {
        iVar5 = 0;
      }
    }
  }
  *(int *)(iStack_8 + 0x48) = iVar5;
  if (*(HANDLE *)(param_1 + 0xb68) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xb68));
  }
  return iStack_8;
}

