// Function: FUN_0054fa50 @ 0054fa50
// Size (bytes): 49


void __fastcall FUN_0054fa50(int param_1)

{
  if (*(int *)(param_1 + 0x1e0) != 0) {
    FUN_00587bcf(*(undefined4 *)(*(int *)(param_1 + 0x1e0) + 8));
    FUN_00587bcf(*(undefined4 *)(param_1 + 0x1e0));
    *(undefined4 *)(param_1 + 0x1e0) = 0;
  }
  return;
}


