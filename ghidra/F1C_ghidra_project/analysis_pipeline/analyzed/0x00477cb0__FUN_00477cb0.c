
undefined4 __fastcall FUN_00477cb0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  uint uVar8;
  char *pcVar9;
  char acStack_180 [64];
  char acStack_140 [64];
  undefined1 auStack_100 [256];
  
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
  *(undefined4 *)(param_1 + 0x174) = 0;
  PTR_s_ProfileIcon_DFT_bmp_005c6658 = s_ProfileIcon_DFT_bmp_005c66f8;
  pcVar4 = DAT_005ec3f8;
  if (DAT_005ec3f8 == (char *)0x0) {
    pcVar4 = &DAT_005ea438;
  }
  iVar5 = -(int)pcVar4;
  do {
    cVar1 = *pcVar4;
    pcVar4[(int)(acStack_140 + iVar5)] = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00565f80(s___BMP_005c715c,1,acStack_140,1);
  FUN_00566380(0);
  pcVar4 = (char *)FUN_005662d0();
  do {
    if (pcVar4 == (char *)0x0) {
      FUN_00565eb0();
      FUN_0048f640();
      return 0;
    }
    uVar8 = 0xffffffff;
    pcVar9 = pcVar4;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    for (pcVar9 = pcVar4 + (~uVar8 - 1); pcVar4 < pcVar9; pcVar9 = pcVar9 + -1) {
      if (*pcVar9 == '\\') {
        pcVar9 = pcVar9 + 1;
        break;
      }
    }
    pcVar4 = pcVar9;
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)(acStack_180 + -(int)pcVar9)] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar8 = 0xffffffff;
    pcVar4 = acStack_180;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = acStack_180 + (~uVar8 - 1);
    if (acStack_180 < pcVar4) {
      do {
        if (*pcVar4 == '.') {
          *pcVar4 = '\0';
          break;
        }
        pcVar4 = pcVar4 + -1;
      } while (acStack_180 < pcVar4);
    }
    FUN_0058815f(auStack_100,&DAT_005be860,acStack_140,pcVar9);
    iVar5 = FUN_00497ad0(auStack_100,0);
    if (iVar5 == 0) {
      FUN_00497ad0(s_ProfileIcon_DFT_bmp_005c66f8,0);
    }
    else {
      pvVar6 = operator_new(0x3c);
      if (pvVar6 == (void *)0x0) {
        uVar7 = 0;
      }
      else {
        uVar7 = FUN_0048fc50();
      }
      FUN_00566650(auStack_100);
      FUN_0048fc80(iVar5);
      FUN_00566650(acStack_180);
      FUN_0048f5d0(uVar7,1);
    }
    FUN_00565f20();
    pcVar4 = (char *)FUN_005662d0();
  } while( true );
}

