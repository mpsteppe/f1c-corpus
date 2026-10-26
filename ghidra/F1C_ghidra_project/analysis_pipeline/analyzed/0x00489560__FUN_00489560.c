// Function: FUN_00489560 @ 00489560
// Size (bytes): 67


undefined4 __fastcall FUN_00489560(int *param_1)

{
  uint uVar1;
  
  (**(code **)(*param_1 + 0x2c))(1);
  uVar1 = param_1[0x53] - param_1[0x59];
  param_1[0x53] = uVar1;
  param_1[0x53] = uVar1 & ((int)uVar1 < 0) - 1;
  FUN_00489d00();
  FUN_00489e90();
  return 0;
}


