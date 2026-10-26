// Function: FUN_00475150 @ 00475150
// Strings:  [FTIM14REDOUTLINED.BMP, FTIM14GreyOutlined.bmp, %d/%d, Searching..., Searching..., No Games Available, No Games Available, FTIM14BLKOUTLINED.BMP]


void FUN_00475150(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  char local_20d;
  int local_20c;
  int local_208;
  char local_200 [32];
  char local_1e0 [32];
  char local_1c0 [112];
  short local_150;
  char local_140 [128];
  char local_c0 [64];
  char local_80 [128];
  
  local_80[0] = '\0';
  pcVar2 = (char *)FUN_00489920();
  if (pcVar2 != (char *)0x0) {
    iVar3 = -(int)pcVar2;
    do {
      cVar1 = *pcVar2;
      pcVar2[(int)(local_80 + iVar3)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
  FUN_00489cb0();
  iVar3 = FUN_00461ff0();
  local_20c = 0;
  if ((0 < iVar3) && (iVar4 = FUN_00461fc0(), iVar4 == 0)) {
    FUN_00462160();
    local_208 = 0;
    if (0 < iVar3) {
      do {
        FUN_00461550();
        local_c0[0] = 0;
        cVar1 = FUN_00462010();
        if ((cVar1 != '\0') && (local_150 < 9999)) {
          uVar5 = 0xffffffff;
          local_140[0] = '\0';
          pcVar2 = local_1c0;
          do {
            pcVar8 = pcVar2;
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            pcVar8 = pcVar2 + 1;
            cVar1 = *pcVar2;
            pcVar2 = pcVar8;
          } while (cVar1 != '\0');
          uVar5 = ~uVar5;
          iVar4 = -1;
          pcVar2 = local_140;
          do {
            pcVar7 = pcVar2;
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            pcVar7 = pcVar2 + 1;
            cVar1 = *pcVar2;
            pcVar2 = pcVar7;
          } while (cVar1 != '\0');
          pcVar2 = pcVar8 + -uVar5;
          pcVar8 = pcVar7 + -1;
          for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
            pcVar2 = pcVar2 + 4;
            pcVar8 = pcVar8 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar8 = *pcVar2;
            pcVar2 = pcVar2 + 1;
            pcVar8 = pcVar8 + 1;
          }
          FUN_004894d0();
          iVar4 = FUN_00423a00();
          if (iVar4 != 0) {
            pcVar2 = &DAT_005ec4cc;
            do {
              cVar1 = (&stack0xffa13a74)[(int)pcVar2];
              *pcVar2 = cVar1;
              pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
          }
          uVar5 = 0xffffffff;
          pcVar2 = &DAT_005ec4cc;
          do {
            pcVar8 = pcVar2;
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            pcVar8 = pcVar2 + 1;
            cVar1 = *pcVar2;
            pcVar2 = pcVar8;
          } while (cVar1 != '\0');
          uVar5 = ~uVar5;
          iVar4 = -1;
          pcVar2 = local_140;
          do {
            pcVar7 = pcVar2;
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            pcVar7 = pcVar2 + 1;
            cVar1 = *pcVar2;
            pcVar2 = pcVar7;
          } while (cVar1 != '\0');
          pcVar2 = pcVar8 + -uVar5;
          pcVar8 = pcVar7 + -1;
          for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
            pcVar2 = pcVar2 + 4;
            pcVar8 = pcVar8 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar8 = *pcVar2;
            pcVar2 = pcVar2 + 1;
            pcVar8 = pcVar8 + 1;
          }
          FUN_004894d0();
          local_1e0[0] = '\0';
          FUN_0058815f();
          uVar5 = 0xffffffff;
          pcVar2 = local_1e0;
          do {
            pcVar8 = pcVar2;
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            pcVar8 = pcVar2 + 1;
            cVar1 = *pcVar2;
            pcVar2 = pcVar8;
          } while (cVar1 != '\0');
          uVar5 = ~uVar5;
          iVar4 = -1;
          pcVar2 = local_140;
          do {
            pcVar7 = pcVar2;
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            pcVar7 = pcVar2 + 1;
            cVar1 = *pcVar2;
            pcVar2 = pcVar7;
          } while (cVar1 != '\0');
          pcVar2 = pcVar8 + -uVar5;
          pcVar8 = pcVar7 + -1;
          for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
            pcVar2 = pcVar2 + 4;
            pcVar8 = pcVar8 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar8 = *pcVar2;
            pcVar2 = pcVar2 + 1;
            pcVar8 = pcVar8 + 1;
          }
          FUN_004894d0();
          local_200[0] = '\0';
          FUN_0058815f();
          uVar5 = 0xffffffff;
          pcVar2 = local_200;
          do {
            pcVar8 = pcVar2;
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            pcVar8 = pcVar2 + 1;
            cVar1 = *pcVar2;
            pcVar2 = pcVar8;
          } while (cVar1 != '\0');
          uVar5 = ~uVar5;
          iVar4 = -1;
          pcVar2 = local_140;
          do {
            pcVar7 = pcVar2;
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            pcVar7 = pcVar2 + 1;
            cVar1 = *pcVar2;
            pcVar2 = pcVar7;
          } while (cVar1 != '\0');
          pcVar2 = pcVar8 + -uVar5;
          pcVar8 = pcVar7 + -1;
          for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined4 *)pcVar8 = *(undefined4 *)pcVar2;
            pcVar2 = pcVar2 + 4;
            pcVar8 = pcVar8 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pcVar8 = *pcVar2;
            pcVar2 = pcVar2 + 1;
            pcVar8 = pcVar8 + 1;
          }
          FUN_0058815f();
          FUN_00489600();
          if (local_20d == '\0') {
            FUN_004615f0();
          }
          FUN_00489c10();
          local_20c = local_20c + 1;
        }
        FUN_004b0170();
        local_208 = local_208 + 1;
      } while (local_208 < iVar3);
    }
    iVar3 = -1;
    pcVar2 = local_80;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (iVar3 != -2) {
      FUN_00489ba0();
    }
    if (local_20c != 0) {
      FUN_0048a3b0();
      return;
    }
  }
  FUN_0048a3b0();
  iVar3 = FUN_00461fc0();
  if (iVar3 == 0) {
    iVar3 = FUN_00423a00();
    if (iVar3 != 0) {
      iVar3 = 0;
      do {
        pcVar2 = s_No_Games_Available_005c7104 + iVar3;
        (&DAT_005ec4cc)[iVar3] = *pcVar2;
        iVar3 = iVar3 + 1;
      } while (*pcVar2 != '\0');
    }
    FUN_00489600();
    return;
  }
  iVar3 = FUN_00423a00();
  if (iVar3 != 0) {
    iVar3 = 0;
    do {
      pcVar2 = s_Searching____005c70f4 + iVar3;
      (&DAT_005ec4cc)[iVar3] = *pcVar2;
      iVar3 = iVar3 + 1;
    } while (*pcVar2 != '\0');
  }
  FUN_00489600();
  return;
}


