// Function: FUN_0041daf0 @ 0041daf0
// Strings:  [F1_2002.gdb, F1_2002.gdb, F1_2001.gdb, F1_2001.gdb, F1_2000.gdb, F1_2000.gdb, F1_1999.gdb, F1_1999.gdb]


void FUN_0041daf0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined1 *puVar11;
  undefined4 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined1 local_20 [32];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  FUN_004144d0();
  FUN_004144f0(0x1de,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
  FUN_00418560(local_20);
  FUN_004144d0();
  puVar2 = (undefined4 *)FUN_0041e920();
  puVar3 = (undefined4 *)FUN_0041eb30();
  FUN_004c2850();
  iVar4 = FUN_004c11d0();
  if (iVar4 == 1) {
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
LAB_0041db90:
    puVar5 = (undefined1 *)puVar2[2];
LAB_0041db93:
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    puVar11 = (undefined1 *)*puVar2;
    if (puVar11 == (undefined1 *)0x0) {
      puVar11 = &DAT_005ea438;
    }
    uVar20 = 0xc0000000;
    uVar19 = 0xc0000000;
    uVar18 = 0xffffffff;
    uVar17 = 0xffffffff;
    uVar16 = 0xffffffff;
    uVar6 = FUN_00415230(puVar11,puVar5);
    uVar15 = 0x1df;
  }
  else {
    iVar4 = FUN_004c2850();
    if (*(int *)(iVar4 + 0xb144) == 3) {
      if (puVar2 != (undefined4 *)0x0) {
        puVar5 = DAT_007d0434;
        if (DAT_007d0434 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        iVar4 = FUN_00588410(puVar5,s_F1_1999_gdb_005bf994);
        if (iVar4 == 0) {
          puVar5 = (undefined1 *)puVar2[2];
          if (puVar5 == (undefined1 *)0x0) {
            puVar5 = &DAT_005ea438;
          }
          puVar11 = (undefined1 *)*puVar2;
          if (puVar11 == (undefined1 *)0x0) {
            puVar11 = &DAT_005ea438;
          }
          uVar20 = 0xc0000000;
          uVar19 = 0xc0000000;
          uVar18 = 0xffffffff;
          uVar17 = 0xffffffff;
          uVar16 = 0xffffffff;
          uVar6 = FUN_00415230(puVar11,puVar5);
          uVar15 = 0x1ea;
        }
        else {
          puVar5 = DAT_007d0434;
          if (DAT_007d0434 == (undefined1 *)0x0) {
            puVar5 = &DAT_005ea438;
          }
          iVar4 = FUN_00588410(puVar5,s_F1_2000_gdb_005bf988);
          if (iVar4 == 0) {
            puVar5 = (undefined1 *)puVar2[2];
            if (puVar5 == (undefined1 *)0x0) {
              puVar5 = &DAT_005ea438;
            }
            puVar11 = (undefined1 *)*puVar2;
            if (puVar11 == (undefined1 *)0x0) {
              puVar11 = &DAT_005ea438;
            }
            uVar20 = 0xc0000000;
            uVar19 = 0xc0000000;
            uVar18 = 0xffffffff;
            uVar17 = 0xffffffff;
            uVar16 = 0xffffffff;
            uVar6 = FUN_00415230(puVar11,puVar5);
            uVar15 = 0x1ee;
          }
          else {
            puVar5 = DAT_007d0434;
            if (DAT_007d0434 == (undefined1 *)0x0) {
              puVar5 = &DAT_005ea438;
            }
            iVar4 = FUN_00588410(puVar5,s_F1_2001_gdb_005bf97c);
            if (iVar4 == 0) {
              puVar5 = (undefined1 *)puVar2[2];
              if (puVar5 == (undefined1 *)0x0) {
                puVar5 = &DAT_005ea438;
              }
              puVar11 = (undefined1 *)*puVar2;
              if (puVar11 == (undefined1 *)0x0) {
                puVar11 = &DAT_005ea438;
              }
              uVar20 = 0xc0000000;
              uVar19 = 0xc0000000;
              uVar18 = 0xffffffff;
              uVar17 = 0xffffffff;
              uVar16 = 0xffffffff;
              uVar6 = FUN_00415230(puVar11,puVar5);
              uVar15 = 0x1f2;
            }
            else {
              puVar5 = DAT_007d0434;
              if (DAT_007d0434 == (undefined1 *)0x0) {
                puVar5 = &DAT_005ea438;
              }
              iVar4 = FUN_00588410(puVar5,s_F1_2002_gdb_005bf970);
              if (iVar4 != 0) goto LAB_0041e2f8;
              puVar5 = (undefined1 *)puVar2[2];
              if (puVar5 == (undefined1 *)0x0) {
                puVar5 = &DAT_005ea438;
              }
              puVar11 = (undefined1 *)*puVar2;
              if (puVar11 == (undefined1 *)0x0) {
                puVar11 = &DAT_005ea438;
              }
              uVar20 = 0xc0000000;
              uVar19 = 0xc0000000;
              uVar18 = 0xffffffff;
              uVar17 = 0xffffffff;
              uVar16 = 0xffffffff;
              uVar6 = FUN_00415230(puVar11,puVar5);
              uVar15 = 0x1f6;
            }
          }
        }
        goto LAB_0041e2ef;
      }
      puVar2 = (undefined4 *)0x0;
      puVar3 = (undefined4 *)0x0;
      FUN_004c2850();
      iVar4 = FUN_004c1390();
      if (*(int *)(iVar4 + 0x19c) == 0) {
        FUN_004c2850();
        puVar2 = (undefined4 *)FUN_004c1390();
      }
      iVar7 = 0;
      FUN_004c2850();
      iVar4 = FUN_004c1370();
      puVar12 = puVar2;
      if (0 < iVar4) {
        do {
          iVar4 = iVar7;
          FUN_004c2850(iVar7);
          iVar4 = FUN_004c13a0(iVar4);
          puVar2 = puVar12;
          if (*(int *)(iVar4 + 0x19c) == 0) {
            iVar4 = iVar7;
            FUN_004c2850(iVar7);
            puVar2 = (undefined4 *)FUN_004c13a0(iVar4);
            if (puVar12 != (undefined4 *)0x0) {
              puVar2 = (undefined4 *)FUN_0041ef40();
              if (puVar2 == puVar12) {
                iVar4 = iVar7;
                FUN_004c2850(iVar7);
                FUN_004c13a0(iVar4);
                puVar10 = (undefined4 *)FUN_0041ef40();
                puVar2 = puVar12;
                if (puVar10 != puVar3) {
                  iVar4 = iVar7;
                  FUN_004c2850(iVar7);
                  puVar3 = (undefined4 *)FUN_004c13a0(iVar4);
                }
              }
              else {
                iVar4 = iVar7;
                FUN_004c2850();
                puVar2 = (undefined4 *)FUN_004c13a0(iVar4);
                puVar3 = puVar12;
              }
            }
          }
          iVar7 = iVar7 + 1;
          FUN_004c2850();
          iVar4 = FUN_004c1370();
          puVar12 = puVar2;
        } while (iVar7 < iVar4);
      }
      if (puVar2 == (undefined4 *)0x0) goto LAB_0041e2f8;
      puVar5 = DAT_007d0434;
      if (DAT_007d0434 == (undefined1 *)0x0) {
        puVar5 = &DAT_005ea438;
      }
      iVar4 = FUN_00588410(puVar5,s_F1_1999_gdb_005bf994);
      if (iVar4 == 0) {
        if (puVar3 == (undefined4 *)0x0) {
          puVar5 = (undefined1 *)puVar2[2];
          if (puVar5 == (undefined1 *)0x0) {
            puVar5 = &DAT_005ea438;
          }
          puVar11 = (undefined1 *)*puVar2;
          if (puVar11 == (undefined1 *)0x0) {
            puVar11 = &DAT_005ea438;
          }
          uVar20 = 0xc0000000;
          uVar19 = 0xc0000000;
          uVar18 = 0xffffffff;
          uVar17 = 0xffffffff;
          uVar6 = 0xffffffff;
          uVar15 = FUN_00415230(puVar11,puVar5);
          uVar16 = 0x1ea;
        }
        else {
          puVar5 = (undefined1 *)puVar3[2];
          if (puVar5 == (undefined1 *)0x0) {
            puVar5 = &DAT_005ea438;
          }
          puVar11 = (undefined1 *)*puVar3;
          if (puVar11 == (undefined1 *)0x0) {
            puVar11 = &DAT_005ea438;
          }
          puVar13 = (undefined1 *)puVar2[2];
          if (puVar13 == (undefined1 *)0x0) {
            puVar13 = &DAT_005ea438;
          }
          puVar14 = (undefined1 *)*puVar2;
          if (puVar14 == (undefined1 *)0x0) {
            puVar14 = &DAT_005ea438;
          }
          uVar20 = 0xc0000000;
          uVar19 = 0xc0000000;
          uVar18 = 0xffffffff;
          uVar17 = 0xffffffff;
          uVar6 = FUN_00415230(puVar11,puVar5);
          uVar15 = FUN_00415230(puVar14,puVar13);
          uVar16 = 0x1eb;
        }
LAB_0041e152:
        FUN_004144f0(uVar16,uVar15,uVar6,uVar17,uVar18,uVar19,uVar20);
      }
      else {
        puVar5 = DAT_007d0434;
        if (DAT_007d0434 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        iVar4 = FUN_00588410(puVar5,s_F1_2000_gdb_005bf988);
        if (iVar4 == 0) {
          if (puVar3 == (undefined4 *)0x0) {
            puVar5 = (undefined1 *)puVar2[2];
            if (puVar5 == (undefined1 *)0x0) {
              puVar5 = &DAT_005ea438;
            }
            puVar11 = (undefined1 *)*puVar2;
            if (puVar11 == (undefined1 *)0x0) {
              puVar11 = &DAT_005ea438;
            }
            uVar20 = 0xc0000000;
            uVar19 = 0xc0000000;
            uVar18 = 0xffffffff;
            uVar17 = 0xffffffff;
            uVar6 = 0xffffffff;
            uVar15 = FUN_00415230(puVar11,puVar5);
            uVar16 = 0x1ee;
          }
          else {
            puVar5 = (undefined1 *)puVar3[2];
            if (puVar5 == (undefined1 *)0x0) {
              puVar5 = &DAT_005ea438;
            }
            puVar11 = (undefined1 *)*puVar3;
            if (puVar11 == (undefined1 *)0x0) {
              puVar11 = &DAT_005ea438;
            }
            puVar13 = (undefined1 *)puVar2[2];
            if (puVar13 == (undefined1 *)0x0) {
              puVar13 = &DAT_005ea438;
            }
            puVar14 = (undefined1 *)*puVar2;
            if (puVar14 == (undefined1 *)0x0) {
              puVar14 = &DAT_005ea438;
            }
            uVar20 = 0xc0000000;
            uVar19 = 0xc0000000;
            uVar18 = 0xffffffff;
            uVar17 = 0xffffffff;
            uVar6 = FUN_00415230(puVar11,puVar5);
            uVar15 = FUN_00415230(puVar14,puVar13);
            uVar16 = 0x1ef;
          }
          goto LAB_0041e152;
        }
        puVar5 = DAT_007d0434;
        if (DAT_007d0434 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        iVar4 = FUN_00588410(puVar5,s_F1_2001_gdb_005bf97c);
        if (iVar4 == 0) {
          if (puVar3 == (undefined4 *)0x0) {
            puVar5 = (undefined1 *)puVar2[2];
            if (puVar5 == (undefined1 *)0x0) {
              puVar5 = &DAT_005ea438;
            }
            puVar11 = (undefined1 *)*puVar2;
            if (puVar11 == (undefined1 *)0x0) {
              puVar11 = &DAT_005ea438;
            }
            uVar20 = 0xc0000000;
            uVar19 = 0xc0000000;
            uVar18 = 0xffffffff;
            uVar17 = 0xffffffff;
            uVar6 = 0xffffffff;
            uVar15 = FUN_00415230(puVar11,puVar5);
            uVar16 = 0x1f2;
          }
          else {
            puVar5 = (undefined1 *)puVar3[2];
            if (puVar5 == (undefined1 *)0x0) {
              puVar5 = &DAT_005ea438;
            }
            puVar11 = (undefined1 *)*puVar3;
            if (puVar11 == (undefined1 *)0x0) {
              puVar11 = &DAT_005ea438;
            }
            puVar13 = (undefined1 *)puVar2[2];
            if (puVar13 == (undefined1 *)0x0) {
              puVar13 = &DAT_005ea438;
            }
            puVar14 = (undefined1 *)*puVar2;
            if (puVar14 == (undefined1 *)0x0) {
              puVar14 = &DAT_005ea438;
            }
            uVar20 = 0xc0000000;
            uVar19 = 0xc0000000;
            uVar18 = 0xffffffff;
            uVar17 = 0xffffffff;
            uVar6 = FUN_00415230(puVar11,puVar5);
            uVar15 = FUN_00415230(puVar14,puVar13);
            uVar16 = 499;
          }
          goto LAB_0041e152;
        }
        puVar5 = DAT_007d0434;
        if (DAT_007d0434 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        iVar4 = FUN_00588410(puVar5,s_F1_2002_gdb_005bf970);
        if (iVar4 == 0) {
          if (puVar3 == (undefined4 *)0x0) {
            puVar5 = (undefined1 *)puVar2[2];
            if (puVar5 == (undefined1 *)0x0) {
              puVar5 = &DAT_005ea438;
            }
            puVar11 = (undefined1 *)*puVar2;
            if (puVar11 == (undefined1 *)0x0) {
              puVar11 = &DAT_005ea438;
            }
            uVar20 = 0xc0000000;
            uVar19 = 0xc0000000;
            uVar18 = 0xffffffff;
            uVar17 = 0xffffffff;
            uVar6 = 0xffffffff;
            uVar15 = FUN_00415230(puVar11,puVar5);
            uVar16 = 0x1f6;
          }
          else {
            puVar5 = (undefined1 *)puVar3[2];
            if (puVar5 == (undefined1 *)0x0) {
              puVar5 = &DAT_005ea438;
            }
            puVar11 = (undefined1 *)*puVar3;
            if (puVar11 == (undefined1 *)0x0) {
              puVar11 = &DAT_005ea438;
            }
            puVar13 = (undefined1 *)puVar2[2];
            if (puVar13 == (undefined1 *)0x0) {
              puVar13 = &DAT_005ea438;
            }
            puVar14 = (undefined1 *)*puVar2;
            if (puVar14 == (undefined1 *)0x0) {
              puVar14 = &DAT_005ea438;
            }
            uVar20 = 0xc0000000;
            uVar19 = 0xc0000000;
            uVar18 = 0xffffffff;
            uVar17 = 0xffffffff;
            uVar6 = FUN_00415230(puVar11,puVar5);
            uVar15 = FUN_00415230(puVar14,puVar13);
            uVar16 = 0x1f7;
          }
          goto LAB_0041e152;
        }
      }
      FUN_00418560(local_20);
      goto LAB_0041e2f8;
    }
    if (puVar2 == (undefined4 *)0x0) goto LAB_0041e2f8;
    if ((puVar3 == (undefined4 *)0x0) &&
       (puVar3 = (undefined4 *)FUN_0041eb30(), puVar3 == (undefined4 *)0x0)) goto LAB_0041db90;
    if (puVar2 == puVar3) {
      iVar4 = puVar2[0x66];
      iVar7 = FUN_0041e920();
      iVar7 = *(int *)(iVar7 + 0x198);
      iVar8 = FUN_0041ed30();
      iVar9 = FUN_0041ed30();
      puVar5 = (undefined1 *)puVar2[2];
      if (iVar9 - iVar8 < iVar4 - iVar7) {
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        puVar11 = (undefined1 *)*puVar2;
        if (puVar11 == (undefined1 *)0x0) {
          puVar11 = &DAT_005ea438;
        }
        uVar20 = 0xc0000000;
        uVar19 = 0xc0000000;
        uVar18 = 0xffffffff;
        uVar17 = 0xffffffff;
        uVar16 = 0xffffffff;
        uVar6 = FUN_00415230(puVar11,puVar5);
        uVar15 = 0x1e1;
      }
      else {
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        puVar11 = (undefined1 *)*puVar2;
        if (puVar11 == (undefined1 *)0x0) {
          puVar11 = &DAT_005ea438;
        }
        uVar20 = 0xc0000000;
        uVar19 = 0xc0000000;
        uVar18 = 0xffffffff;
        uVar17 = 0xffffffff;
        uVar16 = 1;
        uVar6 = FUN_00415230(puVar11,puVar5);
        uVar15 = 0x18d;
      }
    }
    else {
      cVar1 = FUN_0041eda0();
      puVar5 = (undefined1 *)puVar2[2];
      if (cVar1 == '\0') goto LAB_0041db93;
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_005ea438;
      }
      puVar11 = (undefined1 *)*puVar2;
      if (puVar11 == (undefined1 *)0x0) {
        puVar11 = &DAT_005ea438;
      }
      uVar20 = 0xc0000000;
      uVar19 = 0xc0000000;
      uVar18 = 0xffffffff;
      uVar17 = 0xffffffff;
      uVar16 = 0xffffffff;
      uVar6 = FUN_00415230(puVar11,puVar5);
      uVar15 = 0x1e0;
    }
  }
LAB_0041e2ef:
  FUN_004144f0(uVar15,uVar6,uVar16,uVar17,uVar18,uVar19,uVar20);
LAB_0041e2f8:
  FUN_00418560(local_20);
  FUN_00420490();
  return;
}


