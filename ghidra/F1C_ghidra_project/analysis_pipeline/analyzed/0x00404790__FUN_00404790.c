// Function: FUN_00404790 @ 00404790
// Size (bytes): 53


void __fastcall FUN_00404790(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    do {
      FUN_004fb5d0();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x130));
  }
  return;
}


