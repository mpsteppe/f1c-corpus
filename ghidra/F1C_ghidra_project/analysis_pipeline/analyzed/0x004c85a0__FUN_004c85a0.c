// Function: FUN_004c85a0 @ 004c85a0
// Size (bytes): 31


void FUN_004c85a0(void)

{
  int iVar1;
  
  if (DAT_008ac4c8 != (int *)0x0) {
    iVar1 = (**(code **)(*DAT_008ac4c8 + 8))();
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x004c85bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*DAT_008ac4c8 + 0x10))();
      return;
    }
  }
  return;
}


