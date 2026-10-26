// Function: FUN_00409440 @ 00409440
// Size (bytes): 95


void __thiscall FUN_00409440(int param_1,uint param_2)

{
  if ((DAT_007cfe88 == '\0') && (param_2 == 3)) {
    if ((*(char *)(DAT_007c54e0 + 0x344c) != '\0') && (DAT_008ab6e4 != 2)) {
      param_2 = 2;
    }
  }
  else if (8 < param_2) {
    FUN_00408740(*(undefined4 *)(param_1 + 0x34));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00409487. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_004096ac + param_2 * 4))();
  return;
}


