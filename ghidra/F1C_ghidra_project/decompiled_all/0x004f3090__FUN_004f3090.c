// Function: FUN_004f3090 @ 004f3090
// Strings:  [FenderFlareRange, FenderFlareSetting, FenderSideways, FenderLiftParams, FenderDragParams, FenderCenter]


void __thiscall
FUN_004f3090(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_005351d0(0x180);
  while ((iVar1 != 0 && (iVar1 = FUN_005651b0(), iVar1 != 1))) {
    if (iVar1 == 0) {
      iVar1 = FUN_00565aa0(s_FenderCenter_005d535c,param_1 + 0x3c,param_1 + 0x44,param_1 + 0x4c,0);
      if (iVar1 != 0) {
        *param_1 = 1;
      }
      FUN_00565aa0(s_FenderDragParams_005d5348,param_1 + 4,param_1 + 0xc,param_1 + 0x14,0);
      FUN_00565aa0(s_FenderLiftParams_005d5334,param_1 + 0x1c,param_1 + 0x24,param_1 + 0x2c,0);
      FUN_00565aa0(s_FenderSideways_005d5324,param_1 + 0x34,0,0,0);
      FUN_0042e1f0(param_4,s_FenderFlareRange_005d52fc,s_FenderFlareSetting_005d5310,0,0x3ff00000);
    }
    iVar1 = FUN_005351d0(0x180);
  }
  return;
}


