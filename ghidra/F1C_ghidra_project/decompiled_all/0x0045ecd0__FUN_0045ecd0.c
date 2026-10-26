// Function: FUN_0045ecd0 @ 0045ecd0
// Strings:  [autochat_10, autochat_09, autochat_08, autochat_07, autochat_06, autochat_05, autochat_04, autochat_03]


void __fastcall FUN_0045ecd0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char local_618;
  undefined4 local_617;
  undefined4 local_398;
  undefined1 local_394;
  undefined4 local_38c;
  undefined4 local_388;
  undefined4 local_384;
  undefined4 local_380 [96];
  char local_200;
  undefined4 uStack_1ff;
  
  piVar3 = *(int **)(param_1 + 0x1b780);
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {
      if (*piVar2 != 0) {
        FUN_00587bcf(*piVar2);
      }
      FUN_00587bcf(piVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  *(undefined4 *)(param_1 + 0x1b780) = 0;
  *(undefined4 *)(param_1 + 0x1b784) = 0;
  *(undefined4 *)(param_1 + 0x1b788) = 0;
  *(undefined4 *)(param_1 + 0x1b78c) = 0;
  local_200 = DAT_005ea438;
  puVar5 = &uStack_1ff;
  for (iVar7 = 0x7f; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  *(undefined1 *)((int)puVar5 + 2) = 0;
  FUN_005668b0();
  FUN_004b0220(&local_200,0x1ff);
  iVar7 = -1;
  pcVar8 = &local_200;
  do {
    pcVar9 = pcVar8;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar9 = pcVar8 + 1;
    cVar4 = *pcVar8;
    pcVar8 = pcVar9;
  } while (cVar4 != '\0');
  *(undefined4 *)(pcVar9 + -1) = s_quickChatText_txt_005c5e60._0_4_;
  *(undefined4 *)(pcVar9 + 3) = s_quickChatText_txt_005c5e60._4_4_;
  *(undefined4 *)(pcVar9 + 7) = s_quickChatText_txt_005c5e60._8_4_;
  *(undefined4 *)(pcVar9 + 0xb) = s_quickChatText_txt_005c5e60._12_4_;
  *(undefined2 *)(pcVar9 + 0xf) = s_quickChatText_txt_005c5e60._16_2_;
  cVar4 = FUN_00566b20(&local_200,1);
  if (cVar4 != '\0') {
    puVar5 = local_380;
    for (iVar7 = 0x60; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    local_618 = DAT_005ea438;
    puVar5 = &local_617;
    for (iVar7 = 0x3f; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    *(undefined2 *)puVar5 = 0;
    *(undefined1 *)((int)puVar5 + 2) = 0;
    local_398 = 0;
    local_384 = 0;
    local_38c = 0;
    local_388 = 0;
    local_394 = 1;
    iVar7 = FUN_00566cc0(local_380,0x180);
    while (iVar7 != 0) {
      iVar7 = FUN_005651b0();
      if ((iVar7 == 0) &&
         ((((((iVar7 = FUN_005654a0(s_autochat_01_005c5e54,&local_618), iVar7 != 0 ||
              (iVar7 = FUN_005654a0(s_autochat_02_005c5e48,&local_618), iVar7 != 0)) ||
             (iVar7 = FUN_005654a0(s_autochat_03_005c5e3c,&local_618), iVar7 != 0)) ||
            ((iVar7 = FUN_005654a0(s_autochat_04_005c5e30,&local_618), iVar7 != 0 ||
             (iVar7 = FUN_005654a0(s_autochat_05_005c5e24,&local_618), iVar7 != 0)))) ||
           ((iVar7 = FUN_005654a0(s_autochat_06_005c5e18,&local_618), iVar7 != 0 ||
            ((iVar7 = FUN_005654a0(s_autochat_07_005c5e0c,&local_618), iVar7 != 0 ||
             (iVar7 = FUN_005654a0(s_autochat_08_005c5e00,&local_618), iVar7 != 0)))))) ||
          ((iVar7 = FUN_005654a0(s_autochat_09_005c5df4,&local_618), iVar7 != 0 ||
           (iVar7 = FUN_005654a0(s_autochat_10_005c5de8,&local_618), iVar7 != 0)))))) {
        puVar5 = operator_new(8);
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *puVar5 = 0;
          puVar5[1] = 0xffffffff;
          FUN_00566650(&local_618);
        }
        if (puVar5 != (undefined4 *)0x0) {
          puVar6 = operator_new(0xc);
          if (puVar6 == (undefined4 *)0x0) {
            puVar6 = (undefined4 *)0x0;
          }
          else {
            *puVar6 = puVar5;
            puVar6[1] = 0;
            *(undefined1 *)(puVar6 + 2) = 1;
          }
          if (*(int *)(param_1 + 0x1b780) == 0) {
            *(undefined4 **)(param_1 + 0x1b780) = puVar6;
            *(undefined4 **)(param_1 + 0x1b788) = puVar6;
          }
          else {
            *(undefined4 **)(*(int *)(param_1 + 0x1b784) + 4) = puVar6;
          }
          *(undefined4 **)(param_1 + 0x1b784) = puVar6;
          *(int *)(param_1 + 0x1b78c) = *(int *)(param_1 + 0x1b78c) + 1;
        }
        if (9 < *(int *)(param_1 + 0x1b78c)) break;
      }
      iVar7 = FUN_00566cc0(local_380,0x180);
    }
    FUN_00566b90();
  }
  FUN_005668d0();
  return;
}


