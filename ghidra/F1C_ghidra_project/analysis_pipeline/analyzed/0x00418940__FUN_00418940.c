// Function: FUN_00418940 @ 00418940
// Size (bytes): 44


undefined4 __fastcall FUN_00418940(int param_1)

{
  int iVar1;
  
  if ((*(int **)(param_1 + 0xaf4) != (int *)0x0) &&
     (iVar1 = (**(code **)(**(int **)(param_1 + 0xaf4) + 8))(), iVar1 != 0)) {
    return 1;
  }
  if (*(int *)(param_1 + 0x864) != -1) {
    return 1;
  }
  return 0;
}


