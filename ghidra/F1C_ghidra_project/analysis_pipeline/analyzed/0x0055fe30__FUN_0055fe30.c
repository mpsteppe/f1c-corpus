// Function: FUN_0055fe30 @ 0055fe30
// Size (bytes): 59


undefined4 __fastcall FUN_0055fe30(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00587d02(*(int *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  if (*(int *)(param_1 + 0x128) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x128));
    *(undefined4 *)(param_1 + 0x128) = 0;
  }
  return 0;
}


