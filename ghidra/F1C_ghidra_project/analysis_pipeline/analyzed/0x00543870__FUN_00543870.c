// Function: FUN_00543870 @ 00543870
// Size (bytes): 56


void __thiscall FUN_00543870(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  *(undefined2 *)(param_1 + 0x18c) = param_2;
  *(undefined2 *)(param_1 + 0x188) = param_4;
  *(undefined2 *)(param_1 + 0x18a) = param_3;
  *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 0x10000;
  return;
}


