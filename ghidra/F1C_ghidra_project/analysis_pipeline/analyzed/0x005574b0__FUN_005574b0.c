// Function: FUN_005574b0 @ 005574b0
// Size (bytes): 312


undefined4 __fastcall FUN_005574b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_00545f40();
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x4c)) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(iVar3 + 4 + *(int *)(param_1 + 0x50));
      if (iVar1 != 0) {
        FUN_00547710(iVar1);
        *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0x50)) = 0;
      }
      if ((*(byte *)(param_1 + 0x20) & 8) != 0) {
        FUN_00540cb0(*(int *)(param_1 + 0x50) + iVar3);
      }
      iVar1 = *(int *)(iVar3 + 0x14 + *(int *)(param_1 + 0x50));
      if (iVar1 != 0) {
        FUN_00587bcf(iVar1);
      }
      iVar1 = *(int *)(iVar3 + 0xc + *(int *)(param_1 + 0x50));
      if (iVar1 != 0) {
        FUN_00587bcf(iVar1);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x40;
    } while (iVar2 < *(int *)(param_1 + 0x4c));
  }
  FUN_00557630();
  iVar2 = *(int *)(param_1 + 0x50);
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + -4);
    if (-1 < iVar3 + -1) {
      do {
        FUN_004b0170();
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_00587bcf(iVar2 + -4);
  }
  iVar2 = *(int *)(param_1 + 0x34);
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + -4);
    if (-1 < iVar3 + -1) {
      do {
        FUN_005573f0();
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_00587bcf(iVar2 + -4);
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x40));
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x3c));
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x44));
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x48));
  }
  return 0;
}


