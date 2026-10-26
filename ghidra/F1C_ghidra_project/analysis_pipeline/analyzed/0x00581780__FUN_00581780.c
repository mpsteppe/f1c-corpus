// Function: FUN_00581780 @ 00581780
// Size (bytes): 26


undefined4 __fastcall FUN_00581780(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 8) + 4);
  }
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    return **(undefined4 **)(param_1 + 8);
  }
  return 0;
}


