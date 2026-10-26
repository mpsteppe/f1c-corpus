// Function: FUN_0042caa0 @ 0042caa0
// Size (bytes): 833


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042caa0(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float local_e8c [931];
  
  if (0 < DAT_005c329c) {
    pfVar8 = local_e8c + 3;
    iVar11 = 0;
    do {
      iVar5 = (&DAT_007c54f0)[iVar11];
      fVar2 = *(float *)(iVar5 + 0x3500);
      fVar3 = *(float *)(iVar5 + 0x34f8);
      pfVar1 = (float *)(iVar5 + 0x34e0);
      pfVar8[-8] = *pfVar1;
      fVar3 = fVar2 * fVar2 + fVar3 * fVar3;
      fVar2 = *(float *)(iVar5 + 0x34e8);
      pfVar8[-7] = *(float *)(iVar5 + 0x34e4);
      pfVar8[-6] = fVar2;
      fVar2 = SQRT(fVar3);
      pfVar8[-5] = fVar2;
      pfVar8[-4] = ABS(fVar2 * _DAT_0059e9e4);
      if (fVar2 != DAT_0059e440) {
        fVar4 = (_DAT_0059e43c / fVar2) * *(float *)(iVar5 + 0x34f8);
        fVar6 = (_DAT_0059e43c / fVar2) * *(float *)(iVar5 + 0x3500);
        fVar7 = (fVar6 * *(float *)(iVar5 + 0x3540) - fVar4 * *(float *)(iVar5 + 0x3548)) *
                _DAT_0059e7f8;
        if (fVar7 == DAT_0059e440) {
          *pfVar8 = 1e+06;
        }
        else {
          *pfVar8 = fVar3 / ABS(fVar7);
        }
        fVar6 = fVar6 * *pfVar8;
        if (DAT_0059e440 <= fVar7) {
          pfVar8[-2] = fVar6 + *pfVar1;
          pfVar8[-1] = *(float *)(iVar5 + 0x34e8) - fVar4 * *pfVar8;
        }
        else {
          pfVar8[-2] = *pfVar1 - fVar6;
          pfVar8[-1] = fVar4 * *pfVar8 + *(float *)(iVar5 + 0x34e8);
          pfVar8[-5] = -fVar2;
        }
        fVar16 = (float10)fpatan((float10)*pfVar1 - (float10)pfVar8[-2],
                                 (float10)*(float *)(iVar5 + 0x34e8) - (float10)pfVar8[-1]);
        pfVar8[-3] = (float)fVar16;
      }
      iVar11 = iVar11 + 1;
      pfVar8 = pfVar8 + 9;
    } while (iVar11 < DAT_005c329c);
  }
  iVar11 = 0;
  if (0 < DAT_005c329c) {
    do {
      iVar5 = (&DAT_007c54f0)[iVar11];
      fVar16 = (float10)DAT_0059e440;
      fVar2 = *(float *)(iVar5 + 0x34e0);
      fVar13 = (float10)DAT_0059e440;
      fVar3 = *(float *)(iVar5 + 0x34e8);
      iVar10 = 0;
      iVar12 = iVar11;
      while( true ) {
        if (iVar10 < iVar12) {
          iVar9 = iVar12 - iVar10;
          pfVar8 = local_e8c + iVar10 * 9;
          iVar10 = iVar10 + iVar9;
          do {
            fVar4 = *(float *)(iVar5 + 0x34e4) - pfVar8[-4];
            fVar4 = (fVar2 - pfVar8[-5]) * (fVar2 - pfVar8[-5]) +
                    fVar4 * fVar4 + (fVar3 - pfVar8[-3]) * (fVar3 - pfVar8[-3]);
            fVar6 = pfVar8[-1] * pfVar8[-1];
            if (fVar6 < fVar4 == (fVar6 == fVar4)) {
              fVar17 = (float10)fpatan((float10)fVar2 - (float10)pfVar8[1],
                                       (float10)fVar3 - (float10)pfVar8[2]);
              fVar4 = (float)fVar17;
              if (pfVar8[-2] <= DAT_0059e440) {
                fVar6 = fVar4;
                if (fVar4 < *pfVar8) {
                  fVar6 = fVar4 + _DAT_0059e888;
                }
                fVar6 = fVar6 - *pfVar8;
              }
              else if (fVar4 <= *pfVar8) {
                fVar6 = *pfVar8 - fVar4;
              }
              else {
                fVar6 = *pfVar8 - (fVar4 - _DAT_0059e888);
              }
              fVar6 = fVar6 * pfVar8[3];
              if (fVar6 < pfVar8[-1]) {
                fVar17 = ABS((float10)pfVar8[3] -
                             SQRT(((float10)pfVar8[1] - (float10)fVar2) *
                                  ((float10)pfVar8[1] - (float10)fVar2) +
                                  ((float10)pfVar8[2] - (float10)fVar3) *
                                  ((float10)pfVar8[2] - (float10)fVar3)));
                fVar14 = (float10)fVar6 * (float10)_DAT_0059e9e0 + (float10)_DAT_0059e8a8;
                if (fVar17 < fVar14) {
                  fVar15 = (float10)_DAT_0059e43c - (float10)fVar6 / (float10)pfVar8[-1];
                  fVar15 = fVar15 * fVar15;
                  fVar17 = fVar15 * fVar15 * ((float10)_DAT_0059e43c - fVar17 / fVar14) *
                           (float10)pfVar8[-2] * (float10)_DAT_0059e4e0;
                  fVar14 = (float10)fcos((float10)fVar4);
                  fVar16 = fVar14 * fVar17 + fVar16;
                  fVar14 = (float10)fsin((float10)fVar4);
                  fVar13 = fVar13 - fVar14 * fVar17;
                }
              }
            }
            pfVar8 = pfVar8 + 9;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        if (iVar12 != iVar11) break;
        iVar10 = iVar10 + 1;
        iVar12 = DAT_005c329c;
      }
      iVar5 = (&DAT_007c54f0)[iVar11];
      *(float *)(iVar5 + 0x3a64) = (float)fVar16;
      *(undefined4 *)(iVar5 + 0x3a68) = 0;
      *(float *)(iVar5 + 0x3a6c) = (float)fVar13;
      iVar11 = iVar11 + 1;
    } while (iVar11 < DAT_005c329c);
  }
  return;
}


