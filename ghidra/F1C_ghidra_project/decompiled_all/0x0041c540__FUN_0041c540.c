// Function: FUN_0041c540 @ 0041c540
// Strings:  [F1_2002.gdb, F1_2001.gdb, F1_2000.gdb, F1_1999.gdb, Takuma S, Takuma S, Felipe M, Felipe M]


void FUN_0041c540(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 local_24;
  undefined1 local_20 [32];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  if (DAT_007d0410 != 4) {
    return;
  }
  iVar2 = FUN_004c2850();
  if (iVar2 == 0) {
    return;
  }
  FUN_004144d0();
  iVar2 = FUN_004c2990();
  iVar3 = FUN_004c2850();
  if (iVar3 != 0) {
    FUN_004c2850();
    iVar3 = FUN_004c11c0();
    if (iVar3 < 5) {
      FUN_004144f0(0x175,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
    }
  }
  if (iVar2 == 0) {
    puVar4 = DAT_007d0434;
    if (DAT_007d0434 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    iVar2 = FUN_00588410(puVar4,s_F1_1999_gdb_005bf994);
    if (iVar2 == 0) {
      FUN_004144f0(0x176,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
      FUN_004144f0(0x178,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
      uVar14 = 0x177;
    }
    else {
      puVar4 = DAT_007d0434;
      if (DAT_007d0434 == (undefined1 *)0x0) {
        puVar4 = &DAT_005ea438;
      }
      iVar2 = FUN_00588410(puVar4,s_F1_2000_gdb_005bf988);
      if (iVar2 == 0) {
        FUN_004144f0(0x179,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
        FUN_00418560(local_20);
        FUN_004144f0(0x17b,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
        FUN_00418560(local_20);
        uVar14 = 0x17a;
      }
      else {
        puVar4 = DAT_007d0434;
        if (DAT_007d0434 == (undefined1 *)0x0) {
          puVar4 = &DAT_005ea438;
        }
        iVar2 = FUN_00588410(puVar4,s_F1_2001_gdb_005bf97c);
        if (iVar2 == 0) {
          FUN_004144f0(0x17c,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
          FUN_00418560(local_20);
          FUN_004144f0(0x17e,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
          FUN_00418560(local_20);
          uVar14 = 0x17d;
        }
        else {
          puVar4 = DAT_007d0434;
          if (DAT_007d0434 == (undefined1 *)0x0) {
            puVar4 = &DAT_005ea438;
          }
          iVar2 = FUN_00588410(puVar4,s_F1_2002_gdb_005bf970);
          if (iVar2 != 0) {
            return;
          }
          FUN_004c2850();
          FUN_004c1390();
          iVar2 = FUN_00566810();
          bVar7 = iVar2 != 0;
          FUN_004c2850();
          FUN_004c1390();
          iVar2 = FUN_00566810();
          bVar8 = iVar2 != 0;
          FUN_004c2850();
          FUN_004c1390();
          iVar2 = FUN_00566810();
          bVar9 = iVar2 != 0;
          FUN_004c2850();
          FUN_004c1390();
          iVar2 = FUN_00566810();
          bVar10 = iVar2 != 0;
          FUN_004c2850();
          FUN_004c1390();
          iVar2 = FUN_00566810();
          bVar11 = iVar2 != 0;
          FUN_004c2850();
          FUN_004c1390();
          iVar2 = FUN_00566810();
          bVar12 = iVar2 != 0;
          FUN_004c2850();
          FUN_004c1390();
          iVar2 = FUN_00566810();
          bVar13 = iVar2 != 0;
          iVar2 = 0;
          do {
            iVar3 = iVar2;
            FUN_004c2850(iVar2);
            iVar3 = FUN_004c13a0(iVar3);
            if (*(char *)(iVar3 + 0x1b0) != '\0') {
              iVar3 = iVar2;
              FUN_004c2850(iVar2);
              FUN_004c13a0(iVar3);
              iVar3 = FUN_00566810();
              if (iVar3 != 0) {
                bVar7 = true;
              }
              iVar3 = iVar2;
              FUN_004c2850(iVar2);
              FUN_004c13a0(iVar3);
              iVar3 = FUN_00566810();
              if (iVar3 != 0) {
                bVar8 = true;
              }
              iVar3 = iVar2;
              FUN_004c2850(iVar2);
              FUN_004c13a0(iVar3);
              iVar3 = FUN_00566810();
              if (iVar3 != 0) {
                bVar9 = true;
              }
              iVar3 = iVar2;
              FUN_004c2850(iVar2);
              FUN_004c13a0(iVar3);
              iVar3 = FUN_00566810();
              if (iVar3 != 0) {
                bVar10 = true;
              }
              iVar3 = iVar2;
              FUN_004c2850(iVar2);
              FUN_004c13a0(iVar3);
              iVar3 = FUN_00566810();
              if (iVar3 != 0) {
                bVar11 = true;
              }
              iVar3 = iVar2;
              FUN_004c2850(iVar2);
              FUN_004c13a0(iVar3);
              iVar3 = FUN_00566810();
              if (iVar3 != 0) {
                bVar12 = true;
              }
              iVar3 = iVar2;
              FUN_004c2850(iVar2);
              FUN_004c13a0(iVar3);
              iVar3 = FUN_00566810();
              if (iVar3 != 0) {
                bVar13 = true;
              }
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < 0x67);
          if (bVar7) {
            FUN_004144f0(0x17f,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
            FUN_00418560(local_20);
            if (((bVar8) && (bVar9)) && (bVar10)) {
              FUN_004144f0(0x181,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
              FUN_00418560(local_20);
            }
          }
          if (!bVar11) {
            return;
          }
          if (!bVar12) {
            return;
          }
          if (!bVar13) {
            return;
          }
          uVar14 = 0x180;
        }
      }
    }
    FUN_004144f0(uVar14,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
    FUN_00418560(local_20);
    return;
  }
  puVar5 = (undefined4 *)FUN_0041e920();
  if (puVar5 == (undefined4 *)0x0) {
    iVar2 = FUN_0041e920();
    if (iVar2 != 0) {
      FUN_0041e920();
      FUN_00420490();
      return;
    }
    goto LAB_0041ceee;
  }
  cVar1 = FUN_0041f070();
  if (cVar1 == '\0') {
    cVar1 = FUN_0041ef00();
    if (cVar1 == '\0') {
      puVar4 = (undefined1 *)puVar5[2];
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_005ea438;
      }
      puVar6 = (undefined1 *)*puVar5;
      if (puVar6 == (undefined1 *)0x0) {
        puVar6 = &DAT_005ea438;
      }
      uVar20 = 0xc0000000;
      uVar19 = 0xc0000000;
      uVar18 = 0xffffffff;
      uVar17 = 0xffffffff;
      uVar16 = 0xffffffff;
      uVar14 = FUN_00415230(puVar6,puVar4);
      uVar15 = 0x183;
LAB_0041ced0:
      FUN_004144f0(uVar15,uVar14,uVar16,uVar17,uVar18,uVar19,uVar20);
    }
    else {
      cVar1 = FUN_0041f100();
      if (cVar1 == '\0') {
        cVar1 = FUN_0041f190();
        if ((cVar1 == '\0') || (iVar2 = DAT_008ac48c * 0x18c + DAT_008ac490, iVar2 == 0)) {
          cVar1 = FUN_0041f180();
          if ((cVar1 == '\0') || (iVar2 = DAT_008ac48c * 0x18c + DAT_008ac490, iVar2 == 0)) {
            cVar1 = FUN_0041f150();
            if (cVar1 == '\0') {
              puVar4 = (undefined1 *)puVar5[2];
              if (puVar4 == (undefined1 *)0x0) {
                puVar4 = &DAT_005ea438;
              }
              puVar6 = (undefined1 *)*puVar5;
              if (puVar6 == (undefined1 *)0x0) {
                puVar6 = &DAT_005ea438;
              }
              uVar20 = 0xc0000000;
              uVar19 = 0xc0000000;
              uVar18 = 0xffffffff;
              uVar17 = 0xffffffff;
              uVar16 = 1;
              uVar14 = FUN_00415230(puVar6,puVar4);
              uVar15 = 0x18d;
              goto LAB_0041ced0;
            }
            iVar2 = FUN_0041f040();
            if (iVar2 == 2) {
              local_24 = 0x18a;
            }
            else if (iVar2 == 3) {
              local_24 = 0x18b;
            }
            else if (iVar2 == 4) {
              local_24 = 0x18c;
            }
            puVar4 = (undefined1 *)puVar5[2];
            if (puVar4 == (undefined1 *)0x0) {
              puVar4 = &DAT_005ea438;
            }
            puVar6 = (undefined1 *)*puVar5;
            if (puVar6 == (undefined1 *)0x0) {
              puVar6 = &DAT_005ea438;
            }
            uVar19 = 0xc0000000;
            uVar18 = 0xc0000000;
            uVar17 = 0xffffffff;
            uVar16 = 0xffffffff;
            uVar14 = FUN_004155d0(DAT_008ac48c * 0x18c + 0x104 + DAT_008ac490);
            uVar15 = FUN_00415230(puVar6,puVar4);
            FUN_004144f0(local_24,uVar15,uVar14,uVar16,uVar17,uVar18,uVar19);
          }
          else {
            puVar4 = (undefined1 *)puVar5[2];
            if (puVar4 == (undefined1 *)0x0) {
              puVar4 = &DAT_005ea438;
            }
            puVar6 = (undefined1 *)*puVar5;
            if (puVar6 == (undefined1 *)0x0) {
              puVar6 = &DAT_005ea438;
            }
            uVar19 = 0xc0000000;
            uVar18 = 0xc0000000;
            uVar17 = 0xffffffff;
            uVar16 = 0xffffffff;
            uVar14 = FUN_004155d0(iVar2 + 0x104);
            uVar15 = FUN_00415230(puVar6,puVar4);
            FUN_004144f0(0x189,uVar15,uVar14,uVar16,uVar17,uVar18,uVar19);
          }
        }
        else {
          puVar4 = (undefined1 *)puVar5[2];
          if (puVar4 == (undefined1 *)0x0) {
            puVar4 = &DAT_005ea438;
          }
          puVar6 = (undefined1 *)*puVar5;
          if (puVar6 == (undefined1 *)0x0) {
            puVar6 = &DAT_005ea438;
          }
          uVar19 = 0xc0000000;
          uVar18 = 0xc0000000;
          uVar17 = 0xffffffff;
          uVar16 = 0xffffffff;
          uVar14 = FUN_004155d0(iVar2 + 0x104);
          uVar15 = FUN_00415230(puVar6,puVar4);
          FUN_004144f0(0x188,uVar15,uVar14,uVar16,uVar17,uVar18,uVar19);
        }
      }
      else {
        puVar4 = (undefined1 *)puVar5[2];
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_005ea438;
        }
        puVar6 = (undefined1 *)*puVar5;
        if (puVar6 == (undefined1 *)0x0) {
          puVar6 = &DAT_005ea438;
        }
        uVar19 = 0xc0000000;
        uVar18 = 0xc0000000;
        uVar17 = 0xffffffff;
        uVar16 = 0xffffffff;
        uVar15 = 0xffffffff;
        uVar14 = FUN_00415230(puVar6,puVar4);
        FUN_004144f0(0x187,uVar14,uVar15,uVar16,uVar17,uVar18,uVar19);
      }
    }
  }
  else {
    puVar4 = (undefined1 *)puVar5[2];
    if (puVar4 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    puVar6 = (undefined1 *)*puVar5;
    if (puVar6 == (undefined1 *)0x0) {
      puVar6 = &DAT_005ea438;
    }
    uVar19 = 0xc0000000;
    uVar18 = 0xc0000000;
    uVar17 = 0xffffffff;
    uVar16 = 0xffffffff;
    uVar15 = 0xffffffff;
    uVar14 = FUN_00415230(puVar6,puVar4);
    FUN_004144f0(0x182,uVar14,uVar15,uVar16,uVar17,uVar18,uVar19);
  }
  FUN_00418560(local_20);
  FUN_004203f0();
LAB_0041ceee:
  FUN_00420490();
  return;
}


