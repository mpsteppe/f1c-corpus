// Function: FUN_00541ca0 @ 00541ca0
// Size (bytes): 38


void __thiscall FUN_00541ca0(int param_1,int param_2)

{
  if (param_2 != 0) {
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 8;
    return;
  }
  *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) & 0xfffffff7;
  return;
}


