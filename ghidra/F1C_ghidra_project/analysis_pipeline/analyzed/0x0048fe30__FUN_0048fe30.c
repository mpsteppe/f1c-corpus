// Function: FUN_0048fe30 @ 0048fe30
// Size (bytes): 44


void __thiscall FUN_0048fe30(int param_1,undefined4 param_2)

{
  if (*(int **)(param_1 + 0x30) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x30) + 0x3c))(param_2);
                    /* WARNING: Could not recover jumptable at 0x0048fe55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x30) + 0x38))();
    return;
  }
  return;
}


