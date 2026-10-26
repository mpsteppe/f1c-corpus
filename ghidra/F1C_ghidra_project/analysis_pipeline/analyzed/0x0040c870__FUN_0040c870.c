// Function: FUN_0040c870 @ 0040c870
// Size (bytes): 24


int __fastcall FUN_0040c870(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 == 0) {
    if (*(int **)(param_1 + 8) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0040c882. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x18))();
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}


