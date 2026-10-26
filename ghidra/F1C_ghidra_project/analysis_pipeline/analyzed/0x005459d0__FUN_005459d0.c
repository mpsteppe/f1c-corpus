// Function: FUN_005459d0 @ 005459d0
// Size (bytes): 52


void __thiscall FUN_005459d0(int param_1,int param_2)

{
  if (*(int *)(param_2 + 0x30) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x34) = *(undefined4 *)(param_2 + 0x34);
  }
  if (*(int *)(param_2 + 0x34) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x34) + 0x30) = *(undefined4 *)(param_2 + 0x30);
  }
  if (*(int *)(param_1 + 0x15c) == param_2) {
    *(undefined4 *)(param_1 + 0x15c) = *(undefined4 *)(param_2 + 0x34);
  }
  return;
}


