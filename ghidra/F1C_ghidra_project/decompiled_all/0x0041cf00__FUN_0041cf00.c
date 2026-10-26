// Function: FUN_0041cf00 @ 0041cf00
// Strings:  [F1_2002.gdb, F1_2001.gdb, F1_2000.gdb, F1_1999.gdb, TOYOTA, TOYOTA, WILLIAMS, WILLIAMS]


void FUN_0041cf00(void)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined1 *puVar8;
  bool bVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  bool local_22;
  undefined1 local_20 [32];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  FUN_004144d0();
  FUN_004144f0(0x191,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
  FUN_00418560(local_20);
  iVar3 = FUN_004c2990();
  if (iVar3 == 0) {
    puVar4 = DAT_007d0434;
    if (DAT_007d0434 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    iVar3 = FUN_00588410(puVar4,s_F1_1999_gdb_005bf994);
    if (iVar3 == 0) {
      FUN_004144f0(0x192,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
      FUN_004144f0(0x194,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
      uVar10 = 0x193;
    }
    else {
      puVar4 = DAT_007d0434;
      if (DAT_007d0434 == (undefined1 *)0x0) {
        puVar4 = &DAT_005ea438;
      }
      iVar3 = FUN_00588410(puVar4,s_F1_2000_gdb_005bf988);
      if (iVar3 == 0) {
        FUN_004144f0(0x195,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
        FUN_00418560(local_20);
        FUN_004144f0(0x197,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
        FUN_00418560(local_20);
        uVar10 = 0x196;
      }
      else {
        puVar4 = DAT_007d0434;
        if (DAT_007d0434 == (undefined1 *)0x0) {
          puVar4 = &DAT_005ea438;
        }
        iVar3 = FUN_00588410(puVar4,s_F1_2001_gdb_005bf97c);
        if (iVar3 == 0) {
          FUN_004144f0(0x198,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
          FUN_00418560(local_20);
          FUN_004144f0(0x19a,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
          FUN_00418560(local_20);
          uVar10 = 0x199;
        }
        else {
          puVar4 = DAT_007d0434;
          if (DAT_007d0434 == (undefined1 *)0x0) {
            puVar4 = &DAT_005ea438;
          }
          iVar3 = FUN_00588410(puVar4,s_F1_2002_gdb_005bf970);
          if (iVar3 != 0) {
            return;
          }
          bVar9 = false;
          local_22 = false;
          bVar1 = false;
          FUN_004c2850();
          FUN_004c1390();
          iVar3 = FUN_004c0a80();
          if (iVar3 != 0) {
            iVar3 = FUN_00566810();
            local_22 = iVar3 != 0;
            iVar3 = FUN_00566810();
            bVar9 = iVar3 != 0;
            iVar3 = FUN_00566810();
            if (iVar3 != 0) {
              bVar1 = true;
            }
          }
          iVar3 = 0;
          do {
            iVar5 = iVar3;
            FUN_004c2850(iVar3);
            FUN_004c13a0(iVar5);
            iVar5 = FUN_004c0a80();
            if (iVar5 != 0) {
              iVar5 = iVar3;
              FUN_004c2850(iVar3);
              iVar5 = FUN_004c13a0(iVar5);
              if (*(char *)(iVar5 + 0x1b0) != '\0') {
                iVar5 = FUN_00566810();
                if (iVar5 != 0) {
                  local_22 = true;
                }
                iVar5 = FUN_00566810();
                if (iVar5 != 0) {
                  bVar9 = true;
                }
                iVar5 = FUN_00566810();
                if (iVar5 != 0) {
                  bVar1 = true;
                }
              }
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < 0x67);
          if (!local_22) {
            return;
          }
          uVar15 = 0xc0000000;
          uVar14 = 0xc0000000;
          uVar13 = 0xffffffff;
          uVar12 = 0xffffffff;
          uVar11 = 0xffffffff;
          uVar10 = FUN_00415550(s_FERRARI_005c2618);
          FUN_004144f0(0x19b,uVar10,uVar11,uVar12,uVar13,uVar14,uVar15);
          FUN_00418560(local_20);
          if (bVar9) {
            uVar15 = 0xc0000000;
            uVar14 = 0xc0000000;
            uVar13 = 0xffffffff;
            uVar12 = 0xffffffff;
            uVar11 = 0xffffffff;
            uVar10 = FUN_00415550(s_WILLIAMS_005c260c);
            FUN_004144f0(0x19d,uVar10,uVar11,uVar12,uVar13,uVar14,uVar15);
            FUN_00418560(local_20);
          }
          if (!bVar1) {
            return;
          }
          uVar10 = 0x19c;
        }
      }
    }
    FUN_004144f0(uVar10,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
    FUN_00418560(local_20);
    return;
  }
  piVar6 = (int *)FUN_0041f340();
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)FUN_0041f340();
    if (piVar6 == (int *)0x0) goto LAB_0041d61b;
    piVar7 = (int *)FUN_0041f340();
    if (piVar7 != (int *)0x0) {
      puVar4 = (undefined1 *)*piVar7;
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_005ea438;
      }
      puVar8 = (undefined1 *)*piVar6;
      if (puVar8 == (undefined1 *)0x0) {
        puVar8 = &DAT_005ea438;
      }
      uVar15 = 0xc0000000;
      uVar14 = 0xc0000000;
      uVar13 = 0xffffffff;
      uVar12 = 0xffffffff;
      uVar10 = FUN_00415550(puVar4);
      uVar11 = FUN_00415550(puVar8);
      FUN_004144f0(0x1ab,uVar11,uVar10,uVar12,uVar13,uVar14,uVar15);
      FUN_00418560(local_20);
      if (*piVar7 != 0) {
        FUN_00587bcf(*piVar7);
      }
      FUN_00587bcf(piVar7);
    }
    if (*piVar6 != 0) {
      FUN_00587bcf(*piVar6);
    }
  }
  else {
    cVar2 = FUN_0041fb10();
    puVar4 = (undefined1 *)*piVar6;
    if (cVar2 == '\0') {
      cVar2 = FUN_0041fdb0();
      puVar4 = (undefined1 *)*piVar6;
      if (cVar2 == '\0') {
        cVar2 = FUN_0041fc60();
        puVar4 = (undefined1 *)*piVar6;
        if (cVar2 == '\0') {
          if (puVar4 == (undefined1 *)0x0) {
            puVar4 = &DAT_005ea438;
          }
          uVar15 = 0xc0000000;
          uVar14 = 0xc0000000;
          uVar13 = 0xffffffff;
          uVar12 = 0xffffffff;
          uVar11 = 0xffffffff;
          uVar10 = FUN_00415550(puVar4);
          FUN_004144f0(0x1a0,uVar10,uVar11,uVar12,uVar13,uVar14,uVar15);
        }
        else {
          cVar2 = FUN_0041fdf0();
          if (cVar2 == '\0') {
            cVar2 = FUN_0041ff10();
            if ((cVar2 == '\0') || (iVar3 = DAT_008ac48c * 0x18c + DAT_008ac490, iVar3 == 0)) {
              puVar4 = (undefined1 *)*piVar6;
              if (puVar4 == (undefined1 *)0x0) {
                puVar4 = &DAT_005ea438;
              }
              uVar16 = 0xc0000000;
              uVar15 = 0xc0000000;
              uVar14 = 0xffffffff;
              uVar13 = 0xffffffff;
              uVar12 = 0xffffffff;
              uVar10 = FUN_00415550(puVar4);
              uVar11 = 0x1a6;
              goto LAB_0041d5eb;
            }
            puVar4 = (undefined1 *)*piVar6;
            if (puVar4 == (undefined1 *)0x0) {
              puVar4 = &DAT_005ea438;
            }
            uVar15 = 0xc0000000;
            uVar14 = 0xc0000000;
            uVar13 = 0xffffffff;
            uVar12 = 0xffffffff;
            uVar10 = FUN_004155d0(iVar3 + 0x104);
            uVar11 = FUN_00415550(puVar4);
            FUN_004144f0(0x1a5,uVar11,uVar10,uVar12,uVar13,uVar14,uVar15);
          }
          else {
            puVar4 = (undefined1 *)*piVar6;
            if (puVar4 == (undefined1 *)0x0) {
              puVar4 = &DAT_005ea438;
            }
            uVar15 = 0xc0000000;
            uVar14 = 0xc0000000;
            uVar13 = 0xffffffff;
            uVar12 = 0xffffffff;
            uVar10 = FUN_004155d0(DAT_008ac48c * 0x18c + 0x104 + DAT_008ac490);
            uVar11 = FUN_00415550(puVar4);
            FUN_004144f0(0x1a4,uVar11,uVar10,uVar12,uVar13,uVar14,uVar15);
          }
        }
      }
      else {
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_005ea438;
        }
        uVar16 = 0xc0000000;
        uVar15 = 0xc0000000;
        uVar14 = 0xffffffff;
        uVar13 = 0xffffffff;
        uVar12 = 0xffffffff;
        uVar10 = FUN_00415550(puVar4);
        uVar11 = 0x19f;
LAB_0041d5eb:
        FUN_004144f0(uVar11,uVar10,uVar12,uVar13,uVar14,uVar15,uVar16);
      }
    }
    else {
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_005ea438;
      }
      uVar15 = 0xc0000000;
      uVar14 = 0xc0000000;
      uVar13 = 0xffffffff;
      uVar12 = 0xffffffff;
      uVar11 = 0xffffffff;
      uVar10 = FUN_00415550(puVar4);
      FUN_004144f0(0x19e,uVar10,uVar11,uVar12,uVar13,uVar14,uVar15);
    }
    FUN_00418560(local_20);
    if (*piVar6 != 0) {
      FUN_00587bcf(*piVar6);
    }
  }
  FUN_00587bcf(piVar6);
LAB_0041d61b:
  FUN_00420820();
  return;
}


