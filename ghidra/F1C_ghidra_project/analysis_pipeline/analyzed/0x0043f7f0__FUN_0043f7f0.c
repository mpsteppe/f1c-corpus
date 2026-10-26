// Function: FUN_0043f7f0 @ 0043f7f0
// Size (bytes): 1951


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043f7f0(int param_1,double param_2)

{
  float *pfVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  float fVar10;
  bool bVar11;
  char cVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  int extraout_ECX;
  double *pdVar16;
  int extraout_EDX;
  double *pdVar17;
  double *pdVar18;
  int iVar19;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  int *piVar20;
  undefined4 unaff_EDI;
  float10 fVar21;
  float10 fVar22;
  float local_324;
  double local_320;
  double local_318;
  int local_30c;
  double local_308;
  undefined8 local_300;
  undefined4 local_2f8;
  undefined4 uStack_2f4;
  double local_2e8;
  undefined8 uStack_2e0;
  double dStack_2d8;
  double dStack_2d0;
  double dStack_2c8;
  double dStack_2c0;
  double dStack_2b8;
  double local_2b0;
  double local_2a8;
  double dStack_2a0;
  double dStack_298;
  double dStack_290;
  double dStack_288;
  double dStack_280;
  double local_278;
  double local_270 [6];
  double local_240;
  double local_238;
  double dStack_228;
  double dStack_220;
  int aiStack_218 [10];
  double adStack_1f0 [4];
  double dStack_1d0;
  double adStack_1c8 [5];
  double dStack_1a0;
  double dStack_198;
  undefined4 local_190 [12];
  double adStack_160 [10];
  undefined4 auStack_110 [8];
  double adStack_f0 [8];
  double adStack_b0 [4];
  double dStack_90;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined8 uStack_80;
  undefined4 uStack_58;
  undefined4 uStack_54;
  double dStack_50;
  double dStack_48;
  double dStack_30;
  double adStack_28 [4];
  
  iVar13 = 0;
  puVar14 = local_190;
  do {
    aiStack_218[iVar13 + 4] = (int)puVar14;
    iVar13 = iVar13 + 1;
    puVar14 = puVar14 + 0xe;
  } while (iVar13 < 6);
  do {
    fVar21 = (float10)FUN_00438930();
    local_270[extraout_EDX + 1] = (double)fVar21;
  } while (extraout_EDX + 1 < 4);
  if (*(double *)(param_1 + 0x1e38) <= _DAT_0059e900) {
    if (*(double *)(param_1 + 0x1e38) < _DAT_0059ed20) {
      local_270[5] = *(double *)(param_1 + 0x1e68);
    }
    else {
      local_270[5] = *(double *)(param_1 + 0x1e68) * *(double *)(param_1 + 0x1e38) * _DAT_0059ec10;
    }
  }
  else {
    local_270[5] = -*(double *)(param_1 + 0x1e68);
  }
  if (*(double *)(param_1 + 0x1c5c) <= *(double *)(param_1 + 0x1cf4)) {
    local_2b0 = *(double *)(param_1 + 0x1c5c);
  }
  else {
    local_2b0 = *(double *)(param_1 + 0x1cf4);
  }
  fVar21 = (float10)local_2b0;
  if (fVar21 <= (float10)_DAT_0059e900) {
    if (_DAT_0059ed20 <= *(double *)(param_1 + 0x1c5c)) {
      fVar9 = (float10)_DAT_0059ed18;
      fVar22 = (float10)FUN_005895a2((double)(ABS(fVar21) * fVar9));
      local_324 = (float)fVar22;
      iVar13 = (int)ROUND(local_324);
      fVar10 = (float)(ABS(fVar21) * fVar9) - local_324;
      iVar15 = *(int *)(param_1 + 0x1cfc);
      pfVar1 = (float *)(iVar15 + 4 + iVar13 * 8);
      *(float *)(param_1 + 0x1d00) =
           (*(float *)(iVar15 + 8 + iVar13 * 8) - *(float *)(iVar15 + iVar13 * 8)) * fVar10 +
           *(float *)(iVar15 + iVar13 * 8);
      fVar10 = (*(float *)(iVar15 + 0xc + iVar13 * 8) - *pfVar1) * fVar10 + *pfVar1;
      *(float *)(param_1 + 0x1d04) = fVar10;
      local_238 = (double)(fVar10 * DAT_0059e440 + *(float *)(param_1 + 0x1d00));
      if (local_2b0 < _DAT_0059e430) {
        fVar21 = (float10)_DAT_0059e430;
      }
      else {
        dVar2 = *(double *)(param_1 + 8);
        local_320 = (double)CONCAT44(local_320._4_4_,(float)dVar2);
        fVar10 = (float)local_2b0 * _DAT_0059ed18;
        fVar21 = (float10)FUN_005895a2((double)fVar10);
        local_324 = (float)fVar21;
        iVar13 = (int)ROUND(local_324);
        fVar21 = (float10)fVar10 - (float10)local_324;
        iVar15 = *(int *)(param_1 + 0x1cfc);
        pfVar1 = (float *)(iVar15 + 4 + iVar13 * 8);
        *(float *)(param_1 + 0x1d00) =
             (float)(((float10)*(float *)(iVar15 + 8 + iVar13 * 8) -
                     (float10)*(float *)(iVar15 + iVar13 * 8)) * fVar21 +
                    (float10)*(float *)(iVar15 + iVar13 * 8));
        fVar21 = ((float10)*(float *)(iVar15 + 0xc + iVar13 * 8) - (float10)*pfVar1) * fVar21 +
                 (float10)*pfVar1;
        *(float *)(param_1 + 0x1d04) = (float)fVar21;
        fVar21 = (fVar21 * (float10)(float)dVar2 + (float10)*(float *)(param_1 + 0x1d00)) -
                 (float10)local_238;
      }
      local_318 = (double)CONCAT44(local_318._4_4_,iVar13);
      local_240 = (double)((float10)local_238 * (float10)local_2b0 * (float10)_DAT_0059e880 + fVar21
                          );
    }
    else {
      fVar9 = (float10)_DAT_0059ed18;
      fVar22 = (float10)FUN_005895a2((double)(-fVar21 * fVar9));
      local_324 = (float)fVar22;
      iVar13 = (int)ROUND(local_324);
      local_318 = (double)CONCAT44(local_318._4_4_,iVar13);
      fVar10 = (float)(-fVar21 * fVar9) - local_324;
      iVar15 = *(int *)(param_1 + 0x1cfc);
      pfVar1 = (float *)(iVar15 + 4 + iVar13 * 8);
      *(float *)(param_1 + 0x1d00) =
           (*(float *)(iVar15 + 8 + iVar13 * 8) - *(float *)(iVar15 + iVar13 * 8)) * fVar10 +
           *(float *)(iVar15 + iVar13 * 8);
      fVar10 = (*(float *)(iVar15 + 0xc + iVar13 * 8) - *pfVar1) * fVar10 + *pfVar1;
      *(float *)(param_1 + 0x1d04) = fVar10;
      local_240 = (double)-(fVar10 * DAT_0059e440 + *(float *)(param_1 + 0x1d00));
    }
  }
  else {
    dVar2 = *(double *)(param_1 + 8);
    local_318 = (double)CONCAT44(local_318._4_4_,(float)dVar2);
    fVar9 = (float10)_DAT_0059ed18;
    fVar22 = (float10)FUN_005895a2((double)(fVar21 * fVar9));
    local_324 = (float)fVar22;
    iVar13 = (int)ROUND(local_324);
    local_320 = (double)CONCAT44(local_320._4_4_,iVar13);
    fVar10 = (float)(fVar21 * fVar9) - local_324;
    iVar15 = *(int *)(param_1 + 0x1cfc);
    pfVar1 = (float *)(iVar15 + 4 + iVar13 * 8);
    *(float *)(param_1 + 0x1d00) =
         (*(float *)(iVar15 + 8 + iVar13 * 8) - *(float *)(iVar15 + iVar13 * 8)) * fVar10 +
         *(float *)(iVar15 + iVar13 * 8);
    fVar10 = (*(float *)(iVar15 + 0xc + iVar13 * 8) - *pfVar1) * fVar10 + *pfVar1;
    *(float *)(param_1 + 0x1d04) = fVar10;
    local_240 = (double)((float)dVar2 * fVar10 + *(float *)(param_1 + 0x1d00));
  }
  iVar13 = *(int *)(param_1 + 0x15f0);
  dVar2 = local_240 + local_270[5];
  iVar15 = 0;
  pdVar17 = (double *)(param_1 + 0x348);
  local_278 = dVar2 * *(double *)(iVar13 + 0x44);
  local_270[0] = dVar2 * *(double *)(iVar13 + 0x5c);
  *(double *)(iVar13 + 0x14c) = dVar2 * *(double *)(iVar13 + 0x2c) + *(double *)(iVar13 + 0x14c);
  *(double *)(iVar13 + 0x154) = local_278 + *(double *)(iVar13 + 0x154);
  *(double *)(iVar13 + 0x15c) = local_270[0] + *(double *)(iVar13 + 0x15c);
  local_2a8 = (_DAT_0059e420 - *(double *)(param_1 + 0x18)) *
              (_DAT_0059e420 - *(double *)(param_1 + 0x20)) * *(double *)(param_1 + 0x1e58);
  do {
    if (*pdVar17 == _DAT_0059e430) {
      iVar13 = 0;
    }
    else {
      iVar13 = -1;
      if (*pdVar17 <= _DAT_0059e430) {
        iVar13 = 1;
      }
    }
    aiStack_218[iVar15] = iVar13;
    iVar15 = iVar15 + 1;
    pdVar17 = (double *)((int)pdVar17 + 0x464);
  } while (iVar15 < 4);
  if (*(double *)(param_1 + 0x1c5c) == *(double *)(param_1 + 0x1e38)) {
    local_30c = 0;
  }
  else {
    local_30c = -1;
    if (*(double *)(param_1 + 0x1c5c) <= *(double *)(param_1 + 0x1e38)) {
      local_30c = 1;
    }
  }
  iVar13 = *(int *)(param_1 + 0x1e14);
  if (iVar13 == 0) {
    if (*(int *)(param_1 + 0x1ef0) != 0) {
      FUN_0059d7b5(unaff_ESI,unaff_EBX);
      return;
    }
    local_324 = 1.4013e-45;
    local_318 = 0.0;
    local_2e8 = 0.0;
    dVar2 = param_2 * _DAT_0059e880;
    local_300 = (local_270[3] * dVar2 * *(double *)(param_1 + 0xc28) + *(double *)(param_1 + 0xc10))
                - (local_270[4] * dVar2 * *(double *)(param_1 + 0x108c) +
                  *(double *)(param_1 + 0x1074));
    dVar3 = local_300 * *(double *)(param_1 + 0x1e18);
    if (local_300 <= _DAT_0059e430) {
      if (local_300 < _DAT_0059e430) {
        if (-0.0 <= _DAT_0059e430) {
          dVar3 = *(double *)(param_1 + 0x1e28) * -0.0 + dVar3;
        }
        else {
          dVar3 = dVar3 - *(double *)(param_1 + 0x1e20) * -0.0;
        }
        dVar3 = dVar3 - *(double *)(param_1 + 0x1e30);
      }
    }
    else if (-0.0 <= _DAT_0059e430) {
      dVar3 = (dVar3 - *(double *)(param_1 + 0x1e28) * -0.0) + *(double *)(param_1 + 0x1e30);
    }
    else {
      dVar3 = *(double *)(param_1 + 0x1e20) * -0.0 + dVar3 + *(double *)(param_1 + 0x1e30);
    }
    dVar3 = dVar3 * _DAT_0059e880;
    dVar2 = (-(dVar2 * dVar3 * *(double *)(param_1 + 0xc28)) -
            dVar2 * dVar3 * *(double *)(param_1 + 0x108c)) + local_300;
    if (((_DAT_0059e430 <= local_300) && (dVar2 < _DAT_0059e430)) ||
       ((local_300 < _DAT_0059e430 != (local_300 == _DAT_0059e430) && (_DAT_0059e430 < dVar2)))) {
      dVar3 = (local_300 / (local_300 - dVar2)) * dVar3;
    }
    local_270[3] = local_270[3] - dVar3;
    local_270[4] = dVar3 + local_270[4];
    local_2f8 = 0;
    uStack_2f4 = 0;
  }
  else if (iVar13 == 1) {
    pdVar17 = (double *)(param_1 + 0x348);
    iVar13 = 0;
    local_300 = *(double *)(param_1 + 0x1074) + *(double *)(param_1 + 0xc10) +
                *(double *)(param_1 + 0x7ac) + *pdVar17;
    do {
      dVar2 = *pdVar17;
      iVar13 = iVar13 + 1;
      pdVar17 = (double *)((int)pdVar17 + 0x464);
      local_270[iVar13] =
           local_270[iVar13] - (dVar2 - local_300 * _DAT_0059eb50) * *(double *)(param_1 + 0x1e18);
    } while (iVar13 < 4);
    if (*(int *)(param_1 + 0x1ef0) != 0) {
      FUN_0059d928(unaff_EDI,unaff_ESI);
      return;
    }
    local_324 = 1.4013e-45;
    local_318 = 0.0;
    local_2e8 = 0.0;
    local_2f8 = 0;
    uStack_2f4 = 0;
  }
  else if (iVar13 == 2) {
    uVar6 = *(uint *)(param_1 + 0x1ef0);
    if (uVar6 == 0) {
      local_324 = 1.4013e-45;
      local_318 = 0.0;
      local_2e8 = 0.0;
      local_2f8 = 0;
      uStack_2f4 = 0;
      dVar2 = -0.0;
    }
    else {
      pdVar17 = (double *)(param_1 + 0x1e70);
      local_2f8 = *(undefined4 *)pdVar17;
      uStack_2f4 = *(undefined4 *)(param_1 + 0x1e74);
      dVar4 = *pdVar17;
      dVar2 = *pdVar17;
      local_318 = *(double *)(param_1 + 0x1eb0 + (uVar6 & (uVar6 == 0xffffffff) - 1) * 8) *
                  _DAT_0059ec10;
      local_2e8 = local_318 * local_318;
      dVar3 = (*(double *)(param_1 + 0x7ac) + *(double *)(param_1 + 0x348)) * local_318;
      cVar12 = FUN_00435290(dVar3,*(undefined4 *)(param_1 + 0x1e38),
                            *(undefined4 *)(param_1 + 0x1e3c));
      if (cVar12 == '\0') {
        if (dVar3 <= *(double *)(param_1 + 0x1e38)) {
          local_324 = 1.4013e-45;
          dVar2 = -dVar4;
        }
        else {
          local_324 = -NAN;
        }
      }
      else {
        local_324 = 0.0;
        if (extraout_ECX == -1) {
          dVar2 = -local_2a8;
        }
        else if (extraout_ECX == 0) {
          dVar2 = -local_240;
        }
        else {
          dVar2 = local_320;
          if (extraout_ECX == 1) {
            dVar2 = local_2a8;
          }
        }
      }
    }
    dVar2 = dVar2 * local_318;
    dVar3 = param_2 * _DAT_0059e880;
    local_300 = (local_270[1] * *(double *)(param_1 + 0x360) * dVar3 + *(double *)(param_1 + 0x348))
                - (local_270[2] * *(double *)(param_1 + 0x7c4) * dVar3 +
                  *(double *)(param_1 + 0x7ac));
    dVar4 = local_300 * *(double *)(param_1 + 0x1e18);
    if (local_300 <= _DAT_0059e430) {
      if (local_300 < _DAT_0059e430) {
        if (dVar2 <= _DAT_0059e430) {
          dVar4 = dVar2 * *(double *)(param_1 + 0x1e28) + dVar4;
        }
        else {
          dVar4 = dVar4 - dVar2 * *(double *)(param_1 + 0x1e20);
        }
        dVar4 = dVar4 - *(double *)(param_1 + 0x1e30);
      }
    }
    else if (dVar2 <= _DAT_0059e430) {
      dVar4 = (dVar4 - dVar2 * *(double *)(param_1 + 0x1e28)) + *(double *)(param_1 + 0x1e30);
    }
    else {
      dVar4 = dVar2 * *(double *)(param_1 + 0x1e20) + dVar4 + *(double *)(param_1 + 0x1e30);
    }
    dVar4 = dVar4 * _DAT_0059e880;
    dVar2 = (-(dVar3 * dVar4 * *(double *)(param_1 + 0x360)) -
            dVar3 * dVar4 * *(double *)(param_1 + 0x7c4)) + local_300;
    if (((_DAT_0059e430 <= local_300) && (dVar2 < _DAT_0059e430)) ||
       ((local_300 < _DAT_0059e430 != (local_300 == _DAT_0059e430) && (_DAT_0059e430 < dVar2)))) {
      dVar4 = (local_300 / (local_300 - dVar2)) * dVar4;
    }
    local_270[1] = local_270[1] - dVar4;
    local_270[2] = local_270[2] + dVar4;
  }
LAB_00440210:
  do {
    puVar14 = local_190;
    for (iVar13 = 0x54; iVar13 != 0; iVar13 = iVar13 + -1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
    iVar13 = *(int *)(param_1 + 0x1e14);
    if (iVar13 == 0) {
      pdVar17 = (double *)(param_1 + 0x368);
      iVar13 = 0;
      pdVar18 = adStack_160;
      puVar14 = local_190;
      do {
        iVar15 = aiStack_218[iVar13];
        *puVar14 = 0;
        puVar14[1] = 0x3ff00000;
        if (iVar15 == 0) {
          dVar2 = local_270[iVar13 + 1];
LAB_00440574:
          dVar2 = -dVar2;
        }
        else {
          dVar2 = *pdVar17;
          if (iVar15 == -1) goto LAB_00440574;
        }
        *pdVar18 = dVar2;
        iVar13 = iVar13 + 1;
        puVar14 = puVar14 + 0x10;
        pdVar17 = (double *)((int)pdVar17 + 0x464);
        pdVar18 = pdVar18 + 7;
      } while (iVar13 < 2);
      pdVar17 = (double *)(param_1 + 0xc28);
      iVar13 = 2;
      pdVar18 = adStack_f0;
      puVar14 = auStack_110;
      pdVar16 = pdVar17;
      do {
        iVar15 = aiStack_218[iVar13];
        if (iVar15 == 0) {
          *puVar14 = *(undefined4 *)pdVar16;
          puVar14[1] = *(undefined4 *)((int)pdVar16 + 4);
          pdVar18[-2] = local_318 * *pdVar16;
          dVar2 = local_270[iVar13 + 1] * *pdVar16;
LAB_004405ee:
          dVar2 = -dVar2;
        }
        else {
          *puVar14 = 0;
          puVar14[1] = 0x3ff00000;
          dVar2 = pdVar16[1];
          if (iVar15 == -1) goto LAB_004405ee;
        }
        *pdVar18 = dVar2;
        iVar13 = iVar13 + 1;
        puVar14 = puVar14 + 0x10;
        pdVar16 = (double *)((int)pdVar16 + 0x464);
        pdVar18 = pdVar18 + 7;
      } while (iVar13 < 4);
      if (local_324 == 0.0) {
        adStack_b0[2] = local_318 * *pdVar17;
        uStack_88 = *(undefined4 *)(param_1 + 0x1e50);
        uStack_84 = *(undefined4 *)(param_1 + 0x1e54);
        adStack_b0[3] = local_318 * *(double *)(param_1 + 0x108c);
        dStack_90 = (*(double *)(param_1 + 0x108c) + *pdVar17) * local_2e8 +
                    *(double *)(param_1 + 0x1e50);
        dVar2 = *(double *)(param_1 + 0x1e50);
        dVar3 = local_270[3] * *pdVar17 + local_270[4] * *(double *)(param_1 + 0x108c);
LAB_004404d3:
        uStack_80 = local_270[5] * dVar2 - dVar3 * local_318;
      }
      else {
LAB_004403a2:
        dStack_90 = 1.0;
        if (local_324 == -NAN) {
          uStack_80 = -(double)CONCAT44(uStack_2f4,local_2f8);
        }
        else {
          uStack_80 = (double)CONCAT44(uStack_2f4,local_2f8);
        }
      }
    }
    else if (iVar13 == 1) {
      pdVar17 = (double *)(param_1 + 0x360);
      iVar13 = 0;
      pdVar18 = adStack_160;
      puVar14 = local_190;
      do {
        iVar15 = aiStack_218[iVar13];
        if (iVar15 == 0) {
          dVar2 = *pdVar17;
          *puVar14 = *(undefined4 *)pdVar17;
          puVar14[1] = *(undefined4 *)((int)pdVar17 + 4);
          pdVar18[-2] = local_318 * dVar2;
          dVar2 = local_270[iVar13 + 1] * *pdVar17;
LAB_0044042a:
          dVar2 = -dVar2;
        }
        else {
          dVar2 = pdVar17[1];
          *puVar14 = 0;
          puVar14[1] = 0x3ff00000;
          if (iVar15 == -1) goto LAB_0044042a;
        }
        *pdVar18 = dVar2;
        iVar13 = iVar13 + 1;
        puVar14 = puVar14 + 0x10;
        pdVar17 = (double *)((int)pdVar17 + 0x464);
        pdVar18 = pdVar18 + 7;
      } while (iVar13 < 5);
      if (local_324 == 0.0) {
        pdVar17 = (double *)(param_1 + 0x360);
        iVar13 = 0;
        dVar2 = _DAT_0059e430;
        dVar3 = _DAT_0059e430;
        do {
          iVar15 = iVar13 + 8;
          *(double *)((int)adStack_b0 + iVar13) = local_318 * *pdVar17;
          dVar2 = dVar2 + *pdVar17;
          dVar3 = *(double *)((int)local_270 + iVar13 + 8) * *pdVar17 + dVar3;
          pdVar17 = (double *)((int)pdVar17 + 0x464);
          iVar13 = iVar15;
        } while (iVar15 < 0x20);
        uStack_88 = *(undefined4 *)(param_1 + 0x1e50);
        uStack_84 = *(undefined4 *)(param_1 + 0x1e54);
        dStack_90 = dVar2 * local_2e8 + *(double *)(param_1 + 0x1e50);
        dVar2 = *(double *)(param_1 + 0x1e50);
        goto LAB_004404d3;
      }
      dStack_90 = 1.0;
      if (local_324 == -NAN) {
        uStack_80 = -(double)CONCAT44(uStack_2f4,local_2f8);
      }
      else {
        uStack_80 = (double)CONCAT44(uStack_2f4,local_2f8);
      }
    }
    else if (iVar13 == 2) {
      iVar13 = 0;
      pdVar18 = adStack_160;
      puVar14 = local_190;
      pdVar17 = (double *)(param_1 + 0x360);
      do {
        iVar15 = aiStack_218[iVar13];
        if (iVar15 == 0) {
          dVar2 = *pdVar17;
          *puVar14 = *(undefined4 *)pdVar17;
          puVar14[1] = *(undefined4 *)((int)pdVar17 + 4);
          pdVar18[-2] = local_318 * dVar2;
          dVar2 = local_270[iVar13 + 1] * *pdVar17;
LAB_00440295:
          dVar2 = -dVar2;
        }
        else {
          dVar2 = pdVar17[1];
          *puVar14 = 0;
          puVar14[1] = 0x3ff00000;
          if (iVar15 == -1) goto LAB_00440295;
        }
        *pdVar18 = dVar2;
        iVar13 = iVar13 + 1;
        puVar14 = puVar14 + 0x10;
        pdVar17 = (double *)((int)pdVar17 + 0x464);
        pdVar18 = pdVar18 + 7;
      } while (iVar13 < 2);
      iVar13 = 2;
      pdVar18 = adStack_f0;
      puVar14 = auStack_110;
      pdVar17 = (double *)(param_1 + 0xc30);
      do {
        iVar15 = aiStack_218[iVar13];
        *puVar14 = 0;
        puVar14[1] = 0x3ff00000;
        if (iVar15 == 0) {
          dVar2 = local_270[iVar13 + 1];
LAB_004402ec:
          dVar2 = -dVar2;
        }
        else {
          dVar2 = *pdVar17;
          if (iVar15 == -1) goto LAB_004402ec;
        }
        *pdVar18 = dVar2;
        iVar13 = iVar13 + 1;
        puVar14 = puVar14 + 0x10;
        pdVar17 = (double *)((int)pdVar17 + 0x464);
        pdVar18 = pdVar18 + 7;
      } while (iVar13 < 4);
      if (local_324 != 0.0) goto LAB_004403a2;
      uStack_88 = *(undefined4 *)(param_1 + 0x1e50);
      adStack_b0[0] = local_318 * *(double *)(param_1 + 0x360);
      uStack_84 = *(undefined4 *)(param_1 + 0x1e54);
      adStack_b0[1] = local_318 * *(double *)(param_1 + 0x7c4);
      dStack_90 = (*(double *)(param_1 + 0x7c4) + *(double *)(param_1 + 0x360)) * local_2e8 +
                  *(double *)(param_1 + 0x1e50);
      uStack_80 = local_270[5] * *(double *)(param_1 + 0x1e50) -
                  (local_270[1] * *(double *)(param_1 + 0x360) +
                  local_270[2] * *(double *)(param_1 + 0x7c4)) * local_318;
    }
    if (local_30c == 0) {
      uStack_58 = *(undefined4 *)(param_1 + 0x1e50);
      dStack_50 = *(double *)(param_1 + 0x1e50) + *(double *)(param_1 + 0x1c74);
      uStack_54 = *(undefined4 *)(param_1 + 0x1e54);
      dStack_48 = local_270[5] * *(double *)(param_1 + 0x1e50) -
                  local_240 * *(double *)(param_1 + 0x1c74);
    }
    else {
      dStack_50 = 1.0;
      if (local_30c == -1) {
        dStack_48 = -local_2a8;
      }
      else {
        dStack_48 = local_2a8;
      }
    }
    FUN_005677b0();
    bVar11 = true;
    iVar13 = 0;
    pdVar18 = adStack_160;
    pdVar17 = (double *)(param_1 + 0x368);
    do {
      if ((aiStack_218[iVar13] == 0) && (*pdVar17 < ABS(*pdVar18))) {
        bVar11 = false;
        if (*pdVar18 <= _DAT_0059e430) {
          iVar15 = -1;
        }
        else {
          iVar15 = 1;
        }
        aiStack_218[iVar13] = iVar15;
      }
      iVar13 = iVar13 + 1;
      pdVar17 = (double *)((int)pdVar17 + 0x464);
      pdVar18 = pdVar18 + 7;
    } while (iVar13 < 4);
    if ((local_30c != 0) || (ABS(dStack_48) <= local_2a8)) {
      if (bVar11) {
        pdVar18 = adStack_160;
        pdVar17 = (double *)(param_1 + 0x660);
        iVar13 = 0;
        do {
          dVar2 = *pdVar18;
          *(double *)((int)adStack_28 + iVar13) = dVar2;
          *pdVar17 = ABS(dVar2) - pdVar17[1];
          if (ABS(dVar2) - pdVar17[1] < _DAT_0059e430) {
            *(undefined4 *)pdVar17 = 0;
            *(undefined4 *)((int)pdVar17 + 4) = 0;
          }
          iVar15 = iVar13 + 8;
          pdVar18 = pdVar18 + 7;
          pdVar17 = (double *)((int)pdVar17 + 0x464);
          *(double *)((int)adStack_1c8 + iVar13 + 8) =
               dVar2 + *(double *)((int)local_270 + iVar13 + 8);
          iVar13 = iVar15;
        } while (iVar15 < 0x20);
        iVar13 = *(int *)(param_1 + 0x1e14);
        local_320 = uStack_80 * local_318;
        if (iVar13 == 0) {
          adStack_1c8[3] = adStack_1c8[3] + local_320;
          adStack_1c8[4] = adStack_1c8[4] + local_320;
        }
        else if (iVar13 == 1) {
          iVar13 = 0;
          do {
            iVar13 = iVar13 + 1;
            adStack_1c8[iVar13] = local_320 + adStack_1c8[iVar13];
          } while (iVar13 < 4);
        }
        else if (iVar13 == 2) {
          adStack_1c8[1] = adStack_1c8[1] + local_320;
          adStack_1c8[2] = adStack_1c8[2] + local_320;
        }
        pdVar17 = (double *)(param_1 + 0x360);
        dStack_1a0 = (local_270[5] - uStack_80) - dStack_48;
        dStack_198 = dStack_48 + local_240;
        iVar13 = 0;
        do {
          iVar15 = iVar13 + 8;
          dVar2 = *pdVar17;
          pdVar17 = (double *)((int)pdVar17 + 0x464);
          *(double *)((int)adStack_1f0 + iVar13) =
               *(double *)((int)adStack_1c8 + iVar13 + 8) * dVar2;
          iVar13 = iVar15;
        } while (iVar15 < 0x20);
        dStack_1d0 = dStack_1a0 * *(double *)(param_1 + 0x1e50);
        pdVar17 = (double *)(param_1 + 0x348);
        adStack_1c8[0] = (dStack_48 + local_240) * *(double *)(param_1 + 0x1c74);
        iVar13 = 0;
        do {
          if (*(double *)((int)adStack_1f0 + iVar13) == _DAT_0059e430) {
LAB_004409b0:
            *(undefined4 *)((int)&uStack_2e0 + iVar13) = 0xffffffff;
            *(undefined4 *)((int)&uStack_2e0 + iVar13 + 4) = 0x7fefffff;
          }
          else {
            dVar2 = -(*pdVar17 / *(double *)((int)adStack_1f0 + iVar13));
            *(double *)((int)&uStack_2e0 + iVar13) = dVar2;
            if (dVar2 < _DAT_0059e430 != (dVar2 == _DAT_0059e430)) goto LAB_004409b0;
          }
          iVar13 = iVar13 + 8;
          pdVar17 = (double *)((int)pdVar17 + 0x464);
        } while (iVar13 < 0x20);
        iVar13 = *(int *)(param_1 + 0x1e14);
        if (iVar13 == 0) {
          dVar2 = *(double *)(param_1 + 0x1074) + *(double *)(param_1 + 0xc10);
          local_238 = adStack_1f0[3];
LAB_00440a52:
          local_238 = local_238 + adStack_1f0[2];
LAB_00440a59:
          local_300 = dVar2 * local_318;
          local_238 = local_238 * local_318;
        }
        else {
          if (iVar13 == 1) {
            dVar2 = *(double *)(param_1 + 0x1074) + *(double *)(param_1 + 0xc10) +
                    *(double *)(param_1 + 0x7ac) + *(double *)(param_1 + 0x348);
            local_238 = adStack_1f0[1] + adStack_1f0[0] + adStack_1f0[3];
            goto LAB_00440a52;
          }
          if (iVar13 == 2) {
            dVar2 = *(double *)(param_1 + 0x7ac) + *(double *)(param_1 + 0x348);
            local_238 = adStack_1f0[1] + adStack_1f0[0];
            goto LAB_00440a59;
          }
        }
        if ((((dStack_1d0 - local_238 == _DAT_0059e430) || (local_318 == _DAT_0059e430)) ||
            ((double)CONCAT44(uStack_2f4,local_2f8) == _DAT_0059e430)) ||
           (dStack_2c0 = (local_300 - *(double *)(param_1 + 0x1e38)) / (dStack_1d0 - local_238),
           dStack_2c0 < _DAT_0059e430 != (dStack_2c0 == _DAT_0059e430))) {
          dStack_2c0 = 1.7976931348623157e+308;
        }
        local_2b0 = dStack_1d0 - adStack_1c8[0];
        if (((local_2b0 == _DAT_0059e430) || (local_2a8 == _DAT_0059e430)) ||
           (dStack_2b8 = (*(double *)(param_1 + 0x1c5c) - *(double *)(param_1 + 0x1e38)) / local_2b0
           , dStack_2b8 < _DAT_0059e430 != (dStack_2b8 == _DAT_0059e430))) {
          dStack_2b8 = 1.7976931348623157e+308;
        }
        if (dStack_2b8 <= dStack_2c0) {
          local_308 = dStack_2b8;
        }
        else {
          local_308 = dStack_2c0;
        }
        dVar2 = param_2;
        if ((local_308 <= param_2) && (dVar2 = dStack_2b8, dStack_2c0 < dStack_2b8)) {
          dVar2 = dStack_2c0;
        }
        dVar3 = dStack_2d8;
        if (uStack_2e0 < dStack_2d8) {
          dVar3 = uStack_2e0;
        }
        dVar4 = dStack_2c8;
        if (dStack_2d0 < dStack_2c8) {
          dVar4 = dStack_2d0;
        }
        if (dVar4 <= dVar3) {
          dVar3 = dStack_2c8;
          if (dStack_2d0 < dStack_2c8) {
            dVar3 = dStack_2d0;
          }
        }
        else {
          dVar3 = dStack_2d8;
          if (uStack_2e0 < dStack_2d8) {
            dVar3 = uStack_2e0;
          }
        }
        if (dVar3 <= dVar2) {
          dVar2 = dStack_2d8;
          if (uStack_2e0 < dStack_2d8) {
            dVar2 = uStack_2e0;
          }
          dVar3 = dStack_2c8;
          if (dStack_2d0 < dStack_2c8) {
            dVar3 = dStack_2d0;
          }
          if (dVar3 <= dVar2) {
            dVar2 = dStack_2c8;
            if (dStack_2d0 < dStack_2c8) {
              dVar2 = dStack_2d0;
            }
          }
          else {
            dVar2 = dStack_2d8;
            if (uStack_2e0 < dStack_2d8) {
              dVar2 = uStack_2e0;
            }
          }
        }
        else {
          dVar3 = dStack_2b8;
          if (dStack_2c0 < dStack_2b8) {
            dVar3 = dStack_2c0;
          }
          dVar2 = param_2;
          if ((dVar3 <= param_2) && (dVar2 = dStack_2b8, dStack_2c0 < dStack_2b8)) {
            dVar2 = dStack_2c0;
          }
        }
        piVar20 = aiStack_218;
        pdVar17 = (double *)(param_1 + 0x348);
        iVar13 = 0;
        do {
          iVar15 = *piVar20;
          pdVar17[-2] = dVar2 * *pdVar17 + pdVar17[-2];
          if ((iVar15 == 0) || (dVar2 == *(double *)((int)&uStack_2e0 + iVar13))) {
            *(undefined4 *)pdVar17 = 0;
            *(undefined4 *)((int)pdVar17 + 4) = 0;
            *piVar20 = 0;
          }
          else {
            *pdVar17 = dVar2 * *(double *)((int)adStack_1f0 + iVar13) + *pdVar17;
          }
          iVar13 = iVar13 + 8;
          pdVar17 = (double *)((int)pdVar17 + 0x464);
          piVar20 = piVar20 + 1;
        } while (iVar13 < 0x20);
        if ((local_324 == 0.0) || (dVar2 == dStack_2c0)) {
          iVar13 = *(int *)(param_1 + 0x1e14);
          if (iVar13 == 0) {
            dVar3 = *(double *)(param_1 + 0x1074) + *(double *)(param_1 + 0xc10);
LAB_00440d9e:
            local_300 = dVar3 * local_318;
          }
          else {
            if (iVar13 == 1) {
              dVar3 = *(double *)(param_1 + 0x1074) + *(double *)(param_1 + 0xc10) +
                      *(double *)(param_1 + 0x7ac) + *(double *)(param_1 + 0x348);
              goto LAB_00440d9e;
            }
            if (iVar13 == 2) {
              dVar3 = *(double *)(param_1 + 0x7ac) + *(double *)(param_1 + 0x348);
              goto LAB_00440d9e;
            }
          }
          *(undefined4 *)(param_1 + 0x1e38) = (undefined4)local_300;
          *(undefined4 *)(param_1 + 0x1e3c) = local_300._4_4_;
          local_324 = 0.0;
        }
        else {
          *(double *)(param_1 + 0x1e38) = dStack_1d0 * dVar2 + *(double *)(param_1 + 0x1e38);
        }
        if ((local_30c == 0) || (dVar2 == dStack_2b8)) {
          *(undefined4 *)(param_1 + 0x1c5c) = *(undefined4 *)(param_1 + 0x1e38);
          *(undefined4 *)(param_1 + 0x1c60) = *(undefined4 *)(param_1 + 0x1e3c);
          local_30c = 0;
        }
        else {
          *(double *)(param_1 + 0x1c5c) = adStack_1c8[0] * dVar2 + *(double *)(param_1 + 0x1c5c);
        }
        if (dVar2 != param_2) {
          dVar3 = dVar2 / param_2;
          local_320 = local_320 * dVar3;
          uStack_80 = uStack_80 * dVar3;
          iVar13 = 0;
          do {
            iVar15 = iVar13 + 8;
            *(double *)((int)adStack_28 + iVar13) = dVar3 * *(double *)((int)adStack_28 + iVar13);
            *(double *)((int)adStack_1c8 + iVar13 + 8) =
                 dVar3 * *(double *)((int)adStack_1c8 + iVar13 + 8);
            iVar13 = iVar15;
          } while (iVar15 < 0x20);
        }
        iVar13 = *(int *)(param_1 + 0x1e14);
        if (iVar13 == 0) {
          iVar15 = *(int *)(param_1 + 0xcb0);
          dStack_288 = local_320 * _DAT_0059ed20;
          iVar7 = *(int *)(param_1 + 0x1114);
          dStack_228 = local_320 * *(double *)(iVar7 + 0x34);
          dStack_220 = local_320 * *(double *)(iVar7 + 0x4c);
          dStack_2a0 = local_320 * *(double *)(iVar7 + 0x1c) +
                       local_320 * *(double *)(iVar15 + 0x1c);
          dStack_298 = dStack_228 + local_320 * *(double *)(iVar15 + 0x34);
          dStack_290 = dStack_220 + local_320 * *(double *)(iVar15 + 0x4c);
        }
        else if (iVar13 == 1) {
          iVar15 = *(int *)(param_1 + 1000);
          dStack_288 = local_320 * _DAT_0059ed08;
          iVar7 = *(int *)(param_1 + 0x84c);
          dStack_228 = local_320 * *(double *)(iVar7 + 0x34);
          iVar19 = *(int *)(param_1 + 0xcb0);
          iVar8 = *(int *)(param_1 + 0x1114);
          dStack_220 = local_320 * *(double *)(iVar8 + 0x4c);
          dStack_2a0 = local_320 * *(double *)(iVar8 + 0x1c) +
                       local_320 * *(double *)(iVar19 + 0x1c) +
                       local_320 * *(double *)(iVar7 + 0x1c) +
                       local_320 * *(double *)(iVar15 + 0x1c);
          dStack_298 = local_320 * *(double *)(iVar8 + 0x34) +
                       local_320 * *(double *)(iVar19 + 0x34) +
                       dStack_228 + local_320 * *(double *)(iVar15 + 0x34);
          dStack_290 = dStack_220 +
                       local_320 * *(double *)(iVar19 + 0x4c) +
                       local_320 * *(double *)(iVar7 + 0x4c) +
                       local_320 * *(double *)(iVar15 + 0x4c);
        }
        else if (iVar13 == 2) {
          iVar15 = *(int *)(param_1 + 1000);
          dStack_288 = local_320 * _DAT_0059ed20;
          iVar7 = *(int *)(param_1 + 0x84c);
          dStack_228 = local_320 * *(double *)(iVar7 + 0x34);
          dStack_220 = local_320 * *(double *)(iVar7 + 0x4c);
          dStack_2a0 = local_320 * *(double *)(iVar7 + 0x1c) +
                       local_320 * *(double *)(iVar15 + 0x1c);
          dStack_298 = dStack_228 + local_320 * *(double *)(iVar15 + 0x34);
          dStack_290 = dStack_220 + local_320 * *(double *)(iVar15 + 0x4c);
        }
        dStack_288 = dStack_288 * *(double *)(param_1 + 0x1ea4);
        if ((iVar13 != 0) || (iVar13 = *(int *)(param_1 + 0x141c), iVar13 == 0)) {
          iVar13 = *(int *)(param_1 + 0x15f0);
        }
        dStack_280 = dStack_288 * *(double *)(iVar13 + 0x2c);
        dVar3 = dStack_288 * *(double *)(iVar13 + 0x44);
        dStack_30 = dStack_288 * *(double *)(iVar13 + 0x5c);
        *(double *)(iVar13 + 0x14c) = *(double *)(iVar13 + 0x14c) - (dStack_280 + dStack_2a0);
        *(double *)(iVar13 + 0x154) = *(double *)(iVar13 + 0x154) - (dStack_298 + dVar3);
        *(double *)(iVar13 + 0x15c) = *(double *)(iVar13 + 0x15c) - (dStack_290 + dStack_30);
        iVar13 = *(int *)(param_1 + 0x15f0);
        dStack_280 = uStack_80 * *(double *)(iVar13 + 0x2c) - dStack_280;
        *(double *)(iVar13 + 0x14c) = *(double *)(iVar13 + 0x14c) - dStack_280;
        *(double *)(iVar13 + 0x154) =
             *(double *)(iVar13 + 0x154) - (uStack_80 * *(double *)(iVar13 + 0x44) - dVar3);
        *(double *)(iVar13 + 0x15c) =
             *(double *)(iVar13 + 0x15c) - (uStack_80 * *(double *)(iVar13 + 0x5c) - dStack_30);
        iVar13 = 0;
        piVar20 = (int *)(param_1 + 1000);
        do {
          iVar15 = piVar20[1];
          if (iVar15 == 0) {
            iVar15 = *(int *)(param_1 + 0x141c);
          }
          iVar7 = *piVar20;
          dVar3 = *(double *)((int)adStack_28 + iVar13);
          iVar19 = iVar13 + 8;
          dVar4 = *(double *)(iVar7 + 0x34);
          dVar5 = *(double *)(iVar7 + 0x4c);
          *(double *)(iVar15 + 0x14c) =
               *(double *)(iVar15 + 0x14c) - dVar3 * *(double *)(iVar7 + 0x1c);
          *(double *)(iVar15 + 0x154) = *(double *)(iVar15 + 0x154) - dVar3 * dVar4;
          *(double *)(iVar15 + 0x15c) = *(double *)(iVar15 + 0x15c) - dVar3 * dVar5;
          iVar15 = *piVar20;
          dVar3 = *(double *)((int)adStack_1c8 + iVar13 + 8);
          local_278 = dVar3 * *(double *)(iVar15 + 0x34);
          local_270[0] = dVar3 * *(double *)(iVar15 + 0x4c);
          *(double *)(iVar15 + 0x14c) =
               dVar3 * *(double *)(iVar15 + 0x1c) + *(double *)(iVar15 + 0x14c);
          *(double *)(iVar15 + 0x154) = local_278 + *(double *)(iVar15 + 0x154);
          *(double *)(iVar15 + 0x15c) = local_270[0] + *(double *)(iVar15 + 0x15c);
          iVar13 = iVar19;
          piVar20 = piVar20 + 0x119;
        } while (iVar19 < 0x20);
        if (dVar2 == param_2) {
          return;
        }
        param_2 = param_2 - dVar2;
      }
      goto LAB_00440210;
    }
    if (dStack_48 <= _DAT_0059e430) {
      local_30c = -1;
    }
    else {
      local_30c = 1;
    }
  } while( true );
}


