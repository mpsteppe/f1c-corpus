// Function: FUN_0046dc60 @ 0046dc60
// Size (bytes): 170


undefined4 __thiscall FUN_0046dc60(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  FUN_004c8d80();
  cVar1 = FUN_00461db0();
  if (cVar1 == '\0') {
    FUN_0042d210(1);
    if ((DAT_007c56a4 == 5) && (DAT_007cebc4 != '\0')) {
      iVar2 = (**(code **)(**(int **)(param_1 + 0x40) + 0x1c))(0x1e);
      if (iVar2 != 0) {
        FUN_0046bf10(param_2);
      }
      FUN_004d2450();
    }
    FUN_00497250(1);
    iVar2 = FUN_004a0590();
    if (iVar2 == 0) {
      DAT_005cc9e8 = 4;
      return 0;
    }
  }
  else {
    cVar1 = FUN_00461dc0();
    if ((cVar1 != '\0') && (cVar1 = FUN_00462850(), cVar1 != '\0')) {
      DAT_005cc9e8 = 4;
      return 0;
    }
  }
  return 1;
}


