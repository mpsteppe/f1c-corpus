// Function: FUN_004615f0 @ 004615f0
// Size (bytes): 24


bool __thiscall FUN_004615f0(int param_1,byte param_2)

{
  return (*(byte *)(param_1 + 0x6e) & '\x01' << (param_2 & 0x1f)) != 0;
}


