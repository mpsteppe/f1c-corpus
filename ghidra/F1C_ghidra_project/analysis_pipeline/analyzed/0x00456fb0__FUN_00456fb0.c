// Function: FUN_00456fb0 @ 00456fb0
// Size (bytes): 80


void __thiscall FUN_00456fb0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xac) = param_2;
  if (*(float *)(param_1 + 0xac) < *(float *)(param_1 + 0x80)) {
    *(float *)(param_1 + 0xac) = *(float *)(param_1 + 0x80);
    return;
  }
  if (*(float *)(param_1 + 0x84) < *(float *)(param_1 + 0xac)) {
    *(float *)(param_1 + 0xac) = *(float *)(param_1 + 0x84);
  }
  return;
}


