// Function: FUN_00479d00 @ 00479d00
// Size (bytes): 57


undefined4 __fastcall FUN_00479d00(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0xe);
  if (iVar1 != 0) {
    FUN_00477280(param_1);
  }
  iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0xf);
  if (iVar1 != 0) {
    FUN_00477280(param_1);
  }
  return 0;
}


