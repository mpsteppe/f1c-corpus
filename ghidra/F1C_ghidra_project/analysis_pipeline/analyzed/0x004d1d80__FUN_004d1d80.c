// Function: FUN_004d1d80 @ 004d1d80
// Size (bytes): 1004


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d1d80(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  char cVar11;
  int iVar13;
  undefined4 uVar14;
  code *pcVar15;
  float local_74;
  float local_70;
  char local_68 [104];
  char cVar12;
  
  fVar4 = *(float *)(param_1 + 0x120) - (float)_DAT_008afe98;
  *(float *)(param_1 + 0x120) = fVar4;
  if (DAT_0059e440 < fVar4) {
    return;
  }
  *(undefined4 *)(param_1 + 0x120) = 0x3e800000;
  cVar12 = '\0';
  cVar11 = '\0';
  iVar13 = 0;
  if (0 < DAT_005c329c) {
    do {
      pfVar6 = (float *)FUN_004e9630();
      iVar7 = (&DAT_007c54f0)[iVar13];
      if ((*(int *)(iVar7 + 0x4040) == 2) && (pfVar6[0x11] == 0.0)) {
        *(float *)(iVar7 + 0x4044) = DAT_005ea3fc;
      }
      else if ((*(int *)(iVar7 + 0x4040) == 0) && (pfVar6[0x11] == 2.8026e-45)) {
        *(undefined4 *)(iVar7 + 0x4044) = 0;
      }
      else {
        pfVar1 = (float *)pfVar6[0x44];
        pfVar2 = (float *)pfVar6[0x43];
        local_74 = *pfVar1 - *pfVar2;
        local_70 = pfVar1[1] - pfVar2[1];
        fVar4 = pfVar1[2] - pfVar2[2];
        fVar5 = local_74 * local_74 + local_70 * local_70 + fVar4 * fVar4;
        if (fVar5 < DAT_0059e440 == (fVar5 == DAT_0059e440)) {
          fVar5 = _DAT_0059e43c / SQRT(fVar5);
          local_74 = local_74 * fVar5;
          local_70 = local_70 * fVar5;
          fVar4 = fVar5 * fVar4;
        }
        *(float *)(iVar7 + 0x4044) =
             pfVar6[0x12] +
             (*(float *)(iVar7 + 0x34e0) - *pfVar6) * local_74 +
             local_70 * (*(float *)(iVar7 + 0x34e4) - pfVar6[1]) +
             fVar4 * (*(float *)(iVar7 + 0x34e8) - pfVar6[2]);
      }
      cVar11 = cVar12;
      if (pfVar6[0x4b] == 0.0) {
        iVar10 = (&DAT_007c54f0)[iVar13];
        fVar4 = *(float *)(param_1 + 0x100) -
                SQRT(*(float *)(iVar10 + 0x3500) * *(float *)(iVar10 + 0x3500) +
                     *(float *)(iVar10 + 0x34fc) * *(float *)(iVar10 + 0x34fc) +
                     *(float *)(iVar10 + 0x34f8) * *(float *)(iVar10 + 0x34f8)) * _DAT_0059e7ec;
        bVar3 = *(float *)(iVar7 + 0x4044) < *(float *)(param_1 + 0x100);
        if (DAT_0059e440 <= fVar4) {
          if ((bVar3) && (fVar4 < *(float *)(iVar7 + 0x4044))) goto LAB_004d1f92;
        }
        else if ((bVar3) || (DAT_005ea3fc + fVar4 < *(float *)(iVar7 + 0x4044))) {
LAB_004d1f92:
          cVar11 = '\x01';
        }
      }
      iVar13 = iVar13 + 1;
      cVar12 = cVar11;
    } while (iVar13 < DAT_005c329c);
  }
  if (cVar11 != *(char *)(param_1 + 0x104)) {
    if (DAT_0083ee60 < 0x3ff) {
      DAT_0083ee60 = DAT_0083ee60 + 1;
      DAT_008aae64 = DAT_008aae64 + 0x1b0;
    }
    if (cVar11 == '\0') {
      uVar14 = 0x22;
    }
    else {
      uVar14 = 0x21;
    }
    FUN_004b33b0(4,uVar14,0,0xff,(float)_DAT_008afea0,0);
  }
  iVar13 = 0;
  if (0 < DAT_005c329c) {
    do {
      local_68[iVar13] = *(char *)((&DAT_007c54f0)[iVar13] + 0x4894);
      iVar13 = iVar13 + 1;
    } while (iVar13 < DAT_005c329c);
  }
  if (DAT_007c56a4 == 7) {
    pcVar15 = (code *)&LAB_004d0cf0;
  }
  else {
    pcVar15 = FUN_004d0c20;
  }
  FUN_005890aa(local_68,DAT_005c329c,1,pcVar15);
  bVar3 = false;
  iVar13 = 0;
  if (DAT_005c329c < 1) {
LAB_004d2086:
    uVar8 = *(int *)(param_1 + 0x124) + 1;
    *(uint *)(param_1 + 0x124) = uVar8;
    if ((uVar8 & 0xf) != 0) goto LAB_004d215a;
  }
  else {
    do {
      if (*(char *)(iVar13 + 0x128 + param_1) != local_68[iVar13]) {
        bVar3 = true;
      }
      *(char *)(iVar13 + 0x128 + param_1) = local_68[iVar13];
      iVar13 = iVar13 + 1;
    } while (iVar13 < DAT_005c329c);
    if (!bVar3) goto LAB_004d2086;
  }
  *(undefined4 *)(param_1 + 0x124) = 0;
  iVar13 = DAT_008aae64;
  if (DAT_0083ee60 < 0x3ff) {
    DAT_0083ee60 = DAT_0083ee60 + 1;
    DAT_008aae64 = DAT_008aae64 + 0x1b0;
  }
  FUN_004b33b0(4,7,DAT_005c329c + 0xc,0xff,(float)_DAT_008afea0,0);
  if (DAT_005c329c < 1) {
    *(undefined4 *)(iVar13 + 8) = 0xbf800000;
    *(undefined4 *)(iVar13 + 0xc) = 0xbf800000;
    *(undefined4 *)(iVar13 + 0x10) = 0xbf800000;
  }
  else {
    iVar7 = 0;
    puVar9 = (undefined4 *)(iVar13 + 8);
    do {
      iVar10 = (uint)*(byte *)(param_1 + 0x128) * 0x1230 + iVar7;
      iVar7 = iVar7 + 1;
      *puVar9 = *(undefined4 *)(&DAT_005f0780 + iVar10 * 4);
      puVar9 = puVar9 + 1;
    } while (iVar7 < 3);
  }
  iVar7 = 0;
  if (0 < DAT_005c329c) {
    do {
      *(undefined1 *)(iVar13 + 0x14 + iVar7) = *(undefined1 *)(iVar7 + 0x128 + param_1);
      iVar7 = iVar7 + 1;
    } while (iVar7 < DAT_005c329c);
  }
LAB_004d215a:
  FUN_004d1730();
  return;
}


