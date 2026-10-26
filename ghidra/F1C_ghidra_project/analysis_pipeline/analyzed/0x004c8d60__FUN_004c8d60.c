// Function: FUN_004c8d60 @ 004c8d60
// Size (bytes): 16


void FUN_004c8d60(void)

{
  if (DAT_008ac4c4 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004c8d6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_008ac4c4 + 0x14))();
    return;
  }
  return;
}


