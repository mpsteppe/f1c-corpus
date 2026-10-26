// Function: FUN_00439210 @ 00439210
// Strings:  [Vehicle has zero or negative inertia in at least one direction, D:\dev\F1_1999_2002\Source\hdvehicle.cpp]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00439210(int param_1,int param_2,int param_3)

{
  double *pdVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int iVar9;
  double dVar10;
  byte bVar11;
  char cVar12;
  float *pfVar13;
  int iVar14;
  int iVar15;
  double *pdVar16;
  int *piVar17;
  int iVar18;
  undefined4 uVar19;
  double *pdVar20;
  float *pfVar21;
  undefined1 *puVar22;
  int iVar23;
  undefined4 *puVar24;
  undefined8 *puVar25;
  float10 fVar26;
  float10 fVar27;
  int *local_1dc;
  double *local_1d8;
  double local_1d0;
  double local_1c8;
  double local_1c0;
  double local_1b8;
  undefined8 local_1b0;
  double local_1a8;
  double local_1a0;
  double local_198;
  undefined8 local_190;
  double local_188;
  double local_180;
  double local_178;
  double local_170;
  double local_168;
  double local_160;
  double local_158;
  double local_150;
  double local_148;
  double local_140;
  double local_138 [6];
  double local_108;
  double local_100;
  double local_f8;
  double local_f0;
  double local_e8;
  double local_e0;
  double local_d8;
  double local_d0;
  double local_c8;
  double local_c0;
  double local_b8;
  double local_b0 [5];
  undefined4 local_88 [2];
  undefined1 local_80 [40];
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double adStack_28 [4];
  
  iVar15 = *(int *)(param_1 + 0x1f00);
  pfVar21 = (float *)(iVar15 + 0x8c8);
  iVar18 = 4;
  pfVar13 = pfVar21;
  pdVar16 = local_138 + 2;
  do {
    pdVar16[-2] = (double)pfVar13[-1];
    iVar18 = iVar18 + -1;
    pdVar16[-1] = (double)*pfVar13;
    *pdVar16 = (double)pfVar13[1];
    pfVar13 = pfVar13 + 0x4a;
    pdVar16 = pdVar16 + 3;
  } while (iVar18 != 0);
  *(float *)(param_1 + 0x1f34) =
       (float)((float10)local_138[0] * (float10)_DAT_0059ebd0 +
              (float10)local_f0 * (float10)_DAT_0059ebd8 +
              (float10)local_138[5] * (float10)_DAT_0059ebe0 +
              (float10)local_f8 * (float10)_DAT_0059ebe8 +
              (float10)local_138[3] * (float10)_DAT_0059ebf0 +
              (float10)local_108 * (float10)_DAT_0059ebf8 +
              (float10)local_e0 * (float10)_DAT_0059ec00 +
              (float10)local_138[2] * (float10)_DAT_0059ec08);
  if (*(char *)(param_3 + 0x54a) != '\0') {
    local_138[2] = (local_138[5] + local_138[2]) * _DAT_0059e880;
    local_138[0] = (local_138[0] - local_138[3]) * _DAT_0059e880;
    local_138[3] = -local_138[0];
    local_f8 = (local_e0 + local_f8) * _DAT_0059e880;
    local_108 = (local_108 - local_f0) * _DAT_0059e880;
    local_f0 = -local_108;
    local_138[5] = local_138[2];
    local_e0 = local_f8;
  }
  if (*(double *)(param_3 + 0x54c) != _DAT_0059e430) {
    dVar3 = (*(double *)(param_3 + 0x54c) - (local_138[0] - local_138[3])) * _DAT_0059e880;
    local_138[0] = local_138[0] + dVar3;
    local_138[3] = local_138[3] - dVar3;
  }
  if (*(double *)(param_3 + 0x554) != _DAT_0059e430) {
    dVar3 = (*(double *)(param_3 + 0x554) - (local_108 - local_f0)) * _DAT_0059e880;
    local_108 = local_108 + dVar3;
    local_f0 = local_f0 - dVar3;
  }
  if (*(double *)(param_3 + 0x55c) != _DAT_0059e430) {
    dVar3 = (*(double *)(param_3 + 0x55c) - (local_f8 - local_138[2])) * _DAT_0059e880;
    local_138[2] = local_138[2] - dVar3;
    local_f8 = dVar3 + local_f8;
  }
  if (*(double *)(param_3 + 0x564) != _DAT_0059e430) {
    dVar3 = (*(double *)(param_3 + 0x564) - (local_e0 - local_138[5])) * _DAT_0059e880;
    local_138[5] = local_138[5] - dVar3;
    local_e0 = dVar3 + local_e0;
  }
  local_1d8 = (double *)0x4;
  do {
    FUN_0054b3b0(pfVar21[-1],*pfVar21,pfVar21[1]);
    pfVar21 = pfVar21 + 0x4a;
    local_1d8 = (double *)((int)local_1d8 + -1);
  } while (local_1d8 != (double *)0x0);
  iVar18 = *(int *)(param_1 + 0x1d4);
  fVar2 = *(float *)(iVar15 + 0x76c) - (float)*(double *)(param_3 + 0x78);
  *(undefined4 *)(iVar18 + 0xac) = 0;
  *(undefined4 *)(iVar18 + 0xb0) = 0x3ff00000;
  *(undefined4 *)(iVar18 + 0xb4) = 0;
  *(undefined4 *)(iVar18 + 0xb8) = 0x3ff00000;
  *(undefined4 *)(param_1 + 0x15f4) = *(undefined4 *)(param_3 + 0x40);
  iVar18 = *(int *)(param_1 + 0x15ac);
  *(undefined4 *)(param_1 + 0x15f8) = *(undefined4 *)(param_3 + 0x44);
  if (0 < iVar18) {
    iVar14 = *(int *)(param_1 + 0x15b0);
    do {
      if ((iVar14 != *(int *)(param_1 + 0x15f0)) && (iVar14 != *(int *)(param_1 + 0x1e8))) {
        *(double *)(param_1 + 0x15f4) = *(double *)(param_1 + 0x15f4) - *(double *)(iVar14 + 0xac);
      }
      iVar14 = iVar14 + 0x244;
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
  }
  dVar3 = *(double *)(param_1 + 0x15f4);
  iVar18 = *(int *)(param_1 + 0x15f0);
  *(double *)(iVar18 + 0xac) = dVar3;
  piVar17 = (int *)(param_1 + 0x3ec);
  iVar14 = 4;
  *(double *)(iVar18 + 0xb4) = _DAT_0059e420 / dVar3;
  pdVar16 = local_138 + 2;
  dVar3 = _DAT_0059e430;
  dVar5 = _DAT_0059e430;
  local_158 = _DAT_0059e430;
  local_150 = _DAT_0059e430;
  do {
    dVar3 = *(double *)(piVar17[-1] + 0xac) + dVar3;
    dVar4 = *(double *)(piVar17[-1] + 0xac);
    iVar18 = *piVar17;
    local_1a8 = dVar4 * pdVar16[-2];
    local_1a0 = dVar4 * pdVar16[-1];
    dVar5 = dVar4 * pdVar16[-2] + dVar5;
    local_158 = dVar4 * pdVar16[-1] + local_158;
    local_150 = dVar4 * *pdVar16 + local_150;
    if (iVar18 != 0) {
      dVar3 = *(double *)(iVar18 + 0xac) + dVar3;
      dVar4 = *(double *)(iVar18 + 0xac);
      local_1d0 = dVar4 * pdVar16[-2];
      local_1c8 = dVar4 * pdVar16[-1];
      dVar5 = dVar4 * pdVar16[-2] + dVar5;
      local_158 = dVar4 * pdVar16[-1] + local_158;
      local_150 = dVar4 * *pdVar16 + local_150;
    }
    piVar17 = piVar17 + 0x119;
    pdVar16 = pdVar16 + 3;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  iVar18 = *(int *)(param_1 + 0x141c);
  if (iVar18 != 0) {
    iVar14 = *(int *)(param_1 + 0x1114);
    iVar9 = *(int *)(param_1 + 0xcb0);
    local_178 = ((local_108 - *(double *)(iVar9 + 4)) + (local_f0 - *(double *)(iVar14 + 4))) *
                _DAT_0059e880 + *(double *)(iVar18 + 4);
    local_170 = ((local_e8 - *(double *)(iVar14 + 0xc)) + (local_100 - *(double *)(iVar9 + 0xc))) *
                _DAT_0059e880 + *(double *)(iVar18 + 0xc);
    dVar3 = *(double *)(iVar18 + 0xac) + dVar3;
    local_1c0 = *(double *)(iVar18 + 0xac);
    local_1d0 = local_178 * local_1c0;
    local_1c8 = local_170 * local_1c0;
    local_1c0 = local_1c0 *
                (((local_e0 - *(double *)(iVar14 + 0x14)) + (local_f8 - *(double *)(iVar9 + 0x14)))
                 * _DAT_0059e880 + *(double *)(iVar18 + 0x14));
    dVar5 = local_1d0 + dVar5;
    local_158 = local_1c8 + local_158;
    local_150 = local_1c0 + local_150;
  }
  local_140 = local_e0 + local_f8;
  local_1a8 = (local_f0 + local_108) * _DAT_0059e880 + *(double *)(param_3 + 200);
  local_1a0 = (double)(fVar2 + (float)*(double *)(param_3 + 0xd0));
  local_198 = (local_e0 + local_f8) * _DAT_0059e880 + *(double *)(param_3 + 0xd8);
  pdVar16 = &local_1a8;
  pdVar20 = &local_178;
  for (iVar18 = 6; iVar18 != 0; iVar18 = iVar18 + -1) {
    *(undefined4 *)pdVar20 = *(undefined4 *)pdVar16;
    pdVar16 = (double *)((int)pdVar16 + 4);
    pdVar20 = (double *)((int)pdVar20 + 4);
  }
  dVar4 = _DAT_0059ea58 / *(double *)(param_3 + 0xe0);
  iVar18 = *(int *)(param_1 + 0x1d4);
  dVar6 = ((double)*(int *)(param_2 + 0xcc4) * *(double *)(param_2 + 0xcb8) +
          *(double *)(param_2 + 0xcb0)) * _DAT_0059ea60 + _DAT_0059e420;
  dVar10 = _DAT_0059e420 / dVar6;
  *(double *)(iVar18 + 0xac) = dVar6;
  *(double *)(iVar18 + 0xb4) = dVar10;
  local_c0 = local_178 * dVar6;
  local_b0[0] = local_168 * dVar6;
  dVar10 = _DAT_0059e420 / (dVar6 + dVar3);
  local_160 = (dVar5 + local_c0) * dVar10;
  local_1b8 = (local_108 + local_138[0]) * _DAT_0059e880;
  local_148 = (local_f0 + local_138[3]) * _DAT_0059e880;
  local_b8 = (double)*(int *)(param_2 + 0xc44) * *(double *)(param_2 + 0xc38) +
             *(double *)(param_2 + 0xc30);
  local_1b0 = (local_138[5] + local_138[2]) * _DAT_0059e880;
  local_140 = local_140 * _DAT_0059e880;
  local_1d0 = (local_148 - local_1b8) *
              ((double)*(int *)(param_2 + 0xc04) * *(double *)(param_2 + 0xbf8) +
              *(double *)(param_2 + 0xbf0)) + local_1b8;
  local_1c8 = (double)(fVar2 + (float)*(double *)(param_3 + 0x60));
  local_1c0 = (local_140 - local_1b0) * local_b8 + local_1b0;
  local_190 = -((dVar6 + dVar3) / *(double *)(param_1 + 0x15f4));
  dVar3 = local_1d0 + local_190 * (local_160 - local_1d0);
  local_150 = ((local_b0[0] + local_150) * dVar10 - local_1c0) * local_190 + local_1c0;
  local_1a8 = local_1d0 - dVar3;
  local_1a0 = local_1c8 -
              (((dVar6 * (local_1a0 - dVar4) + local_158) * dVar10 - local_1c8) * local_190 +
              local_1c8);
  local_198 = local_1c0 - local_150;
  pdVar16 = &local_1a8;
  puVar24 = (undefined4 *)(param_1 + 0x15fc);
  for (iVar18 = 6; iVar18 != 0; iVar18 = iVar18 + -1) {
    *puVar24 = *(undefined4 *)pdVar16;
    pdVar16 = (double *)((int)pdVar16 + 4);
    puVar24 = puVar24 + 1;
  }
  *(double *)(param_1 + 0x1614) = -dVar3;
  *(double *)(param_1 + 0x161c) = -local_1c8;
  *(double *)(param_1 + 0x1624) = -local_150;
  *(double *)(param_1 + 0x1614) = *(double *)(param_3 + 0x70) + *(double *)(param_1 + 0x1614);
  fVar26 = (float10)*(double *)(param_3 + 0x80) + (float10)*(double *)(param_1 + 0x1624);
  *(double *)(param_1 + 0x1624) = (double)fVar26;
  dVar3 = *(double *)(param_1 + 0x1614);
  dVar5 = *(double *)(param_1 + 0x161c);
  *(float *)(iVar15 + 0x738) = (float)dVar3;
  local_190 = (double)CONCAT44((float)dVar5,(float)dVar3);
  *(float *)(iVar15 + 0x73c) = (float)dVar5;
  fVar2 = (float)fVar26;
  local_188 = (double)CONCAT44(local_188._4_4_,fVar2);
  *(float *)(iVar15 + 0x740) = fVar2;
  iVar15 = 0;
  do {
    iVar18 = iVar15 + 0x18;
    local_1a8 = *(double *)((int)local_138 + iVar15) + *(double *)(param_1 + 0x1614);
    local_1a0 = *(double *)((int)local_138 + iVar15 + 8) + *(double *)(param_1 + 0x161c);
    local_198 = *(double *)(param_1 + 0x1624) + *(double *)((int)local_138 + iVar15 + 0x10);
    pdVar16 = &local_1a8;
    puVar24 = (undefined4 *)((int)local_88 + iVar15);
    for (iVar14 = 6; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar24 = *(undefined4 *)pdVar16;
      pdVar16 = (double *)((int)pdVar16 + 4);
      puVar24 = puVar24 + 1;
    }
    iVar15 = iVar18;
  } while (iVar18 < 0x60);
  local_b0[4] = (dVar6 + *(double *)(param_1 + 0x15f4)) * _DAT_0059ea58;
  dVar5 = (local_1b0 -
          (local_b0[0] * _DAT_0059ea58 * (_DAT_0059e420 / local_b0[4]) -
          *(double *)(param_1 + 0x1624))) / (local_1b0 - local_140);
  dVar3 = (local_1b8 -
          (local_c0 * _DAT_0059ea58 * (_DAT_0059e420 / local_b0[4]) - *(double *)(param_1 + 0x1614))
          ) / (local_1b8 - local_148);
  local_b0[1] = local_b0[4] * (_DAT_0059e420 - dVar5) * (_DAT_0059e420 - dVar3);
  local_b0[2] = dVar3 * local_b0[4] * (_DAT_0059e420 - dVar5);
  local_b0[3] = dVar5 * local_b0[4] * (_DAT_0059e420 - dVar3);
  local_b0[4] = dVar3 * dVar5 * local_b0[4];
  iVar15 = FUN_004d7880();
  if (iVar15 == 0) {
    local_1b0._0_4_ = (double *)iVar15;
  }
  else {
    iVar15 = FUN_004d7570();
    local_1b0._0_4_ = (double *)iVar15;
  }
  local_190 = (double)CONCAT44(local_190._4_4_,local_80);
  pdVar16 = (double *)(param_2 + 0xf8);
  puVar22 = (undefined1 *)(param_1 + 0x451);
  iVar15 = 0;
  do {
    if ((double *)local_1b0 == (double *)0x0) {
      fVar26 = (float10)_DAT_0059ebc8;
      dVar3 = _DAT_0059ebc0;
    }
    else {
      if ((iVar15 == 0) || (iVar15 == 8)) {
        iVar18 = (int)(double *)local_1b0 + 0x18;
      }
      else {
        iVar18 = (int)(double *)local_1b0 + 0x160;
      }
      local_1b8 = (double)CONCAT44(local_1b8._4_4_,iVar18);
      fVar26 = (float10)FUN_004d6ae0((double)*(int *)((int)pdVar16 + 0xc) * *pdVar16 + pdVar16[-1]);
      dVar3 = *(double *)(local_1b8._0_4_ + 0x20);
    }
    if (*(int *)(puVar22 + -0x65) == 0) {
      dVar5 = *(double *)(*(int *)(param_1 + 0x141c) + 0xac);
      *puVar22 = 1;
      fVar27 = (float10)dVar5 * (float10)_DAT_0059e880;
    }
    else {
      fVar27 = (float10)*(double *)(*(int *)(puVar22 + -0x65) + 0xac);
      *puVar22 = 0;
    }
    fVar26 = ((fVar27 + (float10)*(double *)(*(int *)(puVar22 + -0x69) + 0xac)) *
              (float10)_DAT_0059ea58 + (float10)*(double *)((int)local_b0 + iVar15 + 8)) / fVar26;
    *(double *)((int)adStack_28 + iVar15) = (double)((float10)dVar3 - fVar26);
    iVar18 = *(int *)((int)pdVar16 + 0x4c);
    dVar5 = pdVar16[8];
    dVar4 = pdVar16[7];
    dVar6 = *(double *)(param_3 + 0x60);
    *(undefined4 *)(puVar22 + 3) = 0;
    *(undefined4 *)(puVar22 + 7) = 0;
    *(double *)local_190 =
         (double)((((float10)dVar3 - ((float10)iVar18 * (float10)dVar5 + (float10)dVar4)) -
                  (float10)dVar6) - fVar26);
    if ((iVar15 == 0) || (iVar15 == 8)) {
      dVar3 = (double)*(int *)(param_2 + 0xd84) * *(double *)(param_2 + 0xd78) +
              *(double *)(param_2 + 0xd70);
    }
    else {
      dVar3 = (double)*(int *)(param_2 + 0xdc4) * *(double *)(param_2 + 0xdb8) +
              *(double *)(param_2 + 0xdb0);
    }
    *(double *)(puVar22 + 0xb) = dVar3 * _DAT_0059e880;
    if ((iVar15 == 0) || (iVar15 == 0x10)) {
      dVar3 = -((double)*(int *)((int)pdVar16 + -0x34) * pdVar16[-8] + pdVar16[-9]);
    }
    else {
      *(double *)(puVar22 + 0xb) = -*(double *)(puVar22 + 0xb);
      dVar3 = (double)*(int *)((int)pdVar16 + -0x34) * pdVar16[-8] + pdVar16[-9];
    }
    *(double *)(puVar22 + 0x13) = dVar3;
    *(undefined4 *)(puVar22 + 0x1b) = 0;
    *(undefined4 *)(puVar22 + 0x1f) = 0;
    iVar15 = iVar15 + 8;
    pdVar16 = pdVar16 + 0x58;
    puVar22 = puVar22 + 0x464;
    local_190 = (double)CONCAT44(local_190._4_4_,(double *)local_190 + 3);
  } while (iVar15 < 0x20);
  iVar15 = *(int *)(param_1 + 0x141c);
  local_d8 = 0.0;
  local_d0 = 0.0;
  local_c8 = 0.0;
  if (iVar15 != 0) {
    iVar18 = *(int *)(param_1 + 0x1114);
    iVar14 = *(int *)(param_1 + 0xcb0);
    local_1a0 = local_50 - *(double *)(iVar14 + 0xc);
    local_198 = local_48 - *(double *)(iVar14 + 0x14);
    local_160 = (local_58 - *(double *)(iVar14 + 4)) + (local_40 - *(double *)(iVar18 + 4));
    local_178 = local_160 * _DAT_0059e880;
    local_170 = ((local_38 - *(double *)(iVar18 + 0xc)) + local_1a0) * _DAT_0059e880;
    local_168 = ((local_30 - *(double *)(iVar18 + 0x14)) + local_198) * _DAT_0059e880;
    local_1d0 = local_178 + *(double *)(iVar15 + 4);
    local_1c8 = local_170 + *(double *)(iVar15 + 0xc);
    local_1c0 = local_168 + *(double *)(iVar15 + 0x14);
    pdVar16 = &local_1d0;
    pdVar20 = (double *)(iVar15 + 4);
    for (iVar18 = 6; iVar18 != 0; iVar18 = iVar18 + -1) {
      *(undefined4 *)pdVar20 = *(undefined4 *)pdVar16;
      pdVar16 = (double *)((int)pdVar16 + 4);
      pdVar20 = (double *)((int)pdVar20 + 4);
    }
    iVar15 = 0;
    local_1b8 = (double)((ulonglong)local_1b8 & 0xffffffff00000000);
    if (0 < *(int *)(param_1 + 0x15b4)) {
      local_1dc = (int *)0x0;
      do {
        iVar18 = *(int *)(*(int *)(param_1 + 0x15b8) + 4 + (int)local_1dc);
        iVar14 = *(int *)(param_1 + 0x15b8) + (int)local_1dc;
        if ((iVar18 == *(int *)(param_1 + 0x15f0)) &&
           (*(int *)(iVar14 + 0xc) == *(int *)(param_1 + 0x141c))) {
          pdVar16 = *(double **)(iVar14 + 8);
          *pdVar16 = local_178 + *pdVar16;
          pdVar16[1] = local_170 + pdVar16[1];
          pdVar16[2] = local_168 + pdVar16[2];
          FUN_0043aee0(*(int *)(param_1 + 0x15f0) + 4,*(undefined4 *)(iVar14 + 8),&local_1a8);
          uVar19 = *(undefined4 *)(iVar14 + 0x10);
LAB_00439f14:
          local_1b8 = (double)CONCAT44(local_1b8._4_4_,uVar19);
        }
        else if ((*(int *)(iVar14 + 0xc) == *(int *)(param_1 + 0x15f0)) &&
                (iVar18 == *(int *)(param_1 + 0x141c))) {
          pdVar16 = *(double **)(iVar14 + 0x10);
          *pdVar16 = local_178 + *pdVar16;
          pdVar16[1] = local_170 + pdVar16[1];
          pdVar16[2] = local_168 + pdVar16[2];
          FUN_0043aee0(*(int *)(param_1 + 0x15f0) + 4,*(undefined4 *)(iVar14 + 0x10),&local_1a8);
          uVar19 = *(undefined4 *)(iVar14 + 8);
          goto LAB_00439f14;
        }
        iVar15 = iVar15 + 1;
        local_1dc = (int *)((int)local_1dc + 0x30);
      } while (iVar15 < *(int *)(param_1 + 0x15b4));
      if (local_1b8._0_4_ != 0) {
        dVar3 = local_1d0 - local_1a8;
        dVar5 = local_1c8 - local_1a0;
        dVar4 = local_1c0 - local_198;
        local_1d0 = local_58 - local_40;
        local_1c8 = local_50 - local_38;
        local_1c0 = local_48 - local_30;
        pdVar16 = &local_1d0;
        puVar25 = &local_190;
        for (iVar15 = 6; iVar15 != 0; iVar15 = iVar15 + -1) {
          *(undefined4 *)puVar25 = *(undefined4 *)pdVar16;
          pdVar16 = (double *)((int)pdVar16 + 4);
          puVar25 = (undefined8 *)((int)puVar25 + 4);
        }
        dVar6 = _DAT_0059e420 /
                SQRT(local_1d0 * local_1d0 + local_1c8 * local_1c8 + local_1c0 * local_1c0);
        local_190 = local_1d0 * dVar6;
        local_188 = local_188 * dVar6;
        local_180 = local_180 * dVar6;
        local_1d0 = dVar5 * local_180 - dVar4 * local_188;
        local_1c8 = dVar4 * local_190 - local_180 * dVar3;
        dVar3 = local_188 * dVar3 - dVar5 * local_190;
        dVar5 = _DAT_0059e420 / SQRT(local_1d0 * local_1d0 + local_1c8 * local_1c8 + dVar3 * dVar3);
        local_1d0 = local_1d0 * dVar5;
        local_1c8 = local_1c8 * dVar5;
        local_160 = local_188 * dVar5 * dVar3 - local_180 * local_1c8;
        local_158 = local_180 * local_1d0 - dVar5 * dVar3 * local_190;
        local_150 = local_1c8 * local_190 - local_188 * local_1d0;
        dVar3 = _DAT_0059e420 /
                SQRT(local_160 * local_160 + local_158 * local_158 + local_150 * local_150);
        local_160 = local_160 * dVar3;
        local_158 = local_158 * dVar3;
        local_150 = local_150 * dVar3;
        fVar26 = (float10)FUN_00588570();
        local_d8 = (double)-fVar26;
        if (ABS(local_158) == _DAT_0059e420) {
          local_c8 = 0.0;
          fVar26 = (float10)fpatan(-(float10)local_180,(float10)local_190);
        }
        else {
          fVar26 = (float10)fpatan((float10)local_160,(float10)local_150);
          fVar27 = (float10)fpatan((float10)local_188,(float10)local_1c8);
          local_c8 = (double)fVar27;
        }
        local_d0 = (double)fVar26;
        FUN_005691d0();
        FUN_004361d0(*(int *)(param_1 + 0x141c) + 4,&local_1a8,SUB84(local_1b8,0));
      }
    }
    local_1b0._0_4_ = (double *)0x0;
    local_1b8 = local_50 - adStack_28[2];
    local_c0 = local_38 - adStack_28[3];
    if (0 < *(int *)(param_1 + 0x15c4)) {
      local_1dc = (int *)0x0;
      do {
        iVar15 = *(int *)(*(int *)(param_1 + 0x15c8) + 4 + (int)local_1dc);
        iVar18 = *(int *)(param_1 + 0x15c8) + (int)local_1dc;
        if ((iVar15 == *(int *)(param_1 + 0x15f0)) &&
           (*(int *)(iVar18 + 0xc) == *(int *)(param_1 + 0x141c))) {
          pdVar16 = *(double **)(iVar18 + 8);
          iVar15 = *(int *)(iVar18 + 0x10);
LAB_0043a218:
          if ((pdVar16 != (double *)0x0) && (iVar15 != 0)) {
            pdVar20 = pdVar16 + 3;
            *pdVar16 = local_178 + *pdVar16;
            pdVar16[1] = local_170 + pdVar16[1];
            pdVar16[2] = local_168 + pdVar16[2];
            *pdVar20 = local_178 + *pdVar20;
            pdVar16[4] = local_170 + pdVar16[4];
            pdVar16[5] = local_168 + pdVar16[5];
            FUN_0043aee0(*(int *)(param_1 + 0x15f0) + 4,pdVar16,&local_1d0);
            local_148 = (double)*(int *)(param_2 + 0xf44) * *(double *)(param_2 + 0xf38) +
                        *(double *)(param_2 + 0xf30);
            local_140 = local_40 - local_58;
            local_190 = local_c0 - local_1b8;
            local_1c8 = ((*pdVar20 - local_58) / local_140) * local_190 + local_148 + local_1b8;
            FUN_004361d0(*(int *)(param_1 + 0x15f0) + 4,&local_1d0,pdVar16);
            FUN_004388d0(pdVar16,pdVar20);
            *(double *)(param_1 + 0x1420) = pdVar16[1] - local_148;
            FUN_0043aee0(*(int *)(param_1 + 0x141c) + 4,iVar15,&local_160);
            local_158 = ((*(double *)(iVar15 + 0x18) - local_58) / local_140) * local_190 +
                        (double)*(int *)(param_2 + 0xf04) * *(double *)(param_2 + 0xef8) +
                        *(double *)(param_2 + 0xef0) + local_1b8;
            FUN_004361d0(*(int *)(param_1 + 0x141c) + 4,&local_160,iVar15);
            FUN_00435e00(iVar15,(double *)(iVar15 + 0x18));
          }
        }
        else if ((*(int *)(iVar18 + 0xc) == *(int *)(param_1 + 0x15f0)) &&
                (iVar15 == *(int *)(param_1 + 0x141c))) {
          pdVar16 = *(double **)(iVar18 + 0x10);
          iVar15 = *(int *)(iVar18 + 8);
          goto LAB_0043a218;
        }
        local_1b0._0_4_ = (double *)((int)(double *)local_1b0 + 1);
        local_1dc = (int *)((int)local_1dc + 0x48);
      } while ((int)(double *)local_1b0 < *(int *)(param_1 + 0x15c4));
    }
  }
  iVar15 = 0;
  local_1b0 = (double)CONCAT44(local_1b0._4_4_,local_88);
  local_190 = (double)CONCAT44(local_190._4_4_,param_1 + 0x3ec);
  do {
    if (((iVar15 == 2) || (iVar15 == 3)) && (*(int *)(param_1 + 0x141c) != 0)) {
      pdVar16 = &local_d8;
      pdVar20 = &local_1d0;
      for (iVar18 = 6; iVar18 != 0; iVar18 = iVar18 + -1) {
        *(undefined4 *)pdVar20 = *(undefined4 *)pdVar16;
        pdVar16 = (double *)((int)pdVar16 + 4);
        pdVar20 = (double *)((int)pdVar20 + 4);
      }
    }
    else {
      local_1d0 = 0.0;
      local_1c8 = 0.0;
      local_1c0 = 0.0;
    }
    FUN_0056bd40();
    iVar18 = (int)(double *)local_190;
    puVar24 = (undefined4 *)((int)(double *)local_190 + -0xe4);
    FUN_0056bde0((int)(double *)local_190 + 0x68,&local_1d0);
    iVar18 = *(int *)(iVar18 + -4);
    local_160 = *(double *)local_1b0 - *(double *)(iVar18 + 4);
    local_158 = ((double *)local_1b0)[1] - *(double *)(iVar18 + 0xc);
    local_150 = ((double *)local_1b0)[2] - *(double *)(iVar18 + 0x14);
    pdVar16 = (double *)local_1b0;
    for (iVar14 = 6; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar24 = *(undefined4 *)pdVar16;
      pdVar16 = (double *)((int)pdVar16 + 4);
      puVar24 = puVar24 + 1;
    }
    pdVar16 = &local_1d0;
    piVar17 = (int *)((int)(double *)local_190 + -0xcc);
    for (iVar14 = 6; iVar14 != 0; iVar14 = iVar14 + -1) {
      *piVar17 = *(int *)pdVar16;
      pdVar16 = (double *)((int)pdVar16 + 4);
      piVar17 = piVar17 + 1;
    }
    if (*(int *)(double *)local_190 != 0) {
      FUN_004361d0(iVar18 + 4,*(int *)(double *)local_190 + 4,&local_1a8);
    }
    puVar24 = (undefined4 *)(double *)local_1b0;
    pdVar16 = (double *)(iVar18 + 4);
    for (iVar14 = 6; iVar14 != 0; iVar14 = iVar14 + -1) {
      *(undefined4 *)pdVar16 = *puVar24;
      puVar24 = puVar24 + 1;
      pdVar16 = (double *)((int)pdVar16 + 4);
    }
    FUN_005691d0();
    piVar17 = (int *)(double *)local_190;
    if (*(int *)(double *)local_190 == 0) {
      local_1b8 = (double)((ulonglong)local_1b8 & 0xffffffff00000000);
      if (0 < *(int *)(param_1 + 0x15bc)) {
        local_1dc = (int *)0x0;
        do {
          iVar18 = *(int *)(*(int *)(param_1 + 0x15c0) + 4 + (int)local_1dc);
          iVar14 = *(int *)(param_1 + 0x15c0) + (int)local_1dc;
          if ((iVar18 == *(int *)((int)(double *)local_190 + -4)) &&
             (*(int *)(iVar14 + 0xc) == *(int *)(param_1 + 0x141c))) {
            iVar18 = *(int *)(iVar14 + 8);
            iVar14 = *(int *)(iVar14 + 0x10);
LAB_0043a641:
            if ((iVar18 != 0) && (iVar14 != 0)) {
              FUN_00435e00(iVar18,&local_178);
              FUN_004388d0(&local_178,iVar14);
              FUN_00435e00(iVar18 + 0x18,&local_178);
              FUN_004388d0(&local_178,iVar14 + 0x18);
              iVar9 = *(int *)((int)(double *)local_190 + -4);
              local_178 = *(double *)(iVar9 + 0x1c) * *(double *)(iVar18 + 0x30) +
                          *(double *)(iVar9 + 0x24) * *(double *)(iVar18 + 0x38) +
                          *(double *)(iVar9 + 0x2c) * *(double *)(iVar18 + 0x40);
              local_170 = *(double *)(iVar9 + 0x3c) * *(double *)(iVar18 + 0x38) +
                          *(double *)(iVar9 + 0x44) * *(double *)(iVar18 + 0x40) +
                          *(double *)(iVar9 + 0x34) * *(double *)(iVar18 + 0x30);
              iVar23 = *(int *)(param_1 + 0x141c);
              local_168 = *(double *)(iVar9 + 0x54) * *(double *)(iVar18 + 0x38) +
                          *(double *)(iVar9 + 0x5c) * *(double *)(iVar18 + 0x40) +
                          *(double *)(iVar9 + 0x4c) * *(double *)(iVar18 + 0x30);
              *(double *)(iVar14 + 0x30) =
                   local_178 * *(double *)(iVar23 + 0x1c) +
                   local_170 * *(double *)(iVar23 + 0x34) + local_168 * *(double *)(iVar23 + 0x4c);
              *(double *)(iVar14 + 0x38) =
                   local_170 * *(double *)(iVar23 + 0x3c) +
                   local_168 * *(double *)(iVar23 + 0x54) + local_178 * *(double *)(iVar23 + 0x24);
              *(double *)(iVar14 + 0x40) =
                   local_170 * *(double *)(iVar23 + 0x44) +
                   local_168 * *(double *)(iVar23 + 0x5c) + local_178 * *(double *)(iVar23 + 0x2c);
            }
          }
          else if ((*(int *)(iVar14 + 0xc) == *(int *)((int)(double *)local_190 + -4)) &&
                  (iVar18 == *(int *)(param_1 + 0x141c))) {
            iVar18 = *(int *)(iVar14 + 0x10);
            iVar14 = *(int *)(iVar14 + 8);
            goto LAB_0043a641;
          }
          iVar18 = local_1b8._0_4_ + 1;
          local_1dc = (int *)((int)local_1dc + 0x30);
          local_1b8 = (double)CONCAT44(local_1b8._4_4_,iVar18);
        } while (iVar18 < *(int *)(param_1 + 0x15bc));
      }
      iVar18 = 0;
      local_1b8 = (double)((ulonglong)local_1b8 & 0xffffffff00000000);
      if (0 < *(int *)(param_1 + 0x15b4)) {
        do {
          iVar14 = *(int *)(*(int *)(param_1 + 0x15b8) + 4 + iVar18);
          iVar9 = *(int *)((int)(double *)local_190 + -4);
          iVar23 = *(int *)(param_1 + 0x15b8) + iVar18;
          if ((iVar14 == iVar9) && (*(int *)(iVar23 + 0xc) == *(int *)(param_1 + 0x141c))) {
            FUN_0043aee0(iVar9 + 4,*(undefined4 *)(iVar23 + 8),&local_178);
            uVar19 = *(undefined4 *)(iVar23 + 0x10);
LAB_0043a7f6:
            FUN_004361d0(*(int *)(param_1 + 0x141c) + 4,&local_178,uVar19);
          }
          else if ((*(int *)(iVar23 + 0xc) == iVar9) && (iVar14 == *(int *)(param_1 + 0x141c))) {
            FUN_0043aee0(iVar9 + 4,*(undefined4 *)(iVar23 + 0x10),&local_178);
            uVar19 = *(undefined4 *)(iVar23 + 8);
            goto LAB_0043a7f6;
          }
          iVar14 = local_1b8._0_4_ + 1;
          iVar18 = iVar18 + 0x30;
          local_1b8 = (double)CONCAT44(local_1b8._4_4_,iVar14);
        } while (iVar14 < *(int *)(param_1 + 0x15b4));
      }
    }
    else {
      FUN_0043aee0(*(int *)((int)(double *)local_190 + -4) + 4,&local_1a8,
                   *(int *)(double *)local_190 + 4);
      FUN_005691d0();
      local_1b8 = (double)((ulonglong)local_1b8 & 0xffffffff00000000);
      if (0 < *(int *)(param_1 + 0x15c4)) {
        local_1dc = (int *)0x0;
        do {
          iVar18 = *(int *)(*(int *)(param_1 + 0x15c8) + 4 + (int)local_1dc);
          iVar14 = *(int *)(param_1 + 0x15c8) + (int)local_1dc;
          if ((iVar18 == *(int *)(param_1 + 0x15f0)) && (*(int *)(iVar14 + 0xc) == *piVar17)) {
            pdVar16 = *(double **)(iVar14 + 8);
LAB_0043a586:
            *pdVar16 = local_160 + *pdVar16;
            pdVar16[1] = local_158 + pdVar16[1];
            pdVar16[2] = local_150 + pdVar16[2];
          }
          else if ((*(int *)(iVar14 + 0xc) == *(int *)(param_1 + 0x15f0)) && (iVar18 == *piVar17)) {
            pdVar16 = *(double **)(iVar14 + 0x10);
            goto LAB_0043a586;
          }
          iVar18 = local_1b8._0_4_ + 1;
          local_1dc = (int *)((int)local_1dc + 0x48);
          local_1b8 = (double)CONCAT44(local_1b8._4_4_,iVar18);
        } while (iVar18 < *(int *)(param_1 + 0x15c4));
      }
      piVar17[0x1a] = 0;
      piVar17[0x1b] = 0;
      piVar17[0x1c] = 0;
      piVar17[0x1d] = 0;
      piVar17[0x1e] = 0;
      piVar17[0x1f] = 0;
    }
    iVar15 = iVar15 + 1;
    local_190 = (double)CONCAT44(local_190._4_4_,(int)(double *)local_190 + 0x464);
    local_1b0 = (double)CONCAT44(local_1b0._4_4_,(int)(double *)local_1b0 + 0x18);
    if (3 < iVar15) {
      local_1dc = (int *)(param_1 + 1000);
      local_1d8 = (double *)(param_3 + 0x1460);
      local_1b0._0_4_ = (double *)0x4;
      do {
        puVar24 = (undefined4 *)(*local_1dc + 0xbc);
        pdVar16 = &local_1a8;
        for (iVar15 = 6; iVar15 != 0; iVar15 = iVar15 + -1) {
          *(undefined4 *)pdVar16 = *puVar24;
          puVar24 = puVar24 + 1;
          pdVar16 = (double *)((int)pdVar16 + 4);
        }
        local_1a8 = *local_1d8;
        FUN_005697a0();
        local_1d8 = local_1d8 + 0x21;
        local_1dc = local_1dc + 0x119;
        local_1b0._0_4_ = (double *)((int)(double *)local_1b0 + -1);
      } while ((double *)local_1b0 != (double *)0x0);
      uVar7 = *(undefined8 *)(param_3 + 0x58);
      pdVar16 = (double *)(param_3 + 0x48);
      uVar8 = *(undefined8 *)(param_3 + 0x50);
      iVar15 = 0;
      *(double *)(param_1 + 0xd4) = *pdVar16;
      *(undefined8 *)(param_1 + 0xdc) = uVar8;
      *(undefined8 *)(param_1 + 0xe4) = uVar7;
      if (0 < *(int *)(param_1 + 0x15ac)) {
        iVar18 = 0;
        do {
          iVar14 = *(int *)(param_1 + 0x15b0) + iVar18;
          if (((iVar14 != *(int *)(param_1 + 0x15f0)) && (iVar14 != *(int *)(param_1 + 0x1d4))) &&
             (iVar14 != *(int *)(param_1 + 0x1e8))) {
            *pdVar16 = *pdVar16 - *(double *)(iVar14 + 0xbc);
            *(double *)(param_3 + 0x50) = *(double *)(param_3 + 0x50) - *(double *)(iVar14 + 0xc4);
            *(double *)(param_3 + 0x58) = *(double *)(param_3 + 0x58) - *(double *)(iVar14 + 0xcc);
            dVar3 = *(double *)(iVar14 + 4) * *(double *)(iVar14 + 4);
            dVar4 = *(double *)(iVar14 + 0xc) * *(double *)(iVar14 + 0xc);
            dVar5 = *(double *)(iVar14 + 0x14) * *(double *)(iVar14 + 0x14);
            *pdVar16 = *pdVar16 - SQRT(dVar5 + dVar4) * *(double *)(iVar14 + 0xac);
            *(double *)(param_3 + 0x50) =
                 *(double *)(param_3 + 0x50) - SQRT(dVar5 + dVar3) * *(double *)(iVar14 + 0xac);
            *(double *)(param_3 + 0x58) =
                 *(double *)(param_3 + 0x58) - SQRT(dVar4 + dVar3) * *(double *)(iVar14 + 0xac);
          }
          iVar15 = iVar15 + 1;
          iVar18 = iVar18 + 0x244;
        } while (iVar15 < *(int *)(param_1 + 0x15ac));
      }
      if ((((*pdVar16 < _DAT_0059e430 != (*pdVar16 == _DAT_0059e430)) ||
           (*(double *)(param_3 + 0x50) < _DAT_0059e430 !=
            (*(double *)(param_3 + 0x50) == _DAT_0059e430))) ||
          (*(double *)(param_3 + 0x58) < _DAT_0059e430 !=
           (*(double *)(param_3 + 0x58) == _DAT_0059e430))) &&
         ((DAT_007c569c != 5 &&
          (cVar12 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_hdveh_005c421c,0xa00),
          cVar12 != '\0')))) {
        FUN_004d7aa0(&DAT_008ad25c,s_Vehicle_has_zero_or_negative_ine_005c41dc);
      }
      FUN_005697a0();
      FUN_0043b040(param_2,param_3);
      FUN_0043b590(param_2,param_3);
      iVar15 = 0;
      if (0 < *(int *)(param_1 + 0x15c4)) {
        do {
          FUN_0056d1c0();
          iVar15 = iVar15 + 1;
        } while (iVar15 < *(int *)(param_1 + 0x15c4));
      }
      iVar15 = 0;
      if (0 < *(int *)(param_1 + 0x15b4)) {
        do {
          FUN_0056cf70();
          iVar15 = iVar15 + 1;
        } while (iVar15 < *(int *)(param_1 + 0x15b4));
      }
      iVar15 = 0;
      if (0 < *(int *)(param_1 + 0x15bc)) {
        do {
          FUN_0056d020();
          iVar15 = iVar15 + 1;
        } while (iVar15 < *(int *)(param_1 + 0x15bc));
      }
      iVar15 = 0;
      if (0 < *(int *)(param_1 + 0x15c4)) {
        do {
          FUN_0056d2d0();
          iVar15 = iVar15 + 1;
        } while (iVar15 < *(int *)(param_1 + 0x15c4));
      }
      dVar3 = _DAT_0059e420;
      if (DAT_007ce958 != 0) {
        dVar3 = _DAT_0059ebb8;
      }
      *(double *)(param_3 + 0x538) = dVar3;
      dVar3 = _DAT_0059e420;
      if (DAT_007ce958 != 0) {
        dVar3 = _DAT_0059ebb0;
      }
      *(double *)(param_3 + 0x540) = dVar3;
      iVar15 = 0;
      pdVar16 = (double *)(param_1 + 0x400);
      pdVar20 = (double *)(param_3 + 0x1428);
      local_1d8 = (double *)(param_2 + 0x1b8);
      do {
        iVar18 = *(int *)((int)pdVar16 + -0x14);
        if (iVar18 == 0) {
          iVar18 = *(int *)(param_1 + 0x141c);
        }
        iVar14 = *(int *)(pdVar16 + -3);
        dVar3 = pdVar20[-2] + *(double *)(iVar14 + 4);
        dVar10 = pdVar20[-1] + *(double *)(iVar14 + 0xc);
        local_1c0 = *(double *)(iVar14 + 0x14) + *pdVar20;
        dVar5 = dVar3 - *(double *)(iVar18 + 4);
        dVar6 = dVar10 - *(double *)(iVar18 + 0xc);
        dVar4 = local_1c0 - *(double *)(iVar18 + 0x14);
        pdVar16[-2] = dVar5 * *(double *)(iVar18 + 0x1c) +
                      dVar6 * *(double *)(iVar18 + 0x34) + dVar4 * *(double *)(iVar18 + 0x4c);
        pdVar16[-1] = dVar5 * *(double *)(iVar18 + 0x24) +
                      dVar6 * *(double *)(iVar18 + 0x3c) + dVar4 * *(double *)(iVar18 + 0x54);
        *pdVar16 = dVar5 * *(double *)(iVar18 + 0x2c) +
                   dVar6 * *(double *)(iVar18 + 0x44) + dVar4 * *(double *)(iVar18 + 0x5c);
        iVar18 = *(int *)(pdVar16 + -3);
        local_160 = pdVar20[1] + *(double *)(iVar18 + 4);
        local_1a0 = pdVar20[2] + *(double *)(iVar18 + 0xc);
        local_198 = pdVar20[3] + *(double *)(iVar18 + 0x14);
        iVar18 = *(int *)(param_1 + 0x15f0);
        dVar5 = local_160 - *(double *)(iVar18 + 4);
        dVar6 = local_1a0 - *(double *)(iVar18 + 0xc);
        dVar4 = local_198 - *(double *)(iVar18 + 0x14);
        pdVar16[4] = dVar5 * *(double *)(iVar18 + 0x1c) +
                     dVar6 * *(double *)(iVar18 + 0x34) + dVar4 * *(double *)(iVar18 + 0x4c);
        pdVar16[5] = dVar5 * *(double *)(iVar18 + 0x24) +
                     dVar6 * *(double *)(iVar18 + 0x3c) + dVar4 * *(double *)(iVar18 + 0x54);
        pdVar16[6] = dVar5 * *(double *)(iVar18 + 0x2c) +
                     dVar6 * *(double *)(iVar18 + 0x44) + dVar4 * *(double *)(iVar18 + 0x5c);
        local_160 = local_160 - dVar3;
        dVar10 = local_1a0 - dVar10;
        local_148 = SQRT(local_160 * local_160 +
                         dVar10 * dVar10 + (local_198 - local_1c0) * (local_198 - local_1c0));
        dVar10 = (_DAT_0059e420 / local_148) * dVar10;
        pdVar20[8] = dVar10 * dVar10;
        if ((iVar15 == 0) || (iVar15 == 1)) {
          bVar11 = 1;
        }
        else {
          bVar11 = 0;
        }
        iVar18 = ((-(uint)bVar11 & 0xfffffffa) + 0x16) * 0x40;
        pdVar1 = (double *)(iVar18 + 0xbb0 + param_2);
        iVar15 = iVar15 + 1;
        dVar3 = ((double)*(int *)((int)local_1d8 + 0xc) * *local_1d8 + local_1d8[-1] +
                ((double)*(int *)(iVar18 + 0xbc4 + param_2) * pdVar1[1] + *pdVar1) * _DAT_0059e880)
                * *(double *)(param_3 + 0x538);
        pdVar20[9] = local_b0[iVar15] / dVar3;
        *(double *)((int)pdVar16 + 0x84) =
             local_b0[iVar15] / ((dVar3 / (dVar10 * dVar10)) * ABS(dVar10)) + local_148;
        pdVar16 = (double *)((int)pdVar16 + 0x464);
        pdVar20 = pdVar20 + 0x21;
        local_1d8 = local_1d8 + 0x58;
      } while (iVar15 < 4);
      *(undefined4 *)(param_1 + 0x1428) = 0;
      *(undefined4 *)(param_1 + 0x142c) = 0;
      *(double *)(param_1 + 0x1430) =
           -(SQRT(*(double *)(param_3 + 0x1678)) * *(double *)(param_3 + 0x68));
      FUN_0043bb00((double)*(int *)(param_2 + 0xc84) * *(double *)(param_2 + 0xc78) +
                   *(double *)(param_2 + 0xc70));
      fVar27 = (float10)FUN_004390a0(param_2,param_3);
      fVar26 = (float10)_DAT_0059eba8;
      iVar15 = *(int *)(param_1 + 0x1114);
      iVar18 = *(int *)(param_1 + 0xcb0);
      *(double *)(param_1 + 0x1448) =
           (double)(((float10)_DAT_0059e420 - (float10)*(double *)(param_3 + 0x538)) *
                    ((float10)_DAT_0059e420 - (float10)local_b8) *
                    SQRT((float10)_DAT_0059e880 / (float10)*(double *)(param_3 + 0x1468) +
                         (float10)_DAT_0059e880 / (float10)*(double *)(param_3 + 0x1570)) *
                    -fVar27 * fVar26 * (float10)_DAT_0059e880);
      *(double *)(param_1 + 0x1450) =
           (double)(((float10)_DAT_0059e420 - (float10)*(double *)(param_3 + 0x538)) *
                    (float10)local_b8 *
                    SQRT((float10)_DAT_0059e880 / (float10)*(double *)(param_3 + 0x1678) +
                         (float10)_DAT_0059e880 / (float10)*(double *)(param_3 + 0x1780)) *
                    -fVar27 * fVar26 * (float10)_DAT_0059e880);
      local_1c0 = *(double *)(iVar18 + 0x14) + *(double *)(iVar15 + 0x14);
      dVar3 = (*(double *)(iVar18 + 4) + *(double *)(iVar15 + 4)) * _DAT_0059e880;
      iVar14 = *(int *)(param_1 + 0x15f0);
      dVar5 = (*(double *)(iVar18 + 0xc) + *(double *)(iVar15 + 0xc)) * _DAT_0059e880;
      local_1c0 = local_1c0 * _DAT_0059e880;
      local_1d0 = dVar3 * *(double *)(iVar14 + 0x1c) +
                  dVar5 * *(double *)(iVar14 + 0x34) + local_1c0 * *(double *)(iVar14 + 0x4c);
      local_1a8 = local_1d0 + *(double *)(param_3 + 0x1340);
      local_1a0 = -*(double *)(param_3 + 0x60) + *(double *)(param_3 + 0x1348);
      local_198 = dVar3 * *(double *)(iVar14 + 0x2c) +
                  dVar5 * *(double *)(iVar14 + 0x44) + local_1c0 * *(double *)(iVar14 + 0x5c) +
                  *(double *)(param_3 + 0x1350);
      pdVar16 = &local_1a8;
      puVar24 = (undefined4 *)(param_1 + 0x1dfc);
      for (iVar15 = 6; iVar15 != 0; iVar15 = iVar15 + -1) {
        *puVar24 = *(undefined4 *)pdVar16;
        pdVar16 = (double *)((int)pdVar16 + 4);
        puVar24 = puVar24 + 1;
      }
      return;
    }
  } while( true );
}


