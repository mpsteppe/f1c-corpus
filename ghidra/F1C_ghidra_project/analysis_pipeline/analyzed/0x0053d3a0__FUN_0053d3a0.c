// Function: FUN_0053d3a0 @ 0053d3a0
// Size (bytes): 87


void FUN_0053d3a0(int param_1)

{
  if (*(int *)(param_1 + 0x86c) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x86c) + 0x870) = *(undefined4 *)(param_1 + 0x870);
  }
  if (*(int *)(param_1 + 0x870) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x870) + 0x86c) = *(undefined4 *)(param_1 + 0x86c);
  }
  if (DAT_008b8e20 == param_1) {
    DAT_008b8e20 = *(int *)(param_1 + 0x870);
  }
  *(undefined4 *)(param_1 + 0x86c) = 0;
  *(undefined4 *)(param_1 + 0x870) = 0;
  return;
}


