// Function: FUN_004049d0 @ 004049d0
// Size (bytes): 114


void __fastcall FUN_004049d0(int param_1)

{
  if ((*(char *)(param_1 + 0x14) != '\0') && (*(int *)(param_1 + 0x20) == 1)) {
    DAT_007d2e44 = *(undefined4 *)(param_1 + 0x50);
    DAT_007d0410 = *(int *)(param_1 + 0x54);
    if (DAT_007d0410 < DAT_007d0418) {
      DAT_007d0410 = DAT_007d0418;
    }
    else if (DAT_007d041c < DAT_007d0410) {
      DAT_007d0410 = DAT_007d041c;
    }
    DAT_005ea53e = 0;
    FUN_00408450(0x3dcccccd);
    if (DAT_0059e440 < DAT_007cf380) {
      FUN_004c8630();
      return;
    }
  }
  return;
}


