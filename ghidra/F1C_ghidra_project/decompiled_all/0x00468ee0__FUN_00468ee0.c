// Function: FUN_00468ee0 @ 00468ee0
// Strings:  [ProfileIcon_DFT.bmp, ProfileIcon.bmp, ProfileIcon.bmp, *.PLR]


void __fastcall FUN_00468ee0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  char acStack_801 [1024];
  char acStack_401 [1025];
  
  FUN_0048d230();
  piVar4 = *(int **)(param_1 + 0x444);
  while (piVar4 != (int *)0x0) {
    piVar2 = (int *)piVar4[1];
    if (((char)piVar4[2] != '\0') && (*piVar4 != 0)) {
      FUN_00404f70(1);
    }
    FUN_00587bcf(piVar4);
    piVar4 = piVar2;
  }
  *(undefined4 *)(param_1 + 0x444) = 0;
  *(undefined4 *)(param_1 + 0x448) = 0;
  *(undefined4 *)(param_1 + 0x44c) = 0;
  *(undefined4 *)(param_1 + 0x450) = 0;
  puVar5 = DAT_005ec440;
  if (DAT_005ec440 == (undefined1 *)0x0) {
    puVar5 = &DAT_005ea438;
  }
  FUN_00565f80(s___PLR_005c6960,1,puVar5,1);
  FUN_00566380(2);
  iVar6 = FUN_005662d0();
  do {
    if (iVar6 == 0) {
      FUN_00565eb0();
      if (0 < *(int *)(param_1 + 0x450)) {
        *(undefined4 *)(param_1 + 0x44c) = *(undefined4 *)(param_1 + 0x444);
        FUN_00469630();
        return;
      }
      *(undefined4 *)(param_1 + 0x44c) = 0;
      FUN_00469630();
      return;
    }
    puVar5 = DAT_005ec440;
    if (DAT_005ec440 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    FUN_0058815f(acStack_401 + 1,&DAT_005be860,puVar5,iVar6);
    iVar6 = 0;
    do {
      iVar3 = iVar6 + 1;
      acStack_801[iVar6 + 1] = acStack_401[iVar3];
      iVar6 = iVar6 + 1;
    } while (acStack_401[iVar3] != '\0');
    pcVar7 = acStack_801;
    uVar10 = 0xffffffff;
    do {
      pcVar7 = pcVar7 + 1;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
    } while (*pcVar7 != '\0');
    if ((0 < (int)(~uVar10 - 1)) && (pcVar7 = acStack_801 + ~uVar10, acStack_801 + 1 <= pcVar7)) {
      do {
        if (*pcVar7 == '\\') break;
        *pcVar7 = '\0';
        if (acStack_801 + 1 < pcVar7) {
          pcVar7 = pcVar7 + -1;
        }
      } while (acStack_801 + 1 <= pcVar7);
    }
    iVar6 = FUN_00423a00(s_ProfileIcon_bmp_005c6950,&DAT_005ec4cc);
    if (iVar6 != 0) {
      iVar6 = 0;
      do {
        pcVar7 = s_ProfileIcon_bmp_005c6950 + iVar6;
        (&DAT_005ec4cc)[iVar6] = *pcVar7;
        iVar6 = iVar6 + 1;
      } while (*pcVar7 != '\0');
    }
    uVar10 = 0xffffffff;
    pcVar7 = &DAT_005ec4cc;
    do {
      pcVar13 = pcVar7;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      pcVar13 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar13;
    } while (cVar1 != '\0');
    uVar10 = ~uVar10;
    iVar6 = -1;
    pcVar7 = acStack_801 + 1;
    do {
      pcVar12 = pcVar7;
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar12 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar12;
    } while (cVar1 != '\0');
    pcVar7 = pcVar13 + -uVar10;
    pcVar13 = pcVar12 + -1;
    for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar13 = pcVar13 + 4;
    }
    for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *pcVar13 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar13 = pcVar13 + 1;
    }
    iVar6 = FUN_00497ad0(acStack_801 + 1,0);
    if (iVar6 == 0) {
      iVar6 = FUN_00497ad0(s_ProfileIcon_DFT_bmp_005c66f8,0);
    }
    FUN_0048d2b0(iVar6);
    uVar10 = 0xffffffff;
    pcVar7 = acStack_401;
    do {
      pcVar7 = pcVar7 + 1;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
    } while (*pcVar7 != '\0');
    pcVar7 = acStack_401 + ~uVar10;
    if (acStack_401 + 1 < pcVar7) {
      do {
        if (*pcVar7 == '\\') break;
        pcVar7 = pcVar7 + -1;
      } while (acStack_401 + 1 < pcVar7);
    }
    puVar8 = operator_new(8);
    if (puVar8 != (undefined4 *)0x0) {
      *puVar8 = 0;
      puVar8[1] = 0xffffffff;
      FUN_00566650(acStack_401 + 1);
      puVar9 = operator_new(0xc);
      if (puVar9 == (undefined4 *)0x0) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        *puVar9 = puVar8;
        puVar9[1] = 0;
        *(undefined1 *)(puVar9 + 2) = 1;
      }
      if (*(int *)(param_1 + 0x444) == 0) {
        *(undefined4 **)(param_1 + 0x444) = puVar9;
        *(undefined4 **)(param_1 + 0x44c) = puVar9;
      }
      else {
        *(undefined4 **)(*(int *)(param_1 + 0x448) + 4) = puVar9;
      }
      *(undefined4 **)(param_1 + 0x448) = puVar9;
      *(int *)(param_1 + 0x450) = *(int *)(param_1 + 0x450) + 1;
    }
    FUN_00565f20();
    iVar6 = FUN_005662d0();
  } while( true );
}


