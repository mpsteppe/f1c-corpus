// Function: FUN_004c9820 @ 004c9820
// Size (bytes): 30


undefined4 __fastcall FUN_004c9820(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x20 + *(int *)(param_1 + 0x1c) * 4);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    if (iVar2 != 2) {
      return 1;
    }
  }
  return 0;
}


