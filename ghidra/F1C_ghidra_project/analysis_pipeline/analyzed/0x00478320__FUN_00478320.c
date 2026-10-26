// Function: FUN_00478320 @ 00478320
// Size (bytes): 37


undefined4 __fastcall FUN_00478320(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x12);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0xe0) = iVar1;
    FUN_00478390();
  }
  return 0;
}


