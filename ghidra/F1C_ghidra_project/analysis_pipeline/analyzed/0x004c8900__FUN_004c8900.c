// Function: FUN_004c8900 @ 004c8900
// Size (bytes): 26


void FUN_004c8900(void)

{
  if (DAT_008ac4c8 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004c8914. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_008ac4c8 + 0x1c))();
    return;
  }
  return;
}


