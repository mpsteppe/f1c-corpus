// Function: FUN_004f9420 @ 004f9420
// Size (bytes): 83


undefined4 FUN_004f9420(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_004f9240(param_1,param_2,param_3,param_4);
  if (iVar1 < 0) {
    return 1;
  }
  DAT_005d6d68 = param_3;
  DAT_008afe78 = param_4;
  DAT_005d6d60 = param_1;
  DAT_008afe74 = iVar1;
  DAT_005d6d64 = param_2;
  return 0;
}


