// Function: FUN_004054a0 @ 004054a0
// Size (bytes): 55


void __fastcall FUN_004054a0(int param_1)

{
  FUN_00405630();
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00587d02(*(int *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x18));
  }
  FUN_00405440();
  return;
}


