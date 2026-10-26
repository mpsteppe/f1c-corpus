// Function: FUN_004895b0 @ 004895b0
// Size (bytes): 66


undefined4 __fastcall FUN_004895b0(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x2c))(1);
  iVar1 = param_1[0x53] + param_1[0x59];
  param_1[0x53] = iVar1;
  if (param_1[0x58] < iVar1) {
    iVar1 = param_1[0x58];
  }
  param_1[0x53] = iVar1;
  FUN_00489d00();
  FUN_00489e90();
  return 0;
}


