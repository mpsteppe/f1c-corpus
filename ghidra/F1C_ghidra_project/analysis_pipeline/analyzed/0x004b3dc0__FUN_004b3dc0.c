// Function: FUN_004b3dc0 @ 004b3dc0
// Size (bytes): 624


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004b3dc0(int param_1)

{
  char cVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  uint uVar12;
  char *pcVar13;
  float local_3cc;
  float local_3c8;
  float local_3c4;
  float local_3c0;
  float local_3bc;
  float local_3b8;
  float local_3b4;
  float local_3b0;
  float local_3ac;
  char local_3a8 [100];
  float afStack_344 [104];
  float afStack_1a4 [105];
  
  iVar11 = FUN_0040c870();
  if ((*(int *)(iVar11 + 0x70) == 0) && (DAT_007cfc8c < (int)DAT_005c329c)) {
    if (DAT_007c54e0 == 0) {
      return;
    }
    fVar2 = *(float *)(DAT_007c54e0 + 0x34e0);
    fVar3 = *(float *)(DAT_007c54e0 + 0x34e4);
    fVar4 = *(float *)(DAT_007c54e0 + 0x34e8);
    FUN_00566e40();
    iVar11 = 0;
    if (0 < (int)DAT_005c329c) {
      do {
        iVar5 = (&DAT_007c54f0)[iVar11];
        fVar6 = *(float *)(iVar5 + 0x34e0) - fVar2;
        fVar9 = *(float *)(iVar5 + 0x34e4) - fVar3;
        fVar7 = *(float *)(iVar5 + 0x34e8) - fVar4;
        fVar10 = fVar6 * local_3cc + local_3c0 * fVar9 + local_3b4 * fVar7;
        fVar8 = local_3c8 * fVar6 + local_3bc * fVar9 + local_3b0 * fVar7;
        fVar7 = local_3ac * fVar7 + local_3c4 * fVar6 + local_3b8 * fVar9;
        fVar6 = fVar10 * fVar10 + fVar8 * fVar8;
        afStack_344[iVar11 + 1] = fVar6;
        if (fVar7 < DAT_0059e440) {
          fVar7 = fVar7 * _DAT_0059e8c8;
        }
        iVar11 = iVar11 + 1;
        afStack_344[iVar11] = fVar7 * fVar7 + fVar6;
        afStack_1a4[iVar11] = afStack_344[iVar11];
      } while (iVar11 < (int)DAT_005c329c);
    }
    FUN_005890aa(afStack_1a4 + 1,DAT_005c329c,4,&LAB_004b3d70);
    fVar2 = afStack_1a4[DAT_007cfc8c + 1];
    iVar11 = 0;
    if (0 < (int)DAT_005c329c) {
      do {
        local_3a8[iVar11] = afStack_344[iVar11 + 1] < fVar2;
        iVar11 = iVar11 + 1;
      } while (iVar11 < (int)DAT_005c329c);
    }
  }
  else if (0 < (int)DAT_005c329c) {
    uVar12 = DAT_005c329c >> 2;
    pcVar13 = local_3a8;
    while (uVar12 != 0) {
      uVar12 = uVar12 - 1;
      builtin_strncpy(pcVar13,"\x01\x01\x01\x01",4);
      pcVar13 = pcVar13 + 4;
    }
    for (uVar12 = DAT_005c329c & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      *pcVar13 = '\x01';
      pcVar13 = pcVar13 + 1;
    }
  }
  iVar11 = 0;
  if (0 < (int)DAT_005c329c) {
    uVar12 = DAT_005c329c;
    do {
      cVar1 = local_3a8[iVar11];
      if (cVar1 != local_3a8[(param_1 - (int)local_3a8) + iVar11 + -0x3a8 + 0x3a8]) {
        local_3a8[(param_1 - (int)local_3a8) + iVar11 + -0x3a8 + 0x3a8] = cVar1;
        if (cVar1 == '\0') {
          FUN_0054c030(0,0,1,0);
          FUN_0054c030(1,0,0,0);
          FUN_0054c1b0(0,1,0);
          uVar12 = DAT_005c329c;
        }
        else {
          FUN_004e0ed0(*(undefined4 *)((&DAT_007c54f0)[iVar11] + 0x1054));
          uVar12 = DAT_005c329c;
        }
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < (int)uVar12);
  }
  return;
}


