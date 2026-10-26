// Function: FUN_0054a770 @ 0054a770
// Size (bytes): 247


undefined4 __fastcall FUN_0054a770(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x204);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x10); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {
      FUN_0054c410();
      FUN_0054ac30(iVar1);
      FUN_00587bcf(iVar1);
      iVar1 = iVar2;
    }
    FUN_0054c410();
    FUN_0054ac30(iVar1);
    FUN_00587bcf(iVar1);
  }
  if (*(int *)(param_1 + 0x1ec) != 0) {
    FUN_00561940();
  }
  if (*(int *)(param_1 + 0x1e0) != 0) {
    FUN_0054fa50();
  }
  iVar1 = *(int *)(param_1 + 0x224);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      FUN_00587bcf(iVar1);
      iVar1 = iVar2;
    }
    FUN_00587bcf(iVar1);
    *(undefined4 *)(param_1 + 0x224) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x22c);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004b0170();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
    *(undefined4 *)(param_1 + 0x22c) = 0;
  }
  return 0;
}


