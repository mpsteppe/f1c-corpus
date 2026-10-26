// Function: FUN_004b87a0 @ 004b87a0
// Size (bytes): 29


undefined4 __thiscall FUN_004b87a0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  *param_2 = *(undefined4 *)(param_1 + 0xf30);
  uVar1 = *(undefined4 *)(param_1 + 0xf34);
  *param_3 = uVar1;
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}


