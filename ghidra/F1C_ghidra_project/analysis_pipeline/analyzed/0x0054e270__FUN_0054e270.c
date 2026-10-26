// Function: FUN_0054e270 @ 0054e270
// Size (bytes): 1845


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0054e270(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  float *pfVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  float local_188;
  float local_184;
  float local_180;
  double local_178;
  double local_170;
  double local_168;
  double local_160;
  double local_158;
  double local_150;
  double local_148;
  double local_140;
  double local_138;
  float local_130 [5];
  float local_11c;
  float local_118;
  undefined4 local_114;
  float local_110;
  float local_10c;
  float local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  double local_f0;
  double local_e8;
  double local_e0;
  double local_d8;
  double local_d0;
  double local_c8;
  double local_c0;
  double local_b8;
  double local_b0;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  undefined1 local_60 [24];
  float local_48 [17];
  
  iVar9 = *(int *)(param_1 + 0x118);
  iVar12 = 0;
  local_170 = 0.0;
  local_168 = 0.0;
  local_150 = 0.0;
  dVar5 = _DAT_0059e430;
  dVar6 = _DAT_0059e430;
  dVar7 = _DAT_0059e430;
  local_158 = _DAT_0059e430;
  local_160 = _DAT_0059e430;
  local_178 = _DAT_0059e430;
  if (0 < iVar9) {
    piVar14 = (int *)(*(int *)(param_1 + 0x11c) + 8);
    do {
      iVar17 = *piVar14;
      if (0 < iVar17) {
        pfVar10 = (float *)piVar14[1];
        pfVar13 = pfVar10;
        do {
          pfVar11 = pfVar13;
          if ((*(uint *)(param_1 + 0x14) & 0x800000) == 0) {
            pfVar11 = pfVar10;
          }
          pfVar13 = pfVar13 + 0x10;
          pfVar10 = pfVar10 + 0xc;
          iVar17 = iVar17 + -1;
          dVar7 = (double)*pfVar11 * (double)*pfVar11 + dVar7;
          dVar6 = (double)pfVar11[1] * (double)pfVar11[1] + dVar6;
          dVar5 = (double)pfVar11[2] * (double)pfVar11[2] + dVar5;
          local_150 = (double)(pfVar11[1] * *pfVar11 + (float)local_150);
          local_168 = (double)(*pfVar11 * pfVar11[2] + (float)local_168);
          local_170 = (double)(pfVar11[1] * pfVar11[2] + (float)local_170);
          local_178 = local_178 + (double)*pfVar11;
          local_160 = (double)pfVar11[1] + local_160;
          local_158 = (double)pfVar11[2] + local_158;
        } while (iVar17 != 0);
      }
      iVar12 = iVar12 + *piVar14;
      piVar14 = piVar14 + 0x10;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  dVar8 = _DAT_0059e420 / (double)iVar12;
  local_178 = dVar8 * local_178;
  local_160 = dVar8 * local_160;
  local_158 = dVar8 * local_158;
  local_e8 = dVar8 * local_150 - local_160 * local_178;
  local_168 = dVar8 * local_168 - local_158 * local_178;
  local_170 = dVar8 * local_170 - local_158 * local_160;
  local_f0 = dVar8 * dVar7 - local_178 * local_178;
  local_d0 = dVar8 * dVar6 - local_160 * local_160;
  local_b0 = dVar8 * dVar5 - local_158 * local_158;
  local_e0 = local_168;
  local_d8 = local_e8;
  local_c0 = local_168;
  local_b8 = local_170;
  local_c8 = local_170;
  FUN_0053b6f0(&local_f0,local_60,&local_a8);
  local_130[0] = (float)local_a8;
  local_130[3] = 0.0;
  local_114 = 0;
  local_130[1] = (float)local_90;
  local_104 = 0;
  local_100 = 0;
  local_130[2] = (float)local_78;
  local_fc = 0;
  local_f8 = 0;
  local_130[4] = (float)local_a0;
  local_f4 = 0x3f800000;
  pfVar13 = local_48;
  local_11c = (float)local_88;
  pfVar10 = local_130;
  iVar9 = 4;
  local_118 = (float)local_70;
  local_110 = (float)local_98;
  local_10c = (float)local_80;
  local_108 = (float)local_68;
  do {
    iVar12 = 4;
    pfVar11 = pfVar13;
    do {
      *pfVar11 = *pfVar10;
      pfVar11 = pfVar11 + 4;
      pfVar10 = pfVar10 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    pfVar13 = pfVar13 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  iVar12 = 0;
  local_170 = 999999995904.0;
  local_160 = 999999995904.0;
  local_148 = 999999995904.0;
  local_168 = -999999995904.0;
  local_138 = -999999995904.0;
  local_158 = -999999995904.0;
  local_140 = 0.0;
  iVar9 = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    do {
      iVar17 = *(int *)(param_1 + 0x11c);
      iVar16 = 0;
      iVar15 = 0;
      if (0 < *(int *)(iVar17 + 8 + iVar12)) {
        local_178 = (double)((ulonglong)local_178 & 0xffffffff00000000);
        do {
          iVar1 = iVar16;
          if ((*(uint *)(param_1 + 0x14) & 0x800000) == 0) {
            iVar1 = (int)local_178._0_4_;
          }
          (**(code **)(*DAT_008b8f24 + 4))
                    (DAT_008b8f24,*(int *)(iVar17 + 0xc + iVar12) + iVar1,&local_188,local_48);
          if (local_188 < (float)local_148) {
            local_148 = (double)local_188;
          }
          if ((float)local_158 < local_188) {
            local_158 = (double)local_188;
          }
          if (local_184 < (float)local_160) {
            local_160 = (double)local_184;
          }
          if ((float)local_138 < local_184) {
            local_138 = (double)local_184;
          }
          if (local_180 < (float)local_170) {
            local_170 = (double)local_180;
          }
          if ((float)local_168 < local_180) {
            local_168 = (double)local_180;
          }
          iVar17 = *(int *)(param_1 + 0x11c);
          iVar15 = iVar15 + 1;
          iVar16 = iVar16 + 0x40;
          local_178 = (double)CONCAT44(local_178._4_4_,(int)local_178._0_4_ + 0x30);
        } while (iVar15 < *(int *)(iVar17 + 8 + iVar12));
      }
      iVar9 = iVar9 + 1;
      iVar12 = iVar12 + 0x40;
    } while (iVar9 < *(int *)(param_1 + 0x118));
  }
  local_188 = (float)local_158;
  local_150 = (double)CONCAT44(local_150._4_4_,local_188);
  local_184 = (float)local_160;
  fVar2 = (float)local_170;
  local_180 = fVar2;
  local_178._0_4_ = local_184;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&local_188,param_1 + 0x1c,local_130);
  local_180 = (float)local_168;
  local_168 = (double)CONCAT44(local_168._4_4_,local_180);
  local_184 = local_178._0_4_;
  local_188 = local_150._0_4_;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&local_188,param_1 + 0x28,local_130);
  local_188 = (float)local_148;
  local_170 = (double)CONCAT44(local_170._4_4_,local_188);
  local_184 = local_178._0_4_;
  local_180 = (float)local_168._0_4_;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&local_188,param_1 + 0x34,local_130);
  local_188 = local_170._0_4_;
  local_184 = local_178._0_4_;
  local_180 = fVar2;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&local_188,param_1 + 0x40,local_130);
  local_184 = (float)local_138;
  local_178 = (double)CONCAT44(local_178._4_4_,local_184);
  local_188 = local_150._0_4_;
  local_180 = fVar2;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&local_188,param_1 + 0x4c,local_130);
  local_180 = (float)local_168._0_4_;
  local_184 = local_178._0_4_;
  local_188 = local_150._0_4_;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&local_188,param_1 + 0x58,local_130);
  local_180 = (float)local_168._0_4_;
  local_184 = local_178._0_4_;
  local_188 = local_170._0_4_;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&local_188,param_1 + 100,local_130);
  local_184 = local_178._0_4_;
  local_188 = local_170._0_4_;
  local_180 = fVar2;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&local_188,param_1 + 0x70,local_130);
  iVar9 = *(int *)(param_1 + 0x118);
  if (0 < iVar9) {
    piVar14 = (int *)(*(int *)(param_1 + 0x11c) + 8);
    do {
      iVar12 = *piVar14;
      if (0 < iVar12) {
        pfVar10 = (float *)piVar14[1];
        pfVar13 = pfVar10;
        do {
          pfVar11 = pfVar10;
          if ((*(uint *)(param_1 + 0x14) & 0x800000) == 0) {
            pfVar11 = pfVar13;
          }
          fVar2 = *(float *)(param_1 + 0xdc) - *pfVar11;
          fVar4 = *(float *)(param_1 + 0xe0) - pfVar11[1];
          fVar3 = *(float *)(param_1 + 0xe4) - pfVar11[2];
          fVar2 = fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3;
          if ((float)local_140 <= fVar2) {
            local_140 = (double)fVar2;
          }
          pfVar10 = pfVar10 + 0x10;
          pfVar13 = pfVar13 + 0xc;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
      piVar14 = piVar14 + 0x10;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  *(float *)(param_1 + 0x18) = SQRT((float)local_140);
  return;
}


