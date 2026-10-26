// Function: FUN_00436870 @ 00436870
// Size (bytes): 6198


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00436870(int param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined4 uVar5;
  bool bVar6;
  bool bVar7;
  double dVar8;
  int iVar9;
  int iVar10;
  double *pdVar11;
  int iVar12;
  undefined4 *puVar13;
  double *pdVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float10 fVar18;
  double local_260;
  undefined8 local_258;
  double local_250;
  double local_248;
  double local_240;
  double local_238;
  double local_230;
  double local_228;
  double local_220;
  double local_218;
  double local_210;
  double local_208;
  double local_200;
  double local_1f8;
  double local_1f0;
  double local_1e8;
  double local_1e0;
  double local_1d8;
  double local_1d0;
  double local_1c8;
  undefined8 local_1c0;
  double local_1b8;
  double local_1b0;
  double local_1a8;
  undefined8 local_1a0;
  int local_194;
  double local_190;
  double local_188;
  double local_180;
  double local_178;
  double local_168;
  undefined8 local_160;
  double local_158;
  undefined8 local_150;
  double *local_148;
  double local_144;
  double local_13c;
  undefined4 local_134;
  undefined4 local_130;
  double *local_12c;
  undefined1 local_128 [92];
  double local_cc;
  double local_c4;
  double local_bc;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  double local_a4;
  int local_9c;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  undefined4 local_38 [6];
  undefined4 local_20 [7];
  
  *(undefined4 *)(param_1 + 0x31c) = 0;
  *(undefined4 *)(param_1 + 800) = 0;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x268) = 0;
  *(undefined4 *)(param_1 + 0x26c) = 0x3ff00000;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x324) = 0;
  *(undefined4 *)(param_1 + 0x328) = 0;
  if (*(char *)(param_1 + 0x1c4) != '\0') {
    *(undefined4 *)(param_1 + 0x264) = 0;
    *(undefined4 *)(param_1 + 0xfc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x100) = 0xffefffff;
    return;
  }
  iVar12 = *(int *)(param_1 + 0x15c);
  local_238 = *(double *)(iVar12 + 0x1c);
  local_230 = *(double *)(iVar12 + 0x34);
  local_228 = *(double *)(iVar12 + 0x4c);
  local_220 = local_228 - local_230 * _DAT_0059e430;
  dVar2 = local_238 * _DAT_0059e430 - local_228 * _DAT_0059e430;
  local_1d8 = local_230 * _DAT_0059e430 - local_238;
  dVar3 = SQRT(local_220 * local_220 + local_1d8 * local_1d8 + dVar2 * dVar2);
  if (dVar3 == _DAT_0059e430) {
    local_1d8 = 0.0;
    local_238 = 0.0;
    local_230 = 1.0;
    local_228 = 0.0;
    local_208 = 0.0;
    local_200 = 0.0;
    local_1f8 = 1.0;
    local_220 = _DAT_0059e420;
    dVar2 = _DAT_0059e430;
  }
  else {
    local_260 = _DAT_0059e420 / dVar3;
    local_220 = local_260 * local_220;
    dVar2 = dVar2 * local_260;
    local_1d8 = local_1d8 * local_260;
    local_208 = local_1d8 * local_230 - dVar2 * local_228;
    local_200 = local_220 * local_228 - local_1d8 * local_238;
    local_1f8 = local_238 * dVar2 - local_220 * local_230;
    if (local_200 < _DAT_0059e430) {
      local_208 = -local_208;
      local_200 = -local_200;
      local_1f8 = -local_1f8;
    }
    if (local_230 < _DAT_0059e430) {
      local_228 = -local_228;
      local_238 = -local_238;
      local_230 = -local_230;
    }
  }
  local_1f0 = *(double *)(param_1 + 0x224);
  local_1a0 = ABS(*(double *)(param_1 + 0xbc)) * *(double *)(param_1 + 0x214) +
              *(double *)(param_1 + 0x20c);
  local_1b0 = local_1a0 * local_200;
  local_240 = *(double *)(param_1 + 0x21c);
  local_250 = local_238 * local_240;
  local_248 = local_230 * local_240;
  local_240 = local_240 * local_228;
  local_220 = local_1f0 * local_220;
  dVar2 = dVar2 * local_1f0;
  local_210 = local_1d8 * local_1f0;
  local_1b8 = *(double *)(iVar12 + 4) - local_1a0 * local_208;
  dVar3 = *(double *)(iVar12 + 0xc) - local_1a0 * local_200;
  local_168 = *(double *)(iVar12 + 0x14) - local_1a0 * local_1f8;
  local_1e8 = local_1b8 - local_250;
  local_1e0 = dVar3 - local_248;
  local_1d8 = local_168 - local_240;
  local_1b8 = local_1b8 + local_250;
  dVar3 = dVar3 + local_248;
  local_1a8 = local_240 + local_168;
  local_98 = local_1e8 - local_220;
  local_90 = local_1e0 - dVar2;
  local_88 = local_1d8 - local_210;
  local_80 = local_1e8 + local_220;
  local_78 = dVar2 + local_1e0;
  local_70 = local_210 + local_1d8;
  local_68 = local_1b8 - local_220;
  local_194 = 3;
  local_60 = dVar3 - dVar2;
  local_58 = local_1a8 - local_210;
  if (DAT_007ce994 != '\0') {
    local_194 = 5;
    local_50 = local_1b8 + local_220;
    local_48 = dVar3 + dVar2;
    local_40 = local_210 + local_1a8;
    pdVar11 = (double *)(iVar12 + 4);
    puVar13 = local_38;
    for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar13 = *(undefined4 *)pdVar11;
      pdVar11 = (double *)((int)pdVar11 + 4);
      puVar13 = puVar13 + 1;
    }
  }
  local_1d0 = (double)((ulonglong)local_1d0 & 0xffffffff00000000);
  if (local_194 == 0) {
LAB_00436e3f:
    *(undefined4 *)(param_1 + 0x264) = 0;
    *(undefined4 *)(param_1 + 0xfc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x100) = 0xffefffff;
    return;
  }
  pdVar11 = &local_88;
  pdVar14 = &local_158;
  local_258._0_4_ = *(int *)(param_1 + 0x264);
  do {
    local_cc = pdVar11[-2];
    local_b4 = 0x33333333;
    local_c4 = pdVar11[-1] + _DAT_0059eb28;
    local_bc = *pdVar11;
    local_b0 = 0x3fd33333;
    local_ac = 0x40000000;
    local_a8 = 0x479e17b8;
    local_9c = (int)local_258;
    iVar10 = FUN_0044c4c0(&local_cc);
    *(int *)(pdVar14 + 2) = iVar10;
    iVar12 = local_1d0._0_4_;
    if (iVar10 != 0) {
      uVar5 = *(undefined4 *)(pdVar11 + -2);
      *(undefined4 *)((int)pdVar14 + -4) = *(undefined4 *)((int)pdVar11 + -0xc);
      *(undefined4 *)(pdVar14 + -1) = uVar5;
      iVar9 = *(int *)(iVar10 + 0x54);
      uVar5 = *(undefined4 *)((int)pdVar11 + 4);
      iVar12 = local_1d0._0_4_ + 1;
      fVar15 = (float10)fsin((float10)*(float *)(iVar9 + 0x18) * (float10)*pdVar11);
      local_1d0 = (double)CONCAT44(local_1d0._4_4_,iVar12);
      fVar16 = (float10)fsin((float10)pdVar11[-2] * (float10)*(float *)(iVar9 + 0x18));
      fVar1 = *(float *)(iVar9 + 0x14);
      *(undefined4 *)(pdVar14 + 1) = *(undefined4 *)pdVar11;
      *(undefined4 *)((int)pdVar14 + 0xc) = uVar5;
      *pdVar14 = (double)((fVar16 + fVar15) * (float10)fVar1 + (float10)local_a4);
      pdVar14 = (double *)((int)pdVar14 + 0x1c);
      local_258._0_4_ = iVar10;
    }
    uVar5 = local_160._4_4_;
    pdVar11 = pdVar11 + 3;
    local_194 = local_194 + -1;
  } while (local_194 != 0);
  if (iVar12 < 3) {
    if (iVar12 == 0) goto LAB_00436e3f;
    iVar12 = local_1d0._0_4_;
    if (local_1d0._0_4_ == 1) {
      local_144 = (double)CONCAT44(local_160._4_4_,(undefined4)local_160) + _DAT_0059eb20;
      local_12c = local_148;
      local_134 = (undefined4)local_150;
      local_130 = local_150._4_4_;
      iVar10 = *(int *)((int)local_148 + 0x54);
      iVar12 = 2;
      fVar15 = (float10)fsin((float10)*(float *)(iVar10 + 0x18) *
                             (float10)(double)CONCAT44(local_150._4_4_,(undefined4)local_150));
      fVar16 = (float10)fsin((float10)*(float *)(iVar10 + 0x18) * (float10)local_144);
      local_13c = (double)(((float10)(double)CONCAT44(local_150._4_4_,(undefined4)local_150) *
                            (float10)local_148[1] + (float10)local_148[4]) *
                           (float10)(double)CONCAT44(local_150._4_4_,(undefined4)local_150) +
                           ((float10)local_144 * (float10)*local_148 +
                            (float10)(double)CONCAT44(local_150._4_4_,(undefined4)local_150) *
                            (float10)local_148[2] + (float10)local_148[3]) * (float10)local_144 +
                           (float10)local_148[5] +
                          (fVar16 + fVar15) * (float10)*(float *)(iVar10 + 0x14));
    }
    iVar9 = iVar12 * 0x1c;
    (&local_148)[iVar12 * 7] = local_148;
    *(undefined4 *)((int)&local_160 + iVar9) = (undefined4)local_160;
    pdVar11 = (&local_148)[iVar12 * 7];
    *(undefined4 *)((int)&local_160 + iVar9 + 4) = uVar5;
    iVar12 = iVar12 + 1;
    local_1d0 = (double)CONCAT44(local_1d0._4_4_,iVar12);
    fVar15 = (float10)(double)CONCAT44(local_150._4_4_,(undefined4)local_150) +
             (float10)_DAT_0059eb20;
    *(double *)((int)&local_150 + iVar9) = (double)fVar15;
    iVar10 = *(int *)((int)pdVar11 + 0x54);
    fVar16 = (float10)*(double *)((int)&local_160 + iVar9);
    fVar17 = (float10)fsin((float10)*(double *)((int)&local_160 + iVar9) *
                           (float10)*(float *)(iVar10 + 0x18));
    fVar18 = (float10)fsin((float10)*(float *)(iVar10 + 0x18) * fVar15);
    *(double *)((int)&local_158 + iVar9) =
         (double)((fVar15 * (float10)pdVar11[1] + (float10)pdVar11[4]) * fVar15 +
                  (fVar16 * (float10)*pdVar11 + fVar15 * (float10)pdVar11[2] + (float10)pdVar11[3])
                  * fVar16 + (float10)pdVar11[5] +
                 (fVar18 + fVar17) * (float10)*(float *)(iVar10 + 0x14));
  }
  if (iVar12 == 3) {
    iVar12 = FUN_0056c640(local_128,&local_250);
    if (iVar12 == 0) {
      if (local_248 < _DAT_0059e430) {
        local_240 = -local_240;
        local_250 = -local_250;
        local_248 = -local_248;
      }
    }
    else {
      local_250 = 0.0;
      local_248 = 1.0;
      local_240 = 0.0;
    }
    local_260 = local_248 * local_158 +
                local_250 * (double)CONCAT44(local_160._4_4_,(undefined4)local_160) +
                local_240 * (double)CONCAT44(local_150._4_4_,(undefined4)local_150);
  }
  else {
    FUN_004366e0(&local_250,&local_260);
  }
  iVar12 = *(int *)(param_1 + 0x15c);
  bVar6 = local_1a0 < *(double *)(param_1 + 0x21c);
  bVar7 = local_1a0 == *(double *)(param_1 + 0x21c);
  dVar2 = *(double *)(param_1 + 0x21c);
  local_1c0 = (double)((ulonglong)local_1a0 & 0xffffffff);
  pdVar11 = (double *)(iVar12 + 4);
  pdVar14 = &local_220;
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined4 *)pdVar14 = *(undefined4 *)pdVar11;
    pdVar11 = (double *)((int)pdVar11 + 4);
    pdVar14 = (double *)((int)pdVar14 + 4);
  }
  local_1c0 = (double)CONCAT44(local_1a0._4_4_,(undefined4)local_1c0);
  if (bVar6 == bVar7) {
    dVar2 = SQRT(local_1a0 * local_1a0 - dVar2 * dVar2);
  }
  else {
    dVar2 = dVar2 - local_1a0;
    local_1c0 = local_1a0 + dVar2;
    local_1b0 = dVar2 * local_200;
    local_1a8 = dVar2 * local_1f8;
    local_220 = local_208 * dVar2 + local_220;
    local_218 = dVar2 * local_200 + local_218;
    local_210 = dVar2 * local_1f8 + local_210;
    dVar2 = _DAT_0059e430;
  }
  local_1f0 = (local_260 - (local_248 * local_218 + local_240 * local_210 + local_220 * local_250))
              + local_1c0;
  dVar4 = *(double *)(param_1 + 0x21c) + _DAT_0059e420;
  dVar3 = dVar4 + *(double *)(param_1 + 0x21c);
  local_1c8 = SQRT(dVar2 * dVar2 + dVar3 * dVar3);
  local_208 = local_238 * dVar4 + *(double *)(iVar12 + 4);
  local_200 = local_230 * dVar4 + *(double *)(iVar12 + 0xc);
  dVar2 = dVar4 * local_228 + *(double *)(iVar12 + 0x14);
  dVar3 = (local_260 - (local_248 * local_200 + local_240 * dVar2 + local_208 * local_250)) +
          local_1c8;
  if (dVar3 <= local_1f0) {
    *(double *)(param_1 + 0x324) = dVar3;
    dVar3 = dVar3 - local_1c8;
    local_1e8 = local_208 + local_250 * dVar3;
    local_1e0 = dVar3 * local_248 + local_200;
    local_1d8 = dVar3 * local_240 + dVar2;
  }
  else {
    dVar2 = local_1f0 - local_1c0;
    *(double *)(param_1 + 0x324) = local_1f0;
    local_1e8 = local_220 + local_250 * dVar2;
    local_1e0 = dVar2 * local_248 + local_218;
    local_1d8 = dVar2 * local_240 + local_210;
  }
  local_260 = 1.7976931348623157e+308;
  if (0 < local_1d0._0_4_) {
    pdVar11 = (double *)&local_150;
    iVar12 = local_1d0._0_4_;
    do {
      dVar2 = (local_1e0 - pdVar11[-1]) * (local_1e0 - pdVar11[-1]) +
              (local_1d8 - *pdVar11) * (local_1d8 - *pdVar11) +
              (local_1e8 - pdVar11[-2]) * (local_1e8 - pdVar11[-2]);
      if (dVar2 < local_260) {
        *(undefined4 *)(param_1 + 0x264) = *(undefined4 *)(pdVar11 + 1);
        local_260 = dVar2;
      }
      pdVar11 = (double *)((int)pdVar11 + 0x1c);
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  if (*(double *)(param_1 + 0x324) < _DAT_0059e430) {
    *(undefined4 *)(param_1 + 0x324) = 0;
    *(undefined4 *)(param_1 + 0x328) = 0;
    *(undefined4 *)(param_1 + 0xfc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x100) = 0xffefffff;
    return;
  }
  local_194 = *(int *)(*(int *)(param_1 + 0x264) + 0x54);
  iVar12 = *(int *)(param_1 + 0x15c);
  dVar2 = *(double *)(param_1 + 0x22c) * *(double *)(param_1 + 0x324) -
          (local_250 * *(double *)(iVar12 + 100) +
          local_248 * *(double *)(iVar12 + 0x6c) + local_240 * *(double *)(iVar12 + 0x74)) *
          *(double *)(param_1 + 0x234);
  *(double *)(param_1 + 0x31c) = dVar2;
  if (dVar2 < _DAT_0059e430) {
    *(undefined4 *)(param_1 + 0x31c) = 0;
    *(undefined4 *)(param_1 + 800) = 0;
    *(undefined4 *)(param_1 + 0xfc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x100) = 0xffefffff;
    return;
  }
  dVar2 = *(double *)(iVar12 + 0x1c);
  dVar3 = *(double *)(iVar12 + 0x34);
  dVar4 = *(double *)(iVar12 + 0x4c);
  local_1f0 = local_248 * dVar3 + local_240 * dVar4 + local_250 * dVar2;
  if (ABS(local_1f0) <= _DAT_0059eb18) {
    local_208 = local_240 * dVar3 - local_248 * dVar4;
    local_200 = local_250 * dVar4 - dVar2 * local_240;
    local_1f8 = dVar2 * local_248 - local_250 * dVar3;
    local_260 = _DAT_0059e420 /
                SQRT(local_1f8 * local_1f8 + local_200 * local_200 + local_208 * local_208);
    local_208 = local_260 * local_208;
    local_200 = local_260 * local_200;
    local_1f8 = local_260 * local_1f8;
    local_238 = local_248 * local_1f8 - local_240 * local_200;
    local_230 = local_208 * local_240 - local_250 * local_1f8;
    local_228 = local_250 * local_200 - local_208 * local_248;
  }
  else {
    dVar2 = *(double *)(iVar12 + 0x2c);
    dVar3 = *(double *)(iVar12 + 0x44);
    dVar4 = *(double *)(iVar12 + 0x5c);
    local_238 = local_248 * dVar4 - local_240 * dVar3;
    local_230 = dVar2 * local_240 - local_250 * dVar4;
    local_228 = local_250 * dVar3 - dVar2 * local_248;
    local_260 = _DAT_0059e420 /
                SQRT(local_230 * local_230 + local_228 * local_228 + local_238 * local_238);
    local_238 = local_260 * local_238;
    local_230 = local_260 * local_230;
    local_228 = local_260 * local_228;
    local_1b8 = dVar3 * local_228 - dVar4 * local_230;
    local_1b0 = local_238 * dVar4 - dVar2 * local_228;
    dVar8 = dVar2 * local_230 - local_238 * dVar3;
    local_220 = local_1b0 * dVar4 - dVar8 * dVar3;
    local_218 = dVar2 * dVar8 - local_1b8 * dVar4;
    local_1f0 = local_248 * local_218 +
                local_240 * (local_1b8 * dVar3 - dVar2 * local_1b0) + local_220 * local_250;
    local_208 = local_240 * local_230 - local_248 * local_228;
    local_200 = local_250 * local_228 - local_238 * local_240;
    local_1f8 = local_238 * local_248 - local_250 * local_230;
  }
  fVar15 = (float10)FUN_00588570();
  *(double *)(param_1 + 0x314) = (double)fVar15;
  iVar12 = *(int *)(param_1 + 0x15c);
  dVar2 = *(double *)(param_1 + 0x324) * _DAT_0059e880;
  local_1b0 = dVar2 * local_248;
  local_1a8 = local_1d8 - dVar2 * local_240;
  local_178 = (local_1e8 - local_250 * dVar2) - *(double *)(iVar12 + 4);
  dVar2 = (local_1e0 - local_1b0) - *(double *)(iVar12 + 0xc);
  dVar3 = local_1a8 - *(double *)(iVar12 + 0x14);
  local_210 = dVar2 * *(double *)(iVar12 + 0x7c) - local_178 * *(double *)(iVar12 + 0x84);
  local_220 = (dVar3 * *(double *)(iVar12 + 0x84) - dVar2 * *(double *)(iVar12 + 0x8c)) +
              *(double *)(iVar12 + 100);
  dVar2 = (local_178 * *(double *)(iVar12 + 0x8c) - dVar3 * *(double *)(iVar12 + 0x7c)) +
          *(double *)(iVar12 + 0x6c);
  dVar3 = local_210 + *(double *)(iVar12 + 0x74);
  local_260 = dVar2 * local_230 + dVar3 * local_228 + local_220 * local_238;
  dVar4 = dVar3 * local_1f8 + dVar2 * local_200 + local_220 * local_208;
  *(double *)(param_1 + 0x134) = SQRT(local_260 * local_260 + dVar4 * dVar4);
  dVar2 = _DAT_0059e420;
  dVar3 = local_238 * *(double *)(iVar12 + 100) +
          local_230 * *(double *)(iVar12 + 0x6c) + local_228 * *(double *)(iVar12 + 0x74);
  local_1c0 = local_208 * *(double *)(iVar12 + 100) +
              local_1f8 * *(double *)(iVar12 + 0x74) + local_200 * *(double *)(iVar12 + 0x6c);
  local_1c8 = SQRT(dVar3 * dVar3 + local_1c0 * local_1c0);
  if (*(double *)(param_1 + 0x124) <= local_1c8) {
    *(undefined4 *)(param_1 + 0xfc) = 0xffffffff;
    dVar2 = dVar2 / local_1c8;
    *(undefined4 *)(param_1 + 0x100) = 0xffefffff;
  }
  else {
    dVar2 = *(double *)(param_1 + 300);
  }
  local_260 = local_260 * dVar2;
  local_1d0 = dVar2 * dVar4;
  dVar2 = local_260 * local_260 + local_1d0 * local_1d0;
  dVar3 = SQRT(dVar2);
  if (dVar2 <= _DAT_0059e430) {
    local_190 = 0.0;
    local_1f0 = 0.0;
  }
  else {
    local_190 = _DAT_0059e420 / dVar3;
    local_1f0 = (_DAT_0059e420 / (ABS(local_260) + ABS(local_1d0))) * ABS(local_1d0);
  }
  if ((float10)*(double *)(param_1 + 0x31c) <= (float10)*(double *)(param_1 + 0x2a8)) {
    fVar15 = (float10)fcos((float10)*(double *)(param_1 + 0x31c) *
                           (float10)*(double *)(param_1 + 0x2b0) * (float10)_DAT_0059e890);
    fVar15 = fVar15 * (float10)*(double *)(param_1 + 0x2a0) + (float10)*(double *)(param_1 + 0x298);
  }
  else {
    fVar15 = (float10)*(double *)(param_1 + 0x298) - (float10)*(double *)(param_1 + 0x2a0);
  }
  if ((float10)*(double *)(param_1 + 0x31c) <= (float10)*(double *)(param_1 + 0x2c8)) {
    fVar16 = (float10)fcos((float10)*(double *)(param_1 + 0x31c) *
                           (float10)*(double *)(param_1 + 0x2d0) * (float10)_DAT_0059e890);
    fVar16 = fVar16 * (float10)*(double *)(param_1 + 0x2c0) + (float10)*(double *)(param_1 + 0x2b8);
  }
  else {
    fVar16 = (float10)*(double *)(param_1 + 0x2b8) - (float10)*(double *)(param_1 + 0x2c0);
  }
  local_258 = (double)((fVar16 - fVar15) * (float10)local_1f0 + fVar15);
  local_188 = dVar3;
  fVar15 = (float10)FUN_004d6830(local_258,dVar3);
  local_180 = (double)fVar15;
  dVar2 = ABS(local_1c0);
  if (_DAT_0059e420 <= dVar2) {
    fVar15 = (float10)FUN_004d6830((int)local_258,local_258._4_4_,dVar3);
  }
  else {
    if (local_1d0 * local_1c0 <= _DAT_0059e430) {
      dVar2 = dVar2 + _DAT_0059e420;
    }
    else {
      dVar2 = _DAT_0059e420 - dVar2;
    }
    local_188 = dVar2 * _DAT_0059e880;
    fVar15 = (float10)FUN_004d6830((int)local_258,local_258._4_4_,dVar3);
    local_1c0 = (double)fVar15;
    fVar15 = (float10)FUN_004d6830((int)local_258,local_258._4_4_,dVar3);
    fVar15 = (fVar15 - (float10)local_1c0) * (float10)local_188 + (float10)local_1c0;
  }
  iVar12 = local_194;
  fVar15 = ((fVar15 - (float10)local_180) * (float10)local_1f0 + (float10)local_180) *
           (float10)local_190;
  fVar16 = fVar15 * (float10)*(double *)(param_1 + 0x2e4) * (float10)local_258;
  *(double *)(param_1 + 0x144) = (double)fVar16;
  if ((float10)_DAT_0059e420 < fVar16) {
    *(undefined4 *)(param_1 + 0x144) = 0;
    *(undefined4 *)(param_1 + 0x148) = 0x3ff00000;
  }
  *(double *)(param_1 + 0x14c) = SQRT(*(double *)(param_1 + 0x144));
  fVar16 = (float10)*(double *)(param_1 + 0x278) -
           (float10)*(double *)(param_1 + 0x280) * (float10)*(double *)(param_1 + 0x270);
  fVar17 = (float10)*(float *)(local_194 + 8) -
           (float10)*(double *)(param_1 + 0x270) * (float10)*(float *)(local_194 + 0xc);
  *(double *)(param_1 + 0x268) = (double)fVar17;
  fVar18 = (float10)*(double *)(param_1 + 0x31c);
  if ((float10)*(double *)(param_1 + 0x25c) < fVar18) {
    fVar18 = (float10)*(double *)(param_1 + 0x25c);
  }
  fVar16 = (((fVar18 * (float10)*(double *)(param_1 + 0x23c) + (float10)*(double *)(param_1 + 0x244)
             ) * fVar18 + (float10)*(double *)(param_1 + 0x24c)) * fVar18 +
           (float10)*(double *)(param_1 + 0x254)) * (float10)*(double *)(param_1 + 0x31c) *
           ((((float10)*(double *)(param_1 + 0x288) -
             (float10)*(double *)(param_1 + 0x290) * (float10)*(double *)(param_1 + 0x270)) - fVar16
            ) * (float10)local_1f0 + fVar16) * fVar17 * (float10)*(double *)(param_1 + 0x39c);
  *(double *)(param_1 + 0x13c) = (double)fVar16;
  fVar15 = -(fVar16 * fVar15);
  local_258 = (double)((float10)local_260 * fVar15);
  fVar15 = fVar15 * (float10)local_1d0;
  if ((*(int *)(param_1 + 0xfc) != -1) || (*(int *)(param_1 + 0x100) != -0x100001)) {
    if (*(double *)(param_1 + 0xbc) != _DAT_0059e430) {
      dVar2 = ((double)CONCAT44(param_3,param_2) - *(double *)(param_1 + 0xfc)) *
              (local_1a0 - *(double *)(param_1 + 0x324) * _DAT_0059e880) *
              *(double *)(param_1 + 0xbc);
      *(double *)(param_1 + 0xe4) = local_208 * dVar2 + *(double *)(param_1 + 0xe4);
      *(double *)(param_1 + 0xec) = dVar2 * local_200 + *(double *)(param_1 + 0xec);
      *(double *)(param_1 + 0xf4) = dVar2 * local_1f8 + *(double *)(param_1 + 0xf4);
    }
    *(undefined4 *)(param_1 + 0xfc) = param_2;
    *(undefined4 *)(param_1 + 0x100) = param_3;
    local_220 = *(double *)(param_1 + 0xe4) - local_1e8;
    local_218 = *(double *)(param_1 + 0xec) - local_1e0;
    local_210 = *(double *)(param_1 + 0xf4) - local_1d8;
    dVar2 = SQRT(local_218 * local_218 + local_210 * local_210 + local_220 * local_220);
    if ((dVar2 < _DAT_0059eb10) && (*(double *)(param_1 + 0x134) < _DAT_0059eb08)) {
      fVar16 = ((float10)_DAT_0059e420 -
               (float10)*(double *)(param_1 + 0x134) * (float10)_DAT_0059eb28) *
               ((float10)_DAT_0059e420 - (float10)local_1c8 * (float10)*(double *)(param_1 + 300)) *
               (float10)_DAT_0059eb00;
      if (_DAT_0059eaf8 < dVar2) {
        fVar16 = ((float10)_DAT_0059e900 - (float10)dVar2 * (float10)_DAT_0059eaf0) * fVar16;
      }
      dVar2 = (double)(((float10)local_218 * (float10)local_230 +
                       (float10)local_210 * (float10)local_228 +
                       (float10)local_220 * (float10)local_238) * fVar16 + (float10)local_258);
      local_1c8 = (double)(((float10)local_210 * (float10)local_1f8 +
                           (float10)local_218 * (float10)local_200 +
                           (float10)local_220 * (float10)local_208) * fVar16 + fVar15);
      if (dVar2 * dVar2 + local_1c8 * local_1c8 <=
          *(double *)(param_1 + 0x13c) * *(double *)(param_1 + 0x13c)) {
        fVar15 = (float10)local_1c8;
        local_258 = dVar2;
        goto LAB_00437dc8;
      }
    }
    *(undefined4 *)(param_1 + 0xfc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x100) = 0xffefffff;
  }
LAB_00437dc8:
  if ((*(int *)(param_1 + 0xfc) == -1) && (*(int *)(param_1 + 0x100) == -0x100001)) {
    *(double *)(param_1 + 0xe4) = local_1e8;
    *(double *)(param_1 + 0xec) = local_1e0;
    *(double *)(param_1 + 0xf4) = local_1d8;
    *(undefined4 *)(param_1 + 0xfc) = param_2;
    *(undefined4 *)(param_1 + 0x100) = param_3;
  }
  local_180 = *(double *)(param_1 + 0x2ec) * *(double *)(param_1 + 0x13c) *
              *(double *)(param_1 + 0x144);
  fVar16 = ABS((float10)*(double *)(param_1 + 0x314));
  if ((float10)*(double *)(param_1 + 0x2f4) <= fVar16) {
    if ((float10)_DAT_0059e898 <= fVar16) goto LAB_00437eb3;
    fVar17 = (float10)fcos((fVar16 - (float10)*(double *)(param_1 + 0x2f4)) *
                           (float10)*(double *)(param_1 + 0x30c));
    fVar17 = (fVar17 + (float10)_DAT_0059e420) * (float10)_DAT_0059e880 * (float10)local_180;
    if (_DAT_0059e430 < *(double *)(param_1 + 0x314)) {
      local_258 = (double)((float10)local_258 - fVar17);
      goto LAB_00437eb3;
    }
    fVar17 = fVar17 + (float10)local_258;
  }
  else {
    fVar17 = (float10)fsin((float10)*(double *)(param_1 + 0x304) *
                           (float10)*(double *)(param_1 + 0x314));
    fVar17 = (float10)local_258 - fVar17 * (float10)local_180;
  }
  local_258 = (double)fVar17;
LAB_00437eb3:
  iVar10 = *(int *)(param_1 + 0x15c);
  local_190 = (double)(((float10)_DAT_0059e420 - fVar16 * (float10)*(double *)(param_1 + 0x2fc)) *
                      fVar15);
  dVar2 = *(double *)(param_1 + 0x31c);
  *(double *)(iVar10 + 0x134) = local_250 * dVar2 + *(double *)(iVar10 + 0x134);
  *(double *)(iVar10 + 0x13c) = dVar2 * local_248 + *(double *)(iVar10 + 0x13c);
  *(double *)(iVar10 + 0x144) = dVar2 * local_240 + *(double *)(iVar10 + 0x144);
  iVar10 = *(int *)(param_1 + 0x15c);
  puVar13 = (undefined4 *)(iVar10 + 0x7c);
  pdVar11 = &local_220;
  for (iVar9 = 6; iVar9 != 0; iVar9 = iVar9 + -1) {
    *(undefined4 *)pdVar11 = *puVar13;
    puVar13 = puVar13 + 1;
    pdVar11 = (double *)((int)pdVar11 + 4);
  }
  dVar2 = local_218 * local_218 + local_210 * local_210 + local_220 * local_220;
  local_260 = (double)((*(float *)(iVar12 + 0x10) + (float)*(double *)(param_1 + 0x32c)) *
                      (float)*(double *)(param_1 + 0x324));
  dVar3 = local_260;
  if (_DAT_0059e420 < dVar2) {
    local_1c8 = (_DAT_0059e420 / SQRT(dVar2)) * local_260;
    dVar3 = local_1c8;
  }
  *(double *)(iVar10 + 0x14c) = *(double *)(iVar10 + 0x14c) - dVar3 * local_220;
  *(double *)(iVar10 + 0x154) = *(double *)(iVar10 + 0x154) - dVar3 * local_218;
  *(double *)(iVar10 + 0x15c) = *(double *)(iVar10 + 0x15c) - dVar3 * local_210;
  local_168 = local_190 * local_1f8;
  local_1b0 = local_258 * local_230;
  local_1a8 = local_258 * local_228;
  local_220 = local_238 * local_258 + local_208 * local_190;
  local_218 = local_190 * local_200 + local_258 * local_230;
  local_210 = local_190 * local_1f8 + local_258 * local_228;
  pdVar11 = &local_220;
  puVar13 = local_20;
  for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {
    *puVar13 = *(undefined4 *)pdVar11;
    pdVar11 = (double *)((int)pdVar11 + 4);
    puVar13 = puVar13 + 1;
  }
  FUN_00569a20(&local_1e8,local_20);
  *(int *)(param_1 + 0x154) = (int)local_258;
  *(undefined4 *)(param_1 + 0x158) = local_258._4_4_;
  return;
}


