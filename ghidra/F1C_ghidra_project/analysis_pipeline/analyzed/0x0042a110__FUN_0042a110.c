// Function: FUN_0042a110 @ 0042a110
// Size (bytes): 102


void __fastcall FUN_0042a110(int param_1)

{
  int iVar1;
  
  if (DAT_007c56a4 == 7) {
    if (*(int *)(param_1 + 0x403c) != DAT_008acf8c + -1) {
      iVar1 = FUN_004a5c40();
      if (((iVar1 == 0) || (iVar1 == 4)) || (*(int *)(param_1 + 0x4064) == 1)) {
        FUN_004a5e40();
        FUN_0042ac70(1);
        return;
      }
    }
  }
  else {
    FUN_004a5e40();
    FUN_0042ac70(1);
  }
  return;
}


