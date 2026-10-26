// Function: FUN_004ea970 @ 004ea970
// Size (bytes): 2751


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ea970(undefined4 *param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  float *pfVar11;
  float *local_198;
  float local_194;
  float local_190;
  float local_18c;
  float local_188;
  int local_184;
  float local_180;
  float *local_17c;
  float local_178;
  float local_174;
  float local_170;
  int local_16c;
  int local_168;
  float *local_164;
  float local_160;
  float local_15c;
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f0;
  float local_ec;
  float local_e4;
  float local_e0;
  float local_d8;
  float local_cc;
  float local_c8;
  float local_bc;
  double local_b8;
  double local_b0 [2];
  float local_a0;
  double local_9c;
  double local_94;
  double local_8c;
  float local_84;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  undefined1 local_48 [8];
  int local_40;
  int local_38;
  float local_24;
  int local_20;
  int local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  local_17c = (float *)(param_1 + 0xd64);
  pfVar11 = (float *)(param_1 + 0xeaf);
  local_16c = 0;
  do {
    iVar10 = local_16c;
    local_164 = pfVar11;
    iVar8 = FUN_0054fa90(local_16c,local_48);
    if (iVar8 != 0) {
      if ((((iVar10 < 10) || (0xb < iVar10)) || (*(char *)(param_1 + 0xedd) == '\0')) ||
         ((param_1[0x343] != 0 && (*(char *)(param_1 + 0x353) != '\0')))) {
        piVar9 = (int *)FUN_004ea010();
        *piVar9 = iVar10;
        local_bc = local_10;
        pfVar1 = (float *)(piVar9 + 5);
        *pfVar1 = pfVar11[-1] * (float)param_1[0xd2c] +
                  (float)param_1[0xd2d] * *pfVar11 + (float)param_1[0xd2e] * pfVar11[1];
        piVar9[6] = (int)((float)param_1[0xd2f] * pfVar11[-1] +
                         (float)param_1[0xd30] * *pfVar11 + (float)param_1[0xd31] * pfVar11[1]);
        piVar9[7] = (int)((float)param_1[0xd32] * pfVar11[-1] +
                         (float)param_1[0xd33] * *pfVar11 + (float)param_1[0xd34] * pfVar11[1]);
        *pfVar1 = (float)param_1[0xd35] + *pfVar1;
        piVar9[6] = (int)((float)param_1[0xd36] + (float)piVar9[6]);
        piVar9[7] = (int)((float)param_1[0xd37] + (float)piVar9[7]);
        local_15c = local_18 - *pfVar1;
        local_158 = local_14 - (float)piVar9[6];
        local_154 = local_10 - (float)piVar9[7];
        local_84 = local_18 + *pfVar1;
        local_138 = local_84 * _DAT_0059e450;
        local_134 = (local_14 + (float)piVar9[6]) * _DAT_0059e450;
        local_130 = (local_10 + (float)piVar9[7]) * _DAT_0059e450;
        *pfVar1 = local_138;
        piVar9[6] = (int)local_134;
        piVar9[7] = (int)local_130;
        pfVar11 = (float *)(piVar9 + 0xb);
        iVar10 = 0;
        *pfVar11 = local_24;
        local_160 = 0.25;
        piVar9[0xc] = local_20;
        piVar9[0xd] = local_1c;
        piVar9[2] = (int)(local_15c * *pfVar11 +
                         local_158 * (float)piVar9[0xc] + local_154 * (float)piVar9[0xd]);
        local_168 = DAT_005c329c;
        if (0 < DAT_005c329c) {
LAB_004eab74:
          if (local_40 != *(int *)((&DAT_007c54f0)[iVar10] + 0x6f4)) break;
          if ((-1 < local_16c) && (local_16c < 4)) {
            iVar8 = (&DAT_007c54f0)[iVar10];
            local_198 = (float *)(iVar8 + 0x359c);
            local_184 = 4;
            local_144 = (float)param_1[0xd2c] * local_17c[-1] +
                        (float)param_1[0xd2d] * *local_17c + (float)param_1[0xd2e] * local_17c[1] +
                        (float)param_1[0xd35];
            fVar7 = (float)param_1[0xd2f] * local_17c[-1] +
                    (float)param_1[0xd30] * *local_17c + (float)param_1[0xd31] * local_17c[1] +
                    (float)param_1[0xd36];
            local_13c = (float)param_1[0xd32] * local_17c[-1] +
                        (float)param_1[0xd33] * *local_17c + (float)param_1[0xd34] * local_17c[1] +
                        (float)param_1[0xd37];
            do {
              local_148 = *(float *)(iVar8 + 0x34d4) * local_198[-1] +
                          *(float *)(iVar8 + 0x34d8) * *local_198 +
                          *(float *)(iVar8 + 0x34dc) * local_198[1];
              local_150 = *(float *)(iVar8 + 0x34c4) * local_198[1] +
                          *(float *)(iVar8 + 0x34bc) * local_198[-1] +
                          *(float *)(iVar8 + 0x34c0) * *local_198 + *(float *)(iVar8 + 0x34e0);
              local_14c = *(float *)(iVar8 + 0x34d0) * local_198[1] +
                          *(float *)(iVar8 + 0x34c8) * local_198[-1] +
                          *(float *)(iVar8 + 0x34cc) * *local_198 + *(float *)(iVar8 + 0x34e4);
              fVar4 = local_148 + *(float *)(iVar8 + 0x34e8);
              fVar2 = fVar7 - local_14c;
              fVar3 = local_13c - fVar4;
              if ((local_144 - local_150) * (local_144 - local_150) + fVar2 * fVar2 + fVar3 * fVar3
                  < (local_198[0x20] + local_17c[0x20]) * (local_198[0x20] + local_17c[0x20])) {
                local_160 = 0.35;
                local_a0 = fVar4 + local_13c;
                local_12c = (local_150 + local_144) * _DAT_0059e450;
                *pfVar1 = local_12c;
                local_128 = (local_14c + fVar7) * _DAT_0059e450;
                piVar9[6] = (int)local_128;
                local_124 = local_a0 * _DAT_0059e450;
                piVar9[7] = (int)local_124;
              }
              local_198 = local_198 + 0x3e;
              local_184 = local_184 + -1;
            } while (local_184 != 0);
            local_184 = 0;
          }
          local_168 = iVar10;
          if (DAT_005c329c <= iVar10) goto LAB_004eab98;
          iVar8 = (&DAT_007c54f0)[iVar10];
          local_178 = (float)param_1[0xd35] - *(float *)(iVar8 + 0x34e0);
          local_174 = (float)param_1[0xd36] - *(float *)(iVar8 + 0x34e4);
          local_170 = (float)param_1[0xd37] - *(float *)(iVar8 + 0x34e8);
          fVar7 = SQRT(local_178 * local_178 + local_174 * local_174 + local_170 * local_170);
          if (DAT_0059e440 < fVar7) {
            fVar7 = _DAT_0059e940 / fVar7;
            local_f0 = fVar7 * local_174;
            local_ec = fVar7 * local_170;
            *pfVar11 = local_178 * fVar7 + *pfVar11;
            piVar9[0xc] = (int)(local_f0 + (float)piVar9[0xc]);
            piVar9[0xd] = (int)(local_ec + (float)piVar9[0xd]);
            fVar7 = SQRT((float)piVar9[0xd] * (float)piVar9[0xd] +
                         (float)piVar9[0xc] * (float)piVar9[0xc] + *pfVar11 * *pfVar11);
            if (fVar7 <= DAT_0059e440) {
              *pfVar11 = local_178;
              piVar9[0xc] = (int)local_174;
              piVar9[0xd] = (int)local_170;
            }
            else {
              fVar7 = _DAT_0059e43c / fVar7;
              *pfVar11 = fVar7 * *pfVar11;
              piVar9[0xc] = (int)(fVar7 * (float)piVar9[0xc]);
              piVar9[0xd] = (int)(fVar7 * (float)piVar9[0xd]);
            }
          }
          piVar9[3] = 6;
          piVar9[2] = (int)(local_15c * *pfVar11 +
                           local_158 * (float)piVar9[0xc] + local_154 * (float)piVar9[0xd]);
          iVar10 = DAT_005ea570 + *(int *)((&DAT_007c54f0)[iVar10] + 0x10) * 0x24;
          goto LAB_004eaf4f;
        }
LAB_004eab98:
        iVar10 = FUN_00410b80(local_40);
        if (iVar10 == 0) {
          piVar9[3] = 9;
          local_184 = 0;
          iVar10 = local_184;
          if (local_38 != 0) {
            FUN_00547390(&local_184,0x1000);
            iVar10 = local_184;
          }
LAB_004eaf4f:
          piVar9[4] = iVar10;
        }
        else {
          piVar9[3] = 2;
          piVar9[4] = iVar10;
        }
        FUN_004ed420(pfVar1,pfVar11,&local_188,&local_180,&local_194);
        if (piVar9[3] == 6) {
          FUN_004ed420(pfVar1,pfVar11,&local_110,&local_120,&local_100);
          local_188 = local_188 - local_110;
          local_180 = local_120 + local_180;
          local_194 = local_194 - local_100;
          local_190 = local_190 - local_fc;
          local_18c = local_18c - local_f8;
        }
        else if (piVar9[3] == 2) {
          local_9c = (double)*pfVar1;
          local_94 = (double)(float)piVar9[6];
          local_8c = (double)(float)piVar9[7];
          local_60 = (double)*pfVar11;
          local_58 = (double)(float)piVar9[0xc];
          local_50 = (double)(float)piVar9[0xd];
          FUN_005694e0(&local_9c,&local_60,local_b0,&local_b8,&local_78);
          local_188 = local_188 - (float)local_b0[0];
          local_180 = (float)local_b8 + local_180;
          local_18c = local_18c - (float)local_68;
          local_194 = local_194 - (float)local_78;
          local_190 = local_190 - (float)local_70;
        }
        if (local_188 < DAT_0059e440) {
          fVar7 = _DAT_0059e670 / local_188;
        }
        else {
          local_188 = 0.0;
          fVar7 = DAT_0059e440;
        }
        fVar2 = -(local_188 / local_180);
        fVar3 = SQRT(local_18c * local_18c + local_190 * local_190 + local_194 * local_194);
        fVar4 = fVar3;
        if (_DAT_0059e4dc < fVar3) {
          fVar4 = _DAT_0059e4dc;
        }
        fVar5 = _DAT_0059e43c;
        if (fVar4 * fVar7 <= _DAT_0059e43c) {
          fVar4 = fVar3;
          if (_DAT_0059e4dc < fVar3) {
            fVar4 = _DAT_0059e4dc;
          }
          fVar5 = fVar4 * fVar7;
        }
        if (fVar5 < fVar3) {
          fVar5 = fVar5 / fVar3;
          local_194 = local_194 * fVar5;
          local_190 = local_190 * fVar5;
          local_18c = fVar5 * local_18c;
        }
        if (((piVar9[3] == 6) ||
            (((piVar9[3] == 9 && (piVar9[4] != 0)) && (*(char *)(piVar9[4] + 0x2c) != '\0')))) &&
           (fVar7 = (fVar2 * _DAT_0059e77c + fVar3 * _DAT_0059e774) - _DAT_0059e84c,
           DAT_0059e440 < fVar7)) {
          if (_DAT_0059e43c < fVar7) {
            fVar7 = _DAT_0059e43c;
          }
          if ((float)param_1[0x29] < fVar7) {
            fVar4 = *pfVar1 - (float)param_1[0xd35];
            fVar6 = (float)piVar9[6] - (float)param_1[0xd36];
            fVar5 = (float)piVar9[7] - (float)param_1[0xd37];
            local_11c = fVar4 * (float)param_1[0xd2c] +
                        fVar6 * (float)param_1[0xd2f] + fVar5 * (float)param_1[0xd32];
            local_118 = fVar4 * (float)param_1[0xd2d] +
                        fVar6 * (float)param_1[0xd30] + fVar5 * (float)param_1[0xd33];
            param_1[0x2b] = local_11c;
            param_1[0x2c] = local_118;
            local_114 = fVar4 * (float)param_1[0xd2e] +
                        fVar6 * (float)param_1[0xd31] + fVar5 * (float)param_1[0xd34];
            param_1[0x2d] = local_114;
            param_1[0x29] = fVar7;
            param_1[0x2a] = fVar3 * _DAT_005ac988 + _DAT_005ad1dc;
          }
        }
        fVar7 = fVar2 * local_160;
        local_cc = fVar7 * local_190;
        local_c8 = fVar7 * local_18c;
        local_e4 = fVar2 * (float)piVar9[0xc];
        local_e0 = fVar2 * (float)piVar9[0xd];
        fVar7 = fVar2 * *pfVar11 - local_194 * fVar7;
        local_d8 = local_e4 - local_cc;
        fVar3 = local_e0 - local_c8;
        fVar2 = SQRT(fVar7 * fVar7 + local_d8 * local_d8 + fVar3 * fVar3);
        piVar9[1] = (int)fVar2;
        if (fVar2 <= DAT_0059e440) {
          piVar9[8] = 0;
          piVar9[9] = 0;
          piVar9[10] = 0;
        }
        else {
          fVar2 = _DAT_0059e43c / fVar2;
          local_10c = fVar2 * fVar7;
          piVar9[8] = (int)local_10c;
          local_108 = local_d8 * fVar2;
          piVar9[9] = (int)local_108;
          local_104 = fVar2 * fVar3;
          piVar9[10] = (int)local_104;
        }
        if (local_168 < DAT_005c329c) {
          FUN_0041ad80(*param_1,(&DAT_007c54f0)[local_168],piVar9[1]);
        }
        FUN_0054fae0(local_16c);
        pfVar11 = local_164;
        iVar10 = local_16c;
      }
      else {
        FUN_0054fae0(iVar10);
      }
    }
    local_16c = iVar10 + 1;
    pfVar11 = pfVar11 + 3;
    local_17c = local_17c + 0x3e;
    if (0xc < local_16c) {
      return;
    }
  } while( true );
  iVar10 = iVar10 + 1;
  if (DAT_005c329c <= iVar10) goto LAB_004eab98;
  goto LAB_004eab74;
}


