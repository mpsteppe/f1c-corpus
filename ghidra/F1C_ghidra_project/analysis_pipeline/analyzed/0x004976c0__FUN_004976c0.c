// Function: FUN_004976c0 @ 004976c0
// Size (bytes): 131


int __thiscall FUN_004976c0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = *(int **)(param_1 + 4);
  iVar5 = 0;
  *(int **)(param_1 + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *piVar1;
  }
  if (param_2 == 0) {
    return 0;
  }
  if (iVar2 != 0) {
    while( true ) {
      for (iVar2 = FUN_00498e30(); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x48)) {
        puVar3 = *(undefined1 **)(iVar2 + 0x34);
        if (puVar3 == (undefined1 *)0x0) {
          puVar3 = &DAT_005ea438;
        }
        iVar4 = FUN_00588410(puVar3,param_2);
        if (iVar4 == 0) {
          iVar5 = iVar2;
        }
      }
      if (*(int *)(param_1 + 0xc) == 0) break;
      piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 4);
      *(int **)(param_1 + 0xc) = piVar1;
      if (piVar1 == (int *)0x0) {
        return iVar5;
      }
      if (*piVar1 == 0) {
        return iVar5;
      }
    }
  }
  return iVar5;
}


