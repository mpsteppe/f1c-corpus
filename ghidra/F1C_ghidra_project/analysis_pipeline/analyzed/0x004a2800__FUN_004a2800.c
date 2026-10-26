// Function: FUN_004a2800 @ 004a2800
// Size (bytes): 56


void __thiscall FUN_004a2800(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  *(undefined4 *)(param_1 + 0x4c) = *param_2;
  *(undefined4 *)(param_1 + 0x50) = param_2[1];
  *(undefined4 *)(param_1 + 0x54) = param_2[2];
  *(undefined4 *)(param_1 + 0x58) = *param_3;
  *(undefined4 *)(param_1 + 0x5c) = param_3[1];
  *(undefined4 *)(param_1 + 0x60) = param_3[2];
  FUN_004a27d0();
  return;
}


