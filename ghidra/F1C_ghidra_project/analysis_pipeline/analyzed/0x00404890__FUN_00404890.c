// Function: FUN_00404890 @ 00404890
// Size (bytes): 224


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00404890(int param_1)

{
  FUN_00404850();
  if (*(int *)(param_1 + 0x20) != 1) {
    *(undefined1 *)(param_1 + 0x14) = 1;
    *(undefined1 *)(param_1 + 0x15) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x50) = DAT_007d2e44;
  DAT_007d2e44 = 1;
  *(int *)(param_1 + 0x54) = DAT_007d0410;
  DAT_007d0410 = 2;
  if (DAT_007d0418 < 3) {
    if (DAT_007d041c < 2) {
      DAT_007d0410 = DAT_007d041c;
    }
  }
  else {
    DAT_007d0410 = DAT_007d0418;
  }
  FUN_004a0d90();
  FUN_0040d360(1,0xf);
  DAT_007d0798 = 0.05;
  if (_DAT_007d07a0 <= _DAT_0059e448) {
    if (DAT_007d07a4 < _DAT_0059e448) {
      DAT_007d0798 = DAT_007d07a4;
      *(undefined1 *)(param_1 + 0x14) = 1;
      *(undefined1 *)(param_1 + 0x15) = 0;
      return;
    }
  }
  else {
    DAT_007d0798 = _DAT_007d07a0;
  }
  *(undefined1 *)(param_1 + 0x14) = 1;
  *(undefined1 *)(param_1 + 0x15) = 0;
  return;
}


