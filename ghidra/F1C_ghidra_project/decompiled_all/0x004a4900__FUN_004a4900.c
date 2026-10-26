// Function: FUN_004a4900 @ 004a4900
// Strings:  [CMAPS.MAS, PITDIRECTOR%02d, PITCREWNORMAL%02d, PITS\NORMAL\PITCREW.SCR, PITS\LEFT\PITCREW.SCR, PITCREW10SEC%02d, PITS\10SEC\PITCREW.SCR, CDB.MAS]


void __thiscall FUN_004a4900(int *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  bool bVar8;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined1 *local_48;
  undefined4 local_44;
  undefined1 *local_40;
  undefined4 local_3c;
  char *local_38;
  undefined4 local_34;
  undefined1 local_30 [16];
  undefined1 local_20 [32];
  
  FUN_004a4db0();
  if ((DAT_008ab6e4 != 2) && ((bVar8 = *param_1 == DAT_007c54e8, bVar8 || (2 < DAT_007cf884)))) {
    FUN_004a1f60();
    FUN_004a51c0(param_2,local_30);
    local_48 = operator_new(0x100);
    *local_48 = 0;
    local_44 = 0x100;
    local_38 = (char *)0x0;
    local_34 = 0xffffffff;
    FUN_00566650(*param_1 + 0x4714);
    pcVar7 = local_38;
    if (local_38 == (char *)0x0) {
      pcVar7 = &DAT_005ea438;
    }
    uVar6 = 0xffffffff;
    pcVar2 = pcVar7;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (0 < (int)(~uVar6 - 1)) {
      for (pcVar2 = pcVar7 + (~uVar6 - 2); (pcVar7 < pcVar2 && (*pcVar2 != '\\'));
          pcVar2 = pcVar2 + -1) {
      }
      *pcVar2 = '\0';
    }
    pcVar7 = local_38;
    if (local_38 == (char *)0x0) {
      pcVar7 = &DAT_005ea438;
    }
    FUN_0053c800(pcVar7);
    local_40 = operator_new(0x100);
    *local_40 = 0;
    local_3c = 0x100;
    puVar3 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    puVar3 = DAT_005ec420;
    if (DAT_005ec420 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_005665b0(puVar3);
    FUN_005665b0(&DAT_005cd5e4);
    puVar3 = local_40;
    if (local_40 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_0053c800(puVar3);
    local_4c = 0;
    FUN_0053cbc0(&local_4c,s_TEAM_MAS_005cd5d8);
    local_50 = 0;
    FUN_0053cbc0(&local_50,s_PITS_MAS_005cd5cc);
    local_58 = 0;
    puVar3 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    puVar3 = DAT_005ec428;
    if (DAT_005ec428 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_005665b0(puVar3);
    FUN_005665b0(s_CDB_MAS_005cd5c4);
    puVar3 = local_48;
    if (local_48 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_0053cbc0(&local_58,puVar3);
    local_54 = 0;
    puVar3 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    puVar3 = DAT_005ec428;
    if (DAT_005ec428 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_005665b0(puVar3);
    FUN_005665b0(s_CMAPS_MAS_005cceb0);
    puVar3 = local_48;
    if (local_48 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_0053cbc0(&local_54,puVar3);
    puVar3 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    puVar3 = DAT_005ec420;
    if (DAT_005ec420 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_005665b0(puVar3);
    FUN_005665b0(s_PITS_10SEC_PITCREW_SCR_005cd5ac);
    FUN_0058815f(local_20,s_PITCREW10SEC_02d_005cd598,*(undefined4 *)(*param_1 + 0x4894));
    pvVar4 = operator_new(0x18);
    if (pvVar4 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004a2980();
    }
    param_1[4] = iVar5;
    puVar3 = local_48;
    if (local_48 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_004a3220(puVar3,local_30,local_20);
    puVar3 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    puVar3 = DAT_005ec420;
    if (DAT_005ec420 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_005665b0(puVar3);
    if (DAT_005ea3ec == '\0') {
      pcVar7 = s_PITS_NORMAL_PITCREW_SCR_005cd568;
    }
    else {
      pcVar7 = s_PITS_LEFT_PITCREW_SCR_005cd580;
    }
    FUN_005665b0(pcVar7);
    FUN_0058815f(local_20,s_PITCREWNORMAL_02d_005cd554,*(undefined4 *)(*param_1 + 0x4894));
    pvVar4 = operator_new(0x18);
    if (pvVar4 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_004a2980();
    }
    param_1[3] = iVar5;
    puVar3 = local_48;
    if (local_48 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_004a3220(puVar3,local_30,local_20);
    if (bVar8) {
      FUN_0058815f(local_20,s_PITDIRECTOR_02d_005cd544,*(undefined4 *)(*param_1 + 0x4894));
      pvVar4 = operator_new(0x88);
      if (pvVar4 == (void *)0x0) {
        pvVar4 = (void *)0x0;
      }
      else {
        *(undefined4 *)((int)pvVar4 + 100) = 0;
        *(undefined4 *)((int)pvVar4 + 0x6c) = 0;
        *(undefined4 *)((int)pvVar4 + 0x74) = 0;
        FUN_004a2220();
        FUN_004a3b30();
      }
      param_1[5] = (int)pvVar4;
      FUN_004a3910(local_20);
    }
    if (local_58 != 0) {
      FUN_0053ce40(local_58);
    }
    if (local_54 != 0) {
      FUN_0053ce40(local_54);
    }
    if (local_50 != 0) {
      FUN_0053ce40(local_50);
    }
    if (local_4c != 0) {
      FUN_0053ce40(local_4c);
    }
    puVar3 = local_40;
    if (local_40 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_0053c900(puVar3);
    pcVar7 = local_38;
    if (local_38 == (char *)0x0) {
      pcVar7 = &DAT_005ea438;
    }
    FUN_0053c900(pcVar7);
    if (local_40 != (undefined1 *)0x0) {
      FUN_00587bcf(local_40);
    }
    if (local_38 != (char *)0x0) {
      FUN_00587bcf(local_38);
    }
    if (local_48 != (undefined1 *)0x0) {
      FUN_00587bcf(local_48);
    }
    FUN_004a1f80();
  }
  return;
}


