// Function: FUN_004782a0 @ 004782a0
// Size (bytes): 30


undefined4 __fastcall FUN_004782a0(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x10);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0xe0) = iVar1;
  }
  return 0;
}


