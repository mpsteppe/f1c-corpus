// Function: FUN_004fde00 @ 004fde00
// Size (bytes): 164


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004fde00(int param_1,float param_2)

{
  if (param_2 < _DAT_0059e4e8 != (param_2 == _DAT_0059e4e8)) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  if (param_2 < _DAT_0059e8f8 != (param_2 == _DAT_0059e8f8)) {
    param_2 = param_2 - _DAT_0059e4e8;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(float *)(param_1 + 0x20) = param_2 * _DAT_005ad308;
    return;
  }
  if (param_2 < _DAT_0059e6e8 != (param_2 == _DAT_0059e6e8)) {
    *(undefined4 *)(param_1 + 0x20) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  if (param_2 < _DAT_0059e43c != (param_2 == _DAT_0059e43c)) {
    *(undefined4 *)(param_1 + 0x20) = 0x3f800000;
    *(float *)(param_1 + 0x24) = (param_2 - _DAT_0059e6e8) * _DAT_005ad304;
    return;
  }
  *(undefined4 *)(param_1 + 0x20) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x24) = 0x3f800000;
  return;
}


