// Function: FUN_0041f150 @ 0041f150
// Size (bytes): 43


undefined4 __fastcall FUN_0041f150(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    FUN_004c2850();
    iVar1 = FUN_004c11d0();
    if ((0 < iVar1) && (*(int *)(param_1 + 0x14 + iVar1 * 4) < 5)) {
      return 1;
    }
  }
  return 0;
}


