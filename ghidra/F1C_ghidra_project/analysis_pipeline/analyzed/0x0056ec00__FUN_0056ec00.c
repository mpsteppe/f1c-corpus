// Function: FUN_0056ec00 @ 0056ec00
// Size (bytes): 105


void __fastcall FUN_0056ec00(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      FUN_0056cf70();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 8));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      FUN_0056d020();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x10));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      FUN_0056d2d0();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x18));
  }
  return;
}


