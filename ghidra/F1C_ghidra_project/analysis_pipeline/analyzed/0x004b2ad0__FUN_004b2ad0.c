// Function: FUN_004b2ad0 @ 004b2ad0
// Size (bytes): 15


uint __thiscall FUN_004b2ad0(int param_1,byte param_2)

{
  return *(uint *)(param_1 + 0x30) >> (param_2 & 0x1f) & 1;
}


