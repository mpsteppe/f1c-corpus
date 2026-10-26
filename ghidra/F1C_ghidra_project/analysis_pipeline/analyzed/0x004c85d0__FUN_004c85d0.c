// Function: FUN_004c85d0 @ 004c85d0
// Size (bytes): 85


void __fastcall FUN_004c85d0(int param_1)

{
  if (DAT_008ac4c8 == (int *)0x0) {
    if (DAT_008ac4c4 == (int *)0x0) {
      return;
    }
    DAT_008ac4c8 = (int *)(**(code **)(*DAT_008ac4c4 + 0x60))();
    (**(code **)(*DAT_008ac4c8 + 0x1c))(DAT_007cf380);
    if (DAT_008ac4c8 == (int *)0x0) {
      return;
    }
  }
  *(undefined1 *)(param_1 + 0x10) = 1;
  *(undefined4 *)(param_1 + 0x14) = 0;
  (**(code **)(*DAT_008ac4c8 + 0x1c))(DAT_007cf380);
  return;
}


