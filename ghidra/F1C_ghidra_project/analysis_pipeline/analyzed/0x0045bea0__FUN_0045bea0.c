// Function: FUN_0045bea0 @ 0045bea0
// Size (bytes): 109


void __fastcall FUN_0045bea0(int param_1)

{
  if (*(int *)(param_1 + 0x3c) != 0) {
    AVIStreamRelease(*(int *)(param_1 + 0x3c));
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    AVIStreamRelease(*(int *)(param_1 + 0x40));
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if (*(int *)(param_1 + 0x38) != 0) {
    AVIFileRelease(*(int *)(param_1 + 0x38));
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_0053cb90(*(int *)(param_1 + 0x44));
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x50));
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  FUN_0045bf10();
  AVIFileExit();
  return;
}


