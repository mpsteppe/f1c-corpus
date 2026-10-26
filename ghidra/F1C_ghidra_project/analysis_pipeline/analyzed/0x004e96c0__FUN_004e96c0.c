// Function: FUN_004e96c0 @ 004e96c0
// Size (bytes): 695


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __fastcall FUN_004e96c0(int param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float *pfVar10;
  ushort uVar12;
  undefined2 uVar13;
  int *piVar11;
  int iVar14;
  
  fVar1 = *(float *)(param_1 + 0x3aac) - *(float *)(param_1 + 0x34d4);
  fVar6 = *(float *)(param_1 + 0x3ab0) - *(float *)(param_1 + 0x34d8);
  fVar5 = *(float *)(param_1 + 0x3ab4) - *(float *)(param_1 + 0x34dc);
  fVar1 = fVar1 * fVar1 + fVar6 * fVar6 + fVar5 * fVar5;
  if (fVar1 < (float)_DAT_005ad1d0) {
    if (*(uint *)(param_1 + 0x32bc) != 0) {
      return (int *)(*(uint *)(param_1 + 0x32bc) & 0xffffff00);
    }
    fVar5 = (float)_DAT_005ad1c8;
    if (fVar1 < fVar5) {
      return (int *)(uint)(ushort)((ushort)(fVar1 < fVar5) << 8 |
                                   (ushort)(NAN(fVar1) || NAN(fVar5)) << 10 |
                                  (ushort)(fVar1 == fVar5) << 0xe);
    }
  }
  *(float *)(param_1 + 0x3aac) = *(float *)(param_1 + 0x34d4);
  *(undefined4 *)(param_1 + 0x3ab0) = *(undefined4 *)(param_1 + 0x34d8);
  *(undefined4 *)(param_1 + 0x3ab4) = *(undefined4 *)(param_1 + 0x34dc);
  if (*(float *)(param_1 + 0x34c0) < _DAT_0059ee8c) {
    fVar1 = *(float *)(param_1 + 0x34c0);
    if (fVar1 < _DAT_005ad1c4) {
      return (int *)CONCAT31((int3)(CONCAT22((short)((uint)*(undefined4 *)(param_1 + 0x34dc) >> 0x10
                                                    ),(ushort)(fVar1 < _DAT_005ad1c4) << 8 |
                                                      (ushort)(NAN(fVar1) || NAN(_DAT_005ad1c4)) <<
                                                      10 | (ushort)(fVar1 == _DAT_005ad1c4) << 0xe)
                                   >> 8),1);
    }
    iVar14 = 0;
    piVar11 = (int *)(param_1 + 0x828);
    do {
      if ((*piVar11 == 0) || ((char)piVar11[0x10] == '\0')) goto LAB_004e996e;
      iVar14 = iVar14 + 1;
      piVar11 = piVar11 + 0x4a;
    } while (iVar14 < 4);
  }
  pfVar10 = (float *)FUN_004e9630();
  fVar1 = *(float *)(param_1 + 0x34d4) - *pfVar10;
  pfVar3 = (float *)pfVar10[0x44];
  pfVar4 = (float *)pfVar10[0x43];
  fVar5 = *(float *)(param_1 + 0x34d8) - pfVar10[1];
  fVar6 = *(float *)(param_1 + 0x34dc) - pfVar10[2];
  fVar7 = fVar1 * pfVar10[8] + fVar5 * pfVar10[9] + fVar6 * pfVar10[10];
  uVar12 = (ushort)((uint)pfVar10 >> 0x10);
  iVar14 = (uint)uVar12 << 0x10;
  if (fVar7 < *(float *)(param_1 + 0x3b6c)) {
    if (pfVar4[0x16] <= pfVar3[0x16]) {
      fVar2 = pfVar4[0x16];
    }
    else {
      fVar2 = pfVar3[0x16];
    }
    if (fVar2 <= pfVar10[0x16]) {
      if (pfVar4[0x16] <= pfVar3[0x16]) {
        fVar2 = pfVar4[0x16];
      }
      else {
        fVar2 = pfVar3[0x16];
      }
    }
    else {
      fVar2 = pfVar10[0x16];
    }
    fVar8 = *(float *)(param_1 + 0x3b6c) - fVar7;
    iVar14 = CONCAT22(uVar12,(ushort)(fVar8 < fVar2) << 8 | (ushort)(NAN(fVar8) || NAN(fVar2)) << 10
                             | (ushort)(fVar8 == fVar2) << 0xe);
    if (fVar8 < fVar2 == 0 && (fVar8 == fVar2) == 0) {
      return (int *)CONCAT31((int3)((uint)iVar14 >> 8),1);
    }
  }
  uVar12 = (ushort)((uint)iVar14 >> 0x10);
  iVar14 = (uint)uVar12 << 0x10;
  if (-*(float *)(param_1 + 0x3b6c) < fVar7) {
    if (pfVar4[0x17] <= pfVar3[0x17]) {
      fVar2 = pfVar4[0x17];
    }
    else {
      fVar2 = pfVar3[0x17];
    }
    if (fVar2 <= pfVar10[0x17]) {
      if (pfVar4[0x17] <= pfVar3[0x17]) {
        fVar2 = pfVar4[0x17];
      }
      else {
        fVar2 = pfVar3[0x17];
      }
    }
    else {
      fVar2 = pfVar10[0x17];
    }
    fVar7 = fVar7 + *(float *)(param_1 + 0x3b6c);
    iVar14 = CONCAT22(uVar12,(ushort)(fVar7 < fVar2) << 8 | (ushort)(NAN(fVar7) || NAN(fVar2)) << 10
                             | (ushort)(fVar7 == fVar2) << 0xe);
    if (fVar7 < fVar2 == 0 && (fVar7 == fVar2) == 0) {
      return (int *)CONCAT31((int3)((uint)iVar14 >> 8),1);
    }
  }
  fVar7 = *pfVar3 - *pfVar10;
  fVar8 = pfVar3[1] - pfVar10[1];
  fVar9 = pfVar3[2] - pfVar10[2];
  fVar2 = fVar7 * fVar1 + fVar8 * fVar5 + fVar6 * fVar9;
  fVar7 = fVar7 * fVar7 + fVar8 * fVar8 + fVar9 * fVar9;
  uVar13 = (undefined2)((uint)iVar14 >> 0x10);
  if (fVar7 < fVar2) {
    return (int *)CONCAT31((int3)(CONCAT22(uVar13,(ushort)(fVar7 < fVar2) << 8 |
                                                  (ushort)(NAN(fVar7) || NAN(fVar2)) << 10 |
                                                  (ushort)(fVar7 == fVar2) << 0xe) >> 8),1);
  }
  fVar7 = *pfVar4 - *pfVar10;
  fVar2 = pfVar4[1] - pfVar10[1];
  fVar8 = pfVar4[2] - pfVar10[2];
  fVar5 = fVar7 * fVar1 + fVar2 * fVar5 + fVar6 * fVar8;
  fVar1 = fVar7 * fVar7 + fVar2 * fVar2 + fVar8 * fVar8;
  piVar11 = (int *)CONCAT22(uVar13,(ushort)(fVar1 < fVar5) << 8 |
                                   (ushort)(NAN(fVar1) || NAN(fVar5)) << 10 |
                                   (ushort)(fVar1 == fVar5) << 0xe);
  if (fVar1 >= fVar5) {
    return piVar11;
  }
LAB_004e996e:
  return (int *)CONCAT31((int3)((uint)piVar11 >> 8),1);
}


