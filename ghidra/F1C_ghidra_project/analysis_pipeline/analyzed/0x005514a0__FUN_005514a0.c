// Function: FUN_005514a0 @ 005514a0
// Size (bytes): 23


void __fastcall FUN_005514a0(int param_1)

{
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffe2fff | 0x2000;
  FUN_005563e0();
  return;
}


