// Function: FUN_004c8d80 @ 004c8d80
// Size (bytes): 16


void FUN_004c8d80(void)

{
  if (DAT_008ac4c4 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004c8d8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_008ac4c4 + 0x10))();
    return;
  }
  return;
}


