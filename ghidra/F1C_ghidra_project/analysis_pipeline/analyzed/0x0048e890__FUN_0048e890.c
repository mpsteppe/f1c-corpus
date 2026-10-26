// Function: FUN_0048e890 @ 0048e890
// Size (bytes): 49


undefined4 __fastcall FUN_0048e890(int param_1)

{
  if (*(int *)(param_1 + 0xe8) != 0) {
    FUN_005461b0(*(int *)(param_1 + 0xe8));
    *(undefined4 *)(param_1 + 0xe8) = 0;
  }
  *(undefined4 *)(param_1 + 0xec) = 0;
  return 1;
}


