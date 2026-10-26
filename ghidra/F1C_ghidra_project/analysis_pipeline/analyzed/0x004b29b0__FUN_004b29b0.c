// Function: FUN_004b29b0 @ 004b29b0
// Size (bytes): 50


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b29b0(int param_1,float param_2)

{
  *(uint *)(param_1 + 0x2c) =
       *(uint *)(param_1 + 0x2c) ^
       (((int)ROUND(param_2 * _DAT_005accd0) & 0xffU) << 0xc ^ *(uint *)(param_1 + 0x2c)) & 0x1f000;
  return;
}


