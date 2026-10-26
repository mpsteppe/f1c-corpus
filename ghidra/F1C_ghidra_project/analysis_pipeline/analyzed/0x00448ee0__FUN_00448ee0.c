// Function: FUN_00448ee0 @ 00448ee0
// Size (bytes): 31


void __thiscall FUN_00448ee0(int param_1,undefined4 *param_2)

{
  undefined4 local_4;
  
  local_4 = CONCAT31((int3)((uint)param_1 >> 8),*(undefined1 *)(param_1 + 0x19));
  local_4 = CONCAT22(*(undefined2 *)(param_1 + 0x1a),(undefined2)local_4);
  *param_2 = local_4;
  return;
}


