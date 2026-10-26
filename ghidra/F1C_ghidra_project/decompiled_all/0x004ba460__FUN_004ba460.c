// Function: FUN_004ba460 @ 004ba460
// Strings:  [Replay Recording - Off, Replay Recording - Off]


void __fastcall FUN_004ba460(int *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *pcVar8;
  char local_300;
  undefined4 local_2ff;
  undefined1 local_281;
  undefined *local_280;
  undefined4 local_27c [31];
  char local_200;
  undefined4 uStack_1ff;
  
  cVar1 = FUN_00461db0();
  if (cVar1 == '\0') {
    iVar2 = *param_1;
    if (iVar2 == 1) goto LAB_004ba4b3;
    if (iVar2 != 0) {
      if (iVar2 != 2) {
        return;
      }
      *(undefined1 *)(param_1[2] + 0xf80) = 1;
      return;
    }
  }
  else {
    if (((DAT_007d0038 != 0) || (DAT_007d005c != 0)) && (DAT_007c56a4 == 7)) {
      *param_1 = 1;
LAB_004ba4b3:
      pcVar5 = DAT_005ec410;
      if (DAT_005ec410 == (char *)0x0) {
        pcVar5 = &DAT_005ea438;
      }
      FUN_00589671(pcVar5);
      local_200 = DAT_005ea438;
      puVar6 = &uStack_1ff;
      for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      *(undefined2 *)puVar6 = 0;
      *(undefined1 *)((int)puVar6 + 2) = 0;
      iVar2 = -(int)pcVar5;
      do {
        cVar1 = *pcVar5;
        pcVar5[(int)(&local_200 + iVar2)] = cVar1;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      local_280 = PTR_LAB_005d2520;
      puVar6 = local_27c;
      for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      local_300 = DAT_005ea438;
      puVar6 = &local_2ff;
      for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      *(undefined2 *)puVar6 = 0;
      *(undefined1 *)((int)puVar6 + 2) = 0;
      FUN_004c5920(&local_280,0x80);
      iVar2 = FUN_00423a00(&local_280,&DAT_005ec4cc);
      if (iVar2 != 0) {
        iVar2 = 0;
        do {
          cVar1 = *(char *)((int)local_27c + iVar2 + -4);
          (&DAT_005ec4cc)[iVar2] = cVar1;
          iVar2 = iVar2 + 1;
        } while (cVar1 != '\0');
      }
      _strncpy(&local_300,&DAT_005ec4cc,0x7f);
      local_281 = 0;
      pcVar5 = (char *)FUN_00587c20(&local_300,&DAT_005d251c);
      if ((pcVar5 != (char *)0x0) && (&local_300 < pcVar5)) {
        *pcVar5 = '\0';
      }
      uVar3 = 0xffffffff;
      pcVar5 = &local_300;
      do {
        pcVar8 = pcVar5;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar8 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar8;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar2 = -1;
      pcVar5 = &local_200;
      do {
        pcVar7 = pcVar5;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar7 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar7;
      } while (cVar1 != '\0');
      pcVar5 = pcVar8 + -uVar3;
      pcVar8 = pcVar7 + -1;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar8 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar8 = pcVar8 + 1;
      }
      iVar2 = -1;
      pcVar5 = &local_200;
      do {
        pcVar8 = pcVar5;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar8 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar8;
      } while (cVar1 != '\0');
      *(undefined4 *)(pcVar8 + -1) = DAT_005be714;
      pcVar8[3] = DAT_005be718;
      cVar1 = FUN_004b97d0(&local_200,1);
      if (cVar1 == '\0') {
        *param_1 = 0;
      }
      FUN_004b9800();
      FUN_004b9860(DAT_007d00a4);
      return;
    }
    *param_1 = 0;
  }
  if ((4 < DAT_007d0410) && (DAT_007d0410 < 7)) {
    return;
  }
  iVar2 = FUN_00423a00(s_Replay_Recording___Off_005d2504,&DAT_005ec4cc);
  if (iVar2 != 0) {
    iVar2 = 0;
    do {
      pcVar5 = s_Replay_Recording___Off_005d2504 + iVar2;
      (&DAT_005ec4cc)[iVar2] = *pcVar5;
      iVar2 = iVar2 + 1;
    } while (*pcVar5 != '\0');
  }
  FUN_0045bd10(&DAT_005ec4cc,2,0x1020304);
  return;
}


