// Function: FUN_004a5f20 @ 004a5f20
// Strings:  [Exiting Pits Under Red, Exiting Pits Under Red]


void __fastcall FUN_004a5f20(int *param_1)

{
  if ((char)param_1[0x60] != '\0') {
    FUN_004a5c80(0);
    *(undefined1 *)(param_1 + 0x60) = 0;
    *(int *)(*param_1 + 0x406c) = *(int *)(*param_1 + 0x406c) + 1;
    FUN_0041a3a0(*param_1);
    if ((DAT_008acfd4 == 2) && (DAT_007cef84 != 0)) {
      if (DAT_007c56a4 == 7) {
        FUN_004bc0e0(s_Exiting_Pits_Under_Red_005cd698);
      }
      else {
        FUN_004bba90(s_Exiting_Pits_Under_Red_005cd698,0x447a0000);
      }
    }
  }
  if (param_1[5] != 0) {
    FUN_004a3fe0();
    return;
  }
  return;
}


