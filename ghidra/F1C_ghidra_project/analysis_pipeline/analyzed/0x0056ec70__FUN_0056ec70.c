// Function: FUN_0056ec70 @ 0056ec70
// Size (bytes): 123


void __thiscall FUN_0056ec70(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int **)(param_1 + 0x30) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0056ece8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x30) + 0x18))();
    return;
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x20)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x28) + param_2 * 4);
      *(undefined4 *)(iVar1 + iVar2 * 8) = 0;
      *(undefined4 *)(iVar1 + 4 + iVar2 * 8) = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x20));
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x20)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x28) + iVar2 * 4);
      *(undefined4 *)(iVar1 + param_2 * 8) = 0;
      *(undefined4 *)(iVar1 + 4 + param_2 * 8) = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x20));
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x28) + param_2 * 4);
  *(undefined4 *)(iVar2 + param_2 * 8) = 0;
  *(undefined4 *)(iVar2 + 4 + param_2 * 8) = 0x3ff00000;
  iVar2 = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(iVar2 + param_2 * 8) = 0;
  *(undefined4 *)(iVar2 + 4 + param_2 * 8) = 0;
  return;
}


