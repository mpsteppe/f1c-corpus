// Function: FUN_00420820 @ 00420820
// Strings:  [TOYOTA, TOYOTA, TOYOTA, STEWART, STEWART, STEWART, RENAULT, RENAULT]


/* WARNING: Removing unreachable block (ram,0x00420c22) */
/* WARNING: Removing unreachable block (ram,0x00420c11) */
/* WARNING: Removing unreachable block (ram,0x00420c33) */

void __fastcall FUN_00420820(char param_1)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  char *pcVar13;
  undefined4 uVar14;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  undefined1 local_58 [32];
  int local_38 [14];
  
  iVar7 = 0;
  local_68 = -1;
  local_5c = -1;
  local_60 = -1;
  iVar6 = -1;
  local_64 = -1;
  piVar8 = local_38;
  for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar8 = 0;
    piVar8 = piVar8 + 1;
  }
  do {
    switch(iVar7) {
    case 0:
      pcVar13 = s_ARROWS_005c25f4;
      break;
    case 1:
      pcVar13 = (char *)&PTR_DAT_005c25e0;
      break;
    case 2:
      pcVar13 = s_RENAULT_005c25c4;
      break;
    case 3:
      pcVar13 = s_FERRARI_005c2618;
      break;
    case 4:
      pcVar13 = s_JAGUAR_005c25d8;
      break;
    case 5:
      pcVar13 = s_JORDAN_005c2604;
      break;
    case 6:
      pcVar13 = s_MCLAREN_005c2620;
      break;
    case 7:
      pcVar13 = s_MINARDI_005c25e4;
      break;
    case 8:
      pcVar13 = s_PROST_005c25ec;
      break;
    case 9:
      pcVar13 = s_SAUBER_005c25fc;
      break;
    case 10:
      pcVar13 = s_WILLIAMS_005c260c;
      break;
    case 0xb:
      pcVar13 = s_TOYOTA_005c25b4;
      break;
    case 0xc:
      pcVar13 = s_BENETTON_005c25cc;
      break;
    case 0xd:
      pcVar13 = s_STEWART_005c25bc;
      break;
    default:
      goto LAB_004208f2;
    }
    FUN_00566650(pcVar13);
LAB_004208f2:
    iVar5 = FUN_0041f220();
    local_38[iVar7] = iVar5;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0xe);
  iVar7 = 0;
  iVar5 = -1;
  do {
    if (iVar5 < local_38[iVar7]) {
      iVar5 = local_38[iVar7];
      local_68 = iVar7;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0xe);
  iVar7 = 0;
  do {
    if (((iVar7 != local_68) && (iVar1 = local_38[iVar7], iVar6 < iVar1)) && (iVar1 < iVar5)) {
      iVar6 = iVar1;
      local_5c = iVar7;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0xe);
  bVar3 = false;
  iVar5 = 0;
  do {
    if ((iVar5 != local_5c) && (local_38[local_5c] == local_38[iVar5])) {
      bVar3 = true;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xe);
  if ((!bVar3) && (local_5c != -1)) {
    switch(local_5c) {
    case 0:
      pcVar13 = s_ARROWS_005c25f4;
      break;
    case 1:
      pcVar13 = (char *)&PTR_DAT_005c25e0;
      break;
    case 2:
      pcVar13 = s_RENAULT_005c25c4;
      break;
    case 3:
      pcVar13 = s_FERRARI_005c2618;
      break;
    case 4:
      pcVar13 = s_JAGUAR_005c25d8;
      break;
    case 5:
      pcVar13 = s_JORDAN_005c2604;
      break;
    case 6:
      pcVar13 = s_MCLAREN_005c2620;
      break;
    case 7:
      pcVar13 = s_MINARDI_005c25e4;
      break;
    case 8:
      pcVar13 = s_PROST_005c25ec;
      break;
    case 9:
      pcVar13 = s_SAUBER_005c25fc;
      break;
    case 10:
      pcVar13 = s_WILLIAMS_005c260c;
      break;
    case 0xb:
      pcVar13 = s_TOYOTA_005c25b4;
      break;
    case 0xc:
      pcVar13 = s_BENETTON_005c25cc;
      break;
    case 0xd:
      pcVar13 = s_STEWART_005c25bc;
      break;
    default:
      goto switchD_00420984_default;
    }
    FUN_00566650(pcVar13);
switchD_00420984_default:
    if (param_1 != '\0') {
      FUN_004144d0();
      uVar14 = 0xc0000000;
      uVar12 = 0xc0000000;
      uVar11 = 0xffffffff;
      uVar10 = 0xffffffff;
      uVar9 = 0xffffffff;
      uVar4 = FUN_00415550(&DAT_005ea438);
      FUN_004144f0(0x1a7,uVar4,uVar9,uVar10,uVar11,uVar12,uVar14);
      FUN_00418560(local_58);
    }
  }
  iVar5 = 0;
  do {
    if ((((iVar5 != local_68) && (iVar5 != local_5c)) && (iVar7 = local_38[iVar5], local_64 < iVar7)
        ) && (iVar7 < iVar6)) {
      local_64 = iVar7;
      local_60 = iVar5;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xe);
  bVar2 = false;
  iVar6 = 0;
  do {
    if ((iVar6 != local_60) && (local_38[local_60] == local_38[iVar6])) {
      bVar2 = true;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xe);
  if (((!bVar3) && (!bVar2)) && (local_60 != -1)) {
    switch(local_60) {
    case 0:
      pcVar13 = s_ARROWS_005c25f4;
      break;
    case 1:
      pcVar13 = (char *)&PTR_DAT_005c25e0;
      break;
    case 2:
      pcVar13 = s_RENAULT_005c25c4;
      break;
    case 3:
      pcVar13 = s_FERRARI_005c2618;
      break;
    case 4:
      pcVar13 = s_JAGUAR_005c25d8;
      break;
    case 5:
      pcVar13 = s_JORDAN_005c2604;
      break;
    case 6:
      pcVar13 = s_MCLAREN_005c2620;
      break;
    case 7:
      pcVar13 = s_MINARDI_005c25e4;
      break;
    case 8:
      pcVar13 = s_PROST_005c25ec;
      break;
    case 9:
      pcVar13 = s_SAUBER_005c25fc;
      break;
    case 10:
      pcVar13 = s_WILLIAMS_005c260c;
      break;
    case 0xb:
      pcVar13 = s_TOYOTA_005c25b4;
      break;
    case 0xc:
      pcVar13 = s_BENETTON_005c25cc;
      break;
    case 0xd:
      pcVar13 = s_STEWART_005c25bc;
      break;
    default:
      goto switchD_00420aba_default;
    }
    FUN_00566650(pcVar13);
switchD_00420aba_default:
    if (param_1 == '\0') goto LAB_00420b95;
    FUN_004144d0();
    uVar14 = 0xc0000000;
    uVar12 = 0xc0000000;
    uVar11 = 0xffffffff;
    uVar10 = 0xffffffff;
    uVar9 = 0xffffffff;
    uVar4 = FUN_00415550(&DAT_005ea438);
    FUN_004144f0(0x1a8,uVar4,uVar9,uVar10,uVar11,uVar12,uVar14);
    FUN_00418560(local_58);
  }
  if (param_1 != '\0') {
    return;
  }
  if (bVar3) {
    return;
  }
  if (bVar2) {
    return;
  }
LAB_00420b95:
  if ((local_5c != -1) && (local_60 != -1)) {
    FUN_004144d0();
    uVar14 = 0xc0000000;
    uVar12 = 0xc0000000;
    uVar11 = 0xffffffff;
    uVar10 = 0xffffffff;
    uVar4 = FUN_00415550(&DAT_005ea438);
    uVar9 = FUN_00415550(&DAT_005ea438);
    FUN_004144f0(0x1e8,uVar9,uVar4,uVar10,uVar11,uVar12,uVar14);
    FUN_00418560(local_58);
  }
  return;
}


