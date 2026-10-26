// Function: FUN_0048d4b0 @ 0048d4b0
// Size (bytes): 216


undefined4 __fastcall FUN_0048d4b0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0xb4))();
  if ((iVar1 == 0) || ((float)param_1[0x3e] - (float)param_1[0x3d] <= DAT_0059e440)) {
    param_1[0x38] = 0;
    (**(code **)(*param_1 + 0x38))(1);
  }
  else {
    (**(code **)(*param_1 + 0x20))();
    (**(code **)(*param_1 + 0x18))();
    iVar1 = __ftol();
    if (iVar1 != param_1[0x38]) {
      (**(code **)(*param_1 + 0x2c))(1);
      param_1[0x38] = iVar1;
      FUN_00488970();
      (**(code **)(*param_1 + 0xb0))();
      return 0;
    }
  }
  (**(code **)(*param_1 + 0xb0))();
  return 0;
}


