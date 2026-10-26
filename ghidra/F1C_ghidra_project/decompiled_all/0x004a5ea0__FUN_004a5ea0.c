// Function: FUN_004a5ea0 @ 004a5ea0
// Strings:  [Entering Pits Under Red, Entering Pits Under Red]


void __fastcall FUN_004a5ea0(undefined4 *param_1)

{
  if (*(char *)(param_1 + 0x60) == '\0') {
    FUN_004a5c80(2);
    *(undefined1 *)(param_1 + 0x60) = 1;
    FUN_0041a2b0(*param_1);
    FUN_004bc240();
    if ((DAT_008acfc8 == 2) && (DAT_007cef84 != 0)) {
      if (DAT_007c56a4 == 7) {
        FUN_004bc0e0(s_Entering_Pits_Under_Red_005cd680);
        return;
      }
      FUN_004bba90(s_Entering_Pits_Under_Red_005cd680,0x447a0000);
    }
  }
  return;
}


