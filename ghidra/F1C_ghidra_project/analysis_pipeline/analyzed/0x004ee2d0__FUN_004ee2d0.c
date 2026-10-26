// Function: FUN_004ee2d0 @ 004ee2d0
// Size (bytes): 3735


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ee2d0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  short sVar6;
  char cVar7;
  float *pfVar8;
  uint uVar9;
  float *pfVar10;
  int iVar11;
  float *pfVar12;
  float10 fVar13;
  int local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  int local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0 [4];
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  uint local_7c;
  undefined4 local_78;
  uint local_74;
  undefined4 local_70;
  short local_6c;
  float local_68;
  float local_64 [3];
  uint local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  double local_3c;
  double local_34;
  double local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  double local_14;
  int local_c;
  
  if (_DAT_008afeec == _DAT_008afee8) {
    fVar13 = (float10)_DAT_008afee8;
  }
  else {
    pfVar8 = (float *)FUN_004e9630();
    fVar13 = (float10)FUN_004fd7e0(ABS((*(float *)(param_1 + 0x34d4) * pfVar8[8] +
                                       *(float *)(param_1 + 0x34d8) * pfVar8[9] +
                                       *(float *)(param_1 + 0x34dc) * pfVar8[10]) -
                                       (*pfVar8 * pfVar8[8] +
                                        pfVar8[9] * pfVar8[1] + pfVar8[10] * pfVar8[2] + pfVar8[7]))
                                  );
  }
  local_54 = *(float *)(param_1 + 0x34ec);
  local_50 = *(float *)(param_1 + 0x34f0);
  local_4c = *(float *)(param_1 + 0x34f4);
  local_68 = *(float *)(param_1 + 0x34ac);
  local_a4 = (float)fVar13;
  local_ec = 0;
  local_c0 = 0.0;
  local_bc = 0.0;
  local_b8 = 0.0;
  bVar5 = false;
  switch(*(int *)(param_1 + 0x32bc)) {
  case 0:
    FUN_004472b0(param_1 + 0x6e4);
    if (*(char *)(param_1 + 0x1070) != '\0') {
      FUN_004e16f0(param_1 + 0x34b0,param_1 + 0x34d4,*(undefined4 *)(param_1 + 0x3668));
    }
    local_ec = *(int *)(param_1 + 0x3668);
    iVar11 = 0;
    local_c0 = *(float *)(param_1 + 0x3be8) * *(float *)(param_1 + 0x34b0) +
               *(float *)(param_1 + 0x34b4) * *(float *)(param_1 + 0x3bec) +
               *(float *)(param_1 + 0x34b8) * *(float *)(param_1 + 0x3bf0) +
               *(float *)(param_1 + 0x34d4);
    local_bc = *(float *)(param_1 + 0x34c0) * *(float *)(param_1 + 0x3bec) +
               *(float *)(param_1 + 0x34c4) * *(float *)(param_1 + 0x3bf0) +
               *(float *)(param_1 + 0x34bc) * *(float *)(param_1 + 0x3be8) +
               *(float *)(param_1 + 0x34d8);
    local_b8 = *(float *)(param_1 + 0x34cc) * *(float *)(param_1 + 0x3bec) +
               *(float *)(param_1 + 0x34d0) * *(float *)(param_1 + 0x3bf0) +
               *(float *)(param_1 + 0x34c8) * *(float *)(param_1 + 0x3be8) +
               *(float *)(param_1 + 0x34dc);
    do {
      if ((float)_DAT_0059e430 < *(float *)(param_1 + 0x36c4)) {
        bVar5 = true;
        break;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < 4);
    break;
  case 1:
    pfVar8 = (float *)(param_1 + 0x7d4);
    pfVar12 = (float *)(param_1 + 0x3590);
    local_b4 = 4;
    do {
      fVar1 = pfVar12[0xf];
      fVar2 = (_DAT_0059e43c - pfVar12[0x10]) * fVar1;
      if (fVar2 <= _DAT_005ad228) {
        *pfVar8 = 0.0;
      }
      else if (*pfVar8 == DAT_0059e440) {
        *pfVar8 = 1e-05;
      }
      else {
        fVar3 = _DAT_0059e43c;
        if (fVar2 <= _DAT_005ad224) {
          fVar3 = (fVar2 - _DAT_005ad228) * _DAT_005ad220;
        }
        fVar4 = *pfVar8 + _DAT_0059e4e0;
        *pfVar8 = fVar4;
        if (fVar3 < fVar4) {
          *pfVar8 = fVar3;
        }
      }
      if (fVar2 <= _DAT_005ad21c) {
        pfVar8[1] = 0.0;
      }
      else if (fVar2 <= _DAT_005ad218) {
        pfVar8[1] = (fVar2 - _DAT_005ad21c) * _DAT_005ad214;
      }
      else {
        pfVar8[1] = _DAT_0059e43c;
      }
      fVar2 = DAT_0059e440;
      pfVar8[3] = *pfVar8;
      pfVar8[4] = pfVar8[1];
      pfVar8[6] = 2.8026e-44;
      if (fVar1 <= fVar2) {
        pfVar8[2] = 0.0;
      }
      else {
        pfVar8[2] = local_a4;
        bVar5 = true;
      }
      pfVar8[5] = 0.0;
      if (DAT_0059e440 < pfVar8[2]) {
        *pfVar8 = 0.0;
        pfVar8[3] = 0.0;
        pfVar8[4] = 0.0;
      }
      local_c4 = pfVar12[0x36];
      if ((local_c4 != 0.0) && (cVar7 = FUN_004ce380(pfVar8 + -7), cVar7 != '\0')) {
        pfVar10 = pfVar12 + -1;
        local_e8 = *pfVar10 * *(float *)(param_1 + 0x34b0) +
                   *(float *)(param_1 + 0x34b4) * *pfVar12 +
                   *(float *)(param_1 + 0x34b8) * pfVar12[1] + *(float *)(param_1 + 0x34d4);
        local_e4 = *(float *)(param_1 + 0x34c0) * *pfVar12 +
                   *(float *)(param_1 + 0x34bc) * *pfVar10 +
                   *(float *)(param_1 + 0x34c4) * pfVar12[1] + *(float *)(param_1 + 0x34d8);
        local_e0 = *(float *)(param_1 + 0x34cc) * *pfVar12 +
                   *(float *)(param_1 + 0x34c8) * *pfVar10 +
                   *(float *)(param_1 + 0x34d0) * pfVar12[1] + *(float *)(param_1 + 0x34dc);
        pfVar10 = (float *)FUN_004ed750(&local_48);
        local_d0 = *pfVar10;
        local_cc = pfVar10[1];
        local_c8 = pfVar10[2];
        fVar1 = local_d0 + *(float *)(param_1 + 0x34f8);
        fVar3 = local_cc + *(float *)(param_1 + 0x34fc);
        fVar2 = local_c8 + *(float *)(param_1 + 0x3500);
        local_dc = fVar1 * *(float *)(param_1 + 0x34b0) +
                   fVar3 * *(float *)(param_1 + 0x34b4) + fVar2 * *(float *)(param_1 + 0x34b8);
        local_d8 = fVar1 * *(float *)(param_1 + 0x34bc) +
                   fVar3 * *(float *)(param_1 + 0x34c0) + fVar2 * *(float *)(param_1 + 0x34c4);
        local_d4 = fVar1 * *(float *)(param_1 + 0x34c8) +
                   fVar3 * *(float *)(param_1 + 0x34cc) + fVar2 * *(float *)(param_1 + 0x34d0);
        FUN_004ce3e0(pfVar8 + -7,*(undefined4 *)(param_1 + 0x34ac),&local_e8,&local_dc,local_c4,
                     *(undefined4 *)(param_1 + 4));
      }
      pfVar12 = pfVar12 + 0x3e;
      pfVar8 = pfVar8 + 0x4a;
      local_b4 = local_b4 + -1;
    } while (local_b4 != 0);
    pfVar8 = (float *)(param_1 + 0x34b0);
    local_ec = *(int *)(param_1 + 0x3760);
    pfVar12 = (float *)(param_1 + 0x34d4);
    local_c0 = *pfVar8 * *(float *)(param_1 + 0x3be8) +
               *(float *)(param_1 + 0x34b4) * *(float *)(param_1 + 0x3bec) +
               *(float *)(param_1 + 0x34b8) * *(float *)(param_1 + 0x3bf0) + *pfVar12;
    local_bc = *(float *)(param_1 + 0x34c0) * *(float *)(param_1 + 0x3bec) +
               *(float *)(param_1 + 0x34c4) * *(float *)(param_1 + 0x3bf0) +
               *(float *)(param_1 + 0x34bc) * *(float *)(param_1 + 0x3be8) +
               *(float *)(param_1 + 0x34d8);
    local_b8 = *(float *)(param_1 + 0x34cc) * *(float *)(param_1 + 0x3bec) +
               *(float *)(param_1 + 0x34d0) * *(float *)(param_1 + 0x3bf0) +
               *(float *)(param_1 + 0x34c8) * *(float *)(param_1 + 0x3be8) +
               *(float *)(param_1 + 0x34dc);
    FUN_004ee230();
    cVar7 = FUN_004ce8f0(param_1 + 0x77c);
    if (cVar7 != '\0') {
      local_e8 = *(float *)(param_1 + 0x3d54) * *pfVar8 +
                 *(float *)(param_1 + 0x34b4) * *(float *)(param_1 + 0x3d58) +
                 *(float *)(param_1 + 0x34b8) * *(float *)(param_1 + 0x3d5c) + *pfVar12;
      local_e4 = *(float *)(param_1 + 0x34bc) * *(float *)(param_1 + 0x3d54) +
                 *(float *)(param_1 + 0x34c0) * *(float *)(param_1 + 0x3d58) +
                 *(float *)(param_1 + 0x34c4) * *(float *)(param_1 + 0x3d5c) +
                 *(float *)(param_1 + 0x34d8);
      local_e0 = *(float *)(param_1 + 0x34c8) * *(float *)(param_1 + 0x3d54) +
                 *(float *)(param_1 + 0x34cc) * *(float *)(param_1 + 0x3d58) +
                 *(float *)(param_1 + 0x34d0) * *(float *)(param_1 + 0x3d5c) +
                 *(float *)(param_1 + 0x34dc);
      local_dc = *(float *)(param_1 + 0x34ec);
      local_d8 = *(float *)(param_1 + 0x34f0);
      local_d4 = *(float *)(param_1 + 0x34f4);
      FUN_004ce930(param_1 + 0x77c,*(undefined4 *)(param_1 + 0x34ac),&local_e8,&local_dc,
                   *(undefined4 *)(param_1 + 4));
    }
    if (*(char *)(param_1 + 0x1070) != '\0') {
      FUN_004e16f0(pfVar8,pfVar12,*(undefined4 *)(param_1 + 0x3668));
    }
    break;
  case 2:
  case 3:
    uVar9 = *(uint *)(param_1 + 0x101c);
    local_78 = *(uint *)(param_1 + 0x1020);
    local_74 = *(uint *)(param_1 + 0x1024);
    local_70 = *(undefined4 *)(param_1 + 0x1028);
    local_6c = *(short *)(param_1 + 0x102c);
    local_7c = uVar9;
    if (*(int *)(param_1 + 0x32bc) == 3) {
      fVar13 = (float10)FUN_004b9ce0();
      local_c4 = (float)fVar13;
      local_68 = (float)fVar13;
      local_b0 = *(float *)(param_1 + 0x738);
      pfVar8 = (float *)(param_1 + 0x704);
      pfVar12 = local_a0;
      for (iVar11 = 9; iVar11 != 0; iVar11 = iVar11 + -1) {
        *pfVar12 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pfVar12 = pfVar12 + 1;
      }
      local_ac = *(float *)(param_1 + 0x73c);
      local_a8 = *(float *)(param_1 + 0x740);
    }
    else {
      local_c4 = *(float *)(param_1 + 0x34ac);
      pfVar8 = (float *)(param_1 + 0x34b0);
      pfVar12 = local_a0;
      for (iVar11 = 9; iVar11 != 0; iVar11 = iVar11 + -1) {
        *pfVar12 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pfVar12 = pfVar12 + 1;
      }
      local_b0 = *(float *)(param_1 + 0x34d4);
      local_ac = *(float *)(param_1 + 0x34d8);
      local_a8 = *(float *)(param_1 + 0x34dc);
    }
    local_58 = uVar9 & 0xff;
    iVar11 = 0;
    local_64[0] = (float)(uVar9 >> 0x18);
    local_64[1] = (float)(local_7c >> 0x10 & 0xff);
    local_64[2] = (float)(local_7c >> 8 & 0xff);
    local_b4 = 0;
    pfVar8 = (float *)(param_1 + 0x7dc);
    pfVar12 = (float *)(param_1 + 0x3590);
    do {
      fVar1 = local_64[iVar11];
      uVar9 = (int)fVar1 >> 3;
      fVar2 = (float)(uVar9 & 7) * _DAT_005ad210;
      pfVar8[4] = (float)(uVar9 & 0xfffffff8);
      pfVar10 = pfVar12 + -1;
      pfVar8[-2] = fVar2;
      fVar1 = (float)((uint)fVar1 & 7) * _DAT_005ad210;
      pfVar8[-1] = fVar1;
      pfVar8[1] = fVar2;
      pfVar8[2] = fVar1;
      local_e8 = local_b0 +
                 local_a0[1] * *pfVar12 + local_a0[0] * *pfVar10 + local_a0[2] * pfVar12[1];
      local_e4 = local_ac + local_90 * *pfVar12 + local_8c * pfVar12[1] + local_a0[3] * *pfVar10;
      local_e0 = local_a8 + local_84 * *pfVar12 + local_80 * pfVar12[1] + local_88 * *pfVar10;
      if (*(int *)(param_1 + 0x32bc) == 2) {
        pfVar10 = (float *)FUN_004ed750(&local_48);
        local_d0 = *pfVar10;
        local_cc = pfVar10[1];
        local_c8 = pfVar10[2];
        fVar1 = local_d0 + *(float *)(param_1 + 0x34f8);
        fVar3 = local_cc + *(float *)(param_1 + 0x34fc);
        fVar2 = local_c8 + *(float *)(param_1 + 0x3500);
        local_dc = fVar1 * local_a0[0] + local_a0[1] * fVar3 + local_a0[2] * fVar2;
        local_d8 = local_a0[3] * fVar1 + local_90 * fVar3 + local_8c * fVar2;
        local_d4 = local_88 * fVar1 + local_84 * fVar3 + local_80 * fVar2;
      }
      else {
        local_dc = *(float *)(param_1 + 0x4c);
        local_d8 = *(float *)(param_1 + 0x50);
        local_d4 = *(float *)(param_1 + 0x54);
      }
      local_3c = (double)local_e8;
      local_34 = (double)local_e4;
      local_2c = (double)local_e0;
      local_24 = 0x40000000;
      local_20 = 0x3ff33333;
      local_1c = 0x40000000;
      local_18 = 0x479e17b8;
      local_c = local_b4;
      local_ec = FUN_0044c4c0(&local_3c);
      if (local_14 <= (double)local_e4 - (double)pfVar12[0x20]) {
        *pfVar8 = 0.0;
      }
      else {
        *pfVar8 = local_a4;
        bVar5 = true;
      }
      pfVar8[3] = 0.0;
      if (DAT_0059e440 < *pfVar8) {
        pfVar8[-2] = 0.0;
        pfVar8[1] = 0.0;
        pfVar8[2] = 0.0;
      }
      local_b4 = local_ec;
      if (local_ec != 0) {
        FUN_004ce3e0(pfVar8 + -9,local_c4,&local_e8,&local_dc,local_ec,*(undefined4 *)(param_1 + 4))
        ;
      }
      iVar11 = iVar11 + 1;
      pfVar12 = pfVar12 + 0x3e;
      pfVar8 = pfVar8 + 0x4a;
    } while (iVar11 < 4);
    local_c0 = local_b0 +
               local_a0[2] * *(float *)(param_1 + 0x3bf0) +
               local_a0[1] * *(float *)(param_1 + 0x3bec) +
               local_a0[0] * *(float *)(param_1 + 0x3be8);
    local_bc = local_ac +
               local_8c * *(float *)(param_1 + 0x3bf0) +
               local_90 * *(float *)(param_1 + 0x3bec) + local_a0[3] * *(float *)(param_1 + 0x3be8);
    local_b8 = local_a8 +
               local_80 * *(float *)(param_1 + 0x3bf0) +
               local_84 * *(float *)(param_1 + 0x3bec) + local_88 * *(float *)(param_1 + 0x3be8);
    local_e8 = local_b0 +
               local_a0[1] * *(float *)(param_1 + 0x3d58) +
               local_a0[0] * *(float *)(param_1 + 0x3d54) +
               local_a0[2] * *(float *)(param_1 + 0x3d5c);
    local_e4 = local_ac +
               local_90 * *(float *)(param_1 + 0x3d58) +
               local_a0[3] * *(float *)(param_1 + 0x3d54) + local_8c * *(float *)(param_1 + 0x3d5c);
    local_e0 = local_a8 +
               local_84 * *(float *)(param_1 + 0x3d58) +
               local_88 * *(float *)(param_1 + 0x3d54) + local_80 * *(float *)(param_1 + 0x3d5c);
    if (*(int *)(param_1 + 0x32bc) == 2) {
      local_dc = *(float *)(param_1 + 0x34ec);
      local_d8 = *(float *)(param_1 + 0x34f0);
      local_d4 = *(float *)(param_1 + 0x34f4);
    }
    else {
      local_dc = *(float *)(param_1 + 0x4c);
      local_d8 = *(float *)(param_1 + 0x50);
      local_d4 = *(float *)(param_1 + 0x54);
      local_54 = local_dc;
      local_50 = local_d8;
      local_4c = local_d4;
    }
    *(float *)(param_1 + 0x77c) = (float)(local_78._2_1_ & 3) * _DAT_0059e98c;
    *(float *)(param_1 + 0x790) = (float)(local_78._2_1_ >> 2 & 7) * _DAT_005ad210;
    *(float *)(param_1 + 0x7a4) = (float)(local_78._2_1_ >> 5) * _DAT_005ad210;
    FUN_004ce930(param_1 + 0x77c,local_c4,&local_e8,&local_dc,*(undefined4 *)(param_1 + 4));
    *(float *)(param_1 + 0x8cc) = (float)(local_78 >> 0xc & 0xf) * _DAT_005ac108;
    *(float *)(param_1 + 0x9f4) = (float)(local_78 >> 8 & 0xf) * _DAT_005ac108;
    *(float *)(param_1 + 0xb1c) = (float)(local_78 >> 4 & 0xf) * _DAT_005ac108;
    *(float *)(param_1 + 0xc44) = (float)(local_78 & 0xf) * _DAT_005ac108;
    if ((local_74 != 0) && (local_c4 = DAT_008aceb8, DAT_008aceb8 != 0.0)) {
      sVar6 = local_70._2_2_;
      iVar11 = 0;
      pfVar8 = (float *)(param_1 + 0x1078);
      do {
        if ((local_74 & 1 << ((byte)iVar11 & 0x1f)) != 0) {
          local_d0 = *pfVar8;
          local_cc = pfVar8[1];
          local_c8 = pfVar8[2];
          local_64[0] = local_d0 * local_a0[0] + local_a0[1] * local_cc + local_a0[2] * local_c8 +
                        local_b0;
          local_64[1] = local_a0[3] * local_d0 + local_90 * local_cc + local_8c * local_c8 +
                        local_ac;
          local_64[2] = local_88 * local_d0 + local_84 * local_cc + local_80 * local_c8 + local_a8;
          local_48 = (float)(int)(short)local_70 * _DAT_0059e778;
          local_44 = (float)(int)sVar6 * _DAT_0059e778;
          local_40 = (float)(int)local_6c * _DAT_0059e778;
          FUN_004cce90(local_64,local_78._3_1_ >> 4,&local_48,local_78._3_1_ & 0xf,local_b4);
        }
        iVar11 = iVar11 + 1;
        pfVar8 = pfVar8 + 7;
      } while (iVar11 < 0x11);
    }
  }
  if ((DAT_0059e440 < local_a4) && (bVar5)) {
    local_3c = (double)local_c0;
    local_34 = (double)local_bc;
    *(float *)(param_1 + 0xc88) = local_a4;
    local_2c = (double)local_b8;
    *(undefined4 *)(param_1 + 0xc74) = 0;
    *(undefined4 *)(param_1 + 0xc78) = 0;
    *(undefined4 *)(param_1 + 0xc7c) = 0;
    *(undefined4 *)(param_1 + 0xc80) = 0;
    *(undefined4 *)(param_1 + 0xc84) = 0;
    local_24 = 0x40000000;
    local_20 = 0x3ff33333;
    local_1c = 0x40000000;
    local_18 = 0x479e17b8;
    local_c = local_ec;
    iVar11 = FUN_0044c4c0(&local_3c);
    if (iVar11 != 0) {
      FUN_004ce3e0(param_1 + 0xc58,local_68,&local_c0,&local_54,iVar11,*(undefined4 *)(param_1 + 4))
      ;
    }
  }
  return;
}


