
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004d99e0(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uStack_94;
  int iStack_90;
  char *pcStack_8c;
  char acStack_88 [8];
  char acStack_80 [127];
  undefined1 uStack_1;
  
  if (*(float *)(param_1 + 0x10) < DAT_0059e440) {
    return 1;
  }
  pcVar5 = (char *)0x0;
  *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) - (float)_DAT_008afe98;
  pcStack_8c = (char *)0x0;
  iVar2 = FUN_004c5840(0);
  if (iVar2 != 0) {
    iVar2 = FUN_005679c0(PTR_s_VenueName_005d4af8);
    if (iVar2 != 0) {
      pcVar5 = (char *)FUN_00567970();
    }
    iVar2 = FUN_005679c0(PTR_s_TrackName_005d4afc);
    if (iVar2 != 0) {
      pcStack_8c = (char *)FUN_00567970();
    }
    if (pcVar5 != (char *)0x0) {
      iVar2 = FUN_00423a00(pcVar5,&DAT_005ec4cc);
      if (iVar2 != 0) {
        iVar2 = (int)&DAT_005ec4cc - (int)pcVar5;
        do {
          cVar1 = *pcVar5;
          pcVar5[iVar2] = cVar1;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
      }
      _strncpy(acStack_80,&DAT_005ec4cc,0x7f);
      uStack_94 = 0x280;
      uStack_1 = 0;
      FUN_004d7e40(acStack_80,0x280,0x332,0xffffff,2,0,0x3f800000,0x3f800000);
    }
  }
  FUN_0058815f(acStack_88,&DAT_005ccef0,(int)DAT_005d4aec);
  iVar2 = 0;
  do {
    cVar1 = (&DAT_005ea438)[iVar2];
    acStack_80[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  iStack_90 = 0x10;
  do {
    uVar3 = 0xffffffff;
    pcVar5 = acStack_88;
    do {
      pcVar7 = pcVar5;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar2 = -1;
    pcVar5 = acStack_80;
    do {
      pcVar6 = pcVar5;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    pcVar5 = pcVar7 + -uVar3;
    pcVar7 = pcVar6 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    iStack_90 = iStack_90 + -1;
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
    if (iStack_90 == 0) {
      FUN_004d7e40(acStack_80,uStack_94,0x35a,0xffffff,2,3,0x3f800000,0x3f800000);
      if (pcStack_8c != (char *)0x0) {
        iVar2 = FUN_00423a00(pcStack_8c,&DAT_005ec4cc);
        if (iVar2 != 0) {
          iVar2 = (int)&DAT_005ec4cc - (int)pcStack_8c;
          do {
            cVar1 = *pcStack_8c;
            pcStack_8c[iVar2] = cVar1;
            pcStack_8c = pcStack_8c + 1;
          } while (cVar1 != '\0');
        }
        _strncpy(acStack_80,&DAT_005ec4cc,0x7f);
        uStack_1 = 0;
        FUN_004d7e40(acStack_80,0x280,0x382,0xffffff,2,0,0x3f800000,0x3f800000);
      }
      return 0;
    }
  } while( true );
}

