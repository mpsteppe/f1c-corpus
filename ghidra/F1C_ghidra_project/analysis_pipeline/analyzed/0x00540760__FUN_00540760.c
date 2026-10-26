// Function: FUN_00540760 @ 00540760
// Size (bytes): 399


undefined4 __fastcall FUN_00540760(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1[0x4f7] != 0) {
    iVar1 = param_1[0x455];
    if (iVar1 != 0) {
      for (iVar3 = *(int *)(iVar1 + 0x1c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x1c)) {
        piVar2 = *(int **)(*(int *)(iVar3 + 0x18) + 0x20);
        if (piVar2 != (int *)0x0) {
          uVar4 = (**(code **)(*piVar2 + 8))(piVar2);
          *param_1 = uVar4;
        }
        if (*(int *)(iVar3 + 0x18) != 0) {
          FUN_00587bcf(*(int *)(iVar3 + 0x18));
        }
        iVar1 = iVar3;
      }
      piVar2 = *(int **)(iVar1 + 0x20);
      if (piVar2 != (int *)0x0) {
        uVar4 = (**(code **)(*piVar2 + 8))(piVar2);
        *param_1 = uVar4;
      }
      FUN_00587bcf(iVar1);
      param_1[0x455] = 0;
    }
    iVar1 = param_1[0x457];
    if (iVar1 != 0) {
      for (iVar3 = *(int *)(iVar1 + 0x1c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x1c)) {
        piVar2 = *(int **)(*(int *)(iVar3 + 0x18) + 0x20);
        if (piVar2 != (int *)0x0) {
          uVar4 = (**(code **)(*piVar2 + 8))(piVar2);
          *param_1 = uVar4;
        }
        if (*(int *)(iVar3 + 0x18) != 0) {
          FUN_00587bcf(*(int *)(iVar3 + 0x18));
        }
        iVar1 = iVar3;
      }
      piVar2 = *(int **)(iVar1 + 0x20);
      if (piVar2 != (int *)0x0) {
        uVar4 = (**(code **)(*piVar2 + 8))(piVar2);
        *param_1 = uVar4;
      }
      FUN_00587bcf(iVar1);
      param_1[0x457] = 0;
    }
    iVar1 = param_1[0x459];
    if (iVar1 != 0) {
      for (iVar3 = *(int *)(iVar1 + 0x14); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x14)) {
        piVar2 = *(int **)(*(int *)(iVar3 + 0x10) + 0x18);
        if (piVar2 != (int *)0x0) {
          uVar4 = (**(code **)(*piVar2 + 8))(piVar2);
          *param_1 = uVar4;
        }
        if (*(int *)(iVar3 + 0x10) != 0) {
          FUN_00587bcf(*(int *)(iVar3 + 0x10));
        }
        iVar1 = iVar3;
      }
      piVar2 = *(int **)(iVar1 + 0x18);
      if (piVar2 != (int *)0x0) {
        uVar4 = (**(code **)(*piVar2 + 8))(piVar2);
        *param_1 = uVar4;
      }
      FUN_00587bcf(iVar1);
      param_1[0x459] = 0;
    }
    iVar1 = param_1[0x45b];
    if (iVar1 != 0) {
      for (iVar3 = *(int *)(iVar1 + 0x14); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x14)) {
        piVar2 = *(int **)(*(int *)(iVar3 + 0x10) + 0x18);
        if (piVar2 != (int *)0x0) {
          uVar4 = (**(code **)(*piVar2 + 8))(piVar2);
          *param_1 = uVar4;
        }
        if (*(int *)(iVar3 + 0x10) != 0) {
          FUN_00587bcf(*(int *)(iVar3 + 0x10));
        }
        iVar1 = iVar3;
      }
      piVar2 = *(int **)(iVar1 + 0x18);
      if (piVar2 != (int *)0x0) {
        uVar4 = (**(code **)(*piVar2 + 8))(piVar2);
        *param_1 = uVar4;
      }
      FUN_00587bcf(iVar1);
      param_1[0x45b] = 0;
    }
  }
  return 0;
}


