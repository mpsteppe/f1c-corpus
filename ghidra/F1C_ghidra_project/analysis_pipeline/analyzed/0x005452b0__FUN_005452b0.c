// Function: FUN_005452b0 @ 005452b0
// Size (bytes): 52


void __thiscall FUN_005452b0(int param_1,int param_2)

{
  if (*(int *)(param_2 + 0x48) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x48) + 0x4c) = *(undefined4 *)(param_2 + 0x4c);
  }
  if (*(int *)(param_2 + 0x4c) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x4c) + 0x48) = *(undefined4 *)(param_2 + 0x48);
  }
  if (*(int *)(param_1 + 0x108) == param_2) {
    *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_2 + 0x4c);
  }
  return;
}


