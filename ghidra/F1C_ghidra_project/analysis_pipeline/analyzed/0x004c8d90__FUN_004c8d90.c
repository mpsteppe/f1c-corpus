// Function: FUN_004c8d90 @ 004c8d90
// Size (bytes): 46


void FUN_004c8d90(int param_1)

{
  if (DAT_008ac4c4 == (int *)0x0) {
    return;
  }
  if (param_1 == 1) {
                    /* WARNING: Could not recover jumptable at 0x004c8dab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_008ac4c4 + 0x3c))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004c8db8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_008ac4c4 + 0x3c))();
  return;
}


