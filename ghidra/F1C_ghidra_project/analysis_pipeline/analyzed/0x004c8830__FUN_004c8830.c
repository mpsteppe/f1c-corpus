// Function: FUN_004c8830 @ 004c8830
// Size (bytes): 102


void __thiscall FUN_004c8830(int param_1,float param_2)

{
  if ((((*(char *)(param_1 + 0x10) != '\0') && (DAT_008ac4c8 != 0)) &&
      (*(float *)(DAT_008ac4c8 + 4) != DAT_007cf380)) && (DAT_007cf380 != DAT_0059e440)) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    if (DAT_0059e440 < param_2) {
      *(float *)(param_1 + 0x18) = DAT_007cf380 / param_2;
      return;
    }
    *(float *)(param_1 + 0x18) = DAT_007cf380;
  }
  return;
}


