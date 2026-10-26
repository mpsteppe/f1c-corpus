// Function: FUN_004b2ae0 @ 004b2ae0
// Size (bytes): 25


void __thiscall FUN_004b2ae0(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x30) =
       *(uint *)(param_1 + 0x30) ^ (param_2 << 0x1c ^ *(uint *)(param_1 + 0x30)) & 0x70000000;
  return;
}


