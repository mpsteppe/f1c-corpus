// Function: FUN_00478200 @ 00478200
// Size (bytes): 30


undefined4 __fastcall FUN_00478200(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x16);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0xe0) = iVar1;
  }
  return 0;
}


