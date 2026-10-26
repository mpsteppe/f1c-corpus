// Function: FUN_004189b0 @ 004189b0
// Size (bytes): 64


undefined4 __thiscall FUN_004189b0(int param_1,int param_2)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xaec) == param_2) && (*(int **)(param_1 + 0xaf4) != (int *)0x0)) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0xaf4) + 8))();
    if (iVar1 != 0) {
      (**(code **)(**(int **)(param_1 + 0xaf4) + 0xc))();
      return 1;
    }
  }
  return 0;
}


