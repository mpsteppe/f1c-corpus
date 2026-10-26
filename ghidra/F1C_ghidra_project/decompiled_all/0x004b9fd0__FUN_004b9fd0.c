// Function: FUN_004b9fd0 @ 004b9fd0
// Strings:  [Replay Activation, Replay Activation, Replay Recording - On, Replay Recording - On]


void __fastcall FUN_004b9fd0(int *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *pcVar8;
  char local_50;
  undefined4 uStack_4f;
  
  if (((char)param_1[1] == '\0') && (*param_1 == 1)) {
    iVar2 = FUN_00423a00(s_Replay_Recording___On_005d2494,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar3 = s_Replay_Recording___On_005d2494 + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar3;
        iVar2 = iVar2 + 1;
      } while (*pcVar3 != '\0');
    }
    FUN_0045bd10(&DAT_005ec4cc,2,0x1020304);
    cVar1 = FUN_00461db0();
    if (cVar1 == '\0') {
      local_50 = DAT_005ea438;
      puVar6 = &uStack_4f;
      for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      *(undefined2 *)puVar6 = 0;
      *(undefined1 *)((int)puVar6 + 2) = 0;
      iVar2 = FUN_00423a00(s_Replay_Activation_005d2480,&DAT_005ec4cc);
      if (iVar2 != 0) {
        iVar2 = 0;
        do {
          pcVar3 = s_Replay_Activation_005d2480 + iVar2;
          (&DAT_005ec4cc)[iVar2] = *pcVar3;
          iVar2 = iVar2 + 1;
        } while (*pcVar3 != '\0');
      }
      iVar2 = 0;
      do {
        cVar1 = (&DAT_005ec4cc)[iVar2];
        (&local_50)[iVar2] = cVar1;
        iVar2 = iVar2 + 1;
      } while (cVar1 != '\0');
      iVar2 = -1;
      pcVar3 = &local_50;
      do {
        pcVar8 = pcVar3;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar8 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar8;
      } while (cVar1 != '\0');
      *(undefined2 *)(pcVar8 + -1) = DAT_005c32d8;
      pcVar3 = (char *)FUN_00455260(&DAT_007d1d8c);
      if (pcVar3 != (char *)0x0) {
        iVar2 = FUN_00423a00(pcVar3,&DAT_005ec4cc);
        if (iVar2 != 0) {
          iVar2 = (int)&DAT_005ec4cc - (int)pcVar3;
          do {
            cVar1 = *pcVar3;
            pcVar3[iVar2] = cVar1;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
        }
        uVar4 = 0xffffffff;
        pcVar3 = &DAT_005ec4cc;
        do {
          pcVar8 = pcVar3;
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          pcVar8 = pcVar3 + 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar8;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4;
        iVar2 = -1;
        pcVar3 = &local_50;
        do {
          pcVar7 = pcVar3;
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          pcVar7 = pcVar3 + 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar7;
        } while (cVar1 != '\0');
        pcVar3 = pcVar8 + -uVar4;
        pcVar8 = pcVar7 + -1;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
          pcVar8 = pcVar8 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar8 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar8 = pcVar8 + 1;
        }
      }
      FUN_0045bd10(&local_50,3,0x1020304);
    }
    *(undefined1 *)(param_1 + 1) = 1;
  }
  return;
}


