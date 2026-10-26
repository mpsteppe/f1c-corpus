// Function: FUN_00420cf0 @ 00420cf0
// Strings:  [F1_2002.gdb, F1_2001.gdb, F1_2000.gdb, F1_1999.gdb, TOYOTA, TOYOTA, TOYOTA, STEWART]


/* WARNING: Removing unreachable block (ram,0x00420f67) */
/* WARNING: Removing unreachable block (ram,0x00421049) */
/* WARNING: Removing unreachable block (ram,0x00420e6a) */
/* WARNING: Removing unreachable block (ram,0x00420d78) */

void __fastcall FUN_00420cf0(int *param_1)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  char *pcVar16;
  undefined4 uVar17;
  undefined1 *local_a8;
  int *local_9c;
  int local_98;
  undefined1 local_90 [32];
  int local_70 [14];
  int local_38 [14];
  
  iVar9 = 0;
  bVar2 = false;
  if (param_1 == (int *)0x0) {
    local_9c = operator_new(8);
    if (local_9c == (int *)0x0) {
      local_9c = (int *)0x0;
    }
    else {
      *local_9c = 0;
      local_9c[1] = -1;
    }
    iVar8 = -1;
    piVar3 = local_38;
    for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
      *piVar3 = 0;
      piVar3 = piVar3 + 1;
    }
    piVar3 = local_70;
    for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
      *piVar3 = 0;
      piVar3 = piVar3 + 1;
    }
    bVar2 = true;
    local_98 = 0;
    bVar1 = false;
    local_a8 = (undefined1 *)0x0;
    piVar3 = (int *)FUN_0041f340();
    if (piVar3 == (int *)0x0) {
      return;
    }
    iVar7 = FUN_0041f220();
    iVar10 = 0;
    do {
      switch(iVar10) {
      case 0:
        pcVar16 = s_ARROWS_005c25f4;
        break;
      case 1:
        pcVar16 = (char *)&PTR_DAT_005c25e0;
        break;
      case 2:
        pcVar16 = s_RENAULT_005c25c4;
        break;
      case 3:
        pcVar16 = s_FERRARI_005c2618;
        break;
      case 4:
        pcVar16 = s_JAGUAR_005c25d8;
        break;
      case 5:
        pcVar16 = s_JORDAN_005c2604;
        break;
      case 6:
        pcVar16 = s_MCLAREN_005c2620;
        break;
      case 7:
        pcVar16 = s_MINARDI_005c25e4;
        break;
      case 8:
        pcVar16 = s_PROST_005c25ec;
        break;
      case 9:
        pcVar16 = s_SAUBER_005c25fc;
        break;
      case 10:
        pcVar16 = s_WILLIAMS_005c260c;
        break;
      case 0xb:
        pcVar16 = s_TOYOTA_005c25b4;
        break;
      case 0xc:
        pcVar16 = s_BENETTON_005c25cc;
        break;
      case 0xd:
        pcVar16 = s_STEWART_005c25bc;
        break;
      default:
        goto switchD_00420da8_default;
      }
      FUN_00566650(pcVar16);
switchD_00420da8_default:
      iVar4 = FUN_0041f220();
      if (iVar4 == iVar7) {
        iVar4 = FUN_00421380();
        local_70[iVar10] = iVar4;
        if (iVar9 < iVar4) {
          iVar8 = iVar10;
          iVar9 = iVar4;
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < 0xe);
    if (iVar8 == -1) {
      return;
    }
    iVar7 = 0;
    do {
      if ((iVar8 != iVar7) && (local_70[iVar7] == iVar9)) {
        bVar1 = true;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0xe);
    if (bVar1) {
      bVar1 = false;
      iVar8 = -1;
      iVar7 = 0;
      do {
        if (local_70[iVar7] == iVar9) {
          switch(iVar7) {
          case 0:
            pcVar16 = s_ARROWS_005c25f4;
            break;
          case 1:
            pcVar16 = (char *)&PTR_DAT_005c25e0;
            break;
          case 2:
            pcVar16 = s_RENAULT_005c25c4;
            break;
          case 3:
            pcVar16 = s_FERRARI_005c2618;
            break;
          case 4:
            pcVar16 = s_JAGUAR_005c25d8;
            break;
          case 5:
            pcVar16 = s_JORDAN_005c2604;
            break;
          case 6:
            pcVar16 = s_MCLAREN_005c2620;
            break;
          case 7:
            pcVar16 = s_MINARDI_005c25e4;
            break;
          case 8:
            pcVar16 = s_PROST_005c25ec;
            break;
          case 9:
            pcVar16 = s_SAUBER_005c25fc;
            break;
          case 10:
            pcVar16 = s_WILLIAMS_005c260c;
            break;
          case 0xb:
            pcVar16 = s_TOYOTA_005c25b4;
            break;
          case 0xc:
            pcVar16 = s_BENETTON_005c25cc;
            break;
          case 0xd:
            pcVar16 = s_STEWART_005c25bc;
            break;
          default:
            goto switchD_00420eb7_default;
          }
          FUN_00566650(pcVar16);
switchD_00420eb7_default:
          iVar10 = FUN_004212e0();
          local_38[iVar7] = iVar10;
          if (local_98 < iVar10) {
            iVar8 = iVar7;
            local_98 = iVar10;
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0xe);
      if (iVar8 == -1) {
        return;
      }
      iVar9 = 0;
      do {
        if ((iVar8 != iVar9) && (local_38[iVar9] == local_98)) {
          bVar1 = true;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0xe);
      if (bVar1) {
        local_a8 = (undefined1 *)*piVar3;
      }
      else {
        switch(iVar8) {
        case 0:
          goto switchD_00420fae_caseD_0;
        case 1:
          goto switchD_00420fae_caseD_1;
        case 2:
          goto switchD_00420fae_caseD_2;
        case 3:
          goto switchD_00420fae_caseD_3;
        case 4:
          goto switchD_00420fae_caseD_4;
        case 5:
          goto switchD_00420fae_caseD_5;
        case 6:
          goto switchD_00420fae_caseD_6;
        case 7:
          goto switchD_00420fae_caseD_7;
        case 8:
          goto switchD_00420fae_caseD_8;
        case 9:
          goto switchD_00420fae_caseD_9;
        case 10:
          goto switchD_00420fae_caseD_a;
        case 0xb:
          goto switchD_00420fae_caseD_b;
        case 0xc:
          goto switchD_00420fae_caseD_c;
        case 0xd:
          goto switchD_00420fae_caseD_d;
        }
      }
    }
    else {
      switch(iVar8) {
      case 0:
switchD_00420fae_caseD_0:
        pcVar16 = s_ARROWS_005c25f4;
        break;
      case 1:
switchD_00420fae_caseD_1:
        pcVar16 = (char *)&PTR_DAT_005c25e0;
        break;
      case 2:
switchD_00420fae_caseD_2:
        pcVar16 = s_RENAULT_005c25c4;
        break;
      case 3:
switchD_00420fae_caseD_3:
        pcVar16 = s_FERRARI_005c2618;
        break;
      case 4:
switchD_00420fae_caseD_4:
        pcVar16 = s_JAGUAR_005c25d8;
        break;
      case 5:
switchD_00420fae_caseD_5:
        pcVar16 = s_JORDAN_005c2604;
        break;
      case 6:
switchD_00420fae_caseD_6:
        pcVar16 = s_MCLAREN_005c2620;
        break;
      case 7:
switchD_00420fae_caseD_7:
        pcVar16 = s_MINARDI_005c25e4;
        break;
      case 8:
switchD_00420fae_caseD_8:
        pcVar16 = s_PROST_005c25ec;
        break;
      case 9:
switchD_00420fae_caseD_9:
        pcVar16 = s_SAUBER_005c25fc;
        break;
      case 10:
switchD_00420fae_caseD_a:
        pcVar16 = s_WILLIAMS_005c260c;
        break;
      case 0xb:
switchD_00420fae_caseD_b:
        pcVar16 = s_TOYOTA_005c25b4;
        break;
      case 0xc:
switchD_00420fae_caseD_c:
        pcVar16 = s_BENETTON_005c25cc;
        break;
      case 0xd:
switchD_00420fae_caseD_d:
        pcVar16 = s_STEWART_005c25bc;
        break;
      default:
        goto switchD_00420fae_default;
      }
      FUN_00566650(pcVar16);
    }
switchD_00420fae_default:
    if (local_a8 == (undefined1 *)0x0) {
      local_a8 = &DAT_005ea438;
    }
    FUN_00566650(local_a8);
    if (*piVar3 != 0) {
      FUN_00587bcf(*piVar3);
    }
    FUN_00587bcf(piVar3);
    param_1 = local_9c;
  }
  FUN_004144d0();
  puVar5 = DAT_007d0434;
  if (DAT_007d0434 == (undefined1 *)0x0) {
    puVar5 = &DAT_005ea438;
  }
  iVar9 = FUN_00588410(puVar5,s_F1_1999_gdb_005bf994);
  if (iVar9 == 0) {
    puVar5 = (undefined1 *)*param_1;
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    uVar17 = 0xc0000000;
    uVar15 = 0xc0000000;
    uVar14 = 0xffffffff;
    uVar13 = 0xffffffff;
    uVar12 = 0xffffffff;
    uVar6 = FUN_00415550(puVar5);
    uVar11 = 0x1ec;
  }
  else {
    puVar5 = DAT_007d0434;
    if (DAT_007d0434 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    iVar9 = FUN_00588410(puVar5,s_F1_2000_gdb_005bf988);
    if (iVar9 == 0) {
      puVar5 = (undefined1 *)*param_1;
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_005ea438;
      }
      uVar17 = 0xc0000000;
      uVar15 = 0xc0000000;
      uVar14 = 0xffffffff;
      uVar13 = 0xffffffff;
      uVar12 = 0xffffffff;
      uVar6 = FUN_00415550(puVar5);
      uVar11 = 0x1f0;
    }
    else {
      puVar5 = DAT_007d0434;
      if (DAT_007d0434 == (undefined1 *)0x0) {
        puVar5 = &DAT_005ea438;
      }
      iVar9 = FUN_00588410(puVar5,s_F1_2001_gdb_005bf97c);
      if (iVar9 == 0) {
        puVar5 = (undefined1 *)*param_1;
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        uVar17 = 0xc0000000;
        uVar15 = 0xc0000000;
        uVar14 = 0xffffffff;
        uVar13 = 0xffffffff;
        uVar12 = 0xffffffff;
        uVar6 = FUN_00415550(puVar5);
        uVar11 = 500;
      }
      else {
        puVar5 = DAT_007d0434;
        if (DAT_007d0434 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        iVar9 = FUN_00588410(puVar5,s_F1_2002_gdb_005bf970);
        if (iVar9 != 0) goto LAB_004211c6;
        puVar5 = (undefined1 *)*param_1;
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        uVar17 = 0xc0000000;
        uVar15 = 0xc0000000;
        uVar14 = 0xffffffff;
        uVar13 = 0xffffffff;
        uVar12 = 0xffffffff;
        uVar6 = FUN_00415550(puVar5);
        uVar11 = 0x1f8;
      }
    }
  }
  FUN_004144f0(uVar11,uVar6,uVar12,uVar13,uVar14,uVar15,uVar17);
LAB_004211c6:
  FUN_00418560(local_90);
  if ((bVar2) && (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      FUN_00587bcf(*param_1);
    }
    FUN_00587bcf(param_1);
  }
  return;
}


