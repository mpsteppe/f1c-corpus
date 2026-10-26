// Function: FUN_00408450 @ 00408450
// Size (bytes): 55


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00408450(int param_1,float param_2)

{
  *(undefined4 *)(param_1 + 4) = 0;
  if (param_2 < DAT_0059e440 != (param_2 == DAT_0059e440)) {
    *(undefined4 *)(param_1 + 8) = 0x3f800000;
    FUN_004082b0();
    return;
  }
  *(float *)(param_1 + 8) = _DAT_0059e43c / param_2;
  return;
}


