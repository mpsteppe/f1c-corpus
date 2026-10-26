// Function: FUN_00456110 @ 00456110
// Size (bytes): 30


void __thiscall FUN_00456110(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0xc) = *param_2;
    *(undefined4 *)(param_1 + 0x10) = param_2[1];
    *(undefined4 *)(param_1 + 0x14) = param_2[2];
  }
  return;
}


