// Function: FUN_004a0d50 @ 004a0d50
// Strings:  [skipoptions, altosc]


void FUN_004a0d50(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00587c20(param_1,s_altosc_005cd040);
  if (iVar1 != 0) {
    DAT_007ce268 = 1;
  }
  iVar1 = FUN_00587c20(param_1,s_skipoptions_005cd034);
  if (iVar1 != 0) {
    DAT_007ce264 = 2;
  }
  return;
}


