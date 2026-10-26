// Function: FUN_005454d0 @ 005454d0
// Size (bytes): 283


void __thiscall FUN_005454d0(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_3 == 1) {
    piVar1 = (int *)(param_1 + 0x120);
    piVar3 = (int *)(param_1 + 0x11c);
  }
  else if (param_3 == 2) {
    piVar1 = (int *)(param_1 + 0x130);
    piVar3 = (int *)(param_1 + 300);
  }
  else {
    piVar1 = param_2;
    piVar3 = param_2;
    if (param_3 == 4) {
      piVar1 = (int *)(param_1 + 0x128);
      piVar3 = (int *)(param_1 + 0x124);
    }
  }
  iVar4 = *piVar1;
  if (iVar4 == 0) {
    *piVar1 = (int)param_2;
    param_2[0x1a] = 0;
  }
  else {
    for (iVar2 = *(int *)(iVar4 + 0x6c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x6c)) {
      iVar4 = iVar2;
    }
    *(int **)(iVar4 + 0x6c) = param_2;
    param_2[0x1a] = iVar4;
  }
  *piVar3 = *piVar3 + 1;
  param_2[0x1b] = 0;
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 300) + *(int *)(param_1 + 0x124);
  iVar4 = *(int *)(param_1 + 0x138);
  if (iVar4 != 0) {
    iVar2 = *(int *)(iVar4 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004b0170();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar4 + -4);
    *(undefined4 *)(param_1 + 0x138) = 0;
    *(undefined4 *)(param_1 + 0x134) = 0;
  }
  iVar4 = *(int *)(param_1 + 0x60);
  piVar1 = operator_new(iVar4 * 0x38 + 4);
  if (piVar1 != (int *)0x0) {
    *piVar1 = iVar4;
    if (-1 < iVar4 + -1) {
      do {
        FUN_0055d200();
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    *(int **)(param_1 + 0x138) = piVar1 + 1;
    return;
  }
  *(undefined4 *)(param_1 + 0x138) = 0;
  return;
}


