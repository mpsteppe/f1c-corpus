// Function: FUN_004c8dc0 @ 004c8dc0
// Size (bytes): 26


void FUN_004c8dc0(void)

{
  if (DAT_008ac4c4 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004c8dd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_008ac4c4 + 0x50))();
    return;
  }
  return;
}


