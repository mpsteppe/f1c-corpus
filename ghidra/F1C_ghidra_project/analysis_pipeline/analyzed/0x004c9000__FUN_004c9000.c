// Function: FUN_004c9000 @ 004c9000
// Size (bytes): 44


undefined4 __fastcall FUN_004c9000(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0040c910();
  if ((*(int *)(param_1 + 4) != 0) && (iVar1 != 0)) {
    iVar1 = FUN_0054c0e0(iVar1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}


