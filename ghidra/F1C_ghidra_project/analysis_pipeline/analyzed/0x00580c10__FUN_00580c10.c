// Function: FUN_00580c10 @ 00580c10
// Size (bytes): 464


undefined4 __thiscall FUN_00580c10(int param_1,int *param_2,int param_3,char param_4)

{
  int *piVar1;
  DWORD DVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  undefined2 local_1c;
  u_short local_1a;
  u_long local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  piVar1 = param_2;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059cacb;
  local_c = ExceptionList;
  local_1c = 2;
  ExceptionList = &local_c;
  local_18 = htonl(0);
  local_1a = htons(0);
  FUN_0057b9f0(&local_1c);
  piVar5 = (int *)(param_1 + 0xb38);
  if ((*(HANDLE *)(param_1 + 0xb3c) == (HANDLE)0x0) ||
     ((DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xb3c),*(DWORD *)(param_1 + 0xb40)),
      DVar2 != 0 && (DVar2 != 0x80)))) {
    piVar5 = (int *)0x0;
  }
  *param_2 = *piVar5;
  *piVar5 = *piVar5 + 1;
  if (*(HANDLE *)(param_1 + 0xb3c) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xb3c));
  }
  param_2 = (int *)(param_1 + 0xac8);
  if ((*(HANDLE *)(param_1 + 0xad8) == (HANDLE)0x0) ||
     ((DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xad8),*(DWORD *)(param_1 + 0xadc)),
      DVar2 != 0 && (DVar2 != 0x80)))) {
    param_2 = (int *)0x0;
  }
  iVar4 = param_2[3];
  pvVar3 = operator_new(0x20);
  local_4 = 0;
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_0057b780(*piVar1,iVar4,param_3);
  }
  local_4 = 0xffffffff;
  if ((0 < param_3) && (param_3 < 3)) {
    if (param_4 == '\0') {
      FUN_0057dd40(&local_1c,iVar4);
    }
    else {
      if (*(HANDLE *)(param_1 + 0x640) != (HANDLE)0x0) {
        WaitForSingleObject(*(HANDLE *)(param_1 + 0x640),*(DWORD *)(param_1 + 0x644));
      }
      FUN_00587370(iVar4);
      if (*(HANDLE *)(param_1 + 0x640) != (HANDLE)0x0) {
        ReleaseMutex(*(HANDLE *)(param_1 + 0x640));
      }
    }
  }
  if (iVar4 != 0) {
    piVar5 = operator_new(0xc);
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      *piVar5 = iVar4;
      piVar5[1] = 0;
      *(undefined1 *)(piVar5 + 2) = 1;
    }
    if (*param_2 == 0) {
      *param_2 = (int)piVar5;
      param_2[2] = (int)piVar5;
    }
    else {
      *(int **)(param_2[1] + 4) = piVar5;
    }
    param_2[1] = (int)piVar5;
    param_2[3] = param_2[3] + 1;
  }
  if (*(HANDLE *)(param_1 + 0xad8) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xad8));
  }
  ExceptionList = local_c;
  return 1;
}


