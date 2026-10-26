// Function: FUN_00567a90 @ 00567a90
// Size (bytes): 86


void FUN_00567a90(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = thunk_FUN_0059d6a9(0);
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 4);
      FUN_00567a90(iVar2);
      iVar2 = iVar1;
    }
    iVar2 = FUN_0049adb0();
    if (iVar2 != 0) {
      FUN_00567a90(iVar2);
    }
    FUN_00567940();
    FUN_00587bcf(param_1);
  }
  return;
}


