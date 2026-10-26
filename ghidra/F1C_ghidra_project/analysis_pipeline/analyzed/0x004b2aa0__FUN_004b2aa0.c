// Function: FUN_004b2aa0 @ 004b2aa0
// Size (bytes): 39


void __thiscall FUN_004b2aa0(int param_1,byte param_2,uint param_3)

{
  *(uint *)(param_1 + 0x30) =
       ~(1 << (param_2 & 0x1f)) & *(uint *)(param_1 + 0x30) | (param_3 & 1) << (param_2 & 0x1f);
  return;
}


