// Function: FUN_0047c360 @ 0047c360
// Strings:  [FTIM14REDOUTLINED.BMP, FTIM14BLKOUTLINED.BMP]


void __thiscall FUN_0047c360(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  char *pcVar12;
  char *pcVar13;
  undefined4 uVar14;
  int local_158;
  char local_154;
  undefined4 local_153;
  undefined2 local_14f;
  undefined1 local_14d;
  char local_14c;
  undefined4 local_14b;
  undefined2 local_147;
  undefined1 local_145;
  int local_144;
  char local_140;
  undefined4 local_13f;
  char local_120;
  undefined4 local_11f;
  char local_100;
  undefined4 local_ff;
  
  piVar2 = *(int **)(param_1 + 0x44);
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (((char)piVar2[2] != '\0') && (*piVar2 != 0)) {
      FUN_00404f70(1);
    }
    FUN_00587bcf(piVar2);
    piVar2 = piVar1;
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  local_100 = DAT_005ea438;
  puVar6 = &local_ff;
  for (iVar7 = 0x3f; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  *(undefined1 *)((int)puVar6 + 2) = 0;
  FUN_00489cb0();
  *(int *)(param_1 + 0x174) = param_2;
  iVar7 = FUN_004c2850();
  if (param_2 == 0) {
    pcVar4 = *(char **)(param_1 + 0xa0);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = &DAT_005ea438;
    }
    iVar8 = -1;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      cVar3 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar3 != '\0');
    if (iVar8 != -2) {
      puVar5 = *(undefined1 **)(param_1 + 0xa0);
LAB_0047c432:
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_005ea438;
      }
      FUN_00566650(puVar5);
    }
  }
  else if (param_2 == 1) {
    pcVar4 = *(char **)(param_1 + 0xa8);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = &DAT_005ea438;
    }
    iVar8 = -1;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      cVar3 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar3 != '\0');
    if (iVar8 != -2) {
      puVar5 = *(undefined1 **)(param_1 + 0xa8);
      goto LAB_0047c432;
    }
  }
  if (iVar7 == 0) {
    return;
  }
  iVar7 = FUN_004c1370();
  local_120 = DAT_005ea438;
  puVar6 = &local_11f;
  for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  uVar14 = 0x20;
  pcVar4 = &local_120;
  *(undefined1 *)((int)puVar6 + 2) = 0;
  local_144 = iVar7 + 1;
  FUN_004c1390(pcVar4,0x20);
  FUN_004c0a20(pcVar4,uVar14);
  local_158 = 0;
  if (0 < iVar7 + 1) {
    do {
      if (local_158 == 0) {
        puVar6 = (undefined4 *)FUN_004c1390();
      }
      else {
        puVar6 = (undefined4 *)FUN_004c13a0(local_158 + -1);
      }
      local_140 = DAT_005ea438;
      puVar11 = &local_13f;
      for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar11 = 0;
        puVar11 = puVar11 + 1;
      }
      *(undefined2 *)puVar11 = 0;
      *(undefined1 *)((int)puVar11 + 2) = 0;
      local_153 = 0;
      local_14b = 0;
      local_14f = 0;
      local_147 = 0;
      local_14d = 0;
      local_154 = DAT_005ea438;
      local_14c = DAT_005ea438;
      local_145 = 0;
      local_100 = '\0';
      FUN_0058815f(&local_154,&DAT_005c3280,puVar6[0x66]);
      FUN_004c0a20(&local_140,0x20);
      uVar14 = FUN_004c13c0(&local_140);
      FUN_0058815f(&local_14c,&DAT_005c3280,uVar14);
      if (param_2 == 0) {
        iVar7 = 0;
        do {
          pcVar4 = &local_140 + iVar7;
          (&local_100)[iVar7] = *pcVar4;
          iVar7 = iVar7 + 1;
        } while (*pcVar4 != '\0');
        FUN_004894d0(&local_100);
        uVar9 = 0xffffffff;
        pcVar4 = &local_14c;
        do {
          pcVar13 = pcVar4;
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          pcVar13 = pcVar4 + 1;
          cVar3 = *pcVar4;
          pcVar4 = pcVar13;
        } while (cVar3 != '\0');
        uVar9 = ~uVar9;
        pcVar13 = pcVar13 + -uVar9;
LAB_0047c619:
        iVar7 = -1;
        pcVar4 = &local_100;
        do {
          pcVar12 = pcVar4;
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          pcVar12 = pcVar4 + 1;
          cVar3 = *pcVar4;
          pcVar4 = pcVar12;
        } while (cVar3 != '\0');
        pcVar4 = pcVar12 + -1;
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcVar4 = *(undefined4 *)pcVar13;
          pcVar13 = pcVar13 + 4;
          pcVar4 = pcVar4 + 4;
        }
        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pcVar4 = *pcVar13;
          pcVar13 = pcVar13 + 1;
          pcVar4 = pcVar4 + 1;
        }
      }
      else if (param_2 == 1) {
        puVar5 = (undefined1 *)*puVar6;
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        FUN_0058815f(&local_100,&DAT_005c2c18,puVar5);
        FUN_004894d0(&local_100);
        uVar9 = 0xffffffff;
        pcVar4 = &local_140;
        do {
          pcVar13 = pcVar4;
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          pcVar13 = pcVar4 + 1;
          cVar3 = *pcVar4;
          pcVar4 = pcVar13;
        } while (cVar3 != '\0');
        uVar9 = ~uVar9;
        iVar7 = -1;
        pcVar4 = &local_100;
        do {
          pcVar12 = pcVar4;
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          pcVar12 = pcVar4 + 1;
          cVar3 = *pcVar4;
          pcVar4 = pcVar12;
        } while (cVar3 != '\0');
        pcVar4 = pcVar13 + -uVar9;
        pcVar13 = pcVar12 + -1;
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcVar13 = *(undefined4 *)pcVar4;
          pcVar4 = pcVar4 + 4;
          pcVar13 = pcVar13 + 4;
        }
        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pcVar13 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          pcVar13 = pcVar13 + 1;
        }
        FUN_004894d0(&local_100);
        uVar9 = 0xffffffff;
        pcVar4 = &local_154;
        do {
          pcVar13 = pcVar4;
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          pcVar13 = pcVar4 + 1;
          cVar3 = *pcVar4;
          pcVar4 = pcVar13;
        } while (cVar3 != '\0');
        uVar9 = ~uVar9;
        pcVar13 = pcVar13 + -uVar9;
        goto LAB_0047c619;
      }
      cVar3 = FUN_00489a50(&local_100,0);
      if (cVar3 == '\0') {
        FUN_00489600(&local_100,0,0,0,0);
      }
      local_158 = local_158 + 1;
    } while (local_158 < local_144);
  }
  FUN_00489c10(0,s_FTIM14REDOUTLINED_BMP_005c6a28);
  if (param_2 == 0) {
    uVar14 = 1;
  }
  else {
    if (param_2 != 1) goto LAB_0047c696;
    uVar14 = 2;
  }
  FUN_0048a3c0(1,uVar14);
LAB_0047c696:
  local_100 = '\0';
  FUN_00489c10(0,s_FTIM14BLKOUTLINED_BMP_005c7118);
  return;
}


