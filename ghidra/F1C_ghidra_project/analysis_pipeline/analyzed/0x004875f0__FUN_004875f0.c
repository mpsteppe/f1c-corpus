// Function: FUN_004875f0 @ 004875f0
// Size (bytes): 60


undefined4 __fastcall FUN_004875f0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00486720();
  if (iVar1 == 2) {
    (**(code **)(*param_1 + 0x40))(0);
  }
  else if (iVar1 == 3) {
    (**(code **)(*param_1 + 0x40))(1);
    param_1[0x37] = 0;
    return 0;
  }
  param_1[0x37] = 0;
  return 0;
}


