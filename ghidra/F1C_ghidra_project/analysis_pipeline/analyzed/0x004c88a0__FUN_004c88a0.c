// Function: FUN_004c88a0 @ 004c88a0
// Size (bytes): 86


void __thiscall FUN_004c88a0(int param_1,float param_2)

{
  if (((*(char *)(param_1 + 0x10) != '\0') && (DAT_008ac4c8 != 0)) &&
     (DAT_0059e440 <= *(float *)(DAT_008ac4c8 + 4))) {
    *(undefined4 *)(param_1 + 0x14) = 2;
    if (DAT_0059e440 < param_2) {
      *(float *)(param_1 + 0x18) = *(float *)(DAT_008ac4c8 + 4) / param_2;
      return;
    }
    *(undefined4 *)(param_1 + 0x18) = DAT_007cf380;
  }
  return;
}


