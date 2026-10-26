// Function: FUN_0048ea60 @ 0048ea60
// Size (bytes): 52


uint __thiscall FUN_0048ea60(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if (((int)uVar1 < param_2) && (param_2 < (int)(*(int *)(param_1 + 0xc) + uVar1))) {
    uVar1 = *(uint *)(param_1 + 0x18);
    if (((int)uVar1 < param_3) && (param_3 < (int)(*(int *)(param_1 + 0x10) + uVar1))) {
      return CONCAT31((int3)(uVar1 >> 8),1);
    }
  }
  return uVar1 & 0xffffff00;
}


