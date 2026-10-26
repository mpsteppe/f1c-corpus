// Function: FUN_00542e50 @ 00542e50
// Strings:  [Error deallocating DX surface memory]


undefined4 __fastcall FUN_00542e50(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0053fb80(param_1);
  if (iVar1 != 0) {
    FUN_0053c590(0xffffffff,s_Error_deallocating_DX_surface_me_005dbdc4);
    return 0xffffffff;
  }
  iVar1 = param_1[1];
  param_1[6] = 0;
  *param_1 = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 6;
  if (iVar1 != 0) {
    FUN_00557470();
    FUN_00587bcf(iVar1);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return 0;
}


