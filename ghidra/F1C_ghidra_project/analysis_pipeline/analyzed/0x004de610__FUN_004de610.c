// Function: FUN_004de610 @ 004de610
// Size (bytes): 1798


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004de610(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int *piVar8;
  void *pvVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 uVar12;
  int *piVar13;
  float *pfVar14;
  int iVar15;
  int iVar16;
  float *pfVar17;
  int iVar18;
  float *pfVar19;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  float local_2c;
  float local_28;
  int local_24 [3];
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  *(int *)(param_1 + 4) = param_3;
  iVar7 = FUN_0054c210();
  *(int *)(param_1 + 8) = iVar7;
  piVar8 = operator_new(iVar7 * 0xc + 4);
  if (piVar8 == (int *)0x0) {
    piVar13 = (int *)0x0;
  }
  else {
    piVar13 = piVar8 + 1;
    *piVar8 = iVar7;
    piVar8 = piVar13;
    if (-1 < iVar7 + -1) {
      do {
        *piVar8 = 0;
        piVar8[1] = 0;
        piVar8[2] = 0;
        iVar7 = iVar7 + -1;
        piVar8 = piVar8 + 3;
      } while (iVar7 != 0);
    }
  }
  *(int **)(param_1 + 0xc) = piVar13;
  param_3 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    local_48 = 0;
    do {
      iVar7 = FUN_0054c230(param_3);
      piVar8 = (int *)(*(int *)(param_1 + 0xc) + local_48);
      *piVar8 = iVar7;
      iVar7 = FUN_0054e100();
      piVar8[1] = iVar7;
      pvVar9 = operator_new(iVar7 << 6);
      piVar8[2] = (int)pvVar9;
      local_44 = 0;
      if (0 < piVar8[1]) {
        local_54 = 0;
        do {
          puVar10 = (undefined4 *)FUN_0054e120(local_44);
          iVar7 = piVar8[2];
          *(undefined4 **)(iVar7 + local_54) = puVar10;
          uVar12 = puVar10[2];
          uVar1 = puVar10[1];
          iVar7 = iVar7 + local_54;
          local_4c = 0;
          *(undefined4 *)(iVar7 + 4) = *puVar10;
          *(undefined4 *)(iVar7 + 8) = uVar1;
          *(undefined4 *)(iVar7 + 0xc) = uVar12;
          uVar12 = puVar10[5];
          uVar1 = puVar10[4];
          *(undefined4 *)(iVar7 + 0x14) = puVar10[3];
          *(undefined4 *)(iVar7 + 0x18) = uVar1;
          *(undefined4 *)(iVar7 + 0x1c) = uVar12;
          *(undefined4 *)(iVar7 + 0x20) = puVar10[6];
          *(undefined4 *)(iVar7 + 0x10) = *param_2;
          if (0 < (int)param_2[1]) {
            iVar18 = 0;
            do {
              pfVar14 = (float *)(param_2[2] + iVar18);
              fVar3 = *pfVar14;
              local_2c = pfVar14[1];
              local_28 = pfVar14[2];
              iVar11 = *(int *)(param_1 + 4);
              if (*(char *)(iVar11 + 0x42) != '\0') {
                fVar3 = fVar3 - *(float *)(iVar11 + 4);
                local_2c = local_2c - *(float *)(iVar11 + 8);
                local_28 = local_28 - *(float *)(iVar11 + 0xc);
              }
              fVar3 = *(float *)(iVar7 + 4) - fVar3;
              local_2c = *(float *)(iVar7 + 8) - local_2c;
              local_28 = *(float *)(iVar7 + 0xc) - local_28;
              if ((fVar3 * fVar3 + local_2c * local_2c + local_28 * local_28 < pfVar14[3]) &&
                 (pfVar14[4] < *(float *)(iVar7 + 0x10))) {
                *(float *)(iVar7 + 0x10) = pfVar14[4];
              }
              local_4c = local_4c + 1;
              iVar18 = iVar18 + 0x14;
            } while (local_4c < (int)param_2[1]);
          }
          puVar10 = (undefined4 *)(iVar7 + 0x24);
          for (iVar18 = 7; iVar18 != 0; iVar18 = iVar18 + -1) {
            *puVar10 = 0;
            puVar10 = puVar10 + 1;
          }
          local_44 = local_44 + 1;
          local_54 = local_54 + 0x40;
        } while (local_44 < piVar8[1]);
      }
      FUN_005890aa(piVar8[2],piVar8[1],0x40,&LAB_004de590);
      local_3c = *(int *)(*piVar8 + 0x120);
      if (0 < local_3c) {
        local_4c = 0;
        do {
          iVar18 = *(int *)(*piVar8 + 0x124) + local_4c;
          iVar7 = 0;
          do {
            iVar11 = FUN_004de5d0();
            local_24[iVar7] = iVar11;
            iVar7 = iVar7 + 1;
          } while (iVar7 < 3);
          if (*(float *)(local_24[1] + 8) <= *(float *)(local_24[0] + 8)) {
            fVar3 = *(float *)(local_24[1] + 8);
          }
          else {
            fVar3 = *(float *)(local_24[0] + 8);
          }
          if (*(float *)(local_24[2] + 8) <= fVar3) {
            fVar3 = *(float *)(local_24[2] + 8);
          }
          else if (*(float *)(local_24[1] + 8) <= *(float *)(local_24[0] + 8)) {
            fVar3 = *(float *)(local_24[1] + 8);
          }
          else {
            fVar3 = *(float *)(local_24[0] + 8);
          }
          if (*(float *)(local_24[0] + 8) <= *(float *)(local_24[1] + 8)) {
            fVar2 = *(float *)(local_24[1] + 8);
          }
          else {
            fVar2 = *(float *)(local_24[0] + 8);
          }
          if (fVar2 <= *(float *)(local_24[2] + 8)) {
            fVar2 = *(float *)(local_24[2] + 8);
          }
          else if (*(float *)(local_24[0] + 8) <= *(float *)(local_24[1] + 8)) {
            fVar2 = *(float *)(local_24[1] + 8);
          }
          else {
            fVar2 = *(float *)(local_24[0] + 8);
          }
          iVar11 = piVar8[1];
          iVar7 = 0;
          if (0 < iVar11) {
            iVar16 = iVar11;
            do {
              iVar15 = iVar16 + iVar7 >> 1;
              if (*(float *)(iVar15 * 0x40 + 0xc + piVar8[2]) < fVar3 - _DAT_005acd3c) {
                iVar7 = iVar15 + 1;
                iVar15 = iVar16;
              }
              iVar16 = iVar15;
            } while (iVar7 < iVar15);
          }
          if (iVar7 < iVar11) {
            local_40 = iVar7;
            do {
              iVar16 = iVar11 + local_40 >> 1;
              fVar3 = *(float *)(iVar16 * 0x40 + 0xc + piVar8[2]);
              if (fVar3 < fVar2 + _DAT_005acd3c != (fVar3 == fVar2 + _DAT_005acd3c)) {
                local_40 = iVar16 + 1;
                iVar16 = iVar11;
              }
              iVar11 = iVar16;
            } while (local_40 < iVar16);
            if (iVar7 < local_40) {
              local_54 = iVar7 << 6;
              local_40 = local_40 - iVar7;
LAB_004de992:
              iVar7 = piVar8[2] + local_54;
              if (ABS(*(float *)(iVar18 + 0x10) - *(float *)(iVar7 + 4)) <=
                  *(float *)(iVar18 + 0x1c) + _DAT_005acd3c) {
                iVar11 = 0;
                do {
                  pfVar14 = (float *)local_24[iVar11];
                  fVar3 = *pfVar14 - *(float *)(iVar7 + 4);
                  fVar4 = pfVar14[1] - *(float *)(iVar7 + 8);
                  fVar2 = pfVar14[2] - *(float *)(iVar7 + 0xc);
                  if (fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2 < _DAT_005ad13c) {
                    if ((iVar11 < 3) &&
                       (FUN_004dd9f0(local_24[2],&local_18),
                       fVar3 = local_18 * *(float *)(iVar7 + 4) +
                               local_14 * *(float *)(iVar7 + 8) + local_10 * *(float *)(iVar7 + 0xc)
                       , fVar3 < DAT_0059e440 == (fVar3 == DAT_0059e440))) {
                      iVar11 = 0;
                      piVar13 = (int *)(iVar7 + 0x24);
                      goto LAB_004dea55;
                    }
                    break;
                  }
                  iVar11 = iVar11 + 1;
                } while (iVar11 < 3);
              }
              goto LAB_004dead3;
            }
          }
LAB_004deaed:
          local_4c = local_4c + 0x24;
          local_3c = local_3c + -1;
        } while (local_3c != 0);
      }
      param_3 = param_3 + 1;
      local_48 = local_48 + 0xc;
    } while (param_3 < *(int *)(param_1 + 8));
  }
  iVar7 = param_2[3];
  *(int *)(param_1 + 0x10) = iVar7;
  piVar8 = operator_new(iVar7 * 0x18 + 4);
  if (piVar8 == (int *)0x0) {
    piVar13 = (int *)0x0;
  }
  else {
    *piVar8 = iVar7;
    piVar13 = piVar8 + 1;
    if (-1 < iVar7 + -1) {
      do {
        piVar8[5] = 0;
        piVar8[6] = 0;
        iVar7 = iVar7 + -1;
        piVar8 = piVar8 + 6;
      } while (iVar7 != 0);
    }
  }
  *(int **)(param_1 + 0x14) = piVar13;
  param_3 = 0;
  if (*(int *)(param_1 + 0x10) < 1) {
    *(undefined4 *)(param_1 + 0x18) = 0;
    return;
  }
  local_50 = 0;
  do {
    pfVar17 = (float *)(*(int *)(param_1 + 0x14) + local_50);
    pfVar14 = (float *)(param_2[4] + local_50);
    pfVar19 = pfVar17;
    for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar19 = *pfVar14;
      pfVar14 = pfVar14 + 1;
      pfVar19 = pfVar19 + 1;
    }
    pfVar17[4] = 0.0;
    iVar7 = *(int *)(param_1 + 4);
    if (*(char *)(iVar7 + 0x42) != '\0') {
      *pfVar17 = *pfVar17 - *(float *)(iVar7 + 4);
      pfVar17[1] = pfVar17[1] - *(float *)(iVar7 + 8);
      pfVar17[2] = pfVar17[2] - *(float *)(iVar7 + 0xc);
    }
    fVar3 = pfVar17[3];
    local_48 = 0;
    local_54 = 0;
    do {
      if (local_54 == 1) {
        pvVar9 = operator_new(local_48 * 4);
        pfVar17[5] = (float)pvVar9;
      }
      local_3c = 0;
      if (0 < *(int *)(param_1 + 8)) {
        local_4c = 0;
        do {
          iVar7 = *(int *)(param_1 + 0xc) + local_4c;
          iVar18 = 0;
          if (0 < *(int *)(*(int *)(param_1 + 0xc) + 4 + local_4c)) {
            iVar11 = 0;
            do {
              iVar16 = *(int *)(iVar7 + 8);
              fVar2 = *pfVar17 - *(float *)(iVar16 + 4 + iVar11);
              iVar16 = iVar16 + iVar11;
              fVar6 = pfVar17[1] - *(float *)(iVar16 + 8);
              fVar5 = pfVar17[2] - *(float *)(iVar16 + 0xc);
              fVar4 = SQRT(*(float *)(iVar16 + 0x10)) + SQRT(fVar3);
              if (fVar2 * fVar2 + fVar6 * fVar6 + fVar5 * fVar5 < fVar4 * fVar4) {
                if (local_54 == 0) {
                  local_48 = local_48 + 1;
                }
                else {
                  *(int *)((int)pfVar17[5] + (int)pfVar17[4] * 4) = iVar16;
                  pfVar17[4] = (float)((int)pfVar17[4] + 1);
                }
              }
              iVar18 = iVar18 + 1;
              iVar11 = iVar11 + 0x40;
            } while (iVar18 < *(int *)(iVar7 + 4));
          }
          local_3c = local_3c + 1;
          local_4c = local_4c + 0xc;
        } while (local_3c < *(int *)(param_1 + 8));
      }
      local_54 = local_54 + 1;
    } while (local_54 < 2);
    param_3 = param_3 + 1;
    local_50 = local_50 + 0x18;
  } while (param_3 < *(int *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
  while( true ) {
    pfVar14 = &local_c;
    uVar12 = FUN_004de5d0(pfVar14);
    FUN_004de5d0(uVar12);
    FUN_004de5d0();
    FUN_004dd9f0(uVar12,pfVar14);
    if (((local_c == local_18) && (local_8 == local_14)) && (local_4 == local_10)) break;
    iVar11 = iVar11 + 1;
    piVar13 = piVar13 + 1;
    if (6 < iVar11) break;
LAB_004dea55:
    if (*piVar13 == 0) {
      *(int *)(iVar7 + 0x24 + iVar11 * 4) = iVar18;
      break;
    }
  }
LAB_004dead3:
  local_54 = local_54 + 0x40;
  local_40 = local_40 + -1;
  if (local_40 == 0) goto LAB_004deaed;
  goto LAB_004de992;
}


