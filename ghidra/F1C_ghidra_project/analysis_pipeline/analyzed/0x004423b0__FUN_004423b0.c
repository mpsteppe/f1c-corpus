// Function: FUN_004423b0 @ 004423b0
// Size (bytes): 2261


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004423b0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  double dVar8;
  double dVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  double *pdVar14;
  double *pdVar15;
  undefined4 *puVar16;
  float10 fVar17;
  float10 fVar18;
  int local_19c;
  float local_198;
  double local_194;
  double local_18c;
  double local_184;
  double *local_17c;
  double local_178;
  double *local_16c;
  undefined8 local_168;
  double local_160;
  double local_158;
  double local_150;
  double local_148;
  float local_140;
  float local_13c;
  float local_138;
  double local_134;
  double local_12c;
  double local_124;
  double local_11c;
  double local_114;
  double local_10c;
  double local_104;
  double local_fc;
  double local_f4;
  double local_ec;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  double local_d4;
  int local_cc;
  double local_c8;
  double local_c0;
  double local_b8;
  double local_b0;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  double local_80;
  double local_78;
  double local_70;
  undefined4 local_68 [4];
  double local_58;
  undefined4 local_50 [4];
  double local_40;
  double local_38;
  double local_28;
  double local_10;
  
  if (_DAT_008afeec == _DAT_008afee8) {
    iVar11 = 4;
    pdVar15 = (double *)(param_1 + 0x4fc);
    do {
      iVar11 = iVar11 + -1;
      *pdVar15 = (double)_DAT_008afee8;
      pdVar15 = (double *)((int)pdVar15 + 0x464);
    } while (iVar11 != 0);
  }
  else {
    pfVar10 = (float *)FUN_004e9630();
    fVar1 = pfVar10[10];
    pdVar15 = (double *)(param_1 + 0x4fc);
    fVar2 = pfVar10[2];
    iVar11 = 4;
    fVar3 = pfVar10[9];
    fVar4 = pfVar10[1];
    fVar5 = pfVar10[8];
    fVar6 = *pfVar10;
    fVar7 = pfVar10[7];
    do {
      iVar12 = *(int *)((int)pdVar15 + -0x114);
      fVar17 = (float10)FUN_004fd7e0(ABS(((float)*(double *)(iVar12 + 0xc) * pfVar10[9] +
                                         (float)*(double *)(iVar12 + 4) * pfVar10[8] +
                                         (float)*(double *)(iVar12 + 0x14) * pfVar10[10]) -
                                         (fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2 + fVar7)));
      *pdVar15 = (double)fVar17;
      pdVar15 = (double *)((int)pdVar15 + 0x464);
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  if ((*(int *)(*(int *)(param_1 + 0x1f00) + 0xcd4) != 0) &&
     (*(char *)(*(int *)(param_1 + 0x1f00) + 0xd14) != '\0')) {
    FUN_00435e00(param_1 + 0x1948,(double *)(param_1 + 0x1918));
    iVar11 = *(int *)(param_1 + 0x15f0);
    local_194 = *(double *)(param_1 + 0x1918) + *(double *)(iVar11 + 4);
    local_cc = *(int *)(param_1 + 0x1904);
    local_18c = *(double *)(param_1 + 0x1920) + *(double *)(iVar11 + 0xc);
    local_184 = *(double *)(param_1 + 0x1928) + *(double *)(iVar11 + 0x14);
    local_e4 = 0x66666666;
    local_e0 = 0x3fd66666;
    local_dc = 0x40000000;
    local_d8 = 0x479e17b8;
    local_f4 = local_18c + _DAT_0059ec60;
    local_fc = local_194;
    local_ec = local_184;
    iVar11 = FUN_0044c4c0(&local_fc);
    *(int *)(param_1 + 0x1904) = iVar11;
    if (iVar11 == 0) {
      *(undefined4 *)(param_1 + 0x1908) = *(undefined4 *)(param_1 + 0x1910);
      *(undefined4 *)(param_1 + 0x190c) = *(undefined4 *)(param_1 + 0x1914);
    }
    else {
      *(double *)(param_1 + 0x1908) = local_18c - local_d4;
    }
  }
  iVar11 = 4;
  do {
    FUN_00436870(*(undefined4 *)(param_1 + 0x60),*(undefined4 *)(param_1 + 100));
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  local_16c = (double *)(param_1 + 0x1660);
  pdVar15 = (double *)(param_1 + 0x16f0);
  piVar13 = (int *)(param_1 + 0x16e0);
  local_19c = 4;
  do {
    local_17c = pdVar15;
    FUN_0043aee0(*(int *)(param_1 + 0x15f0) + 4,local_16c,&local_194);
    local_cc = *piVar13;
    local_fc = local_194;
    local_f4 = local_18c + _DAT_0059ec60;
    local_e4 = 0x66666666;
    local_e0 = 0x3fd66666;
    local_ec = local_184;
    local_dc = 0x40000000;
    local_d8 = 0x479e17b8;
    iVar11 = FUN_0044c4c0(&local_fc);
    *piVar13 = iVar11;
    if (iVar11 != 0) {
      iVar11 = *(int *)(iVar11 + 0x54);
      fVar17 = (float10)fsin((float10)*(float *)(iVar11 + 0x18) * (float10)local_194);
      fVar18 = (float10)fsin((float10)*(float *)(iVar11 + 0x18) * (float10)local_184);
      fVar17 = (float10)local_18c -
               ((fVar18 + fVar17) * (float10)*(float *)(iVar11 + 0x14) + (float10)local_d4);
      *pdVar15 = (double)fVar17;
      if (DAT_007ce958 != 0) {
        *pdVar15 = (double)(fVar17 + (float10)_DAT_0059eb20);
      }
      if (*pdVar15 < _DAT_0059e430) {
        iVar12 = *(int *)(param_1 + 0x15f0);
        *(undefined1 *)(param_1 + 0x1718) = 1;
        local_114 = local_194 - *(double *)(iVar12 + 4);
        pdVar14 = (double *)*piVar13;
        local_10c = local_18c - *(double *)(iVar12 + 0xc);
        local_104 = local_184 - *(double *)(iVar12 + 0x14);
        dVar8 = local_194 * *pdVar14 + local_194 * *pdVar14 + local_184 * pdVar14[2] + pdVar14[3];
        dVar9 = local_194 * pdVar14[2] + local_184 * pdVar14[1] + local_184 * pdVar14[1] +
                pdVar14[4];
        local_160 = _DAT_0059e420 / SQRT(dVar8 * dVar8 + dVar9 * dVar9 + _DAT_0059e420);
        local_80 = -(local_160 * dVar8);
        dVar8 = -(local_160 * dVar9);
        local_158 = (local_104 * *(double *)(iVar12 + 0x84) - local_10c * *(double *)(iVar12 + 0x8c)
                    ) + *(double *)(iVar12 + 100);
        dVar9 = (local_114 * *(double *)(iVar12 + 0x8c) - local_104 * *(double *)(iVar12 + 0x7c)) +
                *(double *)(iVar12 + 0x6c);
        local_148 = (local_10c * *(double *)(iVar12 + 0x7c) - local_114 * *(double *)(iVar12 + 0x84)
                    ) + *(double *)(iVar12 + 0x74);
        local_178 = dVar8 * local_148 + local_158 * local_80 + local_160 * dVar9;
        local_168 = *pdVar15 * _DAT_0059eda8 - local_178 * _DAT_0059eda0;
        if (_DAT_0059e430 < local_168) {
          local_10 = dVar8 * local_178;
          local_12c = local_158 - local_80 * local_178;
          local_124 = dVar9 - local_160 * local_178;
          local_11c = local_148 - dVar8 * local_178;
          pdVar15 = &local_12c;
          pdVar14 = &local_c8;
          for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {
            *(undefined4 *)pdVar14 = *(undefined4 *)pdVar15;
            pdVar15 = (double *)((int)pdVar15 + 4);
            pdVar14 = (double *)((int)pdVar14 + 4);
          }
          local_178 = SQRT(local_124 * local_124 + local_11c * local_11c + local_12c * local_12c);
          if (_DAT_0059e420 < local_178) {
            dVar9 = _DAT_0059e420 / local_178;
            local_c8 = local_12c * dVar9;
            local_c0 = local_c0 * dVar9;
            local_b8 = local_b8 * dVar9;
          }
          local_58 = local_b8 + local_b8;
          local_134 = (double)*(float *)(iVar11 + 0x24);
          local_38 = (local_c8 + local_c8) * local_134;
          local_98 = local_80 - local_38;
          local_90 = local_160 - (local_c0 + local_c0) * local_134;
          local_b0 = local_98 * local_168;
          local_a8 = local_90 * local_168;
          local_a0 = (dVar8 - (local_b8 + local_b8) * local_134) * local_168;
          pdVar15 = &local_b0;
          puVar16 = local_50;
          for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {
            *puVar16 = *(undefined4 *)pdVar15;
            pdVar15 = (double *)((int)pdVar15 + 4);
            puVar16 = puVar16 + 1;
          }
          FUN_00569ad0(&local_114,local_50);
          pdVar15 = local_17c;
          if ((*(double *)(param_1 + 0x171c) < local_168) && (*(char *)(iVar11 + 0x2c) != '\0')) {
            fVar17 = (float10)_DAT_0059ed98;
            *(undefined4 *)(param_1 + 0x1720) = local_168._4_4_;
            fVar18 = (float10)_DAT_0059ed90;
            *(undefined4 *)(param_1 + 0x171c) = (undefined4)local_168;
            fVar17 = (float10)local_168 * fVar18 * (float10)local_178 * fVar17;
            local_198 = (float)fVar17;
            if ((float10)_DAT_0059e43c < fVar17) {
              local_198 = 1.0;
            }
            fVar17 = (float10)local_178 * (float10)_DAT_0059eb20 + (float10)_DAT_0059e880;
            if ((float10)_DAT_0059e800 < fVar17) {
              fVar17 = (float10)_DAT_0059e800;
            }
            iVar11 = *(int *)(param_1 + 0x1f00);
            if (*(float *)(iVar11 + 0xb0) < local_198) {
              local_140 = (float)*local_16c;
              local_13c = (float)local_16c[1];
              local_138 = (float)local_16c[2];
              *(float *)(iVar11 + 0xb0) = local_198;
              *(float *)(iVar11 + 0xb4) = (float)fVar17;
              *(float *)(iVar11 + 0xb8) = local_140;
              *(float *)(iVar11 + 0xbc) = local_13c;
              *(float *)(iVar11 + 0xc0) = local_138;
            }
          }
        }
      }
    }
    pdVar15 = pdVar15 + 1;
    local_16c = local_16c + 3;
    piVar13 = piVar13 + 1;
    local_19c = local_19c + -1;
  } while (local_19c != 0);
  if (*(char *)(param_1 + 0x1724) != '\0') {
    pdVar14 = (double *)(param_1 + 0x1668);
    local_19c = 4;
    local_17c = pdVar15;
    do {
      iVar11 = *(int *)(param_1 + 0x15f0);
      local_194 = *(double *)(iVar11 + 0x1c) * pdVar14[-1] +
                  *(double *)(iVar11 + 0x24) * *pdVar14 + *(double *)(iVar11 + 0x2c) * pdVar14[1];
      local_18c = *(double *)(iVar11 + 0x3c) * *pdVar14 +
                  *(double *)(iVar11 + 0x34) * pdVar14[-1] + *(double *)(iVar11 + 0x44) * pdVar14[1]
      ;
      local_184 = *(double *)(iVar11 + 0x54) * *pdVar14 +
                  *(double *)(iVar11 + 0x4c) * pdVar14[-1] + *(double *)(iVar11 + 0x5c) * pdVar14[1]
      ;
      local_a0 = local_18c * *(double *)(iVar11 + 0x7c) - local_194 * *(double *)(iVar11 + 0x84);
      local_b0 = (local_184 * *(double *)(iVar11 + 0x84) - local_18c * *(double *)(iVar11 + 0x8c)) +
                 *(double *)(iVar11 + 100);
      local_40 = local_184 + *(double *)(iVar11 + 0x14);
      local_158 = pdVar14[0x1c] - (local_194 + *(double *)(iVar11 + 4));
      local_150 = pdVar14[0x1d] - (local_18c + *(double *)(iVar11 + 0xc));
      local_148 = pdVar14[0x1e] - local_40;
      local_98 = local_b0 * _DAT_0059ed88;
      local_90 = ((local_194 * *(double *)(iVar11 + 0x8c) - local_184 * *(double *)(iVar11 + 0x7c))
                 + *(double *)(iVar11 + 0x6c)) * _DAT_0059ed88;
      local_28 = local_148 * _DAT_0059ed80;
      local_80 = local_158 * _DAT_0059ed80 - local_98;
      local_78 = local_150 * _DAT_0059ed80 - local_90;
      local_70 = local_148 * _DAT_0059ed80 - (local_a0 + *(double *)(iVar11 + 0x74)) * _DAT_0059ed88
      ;
      pdVar15 = &local_80;
      puVar16 = local_68;
      for (iVar11 = 6; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar16 = *(undefined4 *)pdVar15;
        pdVar15 = (double *)((int)pdVar15 + 4);
        puVar16 = puVar16 + 1;
      }
      FUN_00569ad0(&local_194,local_68);
      pdVar14 = pdVar14 + 3;
      local_19c = local_19c + -1;
    } while (local_19c != 0);
  }
  return;
}


