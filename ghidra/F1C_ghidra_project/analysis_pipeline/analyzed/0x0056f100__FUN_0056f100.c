// Function: FUN_0056f100 @ 0056f100
// Size (bytes): 1367


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0056f100(uint *param_1,undefined4 *param_2,double *param_3,undefined4 param_4,char param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined4 *puVar17;
  int iVar18;
  int iVar19;
  double *pdVar20;
  char *pcVar21;
  undefined4 *puVar22;
  bool bVar23;
  float10 fVar24;
  float10 fVar25;
  int local_22c;
  int local_228;
  int local_21c;
  undefined4 local_200 [4];
  undefined4 local_1f0;
  undefined4 uStack_1ec;
  undefined4 local_1e8;
  undefined4 uStack_1e4;
  undefined4 local_1e0;
  undefined4 uStack_1dc;
  undefined4 local_1d8;
  undefined4 uStack_1d4;
  undefined4 local_1d0;
  undefined4 uStack_1cc;
  undefined4 local_1c8;
  undefined4 uStack_1c4;
  undefined4 local_1c0;
  undefined4 uStack_1bc;
  double local_1b8;
  double local_1b0;
  double local_1a0;
  double local_198;
  double local_190;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  char local_140 [32];
  double local_120;
  double local_118;
  double local_110;
  double local_108;
  double local_100;
  double local_f8;
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
  double local_90 [2];
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_50;
  undefined1 local_48 [72];
  
  if (param_5 == '\0') {
    uVar15 = *param_1;
    if (0 < (int)uVar15) {
      uVar12 = uVar15 >> 2;
      pcVar21 = local_140;
      while (uVar12 != 0) {
        uVar12 = uVar12 - 1;
        builtin_strncpy(pcVar21,"\x01\x01\x01\x01",4);
        pcVar21 = pcVar21 + 4;
      }
      for (uVar15 = uVar15 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
        *pcVar21 = '\x01';
        pcVar21 = pcVar21 + 1;
      }
    }
  }
  else {
    uVar15 = *param_1;
    if (0 < (int)uVar15) {
      pcVar21 = local_140;
      for (uVar12 = uVar15 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
        pcVar21[0] = '\0';
        pcVar21[1] = '\0';
        pcVar21[2] = '\0';
        pcVar21[3] = '\0';
        pcVar21 = pcVar21 + 4;
      }
      for (uVar12 = uVar15 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar21 = '\0';
        pcVar21 = pcVar21 + 1;
      }
    }
    iVar9 = 0;
    if (0 < (int)uVar15) {
      puVar17 = (undefined4 *)param_1[1];
      do {
        if (param_2 == puVar17) {
          local_140[iVar9] = '\x01';
          break;
        }
        iVar9 = iVar9 + 1;
        puVar17 = puVar17 + 0x91;
      } while (iVar9 < (int)uVar15);
    }
    uVar12 = param_1[2];
    uVar2 = param_1[4];
    iVar9 = param_1[6] + uVar12 + uVar2;
    do {
      bVar8 = false;
      local_21c = 0;
      if (iVar9 < 1) break;
      iVar1 = uVar12 + uVar2;
      iVar18 = uVar12 * -0x30;
      iVar13 = iVar1 * -0x48;
      local_22c = 0;
      do {
        if (local_21c < (int)uVar12) {
          iVar10 = param_1[3] + local_22c;
          bVar23 = (*(byte *)(iVar10 + 0x2c) & 1) == 0;
        }
        else if (local_21c < iVar1) {
          iVar10 = param_1[5] + iVar18;
          bVar23 = (*(byte *)(iVar10 + 0x2c) & 1) == 0;
        }
        else {
          iVar10 = param_1[7] + iVar13;
          bVar23 = (*(byte *)(iVar10 + 0x44) & 1) == 0;
        }
        if (bVar23) {
          uVar3 = *(uint *)(iVar10 + 4);
          uVar4 = *(uint *)(iVar10 + 0xc);
          iVar10 = 0;
          if (0 < (int)uVar15) {
            iVar19 = 0;
            do {
              if (local_140[iVar10] != '\0') {
                uVar14 = param_1[1];
                uVar16 = uVar4;
                if ((uVar3 == uVar14 + iVar19) || (uVar16 = uVar3, uVar4 == uVar14 + iVar19)) {
                  iVar11 = 0;
                  do {
                    if (uVar16 == uVar14) {
                      if (local_140[iVar11] == '\0') {
                        bVar8 = true;
                      }
                      local_140[iVar11] = '\x01';
                      break;
                    }
                    iVar11 = iVar11 + 1;
                    uVar14 = uVar14 + 0x244;
                  } while (iVar11 < (int)uVar15);
                }
              }
              iVar10 = iVar10 + 1;
              iVar19 = iVar19 + 0x244;
            } while (iVar10 < (int)uVar15);
          }
        }
        local_21c = local_21c + 1;
        iVar13 = iVar13 + 0x48;
        local_22c = local_22c + 0x30;
        iVar18 = iVar18 + 0x30;
      } while (local_21c < iVar9);
    } while (bVar8);
  }
  pdVar20 = &local_108;
  puVar17 = param_2;
  for (iVar9 = 6; puVar17 = puVar17 + 1, iVar9 != 0; iVar9 = iVar9 + -1) {
    *(undefined4 *)pdVar20 = *puVar17;
    pdVar20 = (double *)((int)pdVar20 + 4);
  }
  FUN_0056bd40(param_4);
  puVar17 = param_2 + 7;
  puVar22 = local_200;
  for (iVar9 = 0x12; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar22 = *puVar17;
    puVar17 = puVar17 + 1;
    puVar22 = puVar22 + 1;
  }
  local_188 = local_200[0];
  local_184 = local_200[1];
  local_16c = local_200[3];
  local_170 = local_200[2];
  local_158 = local_1f0;
  local_180 = local_1e8;
  local_154 = uStack_1ec;
  local_17c = uStack_1e4;
  local_164 = uStack_1dc;
  local_168 = local_1e0;
  local_150 = local_1d8;
  local_178 = local_1d0;
  local_14c = uStack_1d4;
  local_174 = uStack_1cc;
  local_15c = uStack_1c4;
  local_160 = local_1c8;
  local_148 = local_1c0;
  local_144 = uStack_1bc;
  FUN_0056c740(local_48);
  local_228 = 0;
  if (0 < (int)*param_1) {
    local_22c = 0;
    do {
      if (local_140[local_228] != '\0') {
        puVar17 = (undefined4 *)(param_1[1] + local_22c);
        dVar5 = *(double *)(puVar17 + 1) - local_108;
        dVar7 = *(double *)(puVar17 + 3) - local_100;
        dVar6 = *(double *)(puVar17 + 5) - local_f8;
        local_1b8 = (double)CONCAT44(local_200[1],local_200[0]) * dVar5 +
                    (double)CONCAT44(uStack_1e4,local_1e8) * dVar7 +
                    (double)CONCAT44(uStack_1cc,local_1d0) * dVar6;
        local_1b0 = dVar5 * (double)CONCAT44(local_200[3],local_200[2]) +
                    (double)CONCAT44(uStack_1dc,local_1e0) * dVar7 +
                    (double)CONCAT44(uStack_1c4,local_1c8) * dVar6;
        dVar5 = (double)CONCAT44(uStack_1ec,local_1f0) * dVar5 +
                (double)CONCAT44(uStack_1d4,local_1d8) * dVar7 +
                (double)CONCAT44(uStack_1bc,local_1c0) * dVar6;
        local_e8 = local_c0 * local_1b8 + local_b8 * local_1b0 + local_b0 * dVar5;
        local_e0 = local_a8 * local_1b8 + local_a0 * local_1b0 + local_98 * dVar5;
        local_120 = local_d8 * local_1b8 + local_d0 * local_1b0 + local_c8 * dVar5 + *param_3;
        local_118 = local_e8 + param_3[1];
        local_110 = local_e0 + param_3[2];
        pdVar20 = &local_120;
        for (iVar9 = 6; puVar17 = puVar17 + 1, iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar17 = *(undefined4 *)pdVar20;
          pdVar20 = (double *)((int)pdVar20 + 4);
        }
        FUN_0056c740(local_90);
        fVar24 = (float10)FUN_00588570();
        local_1a0 = (double)-fVar24;
        if (ABS(local_68) == _DAT_0059e420) {
          local_190 = 0.0;
          fVar24 = (float10)fpatan(-(float10)local_60,(float10)local_90[0]);
        }
        else {
          fVar24 = (float10)fpatan((float10)local_80,(float10)local_50);
          fVar25 = (float10)fpatan((float10)local_78,(float10)local_70);
          local_190 = (double)fVar25;
        }
        local_198 = (double)fVar24;
        FUN_005691d0(&local_1a0);
      }
      local_228 = local_228 + 1;
      local_22c = local_22c + 0x244;
    } while (local_228 < (int)*param_1);
  }
  return;
}


