// Function: FUN_004da0d0 @ 004da0d0
// Strings:  [%6.3f]


void __fastcall FUN_004da0d0(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  char local_88 [8];
  char local_80 [128];
  
  if (*(char *)(param_1 + 0x18) == '\0') {
    iVar5 = *(int *)(param_1 + 0x1c);
    iVar4 = DAT_007c54e0;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x1c);
    iVar5 = DAT_007c54e0;
  }
  if ((iVar4 != 0) && (iVar5 != 0)) {
    iVar2 = *(int *)(iVar4 + 0x4060) + -1;
    if ((-1 < iVar2) && (iVar2 < 0x19)) {
      FUN_0058815f(local_80,&DAT_005ccef0,(int)(char)(DAT_005d4ae8 + (char)iVar2));
      FUN_004d7e40(local_80,100,0x332,0xffffff,0,3,DAT_005acf60,DAT_005acf60);
    }
    pcVar3 = (char *)(iVar4 + 0x46f8);
    iVar4 = -(int)pcVar3;
    do {
      cVar1 = *pcVar3;
      pcVar3[(int)(local_80 + iVar4)] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(local_80);
    FUN_004d7e40(local_80,0xd2,0x332,0xffffff,0,0,0x3f800000,0x3f800000);
    iVar4 = 0;
    do {
      cVar1 = (&DAT_005ea438)[iVar4];
      local_80[iVar4] = cVar1;
      iVar4 = iVar4 + 1;
    } while (cVar1 != '\0');
    iVar4 = 0;
    if (0 < DAT_005d4af4) {
      do {
        FUN_0058815f(local_88,&DAT_005ccef0,DAT_005d4af0 + iVar4);
        uVar6 = 0xffffffff;
        pcVar3 = local_88;
        do {
          pcVar9 = pcVar3;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar9 = pcVar3 + 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar9;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        iVar2 = -1;
        pcVar3 = local_80;
        do {
          pcVar8 = pcVar3;
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          pcVar8 = pcVar3 + 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar8;
        } while (cVar1 != '\0');
        pcVar3 = pcVar9 + -uVar6;
        pcVar9 = pcVar8 + -1;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
          pcVar9 = pcVar9 + 4;
        }
        iVar4 = iVar4 + 1;
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar9 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar9 = pcVar9 + 1;
        }
      } while (iVar4 < DAT_005d4af4);
    }
    FUN_004d7e40(local_80,0xd2,0x364,0xffffff,0,3,0x3f800000,0x3f800000);
    FUN_0058815f(local_80,s__6_3f_005d4b40,(double)ABS(*(float *)(param_1 + 0x14)));
    FUN_004d7e40(local_80,0x280,0x35a,0xffff00,2,0,0x3f800000,0x3f800000);
    iVar4 = *(int *)(iVar5 + 0x4060) + -1;
    if ((-1 < iVar4) && (iVar4 < 0x19)) {
      FUN_0058815f(local_80,&DAT_005ccef0,(int)(char)(DAT_005d4ae8 + (char)iVar4));
      FUN_004d7e40(local_80,0x49c,0x332,0xffffff,1,3,DAT_005acf60,DAT_005acf60);
    }
    pcVar3 = (char *)(iVar5 + 0x46f8);
    iVar5 = -(int)pcVar3;
    do {
      cVar1 = *pcVar3;
      pcVar3[(int)(local_80 + iVar5)] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00589901();
    FUN_004d7e40(local_80,0x42e,0x332,0xffffff,1,0,0x3f800000,0x3f800000);
    iVar5 = 0;
    do {
      cVar1 = (&DAT_005ea438)[iVar5];
      local_80[iVar5] = cVar1;
      iVar5 = iVar5 + 1;
    } while (cVar1 != '\0');
    iVar5 = 0;
    if (0 < DAT_005d4af4) {
      do {
        FUN_0058815f(local_88,&DAT_005ccef0,DAT_005d4af1 + iVar5);
        uVar6 = 0xffffffff;
        pcVar3 = local_88;
        do {
          pcVar9 = pcVar3;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar9 = pcVar3 + 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar9;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        iVar4 = -1;
        pcVar3 = local_80;
        do {
          pcVar8 = pcVar3;
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          pcVar8 = pcVar3 + 1;
          cVar1 = *pcVar3;
          pcVar3 = pcVar8;
        } while (cVar1 != '\0');
        pcVar3 = pcVar9 + -uVar6;
        pcVar9 = pcVar8 + -1;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar3;
          pcVar3 = pcVar3 + 4;
          pcVar9 = pcVar9 + 4;
        }
        iVar5 = iVar5 + 1;
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar9 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar9 = pcVar9 + 1;
        }
      } while (iVar5 < DAT_005d4af4);
    }
    FUN_004d7e40(local_80,0x42e,0x364,0xffffff,1,3,0x3f800000,0x3f800000);
  }
  return;
}


