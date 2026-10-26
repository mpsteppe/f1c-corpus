// Function: FUN_00497650 @ 00497650
// Size (bytes): 102


int __thiscall FUN_00497650(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  piVar1 = *(int **)(param_1 + 4);
  *(int **)(param_1 + 0xc) = piVar1;
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    while (iVar2 != 0) {
      puVar3 = *(undefined1 **)(iVar2 + 0x34);
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      iVar4 = FUN_00588410(puVar3,param_2);
      if (iVar4 == 0) {
        return iVar2;
      }
      if (*(int *)(param_1 + 0xc) != 0) {
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 4);
      }
      if (*(int **)(param_1 + 0xc) == (int *)0x0) {
        return 0;
      }
      iVar2 = **(int **)(param_1 + 0xc);
    }
  }
  return 0;
}


