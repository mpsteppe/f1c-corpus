// Function: FUN_0055d4f0 @ 0055d4f0
// Size (bytes): 56


void __thiscall FUN_0055d4f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x3c) = param_3;
  *(undefined4 *)(param_1 + 0x38) = param_2;
  *(undefined4 *)(param_1 + 0x40) = param_4;
  FUN_005416a0(param_1,*(undefined4 *)(param_1 + 4),6);
  *(uint *)(DAT_008b8f28 + 0xec) = *(uint *)(DAT_008b8f28 + 0xec) | 0x800;
  return;
}


