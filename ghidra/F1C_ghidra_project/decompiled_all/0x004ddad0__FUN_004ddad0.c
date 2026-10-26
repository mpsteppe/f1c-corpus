// Function: FUN_004ddad0 @ 004ddad0
// Strings:  [TrackName, TEAM.MAS, refueler, refueler, wcrefueler, wcrefueler, wcrefueler, lollipop]


void __fastcall FUN_004ddad0(undefined4 *param_1,char *param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined1 *puVar5;
  char *pcVar6;
  int iVar7;
  char **ppcVar8;
  undefined *puVar9;
  char *pcVar10;
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  char *local_d4;
  char *local_d0;
  uint local_cc;
  int local_c8;
  char *local_c4;
  char *local_b8;
  char *local_b4;
  int local_b0;
  undefined4 *local_ac;
  char *local_a8;
  char *local_a4 [9];
  undefined1 local_80 [128];
  
  if (param_1 != (undefined4 *)0x0) {
    local_ac = param_1;
    local_a8 = param_2;
    pcVar4 = operator_new(0x100);
    *pcVar4 = '\0';
    puVar5 = (undefined1 *)*param_1;
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    FUN_00566650(puVar5);
    pcVar13 = pcVar4;
    if (pcVar4 == (char *)0x0) {
      pcVar13 = &DAT_005ea438;
    }
    uVar11 = 0xffffffff;
    pcVar6 = pcVar13;
    do {
      if (uVar11 == 0) break;
      uVar11 = uVar11 - 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    if (0 < (int)(~uVar11 - 1)) {
      for (pcVar6 = pcVar13 + (~uVar11 - 2); (pcVar13 <= pcVar6 && (*pcVar6 != '\\'));
          pcVar6 = pcVar6 + -1) {
        *pcVar6 = '\0';
      }
    }
    FUN_005665b0(s_TEAM_MAS_005cd5d8);
    local_b0 = 0;
    pcVar13 = pcVar4;
    if (pcVar4 == (char *)0x0) {
      pcVar13 = &DAT_005ea438;
    }
    FUN_0053cbc0(&local_b0,pcVar13);
    local_b8 = (char *)param_1[0xf3];
    if (local_b8 == (char *)0x0) {
      local_b8 = &DAT_005ea438;
    }
    local_b4 = (char *)param_1[0xf6];
    if (local_b4 == (char *)0x0) {
      local_b4 = &DAT_005ea438;
    }
    iVar7 = FUN_004c58a0(local_80,0x80,s_TrackName_005c6984,0);
    if (iVar7 != 0) {
      local_80[0] = 0;
    }
    puVar3 = (undefined4 *)param_1[0xf5];
    local_c4 = (char *)0x0;
    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)puVar3[4]) {
      puVar5 = (undefined1 *)*puVar3;
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_005ea438;
      }
      iVar7 = FUN_00588410(puVar5,local_80);
      if (iVar7 == 0) {
        local_c4 = (char *)puVar3[2];
        if (local_c4 == (char *)0x0) {
          local_c4 = &DAT_005ea438;
        }
        break;
      }
    }
    ppcVar8 = local_a4 + 3;
    iVar7 = 3;
    do {
      *ppcVar8 = (char *)0x0;
      ppcVar8[1] = (char *)0xffffffff;
      ppcVar8 = ppcVar8 + 2;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    local_c8 = 0;
    pcVar13 = local_d4;
    do {
      switch(local_c8) {
      case 0:
        pcVar13 = s_wccarbody_005d4cb8;
        local_d0 = &DAT_005ea438;
        local_d4 = pcVar13;
        break;
      case 1:
        pcVar13 = s_wcdriver_005d4cac;
        local_d0 = s_driver_005d4ca4;
        local_d4 = pcVar13;
        break;
      case 2:
        pcVar13 = s_wcarms_005d4c9c;
        local_d0 = &DAT_005d4c94;
        local_d4 = pcVar13;
        break;
      case 3:
        pcVar13 = s_wcwing_005d4c8c;
        local_d0 = &DAT_005d4c84;
        local_d4 = pcVar13;
        break;
      case 4:
        pcVar13 = s_wchelmet_005d4c78;
        local_d0 = s_helmet_005d4c70;
        local_d4 = pcVar13;
        break;
      case 5:
        pcVar13 = s_wcpitbody_005d4c64;
        local_d0 = s_pitbody_005d4c5c;
        local_d4 = pcVar13;
        break;
      case 6:
        pcVar13 = s_wcpithelmet_005d4c50;
        local_d0 = s_pithelmet_005d4c44;
        local_d4 = pcVar13;
        break;
      case 7:
        pcVar13 = s_wclollipop_005d4c38;
        local_d0 = s_lollipop_005d4c2c;
        local_d4 = pcVar13;
        break;
      case 8:
        pcVar13 = s_wcrefueler_005d4c20;
        local_d0 = s_refueler_005d4c14;
        local_d4 = pcVar13;
      }
      uVar11 = 0;
      local_cc = 0;
      if ((local_a8 != (char *)0x0) && (*local_a8 != '\0')) {
        uVar11 = 1;
        local_a4[0] = local_a8;
        local_cc = 1;
      }
      if ((local_c4 != (char *)0x0) && (*local_c4 != '\0')) {
        local_a4[uVar11] = local_c4;
        uVar11 = uVar11 + 1;
        local_cc = uVar11;
      }
      if ((((local_c8 == 5) || (local_c8 == 6)) || (local_c8 == 7)) || (local_c8 == 8)) {
        if (uVar11 < 3) {
          if ((local_b4 != (char *)0x0) && (*local_b4 != '\0')) {
            local_a4[uVar11] = local_b4;
            uVar11 = uVar11 + 1;
            local_cc = uVar11;
          }
          goto LAB_004ddd35;
        }
      }
      else {
LAB_004ddd35:
        if (((uVar11 < 3) && (local_b8 != (char *)0x0)) && (*local_b8 != '\0')) {
          local_a4[uVar11] = local_b8;
          uVar11 = uVar11 + 1;
          local_cc = uVar11;
        }
      }
      iVar7 = 0;
      if (uVar11 == 0) {
LAB_004dde28:
        iVar7 = 3 - iVar7;
        do {
          FUN_00566650(pcVar13);
          FUN_005665b0(&DAT_005d4c0c);
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      else {
        ppcVar8 = local_a4 + 3;
        do {
          puVar5 = (undefined1 *)*local_ac;
          if (puVar5 == (undefined1 *)0x0) {
            puVar5 = &DAT_005ea438;
          }
          FUN_00566650(puVar5);
          pcVar13 = *ppcVar8;
          if (pcVar13 == (char *)0x0) {
            pcVar13 = &DAT_005ea438;
          }
          uVar11 = 0xffffffff;
          pcVar6 = pcVar13;
          do {
            if (uVar11 == 0) break;
            uVar11 = uVar11 - 1;
            cVar2 = *pcVar6;
            pcVar6 = pcVar6 + 1;
          } while (cVar2 != '\0');
          if (0 < (int)(~uVar11 - 1)) {
            for (pcVar6 = pcVar13 + (~uVar11 - 2); (pcVar13 <= pcVar6 && (*pcVar6 != '\\'));
                pcVar6 = pcVar6 + -1) {
              *pcVar6 = '\0';
            }
          }
          pcVar13 = local_a4[iVar7];
          FUN_005665b0(pcVar13);
          pcVar6 = *ppcVar8;
          if (pcVar6 == (char *)0x0) {
            pcVar6 = &DAT_005ea438;
          }
          uVar11 = 0xffffffff;
          pcVar12 = pcVar6;
          do {
            if (uVar11 == 0) break;
            uVar11 = uVar11 - 1;
            cVar2 = *pcVar12;
            pcVar12 = pcVar12 + 1;
          } while (cVar2 != '\0');
          for (pcVar12 = pcVar6 + (~uVar11 - 1); pcVar6 < pcVar12; pcVar12 = pcVar12 + -1) {
            if (*pcVar12 == '.') {
              *pcVar12 = '\0';
              break;
            }
          }
          FUN_005665b0(local_d0);
          puVar9 = (undefined *)FUN_00589db0(pcVar13,0x2e);
          if (puVar9 == (undefined *)0x0) {
            puVar9 = &DAT_005d4c0c;
          }
          FUN_005665b0(puVar9);
          iVar7 = iVar7 + 1;
          ppcVar8 = ppcVar8 + 2;
        } while (iVar7 < (int)local_cc);
        pcVar13 = local_d4;
        if (iVar7 < 3) goto LAB_004dde28;
      }
      pcVar6 = local_a4[7];
      if (local_a4[7] == (undefined1 *)0x0) {
        pcVar6 = &DAT_005ea438;
      }
      pcVar12 = local_a4[5];
      if (local_a4[5] == (undefined1 *)0x0) {
        pcVar12 = &DAT_005ea438;
      }
      pcVar10 = local_a4[3];
      if (local_a4[3] == (undefined1 *)0x0) {
        pcVar10 = &DAT_005ea438;
      }
      iVar7 = FUN_004dc770(pcVar10,pcVar12,pcVar6,1,param_4);
      if ((local_c8 == 0) && (param_3 != 0)) {
        if ((iVar7 < 0) || (2 < iVar7)) {
          pcVar6 = &DAT_005ea438;
        }
        else {
          pcVar12 = local_a4[iVar7 * 2 + 3];
          if (pcVar12 == (char *)0x0) {
            pcVar12 = &DAT_005ea438;
          }
          uVar11 = 0xffffffff;
          pcVar6 = pcVar12;
          do {
            if (uVar11 == 0) break;
            uVar11 = uVar11 - 1;
            cVar2 = *pcVar6;
            pcVar6 = pcVar6 + 1;
          } while (cVar2 != '\0');
          for (pcVar6 = pcVar12 + (~uVar11 - 1); pcVar12 < pcVar6; pcVar6 = pcVar6 + -1) {
            if (*pcVar6 == '\\') {
              pcVar6 = pcVar6 + 1;
              break;
            }
          }
        }
        FUN_00566650(pcVar6);
      }
      local_c8 = local_c8 + 1;
    } while (local_c8 < 9);
    if (local_b0 != 0) {
      FUN_0053ce40(local_b0);
    }
    puVar5 = local_80;
    iVar7 = 3;
    do {
      piVar1 = (int *)(puVar5 + -8);
      puVar5 = puVar5 + -8;
      if (*piVar1 != 0) {
        FUN_00587bcf(*piVar1);
      }
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    if (pcVar4 != (char *)0x0) {
      FUN_00587bcf(pcVar4);
    }
  }
  return;
}


