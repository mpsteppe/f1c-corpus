// Function: FUN_005461b0 @ 005461b0
// Size (bytes): 72


undefined4 FUN_005461b0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00543bf0();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  FUN_0053c630(param_1);
  if (param_1 != 0) {
    FUN_005437e0();
    FUN_00587bcf(param_1);
  }
  DAT_008b8f28 = 0;
  return 0;
}


