// Function: FUN_004df110 @ 004df110
// Size (bytes): 2367


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004df110(float *param_1,float param_2,int param_3)

{
  uint *puVar1;
  float fVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  bool bVar12;
  undefined4 *puVar13;
  float fVar14;
  float *pfVar15;
  int iVar16;
  float *pfVar17;
  int iVar18;
  int iVar19;
  undefined4 *puVar20;
  int iVar21;
  int local_b0;
  int *local_ac;
  int local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  int local_94;
  float local_8c;
  int local_88;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_38;
  float local_30;
  undefined4 local_1c [4];
  undefined1 local_c [12];
  
  bVar12 = false;
  if (*param_1 <= param_2) {
    if (param_3 == -1) {
      param_3 = 0;
      if (0 < (int)param_1[6]) {
        pfVar15 = param_1 + 8;
        do {
          if (*param_1 < *pfVar15) break;
          param_3 = param_3 + 1;
          pfVar15 = pfVar15 + 9;
        } while (param_3 < (int)param_1[6]);
      }
    }
  }
  else {
    fVar2 = param_1[6];
    fVar14 = 0.0;
    if (0 < (int)fVar2) {
      pfVar15 = param_1 + 8;
      do {
        if ((param_2 < *pfVar15) && (*pfVar15 < *param_1 != (*pfVar15 == *param_1))) break;
        fVar14 = (float)((int)fVar14 + 1);
        pfVar15 = pfVar15 + 9;
      } while ((int)fVar14 < (int)fVar2);
    }
    if (fVar14 == fVar2) {
      *param_1 = param_2;
      return;
    }
    local_ac = (int *)0x0;
    if (0 < (int)param_1[2]) {
      local_b0 = 0;
      do {
        iVar18 = (int)param_1[3] + local_b0;
        iVar19 = 0;
        if (0 < *(int *)((int)param_1[3] + 4 + local_b0)) {
          iVar21 = 0;
          do {
            iVar16 = *(int *)(iVar18 + 8);
            puVar20 = *(undefined4 **)(iVar16 + iVar21);
            *puVar20 = *(undefined4 *)(iVar16 + 4 + iVar21);
            puVar20[1] = *(undefined4 *)(iVar16 + iVar21 + 8);
            puVar20[2] = *(undefined4 *)(iVar16 + iVar21 + 0xc);
            iVar19 = iVar19 + 1;
            iVar21 = iVar21 + 0x40;
          } while (iVar19 < *(int *)(iVar18 + 4));
        }
        local_ac = (int *)((int)local_ac + 1);
        local_b0 = local_b0 + 0xc;
      } while ((int)local_ac < (int)param_1[2]);
    }
    param_3 = 0;
    bVar12 = true;
  }
  *param_1 = param_2;
  if (param_3 < (int)param_1[6]) {
    pfVar15 = param_1 + param_3 * 9 + 0xe;
    local_88 = param_3;
    do {
      if (pfVar15[-6] <= param_2) {
        fVar2 = pfVar15[-7];
        bVar12 = true;
        if (fVar2 == 0.0) {
          fVar2 = pfVar15[1] + _DAT_005ad144;
          local_54 = pfVar15[-5];
          local_50 = pfVar15[-4];
          local_4c = pfVar15[-3];
          local_48 = pfVar15[-2];
          local_40 = *pfVar15;
          fVar14 = _DAT_0059e43c / fVar2;
          local_44 = pfVar15[-1];
          local_94 = 0;
          if (0 < (int)param_1[2]) {
            local_b0 = 0;
            do {
              iVar19 = (int)param_1[3] + local_b0;
              iVar18 = 0;
              if (0 < *(int *)((int)param_1[3] + 4 + local_b0)) {
                iVar21 = 0;
                do {
                  iVar16 = *(int *)(iVar19 + 8);
                  pfVar17 = *(float **)(iVar16 + iVar21);
                  iVar16 = iVar16 + iVar21;
                  fVar4 = (*pfVar17 - local_54) * (*pfVar17 - local_54) +
                          (pfVar17[1] - local_50) * (pfVar17[1] - local_50) +
                          (pfVar17[2] - local_4c) * (pfVar17[2] - local_4c);
                  if (fVar4 < fVar2 * fVar2) {
                    fVar4 = _DAT_0059e43c - SQRT(fVar4) * fVar14;
                    fVar5 = local_48 * fVar4 + *pfVar17;
                    *pfVar17 = fVar5;
                    local_58 = local_44 * fVar4 + pfVar17[1];
                    pfVar17[1] = local_58;
                    fVar4 = local_40 * fVar4 + pfVar17[2];
                    pfVar17[2] = fVar4;
                    fVar5 = fVar5 - *(float *)(iVar16 + 4);
                    local_38 = local_58 - *(float *)(iVar16 + 8);
                    fVar4 = fVar4 - *(float *)(iVar16 + 0xc);
                    fVar6 = fVar5 * fVar5 + local_38 * local_38 + fVar4 * fVar4;
                    if (*(float *)(iVar16 + 0x10) < fVar6) {
                      fVar6 = SQRT(*(float *)(iVar16 + 0x10) / fVar6);
                      *pfVar17 = fVar6 * fVar5 + *(float *)(iVar16 + 4);
                      pfVar17[1] = local_38 * fVar6 + *(float *)(iVar16 + 8);
                      pfVar17[2] = fVar6 * fVar4 + *(float *)(iVar16 + 0xc);
                    }
                  }
                  iVar18 = iVar18 + 1;
                  iVar21 = iVar21 + 0x40;
                } while (iVar18 < *(int *)(iVar19 + 4));
              }
              local_94 = local_94 + 1;
              local_b0 = local_b0 + 0xc;
            } while (local_94 < (int)param_1[2]);
          }
          local_94 = 0;
          if (0 < (int)param_1[4]) {
            local_ac = (int *)0x0;
            do {
              pfVar17 = (float *)((int)param_1[5] + (int)local_ac);
              iVar18 = 0;
              if (0 < *(int *)((int)param_1[5] + 0x10 + (int)local_ac)) {
                do {
                  puVar20 = *(undefined4 **)((int)pfVar17[5] + iVar18 * 4);
                  pfVar3 = (float *)*puVar20;
                  if ((((*pfVar3 != (float)puVar20[1]) || (pfVar3[1] != (float)puVar20[2])) ||
                      (pfVar3[2] != (float)puVar20[3])) &&
                     ((fVar2 = (*pfVar3 - *pfVar17) * (*pfVar3 - *pfVar17) +
                               (pfVar3[1] - pfVar17[1]) * (pfVar3[1] - pfVar17[1]) +
                               (pfVar3[2] - pfVar17[2]) * (pfVar3[2] - pfVar17[2]),
                      DAT_0059e440 < fVar2 && (fVar2 < pfVar17[3])))) {
                    fVar2 = (float)puVar20[1];
                    fVar5 = *pfVar3 - fVar2;
                    fVar14 = (float)puVar20[2];
                    fVar4 = (float)puVar20[3];
                    fVar6 = pfVar3[1] - fVar14;
                    local_8c = pfVar17[3];
                    fVar7 = pfVar3[2] - fVar4;
                    local_64 = fVar2 - *pfVar17;
                    fVar9 = fVar14 - pfVar17[1];
                    fVar10 = fVar4 - pfVar17[2];
                    fVar8 = fVar9 * fVar9 + fVar10 * fVar10 + local_64 * local_64;
                    if (fVar8 < local_8c) {
                      local_8c = fVar8;
                    }
                    fVar8 = fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7;
                    fVar11 = local_64 * fVar5 + fVar9 * fVar6 + fVar7 * fVar10;
                    fVar11 = fVar11 + fVar11;
                    local_30 = local_64;
                    if ((fVar8 != DAT_0059e440) &&
                       (fVar9 = fVar11 * fVar11 -
                                ((local_64 * local_64 + fVar9 * fVar9 + fVar10 * fVar10) - local_8c)
                                * fVar8 * _DAT_0059e46c, DAT_0059e440 <= fVar9)) {
                      fVar9 = SQRT(fVar9);
                      fVar8 = _DAT_0059e670 / (fVar8 + fVar8);
                      fVar10 = (fVar9 + fVar11) * fVar8;
                      fVar8 = (fVar11 - fVar9) * fVar8;
                      if (ABS(fVar10) < ABS(fVar8)) {
                        fVar8 = fVar10;
                      }
                      *pfVar3 = fVar5 * fVar8 + fVar2;
                      pfVar3[1] = fVar6 * fVar8 + fVar14;
                      pfVar3[2] = fVar8 * fVar7 + fVar4;
                    }
                  }
                  iVar18 = iVar18 + 1;
                } while (iVar18 < (int)pfVar17[4]);
              }
              local_94 = local_94 + 1;
              local_ac = (int *)((int)local_ac + 0x18);
            } while (local_94 < (int)param_1[4]);
          }
        }
        else if (fVar2 == 1.4013e-45) {
          local_ac = (int *)0x0;
          if (0 < (int)param_1[2]) {
            local_b0 = 0;
            do {
              iVar19 = (int)param_1[3] + local_b0;
              iVar18 = 0;
              if (0 < *(int *)((int)param_1[3] + 4 + local_b0)) {
                iVar21 = 0;
                do {
                  iVar16 = *(int *)(iVar19 + 8);
                  pfVar17 = *(float **)(iVar16 + iVar21);
                  iVar16 = iVar16 + iVar21;
                  fVar2 = *pfVar17 - *(float *)(iVar16 + 4);
                  fVar14 = pfVar17[1] - *(float *)(iVar16 + 8);
                  fVar5 = pfVar17[2] - *(float *)(iVar16 + 0xc);
                  fVar4 = fVar2 * fVar2 + fVar14 * fVar14 + fVar5 * fVar5;
                  if (_DAT_005ad148 < fVar4) {
                    fVar4 = _DAT_0059ef78 / SQRT(fVar4);
                    *pfVar17 = fVar2 * fVar4 + *(float *)(iVar16 + 4);
                    pfVar17[1] = fVar4 * fVar14 + *(float *)(iVar16 + 8);
                    pfVar17[2] = fVar4 * fVar5 + *(float *)(iVar16 + 0xc);
                  }
                  iVar18 = iVar18 + 1;
                  iVar21 = iVar21 + 0x40;
                } while (iVar18 < *(int *)(iVar19 + 4));
              }
              local_ac = (int *)((int)local_ac + 1);
              local_b0 = local_b0 + 0xc;
            } while ((int)local_ac < (int)param_1[2]);
          }
        }
        else if ((fVar2 == 2.8026e-45) && (local_ac = (int *)0x0, 0 < (int)param_1[2])) {
          local_b0 = 0;
          do {
            iVar19 = 0;
            iVar18 = (int)param_1[3] + local_b0;
            if (0 < *(int *)((int)param_1[3] + 4 + local_b0)) {
              iVar21 = 0;
              do {
                iVar16 = *(int *)(iVar18 + 8);
                puVar20 = *(undefined4 **)(iVar16 + iVar21);
                *puVar20 = *(undefined4 *)(iVar16 + 4 + iVar21);
                puVar20[1] = *(undefined4 *)(iVar16 + iVar21 + 8);
                puVar20[2] = *(undefined4 *)(iVar16 + iVar21 + 0xc);
                iVar19 = iVar19 + 1;
                iVar21 = iVar21 + 0x40;
              } while (iVar19 < *(int *)(iVar18 + 4));
            }
            local_ac = (int *)((int)local_ac + 1);
            local_b0 = local_b0 + 0xc;
          } while ((int)local_ac < (int)param_1[2]);
        }
      }
      local_88 = local_88 + 1;
      pfVar15 = pfVar15 + 9;
    } while (local_88 < (int)param_1[6]);
  }
  if (bVar12) {
    iVar18 = 0;
    if (0 < (int)param_1[2]) {
      iVar19 = 0;
      do {
        puVar1 = (uint *)(*(int *)((int)param_1[3] + iVar19) + 0x14);
        *puVar1 = *puVar1 & 0xfeffffdf;
        puVar1 = (uint *)(*(int *)((int)param_1[3] + iVar19) + 0x14);
        *puVar1 = *puVar1 | 0x400000;
        iVar18 = iVar18 + 1;
        iVar19 = iVar19 + 0xc;
      } while (iVar18 < (int)param_1[2]);
    }
    local_94 = 0;
    if (0 < (int)param_1[2]) {
      local_8c = 0.0;
      do {
        iVar18 = (int)param_1[3] + (int)local_8c;
        local_b0 = 0;
        if (0 < *(int *)((int)param_1[3] + 4 + (int)local_8c)) {
          local_a4 = 0;
          do {
            iVar19 = *(int *)(iVar18 + 8);
            pfVar15 = *(float **)(iVar19 + local_a4);
            iVar19 = iVar19 + local_a4;
            if (((*pfVar15 == *(float *)(iVar19 + 4)) && (pfVar15[1] == *(float *)(iVar19 + 8))) &&
               (pfVar15[2] == *(float *)(iVar19 + 0xc))) {
              pfVar15[6] = *(float *)(iVar19 + 0x20);
              pfVar15[3] = *(float *)(iVar19 + 0x14);
              pfVar15[4] = *(float *)(iVar19 + 0x18);
              pfVar15[5] = *(float *)(iVar19 + 0x1c);
            }
            else {
              local_ac = (int *)(iVar19 + 0x24);
              local_a0 = 0.0;
              local_9c = 0.0;
              local_98 = 0.0;
              pfVar15[6] = 1.4751301e-38;
              local_88 = 0;
              do {
                if (*local_ac == 0) break;
                iVar19 = 0;
                puVar20 = local_1c;
                do {
                  puVar13 = (undefined4 *)FUN_004de5d0();
                  puVar20[-2] = *puVar13;
                  iVar19 = iVar19 + 1;
                  puVar20[-1] = puVar13[1];
                  *puVar20 = puVar13[2];
                  puVar20 = puVar20 + 3;
                } while (iVar19 < 3);
                FUN_004dd9f0(local_c,&local_64);
                local_a0 = local_64 + local_a0;
                local_88 = local_88 + 1;
                local_ac = local_ac + 1;
                local_9c = local_60 + local_9c;
                local_98 = local_5c + local_98;
              } while (local_88 < 7);
              fVar2 = SQRT(local_a0 * local_a0 + local_9c * local_9c + local_98 * local_98);
              if ((float)_DAT_0059e430 < fVar2) {
                fVar2 = _DAT_0059e43c / fVar2;
                pfVar15[5] = fVar2 * local_98;
                pfVar15[3] = local_a0 * fVar2;
                pfVar15[4] = fVar2 * local_9c;
              }
            }
            local_b0 = local_b0 + 1;
            local_a4 = local_a4 + 0x40;
          } while (local_b0 < *(int *)(iVar18 + 4));
        }
        local_8c = (float)((int)local_8c + 0xc);
        local_94 = local_94 + 1;
      } while (local_94 < (int)param_1[2]);
    }
  }
  return;
}


