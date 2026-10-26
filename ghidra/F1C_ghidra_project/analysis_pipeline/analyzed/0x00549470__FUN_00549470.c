// Function: FUN_00549470 @ 00549470
// Size (bytes): 2870


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00549470(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  float *pfVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  int iVar20;
  int local_1f0;
  int local_1ec;
  float fStack_1e8;
  float fStack_1e4;
  float fStack_1e0;
  double local_1d8;
  double local_1d0;
  double local_1c8;
  double local_1c0;
  double local_1b8;
  double local_1b0;
  double local_1a8;
  double local_1a0;
  double local_190;
  float afStack_188 [5];
  float fStack_174;
  float fStack_170;
  undefined4 uStack_16c;
  float fStack_168;
  float fStack_164;
  float fStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  float local_148 [4];
  undefined4 uStack_138;
  int aiStack_134 [17];
  double dStack_f0;
  double dStack_e8;
  double dStack_e0;
  double dStack_d8;
  double dStack_d0;
  double dStack_c8;
  double dStack_c0;
  double dStack_b8;
  double dStack_b0;
  double local_a8;
  double dStack_a0;
  double dStack_98;
  double dStack_90;
  double dStack_88;
  double dStack_80;
  double dStack_78;
  double dStack_70;
  double dStack_68;
  undefined1 auStack_60 [24];
  float afStack_48 [17];
  
  iVar17 = *(int *)(param_1 + 0xec);
  local_1ec = 0;
  local_1a0 = 0.0;
  local_1d0 = 0.0;
  local_190 = 0.0;
  local_1c8 = 0.0;
  local_1b0 = 0.0;
  local_1b8 = 0.0;
  local_1d8 = 0.0;
  local_1a8 = 0.0;
  local_1c0 = 0.0;
  for (; iVar17 != 0; iVar17 = *(int *)(iVar17 + 0x4c)) {
    for (iVar15 = *(int *)(iVar17 + 0x204); iVar15 != 0; iVar15 = *(int *)(iVar15 + 0x10)) {
      local_1f0 = 0;
      if (0 < *(int *)(iVar15 + 0x118)) {
        iVar18 = 0;
        do {
          iVar13 = *(int *)(iVar15 + 0x11c);
          iVar16 = 0;
          if (0 < *(int *)(iVar13 + 8 + iVar18)) {
            iVar20 = 0;
            do {
              pfVar11 = (float *)(*(int *)(iVar13 + 0xc + iVar18) + iVar20);
              if ((*(byte *)(iVar17 + 0x3c) & 0x10) != 0) {
                (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,pfVar11,local_148,iVar17 + 0x1a0);
                pfVar11 = local_148;
              }
              iVar16 = iVar16 + 1;
              iVar20 = iVar20 + 0x30;
              local_1b8 = (double)(*pfVar11 * *pfVar11 + (float)local_1b8);
              local_190 = (double)(pfVar11[1] * pfVar11[1] + (float)local_190);
              local_1a0 = (double)(pfVar11[2] * pfVar11[2] + (float)local_1a0);
              local_1b0 = (double)(*pfVar11 * pfVar11[1] + (float)local_1b0);
              local_1c8 = (double)(*pfVar11 * pfVar11[2] + (float)local_1c8);
              local_1d0 = (double)(pfVar11[1] * pfVar11[2] + (float)local_1d0);
              local_1c0 = (double)(*pfVar11 + (float)local_1c0);
              local_1a8 = (double)(pfVar11[1] + (float)local_1a8);
              iVar13 = *(int *)(iVar15 + 0x11c);
              local_1d8 = (double)(pfVar11[2] + (float)local_1d8);
            } while (iVar16 < *(int *)(iVar13 + 8 + iVar18));
          }
          local_1ec = local_1ec + *(int *)(*(int *)(iVar15 + 0x11c) + 8 + iVar18);
          local_1f0 = local_1f0 + 1;
          iVar18 = iVar18 + 0x40;
        } while (local_1f0 < *(int *)(iVar15 + 0x118));
      }
    }
  }
  dVar5 = _DAT_0059e420 / (double)local_1ec;
  dVar6 = local_1c0 * dVar5;
  dVar7 = dVar5 * local_1a8;
  local_1d8 = dVar5 * local_1d8;
  dStack_e8 = dVar5 * local_1b0 - dVar7 * dVar6;
  local_1c8 = dVar5 * local_1c8 - local_1d8 * dVar6;
  local_1d0 = dVar5 * local_1d0 - local_1d8 * dVar7;
  dStack_f0 = dVar5 * local_1b8 - dVar6 * dVar6;
  dStack_d0 = dVar5 * local_190 - dVar7 * dVar7;
  dStack_b0 = dVar5 * local_1a0 - local_1d8 * local_1d8;
  dStack_e0 = local_1c8;
  dStack_d8 = dStack_e8;
  dStack_c0 = local_1c8;
  dStack_b8 = local_1d0;
  dStack_c8 = local_1d0;
  FUN_0053b6f0(&dStack_f0,auStack_60,&local_a8);
  afStack_188[0] = (float)local_a8;
  afStack_188[3] = 0.0;
  uStack_16c = 0;
  afStack_188[1] = (float)dStack_90;
  uStack_15c = 0;
  uStack_158 = 0;
  afStack_188[2] = (float)dStack_78;
  uStack_154 = 0;
  uStack_150 = 0;
  afStack_188[4] = (float)dStack_a0;
  uStack_14c = 0x3f800000;
  pfVar11 = afStack_48;
  fStack_174 = (float)dStack_88;
  pfVar12 = afStack_188;
  iVar17 = 4;
  fStack_170 = (float)dStack_70;
  fStack_168 = (float)dStack_98;
  fStack_164 = (float)dStack_80;
  fStack_160 = (float)dStack_68;
  do {
    iVar15 = 4;
    pfVar14 = pfVar11;
    do {
      *pfVar14 = *pfVar12;
      pfVar14 = pfVar14 + 4;
      pfVar12 = pfVar12 + 1;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    pfVar11 = pfVar11 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  iVar17 = *(int *)(param_1 + 0xec);
  local_1c0 = 999999995904.0;
  local_1b0 = 999999995904.0;
  local_1d0 = 999999995904.0;
  local_1a8 = -999999995904.0;
  local_1b8 = -999999995904.0;
  local_1c8 = -999999995904.0;
  local_1a0 = 0.0;
  for (; iVar17 != 0; iVar17 = *(int *)(iVar17 + 0x4c)) {
    for (iVar15 = *(int *)(iVar17 + 0x204); iVar15 != 0; iVar15 = *(int *)(iVar15 + 0x10)) {
      local_1f0 = 0;
      if (0 < *(int *)(iVar15 + 0x118)) {
        iVar18 = 0;
        do {
          iVar13 = *(int *)(iVar15 + 0x11c);
          iVar16 = 0;
          if (0 < *(int *)(iVar18 + 8 + iVar13)) {
            iVar20 = 0;
            do {
              pfVar11 = (float *)(*(int *)(iVar18 + 0xc + iVar13) + iVar20);
              if ((*(byte *)(iVar17 + 0x3c) & 0x10) != 0) {
                (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,pfVar11,local_148,iVar17 + 0x1a0);
                pfVar11 = local_148;
              }
              (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,pfVar11,&fStack_1e8,afStack_48);
              if (fStack_1e8 < (float)local_1d0) {
                local_1d0 = (double)fStack_1e8;
              }
              if ((float)local_1c8 < fStack_1e8) {
                local_1c8 = (double)fStack_1e8;
              }
              if (fStack_1e4 < (float)local_1b0) {
                local_1b0 = (double)fStack_1e4;
              }
              if ((float)local_1b8 < fStack_1e4) {
                local_1b8 = (double)fStack_1e4;
              }
              if (fStack_1e0 < (float)local_1c0) {
                local_1c0 = (double)fStack_1e0;
              }
              if ((float)local_1a8 < fStack_1e0) {
                local_1a8 = (double)fStack_1e0;
              }
              iVar13 = *(int *)(iVar15 + 0x11c);
              iVar16 = iVar16 + 1;
              iVar20 = iVar20 + 0x30;
            } while (iVar16 < *(int *)(iVar18 + 8 + iVar13));
          }
          local_1f0 = local_1f0 + 1;
          iVar18 = iVar18 + 0x40;
        } while (local_1f0 < *(int *)(iVar15 + 0x118));
      }
    }
  }
  fVar1 = (float)local_1c8;
  fVar2 = (float)local_1b0;
  fVar3 = (float)local_1c0;
  fStack_1e8 = fVar1;
  fStack_1e4 = fVar2;
  fStack_1e0 = fVar3;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&fStack_1e8,param_1 + 0x1c,afStack_188);
  fVar4 = (float)local_1a8;
  fStack_1e8 = fVar1;
  fStack_1e4 = fVar2;
  fStack_1e0 = fVar4;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&fStack_1e8,param_1 + 0x28,afStack_188);
  fStack_1e8 = (float)local_1d0;
  local_1d8 = (double)CONCAT44(local_1d8._4_4_,fStack_1e8);
  fStack_1e4 = fVar2;
  fStack_1e0 = fVar4;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&fStack_1e8,param_1 + 0x34,afStack_188);
  fStack_1e8 = local_1d8._0_4_;
  fStack_1e4 = fVar2;
  fStack_1e0 = fVar3;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&fStack_1e8,param_1 + 0x40,afStack_188);
  fVar2 = (float)local_1b8;
  fStack_1e8 = fVar1;
  fStack_1e4 = fVar2;
  fStack_1e0 = fVar3;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&fStack_1e8,param_1 + 0x4c,afStack_188);
  fStack_1e8 = fVar1;
  fStack_1e4 = fVar2;
  fStack_1e0 = fVar4;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&fStack_1e8,param_1 + 0x58,afStack_188);
  fStack_1e8 = local_1d8._0_4_;
  fStack_1e4 = fVar2;
  fStack_1e0 = fVar4;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&fStack_1e8,param_1 + 100,afStack_188);
  fStack_1e8 = local_1d8._0_4_;
  fStack_1e4 = fVar2;
  fStack_1e0 = fVar3;
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&fStack_1e8,param_1 + 0x70,afStack_188);
  fStack_1e8 = (float)(((float10)local_1c8 + (float10)local_1d0) * (float10)_DAT_0059e880);
  fStack_1e4 = (float)(((float10)local_1b8 + (float10)local_1b0) * (float10)_DAT_0059e880);
  fStack_1e0 = (float)(((float10)local_1a8 + (float10)local_1c0) * (float10)_DAT_0059e880);
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&fStack_1e8,param_1 + 0x7c,afStack_188);
  for (iVar17 = *(int *)(param_1 + 0xec); iVar17 != 0; iVar17 = *(int *)(iVar17 + 0x4c)) {
    for (iVar15 = *(int *)(iVar17 + 0x204); iVar15 != 0; iVar15 = *(int *)(iVar15 + 0x10)) {
      iVar18 = 0;
      local_1f0 = 0;
      if (0 < *(int *)(iVar15 + 0x118)) {
        do {
          iVar13 = *(int *)(iVar15 + 0x11c);
          iVar16 = 0;
          if (0 < *(int *)(iVar18 + 8 + iVar13)) {
            iVar20 = 0;
            do {
              pfVar11 = (float *)(*(int *)(iVar18 + 0xc + iVar13) + iVar20);
              if ((*(byte *)(iVar17 + 0x3c) & 0x10) != 0) {
                (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,pfVar11,local_148,iVar17 + 0x1a0);
                pfVar11 = local_148;
              }
              fVar1 = *(float *)(param_1 + 0x7c) - *pfVar11;
              fVar3 = *(float *)(param_1 + 0x80) - pfVar11[1];
              fVar2 = *(float *)(param_1 + 0x84) - pfVar11[2];
              fVar1 = fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2;
              if ((float)local_1a0 <= fVar1) {
                local_1a0 = (double)fVar1;
              }
              iVar13 = *(int *)(iVar15 + 0x11c);
              iVar16 = iVar16 + 1;
              iVar20 = iVar20 + 0x30;
            } while (iVar16 < *(int *)(iVar18 + 8 + iVar13));
          }
          local_1f0 = local_1f0 + 1;
          iVar18 = iVar18 + 0x40;
        } while (local_1f0 < *(int *)(iVar15 + 0x118));
      }
    }
  }
  uStack_138 = 0;
  aiStack_134[6] = 3;
  aiStack_134[8] = 3;
  aiStack_134[9] = 0;
  aiStack_134[0x10] = 0;
  piVar19 = aiStack_134;
  aiStack_134[3] = 2;
  aiStack_134[5] = 2;
  aiStack_134[0xe] = 2;
  aiStack_134[0] = 1;
  aiStack_134[1] = 5;
  aiStack_134[2] = 1;
  aiStack_134[4] = 6;
  aiStack_134[7] = 7;
  aiStack_134[10] = 4;
  aiStack_134[0xb] = 7;
  aiStack_134[0xc] = 4;
  aiStack_134[0xd] = 5;
  aiStack_134[0xf] = 1;
  local_1f0 = 6;
  *(float *)(param_1 + 0x18) = SQRT((float)local_1a0);
  pfVar11 = (float *)(param_1 + 0x8c);
  do {
    iVar18 = *piVar19;
    iVar13 = piVar19[-1];
    iVar16 = piVar19[1];
    iVar17 = param_1 + iVar18 * 0xc;
    fVar3 = *(float *)(param_1 + 0x1c + iVar18 * 0xc) - *(float *)(param_1 + 0x1c + iVar13 * 0xc);
    iVar15 = param_1 + iVar13 * 0xc;
    fVar9 = *(float *)(iVar17 + 0x20) - *(float *)(iVar15 + 0x20);
    iVar18 = iVar18 * 3 + 9;
    pfVar12 = (float *)(param_1 + (iVar13 * 3 + 9) * 4);
    fVar4 = *(float *)(param_1 + iVar18 * 4) - *pfVar12;
    fVar1 = *(float *)(param_1 + 0x1c + iVar16 * 0xc) - *(float *)(iVar17 + 0x1c);
    fVar2 = *(float *)(param_1 + iVar16 * 0xc + 0x20) - *(float *)(iVar17 + 0x20);
    fVar10 = *(float *)(param_1 + (iVar16 * 3 + 9) * 4) - *(float *)(param_1 + iVar18 * 4);
    fVar8 = fVar10 * fVar9 - fVar2 * fVar4;
    fVar4 = fVar1 * fVar4 - fVar10 * fVar3;
    fVar1 = fVar2 * fVar3 - fVar1 * fVar9;
    fVar2 = (float)_DAT_0059e420 / SQRT(fVar8 * fVar8 + fVar4 * fVar4 + fVar1 * fVar1);
    pfVar11[-1] = fVar8 * fVar2;
    *pfVar11 = fVar4 * fVar2;
    pfVar11[1] = fVar2 * fVar1;
    piVar19 = piVar19 + 3;
    local_1f0 = local_1f0 + -1;
    pfVar11[2] = (-(fVar8 * fVar2 * *(float *)(iVar15 + 0x1c)) -
                 fVar4 * fVar2 * *(float *)(iVar15 + 0x20)) - fVar2 * fVar1 * *pfVar12;
    pfVar11 = pfVar11 + 4;
  } while (local_1f0 != 0);
  return;
}


