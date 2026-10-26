// Function: FUN_00448730 @ 00448730
// Size (bytes): 1616


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00448730(float *param_1)

{
  double *pdVar1;
  double dVar2;
  int *piVar3;
  float *pfVar4;
  float *pfVar5;
  uint uVar6;
  float *pfVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint *puVar19;
  uint uVar20;
  float10 fVar21;
  float10 fVar22;
  float10 fVar23;
  float *apfStack_364 [2];
  uint local_35c;
  undefined8 local_358;
  double local_350;
  double local_348;
  float local_340;
  float local_33c;
  float fStack_338;
  float local_334;
  double local_330;
  undefined8 local_328;
  float *local_31c;
  float local_318;
  float fStack_314;
  float fStack_310;
  float fStack_30c;
  double local_308;
  float local_300;
  float local_2fc;
  float fStack_2f8;
  float local_2f4;
  double local_2e8;
  double local_2d8;
  double local_2d0;
  uint local_2c8 [177];
  
  local_348 = (double)CONCAT44(local_348._4_4_,param_1);
  if (((uint)param_1[6] < 0xc) && (1 < (uint)param_1[6])) {
    uVar20 = 0;
    puVar14 = local_2c8 + 2;
    iVar18 = 0x2c;
    do {
      puVar14[-2] = 0;
      puVar14[-1] = 0;
      *puVar14 = 0;
      puVar14[1] = 0;
      puVar14 = puVar14 + 4;
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
    if (param_1[6] != 0.0) {
      local_31c = param_1 + 7;
      local_328._0_4_ = param_1[6];
      do {
        piVar3 = (int *)*local_31c;
        local_358._4_4_ = (float *)*piVar3;
        pfVar4 = (float *)piVar3[2];
        pfVar5 = (float *)piVar3[4];
        local_318 = *local_358._4_4_;
        fStack_314 = local_358._4_4_[1];
        fStack_310 = local_358._4_4_[2];
        fStack_30c = local_358._4_4_[3];
        local_300 = *pfVar4;
        dVar11 = (double)*local_358._4_4_ - (double)local_300;
        pdVar1 = (double *)(pfVar4 + 1);
        local_2fc = *(float *)pdVar1;
        local_2f4 = pfVar4[3];
        fStack_2f8 = pfVar4[2];
        dVar8 = *(double *)(local_358._4_4_ + 1) - *pdVar1;
        dVar10 = (double)local_358._4_4_[3] - (double)local_2f4;
        local_340 = *pfVar5;
        local_33c = pfVar5[1];
        local_2e8 = (double)(*pfVar5 - local_300);
        fStack_338 = pfVar5[2];
        dVar2 = *(double *)(pfVar5 + 1) - *pdVar1;
        local_334 = pfVar5[3];
        dVar12 = (double)pfVar5[3] - (double)local_2f4;
        dVar9 = dVar12 * dVar8 - dVar2 * dVar10;
        dVar10 = local_2e8 * dVar10 - dVar12 * dVar11;
        dVar2 = dVar2 * dVar11 - local_2e8 * dVar8;
        dVar2 = SQRT(dVar9 * dVar9 + dVar10 * dVar10 + dVar2 * dVar2);
        if ((dVar2 < _DAT_0059e430 != (dVar2 == _DAT_0059e430)) || (dVar10 / dVar2 < _DAT_0059e830))
        goto LAB_00448a32;
        if (*(byte *)((int)piVar3 + 0x19) == 0xff) {
          uVar15 = (uint)*(ushort *)((int)piVar3 + 0x1a);
        }
        else {
          uVar15 = (uint)*(byte *)((int)piVar3 + 0x19);
        }
        uVar16 = 0;
        do {
          if ((float *)piVar3[uVar16] == param_1) break;
          uVar16 = uVar16 + 1;
        } while (uVar16 < 6);
        uVar13 = 4;
        switch(uVar16) {
        case 0:
          apfStack_364[1] = (float *)piVar3[1];
          local_35c = piVar3[5];
          uVar13 = 2;
          break;
        case 1:
          local_35c = piVar3[3];
          iVar18 = piVar3[5];
          apfStack_364[1] = pfVar4;
          goto LAB_00448989;
        case 2:
          apfStack_364[1] = (float *)piVar3[3];
          local_35c = piVar3[1];
          uVar13 = 2;
          break;
        case 3:
          local_35c = piVar3[5];
          iVar18 = piVar3[1];
          apfStack_364[1] = pfVar5;
          local_358._4_4_ = pfVar4;
          goto LAB_00448989;
        case 4:
          apfStack_364[1] = (float *)piVar3[5];
          local_35c = piVar3[3];
          uVar13 = 2;
          break;
        case 5:
          local_35c = piVar3[1];
          iVar18 = piVar3[3];
          apfStack_364[1] = local_358._4_4_;
          local_358._4_4_ = pfVar5;
LAB_00448989:
          local_358 = (double)CONCAT44(local_358._4_4_,iVar18);
        }
        uVar16 = 0;
        if (uVar13 != 0) {
          puVar14 = local_2c8 + uVar20 * 4 + 1;
          do {
            uVar17 = 0;
            if (uVar20 != 0) {
              puVar19 = local_2c8;
              do {
                if (((float *)puVar19[1] == apfStack_364[uVar16 + 1]) && (*puVar19 == uVar15))
                break;
                uVar17 = uVar17 + 1;
                puVar19 = puVar19 + 4;
              } while (uVar17 < uVar20);
            }
            if (uVar17 == uVar20) {
              *puVar14 = (uint)apfStack_364[uVar16 + 1];
              uVar20 = uVar20 + 1;
              puVar14 = puVar14 + 4;
            }
            uVar6 = local_2c8[uVar17 * 4 + 2];
            local_2c8[uVar17 * 4] = uVar15;
            if ((uVar6 == 0) && (uVar16 != 0)) {
              local_2c8[uVar17 * 4 + 2] = (uint)apfStack_364[uVar16];
            }
            if ((local_2c8[uVar17 * 4 + 3] == 0) && (uVar16 < uVar13 - 1)) {
              local_2c8[uVar17 * 4 + 3] = (&local_35c)[uVar16];
            }
            uVar16 = uVar16 + 1;
          } while (uVar16 < uVar13);
        }
LAB_00448a32:
        local_328._0_4_ = (float)((int)(float)local_328 + -1);
        local_31c = local_31c + 1;
      } while ((float)local_328 != 0.0);
    }
    fVar21 = (float10)_DAT_0059e430;
    if (uVar20 != 0) {
      puVar14 = local_2c8 + 3;
      do {
        pfVar4 = (float *)*puVar14;
        pfVar5 = (float *)puVar14[-2];
        pfVar7 = (float *)puVar14[-1];
        if ((pfVar4 != (float *)0x0) && (pfVar7 != (float *)0x0)) {
          dVar2 = (double)(*pfVar5 - *param_1);
          local_318 = SUB84(dVar2,0);
          fStack_314 = (float)((ulonglong)dVar2 >> 0x20);
          dVar8 = *(double *)(pfVar5 + 1) - *(double *)(param_1 + 1);
          fStack_310 = SUB84(dVar8,0);
          fStack_30c = (float)((ulonglong)dVar8 >> 0x20);
          local_308 = (double)(pfVar5[3] - param_1[3]);
          local_358 = *(double *)(pfVar4 + 1) - *(double *)(param_1 + 1);
          local_350 = (double)(pfVar4[3] - param_1[3]);
          local_2d8 = *(double *)(pfVar7 + 1) - *(double *)(param_1 + 1);
          local_2d0 = (double)(pfVar7[3] - param_1[3]);
          dVar9 = dVar8 * _DAT_0059e430 - local_308;
          dVar10 = local_308 * _DAT_0059e430 - dVar2 * _DAT_0059e430;
          fStack_338 = SUB84(dVar10,0);
          local_334 = (float)((ulonglong)dVar10 >> 0x20);
          local_330 = dVar2 - dVar8 * _DAT_0059e430;
          dVar11 = dVar10 * local_308 - local_330 * dVar8;
          dVar12 = local_330 * dVar2 - local_308 * dVar9;
          fStack_2f8 = SUB84(dVar12,0);
          local_2f4 = (float)((ulonglong)dVar12 >> 0x20);
          dVar2 = dVar8 * dVar9 - dVar10 * dVar2;
          dVar8 = dVar9 * dVar9 + dVar10 * dVar10 + local_330 * local_330;
          if (dVar8 < _DAT_0059e430 == (dVar8 == _DAT_0059e430)) {
            dVar8 = _DAT_0059e420 / SQRT(dVar8);
            dVar9 = dVar8 * dVar9;
            dVar10 = dVar10 * dVar8;
            fStack_338 = SUB84(dVar10,0);
            local_334 = (float)((ulonglong)dVar10 >> 0x20);
            local_330 = local_330 * dVar8;
          }
          dVar8 = dVar12 * dVar12 + dVar11 * dVar11 + dVar2 * dVar2;
          if (dVar8 < _DAT_0059e430 == (dVar8 == _DAT_0059e430)) {
            dVar8 = _DAT_0059e420 / SQRT(dVar8);
            dVar11 = dVar8 * dVar11;
            dVar12 = dVar12 * dVar8;
            fStack_2f8 = SUB84(dVar12,0);
            local_2f4 = (float)((ulonglong)dVar12 >> 0x20);
            dVar2 = dVar8 * dVar2;
          }
          local_348 = ((double)*pfVar4 - (double)*param_1) * dVar9 +
                      local_358 * dVar10 + local_350 * local_330;
          dVar8 = dVar11 * ((double)*pfVar4 - (double)*param_1) +
                  local_358 * dVar12 + local_350 * dVar2;
          local_328 = ((double)*pfVar7 - (double)*param_1) * dVar9 +
                      local_2d8 * dVar10 + local_2d0 * local_330;
          dVar2 = dVar11 * ((double)*pfVar7 - (double)*param_1) +
                  local_2d8 * dVar12 + local_2d0 * dVar2;
          if (((local_348 < _DAT_0059e430 == (local_348 == _DAT_0059e430)) ||
              (local_328 < _DAT_0059e430 == (local_328 == _DAT_0059e430))) &&
             ((local_348 < _DAT_0059e430 || (local_328 < _DAT_0059e430)))) {
            fVar22 = (float10)fpatan((float10)dVar8 / (float10)local_348,(float10)1);
            fVar23 = (float10)fpatan((float10)dVar2 / (float10)local_328,(float10)1);
            if (ABS(fVar22 - fVar23) <= (float10)_DAT_0059ec60) {
              fVar21 = ((float10)_DAT_0059e420 - ABS(fVar22 - fVar23) * (float10)_DAT_0059ef28) *
                       ((((float10)dVar2 - (float10)dVar8) *
                         ((float10)local_348 / ((float10)local_348 - (float10)local_328)) +
                        (float10)dVar8) / (float10)dVar12) * (float10)_DAT_0059e880 + fVar21;
            }
          }
        }
        puVar14 = puVar14 + 4;
        uVar20 = uVar20 - 1;
      } while (uVar20 != 0);
      if ((float10)_DAT_0059ef20 < fVar21) {
        *(double *)(param_1 + 4) = _DAT_0059ef20 + *(double *)(param_1 + 1);
        return;
      }
      if (fVar21 < (float10)_DAT_0059ef18) {
        fVar21 = (float10)_DAT_0059ef18;
      }
    }
    *(double *)(param_1 + 4) = (double)(fVar21 + (float10)*(double *)(param_1 + 1));
  }
  return;
}


