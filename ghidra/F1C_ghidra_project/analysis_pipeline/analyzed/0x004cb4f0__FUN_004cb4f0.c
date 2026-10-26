// Function: FUN_004cb4f0 @ 004cb4f0
// Size (bytes): 78


void __fastcall FUN_004cb4f0(int param_1)

{
  *(undefined4 *)(param_1 + 0x58) = 0;
  if (*(int *)(param_1 + 0x5c) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x5c) + -4);
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  *(undefined4 *)(param_1 + 100) = 0;
  if (*(int *)(param_1 + 0x68) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x68));
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_005592b0(*(int *)(param_1 + 0x54));
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  return;
}


