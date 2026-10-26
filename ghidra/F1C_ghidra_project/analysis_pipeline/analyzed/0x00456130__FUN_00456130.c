// Function: FUN_00456130 @ 00456130
// Size (bytes): 30


void __thiscall FUN_00456130(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x18) = *param_2;
    *(undefined4 *)(param_1 + 0x1c) = param_2[1];
    *(undefined4 *)(param_1 + 0x20) = param_2[2];
  }
  return;
}


