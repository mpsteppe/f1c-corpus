// Function: FUN_004b2b10 @ 004b2b10
// Size (bytes): 47


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b2b10(int param_1,float param_2)

{
  *(uint *)(param_1 + 0x30) =
       *(uint *)(param_1 + 0x30) & 0xff3fffff | (int)ROUND(param_2 * _DAT_0059e478) << 0x16;
  return;
}


