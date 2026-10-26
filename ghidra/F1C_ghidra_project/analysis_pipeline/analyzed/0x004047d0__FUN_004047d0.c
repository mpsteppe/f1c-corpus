// Function: FUN_004047d0 @ 004047d0
// Size (bytes): 53


void __fastcall FUN_004047d0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    do {
      FUN_004fb2e0();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x130));
  }
  return;
}


