// Function: FUN_00499b50 @ 00499b50
// Size (bytes): 43


void __fastcall FUN_00499b50(int param_1)

{
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_005539f0(*(int *)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_005502c0();
    return;
  }
  return;
}


