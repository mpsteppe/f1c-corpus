// Function: FUN_004c85c0 @ 004c85c0
// Size (bytes): 16


void FUN_004c85c0(void)

{
  if (DAT_008ac4c8 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004c85cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_008ac4c8 + 0x14))();
    return;
  }
  return;
}


