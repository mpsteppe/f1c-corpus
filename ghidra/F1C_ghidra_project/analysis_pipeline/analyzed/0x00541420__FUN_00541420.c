// Function: FUN_00541420 @ 00541420
// Size (bytes): 70


void __fastcall FUN_00541420(int param_1)

{
  if (*(int *)(param_1 + 0x114c) != 0) {
    FUN_00540eb0(*(int *)(param_1 + 0x114c));
    FUN_00540eb0(*(int *)(param_1 + 0x114c) + 0x24);
    if (*(int *)(param_1 + 0x114c) != 0) {
      FUN_00587bcf(*(int *)(param_1 + 0x114c) + -4);
    }
    *(undefined4 *)(param_1 + 0x114c) = 0;
  }
  return;
}


