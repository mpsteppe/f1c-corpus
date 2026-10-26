// Function: FUN_0041f1e0 @ 0041f1e0
// Size (bytes): 56


undefined4 __fastcall FUN_0041f1e0(int param_1)

{
  int iVar1;
  
  FUN_004c2850();
  iVar1 = FUN_004c11d0();
  if ((((param_1 != 0) && (1 < iVar1)) && (*(int *)(param_1 + 0x14 + iVar1 * 4) == 1)) &&
     (*(int *)(param_1 + 0x10 + iVar1 * 4) == 1)) {
    return 1;
  }
  return 0;
}


