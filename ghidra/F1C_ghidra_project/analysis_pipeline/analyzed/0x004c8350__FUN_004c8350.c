// Function: FUN_004c8350 @ 004c8350
// Size (bytes): 92


void FUN_004c8350(void)

{
  if (DAT_008ac4c8 != (undefined4 *)0x0) {
    (**(code **)*DAT_008ac4c8)(1);
    DAT_008ac4c8 = (undefined4 *)0x0;
  }
  if (DAT_008ac4cc != (undefined4 *)0x0) {
    (**(code **)*DAT_008ac4cc)(1);
    DAT_008ac4cc = (undefined4 *)0x0;
  }
  if (DAT_008ac4d0 != (undefined4 *)0x0) {
    (**(code **)*DAT_008ac4d0)(1);
    DAT_008ac4d0 = (undefined4 *)0x0;
  }
  if (DAT_008ac4c4 != (int *)0x0) {
    (**(code **)(*DAT_008ac4c4 + 0xc))();
  }
  DAT_008ac4c4 = (int *)0x0;
  return;
}


