// Function: FUN_0053fc30 @ 0053fc30
// Size (bytes): 268


undefined4 __thiscall FUN_0053fc30(int *param_1,int param_2,int param_3,int *param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *local_4;
  
  piVar2 = param_4;
  uVar1 = *(uint *)(param_2 + 0x18);
  local_4 = param_1;
  if ((((uVar1 & 4) == 0) || (piVar4 = *(int **)(param_2 + 0x10), piVar4 == (int *)0x0)) &&
     (((uVar1 & 8) == 0 || (piVar4 = *(int **)(param_2 + 0x14), piVar4 == (int *)0x0)))) {
    if (((uVar1 & 1) == 0) || (param_4 = *(int **)(param_2 + 8), param_4 == (int *)0x0)) {
      if ((uVar1 & 2) == 0) {
        return 0xffffffff;
      }
      param_4 = *(int **)(param_2 + 0xc);
      if (param_4 == (int *)0x0) {
        return 0xffffffff;
      }
    }
  }
  else {
    iVar3 = (**(code **)(*piVar4 + 0x3c))(piVar4,param_4,&param_4);
    *param_1 = iVar3;
    if (iVar3 != 0) {
      return 0xffffffff;
    }
  }
  uVar1 = *(uint *)(param_3 + 0x18);
  if ((((uVar1 & 4) == 0) || (piVar4 = *(int **)(param_3 + 0x10), piVar4 == (int *)0x0)) &&
     (((uVar1 & 8) == 0 || (piVar4 = *(int **)(param_3 + 0x14), piVar4 == (int *)0x0)))) {
    if (((uVar1 & 1) == 0) || (local_4 = *(int **)(param_3 + 8), local_4 == (int *)0x0)) {
      if ((uVar1 & 2) == 0) {
        return 0xffffffff;
      }
      local_4 = *(int **)(param_3 + 0xc);
      if (local_4 == (int *)0x0) {
        return 0xffffffff;
      }
    }
  }
  else {
    iVar3 = (**(code **)(*piVar4 + 0x3c))(piVar4,piVar2,&local_4);
    *param_1 = iVar3;
    if (iVar3 != 0) {
      return 0xffffffff;
    }
  }
  iVar3 = FUN_0050099c(local_4,0,0,param_4,0,0,1,0);
  *param_1 = iVar3;
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  if ((*(byte *)(param_2 + 0x18) & 0xc) != 0) {
    (**(code **)(*param_4 + 8))(param_4);
  }
  if ((*(byte *)(param_3 + 0x18) & 0xc) != 0) {
    (**(code **)(*local_4 + 8))(local_4);
  }
  return 0;
}


