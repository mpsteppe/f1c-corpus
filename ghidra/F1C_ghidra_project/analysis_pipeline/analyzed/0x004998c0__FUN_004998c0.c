// Function: FUN_004998c0 @ 004998c0
// Size (bytes): 22


undefined4 __fastcall FUN_004998c0(int param_1)

{
  if (*(int *)(param_1 + 0x14) != 0) {
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x48);
  }
  return CONCAT31((int3)((uint)*(int *)(param_1 + 0x14) >> 8),*(int *)(param_1 + 0x14) != 0);
}


