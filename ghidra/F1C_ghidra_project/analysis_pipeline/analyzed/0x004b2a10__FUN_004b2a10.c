// Function: FUN_004b2a10 @ 004b2a10
// Size (bytes): 29


void __thiscall FUN_004b2a10(int param_1,char param_2)

{
  *(uint *)(param_1 + 0x2c) =
       *(uint *)(param_1 + 0x2c) ^
       ((uint)(byte)(param_2 + 1) << 8 ^ *(uint *)(param_1 + 0x2c)) & 0xf00;
  return;
}


