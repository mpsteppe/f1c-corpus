// Function: FUN_00545090 @ 00545090
// Size (bytes): 73


void __thiscall FUN_00545090(int param_1,int param_2)

{
  if (*(int *)(param_2 + 0x1b4) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x1b4) + 0x1b8) = *(undefined4 *)(param_2 + 0x1b8);
  }
  if (*(int *)(param_2 + 0x1b8) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x1b8) + 0x1b4) = *(undefined4 *)(param_2 + 0x1b4);
  }
  if (*(int *)(param_1 + 0xf8) == param_2) {
    *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(param_2 + 0x1b8);
  }
  return;
}


