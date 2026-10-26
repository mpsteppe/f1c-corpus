// Function: FUN_00420490 @ 00420490
// Size (bytes): 911


void __fastcall FUN_00420490(char param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined1 local_20 [32];
  
  puVar10 = (undefined4 *)0x0;
  puVar11 = (undefined4 *)0x0;
  bVar1 = false;
  bVar2 = false;
  FUN_004c2850();
  iVar3 = FUN_004c1390();
  if (*(int *)(iVar3 + 0x19c) == 1) {
    FUN_004c2850();
    puVar11 = (undefined4 *)FUN_004c1390();
LAB_00420532:
    if (puVar11 != (undefined4 *)0x0) {
      FUN_004c2850();
      puVar4 = (undefined4 *)FUN_004c1390();
      if (puVar11 != puVar4) {
        iVar3 = puVar11[0x66];
        FUN_004c2850();
        iVar5 = FUN_004c1390();
        if (iVar3 == *(int *)(iVar5 + 0x198)) {
          bVar1 = true;
        }
      }
      iVar5 = 0;
      FUN_004c2850();
      iVar3 = FUN_004c1370();
      if (0 < iVar3) {
        do {
          iVar3 = iVar5;
          FUN_004c2850(iVar5);
          puVar4 = (undefined4 *)FUN_004c13a0(iVar3);
          if (puVar11 != puVar4) {
            iVar3 = puVar11[0x66];
            iVar6 = iVar5;
            FUN_004c2850(iVar5);
            iVar6 = FUN_004c13a0(iVar6);
            if (iVar3 == *(int *)(iVar6 + 0x198)) {
              bVar1 = true;
            }
          }
          iVar5 = iVar5 + 1;
          FUN_004c2850();
          iVar3 = FUN_004c1370();
        } while (iVar5 < iVar3);
      }
      if ((!bVar1) && (param_1 != '\0')) {
        FUN_004144d0();
        puVar9 = (undefined1 *)puVar11[2];
        if (puVar9 == (undefined1 *)0x0) {
          puVar9 = &DAT_005ea438;
        }
        puVar7 = (undefined1 *)*puVar11;
        if (puVar7 == (undefined1 *)0x0) {
          puVar7 = &DAT_005ea438;
        }
        uVar16 = 0xc0000000;
        uVar15 = 0xc0000000;
        uVar14 = 0xffffffff;
        uVar13 = 0xffffffff;
        uVar12 = 2;
        uVar8 = FUN_00415230(puVar7,puVar9);
        FUN_004144f0(0x18d,uVar8,uVar12,uVar13,uVar14,uVar15,uVar16);
        FUN_00418560(local_20);
      }
    }
  }
  else {
    iVar5 = 0;
    FUN_004c2850();
    iVar3 = FUN_004c1370();
    if (0 < iVar3) {
      do {
        iVar3 = iVar5;
        FUN_004c2850(iVar5);
        iVar3 = FUN_004c13a0(iVar3);
        if (*(int *)(iVar3 + 0x19c) == 1) {
          FUN_004c2850(iVar5);
          puVar11 = (undefined4 *)FUN_004c13a0(iVar5);
          goto LAB_00420532;
        }
        iVar5 = iVar5 + 1;
        FUN_004c2850();
        iVar3 = FUN_004c1370();
      } while (iVar5 < iVar3);
    }
  }
  FUN_004c2850();
  iVar3 = FUN_004c1390();
  if (*(int *)(iVar3 + 0x19c) == 2) {
    FUN_004c2850();
    puVar10 = (undefined4 *)FUN_004c1390();
LAB_004206d7:
    if (puVar10 != (undefined4 *)0x0) {
      FUN_004c2850();
      puVar4 = (undefined4 *)FUN_004c1390();
      if (puVar10 != puVar4) {
        iVar3 = puVar10[0x66];
        FUN_004c2850();
        iVar5 = FUN_004c1390();
        if (iVar3 == *(int *)(iVar5 + 0x198)) {
          bVar2 = true;
        }
      }
      iVar5 = 0;
      FUN_004c2850();
      iVar3 = FUN_004c1370();
      if (0 < iVar3) {
        do {
          iVar3 = iVar5;
          FUN_004c2850(iVar5);
          puVar4 = (undefined4 *)FUN_004c13a0(iVar3);
          if (puVar10 != puVar4) {
            iVar3 = puVar10[0x66];
            iVar6 = iVar5;
            FUN_004c2850(iVar5);
            iVar6 = FUN_004c13a0(iVar6);
            if (iVar3 == *(int *)(iVar6 + 0x198)) {
              bVar2 = true;
            }
          }
          iVar5 = iVar5 + 1;
          FUN_004c2850();
          iVar3 = FUN_004c1370();
        } while (iVar5 < iVar3);
      }
      if (!bVar2) {
        if (param_1 == '\0') goto LAB_004207f6;
        FUN_004144d0();
        puVar9 = (undefined1 *)puVar10[2];
        if (puVar9 == (undefined1 *)0x0) {
          puVar9 = &DAT_005ea438;
        }
        puVar7 = (undefined1 *)*puVar10;
        if (puVar7 == (undefined1 *)0x0) {
          puVar7 = &DAT_005ea438;
        }
        uVar16 = 0xc0000000;
        uVar15 = 0xc0000000;
        uVar14 = 0xffffffff;
        uVar13 = 0xffffffff;
        uVar12 = 3;
        uVar8 = FUN_00415230(puVar7,puVar9);
        FUN_004144f0(0x18d,uVar8,uVar12,uVar13,uVar14,uVar15,uVar16);
        FUN_00418560(local_20);
      }
    }
  }
  else {
    iVar5 = 0;
    FUN_004c2850();
    iVar3 = FUN_004c1370();
    if (0 < iVar3) {
      do {
        iVar3 = iVar5;
        FUN_004c2850(iVar5);
        iVar3 = FUN_004c13a0(iVar3);
        if (*(int *)(iVar3 + 0x19c) == 2) {
          FUN_004c2850(iVar5);
          puVar10 = (undefined4 *)FUN_004c13a0(iVar5);
          goto LAB_004206d7;
        }
        iVar5 = iVar5 + 1;
        FUN_004c2850();
        iVar3 = FUN_004c1370();
      } while (iVar5 < iVar3);
    }
  }
  if (param_1 != '\0') {
    return;
  }
LAB_004207f6:
  if ((((!bVar1) && (!bVar2)) && (puVar11 != (undefined4 *)0x0)) && (puVar10 != (undefined4 *)0x0))
  {
    FUN_004144d0();
  }
  return;
}


