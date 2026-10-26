// Function: FUN_004bb8e0 @ 004bb8e0
// Size (bytes): 111


void __fastcall FUN_004bb8e0(int *param_1)

{
  if (((-1 < DAT_007c56a4) && (DAT_007c56a4 < 7)) &&
     ((*(int *)(*param_1 + 13000) == 1 || (*(int *)(*param_1 + 13000) == 0)))) {
    FUN_004e9ca0();
    if (param_1[0x18] == 2) {
      param_1[0x18] = 1;
    }
    param_1[6] = -0x40800000;
    param_1[7] = -0x40800000;
    param_1[8] = -0x40800000;
  }
  param_1[0x2c] = 0;
  *(undefined1 *)(param_1 + 0x2a) = 0;
  param_1[0x2b] = 0;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  param_1[0x34] = 0;
  *(undefined1 *)(param_1 + 0x35) = 0;
  return;
}


