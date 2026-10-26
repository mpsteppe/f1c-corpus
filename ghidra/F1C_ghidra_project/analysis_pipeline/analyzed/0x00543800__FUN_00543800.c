// Function: FUN_00543800 @ 00543800
// Size (bytes): 99


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00543800(int param_1,int param_2,int param_3,int param_4)

{
  *(float *)(param_1 + 0x17c) = (float)param_2 * _DAT_0059e460;
  *(float *)(param_1 + 0x180) = (float)param_3 * _DAT_0059e460;
  *(float *)(param_1 + 0x184) = (float)param_4 * _DAT_0059e460;
  FUN_00541670((param_2 * 0x100 + param_3) * 0x100 + param_4);
  *(uint *)(DAT_008b8f28 + 0xec) = *(uint *)(DAT_008b8f28 + 0xec) | 0x800;
  return;
}


