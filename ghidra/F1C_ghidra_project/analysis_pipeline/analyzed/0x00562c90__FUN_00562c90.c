// Function: FUN_00562c90 @ 00562c90
// Size (bytes): 136


int __fastcall FUN_00562c90(int *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (*param_1 != 0) {
    return 4;
  }
  param_1[0x24] = param_4;
  iVar1 = FUN_00562d90();
  if ((iVar1 == 0) && (iVar1 = FUN_00562e30(), iVar1 == 0)) {
    if ((param_4 != 6) && ((param_4 != 7 && (iVar1 = FUN_00562d20(), iVar1 != 0)))) {
      return iVar1;
    }
    param_1[0x1c] = 0;
    param_1[0x1d] = 0;
    iVar1 = FUN_00563eb0();
    param_1[0x26] = iVar1;
    param_1[0x157] = -1;
    if (param_2 == 0) {
      FUN_00563000();
    }
    iVar1 = 0;
  }
  return iVar1;
}


