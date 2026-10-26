// Function: FUN_00464600 @ 00464600
// Size (bytes): 102


void __fastcall FUN_00464600(int *param_1)

{
  if (DAT_007ce260 == '\0') {
    FUN_004b16b0();
    if (*(int *)(*param_1 + 0x3fc4) != 0) {
      FUN_00463140();
      FUN_0045d500();
    }
    FUN_0057a910();
    if ((*(char *)(*param_1 + 0xc5) != '\0') || (*(char *)(*param_1 + 0xc6) != '\0')) {
      FUN_004a0de0();
      return;
    }
  }
  return;
}


