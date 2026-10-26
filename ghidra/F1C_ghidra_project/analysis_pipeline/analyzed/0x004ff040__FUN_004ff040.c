// Function: FUN_004ff040 @ 004ff040
// Size (bytes): 151


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ff040(int param_1,float param_2,float param_3)

{
  *(float *)(param_1 + 0xfc) = _DAT_0059e43c - param_2;
  if (DAT_0059e440 <= *(float *)(param_1 + 0xfc)) {
    if (_DAT_0059e43c < *(float *)(param_1 + 0xfc)) {
      *(undefined4 *)(param_1 + 0xfc) = 0x3f800000;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xfc) = 0;
  }
  *(float *)(param_1 + 0x100) = _DAT_0059e43c - param_3;
  if (*(float *)(param_1 + 0x100) < *(float *)(param_1 + 0xfc)) {
    *(float *)(param_1 + 0x100) = *(float *)(param_1 + 0xfc);
    return;
  }
  if (_DAT_0059e43c < *(float *)(param_1 + 0x100)) {
    *(undefined4 *)(param_1 + 0x100) = 0x3f800000;
  }
  return;
}


