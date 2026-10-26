// Function: FUN_004c2860 @ 004c2860
// Size (bytes): 100


int __thiscall FUN_004c2860(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  piVar1 = *(int **)(param_1 + 0x10);
  *(int **)(param_1 + 0x18) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = *piVar1;
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    puVar3 = *(undefined1 **)(iVar2 + 8);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    iVar4 = FUN_00588410(puVar3,param_2);
    if (iVar4 == 0) break;
    if (*(int *)(param_1 + 0x18) != 0) {
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(*(int *)(param_1 + 0x18) + 4);
    }
    if (*(int **)(param_1 + 0x18) == (int *)0x0) {
      return 0;
    }
    iVar2 = **(int **)(param_1 + 0x18);
  }
  return iVar2;
}


