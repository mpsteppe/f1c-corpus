// Function: FUN_004e49b0 @ 004e49b0
// Size (bytes): 1198


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e49b0(int param_1)

{
  float *pfVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  float fVar16;
  int iVar17;
  undefined4 *puVar18;
  float *pfVar19;
  undefined4 *puVar20;
  double *pdVar21;
  float10 fVar22;
  double local_38;
  double local_30;
  double local_28;
  
  FUN_0043aee0(DAT_007c8a18 + 4,&DAT_007c8a24,&local_38);
  *(float *)(param_1 + 0x34d4) = (float)local_38;
  pfVar1 = (float *)(param_1 + 0x34b0);
  iVar17 = 0;
  *(float *)(param_1 + 0x34d8) = (float)local_30;
  *(float *)(param_1 + 0x34dc) = (float)local_28;
  pfVar19 = pfVar1;
  do {
    iVar2 = iVar17 + 0x1c;
    iVar17 = iVar17 + 8;
    *pfVar19 = (float)*(double *)(iVar2 + DAT_007c8a18);
    pfVar19 = pfVar19 + 1;
  } while (iVar17 < 0x48);
  fVar22 = (float10)FUN_00588570();
  *(float *)(param_1 + 0x34e0) = (float)-fVar22;
  if (ABS(*(float *)(param_1 + 0x34c4)) == (float)_DAT_0059e420) {
    *(undefined4 *)(param_1 + 0x34e8) = 0;
    fVar22 = (float10)fpatan(-(float10)*(float *)(param_1 + 0x34c8),(float10)*pfVar1);
    *(float *)(param_1 + 0x34e4) = (float)fVar22;
  }
  else {
    fVar22 = (float10)fpatan((float10)*(float *)(param_1 + 0x34b8),
                             (float10)*(float *)(param_1 + 0x34d0));
    *(float *)(param_1 + 0x34e4) = (float)fVar22;
    fVar22 = (float10)fpatan((float10)*(float *)(param_1 + 0x34bc),
                             (float10)*(float *)(param_1 + 0x34c0));
    *(float *)(param_1 + 0x34e8) = (float)fVar22;
  }
  puVar18 = (undefined4 *)(DAT_007c8a18 + 100);
  pdVar21 = &local_38;
  for (iVar17 = 6; iVar17 != 0; iVar17 = iVar17 + -1) {
    *(undefined4 *)pdVar21 = *puVar18;
    puVar18 = puVar18 + 1;
    pdVar21 = (double *)((int)pdVar21 + 4);
  }
  *(float *)(param_1 + 0x34ec) = (float)local_38;
  *(float *)(param_1 + 0x34f0) = (float)local_30;
  *(float *)(param_1 + 0x34f4) = (float)local_28;
  *(float *)(param_1 + 0x34f8) =
       *pfVar1 * *(float *)(param_1 + 0x34ec) +
       *(float *)(param_1 + 0x34bc) * *(float *)(param_1 + 0x34f0) +
       *(float *)(param_1 + 0x34c8) * *(float *)(param_1 + 0x34f4);
  *(float *)(param_1 + 0x34fc) =
       *(float *)(param_1 + 0x34c0) * *(float *)(param_1 + 0x34f0) +
       *(float *)(param_1 + 0x34cc) * *(float *)(param_1 + 0x34f4) +
       *(float *)(param_1 + 0x34b4) * *(float *)(param_1 + 0x34ec);
  *(float *)(param_1 + 0x3500) =
       *(float *)(param_1 + 0x34c4) * *(float *)(param_1 + 0x34f0) +
       *(float *)(param_1 + 0x34d0) * *(float *)(param_1 + 0x34f4) +
       *(float *)(param_1 + 0x34b8) * *(float *)(param_1 + 0x34ec);
  dVar3 = *(double *)(DAT_007c8a18 + 0x54);
  dVar4 = *(double *)(DAT_007c8a18 + 0x8c);
  dVar5 = *(double *)(DAT_007c8a18 + 0x3c);
  dVar6 = *(double *)(DAT_007c8a18 + 0x84);
  dVar7 = *(double *)(DAT_007c8a18 + 0x24);
  dVar8 = *(double *)(DAT_007c8a18 + 0x7c);
  dVar9 = *(double *)(DAT_007c8a18 + 0x5c);
  dVar10 = *(double *)(DAT_007c8a18 + 0x8c);
  dVar11 = *(double *)(DAT_007c8a18 + 0x44);
  dVar12 = *(double *)(DAT_007c8a18 + 0x84);
  dVar13 = *(double *)(DAT_007c8a18 + 0x2c);
  dVar14 = *(double *)(DAT_007c8a18 + 0x7c);
  iVar17 = 4;
  *(float *)(param_1 + 0x3504) =
       (float)((float10)*(double *)(DAT_007c8a18 + 0x7c) * (float10)*(double *)(DAT_007c8a18 + 0x1c)
              + (float10)*(double *)(DAT_007c8a18 + 0x34) *
                (float10)*(double *)(DAT_007c8a18 + 0x84) +
                (float10)*(double *)(DAT_007c8a18 + 0x4c) *
                (float10)*(double *)(DAT_007c8a18 + 0x8c));
  *(float *)(param_1 + 0x3508) =
       (float)((float10)dVar7 * (float10)dVar8 +
              (float10)dVar5 * (float10)dVar6 + (float10)dVar3 * (float10)dVar4);
  *(float *)(param_1 + 0x350c) = (float)(dVar13 * dVar14 + dVar11 * dVar12 + dVar9 * dVar10);
  puVar18 = (undefined4 *)(param_1 + 0x3668);
  puVar20 = &DAT_007c7918;
  do {
    puVar18[-0x2e] = (float)*(double *)(puVar20 + -0x6a);
    *puVar18 = *puVar20;
    puVar18[-0x28] = (float)*(double *)(puVar20 + -0x4c);
    iVar17 = iVar17 + -1;
    puVar18[-0x27] = (float)*(double *)(puVar20 + -0x4a);
    puVar18[-0x26] = (float)*(double *)(puVar20 + -0x48);
    puVar18[-0x23] = (float)*(double *)(puVar20 + 0x68);
    puVar18 = puVar18 + 0x3e;
    puVar20 = puVar20 + 0x119;
  } while (iVar17 != 0);
  iVar17 = *(int *)(param_1 + 0x39b4);
  if (iVar17 == 0) {
    fVar16 = *(float *)(param_1 + 0x3898) + *(float *)(param_1 + 0x37a0);
LAB_004e4c3d:
    fVar16 = fVar16 * _DAT_0059e450;
  }
  else {
    if (iVar17 != 1) {
      if (iVar17 != 2) goto LAB_004e4c49;
      fVar16 = *(float *)(param_1 + 0x36a8) + *(float *)(param_1 + 0x35b0);
      goto LAB_004e4c3d;
    }
    fVar16 = (*(float *)(param_1 + 0x3898) + *(float *)(param_1 + 0x37a0) +
              *(float *)(param_1 + 0x36a8) + *(float *)(param_1 + 0x35b0)) * _DAT_0059e7f8;
  }
  *(float *)(param_1 + 0x3964) = fVar16;
LAB_004e4c49:
  *(undefined4 *)(param_1 + 0x39f0) = DAT_007c9318;
  if (_DAT_0059e430 <= _DAT_007c9084) {
    if (_DAT_007c9084 <= _DAT_007c911c) {
      fVar16 = (float)_DAT_007c9084;
    }
    else {
      fVar16 = (float)_DAT_007c911c;
    }
  }
  else {
    fVar16 = (float)_DAT_0059e430;
  }
  *(float *)(param_1 + 0x3994) = fVar16;
  *(float *)(param_1 + 0x3570) = (float)_DAT_007c7430;
  *(float *)(param_1 + 0x3574) = (float)((float10)_DAT_007c74ac * (float10)_DAT_007c7428);
  *(float *)(param_1 + 0x3578) = (float)_DAT_007c7438;
  if (_DAT_007c91dc < _DAT_0059e430 != (_DAT_007c91dc == _DAT_0059e430)) {
    if (DAT_0059e440 <= *(float *)(param_1 + 0x3d64)) {
      *(undefined4 *)(param_1 + 0x3d64) = 0xbf800000;
    }
    *(float *)(param_1 + 0x3d48) = (float)_DAT_007c920c;
    *(float *)(param_1 + 0x3d4c) = (float)_DAT_007c9214;
    *(float *)(param_1 + 0x3d50) = (float)_DAT_007c921c;
  }
  fVar16 = (float)_DAT_007c75c4;
  *(float *)(param_1 + 0x3978) = fVar16;
  fVar16 = fVar16 * _DAT_0059e7fc + *(float *)(param_1 + 0x3510);
  *(float *)(param_1 + 0x3514) = fVar16;
  *(float *)(param_1 + 0x3518) = _DAT_0059e43c / fVar16;
  dVar3 = *(double *)(DAT_007c8a18 + 0x24);
  dVar4 = *(double *)(DAT_007c8a18 + 0x134);
  dVar5 = *(double *)(DAT_007c8a18 + 0x54);
  dVar6 = *(double *)(DAT_007c8a18 + 0x144);
  dVar7 = *(double *)(DAT_007c8a18 + 0x3c);
  dVar8 = *(double *)(DAT_007c8a18 + 0x13c);
  dVar9 = *(double *)(DAT_007c8a18 + 0x2c);
  dVar10 = *(double *)(DAT_007c8a18 + 0x134);
  dVar11 = *(double *)(DAT_007c8a18 + 0x5c);
  dVar12 = *(double *)(DAT_007c8a18 + 0x144);
  dVar13 = *(double *)(DAT_007c8a18 + 0x44);
  dVar14 = *(double *)(DAT_007c8a18 + 0x13c);
  dVar15 = *(double *)(DAT_007c8a18 + 0xb4);
  *(float *)(param_1 + 0x3540) =
       (float)(((float10)*(double *)(DAT_007c8a18 + 0x1c) *
                (float10)*(double *)(DAT_007c8a18 + 0x134) +
               (float10)*(double *)(DAT_007c8a18 + 0x34) *
               (float10)*(double *)(DAT_007c8a18 + 0x13c) +
               (float10)*(double *)(DAT_007c8a18 + 0x4c) *
               (float10)*(double *)(DAT_007c8a18 + 0x144)) * (float10)dVar15);
  *(float *)(param_1 + 0x3544) =
       (float)((float10)(dVar7 * dVar8 + dVar5 * dVar6 + dVar3 * dVar4) * (float10)dVar15);
  *(float *)(param_1 + 0x3548) =
       (float)((dVar13 * dVar14 + dVar11 * dVar12 + dVar9 * dVar10) * dVar15);
  *(float *)(param_1 + 0x3534) =
       *(float *)(param_1 + 0x3540) * *pfVar1 +
       *(float *)(param_1 + 0x34b4) * *(float *)(param_1 + 0x3544) +
       *(float *)(param_1 + 0x34b8) * *(float *)(param_1 + 0x3548);
  *(float *)(param_1 + 0x3538) =
       *(float *)(param_1 + 0x34c0) * *(float *)(param_1 + 0x3544) +
       *(float *)(param_1 + 0x34c4) * *(float *)(param_1 + 0x3548) +
       *(float *)(param_1 + 0x34bc) * *(float *)(param_1 + 0x3540);
  *(float *)(param_1 + 0x353c) =
       *(float *)(param_1 + 0x34cc) * *(float *)(param_1 + 0x3544) +
       *(float *)(param_1 + 0x34d0) * *(float *)(param_1 + 0x3548) +
       *(float *)(param_1 + 0x34c8) * *(float *)(param_1 + 0x3540);
  return;
}


