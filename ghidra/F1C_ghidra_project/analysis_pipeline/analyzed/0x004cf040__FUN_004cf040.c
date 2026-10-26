// Function: FUN_004cf040 @ 004cf040
// Size (bytes): 41


void __fastcall FUN_004cf040(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      FUN_004cb5e0();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x10));
  }
  return;
}


