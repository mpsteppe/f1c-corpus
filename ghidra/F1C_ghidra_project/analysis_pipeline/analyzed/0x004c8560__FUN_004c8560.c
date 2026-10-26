// Function: FUN_004c8560 @ 004c8560
// Size (bytes): 30


void FUN_004c8560(void)

{
  if ((DAT_008ac4c4 != (int *)0x0) && (DAT_008ac4cc == 0)) {
    DAT_008ac4cc = (**(code **)(*DAT_008ac4c4 + 0x60))();
  }
  return;
}


