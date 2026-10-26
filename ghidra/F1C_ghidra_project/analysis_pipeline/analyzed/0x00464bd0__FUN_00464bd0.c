// Function: FUN_00464bd0 @ 00464bd0
// Size (bytes): 60


void __thiscall FUN_00464bd0(int param_1,float param_2)

{
  *(float *)(param_1 + 0x68) = *(float *)(param_1 + 0x68) - param_2;
  if (*(float *)(param_1 + 0x68) < DAT_0059e440) {
    *(undefined4 *)(param_1 + 0x68) = 0;
    return;
  }
  if (param_2 < *(float *)(param_1 + 0x68)) {
    *(float *)(param_1 + 0x68) = param_2;
  }
  return;
}


