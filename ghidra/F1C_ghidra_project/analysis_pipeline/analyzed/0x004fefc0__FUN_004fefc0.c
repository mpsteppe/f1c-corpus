// Function: FUN_004fefc0 @ 004fefc0
// Size (bytes): 115


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004fefc0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xa8) = param_2;
  if (_DAT_0059e444 <= *(float *)(param_1 + 0xa8)) {
    if (_DAT_005ad2c0 < *(float *)(param_1 + 0xa8)) {
      *(undefined4 *)(param_1 + 0xa8) = 0x3f7d70a4;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xa8) = 0x3c23d70a;
  }
  *(float *)(param_1 + 0xac) = _DAT_0059e43c / *(float *)(param_1 + 0xa8);
  *(float *)(param_1 + 0xb0) = _DAT_0059e43c / (_DAT_0059e43c - *(float *)(param_1 + 0xa8));
  return;
}


