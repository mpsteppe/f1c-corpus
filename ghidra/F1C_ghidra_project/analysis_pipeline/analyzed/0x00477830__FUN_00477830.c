
undefined4 __fastcall FUN_00477830(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  undefined4 *puVar16;
  int iStack_150;
  char cStack_140;
  undefined4 uStack_13f;
  char acStack_101 [2];
  undefined4 uStack_ff;
  
  FUN_0048ebd0();
  piVar3 = *(int **)(param_1 + 0xf0);
  while (piVar3 != (int *)0x0) {
    piVar2 = (int *)piVar3[1];
    if (((char)piVar3[3] != '\0') && ((undefined4 *)*piVar3 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar3)(1);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar2;
  }
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  FUN_004c62c0();
  uVar4 = FUN_005681f0(s_Game_Filter_005c7130);
  FUN_004c6330(uVar4);
  iVar5 = FUN_005871f0();
  iStack_150 = 0;
  if (0 < iVar5) {
    do {
      iVar6 = FUN_004c6780(iStack_150);
      if (((iVar6 != 0) && (pvVar7 = operator_new(0x48), pvVar7 != (void *)0x0)) &&
         (iVar8 = FUN_004761c0(), iVar8 != 0)) {
        acStack_101[1] = DAT_005ea438;
        puVar16 = &uStack_ff;
        for (iVar10 = 0x3f; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar16 = 0;
          puVar16 = puVar16 + 1;
        }
        *(undefined2 *)puVar16 = 0;
        *(undefined1 *)((int)puVar16 + 2) = 0;
        pcVar9 = (char *)(iVar6 + 4);
        iVar10 = 1 - (int)pcVar9;
        do {
          cVar1 = *pcVar9;
          pcVar9[(int)(acStack_101 + iVar10)] = cVar1;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        pcVar9 = acStack_101;
        uVar11 = 0xffffffff;
        do {
          pcVar9 = pcVar9 + 1;
          if (uVar11 == 0) break;
          uVar11 = uVar11 - 1;
        } while (*pcVar9 != '\0');
        if ((0 < (int)(~uVar11 - 1)) && (pcVar9 = acStack_101 + ~uVar11, acStack_101 + 1 <= pcVar9))
        {
          do {
            if (*pcVar9 == '\\') break;
            *pcVar9 = '\0';
            if (acStack_101 + 1 < pcVar9) {
              pcVar9 = pcVar9 + -1;
            }
          } while (acStack_101 + 1 <= pcVar9);
        }
        uVar11 = 0xffffffff;
        pcVar13 = (char *)(iVar6 + 0x104);
        pcVar9 = pcVar13;
        do {
          pcVar15 = pcVar9;
          if (uVar11 == 0) break;
          uVar11 = uVar11 - 1;
          pcVar15 = pcVar9 + 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar15;
        } while (cVar1 != '\0');
        uVar11 = ~uVar11;
        iVar10 = -1;
        pcVar9 = acStack_101 + 1;
        do {
          pcVar14 = pcVar9;
          if (iVar10 == 0) break;
          iVar10 = iVar10 + -1;
          pcVar14 = pcVar9 + 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar14;
        } while (cVar1 != '\0');
        pcVar9 = pcVar15 + -uVar11;
        pcVar15 = pcVar14 + -1;
        for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar9;
          pcVar9 = pcVar9 + 4;
          pcVar15 = pcVar15 + 4;
        }
        for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
          *pcVar15 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          pcVar15 = pcVar15 + 1;
        }
        iVar10 = -1;
        pcVar9 = acStack_101 + 1;
        do {
          pcVar15 = pcVar9;
          if (iVar10 == 0) break;
          iVar10 = iVar10 + -1;
          pcVar15 = pcVar9 + 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar15;
        } while (cVar1 != '\0');
        *(undefined4 *)(pcVar15 + -1) = s_Track_bmp_005c7150._0_4_;
        *(undefined4 *)(pcVar15 + 3) = s_Track_bmp_005c7150._4_4_;
        *(undefined2 *)(pcVar15 + 7) = s_Track_bmp_005c7150._8_2_;
        iVar10 = FUN_00497ad0(acStack_101 + 1,0);
        if ((iVar10 != 0) || (iVar10 = FUN_00497ad0(s_DFCarIcon_bmp_005c6a04,0), iVar10 != 0)) {
          FUN_0048fc80(iVar10);
        }
        FUN_004c55b0(pcVar13);
        cStack_140 = DAT_005ea438;
        puVar16 = &uStack_13f;
        for (iVar10 = 0xf; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar16 = 0;
          puVar16 = puVar16 + 1;
        }
        *(undefined2 *)puVar16 = 0;
        *(undefined1 *)((int)puVar16 + 2) = 0;
        FUN_004c5920(&cStack_140,0x3f);
        FUN_00566650(&cStack_140);
        FUN_00566650(pcVar13);
        *(int *)(iVar8 + 0x3c) = iVar6;
        FUN_0048f5d0(iVar8,1);
      }
      iStack_150 = iStack_150 + 1;
    } while (iStack_150 < iVar5);
  }
  FUN_00477ba0();
  FUN_0048f640();
  return 0;
}

