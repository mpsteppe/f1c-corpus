// Function: FUN_0053c630 @ 0053c630
// Size (bytes): 70


void FUN_0053c630(int param_1)

{
  if (*(int *)(param_1 + 0x1e4) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x1e8) = *(undefined4 *)(param_1 + 0x1e8);
  }
  if (*(int *)(param_1 + 0x1e8) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x1e8) + 0x1e4) = *(undefined4 *)(param_1 + 0x1e4);
  }
  if (DAT_008b8f28 == param_1) {
    DAT_008b8f28 = *(int *)(param_1 + 0x1e8);
  }
  return;
}


