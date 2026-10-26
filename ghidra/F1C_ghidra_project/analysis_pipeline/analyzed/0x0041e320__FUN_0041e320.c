// Function: FUN_0041e320 @ 0041e320
// Size (bytes): 1301


void FUN_0041e320(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined1 *puVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int *local_24;
  undefined1 local_20 [32];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  FUN_004144d0();
  iVar11 = 0;
  local_24 = (int *)0x0;
  FUN_004c2850();
  FUN_004c11d0();
  piVar2 = (int *)FUN_0041f340();
  piVar3 = (int *)FUN_0041f5d0();
  if (piVar2 != (int *)0x0) {
    local_24 = (int *)FUN_0041f340();
  }
  if (piVar3 != (int *)0x0) {
    iVar11 = FUN_0041f5d0();
  }
  FUN_004c2850();
  iVar4 = FUN_004c11d0();
  if (iVar4 == 1) {
    if (piVar2 == (int *)0x0) {
      return;
    }
    puVar5 = (undefined1 *)*piVar2;
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    uVar18 = 0xc0000000;
    uVar17 = 0xc0000000;
    uVar16 = 0xffffffff;
    uVar15 = 0xffffffff;
    uVar14 = 0xffffffff;
    uVar6 = FUN_00415550(puVar5);
    uVar13 = 0x1e3;
LAB_0041e409:
    FUN_004144f0(uVar13,uVar6,uVar14,uVar15,uVar16,uVar17,uVar18);
LAB_0041e417:
    FUN_00418560(local_20);
  }
  else {
    iVar4 = FUN_004c2850();
    if (*(int *)(iVar4 + 0xb144) == 3) {
      FUN_00420cf0();
      goto LAB_0041e7d4;
    }
    if (piVar2 != (int *)0x0) {
      if ((piVar3 == (int *)0x0) && (piVar3 = (int *)FUN_0041f5d0(), piVar3 == (int *)0x0)) {
        puVar5 = (undefined1 *)*piVar2;
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        uVar17 = 0xc0000000;
        uVar16 = 0xc0000000;
        uVar15 = 0xffffffff;
        uVar14 = 0xffffffff;
        uVar13 = 0xffffffff;
        uVar6 = FUN_00415550(puVar5);
        FUN_004144f0(0x1e3,uVar6,uVar13,uVar14,uVar15,uVar16,uVar17);
      }
      else {
        puVar5 = (undefined1 *)*piVar3;
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        puVar12 = (undefined1 *)*piVar2;
        if (puVar12 == (undefined1 *)0x0) {
          puVar12 = &DAT_005ea438;
        }
        iVar4 = FUN_00588410(puVar12,puVar5);
        if (iVar4 == 0) {
          if ((local_24 != (int *)0x0) && (iVar11 != 0)) {
            iVar11 = FUN_0041f220();
            iVar4 = FUN_0041f220();
            iVar9 = FUN_0041f220();
            iVar10 = FUN_0041f220();
            puVar5 = (undefined1 *)*piVar2;
            if (iVar4 - iVar11 < iVar10 - iVar9) {
              if (puVar5 == (undefined1 *)0x0) {
                puVar5 = &DAT_005ea438;
              }
              uVar17 = 0xc0000000;
              uVar16 = 0xc0000000;
              uVar15 = 0xffffffff;
              uVar14 = 0xffffffff;
              uVar13 = 0xffffffff;
              uVar6 = FUN_00415550(puVar5);
              FUN_004144f0(0x1e5,uVar6,uVar13,uVar14,uVar15,uVar16,uVar17);
              FUN_00418560(local_20);
              FUN_00420820();
            }
            else if (iVar4 - iVar11 == iVar10 - iVar9) {
              if (puVar5 == (undefined1 *)0x0) {
                puVar5 = &DAT_005ea438;
              }
              uVar17 = 0xc0000000;
              uVar16 = 0xc0000000;
              uVar15 = 0xffffffff;
              uVar14 = 0xffffffff;
              uVar13 = 0xffffffff;
              uVar6 = FUN_00415550(puVar5);
              FUN_004144f0(0x1e6,uVar6,uVar13,uVar14,uVar15,uVar16,uVar17);
              FUN_00418560(local_20);
              FUN_00420820();
            }
            else {
              if (puVar5 == (undefined1 *)0x0) {
                puVar5 = &DAT_005ea438;
              }
              uVar17 = 0xc0000000;
              uVar16 = 0xc0000000;
              uVar15 = 0xffffffff;
              uVar14 = 0xffffffff;
              uVar13 = 0xffffffff;
              uVar6 = FUN_00415550(puVar5);
              FUN_004144f0(0x1e7,uVar6,uVar13,uVar14,uVar15,uVar16,uVar17);
              FUN_00418560(local_20);
              FUN_00420820();
            }
            goto LAB_0041e7d4;
          }
          puVar5 = (undefined1 *)*piVar2;
          if (puVar5 == (undefined1 *)0x0) {
            puVar5 = &DAT_005ea438;
          }
          uVar17 = 0xc0000000;
          uVar16 = 0xc0000000;
          uVar15 = 0xffffffff;
          uVar14 = 0xffffffff;
          uVar13 = 0xffffffff;
          uVar6 = FUN_00415550(puVar5);
          FUN_004144f0(0x1e6,uVar6,uVar13,uVar14,uVar15,uVar16,uVar17);
        }
        else {
          cVar1 = FUN_0041f8a0();
          puVar5 = (undefined1 *)*piVar2;
          if (cVar1 != '\0') {
            if (puVar5 == (undefined1 *)0x0) {
              puVar5 = &DAT_005ea438;
            }
            uVar18 = 0xc0000000;
            uVar17 = 0xc0000000;
            uVar16 = 0xffffffff;
            uVar15 = 0xffffffff;
            uVar14 = 0xffffffff;
            uVar6 = FUN_00415550(puVar5);
            uVar13 = 0x1e4;
            goto LAB_0041e409;
          }
          if (puVar5 == (undefined1 *)0x0) {
            puVar5 = &DAT_005ea438;
          }
          uVar17 = 0xc0000000;
          uVar16 = 0xc0000000;
          uVar15 = 0xffffffff;
          uVar14 = 0xffffffff;
          uVar13 = 0xffffffff;
          uVar6 = FUN_00415550(puVar5);
          FUN_004144f0(0x1e3,uVar6,uVar13,uVar14,uVar15,uVar16,uVar17);
        }
      }
      goto LAB_0041e417;
    }
    piVar7 = (int *)FUN_0041f340();
    if (piVar7 != (int *)0x0) {
      piVar8 = (int *)FUN_0041f340();
      if (piVar8 != (int *)0x0) {
        puVar5 = (undefined1 *)*piVar8;
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        puVar12 = (undefined1 *)*piVar7;
        if (puVar12 == (undefined1 *)0x0) {
          puVar12 = &DAT_005ea438;
        }
        uVar17 = 0xc0000000;
        uVar16 = 0xc0000000;
        uVar15 = 0xffffffff;
        uVar14 = 0xffffffff;
        uVar6 = FUN_00415550(puVar5);
        uVar13 = FUN_00415550(puVar12);
        FUN_004144f0(0x1ab,uVar13,uVar6,uVar14,uVar15,uVar16,uVar17);
        FUN_00418560(local_20);
        if (*piVar8 != 0) {
          FUN_00587bcf(*piVar8);
        }
        FUN_00587bcf(piVar8);
      }
      if (*piVar7 != 0) {
        FUN_00587bcf(*piVar7);
      }
      FUN_00587bcf(piVar7);
      FUN_00420820();
      goto LAB_0041e7d4;
    }
  }
  FUN_00420820();
LAB_0041e7d4:
  if (piVar2 != (int *)0x0) {
    if (*piVar2 != 0) {
      FUN_00587bcf(*piVar2);
    }
    FUN_00587bcf(piVar2);
  }
  if (piVar3 != (int *)0x0) {
    if (*piVar3 != 0) {
      FUN_00587bcf(*piVar3);
    }
    FUN_00587bcf(piVar3);
  }
  if (local_24 != (int *)0x0) {
    if (*local_24 != 0) {
      FUN_00587bcf(*local_24);
    }
    FUN_00587bcf(local_24);
  }
  return;
}


