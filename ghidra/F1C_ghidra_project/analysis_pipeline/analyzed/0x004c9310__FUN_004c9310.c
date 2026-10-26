// Function: FUN_004c9310 @ 004c9310
// Size (bytes): 41


void __fastcall FUN_004c9310(int param_1)

{
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x20) + 8))();
  }
  if (*(int **)(param_1 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x24) + 8))();
  }
  if (*(int **)(param_1 + 0x28) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004c9335. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x28) + 8))();
    return;
  }
  return;
}


