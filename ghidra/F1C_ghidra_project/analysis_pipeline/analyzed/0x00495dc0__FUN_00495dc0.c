// Function: FUN_00495dc0 @ 00495dc0
// Size (bytes): 610


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00495dc0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int local_18;
  
  if (*(int *)(param_1 + 0x1578) == 0) {
    FUN_004962c0(param_2,0xbf800000);
    iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 0x157c) + 0x4c) + 0xc);
    iVar2 = *(int *)(iVar7 + 0x1c);
    iVar7 = *(int *)(iVar7 + 0x20);
    iVar6 = __ftol();
    uVar10 = iVar6 + *(int *)(param_1 + 0x1580);
    iVar6 = __ftol();
    uVar9 = iVar6 + *(int *)(param_1 + 0x1584);
    uVar5 = ((int)uVar10 < 0) - 1 & uVar10;
    uVar3 = ((int)uVar9 < 0) - 1 & uVar9;
    if (799 < (int)(uVar5 + iVar2)) {
      iVar2 = 800 - uVar5;
    }
    if (599 < (int)(iVar7 + uVar3)) {
      iVar7 = 600 - uVar3;
    }
    uVar14 = 0;
    uVar13 = 0;
    uVar11 = uVar5;
    uVar12 = uVar3;
    uVar4 = FUN_00495150(uVar5,uVar3,iVar2,iVar7,0,0);
    FUN_00494a30(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x157c) + 0x4c) + 0xc),uVar5 - uVar10,
                 uVar3 - uVar9,uVar4,uVar11,uVar12,iVar2,iVar7,uVar13,uVar14);
  }
  else if (*(int *)(param_1 + 0x1578) == 1) {
    local_18 = 0;
    do {
      FUN_004962c0(param_2,(float)local_18 * _DAT_0059e448 + _DAT_0059e43c);
      iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 0x157c) + 0x4c) + 0xc);
      iVar2 = *(int *)(param_1 + 0x1580);
      iVar6 = *(int *)(iVar7 + 0x20);
      iVar8 = *(int *)(iVar7 + 0x1c) / 0x50;
      iVar1 = __ftol();
      iVar7 = *(int *)(param_1 + 0x1584);
      uVar10 = iVar8 * local_18 + iVar2 + iVar1;
      iVar2 = __ftol();
      uVar9 = iVar2 + iVar7;
      uVar3 = ((int)uVar10 < 0) - 1 & uVar10;
      uVar5 = ((int)uVar9 < 0) - 1 & uVar9;
      if (799 < (int)(uVar3 + iVar8)) {
        iVar8 = 800 - uVar3;
      }
      if (599 < (int)(iVar6 + uVar5)) {
        iVar6 = 600 - uVar5;
      }
      uVar14 = 0;
      uVar13 = 0;
      uVar11 = uVar5;
      uVar4 = FUN_00495150(uVar3,uVar5,iVar8,iVar6,0,0);
      FUN_00494a30(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x157c) + 0x4c) + 0xc),uVar10,
                   uVar5 - uVar9,uVar4,uVar3,uVar11,iVar8,iVar6,uVar13,uVar14);
      local_18 = local_18 + 1;
    } while (local_18 < 0x50);
    return;
  }
  return;
}


