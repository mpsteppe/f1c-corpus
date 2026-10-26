// Function: FUN_004c0910 @ 004c0910
// Strings:  [SeasonScoringInfo]


void __thiscall FUN_004c0910(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (DAT_007d00ec == 5) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x1a4) * 0x48c0 + 0x4060 + DAT_007d2e48) + -1;
    *(int *)(param_1 + 0x1a8) = iVar2;
    if (iVar2 == 0) {
      *(int *)(param_1 + 0x1a0) = *(int *)(param_1 + 0x1a0) + 1;
    }
  }
  else if (DAT_007d00ec == 7) {
    *(undefined4 *)(param_1 + 0x18 + param_2 * 4) =
         *(undefined4 *)(*(int *)(param_1 + 0x1a4) * 0x48c0 + 0x4060 + DAT_007d2e48);
    iVar2 = *(int *)(param_1 + 0x1a4) * 0x48c0 + DAT_007d2e48;
    iVar4 = 0;
    if (*(int *)(iVar2 + 0x4064) != 3) {
      iVar1 = __ftol();
      if (iVar1 <= *(int *)(iVar2 + 0x403c)) {
        iVar2 = FUN_00568210(s_SeasonScoringInfo_005d2804);
        if (iVar2 != 0) {
          iVar2 = thunk_FUN_0059d6a9(*(int *)(param_1 + 0x18 + param_2 * 4) + -1);
          if (iVar2 != 0) {
            uVar3 = FUN_00567970();
            iVar4 = FUN_00587ece(uVar3);
          }
        }
      }
    }
    *(int *)(param_1 + 0xd8 + param_2 * 4) = iVar4;
    *(int *)(param_1 + 0x198) = *(int *)(param_1 + 0x198) + iVar4;
    *(undefined4 *)(param_1 + 0x1a8) = *(undefined4 *)(param_1 + 0x1a4);
    return;
  }
  return;
}


