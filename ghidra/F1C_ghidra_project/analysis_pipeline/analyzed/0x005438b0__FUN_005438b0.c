// Function: FUN_005438b0 @ 005438b0
// Size (bytes): 99


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005438b0(int param_1,float param_2,float param_3)

{
  if ((float)_DAT_0059e430 <= param_2) {
    *(float *)(param_1 + 0x194) = param_2;
  }
  if (*(float *)(param_1 + 0x194) <= param_3) {
    *(float *)(param_1 + 0x198) = param_3;
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 0x10000;
    return;
  }
  *(undefined4 *)(param_1 + 0x198) = *(undefined4 *)(param_1 + 0x194);
  *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 0x10000;
  return;
}


