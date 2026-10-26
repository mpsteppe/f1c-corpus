// Function: FUN_00558a30 @ 00558a30
// Size (bytes): 252


void __thiscall FUN_00558a30(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint *puVar6;
  int iVar7;
  
  if (((*(int *)(param_1 + 0x30) < *(int *)(param_1 + 0x2c)) && (param_2 < *(int *)(param_1 + 0x2c))
      ) && (puVar6 = (uint *)(param_2 * 0x80 + *(int *)(param_1 + 0x34)),
           (*(byte *)(param_2 * 0x80 + *(int *)(param_1 + 0x34)) & 0x40) == 0)) {
    if (*(char *)(param_1 + 0x20) < '\0') {
      FUN_00558d10(0);
      iVar7 = *(int *)(*(int *)(param_1 + 0x50) + 0x20);
      if (iVar7 != 0) {
        iVar1 = *(int *)(param_1 + 0x24);
        puVar5 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar1 * param_2 * 0x24);
        puVar3 = (undefined4 *)(*(int *)(param_1 + 0x30) * iVar1 * 0x40 + iVar7);
        iVar7 = 0;
        if (0 < iVar1) {
          do {
            *puVar3 = *puVar5;
            puVar3[1] = puVar5[1];
            puVar3[2] = puVar5[2];
            puVar3[6] = puVar5[6];
            puVar3 = puVar3 + 0x10;
            puVar5 = puVar5 + 9;
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(int *)(param_1 + 0x24));
        }
      }
      puVar6[1] = *(uint *)(param_1 + 0x30);
      *(uint **)(*(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x30) * 4) = puVar6;
      *puVar6 = *puVar6 | 0x40;
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      return;
    }
    uVar4 = *(uint *)(param_1 + 0x38);
    if (uVar4 == 0) {
      *(uint **)(param_1 + 0x38) = puVar6;
    }
    else {
      for (uVar2 = *(uint *)(uVar4 + 0x7c); uVar2 != 0; uVar2 = *(uint *)(uVar2 + 0x7c)) {
        uVar4 = uVar2;
      }
      *(uint **)(uVar4 + 0x7c) = puVar6;
    }
    puVar6[0x1e] = uVar4;
    puVar6[0x1f] = 0;
    *puVar6 = *puVar6 | 0x40;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  }
  return;
}


