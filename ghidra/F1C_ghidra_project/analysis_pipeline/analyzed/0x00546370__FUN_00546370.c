// Function: FUN_00546370 @ 00546370
// Size (bytes): 186


undefined4 __fastcall FUN_00546370(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0xa8) != 0) {
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0xa4)) {
      iVar2 = 0;
      do {
        iVar1 = *(int *)(iVar2 + 0x4c + *(int *)(param_1 + 0xa8));
        if (iVar1 != 0) {
          FUN_00587bcf(iVar1);
        }
        iVar1 = *(int *)(iVar2 + 0x90 + *(int *)(param_1 + 0xa8));
        if (iVar1 != 0) {
          FUN_00557470();
          FUN_00587bcf(iVar1);
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x94;
      } while (iVar3 < *(int *)(param_1 + 0xa4));
    }
    iVar3 = *(int *)(param_1 + 0xa8);
    if (iVar3 != 0) {
      iVar2 = *(int *)(iVar3 + -4);
      if (-1 < iVar2 + -1) {
        do {
          FUN_00557470();
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      FUN_00587bcf(iVar3 + -4);
    }
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  return 0;
}


