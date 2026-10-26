// Function: FUN_00478090 @ 00478090
// Size (bytes): 30


undefined4 __fastcall FUN_00478090(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x14);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0xe0) = iVar1;
  }
  return 0;
}


