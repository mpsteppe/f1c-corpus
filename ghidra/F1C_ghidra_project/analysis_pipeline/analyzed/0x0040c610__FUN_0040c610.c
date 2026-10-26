// Function: FUN_0040c610 @ 0040c610
// Size (bytes): 60


void __fastcall FUN_0040c610(int param_1)

{
  int iVar1;
  
  if (DAT_007cfcc8 == 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    if ((iVar1 == 1) || (iVar1 == 2)) {
      *(int *)(param_1 + 0x14) = iVar1;
      FUN_0040cde0(0,0);
    }
  }
  else if (*(int *)(param_1 + 0xc) == 1) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    FUN_0040cde0(2,0);
    return;
  }
  return;
}


