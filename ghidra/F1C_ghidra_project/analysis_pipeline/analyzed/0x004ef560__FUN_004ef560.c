// Function: FUN_004ef560 @ 004ef560
// Size (bytes): 57


void __thiscall
FUN_004ef560(int param_1,int param_2,undefined1 param_3,undefined1 param_4,undefined4 *param_5)

{
  param_1 = param_2 * 0x1c + param_1;
  *(undefined1 *)(param_1 + 0x3b78) = param_3;
  *(undefined1 *)(param_1 + 0x3b79) = param_4;
  *(undefined4 *)(param_1 + 0x3b88) = *param_5;
  *(undefined4 *)(param_1 + 0x3b8c) = param_5[1];
  *(undefined4 *)(param_1 + 0x3b90) = param_5[2];
  return;
}


