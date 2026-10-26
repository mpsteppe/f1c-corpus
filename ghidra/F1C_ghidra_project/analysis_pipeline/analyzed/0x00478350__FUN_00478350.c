// Function: FUN_00478350 @ 00478350
// Size (bytes): 53


undefined4 __fastcall FUN_00478350(int *param_1)

{
  int iVar1;
  
  if ((param_1[0x38] != 0) && (iVar1 = *(int *)(param_1[0x38] + 0x174), param_1[0x39] != iVar1)) {
    param_1[0x39] = iVar1;
    FUN_00478390();
    (**(code **)(*param_1 + 0x2c))(1);
  }
  return 0;
}


