// Function: FUN_00407e40 @ 00407e40
// Size (bytes): 169


int __thiscall FUN_00407e40(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 == -1) {
    if (param_2 == 0) {
      return 0;
    }
    piVar1 = *(int **)(param_1 + 0x38);
    *(int **)(param_1 + 0x40) = piVar1;
    if (piVar1 != (int *)0x0) {
      iVar4 = *piVar1;
      if (iVar4 == 0) {
        return 0;
      }
      while( true ) {
        puVar2 = *(undefined1 **)(iVar4 + 4);
        if (puVar2 == (undefined1 *)0x0) {
          puVar2 = &DAT_005ea438;
        }
        iVar3 = FUN_00588410(puVar2,param_2);
        if (iVar3 == 0) {
          return iVar4;
        }
        if (*(int *)(param_1 + 0x40) != 0) {
          *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 4);
        }
        if (*(int **)(param_1 + 0x40) == (int *)0x0) break;
        iVar4 = **(int **)(param_1 + 0x40);
        if (iVar4 == 0) {
          return 0;
        }
      }
    }
  }
  else {
    piVar1 = *(int **)(param_1 + 0x38);
    *(int **)(param_1 + 0x40) = piVar1;
    if (piVar1 != (int *)0x0) {
      iVar4 = *piVar1;
      if (iVar4 == 0) {
        return 0;
      }
      while( true ) {
        if (*(int *)(iVar4 + 0x10) == param_3) {
          return iVar4;
        }
        if (*(int *)(param_1 + 0x40) != 0) {
          *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 4);
        }
        if (*(int **)(param_1 + 0x40) == (int *)0x0) break;
        iVar4 = **(int **)(param_1 + 0x40);
        if (iVar4 == 0) {
          return 0;
        }
      }
    }
  }
  return 0;
}


