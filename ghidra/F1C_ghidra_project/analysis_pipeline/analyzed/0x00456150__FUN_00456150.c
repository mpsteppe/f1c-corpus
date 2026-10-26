// Function: FUN_00456150 @ 00456150
// Size (bytes): 30


void __thiscall FUN_00456150(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x24) = *param_2;
    *(undefined4 *)(param_1 + 0x28) = param_2[1];
    *(undefined4 *)(param_1 + 0x2c) = param_2[2];
  }
  return;
}


