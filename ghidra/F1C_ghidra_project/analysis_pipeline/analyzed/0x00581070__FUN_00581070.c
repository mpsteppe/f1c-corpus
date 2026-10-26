// Function: FUN_00581070 @ 00581070
// Size (bytes): 297


char __thiscall FUN_00581070(int param_1,int param_2)

{
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  int *piVar4;
  char local_29;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059cb08;
  local_c = ExceptionList;
  local_29 = '\0';
  ExceptionList = &local_c;
  FUN_00587030(0xffffffff,0xff,0);
  piVar4 = (int *)(param_1 + 0xac8);
  local_4 = 0;
  if ((*(HANDLE *)(param_1 + 0xad8) == (HANDLE)0x0) ||
     ((DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xad8),*(DWORD *)(param_1 + 0xadc)),
      DVar2 != 0 && (DVar2 != 0x80)))) {
    piVar4 = (int *)0x0;
  }
  piVar1 = (int *)*piVar4;
  piVar4[2] = (int)piVar1;
  if ((piVar1 != (int *)0x0) && (iVar3 = *piVar1, iVar3 != 0)) {
    while (*(int *)(iVar3 + 0x14) != param_2) {
      if (piVar4[2] == 0) goto LAB_0058111b;
      piVar1 = *(int **)(piVar4[2] + 4);
      piVar4[2] = (int)piVar1;
      if ((piVar1 == (int *)0x0) || (iVar3 = *piVar1, iVar3 == 0)) goto LAB_0058111b;
    }
    FUN_00587370(iVar3);
    local_29 = '\x01';
  }
LAB_0058111b:
  if (*(HANDLE *)(param_1 + 0xad8) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xad8));
  }
  if (local_29 != '\0') {
    if (*(HANDLE *)(param_1 + 0x640) != (HANDLE)0x0) {
      WaitForSingleObject(*(HANDLE *)(param_1 + 0x640),*(DWORD *)(param_1 + 0x644));
    }
    FUN_00587370(local_28);
    if (*(HANDLE *)(param_1 + 0x640) != (HANDLE)0x0) {
      ReleaseMutex(*(HANDLE *)(param_1 + 0x640));
    }
  }
  local_4 = 0xffffffff;
  FUN_005870d0();
  ExceptionList = local_c;
  return local_29;
}


