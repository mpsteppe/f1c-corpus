// Function: FUN_004a5e10 @ 004a5e10
// Size (bytes): 35


void __fastcall FUN_004a5e10(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x184);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      FUN_004a5c80(0);
      return;
    }
    if (iVar1 != 4) {
      return;
    }
  }
  FUN_004a5c80(1);
  return;
}


