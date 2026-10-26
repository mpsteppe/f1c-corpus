// Function: FUN_004b2b60 @ 004b2b60
// Size (bytes): 23


void __thiscall FUN_004b2b60(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffc07fff | param_2 << 0xf;
  return;
}


