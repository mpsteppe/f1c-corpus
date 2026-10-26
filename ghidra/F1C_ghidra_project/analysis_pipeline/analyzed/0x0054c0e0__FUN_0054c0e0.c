// Function: FUN_0054c0e0 @ 0054c0e0
// Size (bytes): 44


undefined4 __thiscall FUN_0054c0e0(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x38);
  if ((uVar1 != 0) && ((*(uint *)(param_2 + 0x84) & uVar1 & DAT_008b8e34) != uVar1)) {
    return 0;
  }
  return 1;
}


