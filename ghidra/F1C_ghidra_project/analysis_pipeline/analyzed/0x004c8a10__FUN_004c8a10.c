// Function: FUN_004c8a10 @ 004c8a10
// Size (bytes): 16


void FUN_004c8a10(void)

{
  if (DAT_008ac4cc != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004c8a1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_008ac4cc + 0xc))();
    return;
  }
  return;
}


