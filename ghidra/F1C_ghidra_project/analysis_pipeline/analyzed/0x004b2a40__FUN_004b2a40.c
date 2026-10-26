// Function: FUN_004b2a40 @ 004b2a40
// Size (bytes): 49


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b2a40(int param_1,float param_2)

{
  undefined1 local_4;
  
  local_4 = (char)(int)ROUND(param_2 * _DAT_005accd8);
  *(uint *)(param_1 + 0x2c) = (byte)(local_4 - 0x40) & 0x7f | *(uint *)(param_1 + 0x2c) & 0xffffff80
  ;
  return;
}


