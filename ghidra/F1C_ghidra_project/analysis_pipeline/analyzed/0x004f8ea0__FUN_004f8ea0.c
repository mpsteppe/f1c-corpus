// Function: FUN_004f8ea0 @ 004f8ea0
// Size (bytes): 106


undefined4 __fastcall FUN_004f8ea0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[6];
  if (iVar1 != 0) {
    FUN_00557470();
    FUN_00587bcf(iVar1);
  }
  iVar1 = FUN_0053d1f0(s__FTFRAMERATE_005d6d77 + 1);
  if (iVar1 != 0) {
    FUN_0053d130(iVar1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  return 0;
}


