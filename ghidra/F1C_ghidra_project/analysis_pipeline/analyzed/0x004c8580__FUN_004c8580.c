// Function: FUN_004c8580 @ 004c8580
// Size (bytes): 25


undefined4 FUN_004c8580(void)

{
  int iVar1;
  
  if (DAT_008ac4c8 != (int *)0x0) {
    iVar1 = (**(code **)(*DAT_008ac4c8 + 8))();
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


