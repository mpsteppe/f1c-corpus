// Function: FUN_004b1de0 @ 004b1de0
// Size (bytes): 59


void __thiscall FUN_004b1de0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  if (*(float *)(param_1 + 0x14) < *(float *)(param_1 + 0x1c)) {
    *(float *)(param_1 + 0x14) = *(float *)(param_1 + 0x1c);
    return;
  }
  if (*(float *)(param_1 + 0x20) < *(float *)(param_1 + 0x14)) {
    *(float *)(param_1 + 0x14) = *(float *)(param_1 + 0x20);
  }
  return;
}


