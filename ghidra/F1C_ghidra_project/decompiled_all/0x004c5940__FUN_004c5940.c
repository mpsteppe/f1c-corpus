// Function: FUN_004c5940 @ 004c5940
// Strings:  [SeasonRaces]


void FUN_004c5940(void)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  int local_198;
  int local_194;
  undefined4 local_18c [99];
  
  iVar2 = FUN_00568210(s_SeasonRaces_005d31c8);
  if (iVar2 != 0) {
    iVar2 = FUN_00567980();
    pvVar3 = operator_new(DAT_008ac488 * 4);
    iVar10 = 0;
    if (0 < DAT_008ac488) {
      local_194 = 0;
      do {
        iVar7 = 0;
        iVar1 = DAT_008ac490 + 0x104;
        if (0 < iVar2) {
          do {
            thunk_FUN_0059d6a9(iVar7);
            uVar4 = FUN_00499e20(iVar1 + local_194);
            iVar5 = FUN_00588410(uVar4);
            if (iVar5 == 0) break;
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar2);
        }
        *(int *)((int)pvVar3 + iVar10 * 4) = iVar7;
        iVar10 = iVar10 + 1;
        local_194 = local_194 + 0x18c;
      } while (iVar10 < DAT_008ac488);
    }
    if (0 < DAT_008ac488) {
      local_198 = 0;
      iVar2 = DAT_008ac488;
      iVar10 = 0;
      do {
        iVar1 = iVar10 + 1;
        if (iVar1 < iVar2) {
          iVar7 = iVar10 * 4;
          iVar5 = iVar10;
          iVar2 = iVar1;
          iVar8 = iVar7;
          do {
            if (*(int *)(iVar2 * 4 + (int)pvVar3) < *(int *)(iVar8 + (int)pvVar3)) {
              iVar5 = iVar2;
              iVar8 = iVar2 * 4;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < DAT_008ac488);
          iVar2 = DAT_008ac488;
          if (iVar5 != iVar10) {
            uVar4 = *(undefined4 *)((int)pvVar3 + iVar5 * 4);
            *(undefined4 *)((int)pvVar3 + iVar5 * 4) = *(undefined4 *)(iVar7 + (int)pvVar3);
            *(undefined4 *)(iVar7 + (int)pvVar3) = uVar4;
            puVar6 = (undefined4 *)(iVar5 * 0x18c + DAT_008ac490);
            puVar9 = puVar6;
            puVar11 = local_18c;
            for (iVar2 = 99; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar11 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar11 = puVar11 + 1;
            }
            puVar9 = (undefined4 *)(DAT_008ac490 + local_198);
            for (iVar2 = 99; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar6 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar6 = puVar6 + 1;
            }
            puVar9 = local_18c;
            puVar6 = (undefined4 *)(DAT_008ac490 + local_198);
            for (iVar10 = 99; iVar2 = DAT_008ac488, iVar10 != 0; iVar10 = iVar10 + -1) {
              *puVar6 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar6 = puVar6 + 1;
            }
          }
        }
        local_198 = local_198 + 0x18c;
        iVar10 = iVar1;
      } while (iVar1 < iVar2);
    }
    FUN_00587bcf(pvVar3);
  }
  return;
}


