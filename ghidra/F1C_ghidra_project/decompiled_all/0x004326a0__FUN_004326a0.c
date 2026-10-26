// Function: FUN_004326a0 @ 004326a0
// Strings:  [SettingsFolder]


undefined4 __fastcall FUN_004326a0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004c5840(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_005679c0(PTR_s_SettingsFolder_005c3fa4);
    if (iVar1 != 0) {
      uVar2 = FUN_00567970();
      return uVar2;
    }
  }
  return param_1;
}


