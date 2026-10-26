// Function: FUN_0054ac30 @ 0054ac30
// Size (bytes): 63


undefined4 __thiscall FUN_0054ac30(int param_1,int param_2)

{
  if (*(int *)(param_2 + 0x140) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x140) + 0x10) = *(undefined4 *)(param_2 + 0x10);
  }
  if (*(int *)(param_2 + 0x10) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x10) + 0x140) = *(undefined4 *)(param_2 + 0x140);
  }
  if (*(int *)(param_1 + 0x204) == param_2) {
    *(undefined4 *)(param_1 + 0x204) = *(undefined4 *)(param_2 + 0x10);
  }
  return 0;
}


